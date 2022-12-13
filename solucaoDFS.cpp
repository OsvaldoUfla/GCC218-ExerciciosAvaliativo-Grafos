#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

#define NAO_VISITADO 0
#define VISITADO 1

// Raiz da DFS
int raiz;

// Armazena a informacao se um vertice eh de articulacao
bool* articulacoes;

/*
 * Parametros:
 *  u -> vertice a ser explorado
 *  lista_adj -> lista de adjacencia, que modela o grafo
 *  low -> vetor com os menores tempos de descoberta de arestas que abracam um vertice
 *  d -> vetor dos tempos de descoberta pre-ordem de todos os vertices
 *  pai -> vetor com os pais de todos os vertices
 *  cont_dfs -> contador do tempo de descoberta em profundidade dos vertices
 *  filhos_raiz -> conta quantos filhos a raiz possui na DFS
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
  int n, m, k;
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

    int cont_dfs = 0;

    for(int i = 1; i <= n; i++)
    {
        if(d[i] == NAO_VISITADO)
        {
            visita(i,  lista_adj, d, cont_dfs);
            cont_dfs++;
        }
    }

    cout <<cont_dfs << endl;
   
   
    delete[] d;
   
  }

return 0;
}
