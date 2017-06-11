#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


 //* Definition for an interval.
struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
};
 
//直接覆盖法
/*class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {        
        vector<Interval> res;
        int i = 0;
        for(; i < intervals.size(); ++i){
            if( newInterval.end < intervals[i].start ){
                break;
            }
            
            else if( intervals[i].end < newInterval.start ){
                res.push_back( intervals[i] );
            }   
            
            else {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }           
            
        }    
        
        res.push_back(newInterval);
        for(; i < intervals.size(); ++i){
            res.push_back(intervals[i]);
        }
        return res;        
    }
};*/

//range法，比上面的方法慢些
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {        

		pair<vector<Interval>::iterator,vector<Interval>::iterator> range = equal_range( intervals.begin(), intervals.end(), newInterval,
			[](const Interval& v1, const Interval& v2){return v1.end < v2.start;} );

		vector<Interval>::iterator first = range.first;
		vector<Interval>::iterator second = range.second;

		if( first == second ){
			intervals.insert(first,newInterval);
		}
		else{
			second--;
			second->end = max(second->end, newInterval.end);
			second->start = min(first->start, newInterval.start);
			intervals.erase(first,second);
		}

        return intervals;        
    }
};



int main()
{
	vector<Interval> v;
	Interval i(1,3);
	Interval i1(2,4);
	v.push_back(i);
	v.push_back(i1);
	cout<<v.back().end;
	Solution s;
	Interval n(3,6);
	v = s.insert(v,n);
}