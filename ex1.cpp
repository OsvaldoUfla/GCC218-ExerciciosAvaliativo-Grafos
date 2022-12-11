
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

//vertices representam Lâmpadas acesas ou apagadas
#define acesa 0 // Lâmpada acesa
#define apagada 1 // Lâmpada apagada

/*Retorna o indice do maior elemento de um vetor
*parametro : referencia do vetor
*retorno : int (indice da localização do maior elemento se não existe maior que zero retorna zero)
*/
int retornaMaior(int vetor[], int tam)
{
  int n = 0;
  int maior = 0;

  for (int i =0 ; i < tam ; i++)
  {
      if(vetor[i] > maior)
      {
        maior = vetor[i];
        n = i;
      }
  }
  
  return n;
}

int main()
{  
  int n, m;
  cin >> n >> m;

  while(!cin.eof())
  {
    // alocando as estruturas auxiliares
    int* grau = new int[n+1]; // grau de cada vertice
    int* lampada = new int[n+1]; // armazena se a lâmpada eatá acesa ou não
    
    // iniciando as estruturas auxiliares
    for(int i = 1; i <= n; i++)
    {
        grau[i] = 0;
        lampada[i] = acesa;
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

      // grafo nao-orientado
      lista_adj[u].push_back(v); //u -> v
      lista_adj[v].push_back(u); //v -> u
      grau[u]++;
      grau[v]++;
    }

    int s = retornaMaior(grau, n+1); // vertice origem
    queue<int> fila; // fila de vertices a serem explorados na BFS
    
    lampada[s] = apagada;
    grau[s] = 0;
    for(auto it = lista_adj[s].begin(); it != lista_adj[s].end(); it++)
    {
        fila.push(*it);
    }
   
    //para cada interruptor acionado apaga o lampada e suas vizinhas
    while(!fila.empty())
    {
      int u = fila.front();
      fila.pop();
      lampada[u] = apagada;
      grau[u] = 0;

      for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
      { 
          grau[*it]--;
      }
    }
   
   
    delete[] grau;
    delete[] lampada;
  }

return 0;
}