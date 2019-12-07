void print(){
    for(int i = 0; i < 3; i++){
        printf("      ");
        for(int j = 0; j < 3; j++)
            printf("%c ", cube[4][i][j]);
        putchar('\n');
    }
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 4; i++){
            for(int k = 0; k < 3; k++)
                printf("%c ", cube[i][j][k]);
        }
        putchar('\n');
    }
    for(int i = 0; i < 3; i++){
        printf("      ");
        for(int j = 0; j < 3; j++)
            printf("%c ", cube[5][i][j]);
        putchar('\n');
    }
}

