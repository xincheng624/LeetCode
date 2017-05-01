#include <iostream>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void reorderList(ListNode *head) {
		if ( head == NULL || head->next == NULL )
			return;

        ListNode *p = head;
        ListNode *q = head->next;
        while( q != NULL && q->next != NULL ){
            p = p->next;
            q = q->next->next;
        }
      
		ListNode *tmp = p->next;
		p->next = NULL;
        p = head;//×ó

		if ( tmp != NULL ){			
			ListNode* pl = tmp;
			ListNode* qr = tmp->next;
			tmp->next = NULL;
			ListNode* qn;
			while( qr != NULL ){
				qn = qr->next;
				qr->next = pl;
				pl = qr;
				qr = qn;
			}
			
			q = pl;//ÓÒ
		}
		
		tmp = head;
		int i = 1;
        while ( p != NULL && q != NULL ){
			ListNode *pnext = p->next;
			ListNode *qnext = q->next;
			p->next = q;
			q->next = pnext;
			p = pnext;
			q = qnext;
        }

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
	s.reorderList(&l1);

}