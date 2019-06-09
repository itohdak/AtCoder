#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct lr{
  int l;
  int r;
  int length;
};

bool compare(const lr &lr1, const lr &lr2){
  return lr1.length < lr2.length;
}

int main(){
  int N;
  cin >> N;
  int a[N], b[N];
  for(int i=0; i<N; i++){
    a[i] = 0;
    cin >> b[i];
  }
  int Q;
  cin >> Q;
  vector<lr> LR;
  for(int i=0; i<Q; i++){
    int lin, rin;
    cin >> lin >> rin;
    lr tmp = {lin, rin, rin-lin+1};
    LR.push_back(tmp);
  }
  sort(LR.begin(), LR.end(), compare);
  // for(int i=0; i<LR.size(); i++){
  //   cout << LR[i].l << ' ' << LR[i].r << endl;
  // }
  for(int i=0; i<Q; i++){
    int improve = 0;
    lr tmp = LR[i];
    for(int j=tmp.l-1; j<tmp.r; j++){
      if(a[j] != b[j] && b[j] == 1)
	improve++;
      else if(a[j] != b[j] && b[j] == 0)
	improve--;
      else if(a[j] == b[j] && a[j] == 0)
	improve--;
    }
    if(improve > 0){
      for(int j=tmp.l-1; j<tmp.r; j++){
	a[j] = 1;
      }
    }
  }
  int ret = 0;
  for(int i=0; i<N; i++){
    if(a[i] != b[i])
      ret++;
  }
  // for(int i=0; i<N; i++)
  //   cout << a[i] << ' ';
  // cout << endl;
  // for(int i=0; i<N; i++)
  //   cout << b[i] << ' ';
  // cout << endl;
  cout << ret << endl;
  return 0;
}

