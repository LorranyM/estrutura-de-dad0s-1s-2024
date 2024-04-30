#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura para representar um ponto
typedef struct {
    int x;
    float y;
} Ponto;

// Função para calcular a média dos valores de x e y
void calcularMedia(Ponto *pontos, int num_registros, float *media_x, float *media_y) {
    float soma_x = 0, soma_y = 0;
    for (int i = 0; i < num_registros; i++) {
        soma_x += pontos[i].x;
        soma_y += pontos[i].y;
    }
    *media_x = soma_x / num_registros;
    *media_y = soma_y / num_registros;
}

// Função para calcular a inclinação (coeficiente angular) da reta de regressão
float calcularInclinacao(Ponto *pontos, int num_registros, float media_x, float media_y) {
    float numerador = 0, denominador = 0;
    for (int i = 0; i < num_registros; i++) {
        numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }
    return numerador / denominador;
}

// Função para calcular o ponto de interceptação (coeficiente linear) da reta de regressão
float calcularInterceptacao(float inclinacao, float media_x, float media_y) {
    return media_y - inclinacao * media_x;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s arquivo.csv\n", argv[0]);
        return 1;
    }

    // Abrir o arquivo
    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Contar o número de registros no arquivo
    int num_registros = 0;
    while (fgetc(arquivo) != EOF) {
        if (fgetc(arquivo) == '\n') {
            num_registros++;
        }
    }

    // Voltar ao início do arquivo
    rewind(arquivo);

    // Alocar dinamicamente um array de pontos
    Ponto *pontos = malloc(num_registros * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Ler os pontos do arquivo e armazená-los no array
    for (int i = 0; i < num_registros; i++) {
        if (fscanf(arquivo, "%d,%f", &pontos[i].x, &pontos[i].y) != 2) {
            printf("Erro ao ler o arquivo.\n");
            return 1;
        }
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Calcular a média dos valores de x e y
    float media_x, media_y;
    calcularMedia(pontos, num_registros, &media_x, &media_y);

    // Calcular a inclinação (coeficiente angular) da reta de regressão
    float inclinacao = calcularInclinacao(pontos, num_registros, media_x, media_y);

    // Calcular o ponto de interceptação (coeficiente linear) da reta de regressão
    float interceptacao = calcularInterceptacao(inclinacao, media_x, media_y);

    // Exibir os resultados da equação da regressão linear
    printf("y = %.2fx + %.2f\n", inclinacao, interceptacao);

    // Liberar a memória alocada
    free(pontos);

    return 0;
}
