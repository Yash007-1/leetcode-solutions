class Solution {
public:
    bool valid(string&s,int i,int j){
        if(i==j)return true;
        
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
  int f(string &s,int i,vector<int>&dp){
   if(i==s.size())return dp[i]=-1;
   if(dp[i]!=-1)return dp[i];
   int ans=s.size();
   for(int k=i;k<s.size();k++){
    int right=s.size();
   if(valid(s,i,k))right=1+f(s,k+1,dp);
    ans=min(ans,right);
   }
   return dp[i]=ans;

  }
    int minCut(string &s) {
       vector<int>dp(s.size()+1,-1);
        return f(s,0,dp);
    }
};