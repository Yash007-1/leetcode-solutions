class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
      
         for(int rshift=1-n;rshift<n;rshift++){
                    for(int cshift=1-n;cshift<n;cshift++){
                        int curr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==0)continue;
               
                        int nr=i+rshift;
                        int nc=j+cshift;
                        if(nr>=0&&nr<n&&nc>=0&&nc<n&&img2[nr][nc]==1){
                           

                                curr++;
                                
                        }
                    }
                }
                 ans=max(ans,curr);
            }
           
        }
   return ans; }
};