#include <vector>
using namespace std;

//代码还可以简化下
class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        vector<int> index;
        while( start <= end ){
            int mid = (start+end)/2;
            if( A[mid] == target && (mid==0 || A[mid-1] < target) ){
                index.push_back(mid);
                break;
            }
            else if( A[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if( index.empty() ){
            index.push_back(-1);
            index.push_back(-1);
            return index;
        }
		start = 0;
		end = n-1;
        
        while( start <= end ){
            int mid = (start+end)/2;
            if( A[mid] == target && (mid==n-1 || A[mid+1] > target) ){
				index.push_back(mid);
                break;
            }
            else if(A[mid] == target || A[mid]<target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return index;
    }
};

int main()
{
	int a[] = {5,7,7,8,8,10};
	Solution s;
	vector<int> result = s.searchRange(a,6,5);
}