#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data {
  int n;
  int p;
  ll y;
  data(int n, int p, ll y) : n(n), p(p), y(y){}
};

bool compare(data d1, data d2) {
  if(d1.p == d2.p)
    return d1.y < d2.y;
  else
    return d1.p < d2.p;
}

char num2char(int n) {
  char c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  return c[n];
}

string gen_str(int p, ll y) {
  string top(6, '0'), bottom(6, '0');
  for(int i=0; i<6; i++) {
    top[5-i] = num2char(p % 10);
    p /= 10;
  }
  for(int i=0; i<6; i++) {
    bottom[5-i] = num2char(y % 10);
    y /= 10;
  }
  return top + bottom;
}

int main(){
  int N, M;
  cin >> N >> M;
  vector<data> D;
  for(int i=0; i<M; i++) {
    int p; ll y;
    cin >> p >> y;
    D.push_back(data(i, p, y));
  }
  sort(D.begin(), D.end(), compare);
  vector<string> ans(M);
  int j = D[0].p;
  int k = 1;
  for(int i=0; i<M; i++) {
    if(D[i].p == j) {
    } else {
      j = D[i].p;
      k = 1;
    }
    ans[D[i].n] = gen_str(j, k);
    k++;
  }
  for(int i=0; i<M; i++)
    cout << ans[i] << endl;
  return 0;
}

