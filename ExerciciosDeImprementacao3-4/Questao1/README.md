O aumento considerável no preço dos combustíveis faz com que o planejamento de qualquer viagem 
seja feito com muita cautela.
Considere um grafo ponderado G=(V,E) que representa as estradas de uma região de interesse, 
em que 1 ≤ |V| ≤ 1.000 e 0 ≤ |E| ≤ 10.000.
O preço para abastecer uma unidade de combustível na cidade v é dado por c[v], 
e a capacidade do tanque de combustível de um veículo é dada por Q, com 1 ≤ Q ≤ 100.

Tarefa: determine a viagem mais barata que se pode realizar entre uma cidade de origem s e 
uma cidade destino t, utilizando um carro com capacidade de combustível Q.

Observação: (i) o carro em questão usa uma unidade de combustível por unidade de distância 
percorrida; (ii) o carro inicia com tanque vazio.

Dica: dicionários (em Python) ou estruturas map (C++) podem ser úteis nesse exercício.

Entradas:

A primeira linha corresponde a quantidade de vértices (|V|) e arestas (|E|) do grafo. 
A próxima linha contém |V| inteiros, representando o custo de se abastecer uma unidade 
do combustível na cidade v (o v-ésimo inteiro corresponde a c[v]). 
As próximas |E| linhas são compostas por inteiros i, j, d, indicando que existe uma estrada 
saindo de i e alcançando j com distância d. 
A linha subsequente corresponde a 1 ≤ x ≤ 10 testes que serão realizados no grafo de entrada, 
em que cada uma das x linhas dispostas a seguir são compostas pela capacidade do tanque de 
combustível do veículo, denotada por Q, o ponto de partida s e o ponto de destino t.

Saídas:

Para cada um dos x testes realizados, a resposta deve imprimir o menor custo de se sair de s 
e chegar a t, dada a capacidade Q do tanque de combustível do veículo. Caso não seja possível
 alcançar o vértice destino t a partir de s, o programa deve imprimir a resposta "sem solucao" 
 (frase com letras minúsculas, e sem acento gráfico).   

Exemplo de Entrada:

5 5
10 10 20 12 13
0 1 9
0 2 8
1 2 1
1 3 11
2 3 7
2
10 0 3
20 1 4   

Exemplo de Saída:

170
sem solucao


=============================================================================================

O aumento considerável no preço dos combustíveis faz com que o planejamento de qualquer viagem 
seja feito com muita cautela.
Considere um grafo ponderado G=(V,E) que representa as estradas de uma região de interesse, 
em que v são as cidades e E são as estradas.
O preço para abastecer uma unidade de combustível na cidade V é dado por c[v], 
e a capacidade do tanque de combustível de um veículo é dada por Q.
O veículo em questão usa uma unidade de combustível por unidade de distância percorrida.
O veículo inicia com tanque vazio.

determine a viagem mais barata que se pode realizar entre uma cidade de origem s e 
uma cidade destino t, utilizando um carro com capacidade de combustível Q.



Dica: dicionários (em Python) ou estruturas map (C++) podem ser úteis nesse exercício.

Para determinar a viagem mais barata que se pode realizar entre uma cidade de origem s e uma cidade destino t, utilizando uma moto com capacidade de combustível Q, podemos aplicar o algoritmo de Dijkstra em um grafo modificado que leva em conta o preço do combustível.

Para isso, vamos criar um grafo ponderado G'=(V',E'), em que cada cidade v é representada por dois vértices, v_0 e v_1. O vértice v_0 representa a cidade v com tanque vazio, enquanto o vértice v_1 representa a cidade v com tanque cheio. Além disso, vamos adicionar uma aresta direcionada (u_0,v_1) para cada aresta (u,v) de G, com peso w(u_0,v_1) = c[v] * (d(u,v) - Q), onde d(u,v) é a distância entre as cidades u e v em G.

A ideia é que, ao percorrer a aresta (u_0,v_1), a moto abasteça na cidade v e encha o tanque, permitindo que chegue até a próxima cidade. O peso da aresta (u_0,v_1) leva em conta o custo do combustível necessário para percorrer a distância entre as cidades u e v, descontando a capacidade do tanque da moto.

Aplicando o algoritmo de Dijkstra em G' a partir do vértice s_0, obtemos o menor caminho até o vértice t_1. O custo do caminho encontrado representa o menor custo para percorrer a distância entre as cidades s e t utilizando a moto com capacidade Q.

Note que, para que o algoritmo de Dijkstra funcione corretamente, é necessário que o grafo seja conexo. Caso contrário, pode ser necessário aplicar o algoritmo para cada componente conexo do grafo.
