#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool isYear(int n) {
  return true;
}
bool isMonth(int n) {
  return n >= 1 && n <= 12;
}
int main() {
  string S;
  cin >> S;
  int first = atoi(S.substr(0, 2).c_str());
  int second = atoi(S.substr(2, 2).c_str());
  if(isYear(first) && isMonth(second) && isMonth(first) && isYear(second))
    cout << "AMBIGUOUS" << endl;
  else if(isYear(first) && isMonth(second))
    cout << "YYMM" << endl;
  else if(isMonth(first) && isYear(second))
    cout << "MMYY" << endl;
  else
    cout << "NA" << endl;
  return 0;
}

