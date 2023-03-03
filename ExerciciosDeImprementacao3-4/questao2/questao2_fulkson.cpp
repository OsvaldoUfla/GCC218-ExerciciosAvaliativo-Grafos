
/*Exercícios de Implementação 3 e 4
    Questão 2: Empresa energética
  GCC218 - Algoritmos em Grafos
  Professor: Mayron César de O. Moreira.
  Alunos :
    Osvaldo Rodrigues de Faria Junior 201911203 14A
    Robson Ferreira 202120530 14A
  
  Logica da resolução do execício
    Foi usado uma adaptação do algoritmo de busca em largura
    O grafo é armazenado em uma lista de adjacencia
    inicia a busca pelo vertice de maior grau 
    define o vertice de maior grau e seu vizinhos como apagado 
    atualiza o grau dos vertice ainda não apagado 
    reinicia pelo novo vertce de maior grau
    repete até apagar todos os vertices
*/

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

    cin >> n >> m;
        
    while (n != 0 && m != 0){

            MA = new int*[n];
            for(int i = 0; i < n; i++){
                MA[i] = new int[n];
            }

            for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                        MA[j][k] = 0;
                    }
            } 
            int u, v, cap;
            for(int i = 0; i < m; i++){
                cin >> u >> v >> cap;
                u--;
                v--;
                MA[u][v] = cap;
                MA[v][u] = cap;
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