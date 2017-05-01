/*Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ( head == NULL || head->next == NULL ) return head;
        ListNode node(0);
        ListNode* r = &node;
        while ( head != NULL ){
            if ( head->next != NULL && head->val == head->next->val ){
                while ( head->next != NULL && head->val == head->next->val ){
                    head = head->next;
                }
            }
            else{
                r->next = head;
                r = r->next;
            }
            head = head->next;
        }
        r->next = NULL;
        return node.next;        
    }
};



int main()
{
	ListNode l1(1);
	ListNode l2(1);
	ListNode l3(3);
	ListNode l4(5);
	ListNode l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	Solution s;
	ListNode *l = s.deleteDuplicates(&l1);
}