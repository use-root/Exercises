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
  int n;
  std::cin >> n;
  std::string problem;
  int problems[n];
  std::cin.ignore();
  int total = 0;
  int num;
  for (int i = 0; i < n; i++) {
    getline(std::cin, problem);
    std::stringstream ss(problem);
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
