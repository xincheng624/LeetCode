#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if( tokens.empty() ) return 0;
        stack<int> tempResult;
        
        vector<string>::iterator it = tokens.begin();
        for(; it != tokens.end(); ++it){
            string expr = *it;
            if( expr != "+" && expr != "-" && expr != "*" && expr != "/" ){
				int num = atoi(expr.c_str());
                tempResult.push(num);
            }
            else{
                if( tempResult.size() <= 1 ) return 0;
                else{
                    int num1 = tempResult.top();
                    tempResult.pop();
                    int num2 = tempResult.top();
                    tempResult.pop();
                    int temp = 0;
					switch(expr[0]){
                        case '+':
                            temp = num2 + num1;
                            break;
                        case '-':
                            temp = num2 - num1;
                            break;
                        case '*':
                            temp = num2 * num1;
                            break;
                        case '/':
                            temp = num2 / num1;
                            break;                            
                    }
                    tempResult.push(temp);                    
                }                
            } 
        }   
        return tempResult.top();  
    }
             
};


int main()
{
	string a[] = {"2","1","+","3","*"};
	vector<string> s(a,a+5);
	Solution ss;
	cout<<ss.evalRPN(s)<<endl;


	string a1[] = {"4","13","5","/","+"};
	vector<string> s1(a1,a1+5);
	cout<<ss.evalRPN(s1)<<endl;
}