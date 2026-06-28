class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int lo = 0, hi = 0, ans = 0;

        unordered_map<char, int> freq;

        while (hi < n) {
            freq[s[hi]]++;

            while (freq[s[hi]] > 1) {  // duplicate

                freq[s[lo]]--;
                if (freq[s[lo]] == 0) freq.erase(s[lo]);
                lo++;
            }

            ans = max(ans, hi - lo + 1);
            hi++;
        }
        return ans;
    }
};
