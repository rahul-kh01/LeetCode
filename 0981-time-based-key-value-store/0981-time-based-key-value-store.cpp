class TimeMap {
    unordered_map<string, vector<pair<int, string>>> mp;
public:
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        auto &v = mp[key];
        if (v.empty()) return "";

        int low = 0, high = v.size() - 1;
        while (low < high) {
            int mid = (low + high + 1) >> 1; // bias mid to right
            if (v[mid].first <= timestamp) low = mid;
            else high = mid - 1;
        }
        return v[low].first <= timestamp ? v[low].second : "";
    }
};
