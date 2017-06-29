#include <iostream>
using namespace std;

//O(n)³¬Ê±
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        if( divisor == 0 ) return 0;
        int count = 0;
		int mark = 1;
		if( (dividend > 0 && divisor > 0 ) ||(dividend < 0 && divisor < 0 ) ){
			mark = 1;
        }
        else{
            mark = -1;
        }
        dividend = abs(dividend);
        divisor = abs(divisor);
        while( dividend-divisor >= 0 ){
            dividend -= divisor;
            ++count;
        }
        return mark*count;
    }
};
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        if( divisor == 0 || (dividend == INT_MIN && divisor == -1) )
            return INT_MAX;
        long long dvd = llabs(dividend);
        long long dis = llabs(divisor);
        int ans = 0;
        while(dvd >= dis){
            long long d = dis;
            long long m = 1;
            while( (d << 1) < dvd ){
				d = d<<1;
                m = m<<1;
            }
            dvd -= d;
            ans += m;
        }
        if( (dividend > 0 && divisor < 0) || (dividend<0 && divisor>0)){
            return -ans;
        }
        return ans;
    }
};


int main()
{
	Solution s;
	cout<<s.divide(2147483647,1)<<endl;
}