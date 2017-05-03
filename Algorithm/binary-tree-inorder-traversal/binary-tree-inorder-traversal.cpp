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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        if( root == NULL ) return inorder;
        stack<TreeNode *> s;
        TreeNode *cur = root;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top();
                s.pop();
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
        return inorder;
    }
    
    
};


int main()
{
	TreeNode l1(5);
	TreeNode l2(4);
	TreeNode l3(3);
	TreeNode l4(2);
	TreeNode l5(1);
	l1.left = &l2;
	l1.right = &l3;
	l2.left = &l4;
	l3.left = &l5;
	Solution s;
	vector<int> a = s.inorderTraversal(&l1);
}