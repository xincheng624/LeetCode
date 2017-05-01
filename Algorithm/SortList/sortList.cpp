#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

/*class Solution {
public:
    ListNode *sortList(ListNode *head) {
        ListNode *tmp = head;
        while ( tmp->next != NULL ){
            ListNode *t1 = head;
            ListNode *t2 = t1->next;
            while ( t2 != NULL ){
                if ( t1->val > t2->val ){
                    ListNode ch(0);
					ch.val = t1->val;
					t1->val = t2->val;
					t2->val = ch.val;
                }
                t1 = t2;
				t2 = t2->next;
            }
            tmp = tmp->next;
        }
		return head;
    }
};*///冒泡解法


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if ( !head || !head->next )
            return head;
        
        ListNode *q = head;
        ListNode *p = head->next;
		while( p && p->next ){
            q = q->next;
            p = p->next->next;  
        }

		ListNode *left = sortList(q->next);//
		q->next = NULL;//在q处截断，分为head到q，和q->next到尾部两段
		ListNode *right = sortList(head);
        return merge(left,right);
    }
    
    ListNode* merge(ListNode *l, ListNode* r){
        if( !l )
            return r;
        else if ( !r )
            return l;
		ListNode first(0);
        ListNode *tmp = &first;
        while ( l && r ){
            if ( l->val < r->val ){
				tmp->next = l;
				l = l->next;
			}
            else {
				tmp->next = r;
				r = r->next;
            }
			tmp = tmp->next;
        }
        if (l)
            tmp->next = l;
		if (r)
			tmp->next = r;
		return first.next;
        
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
	Solution s;
	s.sortList(&l1);

}