#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for(int i=0; i<H; i++)
    cin >> A[i];
  cout << string(W+2, '#') << endl;
  for(int i=0; i<H; i++)
    cout << '#' << A[i] << '#' << endl;
  cout << string(W+2, '#') << endl;
  return 0;
}

