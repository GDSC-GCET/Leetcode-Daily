class Solution {
public:
    bool isLeaf(TreeNode* root){
        if(root == NULL) return false;

        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }

    void solve(TreeNode* root,vector<int>& leafNodes){

        if(root == NULL) return;

        if(isLeaf(root)) leafNodes.push_back(root->val);

        if(root->left) solve(root->left, leafNodes);
        if(root->right) solve(root->right, leafNodes);

        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leafNodesOfTree1;
    vector<int> leafNodesOfTree2; 
    solve(root1, leafNodesOfTree1);
    solve(root2, leafNodesOfTree2);

    return (leafNodesOfTree1 == leafNodesOfTree2);
    }
};
