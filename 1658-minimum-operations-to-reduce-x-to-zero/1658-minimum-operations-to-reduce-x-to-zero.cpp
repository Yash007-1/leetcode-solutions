class Solution {
public:
int f(vector<int>&nums,int i,int j,int x,vector<vector<vector<int>>>&dp){
    if(x==0)return 0;
    if(x<0)return 1e5;
    if(j<i)return 1e5;
    if(dp[i][j][x]!=-1)return dp[i][j][x];
    int begin=1+f(nums,i+1,j,x-nums[i],dp);
    int end=1+f(nums,i,j-1,x-nums[j],dp);
    return dp[i][j][x]=min(begin,end);

}
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(x+1,-1)));
        // int ans=f(nums,0,nums.size()-1,x,dp);
        // return ans>=1e5?-1:ans;

        
    map<int,int>presum;
    int s=0;
    for(int i=0;i<n;i++){
        s+=nums[i];
        if(s>x){
            break;
        }
        else {
            presum[s]=i+1;
        }

    }
    map<int,int>postsum;
    s=0;
    for(int i=n-1;i>=0;i--){
        s+=nums[i];
        if(s>x){
            break;
        }
        else {
            postsum[s]=n-i;
        }

    }
    //  int prefind=presum.find(x)!=presum.end();
    //  int postfind=postsum.find(x)!=postsum.end();
    //  if(prefind&&postfind)return min(presum[x],postsum[x]);
    //  if(prefind)return presum[x];
    //  if(postfind)return postsum[x];
int ans=1e9;
s=0;
int pre=0;
    for(int i=0;i<n;i++){
        s+=nums[i];
        int req=x-s;   if(req<0){pre=i;break;}
        if(req==0){
            ans=min(ans,i+1);
        }
        if(postsum.find(req)!=postsum.end()&&i+1+postsum[req]<=n){
            ans=min(ans,i+1+postsum[req]);
               }
     

    }
    s=0;
    for(int i=n-1;i>=0;i--){
        s+=nums[i];
        int req=x-s;
        if(req<0)break;
        if(req==0)ans=min(ans,n-i);
        if(presum.find(req)!=presum.end()&&n-i+presum[req]<=n){
            ans=min(ans,n-i+presum[req]);
           
        }
    }
    
return ans==1e9?-1:ans;
    }
};