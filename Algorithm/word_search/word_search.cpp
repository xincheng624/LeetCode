#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if( board.empty() ||  board[0].empty() || word.empty() )
            return false;
        int m = board.size();
        int n = board[0].size();
		if( m*n < word.size() ) return false;
		for(int i=0; i<m; ++i){
			for(int j=0; j<n; ++j){
				if( dfs(i,j,m,n,0,word,board) )
					return true;
			}
		}
        return false;
    }
    
    bool dfs(int i, int j, int m, int n, int k,string& word, vector<vector<char> >& board){
        if( k == word.size() )
            return true;
		if( i<0 || i >=m || j<0 || j>=n || board[i][j] != word[k] ) return false;
		bool flag  = false;
        if( board[i][j] == word[k] ){
			char c = board[i][j];
			board[i][j] = '*';
            if( !flag && i>0 )flag |= dfs(i-1,j,m,n,k+1,word,board);
			if( !flag && i<m )flag |= dfs(i+1,j,m,n,k+1,word,board);
			if( !flag && j>0 )flag |= dfs(i,j-1,m,n,k+1,word,board);
			if( !flag && j<n )flag |= dfs(i,j+1,m,n,k+1,word,board);
			board[i][j] = c;
        }
        return flag;
    }
};

int main()
{
	char a1[] = {'A','B','C','E'};
	char a2[] = {'S','F','C','S'};
	char a3[] = {'A','D','E','E'};
	char a4[] = {'a','a','a','a'};
	string word1 = "ABCCED";
	string word2 = "SEE";
	string word3 = "ABCB";
	vector<vector<char> > v;
	v.push_back(vector<char>(a1,a1+4));
	v.push_back(vector<char>(a2,a2+4));
	v.push_back(vector<char>(a3,a3+4));
	Solution s;
	cout<<s.exist(v,word1);
	cout<<s.exist(v,word2);
	cout<<s.exist(v,word3);
	v.clear();
	v.push_back(vector<char>(a4,a4+4));
	v.push_back(vector<char>(a4,a4+4));
	v.push_back(vector<char>(a4,a4+4));
	string word4 = "aaaaaaaaaaab";
	cout<<s.exist(v,word4);
}