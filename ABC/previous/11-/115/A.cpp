#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int D;
  cin >> D;
  string str = "Christmas";
  for(int i=D; i<25; i++) {
    str += " Eve";
  }
  cout << str << endl;

  return 0;
}

