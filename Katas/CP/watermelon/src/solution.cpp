#include <iostream>
#include <string>
using namespace std;

int main() {
  int w;
  cin >> w;
  const string tag = (w > 2 && w % 2 == 0) ? "YES" : "NO";
  cout << tag << "\n";
  return 0;
}
