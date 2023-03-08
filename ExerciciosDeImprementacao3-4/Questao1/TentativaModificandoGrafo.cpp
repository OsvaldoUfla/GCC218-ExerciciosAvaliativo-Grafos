
/*Exercícios de Implementação 3 e 4
    Questão 1: Abastecendo o tanque
  GCC218 - Algoritmos em Grafos
  Professor: Mayron César de O. Moreira.
  Alunos :
    Julia de Carvalho Teixeira 201610018 14A
    Osvaldo Rodrigues de Faria Junior 201911203 14A
    Robson Ferreira 202120530 14A

    A ideia é criar um grafo modificado, nele é adiciona as arestas 
    que representam os trechos que dá para fazer um um tanque de combustivel
    porque se combustivel estiver mais barato na cidade atual
    não se abastece o carro e continua a viajem.
    Depois de modificar o grafo rodar o bellman ford para achar o menor caminho

*/

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

// Preço do combustível em cada cidade
vi preco;

// distancia percorrida auxiliar para o dfs
int distanciaPercorrida;

//Vertice de origem da busca em profundidade (dfs) recursiva    
int origemDaRecursao;

// Capacidade do tanque
int q;

// vetor de visitados
//bool *visitado;

// valor da variavel x, originalmente relacionada a melhor estimativa de distancia do vertice em relacao a origem
vi x;

// numero de vertices
int n;

// numero de arestas
int m;

// numero de testes
int quant_Testes;

void bellman_ford(int org){
    x.assign(n, INF);
    x[org] = 0;
    
    // variaveis auxiliares
    int v, peso;
    ii vizinho;
 
    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < (int)LA[u].size(); j++){
                ii vizinho = LA[u][j];
                v = vizinho.first;
                peso = vizinho.second;
                if(peso < q)
                    x[v] = min(x[v], x[u] + peso * preco[u]);
            }
        }
    }
}

void dfs(int u){
    for(int i = 0; i < (int)LA[u].size(); i++){
        ii vizinho = LA[u][i];
        int v = vizinho.first;
        int peso = vizinho.second;
        distanciaPercorrida += peso;
        if(distanciaPercorrida > peso and distanciaPercorrida <= q){
            LA[origemDaRecursao].push_back(ii(v, distanciaPercorrida));
        }
        if(distanciaPercorrida <= q){
            dfs(v);
            distanciaPercorrida -= peso;
        }
        else{
            distanciaPercorrida -= peso;
        }
    }
}

int main(){
    cin >> n >> m;
    LA = new vii[n];

    preco.assign(n, 0);

    for(int i = 0; i < n; i++)
        cin >> preco[i];
 
    int u, v, p;
    for(int j = 0; j < m; j++){
        cin >> u >> v >> p;
        LA[u].push_back(ii(v, p));
    }

    cin >> quant_Testes;

    int MatrizCaracteristicas[quant_Testes][3];

    for(int i = 0; i < quant_Testes; i++){
        for(int j = 0; j < 3; j++){
            cin >> MatrizCaracteristicas[i][j];
        }
    }

    q = MatrizCaracteristicas[0][0];

    for(int i = 0; i < n; i++){
        origemDaRecursao = i;
        dfs(i);
        distanciaPercorrida = 0;
    }

    for(int i = 0; i < quant_Testes; i++){
        q = MatrizCaracteristicas[i][0];
        bellman_ford(MatrizCaracteristicas[i][1]);
        if(x[MatrizCaracteristicas[i][2]] == INF)
            cout << "sem solucao" << endl;
        else
            cout << x[MatrizCaracteristicas[i][2]] << endl;
    }
 
    return 0;
}

