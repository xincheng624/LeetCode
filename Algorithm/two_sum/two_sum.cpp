#include <iostream>
#include <vector>
#include <hash_map>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if( numbers.size() < 2 ) return vector<int>();
        vector<int> result;
        for(int i=0; i<numbers.size(); ++i){
            for(int j=i+1; j<numbers.size(); ++j){
                if( numbers[i] + numbers[j] == target ){
                    result.push_back(i+1);
                    result.push_back(j+1);
                    return result;
                }
                 
            }
        }
         
        return result;
    }
};
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        if( numbers.size() < 2 ) return vector<int>();
        vector<int> result;
        unordered_map<int,int> m;

        for(int i=0; i<numbers.size(); ++i){
			if( m.find( target-numbers[i] ) != m.end() ){
                result.push_back(m[target-numbers[i]]+1);
				result.push_back(i+1);
                break;
            }

			m[numbers[i]] = i;
        }
        
        return result;
    }
};


int main()
{
	int a[] = {3,2,4,11};
	vector<int> numbers(a,a+4);
	Solution s;
	vector<int> v = s.twoSum(numbers,6);
	return 0;
}