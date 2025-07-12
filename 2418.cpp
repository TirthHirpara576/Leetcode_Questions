class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        map<int, string, greater<int>> myMap;
        for(int i=0;i<n;i++){
            myMap[heights[i]] = names[i];
        }
        
        vector<string> ans;
        for(auto it=myMap.begin();it!=myMap.end();it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};