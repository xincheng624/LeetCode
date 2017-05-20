#include <iostream>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if( n <=0 ) return;
        for(int i=0; i<n; ++i){
            A[m++] = B[i]; 
        }       
        sort(A,A+m);        
    }
};*/


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if( n <= 0 ) return;
        int i = m-1;
        int j = n-1;
        int c = m+n-1;
        while ( j >= 0 && i >= 0 ){
            if ( A[i] > B[j] ){
                A[c] = A[i];
                --i;
            }
            else{
                A[c] = B[j];
                --j;
            }
            --c;
        }   
        while( j >= 0 ){
            A[j] = B[j];
            --j;
        }           
        
    }
};


int main()
{
	int a[1] ;
	int b[] = {1};
	Solution s;
	s.merge(a,0,b,1);
}