class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
       
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int>count(n,1);
    map<int,int>m;
        int maxi = 0;

        for (int i = 0; i < n; i++) {bool flag=true;
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev]) {
                    if (dp[i] < 1 + dp[prev]) {
                        dp[i] = 1 + dp[prev];
                        count[i]=count[prev];
                        
                    }
                    else if(dp[i]==1+dp[prev]){
                        count[i]+=count[prev];
                    }
                }
            }           
            if (dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        int c=0;
       for(int i=0;i<n;i++){
            if(dp[i]==maxi)c+=count[i];
       }
    return c;}
};