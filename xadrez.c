#include <stdio.h>

// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.


// ##### Área de definição de funções auxiliares
// Função auxiliar para se mover na horizontal ou vertical
void printar_mov_vert_hori(char direcao){
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
            printf("Direção inválida! Tente novamente.\nSaindo...\n\n");
            break;
        }
}

// Função auxiliar para se mover na diagonal
void printar_mov_diag(char direcao_cb, char direcao_ed){
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
            printf("Direção Inválida! Tente novamente.\nSaindo...\n\n");
            break;
        }
}

// Definicao do movimento de cada peca usando funcoes recursivas

// Mover horizontal e verticalmente, valido para Torre e Rainha (desconsiderando movimento diag.)
void mover_vert_hori(char direcao, unsigned short num_casas){
    if(num_casas > 0){
        printar_mov_vert_hori(direcao);
        mover_vert_hori(direcao, num_casas-1);
    }
}

// Mover o Bispo (diagonalmente)
void mover_diag(char direcao_cb, char direcao_ed, unsigned short num_casas){
    if(num_casas > 0){
        printar_mov_diag(direcao_cb, direcao_ed);
        mover_diag(direcao_cb, direcao_ed, num_casas-1);
    }
}

// Mover o Cavalo (em 'L')
void mover_cavalo(char direcao_2, char direcao_1, unsigned short var_controle){
    if(var_controle > 0){
        printar_mov_vert_hori(direcao_2);
        if(var_controle == 1){
            printar_mov_vert_hori(direcao_1);
        }
        mover_cavalo(direcao_2, direcao_1, var_controle-1);
    }
}

// Função principal (main)

