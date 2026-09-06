class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        long long  n=speed.size();
        int groups=n;
        long long prevspeed=speed[n-1];
        for(long long i=n-2;i>=0;i--){
            if(position[i+1]-position[i]<=distance){
                groups--;
            }
           else if(speed[i]>prevspeed){
                groups--;
            }
            else{
                prevspeed=speed[i];
            }
            
        }
return groups;
        
  
   }
};