#include <string>
#include <iostream>
using namespace std;

/*class Solution {
public:
    string addBinary(string a, string b) {
        if( a.empty() && b.empty() ) return a;
        int overflow = 0;
        int ai = a.size()-1;
        int bi = b.size()-1;
        string c;
        int length = max(a.size(),b.size());
        c.resize(length+1);
        for(;ai >= 0 && bi >= 0; --ai,--bi){
            int sum = (a[ai]-'0') + (b[bi]-'0')+ overflow;
            overflow = sum/2;
            sum %= 2;
            c[length--] = sum + '0';            
        }       
        
        for(; ai>=0; --ai){
            int sum = a[ai]-'0' + overflow;
            overflow = sum/2;
            sum %= 2;
            c[length--] = sum + '0';  
        }
        for(; bi>=0; --bi){
            int sum = b[bi]-'0' + overflow;
            overflow = sum/2;
            sum %= 2;
            c[length--] = sum + '0'; 
        }
        
        if( overflow == 1 )
            c[0] = '1';
        else
            return string(c.begin()+1,c.end());
        
        return c;        
    }
};*/

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.length()-1;
        int j = b.length()-1;
        int overflow = 0;
        while( i>=0 || j>=0 || overflow ){
            overflow += i>=0 ? (a[i--]-'0'):0;
            overflow += j>=0 ? (b[j--]-'0'):0;
            s = char(overflow%2+'0') + s;
            overflow /= 2;
        }
        return s;
    }
};

int main()
{
	string s1 = "11";
	string s2 = "1";
	Solution s;
	string ss = s.addBinary(s1,s2); 
}