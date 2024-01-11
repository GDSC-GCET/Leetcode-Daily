class Solution {
public:
    int maxDifference;

    void solve(TreeNode* root, int maxi, int mini){
        if(!root){
            maxDifference = max(maxDifference, abs(maxi - mini));
            return;
        }

        maxi = max(root->val, maxi);
        mini = min(root->val, mini);

        solve(root->left, maxi, mini);
        solve(root->right, maxi, mini);
    }

    int maxAncestorDiff(TreeNode* root) {
        maxDifference = 0;
        solve(root, root->val, root->val);
        return maxDifference;
    }
};
