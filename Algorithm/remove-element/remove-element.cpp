#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if ( n <= 0 ) return 0;
        int length = 0;
        
        for( int go=0; go<n; ++go){
            if ( A[go] != elem ){
                A[length++] = A[go];
            }            
        }       
        return length;
    }
};

int main()
{
	int a[] = {2,1,3,1};
	int b[] = {1};
	Solution s;
	cout<<s.removeElement(a,4,1);
	cout<<s.removeElement(b,1,1);
}