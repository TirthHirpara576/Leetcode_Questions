class Solution {
public:
    bool checkDivisibility(int n) {
        int num = n;

        int sum=0,product=1;
        while(n > 0){
            int r = n % 10;
            sum += r;
            product *= r;
            n = n / 10;
        }

        return num % (sum + product) == 0;
    }
};