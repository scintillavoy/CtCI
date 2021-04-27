#include <iostream>
#include <random>
#include <utility>
using namespace std;

// Time complexity: O(n)
void Shuffle(vector<int> &deck) {
  random_device rd;
  mt19937 gen(rd());
  for (int i = 0; i < deck.size(); ++i) {
    uniform_int_distribution<int> dis(i, deck.size()-1);
    swap(deck[i], deck[dis(gen)]);
  }
}

int main() {
  vector<int> deck1;
  for (int i = 0; i < 20; ++i) {
    deck1.push_back(i);
  }
  Shuffle(deck1);
  for (const auto &x : deck1) {
    cout << x << ' ';
  }
  cout << endl;
  return 0;
}
