#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string>  res;
        unordered_map<string,int> m;
        for(int i=0; i<strs.size(); ++i){
            string key = strs[i];
            sort(key.begin(),key.end());
            if( m.find(key) != m.end() ){
                if( m[key] != -2 ){
                    res.push_back(strs[m[key]]);
                }
                m[key] = -2;
                res.push_back(strs[i]);
            }
            else{
                m[key] = i;
            }
        }
        return res;
    }
};

int main()
{
	string a[] = {"tea","and","ate","eat","dan"};
	vector<string> strs(a,a+5);
	Solution s;
	vector<string> v = s.anagrams(strs);
	return 0;
}