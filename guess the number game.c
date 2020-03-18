#include<stdio.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
typedef struct{
    int q;
    int steps;
    int input;
}player ;
int RoundCheck(player *p,int x) {
    p->steps=0;  p->q=10;
    while(p->q !=0) {
        printf("enter you number:\n-");
        scanf("%d",&p->input);
        if (x < p->input) {
            printf("too great\n");
            p->q-=1;
            p->steps++; }
        else {
            if (x > p->input ){
                printf("too small\n");
                p->q-=1;
                p->steps++;}
            else {printf("\n***good job player!****\n");
                break;  }}
    }}

int winner(player p1,player p2){
    if (p1.q==0 && p2.q ==0) return 0;
    else {
        if (p1.steps>p2.steps){ return 2;}
        else {
            if (p1.steps < p2.steps) return 1;
            else  return 0;
        }
    }}

int RamdomNum() {
    return ( (rand()%100 ) +1);
}
int main () {
    int rounds,x ;
    player player1;
    player player2;
    printf("welcome to the game!\n how many rounds you want to play ?\n -");
    scanf("%d",&rounds);

    srand(time(NULL));
    while(rounds != 0 ) {
        printf("\n*******ROUND %d ******\n",rounds);
        x=RamdomNum();
        printf("\nplayers` 1 turn :");
        RoundCheck(&player1,x);
        printf("\nplayers` 2 turn :");
        x=RamdomNum();
        RoundCheck(&player2,x);
        if( winner(player1, player2)==1 ) printf("the winner of this round is player 1!");
        else  {if (winner(player1, player2)==2 ) printf("the winner of this round is player 2 !");
            else printf("It was a tie !");
        }
        rounds -= 1;
    }
    printf("thanks for playing my game !!");
    return 0;
}
