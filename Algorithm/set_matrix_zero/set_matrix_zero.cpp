#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if( matrix.empty() || matrix[0].empty() ) return;
        int col0 = 1;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; ++i){
            if( matrix[i][0] == 0 ) col0 = 0;
            for(int j=1; j<n; ++j){
                if( matrix[i][j] == 0 ){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=1; --j){
                if( matrix[i][0] == 0 || matrix[0][j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
            if( col0 == 0 ){
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
	int a1[] = {1,1,1};
	int a2[] = {0,1,2};
	vector<vector<int> > v;
	v.push_back(vector<int>(a1,a1+3));
	v.push_back(vector<int>(a2,a2+3));
	Solution s;
	s.setZeroes(v);
}