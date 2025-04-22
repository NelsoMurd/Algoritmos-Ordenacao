#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibirVetor(int *vet, int tamanho) {
    printf("[");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vet[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int vet[], int tam, int atual) {
    int maior = atual;
    int esquerdo = 2 * atual + 1;
    int direito = 2 * atual + 2;
    if (esquerdo < tam && vet[esquerdo] > vet[maior]) {
        maior = esquerdo;
    }
    if (direito < tam && vet[direito] > vet[maior]) {
        maior = direito;
    }
    if (maior != atual) {
        trocar(&vet[atual], &vet[maior]);
        heapify(vet, tam, maior);
    }
}

void heapSort(int vet[], int tam) {
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(vet, tam, i);
    }
    for (int i = tam - 1; i > 0; i--) {
        trocar(&vet[0], &vet[i]);
        heapify(vet, i, 0);
    }
}

double medirTempo(int *vetor, int tamanho) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    heapSort(vetor, tamanho);
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    return tempo_execucao;
}

int main(void) {
    int tamanhos[] = {100, 1000, 10000, 100000, 1000000};
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    printf("Medicao de Tempo do Heap Sort para Diferentes Tamanhos de Vetor:\n");
    printf("-------------------------------------------------------------\n");
    printf("| Tamanho do Vetor | Tempo de Execução (segundos) |\n");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < num_testes; i++) {
        int tamanho = tamanhos[i];
        int *vetor = (int *)malloc(tamanho * sizeof(int));

        if (vetor == NULL) {
            printf("Erro ao alocar memoria para o vetor de tamanho %d.\n", tamanho);
            continue;
        }

        // Preenche o vetor com dados aleatórios para o teste
        srand(time(NULL));
        for (int j = 0; j < tamanho; j++) {
            vetor[j] = rand() % tamanho; // Valores aleatórios entre 0 e tamanho-1
        }

        double tempo = medirTempo(vetor, tamanho);
        printf("| %16d | %26f |\n", tamanho, tempo);

        free(vetor);
    }

    printf("-------------------------------------------------------------\n");

    return 0;
}