#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if( num.empty() ) return result;
        int len = num.size();
        sort(num.begin(),num.end());
        for(int i=0; i<len; ++i){
            int a = num[i];
            int tar3 = target - a;
            vector<int> res(4,0);
            for(int j=i+1; j<len; ++j){
                int b = num[j];
                int tar2 = tar3 - b;
                int k = j+1;
                int l = len-1;
                while( k<l ){
                    if( num[k]+num[l] == tar2 ){
                        res[0] = a;
                        res[1] = b;
                        res[2] = num[k];
                        res[3] = num[l];
                        result.push_back(res);
                        
                        while( k<l && num[k] == res[2] ) ++k;
                        while( k<l && num[l] == res[3] ) --l;
                    }
                    else if( num[k]+num[l] < tar2 ){
                        ++k;
                    }
                    else{
                        --l;
                    }
                }
                while( j+1<len && num[j+1] == num[j] ) ++j;
            }
            while( i+1<len && num[i+1] == num[i] ) ++i;
        }
        return result;
    }
};

int main()
{
	int a[] = {1, 0, -1, 0, -2, 2};
	vector<int> v(a,a+6);
	Solution s;
	vector<vector<int> > ans = s.fourSum(v,0);
}