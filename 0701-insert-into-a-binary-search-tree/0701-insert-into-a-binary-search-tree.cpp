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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode * node = new TreeNode(val);
        TreeNode * dummy =root;

        if(root == nullptr ){
            return node ;
        }

        while(true){
            if(root->val > val ){
                if(root->left == nullptr){
                    root->left = node ;
                    return dummy ;
                }
                else{
                    root= root->left ;
                }
            }
            else{
                if(root->right == nullptr){
                    root->right = node;
                    return dummy;
                }
                else{
                    root = root->right ;
                }
            }
        }
    }
};