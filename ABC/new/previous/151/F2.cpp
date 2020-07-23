#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

struct point {
  ld x;
  ld y;
  point(ld x, ld y): x(x), y(y) {}
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
};
ld calc_dist(point p1, point p2) {
  ld dx = p1.x - p2.x;
  ld dy = p1.y - p2.y;
  return sqrt(dx*dx+dy*dy);
}

int N;
vector<point> P;
vector<point> intersection(point p1, point p2, ld r) {
  point mid = (p1+p2)/2.0; // center
  ld dist = calc_dist(p1, p2); // distance
  point diff = point(p1.y-p2.y, -(p1.x-p2.x))/dist; // slope
  vector<point> ret; // intersection
  if(dist > r*2+eps) {
  } else {
    ld h = sqrt(r*r-(dist/2)*(dist/2));
    ret.push_back(mid+diff*h);
    ret.push_back(mid-diff*h);
  }
  return ret;
}

bool testeach(int i, int j, ld k) {
  auto intr = intersection(P[i], P[j], k);
  if(intr.size() != 0) {
    for(auto i: intr) {
      bool ret = true;
      rep(j, N) {
        if(calc_dist(i, P[j]) > k+eps) {
          ret = false;
          break;
        }
      }
      if(!ret) continue;
      return true;
    }
  }
  return false;
}
bool test(ld k) {
  bool ret = false;
  rep(i, N) REP(j, i+1, N) ret |= testeach(i, j, k);
  return ret;
}

ld binary_search() {
  ld ng = 0, ok = 2000;
  rep(i, 50) {
    ld mid = (ok + ng) / 2;
    if(test(mid)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> N;
  P = vector<point>();
  rep(i, N) {
    int x, y;
    cin >> x >> y;
    P.push_back(point(x, y));
  }
  cout << fixed << setprecision(10) << binary_search() << endl;
  return 0;
}
