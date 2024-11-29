#include <bits/stdc++.h>
#include <grid.h>

using namespace std;

namespace algo {

bool dfs(Grid initial_state, vector<Grid> &solution) {
  auto [r, c] = tie(initial_state.row, initial_state.col);
  set<string> visited;
  vector<vector<bool>> vis(r, vector<bool>(c, false));
  auto dfs_impl = [&](auto &self, Grid &cur_state) -> bool {
    if (cur_state.is_solved()) {
      return true;
    }
    string state_str = cur_state.to_string();
    if (visited.find(state_str) != visited.end()) {
      return false;
    }
    visited.emplace(state_str);
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (cur_state.is_empty(i, j) && !vis[i][j]) {
          vis[i][j] = true;
          for (auto &m : cur_state.magnets) {
            Grid cur = cur_state;
            cur.move(m.first, m.second, i, j);
            if (self(self, cur)) {
              solution.emplace_back(cur);
              return true;
            }
          }
          vis[i][j] = false;
        }
      }
    }
    return false;
  };
  bool res = dfs_impl(dfs_impl, initial_state);
  if (res) {
    solution.emplace_back(initial_state);
    reverse(solution.begin(), solution.end());
  }
  return res;
}

} // namespace algo
