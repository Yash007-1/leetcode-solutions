class Solution {
public:
    int f(vector<int>nums,int k){
        if(k<0)return 0;
        int n=nums.size();
        int ans=0;
        int l=0;
        int odds=0;
        for(int r=0;r<n;r++){
            if(nums[r]%2!=0)odds++;
            while(odds>k){
                if(nums[l]%2!=0)odds--;
                l++;
            }
            ans+=r-l+1;
        
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k)-f(nums,k-1);
    }
};