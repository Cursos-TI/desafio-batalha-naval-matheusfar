#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {


    const int agua = 0;

    // Variavel para guardar as letras que vão representar as colunas de forma estetica no tabuleiro
    char coluna[10] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F' , 'G' , 'H' , 'I' , 'J'};

    // 1. Declaração da matriz que vai representar o tabuleiro.
    int tabuleiro [10][10]; 
     
    // 2. Inicialização da matriz(10x10)com 0 em todas as posições

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = agua;
        }
    }

    // 3. Declaração dos vetores que vão representar os navios no tabuleiro

    int navio1[3] = {3 , 3 , 3};

    int navio2[3] = {3 , 3 , 3}; 


    // 4. Posicionando o navio 1 de forma horizontal no tabuleiro

    int posicao = 0;

    //Declaração das variáveis que vão definir as coordenadas inicias do navio 1 

    int linha_navio1 = 2;
    int coluna_navio1 = 5;
    int coluna_final = 8;


    if((linha_navio1 >= 0 && linha_navio1 <= 10) && (coluna_navio1 >= 0 && coluna_final <= 10)){ // Verificação se o navio esta nos limites do tabuleiro
       
        
        for(int i = 0; i < 10; i++){ // Loop para percorrer todo o tabuleiro

            for(int j = 0; j < 10; j++){

                if(i == linha_navio1 && j >= coluna_navio1 && j < coluna_final){ // Coordenadas do navio 1 
                        
                    if (tabuleiro[linha_navio1][j] != 0) { // Verifica se ja tem um navio na posição. Se tiver , exibi a mensagem e encerra o programa 
                        printf("Erro ! Navio encontrado na posição [%d][%d] do tabuleiro.", linha_navio1 , j);

                        return 1;

                    }else{

                        tabuleiro[linha_navio1][j] = navio1[posicao]; // Copiando valor do vetor para a posição do navio no tabuleiro
                        
                        posicao++;
                    }
                        
                    }
            
            }
        }
         
    }else{
          printf("Erro ! Navio 1 ultrapassou os limites do tabuleiro !\n");

          return 1;
    }


    // 5. Posicionando o navio 2 de forma vertical no tabuleiro
    
    posicao = 0;

    // Declação das variaveis que vão definir a posição do navio 2 

    int linha_navio2 = 5;
    int coluna_navio2 = 7;
    int coluna_final2 = 8;

    if((linha_navio2 >= 0 && linha_navio2 <= 10) && (coluna_navio2 >= 0 && coluna_final2 <= 10)){ // Verificaçao se o navio esta no limite do tabuleiro

        for(int i = 0; i < 10; i++){ // loop para percorrer todo tabuleiro

            for(int j = 0; j < 10; j++){

                if(j == coluna_navio2 && i >= linha_navio2 && i < coluna_final2){

                    if(tabuleiro[i][coluna_navio2] != 0 ){ // Verifica se ja tem um navio na posição. Se tiver exibi a mensagem e encerra o programa.
                        printf("Erro ! Navio encontrado na posição [%d][%d] do tabuleiro.\n" , i , coluna_navio2);
                        return 1;

                    }else{
                        // explicar o pq nao coloquei a verificação de if posiçao < 3
                         tabuleiro[i][coluna_navio2] = navio2[posicao]; // Copiando valor do vetor para a posição do navio no tabuleiro

                         posicao++;
                    }
                }
            }
        }

    }else{
        printf("Erro ! Navio 2 ultrapassou os limites do tabuleiro.\n");
        return 1;
    }


    // 6.Exibindo tabuleiro

    printf(" ==== TABULEIRO BATALHA NAVAL ==== \n");
    printf("\n");

    printf("  "); // Espaço para alinhamento estetico das colunas no tabuleiro

    for(int i = 0; i < 10; i++){
        printf(" %c " , coluna[i]); // Exibindo letras que representam as colunas
    }
    printf("\n");

    
    for(int i = 0; i < 10; i++){
            printf("%2d " , i + 1); // Para representar a numeração das linhas na tabela 
        for(int j = 0; j < 10; j++){
            printf("%ds ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}



    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0