class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1)
            return true;

        int num_prereq = prerequisites.size();
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> in_degree;
        for (int i = 0; i < numCourses; i++) {
            graph[i] = vector<int>();
            in_degree[i] = 0;
        }

        for (int i = 0; i < num_prereq; i++) {
            int out_node = prerequisites[i][0];
            int in_node = prerequisites[i][1];
            graph[out_node].push_back(in_node);
            in_degree[in_node]++;
        }

        queue<int> source;
        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                source.push(i);
            }
        }

        int num_out_nodes = 0;
        while (!source.empty()) {
            int out_node = source.front();
            source.pop();
            num_out_nodes++;
            int len_in_nodes = graph[out_node].size();
            for (int i = 0; i < len_in_nodes; i++) {
                int in_node = graph[out_node][i];
                in_degree[in_node]--;
                if (in_degree[in_node] == 0)
                    source.push(in_node);
            }
        }

        return num_out_nodes == numCourses;
    }
};