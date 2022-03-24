int count_friend(int u, int k) {
    queue<int> q;
    q.push(u);
    visited[u] = true;
    dist[u] = 0;
    int count = 0;
    while (q.size() > 0) {
        int v = q.front();
        q.pop();
        count++;
        for (auto x : edges[v]) {
            if (visited[x] == false) {
                visited[x] = true;
                dist[x] = dist[v] + 1;
                if (dist[x] < k)
                    q.push(x);
            }
        }
    }
    return count;
}