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

    TreeNode* build( vector<int>& preorder, vector<int>& inorder , int prestart , int preend , int instart , int inend ){   

        if(inend < instart || prestart > preend) return nullptr ; 
        int first = preorder[prestart];
        int index = instart ;
        TreeNode * node = new TreeNode(first) ;

        for(int i=instart;i<=inend;i++){
            if(inorder[i]== first){
                index = i;
            }
        }
        int newInstart = instart;
        int newInend = index -1;
        int newpreStart = prestart + 1;
        int newpreEnd = prestart + index - instart ;

        node->left = build(preorder,inorder,newpreStart,newpreEnd,newInstart,newInend);

        node->right =  build(preorder,inorder,newpreEnd +1, preend,index+1,inend );

        return node;
        
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);

    }
};