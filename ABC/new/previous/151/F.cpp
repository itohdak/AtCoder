#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

#define vec point
struct point {
  ld x, y;
  point(ld x, ld y) : x(x), y(y) {}
  point operator+(const point& rhs) const {
    return point(x+rhs.x, y+rhs.y);
  }
  point operator-(const point& rhs) const {
    return point(x-rhs.x, y-rhs.y);
  }
  point operator*(const ld& d) const {
    return point(x*d, y*d);
  }
  point operator/(const ld& d) const {
    assert(d != 0);
    return point(x/d, y/d);
  }
  ld length() {
    return sqrt(x*x+y*y);
  }
  point perpendicular() {
    ld d = this->length();
    assert(d != 0);
    return point(y, -x) / d;
  }
};
point midpoint(point p1, point p2) {
  return (p1+p2)/2;
}
struct circle {
  point center;
  ld r;
  circle(ld cx=0, ld cy=0, ld r=1) : center(point(cx, cy)), r(r) {}
  circle(point center, ld r) : center(center), r(r) {}
};
vector<point> intersection(circle c1, circle c2) { // c1.r == c2.r
  ld r = c1.r;
  point mid = midpoint(c1.center, c2.center);
  vec dir = c2.center - c1.center;
  ld dh = dir.length();
  vec perp = dir.perpendicular();
  ld dv = sqrt(r*r-(dh/2)*(dh/2));
  vector<point> ret;
  if(dh > r*2+eps) { // no intersection
  } else {
    ret.push_back(mid+perp*dv);
    ret.push_back(mid-perp*dv);
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  vector<pair<ld, ld>> P(n);
  rep(i, n) cin >> P[i].first >> P[i].second;
  auto test = [&](ld r) {
    vector<circle> C(n);
    rep(i, n) C[i] = circle(P[i].first, P[i].second, r);
    bool ret = false;
    rep(i, n) REP(j, i+1, n) {
      auto inter = intersection(C[i], C[j]);
      if(inter.size() == 0) continue;
      for(auto p: inter) {
        // cerr << p.x << ' ' << p.y << "\n";
        bool ok = true;
        rep(k, n) {
          if((p-C[k].center).length() > r+eps) ok = false;
        }
        if(ok) ret = true;
      }
    }
    return ret;
  };
  auto bsearch = [&]() {
    ld ok = 2000, ng = 0;
    rep(i, 50) {
      ld mid = (ok+ng)/2;
      if(test(mid)) ok = mid;
      else ng = mid;
    }
    return ok;
  };
  cout << bsearch() << "\n";
  return 0;
}
