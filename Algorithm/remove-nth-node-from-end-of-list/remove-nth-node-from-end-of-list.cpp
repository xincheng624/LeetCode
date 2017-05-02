#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if ( head == NULL ) return head;
		ListNode node(0);
		node.next = head;
        ListNode *p = &node;
        ListNode *q = &node;
        for( int i = 0; i<n; ++i){
            p = p->next;
        }
        while ( p->next != NULL  ){
            p = p->next;
            q = q->next;
        }
        
        ListNode *tmp = q->next;
        q->next = q->next->next;
        
        delete tmp;
		return node.next;
        
    }
};

int main()
{

	ListNode l1(1);
	//ListNode l2(2);
	//ListNode l3(3);
	//ListNode l4(4);
	//l1.next = &l2;
	//l2.next = &l3;
	//l3.next = &l4;
	//l4.next = &l2;
	Solution s;
	ListNode *l = s.removeNthFromEnd(&l1,1);

}