#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if( numRows <= 0 ) return result;
        vector<int> before;
        before.push_back(1);
        vector<int> after;
        for(int i=0; i<numRows; ++i){
            after.resize(i+1,0);
            after[0] = 1;
            after.back() = 1;
            for(int j=1; j<i && i>1; ++j){
                after[j] = before[j-1]+before[j];
            }
            result.push_back(after);
            before.swap(after);
        }
        
        return result;
    }
};
*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if( numRows <= 0 ) return result;
        result.resize(numRows,vector<int>());
        for(int i=0; i<numRows; ++i){
            result[i].resize(i+1,1);
            for(int j=1; j<i; ++j ){
                result[i][j] = result[i-1][j-1]+result[i-1][j];
            }
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<vector<int> > v = s.generate(6);
}