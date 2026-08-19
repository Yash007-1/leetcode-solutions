class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prevmin=prices[0];
        int mxprofit=0;
        for(int i=1;i<prices.size();i++){
             mxprofit=max(mxprofit,prices[i]-prevmin);
             prevmin=min(prevmin,prices[i]);
        }
    return mxprofit;}
};