#include <stdio.h>
#include <unistd.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


//#define TAM_TAB 10;

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
    int coluna_navio1 = 4;
    int final_navio1 = 7;

    //Condição para verificar se o navio esta dentro dos limites do tabuleiro

    if((linha_navio1 >= 0 && linha_navio1 <= 10) && (coluna_navio1 >= 0 && final_navio1 <= 10)){ 
       
        
        for(int i = 0; i < 10; i++){ // Loop para percorrer todas as linhas

            for(int j = 0; j < 10; j++){ // Loop para percorrer todas as colunas

                if(i == linha_navio1 && j >= coluna_navio1 && j < final_navio1){ // Condição para verificar a coordenadas do navio 1
                        
                    if (tabuleiro[linha_navio1][j] != 0) { // Verifica se ja tem um navio na posição. Se tiver , exibi a mensagem e encerra o programa 
                        printf("Erro ! Navio encontrado na posição [%d][%d] do tabuleiro.", linha_navio1 , j);

                        return 1;

                    }else{

                        if(posicao < 3) {  //Condição para garantir que o tamanho do navio vai ser respeitado

                        tabuleiro[linha_navio1][j] = navio1[posicao]; // Copiando valor do vetor para a posição do navio no tabuleiro
                    
                        posicao++;

                        }
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
    int final_navio2 = 8;

    //Condição para verificar se o navio esta dentro dos limites do tabuleiro
    if((linha_navio2 >= 0 && linha_navio2 <= 10) && (coluna_navio2 >= 0 && final_navio2 <= 10)){ 

        for(int i = 0; i < 10; i++){ // Loop para percorrer todas as linhas

            for(int j = 0; j < 10; j++){ // Loop para percorrer todas as colunas

                if(j == coluna_navio2 && i >= linha_navio2 && i < final_navio2){ // Condição para verificar a coordenadas do navio 2

                    if(tabuleiro[i][coluna_navio2] != 0 ){ // Verifica se ja tem um navio na posição. Se tiver exibi a mensagem e encerra o programa.
                        printf("Erro ! Navio encontrado na posição [%d][%d] do tabuleiro.\n" , i , coluna_navio2);
                        return 1;

                    }else{

                        if(posicao < 3) {  // Condição para garantir que o tamanho do navio vai ser respeitado.
                        
                         tabuleiro[i][coluna_navio2] = navio2[posicao]; // Copiando valor do vetor para a posição do navio no tabuleiro

                         posicao++;

                        }
                    }
                }
            }
        }

    }else{
        printf("Erro ! Navio 2 ultrapassou os limites do tabuleiro.\n");
        return 1;
    }


    //6. Posicionando navio 3 na diagonal princial

    int navio3[3] = {3 , 3, 3};

    //Declaração das variáveis que vão definir as coordenadas inicias do navio 3

    int linha_navio3  = 1;
    int linha_final3  = 4;  
    int coluna_navio3 = 1;
    int coluna_final3 = 4; 

    posicao = 0;

    //Condição para verificar se o navio esta dentro dos limites do tabuleiro

    if((linha_navio3 >= 0 && linha_navio3 <= 10) && (coluna_navio3 >= 0 && coluna_final3 <= 10)){ 
        
        for(int i = 0; i < 10; i++){ // Loop para percorrer todas as linhas

            for(int j = 0; j < 10; j++){ // Loop para percorrer todas as colunas

                if((i >= linha_navio3 && i < linha_final3) && (j >= coluna_navio3 && j < coluna_final3)){ // Condição para verificar a coordenadas do navio 3

                     if(tabuleiro[i][j] != 0){ // Verifica se ja tem um navio na posição. Se tiver exibi a mensagem e encerra o programa.

                        printf("Erro ! Navio encontrado na posição [%d][%d] do tabuleiro." , i , j);
                        return 1;

                    }else{

                        if(i == j && posicao < 3){  //Condição para verificar se i e j são iguais e se o tamanho do navio esta sendo respeitado

                            tabuleiro[i][j] = navio3[posicao]; // Copiando valor do vetor para a posição do navio no tabuleiro

                            posicao++;
                    
                        }
                     }

                }
               
            }
        }

    }


    // 7. Posicionando navio 4 na diagonal segundaria 
    
    posicao = 0;

    int navio4[3] = {3, 3, 3};

    //Declaração das variáveis que vão definir as coordenadas inicias do navio 4

    int linha_navio4 = 6;
    int final_linha4 = 9; 
    int coluna_navio4 = 1;
    int final_coluna4 = 4; 


    //Condição para verificar se o navio esta dentro dos limites do tabuleiro

    if((linha_navio4 >= 0 && final_linha4 <= 10) && (coluna_navio4 >= 0 && final_coluna4 <= 10)){ 

        for(int i = 0; i < 10; i++){ // Loop para percorrer todas as linhas

            for(int j = 0; j < 10; j++){ // Loop para percorrer todas as colunas
                
                if((i >= linha_navio4 && i < final_linha4) && (j >= coluna_navio4 && j < final_coluna4)){  // Condição para verificar a coordenadas do navio 4
                
                    if(tabuleiro[i][j] != 0) { // Verifica se ja tem um navio na posição. Se tiver exibi a mensagem e encerra o programa.
                        
                        printf("Erro ! Navio encontrado na posição [%d][%d] do tabuleiro" , i , j);
                        return 1;

                    }else{

                        if((i + j == 9) && (posicao < 3)){ // Condição para verificar se a soma dos indices i e j são igual a 9 , e se o tamanho do navio esta sendo respeitado

                            tabuleiro[i][j] = navio4[posicao]; // Copiando o valor do vetor para a posição do navio no tabuleiro
                            posicao++;

                        }
                        
                    }

                }

            }
        }
    }


    printf("\n");

    // 6.Exibindo tabuleiro

    printf(" ==== TABULEIRO BATALHA NAVAL ==== \n");
    printf("\n");

    printf("   "); // Espaço para alinhamento estetico das colunas no tabuleiro

    for(int i = 0; i < 10; i++){
        printf(" %c " , coluna[i]); // Exibindo letras que representam as colunas
    }
    printf("\n");

    
    for(int i = 0; i < 10; i++){
            printf("%2d " , i + 1); // Para representar a numeração das linhas na tabela 
        for(int j = 0; j < 10; j++){
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    printf("\n\n");

    // Declaração das variaveis para escolha e origem de linha e coluna

    int escolha;
    int origem_l;
    int origem_c;

    // Declaração das matrizes de ataques

    int ataque_cone[10][10] = {agua};
    int ataque_cruz[10][10] = {agua};
    int ataque_octaedro[10][10] = {agua};

    //Loop 
    do{
        
        
        
    printf("\n");

    printf("==== MENU DE ESCOLHA ==== \n");

    printf("Ataques: \n");
    printf("[1] Cone \n");
    printf("[2] Cruz \n");
    printf("[3] Octaedro \n");
    printf("[4] Sair \n");

    printf("Escolha o ataque: ");
    scanf("%d" , &escolha);
    


    //Switch para escolher um ataque
    
    switch (escolha)
    {
    case 1:

        //ataque cone
    

        origem_l = 2;  origem_c = 3;


        for (int i = 0 ; i < 3; i++){   // loop para adicionar as posições do cone na matriz ataque cone
            for(int j = -i; j <= i; j++){
                int l = origem_l + i;
                int c = origem_c + j;
                if((l >= 0 && l < 10) && (c >= 0 && c < 10)){
                    ataque_cone[l][c] = 1;
                
            }
        }
    }

        break;

    case 2:

        //ataque cruz 
        

        origem_l = 7; origem_c = 6;

        for(int i = -2; i <= 2 ; i++){ // loop para adicionar as posições da cruz na matriz ataque ataque cruz 
            int l = origem_l + i;
            int c = origem_c + i; 
            if((origem_l >= 0 && origem_l < 10) && (c >= 0 && c < 10)){
                ataque_cruz[origem_l][c] = 2;
            }
            if((l >= 0 && l < 10) && (origem_c >= 0 && origem_c < 10)){
                ataque_cruz[l][origem_c] = 2;
            }
        }

        break;




    case 3:
 

        origem_l = 2; origem_c = 7;
        
        for(int i = -2; i <= 2; i++){ // loop para adicionar as posições do octaedro na matriz ataque octaedro
            for(int j = -2 ; j <= 2; j++){
                int l = origem_l + i;
                int c = origem_c + j;
                if((l == 0 && c == 7) || (l == 1 && c >= 6 && c < 9) || (l == 2 && c >= 5 && c < 10) || (l == 3 && c >= 6 && c < 9) || (l == 4 && c == 7)){// e assim por diante //
            
                    if((l >= 0 && l < 10) && (c >= 0 && c < 10))
                        ataque_octaedro[l][c] = 5;
                }
            }
        }

        break;
    
    case 4:
        printf("Saindo...");
        sleep(1);
        printf("Programa Finalizado");
        

        return 1;

    default:
        printf("\n");
        printf("Opção inválida ! \n");

        break;
    }



    //SOPREPOSIÇÃO TABULEIRO

    for(int i = 0; i < 10; i++){

        for(int j = 0; j < 10; j++){
            if(ataque_cone[i][j] != 0){

                tabuleiro[i][j] = ataque_cone[i][j];
            }
            else if (ataque_cruz[i][j] != 0){
                tabuleiro[i][j] = ataque_cruz[i][j];
            }
            else if(ataque_octaedro[i][j] != 0){
                tabuleiro[i][j] = ataque_octaedro[i][j];
            }
    
        }
    }

    //Exibição do tabuleiro apos ataque

    printf("\n\n");

    printf("==== TABULEIRO APOS OS ATAQUES ==== \n");
    
    printf("\n");

    printf("   ");

    for(int i = 0; i < 10; i++){
            printf(" %c ", coluna[i]);
        }

    printf("\n");

    for(int i = 0; i < 10; i++){
            printf("%2d " , i + 1);
        for(int j = 0; j < 10; j++){
           if((tabuleiro[i][j] != 0) && (tabuleiro[i][j] != 3)){
                printf(" * ");

           }else{
                printf(" %d " , tabuleiro[i][j]);
           }
        }
        printf("\n");
    }



    } while (escolha != 4);
    

    //Comentar codigo 

    return 0;
}
