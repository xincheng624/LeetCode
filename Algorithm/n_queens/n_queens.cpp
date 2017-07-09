#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<string> map(n,string(n,'.'));
        vector<int> queenXY(n,-1);
        dfs(0,n,map,result,queenXY);
        return result;
    }
    
    void dfs(int m, int size, vector<string>& map, vector<vector<string> >& result,vector<int>& queenXY){
        if( m == size ){
            result.push_back(map);
            return;
        }
        for(int i=0; i<size; ++i){
            map[m][i] = 'Q';
			queenXY[m] = i;
            if( checkNoAttack(m,i,size,queenXY) ){
                dfs(m+1,size,map,result,queenXY);
            }
			queenXY[m] = -1;
            map[m][i] = '.';
        }
    }
    
    bool checkNoAttack(int m, int i, int size, vector<int>& queenXY){
        for(int j=0; j<m; ++j){
            if(  queenXY[j] == i ){
                return false;
            }
            else if( (m-j) == ( queenXY[m]-queenXY[j] ) ){
                return false;
            }
            else if( (m-j) == -( queenXY[m]-queenXY[j] ) ){
                return false;
            }
            
        }
        return true;
    }
};

int main()
{
	Solution s;
	vector<vector<string> > v = s.solveNQueens(4);
}