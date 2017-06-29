#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
		sort(num.begin(),num.end());
        int len = num.size();
        for(int i=0; i<len-2; ++i){
            int a = num[i];
			int j = i+1;
			int k = len-1;
            vector<int> res(3,0);
            while( j<k ){
                if( a + num[j] + num[k] == 0 ){
					res[0] = a;
					res[1] = num[j];
					res[2] = num[k];
					result.push_back(res);
					while( j<k && num[j] == res[1] ) ++j;
					while( j<k && num[k] == res[2] ) --k;
                }
				else if( a + num[j] + num[k] > 0 )
				{
					--k;
				}
				else
				{
					++j;
				}
            }
            while( i+1<len && num[i+1] == num[i]) ++i;
        }
        
        return result;
    }
};

int main()
{
	int a[] = {-1, 0, 1, 2, -1, -4};
	//int a[] = {0,-1,1};
	vector<int> n(a,a+6);
	Solution s;
	vector<vector<int> > v= s.threeSum(n);
}