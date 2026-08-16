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
        vector<double >prev(m+1,0);
        prev[0]=1;


        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                double  ntake=prev[j];
                double take=0;
                if(s[i-1]==t[j-1])take=prev[j-1];
                prev[j]=(double) take+ntake ;
            }
        }

     
    
    return(int) prev[m];     
    }
};