class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        for(int i=0;i<n;i++){
            leftsum[i]=sum;
            sum+=nums[i];
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            rightsum[i]=sum;
            rightsum[i]=abs(leftsum[i]-rightsum[i]);
            sum+=nums[i];
        }
        return rightsum;
    }
};