#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string minWindow( string S, string T)
	{
		if( S.empty() || T.empty() || S.size()<T.size() )
			return "";
		vector<int> Tmap(128,0);
		for(int i=0; i<T.size(); ++i)
		{
			Tmap[T[i]]++;
		}

		int minStart = 0;
		int start = 0;
		int minLen = INT_MAX;
		int end = 0;
		int count = 0;
		while( end < S.size() )
		{
			if( Tmap[S[end]] > 0 ) 
				count++;
			Tmap[S[end]]--;
			end++;
			while( count == T.size() )
			{
				if( minLen > end-start )
				{
					minLen = end-start;
					minStart = start;
				}

				Tmap[S[start]]++;
				if(Tmap[S[start]] > 0)
				{
					count--;
				}
				start++;
			}
		}

		return minLen == INT_MAX? "":S.substr(minStart,minLen);
	}
};

int main()
{
	string s1 = "ADOBECODEBANC";
	string s2 = "ABC";
	Solution s;
	cout<<s.minWindow(s1,s2)<<endl;
}