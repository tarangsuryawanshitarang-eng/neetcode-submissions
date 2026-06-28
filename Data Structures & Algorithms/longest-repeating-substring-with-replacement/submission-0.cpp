class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int lo = 0, hi = 0, ans = 0;

        int maxfreq = 0;
        vector<int> freq(26, 0);

        while (hi < n) {
            freq[s[hi] - 'A']++;

            maxfreq = max(maxfreq, freq[s[hi] - 'A']);

            int sub_arr_len = hi - lo + 1;
            int diff = sub_arr_len - maxfreq;

            while (diff > k) {  // srink
                freq[s[lo] - 'A']--;
                lo++;

                // update
                sub_arr_len = hi - lo + 1;
                diff = sub_arr_len - maxfreq;
            }

            ans = max(ans, hi - lo + 1);
            hi++;
        }
        return ans;
    }
};
