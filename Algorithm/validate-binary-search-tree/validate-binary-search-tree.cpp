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
    bool isValidBST(TreeNode *root) {
		return BFS(root,NULL,NULL);
    }
    bool BFS(TreeNode *root, TreeNode *minNode, TreeNode *maxNode){
        if ( root == NULL ) return true;
        if ( minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val )
            return false;
        return BFS(root->left,minNode,root) && BFS(root->right,root,maxNode);
    }
};


int main()
{
	TreeNode l1(5);
	TreeNode l2(2);
	TreeNode l3(1);
	TreeNode l4(6);
	TreeNode l5(7);
	l1.left = &l2;
	l1.right = &l3;
	l2.left = &l4;
	l2.right = &l5;
	Solution s;
	cout<<s.isValidBST(&l1);
}