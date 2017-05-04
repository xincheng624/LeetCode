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
    int run(TreeNode *root) {
        if( root == NULL ) return 0;
        int left = run( root->left);
        int right = run( root->right );
        if ( left != 0 && right != 0)
            return 1+ min( left, right);
        else 
            return 1+ max(left,right);
    }
};

int main()
{
	TreeNode l1(5);
	TreeNode l2(4);
	//TreeNode l3(3);
	//TreeNode l4(2);
	//TreeNode l5(1);
	l1.left = &l2;
	//l1.right = &l3;
	//l2.left = &l4;
	//l3.left = &l5;
	Solution s;
	cout<<s.run(&l1);
}