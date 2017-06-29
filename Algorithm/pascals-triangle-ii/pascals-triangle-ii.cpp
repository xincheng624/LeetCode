#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        if( rowIndex < 0 ) return result;
        result.resize(rowIndex+1,0);
        result[0] = 1;
        for(int i=0; i<rowIndex; ++i){
            for(int j=i+1; j>=1; --j){
                result[j] += result[j-1];
            }
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> v = s.getRow(3);
}