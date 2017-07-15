#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Solution {
    bool mark;
public:
    void solveSudoku(vector<vector<char> > &board) {
        if( board.empty() || board[0].empty() ) return;
		mark = false;
        int m = board.size();
        int n = board[0].size();
        SudokuDFS(board,0,0,m,n);
    }
    
    void SudokuDFS(vector<vector<char> > &board, int i, int j,int m, int n){
		//cout<<"["<<i<<" "<<j<<"]"<<endl;
        if( i == m && j == 0 ){
            mark = true;
            return;
        }
        if( board[i][j] != '.' ){
            SudokuDFS(board, (j+1)/n+i, (j+1)%n, m, n);
        }
        else{
            for(int k=1; k<10; ++k){
                char input = '0'+k;
                if( checkSudoku(board,i,j,input,m,n) ){
                    board[i][j] = input;
                    SudokuDFS(board, (j+1)/n+i, (j+1)%n, m, n);
                    if( mark == true )
                        return;
                }
            }
            board[i][j] = '.';
        }
        
    }
    
    bool checkSudoku(vector<vector<char> > &board, int i, int j, char input,int m, int n){
        for(int k=0; k<m; ++k){
            if( board[k][j] == input )
                return false;
        }
        
        for(int k=0; k<n; ++k){
            if( board[i][k] == input )
                return false;
        }
        
        int k = i/3*3;
        int l = j/3*3;
        for(int ks=k; ks<k+3; ++ks){
            for(int ls=l; ls<l+3; ++ls){
                if(board[ks][ls] == input)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
	/*char a1[] = {'7','3','.','2','1','8','5','.','4'};
	char a2[] = {'2','1','.','.','.','9','.','.','3'};
	char a3[] = {'5','9','.','.','7','.','2','8','1'};
	char a4[] = {'3','4','1','8','6','.','9','2','7'};
	char a5[] = {'.','6','.','.','9','.','.','1','.'};
	char a6[] = {'9','5','2','.','4','1','8','3','6'};
	char a7[] = {'4','7','3','.','8','.','.','5','2'};
	char a8[] = {'6','.','.','1','.','.','.','4','9'};
	char a9[] = {'1','.','9','5','3','4','.','6','8'};*/
	vector<vector<char> > v(9,vector<char>(9,'0'));
	/*v.push_back(vector<char>(a1,a1+9));
	v.push_back(vector<char>(a2,a2+9));
	v.push_back(vector<char>(a3,a3+9));
	v.push_back(vector<char>(a4,a4+9));
	v.push_back(vector<char>(a5,a5+9));
	v.push_back(vector<char>(a6,a6+9));
	v.push_back(vector<char>(a7,a7+9));
	v.push_back(vector<char>(a8,a8+9));
	v.push_back(vector<char>(a9,a9+9));*/
	
	ifstream in;
	in.open("1.txt");

	for(int i=0; i<9; ++i)
	{
		string s;
		in >> s;
		for(int j=0; j<9; ++j)
		{
			v[i][j] = s[j];
		}
	}

	/*
..9748...
7........
.2.1.9...
..7...24.
.64.1.59.
.98...3..
...8.3.2.
........6
...2759..
	*/

	Solution s;
	s.solveSudoku(v);

	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
		{
			cout<<v[i][j];
			if( j != 8)
				cout<<" ";
			else
				cout<<endl;
		}
	}

}