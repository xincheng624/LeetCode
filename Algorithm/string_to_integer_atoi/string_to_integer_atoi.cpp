#include <iostream>
#include <cassert>
#include <exception>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
		int len = strlen(str);
        if( str == NULL && len <= 0 )
            return 0;
        
        long long sum = 0;
        int mul = 1;
		int i = 0;
		while(str[i] == ' ')
			++i;
        if( str[i] == '-' || str[i] == '+' )
            mul = 1-2*(str[i++] == '-');

        while(str[i] >='0' && str[i] <='9'){
			sum = sum*10+str[i]-'0';
			++i;
        }
        
        if( mul*sum > INT_MAX )
            return INT_MAX;
        else if( mul*sum < INT_MIN )
            return INT_MIN;
        
        return mul*sum;
    }
};

int main()
{
	try
	{
	Solution s;
	char* s1 = "123";
	cout<<s.atoi(s1)<<endl;
	char* s2 = "-1566";
	cout<<s.atoi(s2)<<endl;
	char* s3 = "1s3";
	cout<<s.atoi(s3)<<endl;
	char* s4 = " 010";
	cout<<s.atoi(s4)<<endl;

	char* s5 = " -2147483649";
	cout<<s.atoi(s5)<<endl;
	}
	catch(exception x)
	{
		cout<<x.what()<<endl;
	}
}