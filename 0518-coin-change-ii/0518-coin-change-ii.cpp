class Solution {
public:
int f(vector<int>nums,int idx,int amt,vector<vector<int>>&dp){
    if(amt==0)return 1;
    if(idx==0){
        if(amt%nums[0]==0)return 1;
        else return 0;
    }
    if(dp[idx][amt]!=-1)return dp[idx][amt];
    int ntake=f(nums,idx-1,amt,dp);
    int take=0;
    if(nums[idx]<=amt)take=f(nums,idx,amt-nums[idx],dp);
    return dp[idx][amt]=ntake+take;
}
    int change(int amount, vector<int>& coins) {
          int n=coins.size();
        vector<vector<long long >>dp(n,vector<long long >(amount+1,0));
        // for(int i=0;i<n;i++)dp[i][0]=1;
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
                int ntake=dp[i-1][j];
                int take=0;
                if(coins[i]<=j)take=dp[i][j-coins[i]];
                dp[i][j]=(long long)take+ntake;
            }
        
        }
        return dp[n-1][amount];
    }
};