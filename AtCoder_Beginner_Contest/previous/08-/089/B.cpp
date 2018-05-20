#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  bool ret = false;
  for(int i=0; i<N; i++){
    char in;
    cin >> in;
    if(in == 'Y'){
      ret = true;
      break;
    }
  }
  if(ret)
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
  return 0;
}

