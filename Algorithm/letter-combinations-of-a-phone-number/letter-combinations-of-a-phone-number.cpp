#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
		vector<string> result;
        result.push_back("");
        if( digits.empty() ) return result;
        string s2 = "abc";
        string s3 = "def";
        string s4 = "ghi";
        string s5 = "jkl";
        string s6 = "mno";
        string s7 = "pqrs";
        string s8 = "tuv";
        string s9 = "wxyz";
        map<int,string> m ;//= {{2,s2},{3,s3},{4,s4},{5,s5},{6,s6},{7,s7},{8,s8},{9,s9}};
		m[2] = s2;
		m[3] = s3;
		m[4] = s4;
		m[5] = s5;
		m[6] = s6;
		m[7] = s7;
		m[8] = s8;
		m[9] = s9;

        int N = digits.size();
        for(int i=0; i<N; ++i){
            string s = m[digits[i]-'0'];
			vector<string> temp;
			for(int j=0; j<result.size(); ++j)
			{
				for(int k=0; k<s.size(); ++k){
					temp.push_back(result[j]+s[k]);
				}
            }
			result = temp;
        }
        return result;
      }
};

int main()
{
	Solution s;
	vector<string> v = s.letterCombinations("234");
}