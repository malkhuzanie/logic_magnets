#include <bits/stdc++.h>
#include <grid.h>

using namespace std;

template <typename T>
using min_heap = priority_queue<T, std::vector<T>, std::greater<T>>;

namespace algo {

bool dijkstra(Grid &state, vector<vector<int>> dis, set<string> &visited,
              vector<Grid> &solution) {
  if (state.is_solved()) {
    return true;
  }

  string state_str = state.to_string();
  if (visited.find(state_str) != visited.end()) {
    return false;
  }

  visited.emplace(state_str);

  min_heap<pair<int, pair<int, int>>> pq;
  for (auto &magnet : state.magnets) {
    pq.emplace(pair(dis[magnet.first][magnet.second], magnet));
  }
  while (!pq.empty()) {
    auto [d, s] = pq.top();
    pq.pop();
    for (int i = 0; i < dis.size(); ++i) {
      for (int j = 0; j < dis[0].size(); ++j) {
        if (i == s.first && j == s.second) {
          continue;
        }
        if (state.is_empty(i, j)) {
          if (int wgt = d + 1; wgt < dis[i][j]) {
            dis[i][j] = wgt;
            pq.emplace(pair(dis[i][j], pair(i, j)));
            Grid next_state = state;
            next_state.move(s.first, s.second, i, j);
            if (dijkstra(next_state, dis, visited, solution)) {
              solution.emplace_back(next_state);
              return true;
            }
          }
        }
      }
    }
  }
  return false;
}

// naive dijkstra / ucs implementation
bool dijkstra(Grid initial_state, vector<Grid> &solution) {
  auto [r, c] = tie(initial_state.row, initial_state.col);
  set<string> visited;
  vector<vector<int>> dis(r, vector<int>(c, numeric_limits<int>::max()));
  for (auto &m : initial_state.magnets) {
    dis[m.first][m.second] = 0;
  }
  if (dijkstra(initial_state, dis, visited, solution)) {
    solution.emplace_back(initial_state);
    reverse(solution.begin(), solution.end());
    return true;
  }
  return false;
}
} // namespace algo
