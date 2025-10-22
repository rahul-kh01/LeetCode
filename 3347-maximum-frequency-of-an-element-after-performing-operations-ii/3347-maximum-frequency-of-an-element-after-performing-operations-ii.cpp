class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int>mp;
        map<int, int>sweep;
        for(auto &e: nums)
        {
            mp[e]++;

            sweep[max(0, e-k)]++;
            sweep[e+k+1]--;

            if(sweep.find(e) == sweep.end()) sweep[e] = 0;
        }

        int ans = 0, cnt = 0;

        for(auto &[num, fre]: sweep)
        {
            cnt += fre;
            ans = max(ans, mp[num] + min(numOperations, (cnt - mp[num])));
        }
        return ans;
    }
};