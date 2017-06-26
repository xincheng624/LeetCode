#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if( s == NULL ) return 0;
		int start = 0;
        int len = strlen(s);
		int end = len-1;
		while( len>=0 && *(s+end) == ' ' ) end--;
		while( end>=0 && *(s+end) != ' ' )
		{
			start++;
			end--;
		}
        
        return start;
    }
};


int main()
{
	char* s1 = "hello world11 test";
	char* s2 = "";
	char* s3 = "a3 ";
	Solution s;
	cout<<s.lengthOfLastWord(s1)<<endl;
	cout<<s.lengthOfLastWord(s2)<<endl;
	cout<<s.lengthOfLastWord(s3)<<endl;
}