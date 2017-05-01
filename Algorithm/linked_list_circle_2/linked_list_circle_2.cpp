#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



/*class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( head == NULL || head->next == NULL ){
            return NULL;
        }
        vector<ListNode *> v;
        ListNode *p = head;
        while( p != NULL ){
            if ( find(v.begin(),v.end(),p) != v.end() )
                return p;
            else
                v.push_back(p);

			p = p->next;
        }
        return NULL;
    }
};*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if ( head == NULL || head->next == NULL ) return NULL;
        
        ListNode *first = head;
        ListNode *second = head;
        bool hasCircle = false;
        
        while ( second != NULL && second->next != NULL ){
            first = first->next;
            second = second->next->next;
            if ( first == second ){
                hasCircle = true;
                break;
            }
        }
        
        if ( hasCircle == false )
            return NULL;
        
        first = head;
        while ( first != second ){
            first = first->next;
            second = second->next;
        }
        return first;
    }
};


int main()
{
	ListNode l1(3);
	ListNode l2(4);
	ListNode l3(1);
	ListNode l4(2);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l2;
	Solution s;
	ListNode *l = s.detectCycle(&l1);

}