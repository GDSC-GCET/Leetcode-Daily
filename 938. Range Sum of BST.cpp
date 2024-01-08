class Solution {
public:
    int sum;
    int solve(TreeNode* root, int low, int high){
        if(root == NULL) return 0;

        if(root->val >= low && root->val <= high) sum+=root->val;

        if(root->val > low) solve(root->left, low, high);
        if(root->val < high) solve(root->right, low, high);

        return sum;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};

//Here we are using the property of Binary Tree.
//If current node value is less than 'low' value than there's no point going left to it.
//Similarly if current node value is more than 'high' value then there's no point going in right to that node.
//This will reduce the TC effieciently.
