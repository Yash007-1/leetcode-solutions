class Solution {
public:
  
  int f(string &s,int i,vector<int>&dp,vector<vector<bool>>&palin){
   if(i==s.size())return dp[i]=-1;
   if(dp[i]!=-1)return dp[i];
   int ans=s.size();
   for(int k=i;k<s.size();k++){
    int right=s.size();
   if(palin[i][k])right=1+f(s,k+1,dp,palin);
    ans=min(ans,right);
   }
   return dp[i]=ans;

  }
    int minCut(string &s) {
        int n=s.size();
       vector<int>dp(s.size()+1,-1);
       vector<vector<bool>>palin(n,vector<bool>(n,false));
       for(int i=n-1;i>=0;i--){
        for(int j=i;j<n;j++){
            if(s[i]==s[j]&&(j-i<=1||palin[i+1][j-1]))
            palin[i][j]=true;
        }
       }
        return f(s,0,dp,palin);
    }
};