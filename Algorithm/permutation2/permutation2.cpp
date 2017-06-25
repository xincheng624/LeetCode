#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if( num.empty() ) return vector<vector<int> >();
		sort(num.begin(),num.end());
        vector<vector<int> > result;
        dfs(num,0,result);
        return result;
    }
    
    void dfs(vector<int> num, int begin, vector<vector<int> >& result){
        if( begin == num.size() ){
            result.push_back(num);
            return;
        }
        
        for(int i=begin; i<num.size();++i){
            if( i != begin && num[i] == num[begin] ) continue;
            swap(num[begin],num[i]);
            dfs(num,begin+1,result);
			//swap(num[begin],num[i]);
        }
        
    }
};
*/
//set没有重复项来保存
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if( num.empty() ) return vector<vector<int> >();
		sort(num.begin(),num.end());
		set<vector<int>> res;
        dfs(num,0,res);
        return vector<vector<int> >(res.begin(),res.end());
    }
    
    void dfs(vector<int>& num, int begin, set<vector<int> >& result){
        if( begin == num.size() ){
			result.insert(num);
            return;
        }
        
        for(int i=begin; i<num.size();++i){
            if( i != begin && num[i] == num[begin] ) continue;
            swap(num[begin],num[i]);
            dfs(num,begin+1,result);
			swap(num[begin],num[i]);
        }
        
    }
};

int main()
{
	Solution s;
	int a[] = {1,1,2,2};
	vector<int> num(a,a+4);
	vector<vector<int> > v = s.permuteUnique(num);
}