#include <stdio.h>

//funciones
int resolverSudoku(int, int);
void imprimirSudoku(void);
int mismaColumna(int, int, int);
int mismaFila(int, int, int);
int mismoCuadro(int, int, int);


//sudoku inicial
int sudoku[9][9] = {5, 3, 0,     0, 7, 0,   0, 0, 0,
                     6, 0, 0,    1, 9, 5,   0, 0, 0,
                     0, 9, 8,    0, 0, 0,   0, 6, 0,
                     8, 0, 0,    0, 6, 0,   0, 0, 3,
                     4, 0, 0,    8, 0, 3,   0, 0, 1,
                     7, 0, 0,    0, 2, 0,   0, 0, 6,
                     0, 6, 0,    0, 0, 0,   2, 8, 0,
                     0, 0, 0,    4, 1, 9,   0, 0, 5,
                     0, 0, 0,    0, 8, 0,   0, 7, 9};



int main(void){
    int x = 0, y = 0;
    imprimirSudoku();
    resolverSudoku(x,y);
    imprimirSudoku();
    return 0;
}
//función para imprimir el formato de sudoku
void imprimirSudoku(){
    printf("-------------------------------\n");
    for(int i=0;i<9;i++){
        printf("|");
        for(int j=0;j<9;j++){
            printf(" %d ",sudoku[i][j]);
            if(((j+1)%3)==0){
                printf("|");
            }
        }
        printf("\n");
        if(((i+1)%3)==0){
            printf("-------------------------------\n");
        }
    }
    printf("\n\n");
}
int resolverSudoku(int x, int y){
    int x2 = 0, y2 = 0, num = 1;
    if(sudoku[x][y]!=0){
        if(x==8 && y==8){
            return 1;
        }
        if(x<8){
            x++;
        }else{
                x=0;
                y++;
        }
        if(resolverSudoku(x,y)){
            return 1;
        }else{
            return 0;
        }
    }
    if(sudoku[x][y]==0){
        while(num<10){
            //checar si el numero no esta en las mismas posiciones
            if(!mismoCuadro(x,y,num) && !mismaFila(x,y,num) && !mismaColumna(x,y,num)){
                sudoku[x][y] = num;
                if(x==8 && y==8){
                    return 1;
                }
                //ir de cuadro por cuadro
                if(x<8){
                    x2 = x+1;
                }else{
                    if(y<8){
                        x2=0;
                        y2 = y+1;
                    }
                }
                if(resolverSudoku(x2,y2)){
                     return 1;
                }
            }
            num++;
        }
        sudoku[x][y]=0;
        return 0;
    }
}
//función para checar la columna y que no se repitan números
int mismaColumna(int x,int y ,int num){
    for(int i=0;i<9;i++){
        if(sudoku[x][i]==num){ //si encuentra un número devolver verdadero
            return 1;
        }
    }
    return 0;
}
//función para checar la fila y que no se repitan números
int mismaFila(int x, int y, int num){
    for(int i=0;i<9;i++){
        if(sudoku[i][y]==num){
            return 1;
        }
    }
    return 0;
}
//función para checar cuadro por cuadro
int mismoCuadro(int x, int y, int num){
    if(x<3){
        x = 0;
    }else if(x<6){
        x = 3;
    }else{
        x = 6;
    }
    if(y<3){
        y = 0;
    }else if(y<6){
        y = 3;
    }else{
        y = 6;
    }
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(sudoku[i][j] == num){
                return 1;
            }
        }
    }
    return 0;
}