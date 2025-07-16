class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> ms(nums1.begin(), nums1.end()); // Here, we also need to add duplicate elements
        vector<int> ans;

        for (int x : nums2) {
            auto it = ms.find(x); // Remove only one occurrence
            if (it != ms.end()) {
                ans.push_back(x);
                ms.erase(it);  // If I write -> ms.erase(x); Then All occurance of "x" would be deleted.
            }
        }

        return ans;
    }
};