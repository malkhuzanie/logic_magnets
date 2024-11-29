#ifndef GRID_H
#define GRID_H

#include <bits/stdc++.h>
#include <ncurses.h>
#include <utils.h>

using namespace std;

class Grid {
public:
  Grid() {}

  Grid(vector<vector<char>> &adj) : adj(adj) {}

  Grid(int row, int col) : row(row), col(col) {
    grid = vector<vector<node>>(row, vector<node>(col, node(' ', WHITE)));
    init();
  }

  void init() {
    magnets = {{row - 1, col - 1}};
    // grid[0][0] = node('+', RED);
    grid[row - 1][col - 1] = node('-', BLUE);

    holes = {{0, 2}, {4, 2}, {2, 0}, {2, 4}, {2, 2}};
    for (auto &[x, y] : holes) {
      grid[x][y] = node('.', WHITE);
    }

    // iron balls
    grid[1][2] = grid[3][2] = grid[2][1] = grid[2][3] = node('O', GREEN);

    balls_count = 1 + 4;
  }

  bool inside(const int &x, const int &y) {
    return x >= 0 && x < row && y >= 0 && y < col;
  }

  int sign(const int &num) { return num > 0 ? 1 : -1; }

  void analyse_borders(int x, int y) {
    for (int i = 0; i < dx.size(); ++i) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (inside(xx, yy) && !is_empty(xx, yy)) {
        int co = (grid[x][y].ch == '+' ? -1 : 1);
        int nx = xx + co * 1 * (dx[i] + sign(dx[i])) / 2;
        int ny = yy + co * 1 * (dy[i] + sign(dy[i])) / 2;
        if (inside(nx, ny) && is_empty(nx, ny)) {
          if (auto m = find(magnets.begin(), magnets.end(), pair(xx, yy));
              m != magnets.end()) {
            *m = pair(nx, ny);
          }
          grid[nx][ny] = grid[xx][yy];
          grid[xx][yy] = node(' ', WHITE);
        }
      }
    }
  }

  void move(const int &x, const int &y, const int &xx, const int &yy) {
    auto cur = grid[x][y];
    grid[x][y] = node(' ', WHITE);
    auto m = find(magnets.begin(), magnets.end(), pair(x, y));
    *m = pair(xx, yy);
    grid[xx][yy] = cur;
    analyse_borders(xx, yy);
  }

  int filled() {
    int cnt = 0;
    for (auto &[x, y] : holes)
      cnt += !is_empty(x, y);
    return cnt;
  }

  bool is_solved() {
    int cnt = 0;
    for (auto &[x, y] : holes)
      cnt += !is_empty(x, y);
    return cnt == balls_count;
  }

  bool is_empty(const int &x, const int &y) {
    return grid[x][y].ch == ' ' || grid[x][y].ch == '.';
  }

  string to_string() {
    string res;
    for (auto &x : grid) {
      for (auto &y : x) {
        res += (y.ch == ' ' || y.ch == '.' ? '.' : y.ch);
      }
    }
    return res;
  }

  int row;
  int col;

  int balls_count = 0;

  vector<vector<char>> adj;
  vector<vector<node>> grid;
  set<pair<int, int>> holes;

  vector<pair<int, int>> magnets;

  vector<int> dx = {+1, -1, 0, 0, +2, -2, 0, 0};
  vector<int> dy = {0, 0, +1, -1, 0, 0, +2, -2};
};

#endif
