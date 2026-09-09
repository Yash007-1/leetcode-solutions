class Solution {
public:
    long long countCommas(long long n) {
         long long ans = 0;
       
        long long sb = 1000;
        while (sb <= n) {
            ans += (n - sb + 1);

            sb *= 1000;
        }
        return n > 999 ? ans : 0;
    }
};