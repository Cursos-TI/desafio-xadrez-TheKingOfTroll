#include <stdio.h>

// Constantes para direções
#define CIMA 0
#define BAIXO 1
#define ESQUERDA 2
#define DIREITA 3

// Função recursiva para movimentar a Torre
void moverTorreRecursivo(int casas, int direcao) {
    // Caso base - encerra a recursão
    if (casas <= 0) return;

    // Imprime a direção do movimento
    switch(direcao) {
        case CIMA:    printf("Cima\n"); break;
        case BAIXO:   printf("Baixo\n"); break;
        case ESQUERDA: printf("Esquerda\n"); break;
        case DIREITA:  printf("Direita\n"); break;
        default: return;
    }

    // Chamada recursiva
    moverTorreRecursivo(casas - 1, direcao);
}

// Função recursiva para mover o Bispo diagonalmente
void moverBispoRecursivo(int x, int y, int destino) {
    // Caso base - chegou ao destino
    if (x >= destino || y >= destino) return;

    // Movimento diagonal (cima + direita)
    printf("Cima\n");
    printf("Direita\n");
    printf("\n"); // separa os passos

    // Chamada recursiva
    moverBispoRecursivo(x + 1, y + 1, destino);
}

// Função com loops aninhados para o Bispo
void moverBispoLoopsAninhados(int casas) {
    // Loop externo para movimento vertical
    for (int i = 0; i < casas; i++) {
        printf("Cima\n");
        
        // Loop interno para movimento horizontal
        for (int j = 0; j <= i; j++) {
            if (j < i) continue; // Controla quando imprimir
            printf("Direita\n");
        }
    }
}

// Função unificada para a Rainha
void moverRainhaRecursivo(int casas, int tipoMov, int direcao) {
    if (casas <= 0) return;

    if (tipoMov == 0) { // Movimento como Torre
        switch(direcao) {
            case CIMA:    printf("Cima\n"); break;
            case BAIXO:   printf("Baixo\n"); break;
            case ESQUERDA: printf("Esquerda\n"); break;
            case DIREITA:  printf("Direita\n"); break;
        }
    } 
    else { // Movimento como Bispo
        printf("Cima\n");
        printf("Direita\n");
    }

    moverRainhaRecursivo(casas - 1, tipoMov, direcao);
}

// Função melhorada para o Cavalo com loops complexos
void moverCavaloLoops(int movimentos) {
    for (int mov = 0; mov < movimentos; mov++) {
        int passo = 0;
        
        // Loop while com condições complexas
        while (passo < 3) {
            if (passo >= 2) {
                printf("Direita\n");
                break;
            }
            
            printf("Cima\n");
            passo++;
            
            // Demonstração do uso do continue
            if (passo < 2) continue;
        }
        
        printf("\n"); // separa os movimentos em L
    }
}

int main() {
    // Configurações dos movimentos
    const int casasTorre = 3;
    const int casasBispo = 4;
    const int casasRainha = 3;
    const int movCavalo = 2;

    printf("=== SIMULADOR DE XADREZ - NÍVEL MESTRE ===\n\n");

    // Torre - movimento recursivo para cima
    printf("1. Torre (cima):\n");
    moverTorreRecursivo(casasTorre, CIMA);
    printf("\n");

    // Bispo - movimento recursivo diagonal
    printf("2. Bispo (diagonal):\n");
    moverBispoRecursivo(0, 0, casasBispo);
    printf("\n");

    // Bispo - com loops aninhados
    printf("3. Bispo (diagonal):\n");
    moverBispoLoopsAninhados(casasBispo);
    printf("\n");

    // Rainha - movimento como torre (direita)
    printf("4. Rainha (direita):\n");
    moverRainhaRecursivo(casasRainha, 0, DIREITA);
    printf("\n");

    // Rainha - movimento como bispo (diagonal)
    printf("5. Rainha (diagonal):\n");
    moverRainhaRecursivo(casasRainha, 1, 0);
    printf("\n");

    // Cavalo - movimento em L complexo
    printf("6. Cavalo (movimento em L):\n");
    moverCavaloLoops(movCavalo);

    return 0;
}
