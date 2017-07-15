#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if( n<=0 ) return result;
        
        addDfs(result,n,0,"");
        return result;
    }
    
    void addDfs(vector<string>& result, int n, int m,string str){
        if( n==0 && m==0){
            result.push_back(str);
            return;
        }
        if( n>0 ) addDfs(result,n-1,m+1,str+'(');
        if( m>0 ) addDfs(result,n,m-1,str+')');
    }
};

int main()
{
	Solution s;
	vector<string> v = s.generateParenthesis(3);
}