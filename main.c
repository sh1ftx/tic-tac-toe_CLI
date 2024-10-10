#include <stdio.h>

#define SIZE 3 // Define o tamanho do tabuleiro 3x3

// Protótipos de funções
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]);
void mostrarTabuleiro(char tabuleiro[SIZE][SIZE]);
int verificarVitoria(char tabuleiro[SIZE][SIZE]);
int verificarEmpate(char tabuleiro[SIZE][SIZE]);
void jogada(char tabuleiro[SIZE][SIZE], char jogador);

// Função principal
int main() {
    char tabuleiro[SIZE][SIZE];
    char jogadorAtual = 'X';
    int vitoria = 0, empate = 0;

    inicializarTabuleiro(tabuleiro);

    while (1) {
        mostrarTabuleiro(tabuleiro);
        jogada(tabuleiro, jogadorAtual);
        
        vitoria = verificarVitoria(tabuleiro);
        empate = verificarEmpate(tabuleiro);
        
        if (vitoria) {
            mostrarTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        } else if (empate) {
            mostrarTabuleiro(tabuleiro);
            printf("O jogo empatou!\n");
            break;
        }

        // Alterna o jogador
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Inicializa o tabuleiro com números de 1 a 9
void inicializarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    int contador = 1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = contador + '0'; // Converte o número para caractere
            contador++;
        }
    }
}

// Mostra o tabuleiro
void mostrarTabuleiro(char tabuleiro[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

// Função para verificar se há uma vitória
int verificarVitoria(char tabuleiro[SIZE][SIZE]) {
    // Verifica linhas
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
    }

    // Verifica colunas
    for (int i = 0; i < SIZE; i++) {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }

    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }

    return 0;
}

// Função para verificar se houve empate
int verificarEmpate(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (tabuleiro[i][j] != 'X' && tabuleiro[i][j] != 'O') {
                return 0; // Ainda há posições disponíveis
            }
        }
    }
    return 1; // Todas as posições estão preenchidas e não há vencedor
}

// Função que realiza a jogada de um jogador
void jogada(char tabuleiro[SIZE][SIZE], char jogador) {
    int posicao;
    int linha, coluna;

    while (1) {
        printf("Jogador %c, escolha uma posição (1-9): ", jogador);
        scanf("%d", &posicao);

        // Calcula a linha e a coluna a partir da posição escolhida
        linha = (posicao - 1) / SIZE;
        coluna = (posicao - 1) % SIZE;

        // Verifica se a posição é válida
        if (posicao >= 1 && posicao <= 9 && tabuleiro[linha][coluna] != 'X' && tabuleiro[linha][coluna] != 'O') {
            tabuleiro[linha][coluna] = jogador;
            break;
        } else {
            printf("Posição inválida. Tente novamente.\n");
        }
    }
}
