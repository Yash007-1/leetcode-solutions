class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0;
         
        for(int i=0;i<bills.size();i++){
                int change=bills[i]-5;
                
                while(change>=10&&ten>0){
                    ten--;
                    change-=10;
                }
                while(change>=5&&five>0){
                    five--;
                    change-=5;
                }
                if(change!=0)return false;
                if(bills[i]==10)ten++;
                else if(bills[i]==5)five++;

             
        }
    return true;}
};