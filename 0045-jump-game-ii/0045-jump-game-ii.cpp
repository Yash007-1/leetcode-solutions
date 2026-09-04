class Solution {
public:
    
    int jump(vector<int>& nums) {
        
  int n=nums.size();
        if(n<2)return 0;
        int i=0;
        int jumps=0;
        while(i<n){
            if(nums[i]+i>=n-1)return jumps+1;
            int maxjump=0,idx=i;
           for(int j=1;j<=nums[i];j++){
                 if(maxjump<=i+j+nums[j+i]){
                    idx=i+j;
                    maxjump=i+j+nums[j+i];
                 }
           }

           i=idx;
           jumps++;
        }

    return jumps;}

};