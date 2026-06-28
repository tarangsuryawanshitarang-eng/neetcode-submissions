class Solution {
   public:
    bool isValid(vector<int>& freq1, vector<int>& freq2) {

        for (int i = 0; i < 256; i++) {  // i.e more or equal
            if (freq1[i] < freq2[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int lo = 0, hi = 0, start = 0;
        int minlen = INT_MAX;

        vector<int> freq1(256, 0);  // window freq
        vector<int> freq2(256, 0);  // target freq

        // target string ke freq
        for (char c : t) freq2[c]++;

        while (hi < n) {
            freq1[s[hi]]++;

            // shrink jab window valid ho
            while (isValid(freq1, freq2)) {
                int len = hi - lo + 1;
                if (len < minlen) {
                    minlen = len;
                    start = lo;
                }

                freq1[s[lo]]--;
                lo++;
            }
            hi++;
        }
        return minlen == INT_MAX ? "" : s.substr(start, minlen);
    }
};
