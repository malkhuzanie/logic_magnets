#ifndef UTILS_H
#define UTILS_H

#include <bits/stdc++.h>
using namespace std;

int rand(const int &low, const int &high) {
  std::random_device r;
  static std::default_random_engine eng{r()};
  return std::uniform_int_distribution<>{low, high}(eng);
}

template <typename T> T get_random(std::set<T> &s) {
  auto it = s.begin();
  advance(it, rand(0, s.size() - 1));
  T val = *it;
  s.erase(it);
  return val;
}

struct cord {
  int x, y;
  void apply(int xx, int yy) {
    x = xx;
    y = yy;
  }

  operator std::pair<int, int>() const { return {x, y}; }
};

enum COLOR { WHITE = 0, RED = 1, GREEN = 2, BLUE = 3, CYAN = 4 };

struct node {
  char ch;
  enum COLOR colour;
};

bool operator==(const cord &lhs, const cord &rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y;
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

#endif
