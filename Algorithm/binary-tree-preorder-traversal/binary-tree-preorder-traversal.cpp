/*Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},
   1
    \
     2
    /
   3

return[1,2,3].
*/

#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> preorder;
        if ( root == NULL ) return preorder;
        stack<TreeNode *> tmp;
        tmp.push(root);
        while( !tmp.empty() ){
            TreeNode *node = tmp.top();
            tmp.pop();
            preorder.push_back(node->val);
            if ( node->right != NULL )
                tmp.push(node->right);
            if(node->left != NULL )
                tmp.push(node->left);
        }
        return preorder;
    }
    
};