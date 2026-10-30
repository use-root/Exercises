#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
int getKnowingProblems(int *problems, int n) {
  int count_knowing_problems = 0;
  for (int i = 0; i < n; i++) {
    if (problems[i] >= 2) {
      count_knowing_problems++;
    }
  }
  return count_knowing_problems;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, num;
  int total = 0;
  std::string p;
  std::cin >> n;
  int problems[n];

  std::cin.ignore();

  for (int i = 0; i < n; i++) {
    getline(std::cin, p);
    std::stringstream ss(p);
    while (ss >> num) {
      total += num;
    }
    problems[i] = total;
    total = 0;
  }

  int result = getKnowingProblems(problems, n);
  std::cout << result << "\n";
  return 0;
}
