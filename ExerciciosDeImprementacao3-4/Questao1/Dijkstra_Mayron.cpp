#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<functional>
#include <climits> //INT_MAX
using namespace std;

/*
 * Variaveis globais
 */

// lista de adjacencia
vector<pair<int, int>>* LA;

// numero de vertices do grafo
int n;

// numeoro de arestas do grafo
int m;

// Capacidade maxima de combustivel
int Q;

// Destino
int t;

// Custo para chegar na cidade
vector<int> custo;

// Custo para abastecer uma unidade de combustivel em cada cidade
int* combustivel;

// Visitados 
vector<bool> visitado;

// distancia da origem "org" a cada vertice do grafo
vector<int> d;

int dijkstra(int org){
    // heap que auxilia na obtencao do vertice com maior prioridade, a cada iteracao
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > heap;

    // inicializa vetor de distancias com infinito
    d.assign(n, INT_MAX);

    // inicializa vetor de visitados com falso
    visitado.assign(n, false);

    // inicializa vetor de custo com zero
    custo.assign(n, 0);

    // a distance da origem "org" eh sempre zero
    d[org] = 0;
    
    // primeiro par inserido na heap: "org" com custo zero
    heap.push(make_pair(0, org));
 
    // o algoritmo para quando a heap estiver vazia
    while(!heap.empty()){
        pair<int, int> vertice = heap.top();
        heap.pop();

        int distancia = vertice.first;
        int u = vertice.second;

        // se u é o destino, retorna o custo
        if(u == t){
            return custo[t];
        }

        // Se u já foi visitado, ignora
        if(visitado[u])
          continue;
     
        visitado[u] = true;

        for(auto adjacente : LA[u]){
            pair<int, int> vizinho = adjacente;
            int v = vizinho.first;
            int prob = vizinho.second;
         
            // tentativa de melhorar a estimativa de menor caminho da origem ao vertice v
            custo = d[u] * prob;
            if(custo < d[v]) { 
                d[v] = custo; 
                heap.push(make_pair(d[v], v)); 
            }
        }
     
        /* for(int j = 0; j < (int) LA[u].size(); j++){
            pair<int, int> vizinho = LA[u][j];
            int v = vizinho.first;
            int prob = vizinho.second;
         
            // tentativa de melhorar a estimativa de menor caminho da origem ao vertice v
            custo = d[u] * prob;
            if(custo < d[v]) { 
                d[v] = custo; 
                heap.push(make_pair(d[v], v)); 
            }
        } */
    }
}

int main(){
    cin >> n >> m;
   
    LA = new vector<pair<int, int>>[n];
    combustivel = new int[n];

    for(int i = 0; i < n; i++){
      cin >> combustivel[i];
    }

    int u, v;
    int p;
    for(int i = 0; i < m; i++){
        cin >> u >> v; 
        cin >> p;
        u--;
        v--;
        LA[u].push_back(make_pair(v, p));
    }

    cin >> Q;
 
    /* for(int i = 0; i < n; i++){
        cout << "vertice " << i << ": ";
        for(int j = 0; j < (int) LA[i].size(); j++){
            cout << "(" << LA[i][j].first << ", " << LA[i][j].second << ") ";
        }
        cout << endl;
    } */

    dijkstra(0);
 
    /* for(int i = 0; i < n; i++)
      cout << "d[" << i + 1 << "]: " << 1.0 - d[i] << endl; */

    return 0;
}

/* Algoritmo de Dijkstra Modificado:

Crie uma lista de prioridade Q
Para cada vértice v em V, defina distância[v] = infinito e visitado[v] = falso
Defina distância[s] = 0 e insira o par (distância[s], s) na lista Q
Enquanto Q não estiver vazia:
a. Retire da lista Q o vértice com menor distância, chamado de u
b. Se u é o vértice destino t, pare o loop e retorne distância[t]
c. Se visitado[u] for falso:
i. Defina visitado[u] = verdadeiro
ii. Para cada vértice adjacente v de u:
1. Se c[u] <= Q e distância[u] + d(u,v) * c[u] < distância[v]:
a. Atualize distância[v] = distância[u] + d(u,v) * c[u]
b. Insira o par (distância[v], v) na lista Q
Se não foi possível chegar ao vértice destino t a partir do vértice origem s, retorne "sem solução"
Pseudo código:

função dijkstraModificado(Grafo G, inteiro s, inteiro t, inteiro Q, vetor c) retorna inteiro ou "sem solução":
Q = criarListaDePrioridade()
para cada vértice v em G:
distância[v] = infinito
visitado[v] = falso
distância[s] = 0
inserir(Q, (distância[s], s))
enquanto Q não estiver vazia:
u = removerMin(Q)
se u = t:
retornar distância[t]
se visitado[u] for falso:
visitado[u] = verdadeiro
para cada vértice adjacente v de u:
se c[u] <= Q e distância[u] + d(u,v) * c[u] < distância[v]:
distância[v] = distância[u] + d(u,v) * c[u]
inserir(Q, (distância[v], v))
retornar "sem solução" */