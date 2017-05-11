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
    TreeNode *first;
    TreeNode *second;
    TreeNode *tr;
public:
    void recoverTree(TreeNode *root) {
        if ( root == NULL ) return;
        
		first = NULL;
		second = NULL;
		tr = new TreeNode(INT_MIN);

		find(root);

        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void find(TreeNode *root){
        if (root == NULL) return;
        
        find(root->left);
        if ( first == NULL && tr->val > root->val ){
            first = tr;
        }
        
        if( first != NULL && tr->val > root->val ){
            second = root;
        }
        
        tr = root;
        
        find(root->right);        
        
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
	s.recoverTree(&root);
}