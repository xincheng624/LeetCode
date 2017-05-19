#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


/*class Solution {
public:
    int maxArea(vector<int> &height) {
        int N = height.size();
        if ( N < 2 ) return 0;
        int L = height[0];
        int R = height[N-1];
        int M = (N-1)*min(L,R);
        for(int i=0; i != N; ++i){
            if ( height[i] < L ) continue; 
            L = height[i];
			R = height[N-1];
            for(int j=N-1; j != i; --j){
                if ( height[j] < R ) continue;
                R = height[j];
                int temp = (j-i)*min(L,R); 
                M = (temp > M)? temp:M;
            }            
        }
        return M;
    }
};*/

class Solution {
public:
    int maxArea(vector<int>& height) {
    int water = 0;
    int i = 0, j = height.size() - 1;
    while (i < j) {
        int h = min(height[i], height[j]);
        water = max(water, (j - i) * h);
        while (height[i] <= h && i < j) i++;
        while (height[j] <= h && i < j) j--;
    }
    return water;
	}
};



int main()
{
	vector<int> h;
	h.push_back(2);
	h.push_back(3);
	h.push_back(3);
	h.push_back(2);
	Solution s;
	cout<<s.maxArea(h);

}