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
  ll C;
  cin >> N >> C;
  vector<ll> X(N+2, 0), V(N+2, 0);
  for(int i=1; i<N+1; i++)
    cin >> X[i] >> V[i];

  // 累積和
  vector<ll> suml(N+2, 0), sumr(N+2, 0);
  suml[0] = 0;
  for(int i=1; i<N+1; i++)
    suml[i] = suml[i-1] + V[i];
  sumr[N+1] = 0;
  for(int i=N; i>0; i--)
    sumr[i] = sumr[i+1] + V[i];

  // f(a) := v0 + v1 + ... + va - xa
  vector<ll> Fl(N+2, 0), Fr(N+2, 0);
  Fl[0] = 0;
  for(int i=1; i<N+1; i++)
    Fl[i] = suml[i] - X[i];
  Fr[N+1] = 0;
  for(int i=N; i>0; i--)
    Fr[i] = sumr[i] - (C - X[i]);

  // g(a) := max(f(0), f(1), ... , f(a))
  vector<ll> Gl(N+2, 0), Gr(N+2, 0);
  vector<ll> Glpos(N+2, 0), Grpos(N+2, 0);
  Gl[0] = 0;
  Glpos[0] = 0;
  for(int i=1; i<N+1; i++)
    if(Gl[i-1] < Fl[i]){
      Gl[i] = Fl[i];
      Glpos[i] = X[i];
    } else {
      Gl[i] = Gl[i-1];
      Glpos[i] = Glpos[i-1];
    }
  Gr[N+1] = 0;
  Grpos[N+1] = 0;
  for(int i=N; i>0; i--)
    if(Gr[i+1] < Fr[i]){
      Gr[i] = Fr[i];
      Grpos[i] = X[i];
    } else {
      Gr[i] = Gr[i+1];
      Grpos[i] = Grpos[i+1];
    }

  ll ans = 0LL;
  ans = max(ans, Gr[1]); // xa = 0
  ans = max(ans, Gl[N]); // xb = 0
  for(int i=1; i<N+1; i++) {
    ll tmpl = (suml[i]-X[i]) + Gr[i+1] - min(X[i], Grpos[i+1]);
    ll tmpr = (sumr[i]-(C-X[i])) + Gl[i-1] - min(C-X[i], Glpos[i-1]);
    ans = max(ans, tmpl);
    ans = max(ans, tmpr);
  }
  cout << ans << endl;
  return 0;
}

