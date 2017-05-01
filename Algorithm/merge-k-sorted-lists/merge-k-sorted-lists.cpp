//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    class compareList{
        public:
        bool operator() (ListNode* l1, ListNode* l2) const{
            return l1->val > l2->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if ( lists.size() == 0 ) return NULL;
        if ( lists.size() == 1 ) return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, compareList > q;
        for( int i = 0; i < lists.size(); ++i){
            if( lists[i] != NULL )
                q.push(lists[i]);
        }
        
        ListNode node(0);
        ListNode *head = &node;
        
        while ( !q.empty() ){
            head->next = q.top();
            q.pop();
            head = head->next;
            if ( head->next != NULL )
                q.push(head->next);
        }
        return node.next;
               
    }
    
};//nlog(k)

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if ( lists.size() == 0 ) return NULL;
        ListNode* head = lists[0];
        for( int i=1; i<lists.size(); ++i){
            head = mergeTwoLists( head, lists[i]);
        }
        return head;        
    }
    ListNode *mergeTwoLists(ListNode* l1,ListNode* l2){
        if ( l1 == NULL ) return l2;
        if ( l2 == NULL ) return l1;
        ListNode node(0);
        ListNode* p = &node;
        while ( l1 != NULL && l2 != NULL ){
            if ( l1->val < l2->val ){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        
        if ( l1 != NULL ) p->next = l1;
        if ( l2 != NULL ) p->next = l2;
        
        return node.next;
    }
};//n^2log(k)


