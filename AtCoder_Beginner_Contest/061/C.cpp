#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  int d;
  int n;
};
bool comp(data d1, data d2){
  return d1.d < d2.d;
}

int main(){
  int N;
  ll K;
  cin >> N >> K;
  vector<data> D;
  for(int i=0; i<N; i++){
    int a, b;
    cin >> a >> b;
    data d = {a, b};
    D.push_back(d);
  }
  sort(D.begin(), D.end(), comp);
  // for(int i=0; i<N; i++)
  //   cout << D[i].d << ' ' << D[i].n << endl;
  int i = 0;
  K--;
  while(K >= 0){
    if(D[i].n > K){
      cout << D[i].d << endl;
      break;
    } else {
      K -= D[i].n;
      i++;
    }
  }
  return 0;
}

