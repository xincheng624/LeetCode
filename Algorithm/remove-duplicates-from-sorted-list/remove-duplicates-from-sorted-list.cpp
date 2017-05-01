/*Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given1->1->2, return1->2.
Given1->1->2->3->3, return1->2->3.*/

#include <iostream>

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if ( head == NULL || head->next == NULL ) return head;
        ListNode *cur = head;
        while ( cur != NULL ){
            while( cur->next != NULL && cur->val == cur->next->val ){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        return head;
        
    }
};

int main()
{
	ListNode l1(1);
	ListNode l2(1);
	ListNode l3(2);
	ListNode l4(5);
	ListNode l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	Solution s;
	ListNode *l = s.deleteDuplicates(&l1);
}
