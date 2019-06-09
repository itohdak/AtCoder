#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  int a;
  int b;
  data(int a, int b) : a(a), b(b){}
  data() : a(0), b(0){}
};

bool comp(data d1, data d2){
  if(d1.b == d2.b)
    return d1.a <= d2.a;
  else
    return d1.b <= d2.b;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<data> D(M);
  for(int i=0; i<M; i++)
    cin >> D[i].a >> D[i].b;
  sort(D.begin(), D.end(), comp);
  int ans = 0;
  int prev = -1;
  for(int i=0; i<M; i++){
    if(!(D[i].a <= prev)){
      ans++;
      prev = D[i].b - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
