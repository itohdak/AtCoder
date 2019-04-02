#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string S;
  cin >> S;
  int year = atoi(S.substr(0, 4).c_str());
  int month = atoi(S.substr(5, 7).c_str());
  int day = atoi(S.substr(8, 10).c_str());
  if(year < 2019) {
    cout << "Heisei" << endl;
  } else {
    if(month < 5) {
      cout << "Heisei" << endl;
    } else {
      cout << "TBD" << endl;
    }
  }
  return 0;
}

