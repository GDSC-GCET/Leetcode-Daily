class Solution {
public:
    bool hasDup(string& s1, string& s2){
        int check[26] = {0};

        for(char ch : s2){
            if(check[ch - 'a'] > 0) return true;
            check[ch - 'a']++;
        }

        for(char ch : s1){
            if(check[ch - 'a'] > 0) return true;
        }
        return false;
    }
    int solve(int i, vector<string>& arr, string temp, int n){
        if(i >= n){
            return temp.length();
        }

        int include = 0;
        int exclude = 0;

        if(hasDup(temp, arr[i])){
            exclude = solve(i+1, arr, temp, n);
        }
        else{
        include = solve(i+1, arr, temp+arr[i], n);
        exclude = solve(i+1, arr, temp, n);
        }
        return max(include, exclude);
    }

    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        return solve(0, arr, temp, n);
    }
};
