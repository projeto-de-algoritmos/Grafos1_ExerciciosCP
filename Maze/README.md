# Sumário

- [Sumário](#sumário)
- [Maze](#maze)
  - [Entrada](#entrada)
  - [Saída](#saída)
  - [Exemplos](#exemplos)
    - [Entrada 1](#entrada-1)
    - [Saída 1](#saída-1)
    - [Entrada 2](#entrada-2)
    - [Saída 2](#saída-2)
- [Solução](#solução)

# [Maze](https://codeforces.com/contest/377/problem/A)

Pavel loves grid mazes. A grid maze is an n × m rectangle maze where each cell is either empty, or is a wall. You can go from one cell to another only if both cells are empty and have a common side.

Pavel drew a grid maze with all empty cells forming a connected area. That is, you can go from any empty cell to any other one. Pavel doesn't like it when his maze has too little walls. He wants to turn exactly k empty cells into walls so that all the remaining cells still formed a connected area. Help him.

## Entrada

The first line contains three integers n, m, k (1 ≤ n, m ≤ 500, 0 ≤ k < s), where n and m are the maze's height and width, correspondingly, k is the number of walls Pavel wants to add and letter s represents the number of empty cells in the original maze.

Each of the next n lines contains m characters. They describe the original maze. If a character on a line equals ".", then the corresponding cell is empty and if the character equals "#", then the cell is a wall.

## Saída

Print n lines containing m characters each: the new maze that fits Pavel's requirements. Mark the empty cells that you transformed into walls as "X", the other cells must be left without changes (that is, "." and "#").

It is guaranteed that a solution exists. If there are multiple solutions you can output any of them.

## Exemplos

### Entrada 1
```
3 4 2
#..#
..#.
#...
```

### Saída 1
```
#.X#
X.#.
#...
```

### Entrada 2
```
3 4 2
#..#
..#.
#...
```

### Saída 2
```
#.X#
X.#.
#...
```

# Solução

Podemos enxergar a matriz dada pelo problema como um grafo, onde cada célula vazia da matriz representa um vértice do grafo e existe uma aresta entre duas células vazias que compartilham um mesmo lado.

Como o problema já nos garante que o grafo dado é um componente conectado, podemos executar uma BFS ou uma DFS partindo de uma célula vazia, essa travessia por sí visitaria todas as **s** células vazias, porém podemos parar a busca quando visitarmos **s-k** células. As células visitadas por essa travessia representam um componente conectado e sobram exatamente **k** células vazias que não foram visitadas nessa travessia, podemos então adicionar uma parede nessas células.

O código para a solução pode ser encontrado [aqui](./solution.cpp)
