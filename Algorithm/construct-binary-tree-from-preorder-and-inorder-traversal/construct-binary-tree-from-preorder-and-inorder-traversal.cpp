#include <iostream>
#include <vector>
using namespace std;
//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if ( preorder.size() <=0 || inorder.size() <= 0 
            ||preorder.size() != inorder.size()) 
            return NULL;
        
        int node = preorder[0];
        TreeNode *root = new TreeNode(node);
        if ( preorder.size() == 1 && inorder.size() == 1 ) return root;
        int i = 0;
        for( i = 0; i<inorder.size(); ++i){
            if ( inorder[i] == node )
                break;
            
            if ( i == inorder.size() - 1 )
                return NULL;
        }
        
        vector<int> preleft;
        vector<int> preright;
        vector<int> inleft;
        vector<int> inright;
        for( int j=1; j<=i; ++j){
            preleft.push_back(preorder[j]);
			inleft.push_back(inorder[j-1]);
        }

        for( int j=i+1; j<preorder.size();++j){
            preright.push_back(preorder[j]);
            inright.push_back(inorder[j]);
        }
        
        if ( preleft.size() != 0 ){
            root->left = buildTree( preleft, inleft);
        }
        if ( preright.size() != 0 ){
            root->right = buildTree( preright, inright);
        }
        
        return root;       
        
        
    }
};







int main()
{
	TreeNode root(1);
	TreeNode left(2);
	//TreeNode right(3);
	root.left = &left;
	//root.right = &right;
	vector<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	vector<int> r;
	r.push_back(2);
	r.push_back(1);
	r.push_back(2);
	TreeNode* node;
	Solution s;
	node = s.buildTree(l,r);
}