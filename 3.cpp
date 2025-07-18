class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        int n = s.size();
        set<char> charSet;
        vector<string> v;
        string temp = "";

        for (int i = 0; i < n; i++) {
            // if Duplicate found
            if (charSet.find(s[i]) != charSet.end()) {
                v.push_back(temp); // store current unique substring
                charSet.clear(); // Empty the set
                temp = "";

                // restart from the position after previous start
                i = i - temp.length();
                continue;
            }

            temp += s[i];
            charSet.insert(s[i]);
        }

        // Store the last temp if not empty
        if (!temp.empty()) v.push_back(temp);

        // Find max length
        int max_len = 0;
        for (string x : v) {
            max_len = max(max_len, (int)x.length());
        }

        return max_len;
        */


        // Sliding window approach :-
        int n = s.size();
        set<char> charSet;
        int left = 0, right = 0;
        int max_len = 0;

        while (right < n) {
            if (charSet.find(s[right]) == charSet.end()) {
                // No duplicate, add character and expand window
                charSet.insert(s[right]);
                max_len = max(max_len, right - left + 1);
                right++;
            } else {
                // Duplicate found, shrink window from left
                charSet.erase(s[left]);
                left++;

                //  Input: "pwwkew"
                //  → Unique substrings: "pw", "wke"
                //  → Answer: 3
            }
        }

        return max_len;
    }
};
