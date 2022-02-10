#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> RC(50005, vector<int>(505));
vector<vector<int>> RC2(50005);
vector<int> CR(50005, -1);

int cal(int K, int root) {
    int n = RC2[root].size(), ans;
    if (n == 0)
        return 0;
    else if (n == 1) {
        ans = cal(K, RC2[root][0]);
        return ans + RC[root][K - 1];
    } else if (n == 2) {
        int leftChild = RC2[root][0], rightChild = RC2[root][1];
        ans = cal(K, leftChild) + cal(K, rightChild);
        ans += RC[root][2 * (K - 1)] + RC[root][2 * (K - 1) + 1];
        for (int i = K - 2; i >= 0; --i) {
            ans += RC[root][2 * i] * RC[root][2 * (K - i - 2) + 1];
        }
        return ans;
    }
    return 0;
}

void prepare(int itself, int root, int height) {
    if (root == -1)
        return;
    int childNum = RC2[root][0] == itself ? 0 : 1;
    RC[root][2 * height + childNum]++;
    prepare(root, CR[root], height + 1);
}

int main() {
    int N, K, root, child, first;
    cin >> N >> K;
    for (int i = 0; i < N - 1; ++i) {
        cin >> root >> child;
        if (i == 0)
            first = root;
        RC2[root].push_back(child);
        CR[child] = root;
    }
    for (int i = 1; i <= N; ++i) {
        prepare(i, CR[i], 0);
    }
    cout << cal(K, first);
}

/*
6 2
1 2
1 5
5 6
2 4
2 3

6 4
1 2
1 5
5 6
2 4
2 3
*/