#include <iostream>
int main() {

  int n;
  int amount;
  std::cin >> n >> amount;
  int coins[n];
  int rest = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> coins[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    if (amount >= coins[i]) {
      int cnt = (amount / coins[i]);
      rest += cnt;
      amount -= (cnt * coins[i]);
    }

    if (amount == 0) {
      break;
    }
  }

  std::cout << rest << std::endl;

  return 0;
}
