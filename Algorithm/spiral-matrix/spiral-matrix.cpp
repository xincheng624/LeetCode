#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        if( matrix.size() <= 0 ) return vector<int>();
        vector<int> ret;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int start = 0;
        while( rows > start*2 && cols > start*2 ){
            int endX = cols - 1 - start;
            int endY = rows - 1 - start;
            
            for(int i=start; i<=endX; ++i){
                int num = matrix[start][i];               
                ret.push_back(num);
            }           
            
            if( start < endY ){
                for(int i=start+1; i<=endY; ++i){
                    int num = matrix[i][endX];
                    ret.push_back(num);
                }                
            }
            
            if( start < endX && start < endY ){
                for(int i=endX-1; i>=start; --i){
                    int num = matrix[endY][i];
                    ret.push_back(num);
                }
            } 
            
            if( start < endX && start < endY-1 ){
                for(int i=endY-1; i>=start+1; --i){
                    int num = matrix[i][start];
                    ret.push_back(num);
                }
            }
            
            ++start;
        }        
        
        return ret;
    }
};


int main()
{
	vector<vector<int> > matrix;
	vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	v.push_back(3);
	matrix.push_back(v);
	v.clear();

	v.push_back(2);
	//v.push_back(5);
	//v.push_back(6);
	matrix.push_back(v);
	v.clear();

	/*v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	matrix.push_back(v);
	v.clear();
	*/
	Solution s;
	v = s.spiralOrder(matrix);
}