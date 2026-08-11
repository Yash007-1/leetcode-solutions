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

        vector<int>curr(amount+1,1e9);
        vector<int>prev(amount+1,1e9);
        curr[0]=prev[0]=0;

       for(int i=0;i<=amount;i++){
        if(i%coins[0]==0)prev[i]=i/coins[0];
       }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int ntake=prev[j];
                int take=1e9;
                if(j>=coins[i])take=1+curr[j-coins[i]];
                curr[j]=min(take,ntake);
            }
            prev=curr;
        }
        int ans=prev[amount];
        if(ans==1e9)return -1;

       return ans ;
    }
};