#include<iostream>
#include <fstream>
#include<vector>
#include <queue>
#include<utility>
#include<functional>
using namespace std;

#define INF 10000000

//*******************//
// Variaveis globais //
//*******************//

// Matriz de adjacencia do grafo direcionado
int** MA;
int** MA1;

// Valor do fluxo maximo acumulado
int fluxo_max;

// Valor do fluxo maximo na iteracao atual
int fluxo;

// Origem
int s;

// Destino
int t;

// Vetor que armazena o pai de cada vertice pela BFS
typedef vector<int> vi;
vi pai;

// Vetor que armazena a distancia de cada vertice, obtida pela BFS
vi dist;

// Numero de vertices do grafo
int n;

// Numero de arestas do grafo
int m;

void caminho_aumentante(int v, int capacidade_fluxo)
{
    if(v == s)
    {
        fluxo = capacidade_fluxo;
        return;
    }
 
    else if (pai[v] != -1)
    {
        caminho_aumentante(pai[v], min(capacidade_fluxo, MA[pai[v]][v]));
        MA[pai[v]][v] -= fluxo;
        MA[v][pai[v]] += fluxo;
        if(MA[pai[v]][v] == 0)
            cout << pai[v] << " " << v << " " << fluxo  << endl;        
    }
}

void bfs()
{
    pai.assign(n, -1);
    dist.assign(n, INF);
    dist[s] = 0;
    queue<int> fila;
    fila.push(s);
 
    while(!fila.empty())
    {
        int u = fila.front();
        fila.pop();
        if(u == t)
          break;
     
        for(int v = 0; v < n; v++)
        {
            if(MA[u][v] && dist[v] == INF)
            {
                dist[v] = dist[u] + 1;
                fila.push(v);
                pai[v] = u;
            }
        }
    }
}

int main()
{
ifstream arquivo("in2.txt");
    if(arquivo){
        arquivo >> n >> m;
    
        MA = new int*[n];
        for(int i = 0; i < n; i++)
            MA[i] = new int[n];

        for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    MA[j][k] = 0;
                }
        } 
        int u, v, cap;
        for(int i = 0; i < m; i++){
            arquivo >> u >> v >> cap;
            u--;
            v--;
            MA[u][v] = cap;
            MA[v][u] = cap;
        }


            fluxo_max = 0;
        
            // Origem sempre o 0
            s = 1;
        
            // Destino sempre o n-1
            t = 0; //n-1;
        
            while(true)
            {
                fluxo = 0;
                bfs();
                caminho_aumentante(t, INF);
                if(!fluxo)
                    break;
                fluxo_max += fluxo;
            }
        
            cout << "Fluxo Máximo = " << fluxo_max << endl<< endl<< endl;

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    cout << MA[i][j] <<" ";
                }
                cout << endl;
            }
        }
    return 0;
}