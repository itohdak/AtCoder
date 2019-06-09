#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

struct data{
  ll cost;
  bool updated;
};

int main(){
  int N, M;
  cin >> N >> M;
  data cost[N][N];
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(i == j){
	cost[i][j].updated = true;
	cost[i][j].cost = 0;
      } else {
	cost[i][j].updated = false;
      }
    }
  }
  for(int i=0; i<M; i++){
    int l, r, d;
    cin >> l >> r >> d;
    cost[l-1][r-1].updated = true;
    cost[l-1][r-1].cost = d;
    cost[r-1][l-1].updated = true;
    cost[r-1][l-1].cost = -d;
  }
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     for(int k=0; k<N; k++){
  // 	if(!cost[i][j].updated){
  // 	  if(cost[i][k].updated && cost[k][j].updated){
  // 	    cost[i][j].cost = cost[i][k].cost + cost[k][j].cost;
  // 	  }
  // 	} else {
  // 	  if(cost[i][k].updated && cost[k][j].updated){
  // 	    // cost[i][j].cost = min(cost[i][k].cost+cost[k][j].cost, cost[i][j].cost);
  // 	    if(cost[i][k].cost + cost[k][j].cost < cost[i][j].cost){
  // 	      cout << "No" << endl;
  // 	      return 0;
  // 	    }
  // 	  }
  // 	}
  //     }
  //   }
  // }
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      for(int k=0; k<N; k++){
	if(!cost[i][j].updated){
	  if(cost[i][k].updated && cost[k][j].updated){
	    cost[i][j].cost = cost[i][k].cost + cost[k][j].cost;
	  }
	} else {
	  if(cost[i][k].updated && cost[k][j].updated){
	    // cost[i][j].cost = min(cost[i][k].cost+cost[k][j].cost, cost[i][j].cost);
	    if(cost[i][k].cost + cost[k][j].cost < cost[i][j].cost){
  	      cout << "No" << endl;
  	      return 0;
	    }
	  }
	}
      }
    }
  }

  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     for(int k=0; k<N; k++){
  // 	if(cost[i][j].updated){
  // 	  if(cost[i][k].updated && cost[k][j].updated){
  // 	    if(cost[i][j].cost != cost[i][k].cost + cost[k][j].cost || cost[i][j].cost > 1000000000){
  // 	      cout << "No" << endl;
  // 	      return 0;
  // 	    }
  // 	  }
  // 	}
  //     }
  //   }
  // }
  cout << "Yes" << endl;
  return 0;
}

