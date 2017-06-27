#include <iostream>
#include <string>
#include <hash_map>
#include <map>
using namespace std;
//模拟法
/*
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.empty() ) return 0;
        int len = 0;
        int max = -1;
        //hash_map<char,bool> m;
		int start = -1;
		map<char,int> m;
        for(int i=0; i<s.size(); ++i){
            if( m.find(s[i] ) == m.end() ){
                len++;
            }
            else{
                int index = m[s[i]];
				for(int j=start+1; j<=index; ++j)
				{
					m.erase(s[j]);
				}
				len = 1+len-(index-start);
				start = index;
            }
			if( len > max )
				max = len;
			m[s[i]] = i;
        }
        
        return max;
    }
};
*/
//简单遍历
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if( s.empty() ) return 0;
        int start = -1;
        int len = 0;
		vector<int> m(256,-1);
		for(int i=0; i<s.size(); ++i)
		{
			if( m[s[i]] > start )
				start = m[s[i]];
			m[s[i]] = i;
			len = max(len, i-start);
		} 
		return len;
    }
};


int main()
{
	string s1 = "abcabcdbacc";
	string s2 = "bbbba";
	string s3 ="wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	Solution s;
	cout<<s.lengthOfLongestSubstring(s1)<<endl;
	cout<<s.lengthOfLongestSubstring(s2)<<endl;
	cout<<s.lengthOfLongestSubstring(s3)<<endl;
}