#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if ( digits.empty() ) return vector<int>();
        
        if ( digits.back() != 9 ){
            digits.back() += 1;
            return digits;
        }
        else{
            int overflow = 0;
			digits.back() += 1;
            for(int i=digits.size()-1; i>=0; --i){
                digits[i] = digits[i] + overflow;
                overflow = digits[i]/10;
                digits[i] %= 10;
                if ( overflow == 0 )
                    break;                
            }
            
            if ( overflow == 1 ){
                digits.insert(digits.begin(),overflow);
                
            }          
            
        }            
      return digits;          
    }
};

int main()
{
	vector<int> v;
	for(int i=1; i<5; ++i)
	{
		v.push_back(9);
	}
	v.push_back(9);
	cout<<v.size()<<endl;
	Solution s;
	s.plusOne(v);
	for(int i=0; i<v.size(); ++i)
	{
		cout<<v[i];
	}
	cout<<endl<<v.size()<<endl;
}