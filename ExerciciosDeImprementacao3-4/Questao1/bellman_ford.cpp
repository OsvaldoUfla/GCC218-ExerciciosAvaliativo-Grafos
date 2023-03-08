#include<iostream>
#include<vector>
#include<utility>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

/*
 * Variaveis globais
 */

// lista de adjacencia
vii* LA;

// valor da variavel x, originalmente relacionada a melhor estimativa de distancia do vertice em relacao a origem
vi x;

// numero de vertices
int n;

// numero de arestas
int m;

void bellman_ford(int org)
{
  x.assign(n, INF);
  x[org] = 0;
  
  // variaveis auxiliares
  int v, peso;
  ii vizinho;
 
  for(int i = 0; i < n - 1; i++)
  {
      for(int u = 0; u < n; u++)
      {
        for(int j = 0; j < (int)LA[u].size(); j++)
        {
            ii vizinho = LA[u][j];
            v = vizinho.first;
            peso = vizinho.second;
            x[v] = min(x[v], x[u] + peso);
        }
      }
  }
}

int main()
{
    cin >> n >> m;
    LA = new vii[n];
 
    int u, v, p;
    for(int j = 0; j < m; j++)
    {
        cin >> u >> v >> p;
        LA[u].push_back(ii(v, p));
    }

    bellman_ford(0);
    for(int i = 0; i < n; i++)
      cout << "x[" << i << "]: " << x[i] << endl;
 
    return 0;
}

