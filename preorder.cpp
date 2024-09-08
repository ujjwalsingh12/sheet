#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// TreeNode definition (already provided in the solution)
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution class (already provided in the solution)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while(st.size()>0){
            TreeNode *r = st.top(); st.pop();
            if(r!=nullptr){
                ans.push_back(r->val);
                if(r->right!=nullptr){
                    TreeNode *rc = r->right;
                    if(rc!=nullptr){ st.push(rc); }
                }
                if(r->left!=nullptr){
                    TreeNode *lc = r->left;
                    if(lc!=nullptr){ st.push(lc); }
                }
            }
        }
        return ans;
    }
};

// Helper function to create a sample tree
TreeNode* createSampleTree() {
    // Creating the following binary tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    // Create the tree
    TreeNode* root = createSampleTree();
    
    // Create an instance of Solution and call preorderTraversal
    Solution sol;
    vector<int> result = sol.preorderTraversal(root);
    
    // Print the result
    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// using recursiion
// class Solution {
// public:
//     void preOrder(TreeNode* root,vector<int>& ans){
//         if(root==NULL) return;
//         ans.push_back(root->val);
//         preOrder(root->left,ans);
//         preOrder(root->right,ans);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int>ans;
//         preOrder(root,ans);
//         return ans;
//     }
// };