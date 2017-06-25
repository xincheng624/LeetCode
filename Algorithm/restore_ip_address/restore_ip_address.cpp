#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if( s.empty() ) return vector<string>();
        vector<string> result;
        string addr = "";
        dfs(s,0,0,addr,result);
        return result;
    }
    
//private:
    void dfs(string& s, int index, int step, string& addr, vector<string>& result){
        if( step == 4 ){
			addr.pop_back();
			if( index == s.size() )
				result.push_back(addr);
            return;
        }
		if( s.size() - index > (4-step)*3 ) return;
		if( s.size() - index < (4-step) ) return;
        for(int i=1; i<=3 && index+i <= s.size(); ++i){
            string part = s.substr(index,i);
            if( IsIp(part) ){
                addr += part+".";
                dfs(s,index+i,step+1,addr,result);
				if( step < 3 ) addr.pop_back();
                for(int j=0; j<i; ++j){
                    addr.pop_back();
                }
            }
        }
    }

	bool IsIp(string& part){
		int ip = stoi(part);
		if( part[0] == '0' && part.size() > 1 )
			return false;
		if( ip >= 0 && ip <= 255 )
			return true;
		return false;
	}
    
};

int main()
{
	
	string s1 = "25525511135";
	Solution s;
	vector<string> r = s.restoreIpAddresses(s1);
}