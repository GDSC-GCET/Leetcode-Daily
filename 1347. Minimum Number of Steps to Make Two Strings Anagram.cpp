class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:t){
            mp[i]--;
        }

        int count =0;
        for(auto i:mp){
            if(i.second>0){
                count+=i.second;
            }
        }

        return count;
    }
};
