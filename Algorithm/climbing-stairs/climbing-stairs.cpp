#include <iostream>
using namespace std;
/*dp O(1)�ռ� O(n)ʱ��
class Solution {
public:
    int climbStairs(int n) {
        int f = 0;
        int g = 1;
        for(int i=0; i<n; ++i){
            g += f;
            f = g-f;
        }
        return g;
    }
};
*/
//dp O(n)�ռ� O��n)ʱ�䣬ע�����
class Solution {
public:
    int climbStairs(int n) {
        int *s = new int[n];
        s[0] = 1;
        s[1] = 2;
        for(int i=2; i<n; ++i){
            s[i] = s[i-1] + s[i-2];
        }
        return s[n-1];
    }
};

int main()
{
	Solution s;
	cout<<s.climbStairs(20)<<endl;
}