#include <bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> v;
bool test(ll k, ll t) {
  return v[k] <= t; // modify here
}

ll binary_search(ll n, ll t) {
  ll ng = n, ok = 0; // 初期値注意; ngは条件を満たす可能性のある数より1大きく(or小さく)
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(test(mid, t)) ok = mid;
    else ng = mid;
  }
  return ok;
}

ll binary_search_old(ll n, ll t) {
  ll l = -1, r = n; // 初期値注意
  while(r - l > 1) {
    ll mid = (l + r) / 2;
    if(test(mid, t))
      l = mid;
    else
      r = mid;
  }
  return l;
}

int main() {
  ll a[] = {1,4,7,19,29};
  v = vector<ll>(a, a+5);
  int n = v.size();
  cout << "input: ";
  for(int i=0; i<n; i++)
    cout << v[i] << ' ';
  cout << endl;
  cout << binary_search(n, 1) << endl;
  cout << binary_search_old(n, 1) << endl;
  cout << upper_bound(v.begin(), v.end(), 1) - v.begin() << endl; // upper_boundは条件を満たさない
  cout << lower_bound(v.begin(), v.end(), 1) - v.begin() << endl; // lower_boundは条件を満たす
  return 0;
}
