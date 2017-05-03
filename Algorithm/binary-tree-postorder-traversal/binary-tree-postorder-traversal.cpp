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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> postorder;
		if(root == NULL ) return postorder;
        stack<TreeNode *> tmp;
        stack<int> p;
        tmp.push(root);
        while( !tmp.empty() ){
            TreeNode *node = tmp.top();
            tmp.pop();
            p.push(node->val);
			if( node->left != NULL )
                tmp.push(node->left);
            if( node->right != NULL )
                tmp.push(node->right);
            
        }
        while( !p.empty() ){
            postorder.push_back(p.top());
            p.pop();
        }
        return postorder;
    }
};

int main()
{
	TreeNode l1(3);
	TreeNode l2(1);
	TreeNode l3(2);
	//TreeNode l4(-1);
	//TreeNode l5(-1);
	l1.left = &l2;
	
	l1.right = &l3;
	//l2.left = &l4;
	//l3.left = &l5;
	Solution s;
	vector<int> a = s.postorderTraversal(&l1);
}