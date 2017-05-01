#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if ( head == NULL || head->next == NULL || head->next->next == NULL ){
            return false;
        }
        ListNode *p = head;
        ListNode *q = p->next->next;
		while ( q != NULL && q->next != NULL && p != NULL ){            
            if ( q->next == p )
                return true;
            q = q->next->next;
            p = p->next;
        }
        return false;
        
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
	//l4.next = &l2;
	Solution s;
	cout<<s.hasCycle(&l1);

}
