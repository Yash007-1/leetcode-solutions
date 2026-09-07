class Solution {
public:
 long long mod=1e9+7;
 long long  f(string s,int i,vector<long long >&dp){
    if(i<0)return 1;
    
    if(dp[i]!=-1)return dp[i];
    int j=i-1;
    long long  same=0;
    while(j>=0){
        if(s[j]==s[i]) {same=f(s,j-1,dp);break;}
        j--;
    }
   
    long long  total=2*f(s,i-1,dp);
    return dp[i]=(total-same+mod)%mod;
}
    
    int distinctSubseqII(string s) {
        int n=s.size();
        unordered_map<string,int>m;
        vector<long long>dp(n,-1);
        long long ans=(long long)f(s,n-1,dp)-1+mod;
       return ans%mod;
    }
    
};