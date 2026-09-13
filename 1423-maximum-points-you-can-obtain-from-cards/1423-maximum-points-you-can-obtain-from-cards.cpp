class Solution {
public:
    
       
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
      
        int score=0,end=0;
        for(int i=0;i<k;i++){
            score+=cardPoints[i];
        }
        int ans=score;
        for(int i=0;i<k;i++){
            score-=cardPoints[k-1-i];
            score+=cardPoints[n-i-1];
            ans=max(score,ans);
        }
        return ans;
    }
};