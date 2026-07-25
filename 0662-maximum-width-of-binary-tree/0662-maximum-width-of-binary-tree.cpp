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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == nullptr) return 0 ;

        int maxW =0;

        queue<pair<TreeNode*,long long >> q;
        q.push({root,0});

        while(!q.empty()){
            int size =q.size();
            long long minI = q.front().second;

            long long first=0 ;
            long long last = 0;

            for(int i=0;i<size;i++){

                long long  curr = q.front().second - minI ;
                TreeNode* node = q.front().first ;

                q.pop();

                if( i==0) first = curr ;

                if(i==size-1) last = curr ;

                if(node->left){
                    q.push({node->left,2*curr +1});
                }

                if(node->right){
                    q.push({node->right,2*curr +2});
                }


            }
                maxW = max(maxW, (int)(last - first + 1));

        }
            return maxW ;
    }
};