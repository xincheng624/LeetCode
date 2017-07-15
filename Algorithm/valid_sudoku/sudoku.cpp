//œÎ∏¥‘”¡À
/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if( board.empty() || board[0].empty() ) return false;
        int m = board.size();
        int n = board[0].size();
		for(int i=0; i<m; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				if( !checkSudoku(board,i,j) )
					return false;
			}
		}
        return SodokuDFS(0,0,m,n,board);
    }

	bool checkSudoku(vector<vector<char> > &board,int i,int j)
	{
		int m = board.size();
        int n = board[0].size();
		unordered_map<char,int> c;
        for(int l=0; l<m; ++l){
			if(c.find(board[l][j]) == c.end() )
			{
				if( board[l][j] != '.' )
					c[board[l][j]] = 1;
			}
			else
				return false;
        }
		c.clear();
        for(int l=0; l<n; ++l){
            if( c.find(board[i][l]) == c.end() )
			{
				if( board[i][l] != '.' )
					c[board[i][l]] = 1;
			}
			else
				return false;
        }
		c.clear();
        int starti = (i/3)*3;
        int startj = (j/3)*3;
        for(int k=starti; k<starti+3; ++k){
            for(int l=startj; l<startj+3;++l){
                if(c.find(board[k][l]) == c.end() )
				{
					if( board[k][l] != '.' )
						c[board[k][l]] = 1;
				}
				else
					return false;
            }
        }
        
        return true;
	}
    
    bool SodokuDFS(int i, int j, int m, int n,vector<vector<char> > &board){
        if( i==m && j == 0) return true;
        bool mark = false;
        if( board[i][j] == '.' ){
            int num = 10;
            for(int k=1; k<num; ++k){
                char input = '0'+k;
                if( isValidNum(board,i,j,input) ){
                    board[i][j] = input;
                    mark = SodokuDFS((j+1)/n+i,(j+1)%n,m,n,board);
                    board[i][j] = '.';
                    if( mark )
                        break;
                }
            }
        }
        else{
            mark = SodokuDFS((j+1)/n+i,(j+1)%n,m,n,board);
        }
        return mark;
    }
    
    bool isValidNum(vector<vector<char> > &board,int i, int j, char input){
		int m = board.size();
        int n = board[0].size();
        for(int l=0; l<m; ++l){
            if( board[l][j] == input )
                return false;
        }
        for(int l=0; l<n; ++l){
            if( board[i][l] == input )
                return false;
        }
        
        int starti = (i/3)*3;
        int startj = (j/3)*3;
        for(int k=starti; k<starti+3; ++k){
            for(int l=startj; l<startj+3;++l){
                if(board[i][j] == input)
                    return false;
            }
        }
        
        return true;
    }
};
*/