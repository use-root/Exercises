#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int w;
  cin >> w;
  const string tag = (w > 2 && w % 2 == 0) ? "YES" : "NO";
  cout << tag << std::endl;
  return 0;
}
