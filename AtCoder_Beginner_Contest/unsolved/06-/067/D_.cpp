#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <deque>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct Node{
  vector<Node> next;
  int color;
  Node(){
    color = -1;
  }
};

int main(){
  int N;
  cin >> N;
  vector<Node> nodes;
  for(int i=0; i<N; i++){
    struct Node node;
    nodes.push_back(node);
  }
  for(int i=0; i<N-1; i++){
    int a, b;
    cin >> a >> b;
    a--; b--;
    nodes[a].next.push_back(nodes[b]);
    nodes[b].next.push_back(nodes[a]);
  }

  int colored = 0;
  deque<Node> F, S;
  F.push_back(nodes[0]);
  S.push_back(nodes[N-1]);
  while(colored < N){
    int F_size = F.size();
    for(int i=0; i<F_size; i++){
      if(F[i].color == -1){
	F[i].color = 0;
	colored++;
	for(vector<Node>::iterator it=F[i].next.begin(); it!=F[i].next.end(); it++){
	  F.push_back(*it);
	}
      }
    }
    for(int i=0; i<F_size; i++){
      F.pop_front();
    }
    int S_size = S.size();
    for(int i=0; i<S_size; i++){
      if(S[i].color == -1){
	S[i].color = 1;
	colored++;
	for(vector<Node>::iterator it=S[i].next.begin(); it!=S[i].next.end(); it++){
	  S.push_back(*it);
	}
      }
    }
    for(int i=0; i<S_size; i++){
      S.pop_front();
    }
  }
  int F_n = 0, S_n = 0;
  vector<int> F_v, S_v;
  for(int i=0; i<N; i++){
    cout << nodes[i].color << endl;
    if(nodes[i].color == 0){
      F_n++;
      F_v.push_back(i+1);
    } else {
      S_n++;
      S_v.push_back(i+1);
    }
  }
  for(int i=0; i<F_v.size(); i++)
    cout << F_v[i] << " ";
  cout << endl;
  for(int i=0; i<S_v.size(); i++)
    cout << S_v[i] << " ";
  cout << endl;
  if(F_n >= S_n)
    cout << "Fennec" << endl;
  else
    cout << "Snuke" << endl;
  return 0;
}