int main() {

    // Defina as direções
    char cima = 'c';
    char baixo = 'b';
    char direita = 'd';
    char esquerda = 'e';
    
    // Declare as variáveis de direção da peça escolhida pelo usuário
    char direcao_torre;
    char direcao_rainha;
    char direcao_rainha_cb; // para verificar se o usuario quer mover a rainha diag.
    char direcao_rainha_ed;
    char direcao_bispo_cb; // cima ou baixo
    char direcao_bispo_ed; // esquerda ou direita
    char direcao_cavalo_2; // 2 casas verticais ou horizontais do cavalo
    char direcao_cavalo_1; // 1 casa perpendicular

    
    // Defina as variáveis de número de casas definido pelo usuário
    unsigned short num_casas_torre;
    unsigned short num_casas_rainha;
    unsigned short num_casas_bispo;

    // Defina um menu de ajuda caso o usuário precise saber a forma de movimento da peça
    printf("#### Game Start ####\n");
    printf("Digite o número da peça, cujo movimento você gostaria de conferir, ou 0 para avançar.\n");
    unsigned short control_loop = __SHRT_MAX__; // Defina um valor para entrar no loop
    while(control_loop != 0){
        printf("(1)\t\tTorre\n");
        printf("(2)\t\tBispo\n");
        printf("(3)\t\tRainha\n");
        printf("(4)\t\tCavalo\n");
        printf("(0)\t\tAvançar\n");
        printf("Escolha: ");
        
        scanf("%hu", &control_loop);
        
        printf("Ao digitar a direção, considere:\n");
        printf("e - esquerda\nd - direita\nc - cima\nb - baixo\n");
        switch (control_loop){
            case 1:
                printf("Movimenta-se horizontal e verticalmente, várias casas. Indique a direção e o número de casas.\n");
                printf("Exemplo de resposta para a Torre, 3 casas na vertical para cima: c 3\n");
                break;
            
            case 2:
                printf("Movimenta-se diagonalmente. Para esse movimento, escolha a combinação 'c' ou 'b' com 'e' ou 'd'.\n");
                printf("Exemplo de resposta para o Bispo, 4 casas na diagonal para cima a direita: c e 4\n");
                break;
            
            case 3:
                printf("Movimenta-se varias casas para a esquerda ou direita, ou diagonalmente.\n");
                printf("Caso diagonal, escolha a combinação 'c' ou 'b' com 'e' ou 'd', como com o Bispo.\n");
                printf("Exemplo de resposta para a Rainha, 6 casas para esquerda: e 6\n");
                break;
            
            case 4:
                printf("O Cavalo se movimenta em 'L'.\n");
                printf("Escolha a direção do movimento de 2 casas: 'c', 'b', 'e' ou 'd'. Para a última casa, escolha 'e' ou 'd'.\n");
                break;
            
            default:
                break;
        }
    }

    printf("### Início de movimentação das peças ###\n");
    printf("Escolha a peça que deseja movimentar, ou digite 0 para sair do jogo.\n\n");
    unsigned short escolha_peca = __SHRT_MAX__;
    while(escolha_peca != 0){
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

            // Defina o movimento da Torre (versao interativa)
            /** while(num_casas_torre > 0){
                printar_mov_vert_hori(direcao_torre);
                num_casas_torre--;
            }
            */
            mover_vert_hori(direcao_torre, num_casas_torre);
            printf("\n### Finalizado o movimento da Torre ###\n\n");
            break;
        
        case 2:
            printf("Movimente o Bispo: ");
            scanf(" %c %c %hu", &direcao_bispo_cb, &direcao_bispo_ed, &num_casas_bispo);
            printf("\n");

            // Defina o movimento do Bispo (versao interativa)
            /**
            do {
                printar_mov_diag(direcao_bispo_cb, direcao_bispo_ed);
                num_casas_bispo--;
            }
            while(num_casas_bispo > 0);
            */
            mover_diag(direcao_bispo_cb, direcao_bispo_ed, num_casas_bispo);

            printf("\n### Finalizado o movimento do Bispo ###\n\n");
            break;
        
        case 3:
            // Para simplificar, limite o movimento da Rainha a vertical ou horizontal
            unsigned short escolha_mov_diag;
            printf("Deseja mover a Rainha na diagonal?\n");
            printf("(1)\t\tSim\n(0)\t\tNao\n");
            printf("Escolha: ");
            scanf(" %hu", &escolha_mov_diag);
            if(escolha_mov_diag == 0){
                printf("Movimente a Rainha: ");
                scanf(" %c %hu", &direcao_rainha, &num_casas_rainha);
                printf("\n");

                mover_vert_hori(direcao_rainha, num_casas_rainha);
            } else {
                printf("Movimente a Rainha: ");
                scanf(" %c %c %hu", &direcao_rainha_cb, &direcao_rainha_ed, &num_casas_rainha);
                printf("\n");

                mover_diag(direcao_rainha_cb, direcao_rainha_ed, num_casas_rainha);
            }
            

            // Defina o movimento da Rainha (versao interativa)
            /**
            for(unsigned short i=num_casas_rainha; i > 0; i--){
                printar_mov_vert_hori(direcao_rainha);
            }
            */
            printf("\n### Finalizado o movimento da Rainha ###\n\n");
            break;
        
        case 4:
            printf("Movimente o Cavalo: ");
            scanf(" %c %c", &direcao_cavalo_2, &direcao_cavalo_1);
            printf("\n");

            // Defina o movimento do Cavalo (versao interativa)
            /**
            unsigned short stop;    // Condição de parada para o loop interno
            for (unsigned short i = 2; i > 0; i--){
                // Poderia ser um simples if(i == 0) then printar_mov_vert_hori(direcao_cavalo_1)
                stop = 1;
                while(stop < 2){
                    printar_mov_vert_hori(direcao_cavalo_3);   // "Perna maior" do 'L'
                    stop++;
                }
            }
            printar_mov_vert_hori(direcao_cavalo_1);           // "Perna menor" do 'L'
            */
            mover_cavalo(direcao_cavalo_2, direcao_cavalo_1, 2);
            printf("\n### Finalizado o movimento do Cavalo ###\n\n");
            break;
        
        default:
            printf("\n### Fim do jogo!! ###\n\n");
            break;
        }
        
    }
    return 0;
}
