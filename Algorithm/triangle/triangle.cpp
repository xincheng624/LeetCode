#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if( triangle.empty() ) return 0;
        int height = triangle.size();
        int length = triangle[height-1].size();
        //vector<int> dp(triangle[height-1].begin(),triangle[height-1].end());
		vector<int> dp(length,0);
		dp = triangle[height-1];
        for(int i=height-2; i>=0; --i){
            for(int j=0; j<triangle[i].size(); ++j){
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);                    
            } 
            //dp.pop_back();
        }          
        return dp[0];
    }
};

int main()
{
	Solution s;
	int a1[] = {2};
	int a2[] = {3,4};
	int a3[] = {6,5,7};
	int a4[] = {4,1,8,3};
 	vector<vector<int> > tri;
	tri.push_back(vector<int>(a1,a1+1));
	tri.push_back(vector<int>(a2,a2+2));
	tri.push_back(vector<int>(a3,a3+3));
	tri.push_back(vector<int>(a4,a4+4));

	cout<<s.minimumTotal(tri)<<endl;

}