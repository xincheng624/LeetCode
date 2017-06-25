#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<char,int> m;/* = {{ 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 }
                                 };*/


class Solution {
public:
    int romanToInt(string s) {
        if( s.empty() ) return 0;

        int sum = m[s.back()];
        for(int i=s.size()-2; i>=0; --i){
            if( m[s[i]]<m[s[i+1]] )
                sum -= m[s[i]];
            else
                sum += m[s[i]];  
            
        }
        return sum;
    }
};

int main()
{
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	string s1 = "MIV";
	Solution s;
	cout<< s.romanToInt(s1) <<endl;
}