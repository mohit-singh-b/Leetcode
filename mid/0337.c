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
    int rob(TreeNode* root){
        pair <int,int> res =  rob2(root);
        return max(res.first,res.second);
    }

    pair<int,int> rob2(TreeNode* root) {
        if ( root->left == nullptr && root->right == nullptr)
            return {root->val,0};

        pair<int,int> left = {0,0} , right = {0,0};
        if ( root->left) left = rob2(root->left);
        if ( root->right) right = rob2(root->right);

        int include = root->val + left.second + right.second;
        int exclude = max ( left.first,left.second) + max ( right.first,right.second);

        return {include,exclude};
        
    }
};