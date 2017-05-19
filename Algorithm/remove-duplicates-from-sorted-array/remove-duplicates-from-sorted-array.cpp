#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if( n<= 0 ) return 0;
        int loc = 0;
        for(int i=1; i<n-1; ++i){
            if ( A[i] == A[i-1] ) loc++;
            else
                A[i-loc] = A[i];
        }
        return n-loc;
    }
};

int main()
{
	int a[] = {1,1};
	Solution s;
	cout<<s.removeDuplicates(a,2);
}