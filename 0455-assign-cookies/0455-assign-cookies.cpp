class Solution {
public:int f(vector<int>&greed,vector<int>&s,int child,int cook,vector<vector<int>>&dp){
    if(cook<0)return 0;
    if(child==0)return greed[child]<=s[cook];
    if(dp[child][cook]!=-1)return dp[child][cook];
    int ngive=f(greed,s,child-1,cook,dp);
    int give=0;
    if(greed[child]<=s[cook])give=1+f(greed,s,child-1,cook-1,dp);
    return dp[child][cook]= max(ngive,give);
}
    
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n=g.size();
        int c=s.size();
      int i=0,j=0;
      while(i<n&&j<c){
        if(s[j]>=g[i])i++;
        j++;
      }
       
return i;
    }
};