class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long  i=0,j=(i+n-1)/2,last=n-1;
        long long  count=0;
        long long  presum=0,postsum=0;
        for(int x=0;x<=j;x++){
            presum+=nums[x];
            
        }
        for(int x=j+1;x<=last;x++){
            postsum+=nums[x];
        }
        while(i<n){
            if(presum>postsum)count++;
            presum-=(long long)nums[i];
            i++;
            
            postsum-=nums[(j+1)%n];
            last=(last+1)%n;
            j=(j+1)%n;
            if(i<n){postsum+=(long long)nums[last];presum+=(long long)nums[j];}
            
        }
        return (int)count;
    }
};