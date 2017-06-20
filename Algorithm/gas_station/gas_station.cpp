#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if( gas.empty() || cost.empty() || gas.size() != cost.size() ) return -1;
        int start = gas.size()-1;
        int end = 0;
        int sum = gas[start] - cost[start];
        while( start > end ){
            if( sum >=0 ){
                sum += gas[end] - cost[end];
                ++end;
            }
            else{
                --start;
                sum += gas[start] - cost[start];
            }
        }
        
        return  sum>=0? start:-1;
    }
};



int main()
{
	int a[] = {1,1,4,8};
	vector<int> gas(a,a+4);
	int b[] = {1,11,1,1};
	vector<int> cost(b,b+4);
	Solution s;
	cout<<s.canCompleteCircuit(gas,cost)<<endl;
}