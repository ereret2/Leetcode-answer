class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return vector<int>(1, 0);

        if (n == 2)
            return vector<int>{0, 1};

        vector<int> roots;
        unordered_map<int, vector<int>> undirected_graph;
        unordered_map<int, int> in_degree;

        for (int i = 0; i < n; i++) {
            undirected_graph[0] = vector<int>();
            in_degree[0] = 0;
        }

        int num_edge = edges.size();
        for (int i = 0; i < num_edge; i++) {
            int vertex1 = edges[i][0], vertex2 = edges[i][1];
            undirected_graph[vertex1].push_back(vertex2);
            undirected_graph[vertex2].push_back(vertex1);
            in_degree[vertex1]++;
            in_degree[vertex2]++;
        }

        queue<int> leaves;
        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 1)
                leaves.push(i);
        }

        int total_size = n;
        while (total_size > 2) {
            int size_leaves = leaves.size();
            total_size -= size_leaves;
            for (int i = 0; i < size_leaves; i++) {
                int vertex = leaves.front();
                leaves.pop();
                int size_child = undirected_graph[vertex].size();
                for (int j = 0; j < size_child; j++) {
                    int child = undirected_graph[vertex][j];
                    in_degree[child]--;
                    if (in_degree[child] == 1)
                        leaves.push(child);
                }
            }
        }
        
        int size_leaves = leaves.size();
        for (int i = 0; i < size_leaves; i++) {
            int vertex = leaves.front();
            leaves.pop();
            roots.push_back(vertex);
        }

        return roots;
    }
};