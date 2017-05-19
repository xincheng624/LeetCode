#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if ( num.size() < 3 ) return 0;
        int sum = num[0] + num[1] + num[2];
        sort(num.begin(),num.end());
        for(int first=0; first <= num.size()-2; ++first){
            if ( first>0 && num[first] == num[first-1] ) continue;
            int second = first+1;
            int third = num.size()-1;
            while ( second < third ){
                int temp = num[first]+num[second]+num[third];
                if (temp == target ) return target;
                if ( abs(temp-target) < abs(sum-target))
                    sum = temp;          
                
                
                if ( temp > target ) --third;
                else if ( temp < target ) ++second;               
                
            }                
            
          
        }      
        return sum;
        
    }
};

int main()
{
	vector<int> i;
	i.push_back(1);
	i.push_back(2);
	//i.push_back(-3);
	i.push_back(2);
	i.push_back(3);
	Solution s;
	cout<<s.threeSumClosest(i,2);
}