#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{  
  int n, m, k;
  cin >> n >> m >> k;

  while(!cin.eof())
  {
    // considerando que os índices dos vértices começam de 1 e vão até n
    vector<int>* lista_adj = new vector<int>[n+1];
    int* grau = new int[n+1];

    for(int i = 1; i <= n; i++)
      grau[i] = 0; //grau do nó i
    
    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      // evitando a leitura de vertices repetidos nas listas
      if(find(lista_adj[u].begin(), lista_adj[u].end(), v) != lista_adj[u].end())
        continue;
    
      // grafo nao-orientado
      lista_adj[u].push_back(v); //u -> v
      lista_adj[v].push_back(u); //v -> u
      
      grau[u]++;
      grau[v]++;
    }

    // empilha todos os vertices 
    priority_queue<pair<int,int>> PQ;
    for(int i = 1; i <= n; i++)
    {
      PQ.push({grau[i], i});
    }

    while(!PQ.empty())
    {
      if(PQ.top().first > 0 )
      {
        int x = PQ.top().second;
        PQ.pop();
        //Desempilha o vertice de maior grau e tem mais vizinhos 

        for(auto it = lista_adj[x].begin(); it != lista_adj[x].end(); it++)
        {
          //reduz o grau de todos os vizinhos 
          grau[*it]--;
        }
      }
      else
        PQ.pop();
    }

    /*
    // apenas para imprimir corretmente
    bool primeiro = true;
    for(int i = 1; i <= n; i++)
      if(grau[i]>=k)
      {
        if(!primeiro)
            cout <<" ";
        
        cout << i;
        primeiro = false;
      }

    if(primeiro)
        cout << 0;
    
    cout << endl;
    
    cin >> n >> m >> k;
  }
  */

  return 0;
}