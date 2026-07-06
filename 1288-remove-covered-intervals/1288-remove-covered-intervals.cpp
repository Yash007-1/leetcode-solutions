class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        for(int i=0;i<intervals.size();i++){
            for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<intervals[i][0]){
                    swap(intervals[i],intervals[j]);
                }
                else if(intervals[j][0]==intervals[i][0]){
                    if(intervals[j][1]>intervals[i][1])
                    swap(intervals[i],intervals[j]);
                }
            }}
            unordered_map<int,int>m;
            int count=0;
            for(int i=0;i<intervals.size();i++){
                if(m[i]==1)continue;
                 for(int j=i+1;j<intervals.size();j++){
                    
                      
              
                     if(intervals[j][1]<=intervals[i][1]){
                    m[j]=1;
                  }
                
                 }
                 count++;
            }
            
        return count;}

};