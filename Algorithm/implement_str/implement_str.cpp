#include <iostream>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if( haystack == NULL && needle == NULL ){
            return NULL;
        }
		int lenh = strlen(haystack);
		int lenn = strlen(needle);
		if( lenh < lenn ) return NULL;

		for(int i=0; i<=lenh-lenn; ++i)
		{
			int j=0;
			while( j<lenn && haystack[i+j] == needle[j] )
			{
				++j;
			}
			if( j == lenn )
				return haystack+i;
		}
        
        return NULL;
    }
};

int main()
{
	char* p1 = "a";
	char* p2 = "a";
	Solution s;
	char* p = s.strStr(p1,p2);
}