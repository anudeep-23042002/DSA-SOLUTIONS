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
    TreeNode* help(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        if(root->right==NULL){
            return root->left;
        }
        TreeNode* curr=root->left;
        while(curr->right!=NULL){
            curr=curr->right;
        }
        curr->right=root->right;
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return help(root);
        }
        TreeNode* curr=root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left=help(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=help(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return curr;
        
    }
};