//Approach 1: 

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].length();
        int prev = 0;
        int curr = 0;
        int numberOfBeams = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(bank[i][j] == '1') curr++;
            }
            if(curr==0) continue;
            else{
                numberOfBeams += curr*prev;
            }
            prev = curr;
            curr=0;
        }
        return numberOfBeams;
    }
};

//Here we are counting the number of devices in each row and storing that in curr. And then multiplying it with prev.


//Approach 2:

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m = bank.size(), n = bank[0].size();
        vector<int> cnt;
        for(auto i : bank){
            int numberOf1 = count(i.begin(), i.end(), '1');
            if(numberOf1 != 0) cnt.push_back(numberOf1);
        }
        int ans = 0;
        int x = cnt.size();
        for(int i = 0; i < x-1; i++){
            ans += (cnt[i] * cnt[i+1]);
        }
        return ans;
    }
};

//Here we are first counting the number of devices in each row and storing that in cnt vector.
//If the count is 0, then ignore it. Else push count in cnt.
//After that just multiply each element to its next element and add it.