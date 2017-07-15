#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int i = 0;
        int j = n;
        while( i<j ){
            int mid = (i+j)/2;
            if( A[mid] < target ){
                i = mid+1;
            }
            else if( A[mid] > target ){
                j = mid;
            }
            else
                return mid;
        }
        return j;
    }
};

int main()
{
	int a[] = {1,3,5,6};
	Solution s;
	cout<<s.searchInsert(a,4,5)<<endl;
	cout<<s.searchInsert(a,4,2)<<endl;
	cout<<s.searchInsert(a,4,7)<<endl;
	cout<<s.searchInsert(a,4,0)<<endl;
}