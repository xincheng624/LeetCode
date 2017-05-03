#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root,sum,path,paths);
        return paths;   
        
    }
    
    void findPaths(TreeNode *node, int sum, vector<int> &path, vector<vector<int> > &paths){
        if ( node == NULL ) return;
        path.push_back(node->val);
        if(sum == node->val && node->left == NULL && node->right == NULL ){
            paths.push_back(path);
        }
        findPaths(node->left,sum-node->val,path,paths);
        findPaths(node->right,sum-node->val,path,paths);
        path.pop_back();
    }
};