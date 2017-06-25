#include <iostream>
using namespace std;

//最简单的分治，但是x大的时候递归层数过多
/*
class Solution {
public:
    int sqrt(int x) {
        if( x < 0 ) return -1;
        int start = 0;
        int end = x;
        return help(start, end, x);
    }
    
    int help(int s, int e, int x){
        long long mid = (s+e)/2;
        if( mid*mid == x ){
            return mid;
        }
        else if( mid*mid < x ){
            mid = help(mid, e, x);
        }
        else{
            mid = help(s,mid,x);
        }
        return mid;
    }
};
*/
//循环2分
/*
class Solution {
public:
    int sqrt(int x) {
        if( x < 0 ) return -1;
        int start = 0;
        int end = x;
		while( start <= end ){
			long long mid = (start+end)/2;
			if( mid*mid == x ){
				return mid;
			}
			else if( mid*mid < x )
				start = mid+1;
			else
				end = mid - 1;
		}
		return end;
    }
    
};*/
//牛顿迭代
class Solution {
public:
    int sqrt(int x) {
		double e = 0.1;
		double x0 = x;
		while( abs(x0*x0-x) > 0.1 )
			x0 = (x0+x/x0)/2;
		return static_cast<int>(x0);
    }
    
};


int main()
{
	Solution s;
	cout<<s.sqrt(0)<<endl;
}