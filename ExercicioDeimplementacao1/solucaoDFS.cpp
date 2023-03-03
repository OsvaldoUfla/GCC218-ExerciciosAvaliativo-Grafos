#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#define NAO_VISITADO 0
#define VISITADO 1

/*
 * Parametros:
 *  u -> vertice a ser explorado
 *  lista_adj -> lista de adjacencia, que modela o grafo
 */
void visita(int u, vector<int>* lista_adj, int* d, int& cont_dfs)
{
    d[u] = VISITADO;
 
    for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
    {
        int v = *it;
        if(d[v] == NAO_VISITADO)
        {
            visita(v, lista_adj, d, cont_dfs);
        }
    }
}


int main()
{  

  int n, m, k, cont_dfs = 0,cont_dfs1 = 999999999;
  cin >> k;

  for(int i =0 ; i < k ; i++)
  {
    cin >> n >> m;

    // alocando as estruturas auxiliares
    int* d = new int[n+1];
   
    // iniciando as estruturas auxiliares
    for(int i = 1; i <= n; i++)
    {
        d[i] = NAO_VISITADO;
    }
   
    vector<int>* lista_adj = new vector<int>[n+1];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // evitando a leitura de vertices repetidos nas listas
      if(find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
      {
        continue;
      }

      // grafo orientado
      lista_adj[u].push_back(v); //u -> v
    }
  
    for(int j = n ; j > 0 ; j--)
    {
      visita(j,  lista_adj, d, cont_dfs);
      cont_dfs++;
      for(int i = 1 ; i<=n ; i++)
      {
        if(d[i] == NAO_VISITADO)
        {
            visita(i,  lista_adj, d, cont_dfs);
            cont_dfs++;
        }
      }

      if(cont_dfs < cont_dfs1)
      {
        cont_dfs1 = cont_dfs;
      }

      //cout << endl << cont_dfs;

      cont_dfs = 0;
      for(int i = 1; i <= n; i++)
      {
        d[i] = NAO_VISITADO;
      }
    }

    cout <<cont_dfs1 << endl;

    delete[] d;
   
  }

return 0;
}
