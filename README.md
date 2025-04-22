Excelente! Com essa informação, podemos refinar o README. Aqui está uma versão atualizada:

Markdown

# Heapsort em C

Este repositório contém duas implementações do algoritmo de ordenação Heapsort escritas na linguagem de programação C. Uma implementação opera sobre um vetor predefinido, enquanto a outra é projetada para ordenar vetores de tamanhos variáveis.

## Descrição

O algoritmo Heapsort é um eficiente algoritmo de ordenação por comparação que utiliza a estrutura de dados heap. Este repositório demonstra duas abordagens para aplicar o Heapsort em C.

* **`heapsort_fixo.c`**: Implementa o Heapsort em um vetor com um tamanho definido no código-fonte. Este exemplo é útil para ilustrar o funcionamento básico do algoritmo com um conjunto de dados conhecido.
* **`heapsort_dinamico.c`**: Implementa o Heapsort em vetores de tamanhos diferentes, permitindo maior flexibilidade ao ordenar coleções de dados variáveis.

## Algoritmos Implementados

### `heapsort_fixo.c`: Heapsort em Vetor Predefinido

Esta implementação demonstra o Heapsort aplicado diretamente a um array com valores e tamanho codificados no arquivo `heapsort_fixo.c`. É um exemplo simples para entender a lógica do algoritmo.

### `heapsort_dinamico.c`: Heapsort para Vetores de Tamanhos Variáveis

Esta implementação oferece uma função de Heapsort que pode receber um vetor de qualquer tamanho e ordená-lo. Isso torna o algoritmo mais reutilizável em diferentes cenários.

## Como Compilar e Executar

Para compilar os arquivos, você pode usar o GCC:

```bash
gcc heapsort_fixo.c -o heapsort_fixo
gcc heapsort_dinamico.c -o heapsort_dinamico
