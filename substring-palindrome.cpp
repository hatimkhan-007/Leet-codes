#include <iostream>
#include <cstring>

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";
        int start = 0;
        int maxLen = 1;
        for(int i = 0; i < n; i++){
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                int currentLen = r - l + 1;
                if( currentLen > maxLen){
                    start = l;
                    maxLen = currentLen;
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                int currentLen = r - l + 1;
                if(currentLen > maxLen){
                    start = l;
                    maxLen = currentLen;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxLen);
    }
};