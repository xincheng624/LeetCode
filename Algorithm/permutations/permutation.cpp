#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		if( num.empty() ) return vector<vector<int> >();
		vector<vector<int> > result;
		permutation(num,0,result);
		return result;
    }

	void permutation(vector<int>& num, int begin, vector<vector<int> >& result){
		if( begin == num.size() ){
			result.push_back(num);
			return;
		}

		for(int i=begin; i<num.size(); ++i){
			swap(num[begin],num[i]);
			permutation(num,begin+1,result);
			swap(num[begin],num[i]);
		}	
	}

};

int main()
{
	Solution s;
	int a[] = {1,2,3};
	vector<int> num(a,a+3);
	vector<vector<int> > v = s.permute(num);
}