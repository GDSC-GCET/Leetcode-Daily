class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int x : nums){
            m[x]++;
        }
        int cnt = 0;
        for(auto [num, freq] : m){
            if(freq == 1) return -1;
            cnt += ceil((double)freq/3);
        }
        return cnt;
    }
};

//Here if are taking the Greedy Approach, we can see that if freq is divisible by 3 then we simply add 1 to cnt, and if it is giving any remainder then we that ceil of it.
