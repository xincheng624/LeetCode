#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	//dp
    bool canJump(int A[], int n) {
        vector<bool> reach(n,false);
        reach[0] = true;
        for(int i=0; i<n&&reach[i]; ++i){
			for(int j=i+1; j<=i+A[i]; ++j){
				if( j<n )
					reach[j] = true;
				if( j >= n-1 )
					return true;
            }
		}
        return reach[n-1];
    }

	//dp Ì°ÐÄ
	bool canJump1(int A[], int n)
	{
		int max = 0;
		for(int i=0; i<n && max>=i; ++i)
		{
			if(i+A[i] > max)
				max = i+A[i];
		}
		return max>=n-1;
	}
};





int main()
{
	int a[] = {1,2};
	Solution s;
	cout<<s.canJump(a,2)<<endl;
	cout<<s.canJump1(a,2)<<endl;
}