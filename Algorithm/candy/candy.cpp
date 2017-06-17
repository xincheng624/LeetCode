#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        if( ratings.empty() ) return 0;
        int length = ratings.size();
        vector<int> candy(length,1);
        for( int i=0; i<length-1; ++i){           
            if( ratings[i] < ratings[i+1] )
                candy[i+1] = candy[i] + 1;            
        }
        
        for( int i=length-1; i>=1; --i){
            if( ratings[i-1] > ratings[i] )
			{
				if( candy[i-1] <= candy[i] )
					candy[i-1] = candy[i] + 1;
			}
        }
        
        int sum = 0;
        for( int i=0; i<length; ++i){
            sum += candy[i];            
        }      
        return sum;
    }
};

int main()
{
	Solution s;
	int a[] = {2,1,5,7,6};
	vector<int> ratings(a,a+2);
	cout<<s.candy(ratings)<<endl;
}