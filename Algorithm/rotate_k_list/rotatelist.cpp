#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if ( head == NULL || head->next == NULL ) return head;
        ListNode *rear = head;
        int total = 1;
        while( rear->next != NULL ){
            rear = rear->next;
            ++total;
        }
        total -= k;
        ListNode *tmp;
        while ( --total >= 0 ){
            tmp = head;
            head = head->next;
            rear->next = tmp;
            rear = rear->next;
        }
		rear->next = NULL;
        return head;
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
	ListNode *l = s.rotateRight(&l1,2);
}
