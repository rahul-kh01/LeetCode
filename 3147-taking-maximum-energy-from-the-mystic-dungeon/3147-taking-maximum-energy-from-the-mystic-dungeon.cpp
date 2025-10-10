class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        
        // Traverse from the end towards the start
        for (int i = n - 1; i >= 0; --i) {
            if (i + k < n) energy[i] += energy[i + k]; // accumulate optimal future energy
            ans = max(ans, energy[i]);                // track maximum energy so far
        }
        return ans;
    }
};
