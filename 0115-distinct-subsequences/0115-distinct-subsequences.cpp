class Solution {
public:
int f(string s,string t,int i1,int i2,vector<vector<int>>&dp){
    if(i2<0)return 1;
    if(i1<0)return 0;
    if(dp[i1][i2]!=-1)return dp[i1][i2];
    int ntake=f(s,t,i1-1,i2,dp);
    int take=0;
    if(s[i1]==t[i2])take=f(s,t,i1-1,i2-1,dp);
    return dp[i1][i2]=take+ntake;
}
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long>(m+1,0));
        for(int i=0;i<=n;i++)dp[i][0]=1;


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                long long  ntake=dp[i-1][j];
                long long take=0;
                if(s[i-1]==t[j-1])take=dp[i-1][j-1];
                dp[i][j]=(unsigned long long) take+ntake ;
            }
        }

     
    
    return(int) dp[n][m];     
    }
};