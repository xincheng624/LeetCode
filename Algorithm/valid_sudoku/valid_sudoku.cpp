#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if( board.empty() || board[0].empty() )
            return false;
        int m = board.size();
        int n = board[0].size();
        
        bool usedRow[9][9] = {0};
        bool usedCol[9][9] = {0};
        bool usedMat[9][9] = {0};
        
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if( board[i][j] != '.' ){
                    int num = board[i][j]-'0'-1;
                    int k = i/3*3+j/3;
                    if( usedRow[i][num] || usedCol[num][j] || usedMat[k][num] )
                        return false;
                    usedRow[i][num] = usedCol[num][j] = usedMat[k][num] = true;
                }
            }
        }
        return true;
    }
};


int main()
{
	char a1[] = {'7','3','.','2','1','8','5','.','4'};
	char a2[] = {'2','1','.','.','.','9','.','.','3'};
	char a3[] = {'5','9','.','.','7','.','2','8','1'};
	char a4[] = {'3','4','1','8','6','.','9','2','7'};
	char a5[] = {'.','6','.','.','9','.','.','1','.'};
	char a6[] = {'9','5','2','.','4','1','8','3','6'};
	char a7[] = {'4','7','3','.','8','.','.','5','2'};
	char a8[] = {'6','.','.','1','.','.','.','4','9'};
	char a9[] = {'1','.','9','5','3','4','.','6','8'};
	vector<vector<char> > v;
	v.push_back(vector<char>(a1,a1+9));
	v.push_back(vector<char>(a2,a2+9));
	v.push_back(vector<char>(a3,a3+9));
	v.push_back(vector<char>(a4,a4+9));
	v.push_back(vector<char>(a5,a5+9));
	v.push_back(vector<char>(a6,a6+9));
	v.push_back(vector<char>(a7,a7+9));
	v.push_back(vector<char>(a8,a8+9));
	v.push_back(vector<char>(a9,a9+9));

	Solution s;
	cout<<s.isValidSudoku(v);
}