/*Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given1->2->3->4, you should return the list as2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        if ( head == NULL || head->next == NULL ) return head;
        ListNode node(0);
        ListNode *pre = &node;
        pre->next = head;
        ListNode *cur = pre;
        ListNode *nex = pre;
        while( pre != NULL && pre->next != NULL ){
            cur = pre->next;
            nex = cur->next;
            
            if ( nex != NULL ){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;            
            }
            
            pre = cur;
        }
        
        return node.next;
    }
};


int main()
{
	ListNode l1(1);
	ListNode l2(2);
	ListNode l3(3);
	ListNode l4(4);
	ListNode l5(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	Solution s;
	ListNode *l = s.swapPairs(&l1);
}
