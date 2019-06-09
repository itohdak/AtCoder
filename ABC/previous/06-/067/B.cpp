#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define ll long long

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> L;
  for(int i=0; i<N; i++){
    int l;
    cin >> l;
    L.push_back(l);
  }
  sort(L.begin(), L.end(), greater<int>());
  int ret = 0;
  for(int i=0; i<K; i++)
    ret += L[i];
  cout << ret << endl;
  return 0;
}

