class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int , int> mp;
        unordered_map<int , int> cnt_mp;
        for(auto& it : arr){
            mp[it] += 1;
        }

        for(auto& it : mp){
            int ele = it.first;
            int cnt = it.second;
            if(cnt_mp.find(cnt) == cnt_mp.end()) cnt_mp[cnt] = ele;
            else return false;
        }
        return true;
    }
};
