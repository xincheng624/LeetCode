#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
		if(s.empty()) return 0;
        int n = s.length();
		vector<int> dp(n+1,0);
        dp[0] = 1;
		if( s[0] >= '1' && s[0] <= '9')
			dp[1] = 1;
        for(int i=2; i<=n; ++i){
            if( s[i-1] >= '1' && s[i-1] <= '9' ){
				dp[i] = dp[i-1];
            }
            
			int t = 0;
			t = (s[i-2]-'0')*10+(s[i-1]-'0');
			if( t>=10 && t<=26 )
				dp[i] += dp[i-2]; 
        }
        
        return dp[n];
    }
};

int main()
{
	string s1 = "0121";
	Solution s;
	cout<<s.numDecodings(s1)<<endl;
}