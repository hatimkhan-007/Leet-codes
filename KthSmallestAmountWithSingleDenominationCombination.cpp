class Solution {
    long long gcd(long long a, long long b){
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b){
        return (a / gcd(a, b)) * b;
    }

    long long countMultiples(long long max_val, const vector<int>& coins){
        long long total_counts = 0;
        int n = coins.size();
        int total_subsets = 1 << n;

        for(int i = 1; i < total_subsets; i++){
            long long current_lcm = 1;
            int element_count = 0;
            for(int j = 0; j < n; j++){
                if((i >> j) & 1){
                    current_lcm = lcm(current_lcm, coins[j]);
                    element_count++;
                    if(current_lcm > max_val) break;
                }
            }
            if(element_count % 2 != 0){
                total_counts += (max_val / current_lcm);
            } else {
                total_counts -= (max_val / current_lcm);
            }
        }
        return total_counts;
    }


public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long min_val = *min_element(coins.begin(), coins.end());
        long long low = 1;
        long long high = min_val * k;
        long long answer = high;
        
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(countMultiples(mid, coins) >= k){
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return answer;
    }
};