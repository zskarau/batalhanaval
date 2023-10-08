#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20    

int main(){
    int i, j, letra;
    int pos_X, pos_Y;
    int pos[10][2],dir;
    int mat[N][N] = {0};

    srand(time((NULL)));
    printf("\n");
    printf("   "); //Centralizando
    for(letra = 'A'; letra <= 'T'; letra++){ //Letras acima das Colunas
        printf("%c  ", letra);
    }
    printf("\n");

    //Randomizações das Posições:

        //Boias
        for(i=0;i<10;i++){
            do{
                pos_X = rand() % N;
                pos_Y = rand() % N;
            }while(mat[pos_Y][pos_X] == 1); 
            mat[pos_Y][pos_X] = 1; 
        }

        //Aviões
        for(i=0;i<5;i++){
            dir=rand()%4;
            while(1){
                pos_X=rand()%N;
                pos_Y=rand()%N;

            switch (dir){
            case 0: pos[0][0]=pos_Y;pos[0][1]=pos_X;
                    pos[1][0]=pos_Y+1;pos[1][1]=pos_X;
                    pos[2][0]=pos_Y-1;pos[2][1]=pos_X;
                    pos[3][0]=pos_Y;pos[3][1]=pos_X-1;
                    
            break;

            case 1:pos[0][0]=pos_Y;pos[0][1]=pos_X;
                    pos[1][0]=pos_Y-1;pos[1][1]=pos_X;
                    pos[2][0]=pos_Y;pos[2][1]=pos_X-1;
                    pos[3][0]=pos_Y;pos[3][1]=pos_X+1;
                    
            break;

            case 2:pos[0][0]=pos_Y;pos[0][1]=pos_X;
                    pos[1][0]=pos_Y+1;pos[1][1]=pos_X;
                    pos[2][0]=pos_Y-1;pos[2][1]=pos_X;
                    pos[3][0]=pos_Y;pos[3][1]=pos_X+1;
                   
            break;

            case 3: pos[0][0]=pos_Y;pos[0][1]=pos_X;
                    pos[1][0]=pos_Y+1;pos[1][1]=pos_X;
                    pos[2][0]=pos_Y;pos[2][1]=pos_X-1;
                    pos[3][0]=pos_Y;pos[3][1]=pos_X+1;
                    
            break;
            default:
                break;
            }
            if(pos_X + 2 > N || pos_Y + 2 > N || pos_X - 2 < 0 || pos_Y - 2 < 0){
                continue;
            }
            if(mat[pos[0][0]][pos[0][1]] == 0 && mat[pos[1][0]][pos[1][1]] == 0 && mat[pos[2][0]][pos[2][1]] == 0 && mat[pos[3][0]][pos[3][1]] == 0){
                break;
            }
        }
            mat[pos[0][0]][pos[0][1]] = 2;
            mat[pos[1][0]][pos[1][1]] = 2;
            mat[pos[2][0]][pos[2][1]] = 2;
            mat[pos[3][0]][pos[3][1]] = 2;
        }
        //Submarinos
        for(i=0; i<5; i++){
            dir = rand () % 2;
            while(1){
                pos_X=rand()%N;
                pos_Y=rand()%N;
            switch(dir){
                case 0: pos[0][0]=pos_Y;pos[0][1]=pos_X;
                    pos[1][0]=pos_Y;pos[1][1]=pos_X + 1;
                    pos[2][0]=pos_Y;pos[2][1]=pos_X - 1;
                    pos[3][0]=pos_Y;pos[3][1]=pos_X + 2;
                    
                break;
                case 1: pos[0][0]=pos_Y;pos[0][1]=pos_X;
                    pos[1][0]=pos_Y + 1;pos[1][1]=pos_X;
                    pos[2][0]=pos_Y + 2;pos[2][1]=pos_X;
                    pos[3][0]=pos_Y - 1;pos[3][1]=pos_X;
                    
                break;
            }
            if(pos_X + 3 > N || pos_Y + 3 > N || pos_X - 1 < 0 || pos_Y - 1 < 0){
                continue;
            }
            if(mat[pos[0][0]][pos[0][1]] == 0 && mat[pos[1][0]][pos[1][1]] == 0 && mat[pos[2][0]][pos[2][1]] == 0 && mat[pos[3][0]][pos[3][1]] == 0){
                break;
            }
        }
            mat[pos[0][0]][pos[0][1]] = 3;
            mat[pos[1][0]][pos[1][1]] = 3;
            mat[pos[2][0]][pos[2][1]] = 3;
            mat[pos[3][0]][pos[3][1]] = 3;
        }
        //Espiões 1
        for(i=0; i<4; i++){
            dir = rand () % 4;
            while(1){
                pos_X = rand() % N;
                pos_Y = rand() % N;
                switch(dir){
                    case 0: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X + 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X + 2;
                        pos[3][0]=pos_Y; pos[3][1]=pos_X + 3;
                        pos[4][0]=pos_Y + 1; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y - 1; pos[5][1]=pos_X;

                    break;
                    case 1: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X + 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X - 1;
                        pos[3][0]=pos_Y + 1; pos[3][1]=pos_X;
                        pos[4][0]=pos_Y + 2; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y + 3; pos[5][1]=pos_X;

                    break;
                    case 2: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X - 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X - 2;
                        pos[3][0]=pos_Y; pos[3][1]=pos_X - 3;
                        pos[4][0]=pos_Y + 1; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y - 1; pos[5][1]=pos_X;
                    
                    break;
                    case 3:  pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X - 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X + 1;
                        pos[3][0]=pos_Y - 1; pos[3][1]=pos_X;
                        pos[4][0]=pos_Y - 2; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y - 3; pos[5][1]=pos_X;
                    default:
                    break;
                }
                if(pos_X + 4 > N || pos_Y + 4 > N || pos_X - 3 < 0 || pos_Y - 3 < 0){
                continue;
            }
                if(mat[pos[0][0]][pos[0][1]] == 0 && mat[pos[1][0]][pos[1][1]] == 0 && mat[pos[2][0]][pos[2][1]] == 0 && mat[pos[3][0]][pos[3][1]] == 0 && mat[pos[4][0]][pos[4][1]] == 0 && mat[pos[5][0]][pos[5][1]] == 0){
                break;
            }
        }
            mat[pos[0][0]][pos[0][1]] = 4;
            mat[pos[1][0]][pos[1][1]] = 4;
            mat[pos[2][0]][pos[2][1]] = 4;
            mat[pos[3][0]][pos[3][1]] = 4;
            mat[pos[4][0]][pos[4][1]] = 4;
            mat[pos[5][0]][pos[5][1]] = 4;

        }
        //Espiões 2
        for(i=0; i<4; i++){
            dir = rand () % 4;
            while(1){
                pos_X = rand() % N;
                pos_Y = rand() % N;
                switch(dir){
                    case 0: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X + 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X + 2;
                        pos[3][0]=pos_Y; pos[3][1]=pos_X + 3;
                        pos[4][0]=pos_Y + 1; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y - 1; pos[5][1]=pos_X;

                    break;
                    case 1: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X + 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X - 1;
                        pos[3][0]=pos_Y + 1; pos[3][1]=pos_X;
                        pos[4][0]=pos_Y + 2; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y + 3; pos[5][1]=pos_X;

                    break;
                    case 2: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X - 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X - 2;
                        pos[3][0]=pos_Y; pos[3][1]=pos_X - 3;
                        pos[4][0]=pos_Y + 1; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y - 1; pos[5][1]=pos_X;
                    
                    break;
                    case 3:  pos[0][0]=pos_Y; pos[0][1]=pos_X;
                        pos[1][0]=pos_Y; pos[1][1]=pos_X - 1;
                        pos[2][0]=pos_Y; pos[2][1]=pos_X + 1;
                        pos[3][0]=pos_Y - 1; pos[3][1]=pos_X;
                        pos[4][0]=pos_Y - 2; pos[4][1]=pos_X;
                        pos[5][0]=pos_Y - 3; pos[5][1]=pos_X;
                    default:
                    break;
                }
                if(pos_X + 4 > N || pos_Y + 4 > N || pos_X - 3 < 0 || pos_Y - 3 < 0){
                continue;
            }
                if(mat[pos[0][0]][pos[0][1]] == 0 && mat[pos[1][0]][pos[1][1]] == 0 && mat[pos[2][0]][pos[2][1]] == 0 && mat[pos[3][0]][pos[3][1]] == 0 && mat[pos[4][0]][pos[4][1]] == 0 && mat[pos[5][0]][pos[5][1]] == 0){
                break;
            }
        }
            mat[pos[0][0]][pos[0][1]] = 5;
            mat[pos[1][0]][pos[1][1]] = 5;
            mat[pos[2][0]][pos[2][1]] = 5;
            mat[pos[3][0]][pos[3][1]] = 5;
            mat[pos[4][0]][pos[4][1]] = 5;
            mat[pos[5][0]][pos[5][1]] = 5;

        }
        //Porta Aviões
        for(i=0; i<2; i++){
            dir = rand() % 2;
            while(1){
                pos_X = rand () % N;
                pos_Y = rand () % N;
                switch (dir){
                case 0: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                    pos[1][0]=pos_Y; pos[1][1]=pos_X - 1;
                    pos[2][0]=pos_Y; pos[2][1]=pos_X - 2;
                    pos[3][0]=pos_Y; pos[3][1]=pos_X + 1;
                    pos[4][0]=pos_Y; pos[4][1]=pos_X + 2;
                    pos[5][0]=pos_Y + 1; pos[5][1]=pos_X;
                    pos[6][0]=pos_Y + 1; pos[6][1]=pos_X - 1;
                    pos[7][0]=pos_Y + 1; pos[7][1]=pos_X - 2;
                    pos[8][0]=pos_Y + 1; pos[8][1]=pos_X + 1;
                    pos[9][0]=pos_Y + 1; pos[9][1]=pos_X + 2;          
                    
                    break;
                case 1: pos[0][0]=pos_Y; pos[0][1]=pos_X;
                    pos[1][0]=pos_Y - 1; pos[1][1]=pos_X;
                    pos[2][0]=pos_Y - 2; pos[2][1]=pos_X;
                    pos[3][0]=pos_Y + 1; pos[3][1]=pos_X;
                    pos[4][0]=pos_Y + 2; pos[4][1]=pos_X;
                    pos[5][0]=pos_Y; pos[5][1]=pos_X + 1;
                    pos[6][0]=pos_Y - 1; pos[6][1]=pos_X + 1;
                    pos[7][0]=pos_Y - 2; pos[7][1]=pos_X + 1;
                    pos[8][0]=pos_Y + 1; pos[8][1]=pos_X + 1;
                    pos[9][0]=pos_Y + 2; pos[9][1]=pos_X + 1;
                    
                    break;
                default:
                    break;
                }
                if(pos_X + 3 > N || pos_Y + 3 > N || pos_X - 2 < 0 || pos_Y - 2 < 0){
                    continue;
                }
                if(mat[pos[0][0]][pos[0][1]] == 0 && mat[pos[1][0]][pos[1][1]] == 0 && mat[pos[2][0]][pos[2][1]] == 0 && mat[pos[3][0]][pos[3][1]] == 0 && mat[pos[4][0]][pos[4][1]] == 0 && mat[pos[5][0]][pos[5][1]] == 0 && mat[pos[6][0]][pos[6][1]] == 0 && mat[pos[7][0]][pos[7][1]] == 0 && mat[pos[8][0]][pos[8][1]] == 0 && mat[pos[9][0]][pos[9][1]] == 0){
                    break;
                }
            }
            mat[pos[0][0]][pos[0][1]] = 6;
            mat[pos[1][0]][pos[1][1]] = 6;
            mat[pos[2][0]][pos[2][1]] = 6;
            mat[pos[3][0]][pos[3][1]] = 6;
            mat[pos[4][0]][pos[4][1]] = 6;
            mat[pos[5][0]][pos[5][1]] = 6;
            mat[pos[6][0]][pos[6][1]] = 6;
            mat[pos[7][0]][pos[7][1]] = 6;
            mat[pos[8][0]][pos[8][1]] = 6;
            mat[pos[9][0]][pos[9][1]] = 6;

        }
        for(i = 0; i < N; i++){
            if(i + 1 < 10){        
            printf("%d  ", i + 1);
        }
        else if(i + 1 >= 10){
            printf("%d ", i + 1);
        } 
            for(j = 0; j < N; j++){
                if(mat[i][j] == 0){
                    printf("%s  ", "*");
                }
                else if(mat[i][j] == 1){
                    printf("\033[31m%s  \033[0m", "0");
                }
                else if(mat[i][j] == 2){
                    printf("\033[36m%s  \033[0m", "1");
                }
                else if(mat[i][j] == 3){
                    printf("\033[33m%s  \033[0m", "2");
                }
                else if(mat[i][j] == 4){
                    printf("\033[34m%s  \033[0m", "3");
                }
                else if(mat[i][j] == 5){
                    printf("\033[35m%s  \033[0m", "4");
                }
                else if(mat[i][j] == 6){
                    printf("\033[32m%s  \033[0m", "5");
                }
            }
            printf("\n");
        }
        printf("\n");
    }