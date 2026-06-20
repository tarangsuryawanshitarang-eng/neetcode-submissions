class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // insert all element in set
        unordered_set<int> s(nums.begin(), nums.end());

        int maxlen = 0;

        for (int ele : s) {
            // check wether its starting of sequence ?
            if (!s.count(ele - 1)) {
                int curr = ele;
                int len = 1;  // if start -> ele -> len = 1;

                while (s.count(curr + 1)) {
                    curr++;
                    len++;
                }
                maxlen = max(len , maxlen);
            }
        }
        return maxlen;
    }
};
