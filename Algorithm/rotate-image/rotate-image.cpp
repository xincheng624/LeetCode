#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        if( matrix.size() == 0 ) return;
        const int n = matrix.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n-i; ++j){
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
            }            
        }
        
        for(int i=0; i<n/2; ++i){
            for(int j=0; j<n; ++j){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }            
        }
                
    }
};

int main()
{
	int a[3] = {1,2,3};
	int b[3] = {4,5,6};
	int c[3] = {7,8,9};
	
	vector<int> v1(a,a+3);
	vector<int> v2(b,b+3);
	vector<int> v3(c,c+3);
	vector<vector<int> > v;
	Solution s;
	s.rotate(v);

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	
	s.rotate(v);
	
}