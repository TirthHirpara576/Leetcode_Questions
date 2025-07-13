class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch >= 'a' && ch <= 'z'){ // Lowercase
                ans += ch;
            }
            else if(ch == '*'){
                if (!ans.empty()) ans.pop_back(); // Removes last character
                //OR
                //ans.erase(ans.size() - 1); // Removes last character
            }
            else if(ch == '#'){
                ans = ans + ans;
            }
            else if(ch == '%'){
                reverse(ans.begin(),ans.end());
            }
        }
        return ans;
    }
};