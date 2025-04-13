// двудольность
class Solution {
public:
    void dfs_bipartite(std::vector<std::vector<int>> &graph, int v, std::vector<int> &visited, bool &isValid) {
        for (int elem : graph[v]) {
            if (visited[elem] == -1) {
                visited[elem] = (visited[v] == 0 ? 1 : 0);
                dfs_bipartite(graph, elem, visited, isValid);
            } else if (visited[v] == visited[elem]) {
                isValid = false;
            } 
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        std::vector<int> visited(graph.size(), -1);
        bool isValid = true;
        for (int i = 0; i < graph.size(); ++i) {
        if (visited[i] == -1) {
            visited[i] = 0;
            dfs_bipartite(graph, i, visited, isValid);
        }

        }
        return isValid;
    }
};
