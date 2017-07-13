#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if( n<=0 || k<=0 || n<k) return result;
        vector<int> temp;
        dfs(n+1,k,1,0,temp,result);
        return result;
    }
    
    void dfs(int n, int k, int start, int num, vector<int>& temp, vector<vector<int> >& result){
        if( num == k ){
            result.push_back(temp);
            return;
        }
        for(int i=start; i<n-(k-num-1); ++i){
            temp.push_back(i);
            dfs(n,k,i+1,num+1,temp,result);
            temp.pop_back();
        }
    }
};

int main()
{
	Solution s;
	vector<vector<int> > v = s.combine(4,3);
}