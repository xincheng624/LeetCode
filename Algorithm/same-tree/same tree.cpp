#include <iostream>

using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };



class Solution {
    bool mark;
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if( p == NULL && q == NULL ) return true;
        if( p == NULL || q == NULL ) return false;
        mark = true;
        preorder(p,q);
        return mark;
    }
    
    void preorder(TreeNode *p, TreeNode* q){
        if ( p == NULL && q == NULL ) return;
        if ( p == NULL || q == NULL ){
            mark = false;
            return;
        }
        
        if ( q->val != p->val){
            mark = false;
            return;
        }
        
        preorder(p->left,q->left);
        preorder(p->right,q->right);
        
    }
};