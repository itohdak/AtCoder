#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  vector<int> next;
  bool checked;
};

int main(){
  int N;
  cin >> N;
  data D[N];
  for(int i=0; i<N; i++){
    vector<int> next;
    data init = {next, false};
    D[i] = init;
  }
  for(int i=0; i<N; i++){
    int in;
    cin >> in;
    in--;
    D[i].next.push_back(in);
  }
  int checked = 0;
  int ret = 0;
  while(checked < N){
    int tmp = 0;
    while(D[tmp].checked) tmp++;
    int group_n = 1;
    int tmp_n = tmp;
    D[tmp_n].checked = true;
    checked++;
    int next_n = D[tmp_n].next[0];
    int last_n;
    while(!D[next_n].checked){
      D[next_n].checked = true;
      checked++;
      group_n++;
      last_n = tmp_n;
      tmp_n = next_n;
      if(D[tmp_n].next[0] == last_n){
	next_n = D[tmp_n].next[1];
      } else {
	next_n = D[tmp_n].next[0];
      }
    }
    if(group_n % 2 == 0){
      ret += group_n / 2;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ret << endl;
  return 0;
}

