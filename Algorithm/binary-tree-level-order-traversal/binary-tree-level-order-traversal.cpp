#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if ( root == NULL ) return result; 
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while( !q.empty() ){
            TreeNode* node = q.front();
            q.pop();
            if ( node != NULL ){
                level.push_back(node->val);
                if( node->left != NULL )
                    q.push(node->left);
                if( node->right != NULL )
                    q.push(node->right);
            }
            else{
                result.push_back(level);
                level.resize(0);
                if ( !q.empty() )q.push(NULL);
            }
        }
        
        return result;
        
    }
};

int main()
{
	TreeNode root(1);
	TreeNode left(2);
	TreeNode right(3);
	root.left = &left;
	root.right = &right;
	Solution s;
	s.levelOrder(&root);
}