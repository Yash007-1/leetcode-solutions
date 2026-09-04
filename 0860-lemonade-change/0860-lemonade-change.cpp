class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>m;
         int money=0;

        for(int i=0;i<bills.size();i++){
                int change=bills[i]-5;
                while(change>=20&&m[20]>0){

                    m[20]--;
                    change-=20;
                }
                while(change>=10&&m[10]>0){
                    m[10]--;
                    change-=10;
                }
                while(change>=5&&m[5]>0){
                    m[5]--;
                    change-=5;
                }
                if(change!=0)return false;
                m[bills[i]]++;
                
             
        }
    return true;}
};