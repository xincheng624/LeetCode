#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
class Solution {
public:
    string multiply(string num1, string num2) {
        if( num1.empty() || num2.empty() ) return "";
        string result = "";
        int n = num2.size();
        vector<string> a(n,"");
        for(int i=0; i<n; ++i){
            a[i] = mul(num1,num2[i]);
			for(int j=0; j<num2.size()-1-i;++j)
				a[i] += "0";
			if( a[i][0] == '0' )
				a[i] = "0";
        }
        
        for(int i=0; i<n; ++i){
            result = add(result,a[i]);
        }
        
        return result;
    }
    
    string mul(string num1,char num2){
        string s = "";
        int over = 0;
        int m = num2 - '0';
        for(int i=num1.size()-1; i>=0;--i){
            int t = num1[i] - '0';
            t = t*m+over;
            over = t/10;
            t = t%10;
            s = to_string((long long)t)+s;
        }
		if( over > 0 )
			s = to_string((long long) over)+s;
		if( s[0] == '0' )
			s = "0";
        return s;
    }
    
    string add(string num1, string num2){
        int over = 0;
        string s = "";
        for(int i=num1.size()-1,j=num2.size()-1; i>=0 || j>=0 ; --i,--j){
            int t1 = 0;
            int t2 = 0;
            if( i>=0 )
                t1 = num1[i]-'0';
            if( j>=0 )
                t2 = num2[j]-'0';
            t1 = t1+t2+over;
            over = t1/10;
            t1 = t1%10;
            s = to_string((long long)t1)+s;
        }
		if( over > 0 )
			s = to_string((long long) over)+s;
        return s;
    }
    
};
*/

//
class Solution {
public:
    string multiply(string num1, string num2) {
        if( num1.empty() || num2.empty() ) return "";
        vector<int> temp(num1.size()+num2.size(),0);
        for(int i=num1.size()-1; i>=0; --i){
            for(int j=num2.size()-1; j>=0; --j){
                temp[i+j+1] += (num1[i]-'0')*(num2[j]-'0'); 
            }
        }
        
        int over = 0;
        for(int i=num1.size()+num2.size()-1; i>=0; --i){
            temp[i] += over;
            over = temp[i]/10;
            temp[i] %= 10;
        }
        
        int start=0;
        while( start<num1.size()+num2.size() && temp[start] == 0 )
            ++start;
        
        string s = "";
        while( start<num1.size()+num2.size() ){
            s += temp[start]+'0';
			++start;
        }
        return s;
	}
};

int main()
{
	string s1 = "140";
	string s2 = "721";
	Solution s;
	cout<<s.multiply(s1,s2)<<endl;
}