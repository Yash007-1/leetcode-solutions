class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
         int n = s1.size();
        int m=s2.size();
        
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[ j-1]){
                   dp[i][j]=1+dp[i-1][j-1];
                }
                   
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
            }
           
        }
        int i=n,j=m;
        int len=n+m-dp[n][m];
        int idx=len-1;
        string ans;
        for(int i=0;i<len;i++)ans+='*';
        while(i>0&&j>0&&idx>=0){
            if(s1[i-1]==s2[j-1]){
                 ans[idx--]=s1[i-1];
                 i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                       ans[idx--]=s1[i-1];
                       i--;
            }
            else {
                ans[idx--]=s2[j-1];
                j--;
            }
                
            
        

        }
        while(i>0&&idx>=0)ans[idx--]=s1[i-- -1];
        while(j>0&&idx>=0)ans[idx--]=s2[j-- -1];
   return ans; }
};