#include <iostream>
using namespace std;

class Solution {
public:
	Solution():error(true){}
	bool error;
    double pow(double x, int n) {
		error = true;
        if( n == 0 && !equal(x,0.0) )  return 1;
        if( equal(x,0.0) && n > 0 )  return 0;
		if( equal(x,0.0) && n <= 0 ){
			error = false;
			return 0.0;
		}
		unsigned long p = n;
        if( n < 0 ){
            x = 1/x;
           // if( n == INT_MIN )
            //    n = INT_MAX;
            //else
                p = -n;
        }

		double temp = powN(x,n);

        return temp;
    }

	double powN(double x, int n){
		if( n == 0 ) return 1;
		double result = powN(x,n>>1);
		result *= result;
		if( n&0x1 == 1 )
			return result *= x;
		else
			return result;
	}


	bool equal(double num1, double num2)
	{
		if( abs(num1-num2) < 0.000001 )
			return true;
		else
			return false;
	}
};

int main()
{
	Solution s;
	//cout<<s.pow(2,3)<<endl;
	//cout<<s.pow(2,-3)<<endl;
	//cout<<s.pow(0,1)<<endl;
	//cout<<s.pow(0.5,-2)<<endl;
	//cout<<s.pow(0,-2)<<endl;
	//cout<<"Error: "<<s.error<<endl;
	cout<<s.pow(-1,-2147483648)<<endl;
	//cout<<s.pow(2,100)<<endl;
}