// #include <cmath>
// #include <iostream>
// int main() {
//   int t, n, k;
//   int a = 1;
//   int c = 0;
//
//   std::cin >> t;
//   for (int i = 0; i < t; i++) {
//     std::cin >> n >> k;
//     for (int j = n; j > 0; j--) {
//       if (j >= k) {
//         if (j == (n - k)) {
//           c += a;
//           a = 1;
//           k--;
//         } else {
//           a = pow(2, j);
//         }
//       }
//     }
//     std::cout << c << std::endl;
//   }
//
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k;
    cin >> n >> k;
    cout << (1 << (n - k + 1)) + 2 * (k - 1) << '\n';
  }
  return 0;
}
