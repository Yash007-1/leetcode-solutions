class Solution {
public:
    int minMoves(vector<int>& nums) {
        int  maxe,mine=INT_MAX;;
        for(auto i:nums){
            mine=min(mine,i);
        
        }
        int ans=0;
        for(auto i:nums){
            ans+=i-mine;
        }

        return ans;
        
    }
};