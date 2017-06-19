#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//排序法
/*bool comp(vector<int>& v1, vector<int>& v2)
{
	if( v1.size() != v2.size() )
		return v1.size() < v2.size();
	for(int i=0; i<v1.size();++i)
	{
		if( v1[i] != v2[i] )
			return v1[i] < v2[i];
	}
}*///全局排序

/*class Solution {
public:

	static bool comp(vector<int>& v1, vector<int>& v2)
	{
		if( v1.size() != v2.size() )
			return v1.size() < v2.size();
		for(int i=0; i<v1.size();++i)
		{
			if( v1[i] != v2[i] )
				return v1[i] < v2[i];
		}
	}//类中静态函数排序

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> subs;
        vector<int> sub;
        getSubs(S,0,sub,subs);   
		sort(subs.begin(),subs.end(),comp);
        return subs;
    }
    
    void getSubs(vector<int>& S, int num, vector<int>& sub, vector<vector<int> >& subs){
        subs.push_back(sub);
        for(int i=num; i<S.size(); ++i){
            sub.push_back(S[i]);
            getSubs(S,i+1,sub,subs);
            sub.pop_back();
        }
    }


	
};
*/

/*
class Solution {
public:

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int>> subs;
        vector<int> sub;
        getSubs(S,0,sub,subs);   
		sort(subs.begin(),subs.end(),[](vector<int>& v1, vector<int>& v2)->bool{
            if( v1.size() != v2.size() )
                return v1.size() < v2.size();
            for(int i=0; i<v1.size();++i)
            {
                if( v1[i] != v2[i] )
                    return v1[i] < v2[i];
            } 
			return true;
        }     //lamba排序     
            );
        return subs;
    }
    
    void getSubs(vector<int>& S, int num, vector<int>& sub, vector<vector<int> >& subs){
        subs.push_back(sub);
        for(int i=num; i<S.size(); ++i){
            sub.push_back(S[i]);
            getSubs(S,i+1,sub,subs);
            sub.pop_back();
        }
    }

};
*/
//回溯法
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> subs;
		vector<int> sub;
		sort(S.begin(),S.end());
		int n = S.size();
		for(int i=0; i<=n; ++i)
		{
			getSubs(S,n,i,0,sub,subs);
		}
		return subs;
    }

	void getSubs(vector<int>& S, int n, int k, int begin, vector<int>& sub, vector<vector<int>>& subs)
	{
		if( sub.size() == k )
		{
			subs.push_back(sub);
			return;
		}

		for(int i=begin; i<n; ++i)
		{
			sub.push_back(S[i]);
			getSubs(S,n,k,i+1,sub,subs);
			sub.pop_back();
		}
	}
};

int main()
{
	int a[] = {1,2,3};
	vector<int> S(a,a+3);
	Solution s;
	vector<vector<int> > subs = s.subsets(S);
}