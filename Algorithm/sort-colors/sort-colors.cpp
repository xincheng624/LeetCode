#include <iostream>
using namespace std;

/*class Solution {
public:
    void sortColors(int A[], int n) {
		if ( n<=0 ) return;
        int count0 = 0;
        int count1 = 0;
        for(int i=0; i<n; ++i){
            if ( A[i] == 0 ){
                ++count0;                
            }else if ( A[i] == 1 ){
                ++count1;
            } 
        }
        for( int i=0; i<n; ++i ){
            if ( i<count0 ){
                A[i] = 0;
             }
            else if ( i<count0+count1 ){
                A[i] = 1;
            }
            else{
                A[i] = 2;
            }
        }
        
    }
};*/

class Solution {
public:
    void sortColors(int A[], int n) {
        if ( n <= 1 ) return;
        int i = 0;
        int j = n-1;
        
        for(int k=0; k<n; ++k){
            while( (A[k] == 0 && k>i) || (A[k] == 2 && k<j)){
                if ( A[k] == 0 ){
                    int temp = A[k];
                    A[k] = A[i];
                    A[i] = temp;
                    ++i;
                }
                else if ( A[k] == 2 ){
                    int temp = A[k];
                    A[k] = A[j];
                    A[j] = temp;
                    --j;
                }
            }
        } 
    }
};



int main()
{
	int a[] = {2,1,0,2,0};
	Solution s;
	s.sortColors(a,5);
}