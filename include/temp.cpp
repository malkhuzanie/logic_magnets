// void move(const int &dir) {
//   int x = pos.x;
//   int y = pos.y;

//   (dir == KEY_UP      ? x -= 1
//    : dir == KEY_DOWN  ? x += 1
//    : dir == KEY_LEFT  ? y -= 1
//    : dir == KEY_RIGHT ? y += 1
//                       : false);
//   if (dir == 9) {
//     int nx, ny;
//     grid[pos.x][pos.y].colour == 2 ? find(4, nx, ny) : find(2, nx, ny);
//     pos.apply(nx, ny);
//     return;
//   }

//   if (inside(x, y) && grid[x][y].ch == ' ') {
//     int ccc = grid[pos.x][pos.y].colour;
//     grid[pos.x][pos.y] = node(' ', 1);
//     pos.apply(x, y);
//     grid[x][y] = node('O', ccc);
//     check_filled(x, y);
//   }
// }
