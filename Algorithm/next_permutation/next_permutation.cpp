#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		if( num.empty() ) return;
		//找到最后一组递增的2个数
		int k= -1;
		for(int i=num.size()-2; i>=0; --i)
		{
			if( num[i] < num[i+1] )
			{
				k = i;
				break;
			}
		}
		if( k == -1 )
		{
			reverse(num.begin(),num.end());
			return;
		}

		//找到最后比k位置的大的数
		int l=-1;
		for(int i=num.size()-1; i>=0; --i)
		{
			if( num[i] > num[k] )
			{
				l = i;
				break;
			}
		}
		int temp = num[l];
		//后面的数均比k位置的小，因此翻转一下
        reverse(num.begin()+k+1,num.end());
    }
};

int main()
{
	int a[] = {1,2,5,4};
	vector<int> num(a,a+4);
	Solution s;
	s.nextPermutation(num);
}