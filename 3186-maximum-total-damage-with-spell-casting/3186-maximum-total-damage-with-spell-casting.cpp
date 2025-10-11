class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        // Step 1: Count frequency of each power
        unordered_map<int, long long> freq;
        for (int p : power) freq[p]++;

        // Step 2: Extract and sort unique powers
        vector<int> nums;
        for (auto it : freq) nums.push_back(it.first);
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<long long> dp(n);

        // Base case
        dp[0] = freq[nums[0]] * nums[0];

        // Step 3: Build dp array
        for (int i = 1; i < n; i++) {
            long long take = freq[nums[i]] * nums[i];
            
            // find previous power > 2 smaller
            int j = i - 1;
            while (j >= 0 && nums[i] - nums[j] <= 2) j--;
            if (j >= 0) take += dp[j];

            dp[i] = max(dp[i - 1], take);
        }

        return dp[n - 1];
    }
};
