class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        int sum1 = 0;
        for(int stone : stones){
            sum1 += stone;
        }

        int max_diff = sum1;
        for(int i = n - 2; i > 0; i--){
            sum1 -= stones[i + 1];
            max_diff = max(max_diff, sum1 - max_diff);
        } 
        return max_diff;
    }
};