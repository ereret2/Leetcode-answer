class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> frequency_map;
        for (int i = 0; i < n; i++) {
            frequency_map[s[i]]++;
        }
        priority_queue<pair<int, char>> frequency_pq;
        for (auto it = frequency_map.begin(); it != frequency_map.end(); it++) {
            frequency_pq.push(pair<int, char>(it->second, it->first));
        }
        string res;
        while (!frequency_pq.empty()) {
            pair<int, char> tmp = frequency_pq.top();
            frequency_pq.pop();
            res.append(tmp.first, tmp.second);
        }
        return res;
    }
};