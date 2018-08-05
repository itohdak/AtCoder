#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)
#include <queue>

using namespace std;
#define ll long long

int main(){
  int N;
  cin >> N;
  vector<ll> A(3*N);
  for(int i=0; i<3*N; i++)
    cin >> A[i];

  vector<ll> Memoa(N+1, 0), Memob(N+1, 0);
  priority_queue<ll, vector<ll>, std::greater<ll> > Qa;
  priority_queue<ll, vector<ll>, std::less<ll> > Qb;
  for(int i=0; i<N; i++){
    Qa.push(A[i]);
    Qb.push(A[i+2*N]);
  }
  Memoa[0] = accumulate(A.begin(), A.begin()+N, 0LL);
  for(int i=0; i<N; i++){
    ll tmp = A[i+N];
    Memoa[i+1] = Memoa[i];
    if(tmp > Qa.top()){
      Memoa[i+1] += - Qa.top() + tmp;
      Qa.pop();
      Qa.push(tmp);
    }
  }
  Memob[0] = accumulate(A.begin()+2*N, A.end(), 0LL);
  for(int i=0; i<N; i++){
    ll tmp = A[2*N-1-i];
    Memob[i+1] = Memob[i];
    if(tmp < Qb.top()){
      Memob[i+1] += - Qb.top() + tmp;
      Qb.pop();
      Qb.push(tmp);
    }
  }
  ll max = Memoa[0] - Memob[N];
  for(int i=0; i<N+1; i++){
    if(max < Memoa[i] - Memob[N-i])
      max = Memoa[i] - Memob[N-i];
  }
  cout << max << endl;
  return 0;
}

