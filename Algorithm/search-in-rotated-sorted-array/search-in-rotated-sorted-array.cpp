#include <iostream>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int i = 0;
        int j = n-1;
        while( i<=j ){
            int mid = (i+j)/2;
            if( A[mid] == target) {
                return mid;
            }
            
            if( A[mid] > A[j] ){
                if( target < A[mid] && target >= A[i] ){
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
            else if( A[mid] < A[i] ){
                if( target > A[mid] && target <= A[j] ){
                    i = mid+1;
                }
                else{
                    j = mid-1;
                }
            }
            else{
                if( target < A[mid] ){
                    j = mid-1;
                }
                else{
                    i = mid+1;
                }
            }
        }
        return -1;
    }
};

int main()
{
	int a[] = {4,5,6,7,0,1,2};
	Solution s;
	cout<<s.search(a,7,4)<<endl;
}