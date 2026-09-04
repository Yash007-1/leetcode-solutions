class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int>arr(3,0);
         
        for(int i=0;i<bills.size();i++){
                int change=bills[i]-5;
                while(change>=20&&arr[2]>0){

                    arr[2]--;
                    change-=20;
                }
                while(change>=10&&arr[1]>0){
                    arr[1]--;
                    change-=10;
                }
                while(change>=5&&arr[0]>0){
                    arr[0]--;
                    change-=5;
                }
                if(change!=0)return false;
                arr[bills[i]/10]++;

             
        }
    return true;}
};