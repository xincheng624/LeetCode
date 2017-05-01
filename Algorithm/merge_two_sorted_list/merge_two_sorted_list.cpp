#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if ( l1 == NULL ) return l2;
        if ( l2 == NULL ) return l1;
        ListNode head(0);
        ListNode *lh = l1;
        ListNode *rh = l2;
        ListNode *phead = &head;
        while ( lh != NULL && rh != NULL ){
           if( lh->val < rh->val ){
			   phead->next = lh;
               lh = lh->next;
           }else{
			   phead->next = rh;
               rh = rh->next;
           }
		   phead = phead->next;
        }
        if ( lh != NULL ){
			phead->next = lh;
        }
        if ( rh != NULL){
            phead->next = rh;
        }
		return head.next;        
    }
};

int main()
{
	ListNode l1(1);
	
	ListNode l3(3);
	
	ListNode l5(5);
	l1.next = &l3;
	
	l3.next = &l5;
	
	ListNode l2(2);
	ListNode l4(4);
	l2.next = &l4;
	Solution s;

	ListNode *l = s.mergeTwoLists(&l1,&l4);
}