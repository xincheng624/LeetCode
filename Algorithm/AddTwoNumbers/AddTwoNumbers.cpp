#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        int sum = 0;
        ListNode node(0);
        ListNode *r = &node;
        while ( p1 != NULL || p2 != NULL || sum != 0 ){
            int d1 = p1? p1->val:0;
            int d2 = p2? p2->val:0;
            if ( p1 != NULL ) p1 = p1->next;
            if ( p2 != NULL ) p2 = p2->next;
            sum += d1+d2;
            r->next = new ListNode( sum%10 );
            r = r->next;
            sum /= 10;
        }
        return node.next;
    }
};


int main()
{
	ListNode l1(2);
	ListNode l2(4);
	ListNode l3(3);
	ListNode l4(5);
	ListNode l5(1);
	ListNode l6(4);
	l1.next = &l2;
	l2.next = &l3;
	//l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	//Solution s;
	ListNode *l = addTwoNumbers(&l1,&l4);
}
