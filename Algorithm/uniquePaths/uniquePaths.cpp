#include <iostream>
#include <vector>
using namespace std;

/*dfs �����ݳ�ʱ
class Solution {
    int paths;
public:
    int uniquePaths(int m, int n) {
        paths = 0;
        dfsMove(1,1,m,n);
        return paths;
    }
    
    void dfsMove(int i, int j, int m, int n){
        if( i == m && j == n ){
            ++paths;
            return;
        }
        
        if( i < m )
            dfsMove(i+1,j,m,n);
        if( j < n )
            dfsMove(i,j+1,m,n);        
    }
};
*/

// dp ��Ҫע��һ�㣬���ݴ�һ��ͻ������Ҫ����������ֻ�н����ݴ�Ϊstring���ͣ�
//Ȼ����string�ļӷ�
class Solution {
public:
    long long uniquePaths(int m, int n) {
        vector<vector<long long> > path(m,vector<long long>(n,0));
        path[0][0] = 1;
        for(int i=0; i<m; ++i){
            path[i][0] = 1;
        }
        for(int i=0; i<n; ++i){
            path[0][i] = 1;
        }
        
        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                path[i][j] = path[i-1][j]+path[i][j-1];
            }
        }
        
        return path[m-1][n-1];
    }
};

int main()
{
	Solution s;
	cout<<s.uniquePaths(30,20)<<endl;
}