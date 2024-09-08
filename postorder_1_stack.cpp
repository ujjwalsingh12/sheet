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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        TreeNode *r = root;
        st.push(r);
        while(!st.empty()){
            TreeNode *t = st.top(); st.pop();
            if(t!=nullptr){
                ans.push_back(t->val);
                if(t->left != nullptr){
                    st.push(t->left);
                }
                if(t->right != nullptr){
                    st.push(t->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};