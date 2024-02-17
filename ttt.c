#include <stdio.h>

int moves[2][2][5];
char output;
int whoseturn = 0;
int turnnum = 0;
int debug = 1;
int win = 0;

void getmove(){
  int r;
  int c;
  printf("Player %d:\n", (whoseturn+1));
  scanf("%d %d", &r, &c);
  moves[whoseturn][0][turnnum] = r; //0 = row
  moves[whoseturn][1][turnnum] = c; //1 = col  
  
  printf("Player %d entered %d %d.\n", (whoseturn+1), r, c);
  if (whoseturn == 1){turnnum++;}
  switch (whoseturn){
  case 0:
    whoseturn = 1; break;
  case 1:
    whoseturn = 0; break;
  }

  if(debug == 1){
    printf("entering debug\n");
    int i; int j; int k;
    for (i=0; i<2; i++){
      for(j=0; j<2; j++){
	      for(k=0; k<5; k++){
	        printf("%d ", moves[i][j][k]);
	      }
	    printf("\n");
      }
    printf("\n");
    }
    printf("\n");
  }
  
  return;
}

///////////////

int checkforwin(){
    if(debug == 1){
    printf("entering debug\n");
    int i; int j; int k;
    for (i=0; i<2; i++){
      for(j=0; j<2; j++){
	      for(k=0; k<5; k++){
	        int checkarray[4];
          checkarray[moves[i][j][k] + 1] += 1;
          if (checkarray[moves[i][j][k] + 1] == 2){
            return i;
          }
	      }
	    printf("\n");
      }
    printf("\n");
    }
    printf("\n");
  }
  getmove();
  return 5;
}

///////////////

int main(){
  printf("Output Play (y/n):\n");
  scanf("%c", &output);
  printf("\nYou entered %c.",output);
  printf("\nStarting game with 3 x 3 board.\nEach player should enter\na row and col num (eg: 2 0).\n");
  while (win == 5){
    win = checkforwin();
  }
  
}
