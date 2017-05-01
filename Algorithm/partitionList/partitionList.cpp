/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.*/

#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if ( head == NULL || head->next == NULL ) return head;
        ListNode node1(0);
        ListNode node2(0);
        ListNode* p1 = &node1;
        ListNode* p2 = &node2;
        
        while ( head != NULL ){
            if ( head->val < x ){
                p1->next = head;
                p1 = p1->next;
            }
            else{
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;        
    }
};


int main()
{
	ListNode l1(2);
	ListNode l2(1);
	//ListNode l3(3);
	//ListNode l4(4);
	//ListNode l5(5);
	l1.next = &l2;
	//l2.next = &l3;
	//l3.next = &l4;
	//l4.next = &l5;
	Solution s;
	ListNode *l = s.partition(&l1,2);
}
