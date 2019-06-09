#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  int graph[n][n], graph_t[n][n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(i == j)
	graph[i][j] = 1;
      else
	graph[i][j] = 0;
    }
  }

  int a, b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    graph[a-1][b-1] = graph[b-1][a-1] = 1;
  }

  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //     cout << graph[i][j] << ' ';
  //   }
  //   cout << endl;
  // }

  int ret = 0;
  for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
      if(graph[i][j] == 1){
	graph[i][j] = 0;

	// copy graph
	for(int in=0; in<n; in++){
	  for(int jn=0; jn<n; jn++){
	    graph_t[in][jn] = graph[in][jn];
	  }
	}

	for(int kn=0; kn<n; kn++){
	  for(int in=0; in<n; in++){
	    for(int jn=0; jn<n; jn++){
	      if(kn != in && kn != jn && in != jn &&
		 graph_t[in][jn] == 0 &&
		 graph_t[in][kn] == 1 && graph_t[kn][jn] == 1)
		graph_t[in][jn] = 1;
	    }
	  }
	}

	bool flag = false;
	for(int in=0; in<n; in++){
	  for(int jn=0; jn<n; jn++){
	    if(graph_t[in][jn] == 0){
	      flag = true;
	      break;
	    }
	  }
	  if(flag) break;
	}
	if(flag) ret++;

	graph[i][j] = 1;
      }
    }
  }

  cout << ret << endl;

  return 0;
}

