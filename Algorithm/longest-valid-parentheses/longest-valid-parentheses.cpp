#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if( s.empty() ) return 0;
        int maxL = 0;
        stack<int> index;
        index.push(-1);
        for(int i=0; i<s.size(); ++i){
            int t = index.top();
            if( t != -1 && s[i] == ')' && s[t] =='(' ){
				index.pop();
                maxL = max(maxL,i-index.top());
            }
            else{
                index.push(i);
            }
        }
		return maxL;
    }
};

int main()
{
	string s1 = ")()())";
	Solution s;
	cout<<s.longestValidParentheses(s1)<<endl;
}