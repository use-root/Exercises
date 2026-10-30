#include <iostream>

int min(int a, int b) { return (a > b) ? b : a; }

int main() {
  int t, a, b;
  std::cin >> t;

  for (int i = 0; i < t; i++) {
    std::cin >> a >> b;
    if (b >= a) {
      std::cout << "-1" << std::endl;
    } else {
      std::cout << min(b, a - b) << std::endl;
    }
  }

  return 0;
}
