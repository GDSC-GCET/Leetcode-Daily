class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        unordered_map<int, int> m;

        //Loop and counting the frequency of elements. 
        //maxRow will store the max frequency.
        int maxRow = -1;
        for(int x : nums){
            m[x]++;
            maxRow = max(maxRow, m[x]);
        }

        for(int i=1; i<=maxRow; i++){
            vector<int> temp;
            for(auto x : m){
                if(x.second >= i){
                    temp.push_back(x.first);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//Here we are storing the frequency of each element of nums. 