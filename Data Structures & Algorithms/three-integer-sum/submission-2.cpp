class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int lo = i + 1, hi = n - 1;

            while (lo < hi) {
                int sum = nums[lo] + nums[hi] + nums[i];

                if (sum == 0) {
                    ans.push_back({nums[i], nums[lo], nums[hi]});

                    while (lo < hi && nums[lo] == nums[lo + 1]) lo++;
                    while (lo < hi && nums[hi] == nums[hi - 1]) hi--;

                    lo++;
                    hi--;
                }

                else if (sum > 0)
                    hi--;

                else
                    lo++;
            }
        }
        return ans;
    }
};
