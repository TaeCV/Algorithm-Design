#include "stdio.h"

int n, m, k, g, h,sm = 0;
int b[5000],day[5000];
int edges[5000][5000];

void dfs(int u) {
    sm -= b[u];
    b[u] = 0;
    for (int v=0;v<n;++v) {
        if (edges[u][v] && b[v])
            dfs(v);
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&b[i]);
        sm += b[i];
    }
    for (int i = 0; i < k; ++i)
        scanf("%d",&day[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&g,&h);
        edges[g][h] = 1;
    }
    for (int i = 0; i < k; ++i) {
        dfs(day[i]);
        printf("%d ",sm);
    }
}