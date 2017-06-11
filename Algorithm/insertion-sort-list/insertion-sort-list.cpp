#include <iostream>
using namespace std;
 //Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
//head节点为头结点的情况
/*
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if( head == NULL ) return head;
        
        ListNode* pBefore = head;
        ListNode* pAfter = pBefore->next;
        
        while( pAfter != NULL ){
            pBefore = pAfter;
            pAfter = pAfter->next;
            
            if( pAfter != NULL && pAfter->val < pBefore->val ){
                ListNode* p = head;
                while( p != NULL ){
                    if( p->next->val < pAfter->val ){
						p = p->next;
                    }
                    else{
                        break;
                    }
                } 
                
                pBefore->next = pAfter->next;
                pAfter->next = p->next;
                p->next = pAfter;
				pAfter = pBefore;
            }            
            
            
        }      
        
        return head;
    }
};*/

//head不为头结点
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if( head == NULL ) return head;
        ListNode r(0);
		r.next = head;
        ListNode* pBefore = &r;
        ListNode* pAfter = pBefore->next;
        
        while( pAfter != NULL ){     
			pBefore = pAfter;
            pAfter = pAfter->next;

            if( pAfter != NULL && pAfter->val < pBefore->val ){
                ListNode* p = &r;
				while( p != NULL && p->next->val < pAfter->val ){
                    p = p->next;
                } 

				pBefore->next = pAfter->next;				
				pAfter->next = p->next;
				p->next = pAfter;
				pAfter = pBefore;


            }            
                        
        }      
        
		return r.next;
    }
};

int main()
{
	ListNode l0(7);
	ListNode l1(6);
	ListNode l2(4);
	ListNode l3(3);
	ListNode l4(2);
	ListNode l5(5);
	l0.next = &l1;
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;


	Solution s;
	ListNode* l = s.insertionSortList(&l0);

}