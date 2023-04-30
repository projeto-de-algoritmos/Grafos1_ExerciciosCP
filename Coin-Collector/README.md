# Sumário

- [Sumário](#sumário)
- [Coin Collector](#coin-collector)
  - [Entrada](#entrada)
  - [Saída](#saída)
  - [Restrições](#restrições)
  - [Exemplos](#exemplos)
    - [Entrada 1](#entrada-1)
    - [Saída 1](#saída-1)
- [Solução](#solução)

# [Coin Collector](https://cses.fi/problemset/task/1686)

A game has **n** rooms and **m** tunnels between them. Each room has a certain number of coins. What is the maximum number of coins you can collect while moving through the tunnels when you can freely choose your starting and ending room?

## Entrada

The first input line has two integers **n** and **m**: the number of rooms and tunnels. The rooms are numbered 1,2,…,**n**.

Then, there are **n** integers **k<sub>1</sub>,k<sub>2</sub>,…,k<sub>n</sub>**: the number of coins in each room.

Finally, there are m lines describing the tunnels. Each line has two integers **a** and **b**: there is a tunnel from room **a** to room **b**. Each tunnel is a one-way tunnel.

## Saída

Print one integer: the maximum number of coins you can collect.

## Restrições

- 1 ≤ **n** ≤ 10<sup>5</sup>
- 1 ≤ **m** ≤ 2⋅10<sup>5</sup>
- 1 ≤ **k<sub>i</sub>** ≤ 10<sup>9</sup>
- 1 ≤ **a**,**b** ≤ **n**

## Exemplos

### Entrada 1
```
4 4
4 5 2 7
1 2
2 1
1 3
2 4
```

### Saída 1
```
16
```

# [Solução](./solution.cpp)

O problema não tem nenhuma restrição a respeito de passar mais de uma vez por uma mesma aresta, tendo isso em mente podemos simplificar o grafo dado eliminando seus ciclos e tratando cada componente fortemente conectado como um vértice.

Para encontrar os componentes fortemente conectados do grafo precisamos calcular o grafo transposto (G<sup>T</sup>), que é dado pela reversão da direção de cada aresta. Em seguida é necessário encontrar a ordenação topológica do grafo G, que pode ser calculada utilizando uma sequencia de DFS e armazenando a ordem de saída de cada vértice. Após este passo, basta executar uma DFS ou BFS no grafo transposto G<sup>T</sup> seguindo a ordem encontrada na ordenação topológica.

Em seguida, podemos condensar o grafo elegendo um representante para cada componente fortemente conectado e criando um novo grafo com apenas estes representantes. Além disso, devemos atualizar a quantidade de moedas que cada vértice desse novo grafo condensado possui para a soma de todas as moedas dos vértices que fazem parte desse componente fortemente conectado. Por fim, ficamos um grafo direcionado acíclico (DAG) e para resolver o problema basta encontrar o caminho com mais moedas neste grafo.

Porém não podemos executar **N** travessias para encontrar o caminho com mais moedas neste DAG, pois isto seria um algorítimo quadrático e estouraria o tempo limite do problema. Para resolver isto basta adicionar uma memorização dos caminhos já calculados utilizando um conceito de _memoization_ que faz parte do módulo de Programação Dinâmica (DP), utilizando DP podemos reduzir a complexidade de O(n<sup>2</sup>) para O(n).
