#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if( matrix.empty() || matrix[0].empty() ) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> left(n,0);
        vector<int> right(n,n);
        vector<int> height(n,0);
        int maxA = 0;
        for(int i=0; i<m; ++i){
            int cur_left = 0;
            int cur_right = n;
            for(int j=0; j<n; ++j){
                if( matrix[i][j] == '1' )
                    height[j]++;
                else
                    height[j] = 0;
            }
            
            for(int j=0; j<n; ++j){
                if( matrix[i][j] == '1' ){
                    left[j] = max(left[j],cur_left);
                }
                else{
                    left[j] = 0;
                    cur_left = j+1;
                }
            }
            
            for(int j=n-1; j>=0; --j){
                if( matrix[i][j] == '1' ){
                    right[j] = min(right[j],cur_right);
                }
                else{
                    right[j] = n;
                    cur_right = j;
                }
            }
            
            for(int j=0; j<n; ++j){
                maxA = max(maxA,(right[j]-left[j])*height[j]);
            }
            
        }
        return maxA;
    }
};


int main()
{
	char a[][3] = {{'1','0','0'},{'0','1','1'},{'0','1','1'}};
	vector<vector<char>> mat;
	for(int i=0; i<1; ++i)
		mat.push_back(vector<char>(a[i],a[i]+1));

	Solution s;
	cout<<s.maximalRectangle(mat)<<endl;
}