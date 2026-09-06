class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        // long long  n=speed.size();
        // vector<int>dummy=position;
        // int it=-1;
        // if(n==1)return 1;
        // int lastmin=INT_MAX;
        // for(long long i=n-2;i>=0;i--){
        //     if(position[i+1]-position[i]<=distance){
        //         dummy[i]=dummy[i+1];
        //         speed[i]=speed[i+1];
        //     }
            
        // }

        // vector<int>time_req(n,-1);
        // int lastrobo=n-1;
        // for(long long  i=n-1;i>=0;i--){
        //     if(dummy[i]==dummy[i+1])continue;
        //     if(speed[i]>speed[i+1]){
        //         long long gap=dummy[i+1]-dummy[i]-distance;
        //        long long r_speed=speed[i+1]-speed[i];
        //        time_req[i]=gap/r_speed;
        //     }
            

        // }
        // int count = 0;
        // for (int i = 0; i < n; i++) {
        //     if (i == 0 || dummy[i] != dummy[i - 1]) {
        //         count++;
        //     }
        // }

        // return count;

   
        pair<int, int> prev;
        int n = position.size();
        prev = {speed[n-1], position[n-1]};
        int sol = 1;
        for(int i = n-2; i >= 0; i--){
            if(speed[i] > prev.first || prev.second - position[i] <= distance){
                prev = {prev.first, position[i]};
            }else{
                sol++;
                prev = {speed[i],position[i]};
            }
        }
        return sol;
  
   }
};