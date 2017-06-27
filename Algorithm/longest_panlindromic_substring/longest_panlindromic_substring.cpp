#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if( s.empty() ) return "";
        int len = s.size();
        int maxl = -1;
        int half = 0;
        string str = "";
        string ans = "";
        for(int i=0; i<len; ++i){
            str += "#";
            str += s[i];
        }
        str += "#";
        for(int i=1; i<2*len; ++i){
            half = 0;
            while( (i-half >=0) && (i+half <= 2*len) && str[i-half] == str[i+half] )
                ++half;
            half--;
            if( half > maxl ){
                maxl = half;
                ans = s.substr((i-half)/2, (i+half)/2-(i-half)/2);
            }
        }
        return ans;
    }
};

int main()
{
	string s1 = "a";
	Solution s;
	cout<<s.longestPalindrome(s1)<<endl;
}