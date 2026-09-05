class Solution {
public:
  static  bool comp(vector<int>a,vector<int>b){
            return a[1]<b[1]?true:false;
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
        int n=intervals.size();
        int ans=0;
        int prev=0;

        sort(intervals.begin(),intervals.end(),comp);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<intervals[prev][1]){
                ans++;
            }
            else prev=i;
        }
    return ans;}
};