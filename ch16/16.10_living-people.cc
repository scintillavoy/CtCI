#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Time complexity: O(P + R),
// where P is the number of people and R is the range of years
// O(PlogP) solution is also possible
int LivingPeople(const vector<pair<int, int>> &people) {
  vector<int> years(102, 0);
  for (const auto &person : people) {
    ++years[person.first-1900];
    --years[person.second-1900+1];
  }
  int max_alive = -1;
  int max_alive_year = -1;
  int alive = 0;
  for (int i = 0; i < 101; ++i) {
    alive += years[i];
    if (alive > max_alive) {
      max_alive = alive;
      max_alive_year = i + 1900;
    }
  }
  return max_alive_year;
}

int main() {
  vector<pair<int, int>> people{{1900, 1940}, {1900, 1942},
                                {1998, 2000}, {1932, 2000},
                                {1968, 1999}, {1922, 1949},
                                {1954, 1989}, {1912, 1946},
                                {1907, 1960}, {1911, 1959},
                                {1904, 1926}, {1944, 1978}};
  cout << LivingPeople(people) << endl;
  return 0;
}
