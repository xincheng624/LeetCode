#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int> A, int n) {
        if( n<=0 ) return 0;
        int maxleft = 0;
        int maxright = 0;
        int left = 0;
        int right = n-1;
        int water = 0;
        while( left <= right ){
            if( A[left] <= A[right] ){
                if( A[left] >= maxleft ){
                    maxleft = A[left];
                }
                else{
                    water += maxleft-A[left];
                }
                ++left;
            }
            else{
                if( A[right] >= maxright ){
                    maxright = A[right];
                }
                else{
                    water += maxright-A[right];
                }
                --right;
            }
            
        }
        return water;
    }
};

int main()
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	cout<<s.trap(vector<int>(a,a+12),12)<<endl;
}