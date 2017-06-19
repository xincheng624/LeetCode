#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if( s3.size() != s1.size() + s2.size() ) return false;
        
        int m = s1.length();
        int n = s2.length();
        int l = s3.length();
        
		vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));       
        for(int i=0; i<=m; ++i){
			for(int j=0; j<=n; ++j)
			{
				if( i==0 && j==0)
					dp[i][j] = true;
				else if( i==0 )
					dp[i][j] = ( dp[i][j-1] && s2[j-1] == s3[j-1] );
				else if( j==0 )
					dp[i][j] = ( dp[i-1][j] && s1[i-1] == s3[i-1] );
				else
					dp[i][j] = ( (dp[i-1][j] && s1[i-1] == s3[i+j-1] ) || 
					             ( dp[i][j-1] && s2[j-1] == s3[i+j-1] ) );
			}          
        }
        
        return dp[m][n];
     }
};

int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s4 = "aadbbbaccc";
	Solution s;
	cout<<s.isInterleave(s1,s2,s3)<<endl;
	cout<<s.isInterleave(s1,s2,s4)<<endl;
}