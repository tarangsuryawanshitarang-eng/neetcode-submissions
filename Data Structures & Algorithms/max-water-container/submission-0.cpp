class Solution {
   public:
    int maxArea(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        int ans = 0;

        while (lo < hi) {
            // cal for all
            int height = min(arr[lo], arr[hi]);  
            int width = hi - lo;

            ans = max ( ans , height * width); // volume

            if (arr[lo] < arr[hi]) lo++;

            else  hi--;
            
        }

        return ans;
    }
};
