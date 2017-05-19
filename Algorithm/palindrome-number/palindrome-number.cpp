#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x<0 || ( x>0 && x%10 == 0) ) return false;
        int o = x, re = 0;
        while( x > re ){
            re = re*10 + x%10;
            x /= 10;
        }
        return (x == re || re/10 == x);
    }
    
 
};

int main()
{
	
	Solution s;
	cout<<s.isPalindrome(100);
	cout<<s.isPalindrome(-1);
	cout<<s.isPalindrome(1000000001);
}