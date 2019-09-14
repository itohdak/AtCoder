#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  string in;
  cin >> in;
  if(in == "abc" ||
     in == "acb" ||
     in == "bac" ||
     in == "bca" ||
     in == "cab" ||
     in == "cba")
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}

