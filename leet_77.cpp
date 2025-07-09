class Solution {
public:
//You don’t need the set<vector<int>> s. Because in correct backtracking, you will never generate duplicates.
    void get_combination(int n, int k, int i, vector<int>& combination, vector<vector<int>>& ans) {
        // If combination size k is reached, store it
        if (k == 0) {
            ans.push_back(combination);
            return;
        }
        // If no more elements to pick
        if (i > n) {
            return;
        }

        // Include current number i
        combination.push_back(i);
        get_combination(n, k - 1, i + 1, combination, ans);
        combination.pop_back();

        // Exclude current number i
        get_combination(n, k, i + 1, combination, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        vector<vector<int>> ans;
        get_combination(n, k, 1, combination, ans);
        return ans;
    }
};
