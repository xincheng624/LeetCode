#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        vector<int> temp;
		sort(candidates.begin(),candidates.end());
        dfs(target,temp,0,candidates,result);
		return result;
    }
    void dfs(int target,vector<int>& temp,int i,vector<int>& candidate,vector<vector<int> >&result){
        if( target == 0 ){
            result.push_back(temp);
            return;
        }
        if( target < candidate[i] ) return;
        for(int j=i; j<candidate.size(); ++j){
            temp.push_back(candidate[j]);
            dfs(target-candidate[j],temp,j,candidate,result);
            temp.pop_back();
        }
    }
};

int main()
{
	//int a[] = {2,3,6,7};
	int a[] = {8,7,4,3};
	vector<int> v(a,a+4);
	Solution s;
	vector<vector<int> > result = s.combinationSum(v,11);
}