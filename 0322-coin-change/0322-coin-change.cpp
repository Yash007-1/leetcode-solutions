class Solution {
public:
int f(vector<int>&coins,int idx,int amt,vector<vector<int>>&dp){
    if(amt==0)return 0;
    if(idx==0){
        if(amt%coins[idx]!=0)return INT_MAX-1;
        else return amt/coins[0];
    }
    if(dp[idx][amt]!=-1)return dp[idx][amt];
    int ntake=f(coins,idx-1,amt,dp);
    int take=INT_MAX-1;
    if(amt>=coins[idx])take=1+f(coins,idx,amt-coins[idx],dp);
    return dp[idx][amt]=min(take,ntake);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,INT_MAX-1));
        
        for(int i=0;i<coins.size();i++)dp[i][0]=0;
       for(int i=0;i<=amount;i++){
        if(i%coins[0]==0)dp[0][i]=i/coins[0];
       }
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                int ntake=dp[i-1][j];
                int take=INT_MAX;
                if(j>=coins[i])take=1+dp[i][j-coins[i]];
                dp[i][j]=min(take,ntake);
            }
        }
        int ans=dp[coins.size()-1][amount];
        if(ans==INT_MAX-1)return -1;

       return ans ;
    }
};