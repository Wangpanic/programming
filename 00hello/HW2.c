#include <stdio.h>


int can(int color ,int x, int y, int chess[8][8]) {
    int an_color = 3-color;
    for(int i = -1; i <= 1; i ++) {
        for(int j = -1; j <= 1; j ++) {
            if(x+i < 8 && x+i >= 0 && y+j < 8 && y+j >= 0 && chess[x+i][y+j] == an_color) {
                int cx = x+i, cy = y+j;
                while(cx < 8 && cx >= 0 && cy < 8 && cy >= 0) {
                    if(chess[cx][cy] == 0)
                        break;
                    if(chess[cx][cy] == color)
                        return 1;
                    cx = cx+i;
                    cy = cy+j;
                }
           }
        }
    }
    return 0;
}

int main(){
    int x, y;
    int chess[8][8];
    for(int i = 0; i < 8; i ++)
        for(int j = 0; j < 8; j ++)
            scanf("%d" , &chess[i][j]);
    scanf("%d %d", &x, &y);
    
    for(int i = -1; i <= 1; i ++) {
        for(int j = -1; j <= 1; j ++) {
            if((x+j) >= 0 && (y+i) >= 0 && (y+i) < 8 && (x+j) < 8) {
                if(chess[x+i][y+j] == 0 && can(chess[x][y] ,x+i, y+j, chess) == 1)
                    printf("(%d %d) ", x+i, y+j);
            }
        }
    }
    return 0;
}