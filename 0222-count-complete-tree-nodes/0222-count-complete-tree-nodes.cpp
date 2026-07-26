/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // int level = 0;

    int count(TreeNode* root) {
        int left = 0;
        TreeNode* temp = root ;
        if(root==nullptr) return 0;


        while(root!=nullptr){
            left++ ;
            root = root->left ;
        }
        // left-- ;

        int right =0 ;
        root = temp ;
         while(root!=nullptr){
            right++ ;
            root = root->right ;
        }
        // right -- ;
        root = temp ;

        if(left == right){
            return pow(2,left)-1;
        }

        else {
            return 1 + count(root->left) + count(root->right) ;
        }
        
    }
    int countNodes(TreeNode* root) { 
        if(root==nullptr) return 0;
        return count(root);
    }
};