#include <bits/stdc++.h>
#include <grid.h>

using namespace std;

template <typename T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;

namespace algo {
bool dfs(Grid initial_state, vector<Grid> &solution);

// naive dijkstra / ucs implementation
bool dijkstra(Grid initial_state, vector<Grid> &solution);

bool dijkstra(Grid &state, vector<vector<int>> dis, set<string> &visited,
              vector<Grid> &solution);

} // namespace algo
