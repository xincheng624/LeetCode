#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if( obstacleGrid.empty() || obstacleGrid[0].empty() ) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int> > path(m,vector<int>(n,0));
        if( obstacleGrid[0][0] == 1 )
            return 0;
        else
            path[0][0] = 1;
        for(int i=1; i<m; ++i){
            if( obstacleGrid[i][0] == 0 )
                path[i][0] = path[i-1][0];
            else
                path[i][0] = 0;
        }
        
        for(int i=1; i<n; ++i){
            if(obstacleGrid[0][i] == 0 )
                path[0][i] = path[0][i-1];
            else
                path[0][i] = 0;
        }
        
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if( obstacleGrid[i][j] == 0 ){
                    path[i][j] = path[i-1][j]+path[i][j-1];
                }
                else
                    path[i][j] = 0;
            }
        }
        
        return path[m-1][n-1];       
        
    }
};

int main()
{
	Solution s;
	int a[] = {0,0,0};
	int b[] = {0,1,0};
	vector<int> a1(a,a+3);
	vector<int> b1(b,b+3);
	vector<vector<int> > v;
	//v.push_back(a1);
	v.push_back(b1);
	//v.push_back(a1);
	cout<<s.uniquePathsWithObstacles(v)<<endl;
}