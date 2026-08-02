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
    // int max = 0;
    // int sum =0;

    // int func(TreeNode * root , int max , int min){

    //     if(root == nullptr) return 0;

    //     int left = func(root->left , max , min) ;
    //     int right = func (root->right , max , min);

    //     if( left || right == -1) return -1 ;

    //     if(root->left == nullptr && root->right == nullptr) return 0;
    //     // else if(root->left == nullptr && root->right!=nullptr){
    //     //     sum = 
    //     // } 

    //     if(root->val > 0 && root->val > left && root->val < right){
    //         sum = sum + left + right ;
    //     }
    //     if(sum >max ) max = sum ;
    //     else {
    //         return -1;
    //         sum =0;
    //     }


    // }

    int ans =0;

    struct Info {
        bool isBST ;
        int sum ;
        int mini;
        int maxi;
    };

    Info func(TreeNode * root){

        if(root== nullptr){
            return {true,0,INT_MAX , INT_MIN};

        }

        Info left = func(root->left);
        Info right = func(root->right);

        if(!left.isBST || !right.isBST){
            return {false , 0,0,0};
        }

        if(root->val <= left.maxi || root->val >= right.mini){
            return {false,0,0,0};
        }

        int currSum = left.sum + right.sum +root->val ;

        ans = max(ans , currSum);

        return {
            true,
            currSum,
            min(root->val,left.mini),
            max(root->val,right.maxi)
            
        };
    }

    int maxSumBST(TreeNode* root) {
        func(root);
        return ans;
    }
};