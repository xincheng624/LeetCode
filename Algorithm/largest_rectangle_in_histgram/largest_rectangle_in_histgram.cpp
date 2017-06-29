#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if( height.empty() ) return 0;
        stack<int> index;
        height.push_back(0);
        int res = 0;
        for(int i=0; i<height.size(); ++i){
            while(index.size()>0 && height[index.top()] > height[i]){
                int h = height[index.top()];
                index.pop();
                
                int begin = index.size()>0? index.top():-1;
                if( h*(i-1-begin) > res )
                    res = h*(i-1-begin);
            }
            index.push(i);
        }
        return res;
    }
};


int main()
{
	int a[] = {2,1,5,6,2,3};
	vector<int> v(a,a+6);
	Solution s;
	s.largestRectangleArea(v);



}

