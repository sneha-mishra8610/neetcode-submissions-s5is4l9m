/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int h=0;
    void traverse(TreeNode* node,int height){
        if(node==NULL)
        return;
        h=max(h,height);
        traverse(node->left,height+1);
        traverse(node->right,height+1);
    }
    int maxDepth(TreeNode* root) {
        traverse(root,1);
        return h;
    }
};