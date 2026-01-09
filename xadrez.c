#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {

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
    char direcao_cavalo_3; // 3 casas verticais ou horizontais do cavalo
    char direcao_cavalo_1; // 1 casa perpendicular

    
    // Defina as variaveis de numero de casas definido pelo usuario
    unsigned short num_casas_torre;
    unsigned short num_casas_rainha;
    unsigned short num_casas_bispo;

    // Logica pra o menu de selecao da direcao aqui
    // Defina um menu de ajuda caso o usuario precise saber a forma de movimento da peca
      
    printf("Ao digitar a direcao, considere:\n");
    printf("e - esquerda\nd - direita\nc - cima\nb - baixo\n");
    printf("#### Game Start ####\n");
    printf("Digita o numero da peca cujo movimento voce gostaria de conferir, ou 0 para avancar.\n");
    unsigned short escolha = 1; // Defina um valor para entrar no loop
    while(escolha != 0){
        printf("(1)\t\tTorre\n");
        printf("(2)\t\tBispo\n");
        printf("(3)\t\tRainha\n");
        printf("(4)\t\tCavalo\n");
        printf("(0)\t\tAvancar\n");
        printf("Escolha: ");
        scanf("%hu", &escolha);

        switch (escolha)
        {
        case 1:
            printf("Movimenta-se horizontal e verticalmente, varias casas. Indique a direcao e o numero de casas.\n");
            break;
        
        case 2:
            printf("Movimenta-se diagonalmente. Para esse movimento, escolha a combinacao 'c' ou 'b' com 'e' ou 'd' pra se mover na diagonal.\n");
            printf("Exemplo de resposta para o Bispo, 4 casas na diagonal para cima a direita: c e 4\n");
            break;
        
        case 3:
            // Para simplificar, limite o movimento da Rainha a vertical ou horizontal
            // TODO Implementar o movimento real da Rainha
            printf("Movimenta-se varias casas para a esquerda ou direita.\n");
            // printf("Para o movimento diagonal, escolha a combinacao 'c' ou 'b' com 'e' ou 'd' pra se mover na diagonal.\n");
            break;
        
        case 4:
            printf("O Cavalo se movimenta em 'L'.\n");
            printf("Escolha a direcao do movimento de 2 casas, 'c', 'b', 'e' ou 'd'. Para completar o movimento, escolha 'e' ou 'd'.\n");
            break;
        
        default:
            break;
        }
        
    }

    printf("### Inicio de movimentacao das pecas ###\n");
    printf("Escolha a peca que deseja movimentar, ou digite 0 para sair do jogo.\n\n");
    unsigned short escolha_peca;
    while(1){
        printf("(1)\t\tTorre\n");
        printf("(2)\t\tBispo\n");
        printf("(3)\t\tRainha\n");
        printf("(4)\t\tCavalo\n");
        printf("(0)\t\tSair do jogo...\n");
        printf("Escolha: ");
        scanf("%hu", &escolha_peca);

        switch (escolha_peca)
        {
        case 1:
            printf("Movimente a Torre: ");
            scanf(" %c %hu", &direcao_torre, &num_casas_torre); // Adicione espaco antes de %c para consumir algum espaco remanescente
            printf("\n");

            // Defina o movimento da Torre
            while(num_casas_torre > 0){
                executar_mov_vert_hori(direcao_torre);
                num_casas_torre--;
            }
            printf("\n### Finalizado o movimento da Torre ###\n\n");
            break;
        
        case 2:
            printf("Movimente o Bispo: ");
            scanf(" %c %c %hu", &direcao_bispo_cb, &direcao_bispo_ed, &num_casas_bispo);
            printf("\n");

            // Defina o movimento do Bispo
            do {
                executar_mov_diag(direcao_bispo_cb, direcao_bispo_ed);
                num_casas_bispo--;
            }
            while(num_casas_bispo > 0);

            printf("\n### Finalizado o movimento do Bispo ###\n\n");
            break;
        
        case 3:
            // Para simplificar, limite o movimento da Rainha a vertical ou horizontal
            printf("Movimente a Rainha: ");
            scanf(" %c %hu", &direcao_rainha, &num_casas_rainha);
            printf("\n");

            // Defina o movimento da rainha
            for(unsigned short i=num_casas_rainha; i > 0; i--){
                executar_mov_vert_hori(direcao_rainha);
            }

            printf("\n### Finalizado o movimento da Rainha ###\n\n");
            break;
        
        case 4:
            
            printf("Movimente o Cavalo: ");
            scanf(" %c %c", &direcao_cavalo_3, &direcao_cavalo_1);
            printf("\n");
            unsigned short stop;
            for (unsigned short i = 2; i > 0; i--){
                // Poderia ser um simples if(i == 0) then executar_mov_vert_hori(direcao_cavalo_1)
                // Crie um loop while para movimentar o Cavalo 2 casas na vert ou hori e depois 1 casa perpendicular
                stop = 1;
                while(stop < 2){
                    executar_mov_vert_hori(direcao_cavalo_3);
                    stop++;
                }
            }
            executar_mov_vert_hori(direcao_cavalo_1);
            printf("\n### Finalizado o movimento do Cavalo ###\n\n");
            break;
        
        default:
            break;
        }
        
    }

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

