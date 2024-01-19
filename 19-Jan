// TC=O(n*m)
// SC=O(n*m)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>dp(row,vector<int>(col,INT_MAX));
        dp=matrix;

        // first row of dp and matrix will remain same
        if(row>=2){
            int i=1;
            while(i<row){
                int j=0;
               
                while(j<col){
                     int minn_possbile=INT_MAX;
                    int newrow[3]={-1,-1,-1};
                    int newcol[3]={-1,0,+1};
                    for(int k=0;k<3;k++){
                        int r=i+newrow[k];
                        int c=j+newcol[k];
                        if(r>=0 && c>=0 && r<row && c<col){
                            minn_possbile=min(minn_possbile,matrix[i][j]+dp[r][c]);
                          
                        }
                    }

                    dp[i][j]=minn_possbile;
                    j++;
                }
                i++;
            }
        }
       
    //    iterate the last row(each col) and return the minimum ans.
    int ans=INT_MAX;
    for(int i=0;i<col;i++){
        ans=min(ans,dp[row-1][i]);
    }

    return ans;
    }
};
