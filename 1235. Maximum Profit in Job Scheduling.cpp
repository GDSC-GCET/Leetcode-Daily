class Solution {
public:
    int n;
    int dp[50001];

    int solve(vector<vector<int>>& input, int idx){
        if (idx >= input.size())  return 0;
        if (dp[idx] != -1)  return dp[idx];

        int notTake = solve(input, idx + 1);
        vector<int> v = {input[idx][1], 0, 0};
        int nextIdx = lower_bound(input.begin(), input.end(), v) - input.begin();
        int take = input[idx][2] + solve(input, nextIdx);
        return dp[idx] = max(take, notTake);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();
        vector<vector<int>> input(n, vector<int>(3, 0));

        for(int i=0; i<n; i++){
            input[i][0] = startTime[i];
            input[i][1] = endTime[i];
            input[i][2] = profit[i];
        }

        sort(input.begin(), input.end());
        memset(dp, -1, sizeof(dp));
        return solve(input, 0);
    }
};
