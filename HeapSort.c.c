#include <stdio.h>
#include <stdlib.h>


void exibirVetor(int *vet, int tamanho) {
    int i;
    printf("[");
    for (i = 0; i < tamanho; i++) {
        printf("%d", vet[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void trocar(int *a, int *b) {
    int temp = *a; // Cria uma variável temporária para armazenar o valor de 'a'
    *a = *b;      // O valor no endereço de 'a' recebe o valor no endereço de 'b'
    *b = temp;     // O valor no endereço de 'b' recebe o valor armazenado em 'temp'
}

void heapify(int vet[], int tam, int atual) {
    int maior = atual;   // Assume que o nó atual é o maior
    int esquerdo = 2 * atual + 1; // Calcula o índice do filho esquerdo
    int direito = 2 * atual + 2;  // Calcula o índice do filho direito

    // Se o filho esquerdo existe (dentro dos limites do heap) e é maior que o maior atual
    if (esquerdo < tam && vet[esquerdo] > vet[maior]) {
        maior = esquerdo; // Atualiza o índice do maior para o filho esquerdo
    }

    // Se o filho direito existe (dentro dos limites do heap) e é maior que o maior atual
    if (direito < tam && vet[direito] > vet[maior]) {
        maior = direito; // Atualiza o índice do maior para o filho direito
    }

    // Se o maior não é o nó atual, troca o nó atual com o maior filho
    if (maior != atual) {
        trocar(&vet[atual], &vet[maior]);
        // Recursivamente chama heapify na subárvore afetada para manter a propriedade do heap
        heapify(vet, tam, maior);
    }
}

void heapSort(int vet[], int tam) {
    int i; // Declare 'i' aqui

    // Fase 1: Construir o heap máximo
    for (i = tam / 2 - 1; i >= 0; i--) {
        heapify(vet, tam, i);
    }

    // Fase 2: Extrair elementos do heap um por um
    for (i = tam - 1; i > 0; i--) {
        // Troca a raiz (maior elemento) com o último elemento não ordenado
        trocar(&vet[0], &vet[i]);

        // Chama heapify na raiz do heap reduzido (tamanho 'i') para manter a propriedade do heap máximo
        heapify(vet, i, 0);
    }
}

int main(void) {
    // Define um vetor de inteiros com dados previamente definidos
    int vet[] = {12, 11, 13, 5, 6, 7};
    // Calcula o número de elementos no vetor
    int tamanho = sizeof(vet) / sizeof(vet[0]); // Correção aqui: sizeof(vet)

    // Exibe o vetor antes da ordenação
    printf("Vetor antes da ordenacao: ");
    exibirVetor(vet, tamanho); // Correção aqui: exibirVetor(vet, ...)

    // Chama a função heapSort para ordenar o vetor
    heapSort(vet, tamanho); // Correção aqui: heapSort(vet, ...)

    // Exibe o vetor depois da ordenação
    printf("Vetor depois da ordenacao: ");
    exibirVetor(vet, tamanho); // Correção aqui: exibirVetor(vet, ...)

    return 0; 

}