/*Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ¡Ü m ¡Ü n ¡Ü length of list.

Subscribe to see which companies asked this question.
*/
#include <iostream>


struct ListNode {
   int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if( head == NULL || m == n ) return head;
        ListNode *pNode = new ListNode(0);
        pNode->next = head;
        ListNode* new_head = pNode;
        for( int i=0; i < m-1; ++i ){
            pNode = pNode->next;
        }
        ListNode *cur = pNode->next;
        for ( int i=0; i<n-m; ++i){
            ListNode *move = cur->next;
            cur->next = move->next;
            move->next = pNode->next;
            pNode->next = move;
        }
        return new_head->next;       
    }
};