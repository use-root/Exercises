#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  std::cin >> n;
  std::cin.ignore();
  std::string bit_v;
  int total = 0;
  for (int i = 0; i < n; i++) {
    getline(std::cin, bit_v);
    if (bit_v.find("+") != std::string::npos) {
      total += 1;
    } else {
      total -= 1;
    }
  }
  std::cout << total << "\n";
  return 0;
}
