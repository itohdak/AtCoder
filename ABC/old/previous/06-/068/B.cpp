#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  cout << pow(2, floor(log2(N))) << endl;
  return 0;
}

