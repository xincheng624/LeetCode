#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int max = -2147483648;
        findMaxSum(root,max);
        return max;
    }
    
    int findMaxSum(TreeNode *root, int& m){
        int left = 0;
        int right = 0;
        if( root == NULL ) {
            return 0;
        }
        left = findMaxSum(root->left,m);
        right = findMaxSum(root->right,m);
        if ( left < 0 ) left = 0;
        if ( right < 0 ) right = 0;
        
        if ( left+right+root->val > m ) m = left+right+root->val;
        return root->val += max(left,right);
        
    }
};

int main()
{
	TreeNode l1(3);
	TreeNode l2(-2);
	TreeNode l3(-1);
	TreeNode l4(-1);
	TreeNode l5(-1);
	l1.left = &l2;
	l1.right = &l3;
	l2.left = &l4;
	l3.left = &l5;
	Solution s;
	int a = s.maxPathSum(&l1);
}