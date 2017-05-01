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
