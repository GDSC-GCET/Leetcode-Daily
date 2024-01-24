class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root, vector<int>& freqCount){
        if(!root) return;

        freqCount[root->val]++;

        if(!root->left && !root->right){
            int oddFreq = 0;
            for(int i=0; i<10; i++){
                if(freqCount[i]%2 != 0){
                    oddFreq++;
                }
            }

            if(oddFreq <= 1){
                ans++;
            }
        }

        solve(root->left, freqCount);
        solve(root->right, freqCount);

        freqCount[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freqCount(10, 0);
        solve(root, freqCount);
        return ans;
    }
};
