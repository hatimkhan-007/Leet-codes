class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        if(count(s.begin(), s.end(), '1') < k){
            return "";
        }
        string ans = "";
        int left = 0;
        int count_ones = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                count_ones++;
            }
            while(count_ones == k){
                int len = i - left + 1;
                string substring = s.substr(left, len);
                if(ans.empty() || substring.size() < ans.size() || substring.size() == ans.size() && substring < ans){
                    ans = substring;
                }
                if(s[left] == '1'){
                    count_ones--;
                }
                left++;
            }
        }
        return ans;
    }
};