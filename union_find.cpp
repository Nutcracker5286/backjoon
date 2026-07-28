#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2100];
int p[2100];

int find(int u)
{
    if (p[u] < 0)
        return u;
    p[u] = find(p[u]);
}

bool uni(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    if (p[v] < p[u])
        swap(u, v);

    if (p[u] == p[v])
        p[u]--;

    p[v] = u;
    return true;
}