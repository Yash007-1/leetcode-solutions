class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
          int n=prices.size();
        vector<int>curr(2,0),next(2,0);
       
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                if(!j)curr[j]=max(prices[i]+next[1]-fee,next[0]);
                else curr[j]=max(-prices[i]+next[0],next[1]);
            }
            next=curr;
        }
        return next[1];
    }
};