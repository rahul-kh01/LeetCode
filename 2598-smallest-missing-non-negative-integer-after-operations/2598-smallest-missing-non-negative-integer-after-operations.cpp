class Solution {
public:
	int findSmallestInteger(vector<int>& nums, int v) {
    vector<int> rem(v, 0);
    for (int num : nums) rem[(num % v + v) % v]++;
    int res = 0;
    while (rem[res % v] > 0) rem[res++ % v]--;
    return res;
}

};