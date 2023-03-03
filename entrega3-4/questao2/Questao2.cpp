#include <iostream>
#include <vector>
#include <queue>
#include <utility> 
#include <algorithm>
#include <functional>

using namespace std;

int main(){  
  int n, m, w;
  cin >> n >> m;

  while(!cin.eof()){
   
    vector<pair<int, int>>* lista_adj = new vector<pair<int, int>>[n+1];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++){
      cin >> u >> v >> w; // lendo as arestas do grafo

      // evitando a leitura de vertices repetidos nas listas
      //if(find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end()){
      //  continue;
      //}

      // grafo nao-orientado
      lista_adj[u].push_back(make_pair(v, w)); //u -> v
      lista_adj[v].push_back(make_pair(u, w)); //v -> u
    }

    for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++){
        pair <int, int> p = *it;
        cout << p.first << "  " << p.second << endl;
    }

    
    cin >> n >> m;
  }

  cout << "*****" << endl;

  return 0;
}