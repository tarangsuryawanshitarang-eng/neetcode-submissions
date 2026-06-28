class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0;
        int minele = arr[0];
        for(int ele : arr){
            profit = max ( profit , ele - minele);
            minele = min ( ele , minele);
        }
        return profit;
    }
};
