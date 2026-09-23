class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
       
        
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
  
int ans=1e9;
s=0;

    for(int i=0;i<n;i++){
        s+=nums[i];
        int req=x-s;   if(req<0)break;
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