#ifndef DRAWER_H
#define DRAWER_H

#include <bits/stdc++.h>
#include <grid.h>
#include <ncurses.h>
#include <utils.h>

using namespace std;

void surround_cc(const int &x, const int &y, char ch = '!') {
  mvaddch(x - 1, y, ch != ' ' ? '-' : ' ');
  mvaddch(x + 1, y, ch != ' ' ? '-' : ' ');
  mvaddch(x, y - 1, ch != ' ' ? '|' : ' ');
  mvaddch(x, y + 1, ch != ' ' ? '|' : ' ');
  mvaddch(x - 1, y - 1, ch != ' ' ? '+' : ' ');
  mvaddch(x - 1, y + 1, ch != ' ' ? '+' : ' ');
  mvaddch(x + 1, y - 1, ch != ' ' ? '+' : ' ');
  mvaddch(x + 1, y + 1, ch != ' ' ? '+' : ' ');
}

void draw(vector<vector<node>> &grid, const int &s_row, const int &s_col,
          bool surround = true) {

  int row = grid.size();
  int col = grid[0].size();
  int total_width = col * 3 + 2;

  attron(COLOR_PAIR(WHITE));
  mvaddch(s_row - 2, s_col - 2, '+');
  for (int j = 0; j < total_width - 2; ++j) {
    mvaddch(s_row - 2 + 0, s_col - 2 + j + 1, '-');
  }
  mvaddch(s_row - 2, s_col - 2 + total_width - 1, '+');
  attroff(COLOR_PAIR(WHITE));

  for (size_t i = 0; i < row; ++i) {
    attron(COLOR_PAIR(WHITE));
    mvaddstr(s_row - 2 + i, s_col - 2, "| ");
    mvaddstr(s_row - 2 + (2 * row + 1) - i, s_col - 2, "| ");
    attroff(COLOR_PAIR(WHITE));
    for (size_t j = 0; j < col; ++j) {
      int x = s_row + i * 2;
      int y = s_col + j * 3;

      mvaddch(x, y, grid[i][j].ch);
      attron(COLOR_PAIR(grid[i][j].colour));
      mvaddch(x, y, grid[i][j].ch);
      attroff(COLOR_PAIR(grid[i][j].colour));

      // if (i == cur_chosen_cell.x && j == cur_chosen_cell.y) {
      //   attron(COLOR_PAIR(4));
      //   if (surround) {
      //     surround_cc(cc_s_cur_chosen_cell.x, cc_s_cur_chosen_cell.y, ' ');
      //     surround_cc(x, y);
      //   }
      //   cc_s_cur_chosen_cell.apply(x, y);
      //   attroff(COLOR_PAIR(4));
      // }
    }

    attron(COLOR_PAIR(WHITE));
    mvaddstr(s_row - 2 + i, s_col - 2 + total_width - 1, " |");
    mvaddstr(s_row - 2 + (2 * row + 1) - i, s_col - 2 + total_width - 1, " |");
    attroff(COLOR_PAIR(WHITE));
  }

  attron(COLOR_PAIR(WHITE));
  mvaddch(s_row + 2 * row, s_col - 2, '+');
  for (int j = 0; j < total_width - 2; ++j) {
    mvaddch(s_row + 2 * row, s_col - 2 + j + 1, '-');
  }
  mvaddch(s_row + 2 * row, s_col - 2 + total_width - 1, '+');
  attroff(COLOR_PAIR(WHITE));

  refresh();
}

void clear_grid(vector<vector<node>> &grid, const int &s_row, const int &s_col,
                bool surround = true) {

  int row = grid.size();
  int col = grid[0].size();
  int total_width = col * 3 + 2;

  mvaddch(s_row - 2, s_col - 2, ' ');
  for (int j = 0; j < total_width - 2; ++j) {
    mvaddch(s_row - 2 + 0, s_col - 2 + j + 1, ' ');
  }
  mvaddch(s_row - 2, s_col - 2 + total_width - 1, ' ');

  for (size_t i = 0; i < row; ++i) {
    mvaddstr(s_row - 2 + i, s_col - 2, "  ");
    mvaddstr(s_row - 2 + (2 * row + 1) - i, s_col - 2, "  ");
    for (size_t j = 0; j < col; ++j) {
      mvaddch(s_row + i * 2, s_col + j * 3, ' ');
    }

    mvaddstr(s_row - 2 + i, s_col - 2 + total_width - 1, "  ");
    mvaddstr(s_row - 2 + (2 * row + 1) - i, s_col - 2 + total_width - 1, "  ");
  }

  mvaddch(s_row + 2 * row, s_col - 2, ' ');
  for (int j = 0; j < total_width - 2; ++j) {
    mvaddch(s_row + 2 * row, s_col - 2 + j + 1, ' ');
  }
  mvaddch(s_row + 2 * row, s_col - 2 + total_width - 1, ' ');

  refresh();
}

namespace drawer {
void print(vector<Grid> state, const int &r, const int &c, const int &idx = 0) {
  int max_y, max_x;
  getmaxyx(stdscr, max_y, max_x);

  int s_row = (max_y - r - 2) / 2;
  int s_col = (max_x - (c * 2 + 2)) / 2;

  attron(COLOR_PAIR(RED));
  string nosts = format("Required {} Steps to solve",
                        bitset<8>(state.size() - 1).to_string());
  mvaddstr(2, 3, nosts.c_str());
  attroff(COLOR_PAIR(RED));

  if (idx < state.size()) {
    attron(COLOR_PAIR(CYAN));
    mvaddstr(s_row - 5, s_col - r * 3 + 1,
             format("state: {}", bitset<8>(idx + 1).to_string()).c_str());
    attroff(COLOR_PAIR(CYAN));
    draw(state[idx].grid, s_row, s_col - r * 3 - 5, false);
  }

  attron(COLOR_PAIR(CYAN));
  mvaddstr(s_row - 5, s_col + r * 3 + 13,
           format("state: {}", bitset<8>(idx + 2).to_string()).c_str());
  attroff(COLOR_PAIR(CYAN));
  if (idx + 1 < state.size()) {
    draw(state[idx + 1].grid, s_row, s_col + r * 3 + 5);
  } else if (!state.empty()) {
    clear_grid(state[0].grid, s_row, s_col + r * 3 + 5);
  }
}
} // namespace drawer

#endif
