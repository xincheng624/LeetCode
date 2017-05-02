/*Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path1->2->3which represents the number123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3

The root-to-leaf path1->2represents the number12.
The root-to-leaf path1->3represents the number13.
Return the sum = 12 + 13 =25.
*/

#include<iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int sumNumbers(TreeNode *root) {
		if ( root == NULL ) return 0;
        return pSumNum(root,0);
    }
    int pSumNum(TreeNode *root, int sum){
        if( root == NULL ) return 0;
        sum = sum*10 + root->val;
        if (root->left == NULL && root->right == NULL )
            return sum;
        return pSumNum(root->left,sum)+pSumNum(root->right,sum);
    }
};



int main()
{
	TreeNode l1(1);
	TreeNode l2(2);
	TreeNode l3(3);
	l1.left = &l2;
	//l1.right = &l3;

	Solution s;
	int a = s.sumNumbers(&l1);
}