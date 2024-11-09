#include <dfs.h>
#include <drawer.h>
#include <iostream>

using namespace std;

void init_ncurses();

void draw_outer_box();

int main() {

  init_ncurses();
  draw_outer_box();

  cout << "starting...\n";
  int r = 5;
  int c = 5;
  Solve solution = Solve(r, c);
  // solution.print(solution.state.back());
  drawer::print(solution.state, r, c);
  solution.dfs(Grid(r, c));
  drawer::print(solution.state, r, c);

  int ch;
  int idx = 0;
  while ((ch = getch()) != 'q') {
    switch (ch) {
    case KEY_LEFT:
      if (idx - 2 >= 0) {
        idx -= 2;
      }
      break;
    case KEY_RIGHT:
      if (idx + 2 < solution.state.size()) {
        idx += 2;
      }
      break;
    }
    drawer::print(solution.state, r, c, idx);
  }

  endwin();
}

void init_ncurses() {
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  noecho();
  curs_set(0);

  start_color();
  init_pair(WHITE, COLOR_WHITE, COLOR_BLACK);
  init_pair(RED, COLOR_RED, COLOR_BLACK);
  init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
  init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
  init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
}

void draw_outer_box() {
  attron(COLOR_PAIR(2));
  box(stdscr, 0, 0);
  attroff(COLOR_PAIR(2));
}