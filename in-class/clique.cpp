void dfs(G = (V, E), u, visited[1...n]) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if ({u, v} is in E && !visited[v])
            dfs(v);
    }
}

bool Clique(G = (V, E), k) {
    for (int u = 1; u <= | V | ; ++u) {
        // checking k or more vertices
        if (visited[u]) {
            vector<bool> visited(| V |, false);
            dfs(G, u, visited);
            int count = 0;
            for (bool each : visited)
                count += each;
            if (count >= k)
                return true;
        }
    }
    return false;
}