#include <iostream>
#include <sstream>
using namespace std;

//int i = 123;
//string s1 = to_string((long long)i);

class Solution {
public:
    string countAndSay(int n) {
        if( n <= 0 ) return "";
        
        string s = "1";
		for(int i=1; i<n; ++i)
		{
			s = count(s);
		}        
        
		return s;
    }

	string count(string& s)
	{
		int count = 0;
		char c = s[0];
		int num = s.size();
 
		string temp = "";
		for(int j=0; j<num; ++j){
			if( s[j] == c ){
				++count;
				continue;
			}
			if( count > 0 )
			{
				string nz;
				stringstream os;
				os<<count;
				os>>nz;
				temp += nz;
				temp += c;
				count = 1;
				c = s[j];
			}
		}

		if( count>0 )
		{
			string nz;
			stringstream os;
			os<<count;
			os>>nz;
			temp += nz;
			temp += c;
		}
		s = temp;

		return s;
	}

};

int main()
{
	Solution s;
	cout<<s.countAndSay(4);
}