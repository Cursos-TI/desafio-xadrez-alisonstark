#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.

    // Defina as direcoes
    char cima = 'c';
    char baixo = 'b';
    char direita = 'd';
    char esquerda = 'e';
    
    // Declare as variaveis de direcao da peca escolhida pelo usuario
    char direcao_torre;
    char direcao_rainha;
    char direcao_bispo_cb; // cima ou baixo
    char direcao_bispo_ed; // esquerda ou direita

    
    // Defina as variaveis de numero de casas definido pelo usuario
    unsigned short num_casas_torre;
    unsigned short num_casas_rainha;
    unsigned short num_casas_bispo;

    // Logica pra o menu de selecao da direcao aqui
    printf("Escolha a direcao e a quantidade de casas para movimentar cada peca.\n");
    printf("Use:\n");
    printf("e - esquerda\nd - direita\nc - cima\nb - baixo\n");
    printf("Exemplo de resposta, 5 casas para a esquerda: e 5\n\n");
    printf("No caso do Bispo, escolha a combinacao cima ou baixo com esquerda ou direita pra se mover na diagonal.\n");
    printf("Exemplo de resposta para o Bispo, 4 casas na diagonal para cima a direita: c e 4\n\n");

    printf("### Inicio de movimentacao das pecas ###\n\n");
    printf("Movimente a Torre: ");
    scanf(" %c %hu", &direcao_torre, &num_casas_torre); // Adicione espaco antes de %c para consumir algum espaco remanescente
    printf("\n");

    
    printf("Movimente o Bispo: ");
    scanf(" %c %c %hu", &direcao_bispo_cb, &direcao_bispo_ed, &num_casas_bispo);
    printf("\n");

    printf("Movimente a Rainha: ");
    scanf(" %c %hu", &direcao_rainha, &num_casas_rainha);
    printf("\n");

    // Possivel melhoria: o usuario pode escolher a peca que quer movimentar

    
    // Defina o movimento da Torre
    while(num_casas_torre > 0){
        executar_mov_vert_hori(direcao_torre);
        num_casas_torre--;
    }
    printf("\n### Finalizado o movimento da Torre ###\n\n");

    // Defina o movimento do Bispo
    do {
        executar_mov_diag(direcao_bispo_cb, direcao_bispo_ed);
        num_casas_bispo--;
    }
    while(num_casas_bispo > 0);

    printf("\n### Finalizado o movimento do Bispo ###\n\n");
    // Defina o movimento da rainha
    for(unsigned short i=num_casas_rainha; i > 0; i--){
        executar_mov_vert_hori(direcao_rainha);
    }

    printf("\n### Finalizado o movimento da Rainha ###\n\n");

    return 0;
}
// ##### Area de definicao de funcoes auxiliares
// Funcao auxiliar para se mover na horizontal ou vertical
void executar_mov_vert_hori(char direcao){
    switch (direcao)
        {
        case 'd':
            printf("Direita\n");
            break;
        
        case 'e':
            printf("Esquerda\n");
            break;
        
        case 'c':
            printf("Cima\n");
            break;
        
        case 'b':
            printf("Baixo\n");
            break;

        default:
            printf("Direcao invalida! Tente novamente.\nSaindo...\n\n");
            break;
        }
}

// Funcao auxiliar para se mover na diagonal
void executar_mov_diag(char direcao_cb, char direcao_ed){
    switch (direcao_cb)
        {
        case 'c':
            if(direcao_ed == 'e'){
                printf("Cima Esquerda\n");
            }
            else if(direcao_ed == 'd'){
                printf("Cima Direita\n");
            }
            break;
        
        case 'b':
            if(direcao_ed == 'e'){
                printf("Baixo Esquerda\n");
            }
            else if(direcao_ed == 'd'){
                printf("Baixo Direita\n");
            }
            break;

        default:
            printf("Direcao invalida! Tente novamente.\nSaindo...\n\n");
            break;
        }
}

