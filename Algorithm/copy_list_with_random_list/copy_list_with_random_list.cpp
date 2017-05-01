#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

  struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };



class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
		if ( head == NULL ) return NULL;
        RandomListNode r(0);
        RandomListNode *p = head;
        RandomListNode *rp = &r;
        while ( p != NULL ){
			rp->next = new RandomListNode( p->label );
            p = p->next;
            rp = rp->next;
        }
        
        p = head;
        rp = r.next;
        while( p != NULL ){
            if ( p->random != NULL ){
                RandomListNode *pt = head;
                RandomListNode *rpt = r.next;
                while ( p->random != pt && pt != NULL && rpt != NULL ){
                    pt = pt->next;
                    rpt = rpt->next;
                }
                rp->random = rpt;                
            }
            p = p->next;
            rp = rp->next;
        }
        return r.next;
    }
};

int main()
{
	RandomListNode l1(3);
	RandomListNode l2(4);
	RandomListNode l3(1);
	RandomListNode l4(2);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l2.random = &l4;
	l3.random = &l1;
	Solution s;
	RandomListNode *l = s.copyRandomList(&l1);

}