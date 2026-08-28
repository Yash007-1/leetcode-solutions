class Solution {
public:
    bool valid(string&s,int i,int j,vector<vector<int>>&dp){
        if(i==j)return dp[i][j]=true;
        if(dp[i][j]!=-1)return dp[i][j];
        while(i<j){
            if(s[i]!=s[j])return dp[i][j]=false;
            i++;
            j--;
        }
        return dp[i][j]=true;
    }
  int f(string &s,int i,vector<int>&dp,vector<vector<int>>&palin){
   if(i==s.size())return dp[i]=-1;
   if(dp[i]!=-1)return dp[i];
   int ans=s.size();
   for(int k=i;k<s.size();k++){
    int right=s.size();
   if(valid(s,i,k,palin))right=1+f(s,k+1,dp,palin);
    ans=min(ans,right);
   }
   return dp[i]=ans;

  }
    int minCut(string &s) {
       vector<int>dp(s.size()+1,-1);
       vector<vector<int>>palin(s.size(),vector<int>(s.size(),-1));
        return f(s,0,dp,palin);
    }
};