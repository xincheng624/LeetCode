/*Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if ( head == NULL || head->next == NULL || k == 1 ) return head;
        ListNode node(0);
        ListNode *pre = &node;
        pre->next = head;
        ListNode *cur = pre, *nex = pre;
        int num = 0;
        while ( cur = cur->next )
            ++num;
        
        while( num >= k ){
            cur = pre->next;
            nex = cur->next;
            for( int i=1; i<k; ++i){
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            num -= k;
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
	ListNode *l = s.reverseKGroup(&l1,2);
}
