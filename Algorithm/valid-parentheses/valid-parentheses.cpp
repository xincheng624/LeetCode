#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> mark;
        for(int i=0; i<s.size(); ++i){
            if( s[i] == '('){
                mark.push(')');
            }
            else if( s[i] == '{' ){
                mark.push('}');
            }
            else if( s[i] == '[' ){
                mark.push(']');
            }
            else{
                if( mark.empty() || s[i] != mark.top() ){
                    return false;
                }
                else{
                    mark.pop();
                }
            }
        }
        if( mark.empty() )
            return true;
        else
            return false;
    }
};

int main()
{
	string s1 = "(){[]}";
	Solution s;
	cout<<s.isValid(s1)<<endl;
}