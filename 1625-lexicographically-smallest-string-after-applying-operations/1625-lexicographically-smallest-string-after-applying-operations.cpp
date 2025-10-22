class Solution {
public:
string rotateRight(string &s,int b){
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+b);
    reverse(s.begin()+b,s.end());
    return s;
   }
    string findLexSmallestString(string s, int a, int b) {
      

        string ans = s;
        queue<string> q({s});
        unordered_set<string> seen({s});

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            ans = min(ans, cur);

            // Operation 1: add 'a' to digits at odd indices
            for (int i = 1; i < cur.size(); i += 2)
                cur[i] = ((cur[i] - '0' + a) % 10) + '0';
            if (seen.insert(cur).second) q.push(cur);

            // Operation 2: rotate by b
            auto rot = rotateRight(cur,b);
            if (seen.insert(rot).second) q.push(rot);
        }
        return ans;
    }
};
