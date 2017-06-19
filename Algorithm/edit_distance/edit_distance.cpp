#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        if( word1.empty() && word2.empty() ) return 0;
        int m = word1.length();
        int n = word2.length();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int i=0; i<=m; ++i){
            dp[i][0] = i;
        }
        for(int i=0; i<=n; ++i){
            dp[0][i] = i;
        }
        
        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n; ++j){
                if( word1[i-1] == word2[j-1] )
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i][j-1]+1,dp[i-1][j]+1));
				//注意min只能接受2个参数
            }
        }
       return dp[m][n];
        
    }
};

int main()
{
	string s1 = "abc";
	string s2 = "abdd";
	Solution s;
	cout<<s.minDistance(s1,s2)<<endl;
}