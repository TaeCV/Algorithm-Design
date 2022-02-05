#include <bits/stdc++.h>

using namespace std;
vector<int> mulMatWithModK(const vector<int> &M, const vector<int> &N, int k) {
    return {(M[0] * N[0] + M[1] * N[2]) % k, (M[0] * N[1] + M[1] * N[3]) % k, (M[2] * N[0] + M[3] * N[2]) % k, (M[2] * N[1] + M[3] * N[3]) % k};
}

vector<int> matMod(const vector<int> &M, int n, int k) {
    if (n == 1) {
        return {M[0] % k, M[1] % k, M[2] % k, M[3] % k};
    };
    int newN = n >> 1;
    vector<int> newM = matMod(M, newN, k);
    vector<int> mn = mulMatWithModK(newM, newM, k);
    if (n % 2 == 1) {
        return mulMatWithModK(mn, matMod(M, 1, k), k);
    }
    return mn;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> M(4);
    for (int i = 0; i < 4; ++i)
        cin >> M[i];
    for (int &x : matMod(M, n, k))
        cout << x << " ";
}