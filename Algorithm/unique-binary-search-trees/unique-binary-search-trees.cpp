#include <iostream>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        int *G = new int[n+1];
        G[0] = G[1] = 1;
        for( int i = 2; i <= n ;++i){
			G[i] = 0;
            for(int j = 1; j <= i; ++j){
                G[i] += G[j-1]*G[i-j];
				//G[n] = F(0,n)+F(1,n)+...+F(n.n);
				//F(i,n) = G(i-1)*G(n-i);
            }
        }
        int Num = G[n];
        delete[] G;
        return Num;
    }
};

int main()
{
	Solution s;
	cout<<s.numTrees(2);
}