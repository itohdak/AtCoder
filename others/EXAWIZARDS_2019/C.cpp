#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

bool execute(int n, int N, int Q, string S, vector<char>& T, vector<char>& D, char type) {
  int tmp = n;
  for(int i=0; i<Q; i++) {
    if(S[tmp] == T[i]) {
      if(D[i] == 'L')
	tmp--;
      else
	tmp++;
    }
  }
  // cout << tmp << ' ';
  return (type == 'L' && tmp >= 1) || (type == 'R' && tmp <= N);
}

int main(){
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  S = ' ' + S + ' ';
  vector<char> T(Q), D(Q);
  for(int i=0; i<Q; i++)
    cin >> T[i] >> D[i];

  // for(int i=0; i<N; i++)
  //   cout << execute(i+1, N, Q, S, T, D, 'R') << endl;

  int left, right;
  {
    int l = 0, r = N+1;
    while(l < r) {
      int mid = (l + r) / 2;
      if(execute(mid, N, Q, S, T, D, 'L'))
  	r = mid;
      else
  	l = mid + 1;
    }
    left = l;
  }
  {
    int l = 0, r = N+1;
    while(l < r) {
      int mid = (l + r) / 2;
      if(execute(mid, N, Q, S, T, D, 'R'))
  	l = mid + 1;
      else
  	r = mid;
    }
    right = l;
  }
  // cout << right << ' ' << left << endl;
  cout << right - left << endl;
  return 0;
}

