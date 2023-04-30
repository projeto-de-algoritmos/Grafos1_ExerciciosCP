# Sumário

- [Sumário](#sumário)
- [Friendly Spiders](#friendly-spiders)
  - [Entrada](#entrada)
  - [Saída](#saída)
  - [Exemplos](#exemplos)
    - [Entrada 1](#entrada-1)
    - [Saída 1](#saída-1)
    - [Entrada 2](#entrada-2)
    - [Saída 2](#saída-2)
    - [Entrada 3](#entrada-3)
    - [Saída 3](#saída-3)
- [Solução](#solução)

# [Friendly Spiders](https://codeforces.com/contest/1775/problem/D)

Mars is home to an unusual species of spiders — Binary spiders.

Right now, Martian scientists are observing a colony of **n** spiders, the **i**-th of which has **a<sub>i</sub>** legs.

Some of the spiders are friends with each other. Namely, the **i**-th and **j**-th spiders are friends if gcd(a<sub>i</sub>,a<sub>j</sub>) ≠ 1, i. e., there is some integer k ≥ 2 such that **a<sub>i</sub>** and **a<sub>j</sub>** are simultaneously divided by **k** without a remainder. Here gcd(x,y) denotes the [greatest common divisor (GCD)](https://en.wikipedia.org/wiki/Greatest_common_divisor) of integers x and y.

Scientists have discovered that spiders can send messages. If two spiders are friends, then they can transmit a message directly in one second. Otherwise, the spider must pass the message to his friend, who in turn must pass the message to his friend, and so on until the message reaches the recipient.

Let's look at an example.

Suppose a spider with eight legs wants to send a message to a spider with 15 legs. He can't do it directly, because gcd(8,15) = 1. But he can send a message through the spider with six legs because gcd(8,6) = 2 and gcd(6,15) = 3. Thus, the message will arrive in two seconds.

Right now, scientists are observing how the **s**-th spider wants to send a message to the **t**-th spider. The researchers have a hypothesis that spiders always transmit messages optimally. For this reason, scientists would need a program that could calculate the minimum time to send a message and also deduce one of the optimal routes.

<center>

![Imagem referente ao exemplo acima](https://espresso.codeforces.com/483a1fb1da2c818e47b844bc731a0d33956835e5.png)

</center>

## Entrada

The first line of input contains an integer **n** (2 ≤ **n** ≤ 3⋅10<sup>5</sup>) — the number of spiders in the colony.

The second line of input contains **n** integers **a<sub>1</sub>**,**a<sub>2</sub>**,…,**a<sub>n</sub>** (1 ≤ **a<sub>i</sub>** ≤ 3⋅10<sup>5</sup>) — the number of legs the spiders have.

The third line of input contains two integers **s** and **t** (1 ≤ **s**,**t** ≤ **n**) — the spiders between which the message must be sent.

## Saída

If it is impossible to transmit a message between the given pair of spiders, print **−1**.

Otherwise, in the first line of the output print the integer **t** (**t** ≥ 1) — the number of spiders that participate in the message transmission (i. e. the minimum time of message delivery in seconds plus one). In the second line, print **t** different integers **b<sub>1</sub>**,**b<sub>2</sub>**,…,**b<sub>t</sub>** (1 ≤ **b<sub>i</sub>** ≤ **n**) — the ids of the spiders through which the message should follow, in order from sender to receiver.

If there are several optimal routes for the message, output any of them.

## Exemplos

### Entrada 1
```
7
2 14 9 6 8 15 11
5 6
```

### Saída 1
```
3
5 4 6
```

### Entrada 2
```
7
2 14 9 6 8 15 11
5 7
```

### Saída 2
```
-1
```

### Entrada 3
```
7
2 14 9 6 8 15 11
5 5
```

### Saída 3
```
1
5
```

# [Solução](./solution.cpp)

Devido a grande quantidade de vértices que o grafo possui, não é possível construí-lo baseado na definição dada no problema, já que o algoritmo para construí-lo seria quadrático e isso excederia o limite de tempo do problema. Então temos que tentar deixar o grafo mais compacto.

É possível mostrar que o GCD de dois números só é igual a 1 quando ambos os números não possuem nenhum primo em comum em sua fatoração, ou seja, só existirá uma aresta entre vértices que possuam um fator primo em comum. E que um número **a<sub>i</sub>** possui no máximo log(**a<sub>i</sub>**) divisores primos diferentes.

Baseado nisso, podemos criar um grafo bipartido onde sua parte esquerda corresponde aos **n** vértices com números **a<sub>i</sub>** e na sua parte direita cada vértice corresponde a um número primo presente na fatoração dos números da parte esquerda.

Assim, criamos uma aresta partindo de um vértice **v** da parte esquerda para um vértice **u** da parte direita se e somente se **a<sub>v</sub>** é divisível pelo número correspondente ao vértice **u**. Com o grafo construído basta executar uma BFS para achar o menor caminho.
