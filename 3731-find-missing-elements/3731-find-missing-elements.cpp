class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        int mine=nums[0];
        int maxe=nums[0];
        for(auto i:nums){
            mine=min(mine,i);
            maxe
            =max(maxe,i);
            m[i]++;
        }
        for(int j=mine;j<=maxe;j++){
            if(m[j]==0)ans.push_back(j);
        }
   return ans; }
};