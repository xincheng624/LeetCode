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
 
bool compare(Interval& v1,Interval& v2){
        return v1.start < v2.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if ( intervals.size() <= 1 ) return intervals;
		sort(intervals.begin(),intervals.end(),[](Interval& v1,Interval& v2){return v1.start < v2.start;});
        
        vector<Interval> res;
        res.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); ++i){
            if (res.back().end < intervals[i].start){
                res.push_back(intervals[i]);
            }
            else{
                res.back().end = max(res.back().end, intervals[i].end);
            }          
            
        } 
		return res;
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
	v = s.merge(v);
}