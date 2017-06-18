#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    /*int numDistinct(string S, string T) {
        const int Sl = S.length();
        const int Tl = T.length();

		vector<vector<int> > dp(Sl+1, vector<int>(Tl+1,0));
        dp[0][0] = 1;
        for(int i=1; i<=Sl;++i){
            dp[i][0] = 1;
        }
        for(int i=1; i<=Tl; ++i){
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=Sl; ++i){
            for(int j=1; j<=Tl; ++j){
                dp[i][j] = dp[i-1][j];
                if( S[i-1] == T[j-1] )
                    dp[i][j] += dp[i-1][j-1];                
            }
        }
        
        return dp[Sl][Tl];        
    }*/

	int numDistinct(string s, string t) {
     int n = s.length(), m = t.length();
     vector<int> dp(m+1, 0);
     dp[0] = 1;
     for (int j = 1; j <= n; j++){
         for (int i = m; i >= 1; i--){
             dp[i] += s[j-1] == t[i-1] ? dp[i-1] : 0;
         }
     }
    return dp[m];
}
};


int main()
{
	string s1 = "aa";
	string s2 = "a";
	Solution s;
	cout<<s.numDistinct(s1,s2)<<endl;

}