#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if ( n <= 0 ) return 1;
        
        for( int i=0; i<n; ++i ){
            while( A[i] >0 && A[i] <= n && A[A[i]-1] != A[i] )
                swap(A[i],A[A[i]-1]);
        }
        
        for( int i=0; i<n; ++i ){
            if ( A[i] != i+1 )
                return i+1;
        }
        
        return n+1;
    }
};

int main()
{
	int A[] = {-1,4,2,1,9,10};
	Solution s;
	cout<<s.firstMissingPositive(A,6);
}