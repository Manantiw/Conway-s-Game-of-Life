#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "life.h"


int alivecount=0;
int deadcount=0;
int c=0;

void ncc(char arr[2][GRIDY+2][GRIDX+2], int i, int j) //counting alive and dead neighbours of a[0][i][j]
{
    
    if(arr[c][i][j]==LIVE)
        {
            alivecount = -1;
        }
    if(arr[c][i][j]==DEAD)
        {
             deadcount = -1;
        }

    for (int x=i-1;x<i+2;x++)
        {
            for(int y=j-1;y<j+2;y++)
                {
                    if (arr [c][x][y] == DEAD)
                        {
                             deadcount = deadcount + 1;
                        }
                    if( arr [c][x][y]== LIVE)
                        {
                             alivecount = alivecount  + 1;
                        }
                }
        }
}


int main(int argc, char *argv[])
{

    char grids [2][GRIDY+2][GRIDX+2];
    int gen = atoi(argv[2]);
    if (argc>3 || argc<=2)

        {
           printf("Invalid number of Arguments\n");
            exit(1);

        }

    if(argc==3)
        {
            char ** grid;
            grid=parse_life(argv[1]);  // isn't grid[][] being returned from parse_life
            for(int i=1;i<GRIDY+1;i++)
                {
                    for(int j=1; j<GRIDX+1;j++)
                        {
                            grids [0][i][j] = grid [i-1][j-1];
                            //  grids[1][i][j] = grid[i-1][j-1];
                        }
                }

            for (int j=0; j<=GRIDX+1; j++)  // setting horizontal boundary dead
                {
                    grids[0][0][j] = DEAD;
                    grids[0][GRIDY+1][j]= DEAD;
                    grids[1][GRIDY+1][j]= DEAD;
                    grids[1][0][j]= DEAD;
                }

            for (int i=0; i<=GRIDY+1;i++) //setting vertical boundary dead
                {
                    grids[0][i][0]= DEAD;
                    grids[0][i][GRIDX+1]= DEAD;
                    grids[1][i][0]= DEAD;
                    grids[1][i][GRIDX+1]= DEAD;
                }
        }


    for(int h=0;h<gen;h++)
        {
            for (int i=1; i<GRIDY+1; i++)
                {
                    for (int j=1; j<GRIDX+1; j++)
                        {
                            ncc(grids, i, j);
                            int check = 1;
                            if (grids [c][i][j] == LIVE && (alivecount==2 || alivecount==3))
                                {
                                    grids [(c+1)%2][i][j] = LIVE;
                                    check=0;
                                }
                            if (grids [c][i][j] == LIVE && (alivecount<2))
                                {
                                    grids [(c+1)%2][i][j] = DEAD;
                                      check=0;
                                }
                            if (grids [c][i][j] == LIVE && (alivecount>3))
                                {
                                    grids [(c+1)%2][i][j]=DEAD;
                                      check=0;
                                }
                            if (grids [c][i][j] == DEAD && (alivecount==3))
                                {
                                    grids [(c+1)%2][i][j] = LIVE;
                                      check=0;
                                }
                            if(check) {
                                 grids [(c+1)%2][i][j] = grids[c][i][j];
                            }
                            // grids [(c+1)%2][i][j] = grids [0][i][j];
                            alivecount=0;
                            deadcount=0;
                        }
                }
            c=(c+1)%2;
        }


    for (int i=1;i<GRIDY+1;i++)
        {
            for(int j=1; j<GRIDX+1;j++)
                {
                    putchar(grids[c][i][j]);
                }
             printf("\n");
        }

    return 0;
}






