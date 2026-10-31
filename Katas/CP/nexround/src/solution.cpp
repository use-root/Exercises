#include <iostream>
#include <sstream>
#include <string>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, k;
  std::cin >> n >> k;
  int scores[n];

  for (int i = 0; i < n; i++) {
    std::cin >> scores[i];
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    if (scores[i] == 0)
      break;
    else {
      if (scores[i] > 0 && i + 1 <= k) {
        count++;
      } else {
        if (scores[i] == scores[k - 1]) {
          count++;
        } else {
          break;
        }
      }
    }
  }
  std::cout << count << std::endl;

  return 0;
}
