class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        if (s.size() != target.size()) return "";
        
        int n = s.size();
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        
        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        if (odd_count > 1) return ""; 

        int half_len = n / 2;
        int half_count[26] = {0};
        for (int i = 0; i < 26; i++) {
            half_count[i] = count[i] / 2; 
        }

        string best_pal = "";
        
        for (int i = half_len; i >= 0; i--) {
            int current_half_count[26];
            for (int k = 0; k < 26; k++) current_half_count[k] = half_count[k];
            
            bool possible = true;
            string prefix = "";
            
            for (int j = 0; j < i; j++) {
                int t_idx = target[j] - 'a';
                if (current_half_count[t_idx] > 0) {
                    prefix.push_back(target[j]);
                    current_half_count[t_idx]--;
                } else {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            
            int start_char = 0;
            if (i < half_len) {
                start_char = (target[i] - 'a') + 1;
            }
            
            for (int c = start_char; c < 26; c++) {
                if (i < half_len && current_half_count[c] <= 0) continue;
                
                string current_half = prefix;
                int temp_count[26];
                for (int k = 0; k < 26; k++) temp_count[k] = current_half_count[k];
                
                if (i < half_len) {
                    current_half.push_back((char)('a' + c));
                    temp_count[c]--;
                }
                
                for (int k = 0; k < 26; k++) {
                    while (temp_count[k] > 0) {
                        current_half.push_back((char)('a' + k));
                        temp_count[k]--;
                    }
                }
                
                string full = current_half;
                if (n % 2 != 0) {
                    full.push_back(mid_char);
                }
                string rhs = current_half;
                reverse(rhs.begin(), rhs.end());
                full += rhs;
                
                if (full > target) {
                    if (best_pal.empty() || full < best_pal) {
                        best_pal = full;
                    }
                }
                
                if (i == half_len) break;
            }
        }
        
        return best_pal;
    }
};
