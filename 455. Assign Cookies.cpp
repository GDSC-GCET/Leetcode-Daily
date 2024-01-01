class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int idxChild=0,idxCookie=0;
        int ans=0;
        while(idxChild<g.size() && idxCookie<s.size()){
            if(g[idxChild]<=s[idxCookie]){
                ans++;
                idxChild++;
                idxCookie++;
            }
            else if(g[idxChild]>s[idxCookie]){
                idxCookie++;
            }
        }
        return ans;
    }
};