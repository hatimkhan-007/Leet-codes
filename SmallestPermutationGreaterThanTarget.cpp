class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        if (s.size() != target.size()) return "";

        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }

        string ans = "";
        int best_diverge_idx = -1;
        char best_diverge_char = ' ';

        for (int i = 0; i < s.size(); i++) {
            for (int c = (target[i] - 'a') + 1; c < 26; c++) {
                if (count[c] > 0) {
                    best_diverge_idx = i;
                    best_diverge_char = (char)('a' + c);
                    break; 
                }
            }

            int target_char_idx = target[i] - 'a';
            if (count[target_char_idx] > 0) {
                count[target_char_idx]--; 
                ans.push_back(target[i]);
            } else {
                break;
            }
        }

        if (best_diverge_idx == -1) return "";
        int final_count[26] = {0};
        for (char c : s) final_count[c - 'a']++;

        string final_ans = "";
        for (int i = 0; i < best_diverge_idx; i++) {
            final_ans.push_back(target[i]);
            final_count[target[i] - 'a']--;
        }
        final_ans.push_back(best_diverge_char);
        final_count[best_diverge_char - 'a']--;
        for (int c = 0; c < 26; c++) {
            while (final_count[c] > 0) {
                final_ans.push_back((char)('a' + c));
                final_count[c]--;
            }
        }

        return final_ans;
    }
};
