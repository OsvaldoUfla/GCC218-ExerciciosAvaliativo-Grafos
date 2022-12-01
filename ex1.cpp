#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{  
  int n, m, k;
  cin >> k >> n >> m;
  bool lampadaAcesa[n + 1]; //indica se a lâmpada está acesa  
  int interruptor = 0;  //indica quantos interruptores foram acionados
  
  //Todas lâmpadas acesas
  for(int i =1 ; i < n + 1; i++)
  {
      lampadaAcesa[i] = true;
  }


  for(int j = 0 ; j < k ; j++)
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
        //Se a lâmpada está acesa
      if(lampadaAcesa[PQ.top().first])
      {
        int x = PQ.top().second;
        PQ.pop();   //Desempilha o vertice de maior grau e mais vizinhos 
        interruptor++;  //aperta um interruptor  
        lampadaAcesa[x] = false;    //Apaga a lâmpada
        
        for(auto it = lista_adj[x].begin(); it != lista_adj[x].end(); it++)
        {
          lampadaAcesa[*it] = false;     //apaga todas as lâmpadas vizinhas 
          int y = *it;
          for(auto it2 = lista_adj[y].begin(); it2 != lista_adj[y].end(); it2++)
          {
            grau[*it2]--;   //Diminiu o grau dos vizinhos da lampada vizinha apagada
          }
        }
      }
      else
        PQ.pop();   //Se lâmpada está apagada retira da fila de prioridade
    }

    cout << endl << interruptor ;
  }

  return 0;
}