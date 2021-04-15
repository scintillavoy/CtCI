#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

void DrawLine(vector<bitset<8>> &screen, int width, int x1, int x2, int y) {
  if (x1/8 == x2/8) {   // Caution ! if x1 and x2 are in the same byte
    screen[width/8*y + x1/8] |= ((1 << 8-x1%8) - 1) & (~0 << 7-x2%8);
  } else {
    screen[width/8*y + x1/8] |= (1 << 8-x1%8) - 1;
    for (int i = x1/8 + 1; i < x2/8; ++i) {
      screen[width/8*y + i] = ~0;
    }
    screen[width/8*y + x2/8] |= ~((1 << 7-x2%8) - 1);
  }
}

int main() {
  vector<bitset<8>> scr;
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  scr.emplace_back("00000000"); scr.emplace_back("00000000"); scr.emplace_back("00000000");
  DrawLine(scr, 24, 9, 21, 4);
  for (int i = 0; i < scr.size(); ++i) {
    cout << scr[i];
    if (i % 3 == 2) {
      cout << endl;
    }
  }
  return 0;
}
