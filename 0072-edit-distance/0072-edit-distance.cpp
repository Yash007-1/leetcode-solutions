class Solution {
public:
int f(string s1,string s2,int i1,int i2,vector<vector<int>>&dp){
   if(i2<0)return i1+1;
    if(i1<0)return i2+1;
    if(dp[i1][i2]!=-1)return dp[i1][i2];
    if(s1[i1]==s2[i2])return dp[i1][i2]=f(s1,s2,i1-1,i2-1,dp);
    else return dp[i1][i2]=min(min(1+f(s1,s2,i1-1,i2-1,dp),1+f(s1,s2,i1-1,i2,dp)),1+f(s1,s2,i1,i2-1,dp));
}
    int minDistance(string s1, string s2) {
                 int n = s1.size();
        int m=s2.size();
        if(n==0)return m;
        if(m==0)return n; 
        vector<vector<int>>dp(n,vector<int>(m,-1));
       
        
        
       
        // while(i>0&&j>0){
        //     if(s1[i-1]==s2[j-1]){
                
        //          i--;j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1]){
        //         if(i==j)count++;
        //         else count+=2;
        //         i--;
        //     }
        //     else {
        //        if(i==j)count++;
        //        else count+=2;
        //         j--;
        //     }}
    return f(s1,s2,n-1,m-1,dp);}

};