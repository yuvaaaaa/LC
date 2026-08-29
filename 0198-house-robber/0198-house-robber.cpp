class Solution {
public:
    int money(vector<int>& nums, int index, vector<int>& dp) {
        if (index >= nums.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int take = nums[index] + money(nums, index + 2, dp);
        int nt = money(nums, index + 1, dp);

        return dp[index] = max(take, nt);
    }
    int rob(vector<int>& nums) {
    
        vector<int> dp(nums.size(), -1);
        return money(nums, 0, dp);
    }
};