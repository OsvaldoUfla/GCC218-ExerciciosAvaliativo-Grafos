/*Exercício Avaliativo 1
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
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

void exibe(int vetor[], int tam)
{
  cout << endl;
  for (int i =0 ; i < tam ; i++)
  {
     cout << vetor[i] << endl;
  }
  cout << endl;
}


/*
  Retorna se ainda tem lâmpada acessa
  Parametros : nenhum
  retorno : true se ainda tem lâmpada acessa se não false
*/
bool temAcesa(bool lampada[], int tam)
{
  for (int i =0 ; i < tam ; i++)
  {
      if(lampada[i])
      {
        return true;
      }
  }
  
  return false;
}

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
      if(vetor[i] >= maior)
      {
        maior = vetor[i];
        n = i;
      }
  }
  
  return n;
}

int main()
{  
<<<<<<< HEAD
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
=======
  int x;
  cin >> x;

  for(int j = 0 ; j < x ; j++)
>>>>>>> main
  {
    int n, m, interruptores = 0;
    cin >> n >> m;
    // alocando as estruturas auxiliares
    int* grau = new int[n]; // grau de cada vertice
    bool* lampada = new bool[n]; // armazena se a lâmpada eatá acesa ou não
    
    // iniciando as estruturas auxiliares
    for(int i = 0; i < n; i++)
    {
        grau[i] = 0;
        lampada[i] = true;
    }
   
    vector<int>* lista_adj = new vector<int>[n+1];

    // leitura do grafo
    int u, v;
    for(int i = 0; i < m; i++)
    {
      cin >> u >> v; // lendo as arestas do grafo

      v--;//formata o grafo para usar o indice zero
      u--;

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

    while (temAcesa(lampada, n))
    {
<<<<<<< HEAD
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
=======
      interruptores++;
      int s = retornaMaior(grau, n); // vertice origem
      
      queue<int> fila; // fila de vertices a serem explorados na BFS
      
      lampada[s] = false;
      grau[s] = -1;
      for(auto it = lista_adj[s].begin(); it != lista_adj[s].end(); it++)
      {
          fila.push(*it);
      }
    
      //para cada interruptor acionado apaga o lampada e suas vizinhas
      while(!fila.empty())
      {
        int u = fila.front();
        fila.pop();
        lampada[u] = false;
        grau[u] = -1;

        for(auto it = lista_adj[u].begin(); it != lista_adj[u].end(); it++)
        {
          if(grau[*it] > 0)
          {
            grau[*it]--;
          }
        }
      }
    }

    cout << interruptores <<endl;
   
    delete[] grau;
    delete[] lampada;
    
>>>>>>> main
  }

return 0;
}