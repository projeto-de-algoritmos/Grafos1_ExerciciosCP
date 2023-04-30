# Sumário

- [Sumário](#sumário)
- [+1-1x2](#1-1x2)
  - [Restrições](#restrições)
  - [Entrada](#entrada)
  - [Saída](#saída)
  - [Exemplos](#exemplos)
    - [Entrada 1](#entrada-1)
    - [Saída 1](#saída-1)
    - [Entrada 2](#entrada-2)
    - [Saída 2](#saída-2)
- [Solução](#solução)

# [+1-1x2](https://atcoder.jp/contests/abc188/tasks/abc188_f)

Takahashi has written an integer **_X_** on a blackboard. He can do the following three kinds of operations any number of times in any order:

- increase the value written on the blackboard by **1**;
- decrease the value written on the blackboard by **1**;
- multiply the value written on the blackboard by **2**.

Find the minimum number of operations required to have **_Y_** written on the blackboard.

## Restrições

- 1 &le; **_X_** &le; 10<sup>18</sup>
- 1 &le; **_Y_** &le; 10<sup>18</sup>
- **_X_** and **_Y_** are integers.

## Entrada

Input is given from Standard Input in the following format:
```
X Y
```

## Saída

Print the answer.

## Exemplos

### Entrada 1
```
3 9
```

### Saída 1
```
3
```

### Entrada 2
```
7 11
```

### Saída 2
```
3
```

# [Solução](./solution.cpp)

Podemos enxergar os valores **_X_** e **_Y_** como vértices de grafo, onde queremos encontrar a quantidade de vértices presentes no menor caminho entre **_X_** e **_Y_**. Neste grafo implícito as arestas são representadas pelas possíveis operações descritas no problema.
- **+ 1**
- **- 1**
- **&times; 2**

É importante notar que a única operação possível que nos permite ir para um vértice com valor menor que o atual é a **-1**. Portanto quando o valor de **_X_** é maior ou igual a **_Y_** podemos simplesmente retornar **_X_** - **_Y_**.

Tendo em vista que esse grafo possui muitos vértices e arestas, é interessante buscar formas de reduzir o nosso escopo de busca. Para isso, podemos considerar as operações opostas às descritas no enunciado, ficando assim com um problema equivalente porém com uma quantidade reduzida de arestas no grafo. Utilizando as operações opostas queremos sair de **_Y_** e chegar em **_X_** com as seguintes operações:
- **- 1**
- **+ 1**
- **/ 2** (apenas quando **_Y_** é divisível por 2)

Dessa forma, apenas os números pares podem utilizar a terceira operação.

Visto que sempre é possível sair de um **_Y_** qualquer e chegar a **_X_** com **|_X-Y_|** movimentos, podemos utilizar isso como um limite superior para nossa resposta, descartando assim os caminhos que passam por mais vértices que esse limite superior.

Sendo assim, basta executar uma BFS neste grafo utilizando o limite superior calculado anteriormente para podar os caminhos calculados.
