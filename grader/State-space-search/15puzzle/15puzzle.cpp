#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int>> VVI;

struct board {
    VVI table = VVI(4, vector<int>(4));
    int cost;
    pair<int, int> zeroPos;
    bool operator<(const board &other) const {
        return cost > other.cost;
    }

    void printTable() {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                cout << table[i][j] << " ";
            cout << "\n";
        }
    }
};

board starter;
pair<int, int> pos[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
set<VVI> s;

int cost(board b) {
    int c = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (b.table[i][j] == 0)
                continue;
            int x = b.table[i][j];
            c += abs(i - (x - 1) / 4) + abs(j - (x - 1) % 4);
        }
    }
    return c;
}

int cal() {
    priority_queue<pair<board, int>> pq;
    starter.cost = cost(starter);
    s.insert(starter.table);
    pq.push({starter, 0});
    while (!pq.empty()) {
        board now = pq.top().first;
        int n = pq.top().second;
        // cout << -n << " " << now.cost << "\n";
        // now.printTable();
        pq.pop();
        if (now.cost + n == 0)
            return -n;
        for (auto p : pos) {
            int oldX = now.zeroPos.first, oldY = now.zeroPos.second;
            int x = oldX + p.first;
            int y = oldY + p.second;
            if (x < 0 || x >= 4 || y < 0 || y >= 4)
                continue;
            board newBoard = now;
            swap(newBoard.table[oldX][oldY], newBoard.table[x][y]);
            if (s.find(newBoard.table) != s.end())
                continue;
            newBoard.cost = cost(newBoard) - n + 1;
            newBoard.zeroPos = {x, y};
            pq.push({newBoard, n - 1});
            s.insert(newBoard.table);
        }
    }
}

int main() {
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
            cin >> starter.table[i][j];
            if (starter.table[i][j] == 0)
                starter.zeroPos = {i, j};
        }
    cout << cal();
}