#include <bits/stdc++.h>
#include <drawer.h>
#include <grid.h>

using namespace std;

class Solve {
public:
  Solve(int r, int c) : r(r), c(c) {}

  // holds the solution states
  vector<Grid> state;

  set<string> visited;

  bool dfs(Grid initial_state) {
    state = vector<Grid>();
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
                state.emplace_back(cur);
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
      state.emplace_back(initial_state);
      reverse(state.begin(), state.end());
    }
    return res;
  }

  void print(vector<vector<node>> &adj) {
    cout << "---------------------------------------\n";
    for (auto &x : adj) {
      for (auto &y : x) {
        cout << y.ch << ' ';
      }
      cout << '\n';
    }
  }

  int r;
  int c;
};
