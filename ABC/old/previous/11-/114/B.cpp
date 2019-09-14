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
  int min = 753;
  for(int i=0; i<S.size()-2; i++) {
    int tmp = 100 * (int(S[i])-int('0')) + 10 * (int(S[i+1])-int('0')) + 1 * (int(S[i+2])-int('0'));
    if(abs(tmp - 753) < min) {
      min = abs(tmp - 753);
    }
  }
  cout << min << endl;
  return 0;
}

