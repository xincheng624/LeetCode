#include <iostream>
#include <vector>
using namespace std;
//O(n)¿Õ¼ä dp
/*class Solution {
public:
    int jump(int A[], int n) {
        if( n<=0 ) return -1;
        vector<int> dp(n,-1);
        dp[0] = 0;
		static int c = 0;
        for(int i=0; i<n; ++i){
            for(int j=0; j<A[i]; ++j){
                if( i+j+1 < n && dp[i] != -1 )
				{
					
					c++;
					if( dp[i+j+1] == -1)
						dp[i+j+1] = dp[i]+1;
				}
            }
        }
        cout<<c<<endl;
        return dp[n-1];
    }
};*/

//O(1)¿Õ¼ä dp
class Solution
{
public:
	int jump(int A[], int n)
	{
		if( n<=0 ) return -1;
		int cover = 0;
		int step = 0;
		int last = 0;
		for(int i=0; i<n && cover>=i; ++i)
		{
			if( i > last  )
			{
				last = cover;
				++step;
			}
			cover = max(cover,i+A[i]);
			if( last >= n-1 )
				break;
		}
		return step;
	}
};



int main()
{
	int a[] = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	Solution s;
	cout<<s.jump(a,15)<<endl;
}