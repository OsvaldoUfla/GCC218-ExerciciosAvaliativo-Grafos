/*Exercícios de Implementação 3 e 4
    Questão 1: Abastecendo o tanque
  GCC218 - Algoritmos em Grafos
  Professor: Mayron César de O. Moreira.
  Alunos :
    Julia de Carvalho Teixeira 201610018 14A
    Osvaldo Rodrigues de Faria Junior 201911203 14A
    Robson Ferreira 202120530 14A

*/


#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> ii;

int n = 3; // numero de cidades
int origem = 0;
int capacidade = 10; // capacidade do tanque
vector<pair<int, int>> adj[3]; // lista de adjacência do grafo
vector<int> gasto; // vetor de gasto com combustivel ate a cidade
vector<int> combustivelSobrando; // vetor de quantidade de combustivel sobrando para abastecer nas cidade anteriores
vector<int> tanque; // vetor de combustivel no tanque
vector<int> preco; // vetor de preco do combustivel
vector<int> pai; // vetor de pai da cidade ou vertice


int main(){

    
    
    gasto.assign(n, INT_MAX);// inicializa vetor de gasto com infinito
    gasto[origem] = 0;// inicializa vetor de gasto com zero na origem
    combustivelSobrando.assign(n, capacidade);// vetor de quantidade de combustivel abastecido na cidade
    tanque.assign(n, 0);// inicializa vetor de tanque com zero
    pai.assign(n, -1);// inicializa vetor de pai com -1 

    adj[0].push_back(make_pair(1, 9));
    adj[0].push_back(make_pair(2, 8));
    adj[1].push_back(make_pair(2, 1));
    adj[1].push_back(make_pair(3, 11));
    adj[2].push_back(make_pair(3, 7));

    preco.push_back(10);
    preco.push_back(10);
    preco.push_back(20);
    preco.push_back(12);

    capacidade = 10;

    for(int i = 0; i < n - 1; i++){
        for(int u = 0; u < n; u++){
            for(int j = 0; j < (int)adj[u].size(); j++){
                ii vizinho = adj[u][j];

                int v = vizinho.first;
                int peso = vizinho.second;

                //calcularando o custo para sair de u para v
                //Primeiro verifica o se poderia ter comprado combustivel antes mais barato
                int custo2 = 0;

                if(pai[u] != -1 and combustivelSobrando[pai[u]] > 0){
                    if(preco[u] < preco[pai[u]]){
                        custo2 = preco[u] * combustivelSobrando[pai[u]];
                    }
                    
                }

                }
                

            }
        }
    }

    return 0;
}

