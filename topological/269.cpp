class Solution {
public:
    string alienOrder(vector<string>& words) {
        int num_words = words.size();
        if (num_words == 0)
            return "";
        
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> in_degree;
        for (int i = 0; i < num_words; i++) {
            int len = words[i].size();
            for (int j = 0; j < len; j++) {
                graph[words[i][j]] = vector<char>();
                in_degree[words[i][j]] = 0;
            }
        }

        int num_character = 0;
        for (auto vertex : graph) {
            num_character++;
        }

        for (int i = 0; i < num_words - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len_w1 = w1.size(), len_w2 = w2.size();
            for (int j = 0; j < min(len_w1, len_w2); j++) {
                char parent = w1[j], child = w2[j];
                if (parent != child) {
                    graph[parent].push_back(child);
                    in_degree[child]++;
                    break;
                }
                if (j == (min(len_w1, len_w2) - 1) && len_w1 > len_w2)
                    return "";

            }
        }

        queue<char> source;
        for (auto item : in_degree) {
            if (item.second == 0) {
                source.push(item.first);
            }
        }

        string res = "";
        while (!source.empty()) {
            char parent = source.front();
            source.pop();
            res += parent;
            int len = graph[parent].size();
            for (int i = 0; i < len; i++) {
                char child = graph[parent][i];
                in_degree[child]--;
                if (in_degree[child] == 0)
                    source.push(child);
            }
        }

        //cout << res << endl;
        if (res.size() != num_character)
            return "";
        return res;
    }
};