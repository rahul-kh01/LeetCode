class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans{words[0]};
        for (int i = 1; i < words.size(); i++) {
            string cur = words[i], prev = words[i - 1];
            sort(cur.begin(), cur.end());
            sort(prev.begin(), prev.end());
            if (cur != prev) ans.push_back(words[i]);
        }
        return ans;
    }
};
