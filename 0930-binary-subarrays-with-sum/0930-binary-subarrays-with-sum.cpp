class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>m;
        int ans=0;
        m[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
          sum+=nums[i];
          if(m.find(sum-goal)!=m.end())ans+=m[sum-goal];
          m[sum]++;
        }
       
        return ans;
    }
};