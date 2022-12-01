# GCC218-ExercicioAvaliativo1
Exercício avaliativo 1 da disciplina de algoritmos em grafos  
[Colab](https://colab.research.google.com/drive/1wX8_ocjYJPp1JdtSQ74cvEfA8arYbnyn#scrollTo=JCmOy9gUrCVJ)  

Lógica para resolução do exercício  
  
Utiliza-se vetores para indicar se a lâmpada está acesa e o grau de cada vértice e uma lista de adjacência para armazenar o grafo,  
enquanto é armazenado o grafo na lista de adjacência também é armazenado o valor do grau de cada vertice   
Empilha em uma fila  de prioridade todos os vertices como vertice(chave) e o grau do vértice(valor)  
Se no topo da fila de prioridade tem uma lâmpada acesa, muda a lâmpada para apagada conta mais um iterruptor acionado e desempilha  
Apaga as lâmpadas vizinhas e diminue o grau das lâmpadas adjacentes 
Repete até a fila ficar vazia e depois exibe quantos interuptores foram acionados