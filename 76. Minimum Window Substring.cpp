
class Solution {
public:
    string minWindow(string& s, string& t) {
        int n = s.size(), tn= t.size();
        int left = 0, right;
        int mp[64]={0}, tmp[64]={0};
        
        for (char c : t){
            int idx=0x3f &c;
            tmp[idx]++;
        }
        
        int count = 0;
        
        int minLength = INT_MAX; 
        int minLeft = 0; 
        
        for (right = 0; right < n; right++) {
            char c = s[right];
            int idx= 0x3f & c;
        
            if (tmp[idx] == 0) continue;
           
            mp[idx]++;
        
            if (mp[idx] <= tmp[idx]) count++;
            
     
            if (count == tn) {
      
                while (tmp[0x3f& s[left]]==0|| mp[0x3f& s[left]]>tmp[0x3f& s[left]]) {
                    if (mp[0x3f&s[left]]!=0) mp[0x3f&s[left]]--;
                    left++;
                }
                
  
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
            }
        }
        
        if (minLength == INT_MAX) return "";
  
        return s.substr(minLeft, minLength);
    }
};
