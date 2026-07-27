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

    TreeNode* build(vector<int>& inorder, vector<int>& postorder , int posts , int poste , int ins , int ine){

        if(ins > ine || posts > poste) return nullptr ; 

        int n = postorder.size();
        int first = postorder[poste];
        int index =0 ;
        for(int i= ins;i<= ine ; i++){
            if(inorder[i]== first){
             index = i ;   
            }
        }

        TreeNode* node = new TreeNode(first);

        // int newins = index + 1 ;
        // int newine =  n-1;
        // int newposts = posts-1;
        // int newposte = posts + index - ins +1 ; 

        node->left = build(inorder,postorder,posts, posts + index - ins -1  , ins ,index-1);

        node->right = build(inorder , postorder , posts+index-ins , poste-1 , index +1 , ine);


        return node;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder, postorder , 0,n-1,0,n-1 );
    }
};