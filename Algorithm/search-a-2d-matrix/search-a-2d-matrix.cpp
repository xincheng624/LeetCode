#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if ( matrix.size() == 0 ) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; ++i){
            int j = n-1;
            for(; j>=0; --j){
                if ( target == matrix[i][j] )
                    return true;
                else if(target > matrix[i][j]){
                    break;
                }
            }
            if( j == -1 )
                break;
        }        
        
        return false;
    }
};

int main()
{
	//int a[3] = {1,2,3};
	//int b[3] = {4,5,6};
	//int c[3] = {7,8,9};

	int a[3] = {1};
	int b[3] = {4};
	int c[3] = {7};
	
	vector<int> v1(a,a+1);
	vector<int> v2(b,b+1);
	vector<int> v3(c,c+1);
	vector<vector<int> > v;
	Solution s;
	cout<<s.searchMatrix(v,1)<<endl;

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	
	cout<<s.searchMatrix(v,4)<<endl;



}