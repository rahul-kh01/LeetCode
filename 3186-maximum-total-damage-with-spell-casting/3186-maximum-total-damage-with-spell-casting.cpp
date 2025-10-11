class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        sort(power.begin(), power.end());
        vector<long long> dp(n+2);

        int i = n-1, j = n-1, k = n-1;
        while(i >= 0) {
            while(j>=i && power[j] > power[i]+2) j--;
            while(k>=0 && power[k] == power[i]) k --;
            dp[k+1] = dp[i] = max(dp[i+1], power[i]*1ll*(i-k) + dp[j+1]);
            i = k;
        }

        return dp[0];
    }
};