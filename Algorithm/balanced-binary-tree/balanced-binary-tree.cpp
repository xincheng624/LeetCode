#include <iostream>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if( root == NULL ) return true;
		int dl =depthTree( root->left) ;
		int dr = depthTree( root->right);
        if( abs(depthTree( root->left) - depthTree( root->right)) > 1 )
            return false;
        
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int depthTree(TreeNode *root){
        if ( root == NULL ) return 0;
        return 1+max( depthTree(root->left), depthTree(root->right));
    }
};
*/

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return depthTree(root) != -1;
    }
    int depthTree(TreeNode *root){
        if ( root == NULL ) return 0;
        int leftDepth = depthTree(root->left);
        int rightDepth = depthTree(root->right);
        if ( leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
            return -1;
        
        return 1+max( leftDepth, rightDepth);
    }
};

int main()
{
	TreeNode l1(1);
	//TreeNode l2(2);
	TreeNode l3(1);
	//TreeNode l4(6);
	TreeNode l5(7);
	//l1.left = &l2;
	l1.right = &l3;
	//l2.left = &l4;
	l3.right = &l5;
	Solution s;
	cout<<s.isBalanced(&l1);
}