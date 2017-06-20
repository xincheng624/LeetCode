#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1<<n);
        for(int i = 0; i < (1<<n); ++i)
            ret[i] = i^(i>>1);
        return ret;
    }
};

/*
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code;
        code.push_back(0);
        int m = 1;
        for(int i=0; i<n; ++i){
            for(int j=code.size()-1; j>=0; --j){
                code.push_back(code[j]^m);
            }
            m = m<<1;            
        }
        
        return code;
    }
};
*/
int main()
{
	Solution s;
	s.grayCode(3);
}