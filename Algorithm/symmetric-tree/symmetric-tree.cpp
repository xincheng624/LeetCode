#include <iostream>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if ( root == NULL ) return true;
        return subSymetric(root->left,root->right);
    }
    bool subSymetric(TreeNode *left,TreeNode *right){
        if(left == NULL && right == NULL) return true;
        if( left == NULL || right == NULL ) return false;
        return left->val == right->val && subSymetric(left->left,right->right) && subSymetric(left->right,right->left);
    }
};