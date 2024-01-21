class Solution {
private: 
    int solve(int ind, vector<int>& nums,vector<int>& memo){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(memo[ind] != -1) return memo[ind]; //if for index 'ind' value is already calculated,
        int rob = nums[ind] + solve(ind-2, nums, memo);//return from there only.
        int notRob = 0 + solve(ind-1, nums, memo);

        return memo[ind] = max(rob, notRob);
    }

public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      vector<int> memo(n, -1);
      return solve(n-1, nums, memo);
    }
};
