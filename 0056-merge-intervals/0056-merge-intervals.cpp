class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=0;
        while(i<n){
            int currst=intervals[i][0];
            int largest=intervals[i][1];
            while(i<n-1&&largest>=intervals[i+1][0]){
                i++;
                largest=max(largest,intervals[i][1]);
            }
            ans.push_back({currst,largest});
            i++;
        }
        return ans;}
};