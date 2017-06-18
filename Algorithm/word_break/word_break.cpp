#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
bool help(string& s, int first, int last, unordered_set<string>& dict);

bool wordBreak(string s, unordered_set<string> &dict) {
        if( s.empty() ) return true;
        int length = s.length();
        int first = 0;
        for(int last=1; last<=length; ++last){
            if( help(s,first, last, dict) )
				return true;
            
        }
		
		return false;

    }
    
bool help(string& s, int first, int last, unordered_set<string>& dict){
		if( first == s.length() ) return true;
		string t(s.begin()+first,s.begin()+last);
		if( dict.find(t) != dict.end() )
		{
			return wordBreak(s.substr(last),dict);
		}
		else
			return false;
    }
*/

bool wordBreak(string& s, unordered_set<string>& dict)
{
	if( s.empty() && !dict.empty() ) return false;
	vector<bool> dp(s.size()+1,false);
	dp[0] = true;
	for(int i=1; i<=s.size(); ++i)
	{
		for(int j=i-1; j>=0; --j)
		{
			if(dp[j])
			{
				string word = s.substr(j,i-j);
				if( dict.find(word) != dict.end() )
				{
					dp[i] = true;
					break;
				}
			}
			
		}
	}
	return dp[s.size()];
}



int main()
{
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");

	string s = "leetcode";
	cout<<wordBreak(s,dict)<<endl;
}