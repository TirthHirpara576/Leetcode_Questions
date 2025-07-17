class Solution {
public:
    char findTheDifference(string s, string t) {
        /* similsr to this
        int ans=0;
        for(int value : nums){
            ans = ans ^ value;
        }
        return ans; */

        int total_ascii_s = 0;
        for(char ch : s){
            total_ascii_s = total_ascii_s + ch-'0';
        }
        int total_ascii_t = 0;
        for(char ch : t){
            total_ascii_t = total_ascii_t + ch-'0';
        }
        return (total_ascii_t - total_ascii_s) + '0';
    }
};