class Solution {
public:
    int minDays(int n) {
        vector<int>dp(n+1,INT_MAX);
       dp[0]=0;
        for(int score=0;score<=n;score++){
           long long sum=0;
           for(int i=1;i<=score;i++){
                sum+=i;
                if(sum>score)break;
                int remaining=score-sum;
                if(remaining==0)dp[score]=min(dp[score],i);
                else {
                    dp[score]=min(dp[score],dp[remaining]+i+1);
                }
           }
            
        }
   return dp[n];}
};