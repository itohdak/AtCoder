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
  cin >> N;
  vector< vector<int> > next(N);
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    next[a-1].push_back(b-1);
    next[b-1].push_back(a-1);
  }

  vector<bool> FS(N, false);
  vector<int> F, S;
  F.push_back(0);
  S.push_back(N-1);
  FS[0] = true;
  FS[N-1] = true;
  int f = 0;
  int s = 0;
  int n = 2;
  int nf = 1;
  int ns = 1;
  while(n < N){
    int fend = F.size();
    for(int i=f; i<fend; i++)
      for(int j=0; j<next[F[i]].size(); j++)
	if(!FS[next[F[i]][j]]){
	  F.push_back(next[F[i]][j]);
	  FS[next[F[i]][j]] = true;
	  nf++;
	  n++;
	}
    f = fend;
    int send = S.size();
    for(int i=s; i<send; i++)
      for(int j=0; j<next[S[i]].size(); j++)
	if(!FS[next[S[i]][j]]){
	  S.push_back(next[S[i]][j]);
	  FS[next[S[i]][j]] = true;
	  ns++;
	  n++;
	}
    s = send;
  }
  if(nf > ns)
    cout << "Fennec" << endl;
  else
    cout << "Snuke" << endl;

  return 0;
}
