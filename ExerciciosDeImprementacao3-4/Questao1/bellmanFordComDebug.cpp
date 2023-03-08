
/*Exercícios de Implementação 3 e 4
    Questão 1: Abastecendo o tanque
  GCC218 - Algoritmos em Grafos
  Professor: Mayron César de O. Moreira.
  Alunos :
    Julia de Carvalho Teixeira 201610018 14A
    Osvaldo Rodrigues de Faria Junior 201911203 14A
    Robson Ferreira 202120530 14A

*/

#include<iostream>
#include<vector>
#include<utility>
#include<fstream>
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

void exibeAdjacencias(){
    for(int e = 0 ; e < n; e++){
        for(auto it = LA[e].begin(); it != LA[e].end(); it++){
            ii v = *it;
            cout << e << " -> " << v.first << " : " << v.second << endl;
        }
    }
}

void dfs(int u){
   // visitado[u] = true;
    for(int i = 0; i < (int)LA[u].size(); i++){
        ii vizinho = LA[u][i];
        int v = vizinho.first;
        int peso = vizinho.second;
        distanciaPercorrida += peso;
        if(distanciaPercorrida > peso and distanciaPercorrida <= q){
            LA[origemDaRecursao].push_back(ii(v, distanciaPercorrida));
        }
        if(distanciaPercorrida <= q){
            //if(!visitado[v]){
                dfs(v);
                distanciaPercorrida -= peso;
           // }
        }
        else{
            distanciaPercorrida -= peso;
        }
    }
}

int main(){

    ifstream cin("entradas-saidas/3.in");
    if(!cin){
        cout << "Erro ao abrir o arquivo de entrada" << endl;
        return 0;
    }
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

    //exibeAdjacencias();

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

























/* #include<iostream>
#include<vector>
#include<utility>
#include<fstream>
using namespace std;

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 */
/*
 * Variaveis globais
 */

// Matriz de adjacencia
/* int **matriz; */

// valor da variavel x, originalmente relacionada a melhor estimativa de distancia do vertice em relacao a origem
//vi x;
//pai de cada vertice
//vi pai;
// Preço do combustível em cada cidade
//vi preco;
// Tanque de combustível, Armazena a quantidade decombustível restante que o carro pode ter em cada cidade
//vi tanque;

// capacidade do tanque
//int capacidade = 10;

// numero de vertices
//int n;

// numero de arestas
//int m;

/* void exibe(){
    cout << endl << "V  |  p  |  t  |  d  " << endl;
            for(int k = 0; k < n; k++)
              cout << k << "  |  " << pai[k] << " |  " << tanque[k]  << " |  " << x[k] << endl;
}
void bellman_ford(int org){
  x.assign(n, INF);// inicializa o vetor x com infinito
  pai.assign(n, -1);// inicializa o vetor pai com -1
  tanque.assign(n, 10);// inicializa o vetor tanque com a capacidade do tanque
  tanque[org] = 0;// tanque da origem com 0
  x[org] = 0;// distancia da origem para a origem é 0
  
  // variaveis auxiliares
  int peso;
  ii vizinho;
 
  for(int i = 0; i < n - 1; i++){
      for(int u = 0; u < n; u++){
        for(int v = 0; v < n ; v++){
            if(matriz[u][v]){
                peso = matriz[u][v];
                if(peso < capacidade){
                    cout << endl << "Relaxamento " << u << " -> " << v << endl;
                    cout << "A distancia de " << u << " = " << x[u] << endl;
                    cout << "A distancia de " << v << " = " << x[v] << endl;
                    cout << "O peso(" << u << " -> " << v <<") = "  << peso << endl;

                    exibe();
                    /*Se o tanque combustivel está vazio abastece */
                /*  if(tanque[u] == 0){
                        x[v] = min(x[v], x[u] + (peso * preco[u]));
                        if(x[v] == x[u] + (peso * preco[u])){
                            pai[v] = u;
                        }
                    } */
                    
                    /*Se o preço do combustivel na cidade atual é maior que o preço do combustivel no tanque*/
                    /*
                    if(preco[pai[u]] < preco[u]){
                        /*Combustível restante no tanque não é suficiente para chegar na proxima cidade 
                        então abastece o necessario*/
                        /*
                        if(peso > tanque[pai[u]]){
                            int aux;
                            aux = tanque[pai[u]] * preco[pai[u]];
                            aux += (peso - tanque[pai[u]]) * preco[u];
                            if(aux < x[v]){
                                x[v] = aux;
                                tanque[u] = tanque[u] - peso;
                                pai[v] = u;
                            }
                        }
                        /*Combustível restante no tanque é suficiente para chegar na proxima cidade */
                        /*
                        else{
                            if(x[u] + peso * preco[pai[u]] < x[v]){
                                x[v] = x[u] + peso * preco[pai[u]];
                                tanque[u] = tanque[u] - peso;
                                pai[v] = u;
                            }
                        }
                    }
                
                    /* O preço do combustível na cidade atual é menor ou igual ao restante no tanque */
                    /*
                    if(0){
                        if(x[v] > x[u] + (peso * preco[u])){
                            x[v] = min(x[v], x[u] + (peso * preco[u]));
                            pai[v] = u;
                            tanque[v] = tanque[v] - peso;
                        }
                    }
                    
                    cout << endl << " Se for menor melhora a estimativa" << endl;
                    exibe();
                }
            }
        }
      }
  }
}

int main(){
    ifstream cin("entradas-saidas/1.in");
    if(!cin){
        cout << "Erro ao abrir o arquivo de entrada" << endl;
        return 0;
    }
    cin >> n >> m;
    
    matriz = new int*[n];
    for(int i = 0; i < n; i++)
      matriz[i] = new int[n];

    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        matriz[i][j] = 0;


    preco.assign(n, 0);// inicializa o vetor preco com 0
    for(int i = 0; i < n; i++)
      cin >> preco[i];
    int u, v, p;
    for(int j = 0; j < m; j++){
        cin >> u >> v >> p;
        matriz[u][v] = p;
    }

    bellman_ford(0);
    for(int i = 0; i < n; i++)
      cout << "x[" << i << "]: " << x[i] << endl;
 
    return 0;
}
*/