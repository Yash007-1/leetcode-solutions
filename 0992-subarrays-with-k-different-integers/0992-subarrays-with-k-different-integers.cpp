class Solution {
public:
   
    int atmost(vector<int>&nums,int k){
        if( k==0) return 0;
        int l=0,count=0;
        int n=nums.size();
        unordered_map<int,int>m;
         set<int>s;
      
        for(int r=0;r<n;r++){
            m[nums[r]]++;
            s.insert(nums[r]);
            
           
            while(s.size()>k){
                m[nums[l]]--;
                if(m[nums[l]]==0)s.erase(nums[l]);
                l++;
            }
           
           
            count+=r-l+1;
            

        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       
       
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};