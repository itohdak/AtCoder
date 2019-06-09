#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool compX(pair<int, ll> p1, pair<int, ll> p2) {
  return p1.second < p2.second;
}
bool compI(pair<int, ll> p1, pair<int, ll> p2) {
  return p1.first < p2.first;
}

int main(){
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> S(A+2, 0), T(B+2, 0);
  S[0] = -1e10;  S[A+1] = 2e+10;
  T[0] = -1e10;  T[B+1] = 2e+10;
  for(int i=0; i<A; i++)
    cin >> S[i+1];
  for(int i=0; i<B; i++)
    cin >> T[i+1];
  vector<pair<int, ll> > X;
  for(int i=0; i<Q; i++) {
    ll x;
    cin >> x;
    X.push_back(pair<int, ll>(i, x));
  }
  sort(X.begin(), X.end(), compX);
  vector<pair<int, ll> > Ans;
  int tmpA = 0, tmpB = 0;
  for(int i=0; i<X.size(); i++) {
    ll x = X[i].second;
    while(S[tmpA] <= x) tmpA++;
    while(T[tmpB] <= x) tmpB++;
    ll al = S[tmpA-1], ar = S[tmpA];
    ll bl = T[tmpB-1], br = T[tmpB];
    // cout << max(ar, br)-x << ' ' << x-min(al, bl) << ' '
    // 	 << (br-al)+min(br-x,x-al) << ' ' << (ar-bl)+min(x-bl,ar-x) << endl;
    ll ans = min(min(max(ar, br)-x, x-min(al, bl)),
		 min((br-al)+min(br-x,x-al), (ar-bl)+min(x-bl,ar-x)));
    Ans.push_back(pair<int, ll>(X[i].first, ans));
  }
  sort(Ans.begin(), Ans.end(), compI);
  for(int i=0; i<Ans.size(); i++)
    cout << Ans[i].second << endl;
  return 0;
}

