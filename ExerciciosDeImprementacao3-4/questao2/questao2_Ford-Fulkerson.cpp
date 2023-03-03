
/*Exercícios de Implementação 3 e 4
    Questão 2: Empresa energética
  GCC218 - Algoritmos em Grafos
  Professor: Mayron César de O. Moreira.
  Alunos :
    Julia de Carvalho Teixeira 201610018 14A
    Osvaldo Rodrigues de Faria Junior 201911203 14A
    Robson Ferreira 202120530 14A
  
  Logica da resolução do execício
    Utilizando o algoritmo de Ford-Fulkerson para encontrar o fluxo maximo no grafo, e depois utilizando o 
    conceito de corte minimo para encontrar as arestas que saem da componente1 e entram na componente2.
    utilizando a BFS para encontrar as componente1 e as componente2 do grafo, e depois
    imprimindo as arestas que saem da componente1 e entram na componente2.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 10000000

//*******************//
// Variaveis globais //
//*******************//

// Matriz de adjacencia do grafo direcionado
int** MA;

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
vi componente1; // Vetor que armazena uma componente1 depois do execução do algoritmo
vi componente2;// Vetor que armazena uma componente2 depois do execução do algoritmo

// Vetor que armazena a distancia de cada vertice, obtida pela BFS
vi dist;

// Numero de vertices do grafo
int n;

// Numero de arestas do grafo
int m;

/*
* Executa o caminho aumentante a partir do vertice v, e atualiza a matriz de adjacencia
*/
void caminho_aumentante(int v, int capacidade_fluxo){
    if(v == s){
        fluxo = capacidade_fluxo;
        return;
    }
 
    else if (pai[v] != -1){
        caminho_aumentante(pai[v], min(capacidade_fluxo, MA[pai[v]][v]));
        MA[pai[v]][v] -= fluxo;
        MA[v][pai[v]] += fluxo;
    }
}

/*
* Executa a busca em largura no grafo, e armazena o pai de cada vertice e a distancia de cada vertice
* se o parametro armazenaComponente for true, armazena os vertices da componente1
*/
void bfs(bool armazenaComponente){
    pai.assign(n, -1);
    dist.assign(n, INF);
    dist[s] = 0;
    queue<int> fila;
    fila.push(s);
 
    while(!fila.empty()){
        int u = fila.front();
        if(armazenaComponente){
            componente1.push_back(u);
        }
        fila.pop();
        if(u == t)
          break;
     
        for(int v = 0; v < n; v++){
            if(MA[u][v] && dist[v] == INF){
                dist[v] = dist[u] + 1;
                fila.push(v);
                pai[v] = u;
            }
        }
    }
}

int main(){

    // Leitura do numero de vertices e arestas
    cin >> n >> m;
        
    while (n != 0 && m != 0){

            // Aloca a matriz de adjacencia
            MA = new int*[n];
            for(int i = 0; i < n; i++){
                MA[i] = new int[n];
            }

            // Inicializa a matriz de adjacencia com 0
            for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        MA[j][k] = 0;
                    }
            } 
            int u, v, cap;// Vertice de origem, vertice de destino, capacidade da aresta
            // Leitura das arestas
            for(int i = 0; i < m; i++){
                cin >> u >> v >> cap;
                u--;// Decrementa 1 para que o vertice 1 seja representado pelo indice 0
                v--;
                MA[u][v] = cap;// Adiciona a capacidade da aresta
                MA[v][u] = cap;// Grafo nao direcionado por isso a aresta u->v tem a mesma capacidade que v->u
            }


                fluxo_max = 0;
            
                // Origem sempre o 0
                s = 0;
            
                // Destino sempre o n-1
                t = 1; //n-1;
            
                while(true){
                    fluxo = 0;
                    bfs(false);
                    caminho_aumentante(t, INF);
                    if(!fluxo)
                        break;
                    fluxo_max += fluxo;
                }

                /* Caso queira imprimir o fluxo maximo descomente a linha abaixo
                cout << "Fluxo Máximo = " << fluxo_max << endl; */

                bfs(true);
                
                for(int i = 0; i < n; i++){
                    if((find(componente1.begin(), componente1.end(), i)) == componente1.end()){
                        componente2.push_back(i);
                    }
                }

                /* for(int x : componente2){
                    for(int y : componente1){
                        if(MA[x][y] > 0){
                            cout << y+1 << " " << x+1 << endl;
                        }
                    }
                }
                cout << endl; */

                 for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(MA[j][i] > 0){
                            if((find(componente1.begin(), componente1.end(), i)) != componente1.end()   // Se i pertence a componenteq
                             && (find(componente2.begin(), componente2.end(), j)) != componente2.end()){    // Se j pertence a componente2
                                cout << i+1 << " " << j+1 << endl;
                            }
                        }
                    }
                }
                cout << endl;

                for(int i = 0; i < n; i++){
                    // desaloca a as colunas da matriz
                    delete[] MA[i];
                }
                delete[] MA;// desaloca a matriz linha
                componente1.clear();// limpa o vetor componente1
                componente2.clear();// limpa o vetor componente2

                cin >> n >> m;
        }
    return 0;
}