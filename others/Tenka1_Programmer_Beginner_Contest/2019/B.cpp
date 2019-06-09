#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

int main(){
  int N, K;
  string S;
  cin >> N >> S >> K;
  char target = S[K-1];
  for(int i=0; i<N; i++)
    if(S[i] == target)
      cout << S[i];
    else
      cout << '*';
  cout << endl;
  return 0;
}

