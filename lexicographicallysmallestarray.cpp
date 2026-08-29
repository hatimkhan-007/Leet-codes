class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n == 0) return nums;

        vector<pair<int, int>> sorted_pairs(n);
        for (int i = 0; i < n; i++) {
            sorted_pairs[i] = {nums[i], i};
        }
        
        sort(sorted_pairs.begin(), sorted_pairs.end());
        
        vector<vector<int>> groups_vals;
        vector<vector<int>> groups_idxs;
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || sorted_pairs[i].first - sorted_pairs[i - 1].first > limit) {
                groups_vals.push_back({});
                groups_idxs.push_back({});
            }
            groups_vals.back().push_back(sorted_pairs[i].first);
            groups_idxs.back().push_back(sorted_pairs[i].second);
        }
        
        vector<int> result(n);
        for (int i = 0; i < groups_vals.size(); i++) {
            vector<int>& vals = groups_vals[i];
            vector<int>& idxs = groups_idxs[i];
            
            sort(idxs.begin(), idxs.end());
            
            for (int j = 0; j < vals.size(); j++) {
                result[idxs[j]] = vals[j];
            }
        }
        
        return result;
    }
};
