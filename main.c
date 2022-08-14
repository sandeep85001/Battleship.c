#include <stdio.h>
#include <stdlib.h>

//functions to display board
int boardshow();
int boardshow2(char board1[10][10],char board2[10][10]);

//global variables
int x,y,shipguess;
int p,q;
int r,s;
int pl,ql;
int rl,sl;
int xl,yl;

//functions to print instructions
void instructions1();
void instructions2();

//function to convert rown no. and column no. to a single number
int guess(int r,int c);

//function to randomly place ships
void carry(int *ships,int *carrier,int *array);
void batshp(int *ships,int *b,int count,int *array,int ind);
void crui(int *ships,int *b,int count,int *array,int ind);
void des(int *ships,int *b,int count,int *array,int ind);

//function to print MISS
void miss();

//function to print HIT
void hit();

//function to let user guess
int userguess(char *board,int ships[30],int *trial,int tri);

//  CARRIER      : _ _ _ _ _ :5 :1   : 0-4
//  BATTLESHIP   : _ _ _ _   :4 :2   : 5-8    : 9-12
//  CRUISER      : _ _ _     :3 :2   : 13-15  : 16-18
//  SUBMARINE    : _ _ _     :3 :1   : 19-21
//  DESTROYER    : _ _       :2 :4   : 22-23  : 24-25  : 26-27 : 28-29
//                           :30:10

struct ba{
    int bat[4];
};
struct ba bat1,bat2;

struct cru{
    int cruis[3];


};
struct cru crui1,crui2,subm;


struct dest{
    int destr[2];


};
struct dest dest1,dest2,dest3,dest4;


int main()
{
     int i,j,k,mode,fle=0;
     int array[10];
     int trial[100];
     int tri=0;
     int trial1[100];
     int tri1=0;
     int trial2[100];
     int tri2=0;
     int count=5,hits=-1,misss=-1;
     int win=0,tries=-1;
     int n=4,m=1,ind=1;
     int ships[30];
     int carrier[5];
     printf("============================================================================================\n");
     for(i=1;i<=n-1;i++){
        for(j=1;j<=i;j++)
            {
                printf(" *");
            }
            printf("\n");
     }
     printf(" * * * *                             BATTLESHIP GAME\n");
     for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf(" *");
        }
        printf("\n");
    }
    printf("============================================================================================\n");
    //battleship design in C
printf("\n                             |                                                     ");
printf("\n                             |                                                                  ");
printf("\n                    |        |                                                   ");
printf("\n                  |-|-|      |                                                   ");
printf("\n                    |        |                                                   ");
printf("\n                    |  O     |                                                   ");
printf("\n                    '--|     |                                                   ");
printf("\n                      .|]_   |                                                   ");
printf("\n                _.-=.' |     |                                                   ");
printf("\n               |    |  |]_   |                                                   ");
printf("\n               |.-='  |   _|__                                                   ");
printf("\n                _.-='  |\   /|\                                                   ");
printf("\n               |    |  |-'-'-'-'-.                                                   ");
printf("\n               |_.-='  '========='                                                   ");
printf("\n                    `   |     |                                                   ");
printf("\n                     `. |    / \                                                   ");
printf("\n                       ||   /   \__.--=''''==--.._                                                   ");
printf("\n                       ||.'--=='    |_  _  _  _.'                                                   ");
printf("\n                       ||  |    |    |\ ||  ||  || |                        _                                                   ");
printf("\n          __         ||_|_|_| \||||||/    ______/|   |                                                   ");
printf("\n         |    |__  |===.---. .---.========''''=-._ |     |     |     / |  |                                                   ");
printf("\n         |    ||     |\| |||   | |   |      '===' ||  \|__|_|_/_|__|                                                   ");
printf("\n         |-..||_|\__'---' '---'___....---===''=======================|                                                   ");
printf("\n         |--------------\------------------/------------------------------------/                                                   ");
printf("\n         |               \                /                                                                    ");
printf("\n         |                \______/                                    /                                                   ");
printf("\n         |                                                                  /                                                   ");
printf("\n         |=================================================================/                                                   ");
printf("\n         '----------------------------------------------------------------`                               ");
printf("\n     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
printf("\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");;
printf("\n     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    //creation of 3 boards of character type
    char board[10][10];
    int choice=1;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            board[i][j]='~';
        }
    }
    char board1[10][10];
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            board1[i][j]='~';
        }
    }
    char board2[10][10];
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            board2[i][j]='~';
        }
    }
    //menu driven code
    while(choice==1){
    printf("\n\n\n");
    printf("                There are 2 gameplay modes:");
    printf("\n");
    printf("\n                        1. Multi Player Mode : Player 1 vs Player 2.");
    printf("\n                        2. Single Player Mode : User vs Computer.");
    printf("\n\n\n");
    printf("Enter gameplay mode (1/2) :");
    scanf("%d",&mode);
    printf("\n\n\n");
    int win1=0;
    int win2=0;
    int ships1[30];
    int count1=0;
    int ships2[30];
    int x=0,y=0;
    int flag1=0;
    int flag2=0;
    int count2=0;
    int flare=0;
    int hits1=-1,tries1=-1,misss1=-1,hits2=-1,tries2=-1,misss2=-1;
    if(mode==1){
        boardshow2(board1,board2);
        instructions1();
        printf("\n PLAYER-2 :");
        printf("Enter positions to place boats");
        //player 2 placing boats for player 1 to guess
        for(i=0;i<20;){
                do {
        printf("\n Row Number [1 - 10]:");
        scanf("\n%d",&pl);
            }while(pl<1 || pl>10);
            do {
        printf("\n Column Number:");
        scanf("%d",&ql);
        }while(ql<1 || ql>10);
            n=guess(pl,ql);
            if(count1==0){
                ships1[0]=n;
                count1++;
            }
            else{
                    //check if value is a duplicate
                for(i=0;i<count1;i++){
                    if(n==ships1[i]){
                            flag1=1;
                    }
                    else{
                    }
                }
                if(flag1==1){
                    printf("\nCant enter already chosen box");
                }
                else{
                    ships1[i]=n;
                    i++;
                    count1++;
                }
                flag1=0;

            }

        }
        for(i=0;i<20;i++){
            printf("%d:",ships1[i]);
        }
        //player 1 placing boats for player 2 to guess
        printf("\n PLAYER-1 :");
        printf("\nEnter positions to place boats");
        for(i=0;i<20;){
                do {
        printf("\n Row Number [1 - 10]:");
        scanf("\n%d",&rl);
            }while(rl<1 || rl>10);
            do {
        printf("\n Column Number:");
        scanf("%d",&sl);
        }while(sl<1 || sl>10);
            n=guess(rl,sl);
            if(count2==0){
                ships2[0]=n;
                count2++;
            }
            else{
                    //check if value is a duplicate
                for(i=0;i<count2;i++){
                    if(n==ships2[i]){
                            flag2=1;
                    }
                    else{
                    }
                }
                if(flag2==1){
                    printf("\nCant enter already chosen box");
                }
                else{
                    ships2[i]=n;
                    i++;
                    count2++;
                }
                flag2=0;

            }

        }
        for(i=0;i<20;i++){
            printf("%d:",ships2[i]);
        }

        while(win1!=20 || win2!=20){
            tries1++;
            //player 1 turn
            fle=userguess1(board1,ships1,trial1,tri1);
            printf("x:%d",p);
            printf("y:%d",q);
            if(fle==1){
                win1++;
                hits1++;
                board1[p-1][q-1]='X';
                boardshow2(board1,board2);
            }
            else{
                misss1++;
                board1[p-1][q-1]='O';
                boardshow2(board1,board2);
            }
            tri1++;
            if(win1==20){
                flare=1;
                break;
            }

            tries2++;
            //player 2 turn
            fle=userguess2(board2,ships2,trial2,tri2);
            printf("x:%d",r);
            printf("y:%d",s);
            if(fle==1){
                win2++;
                hits2++;
                board2[r-1][s-1]='X';
                boardshow2(board1,board2);
            }
            else{
                misss2++;
                board2[r-1][s-1]='O';
                boardshow2(board1,board2);
            }
            tri2++;
            if(win2==20){
                flare=0;
                break;
            }

    }
    if(flare==1){
        printf("\n\nPLAYER 1 WINS!!");
    }
    else{
        printf("\n\nPLAYER 2 WINS!!");
    }
    //game report
        printf("\n     GAME OVER !  ^_^");
        printf("\n\n  Player - 1 ");
        printf("\n\n total number of tries  o   : %d",tries1+1);
        printf("\n\n total number of hits  ^_^   : %d",hits1+1);
        printf("\n\n total number of misses  o   : %d",misss1+1);
        printf("\n\n  Player - 2 ");
        printf("\n\n total number of tries  o   : %d",tries2+1);
        printf("\n\n total number of hits  ^_^   : %d",hits2+1);
        printf("\n\n total number of misses  o   : %d",misss2+1);

    }

    else{
        printf("    ");
        instructions2();
        //functions to place boats randomly on board
        carry(ships,carrier,array);
        batshp(ships,bat1.bat,count,array,ind);
        batshp(ships,bat2.bat,count+4,array,ind+1);
        crui(ships,crui1.cruis,count+8,array,ind+2);
        crui(ships,crui2.cruis,count+11,array,ind+3);
        crui(ships,subm.cruis,count+14,array,ind+4);
        des(ships,dest1.destr,count+17,array,ind+5);
        des(ships,dest2.destr,count+19,array,ind+6);
        des(ships,dest3.destr,count+21,array,ind+7);
        des(ships,dest4.destr,count+23,array,ind+8);
        for(i=0;i<30;i++){
            printf("\n%d",ships[i]);
        }
        for(i=0;i<10;i++){
            printf("\n%d",array[i]);
        }

    boardshow(board);
    char hint;
    while(win!=30){
            printf("x:%d",xl);
            printf("y:%d",yl);
            tries++;
            fle=userguess(board,ships,trial,tri);
            printf("x:%d",xl);
            printf("y:%d",yl);
            if(fle==1){
                win++;
                hits++;
                board[xl-1][yl-1]='X';
                boardshow(board);
            }
            else{
                misss++;
                board[xl-1][yl-1]='O';
                boardshow(board);
            }
            tri++;
            //hints after each turn
            printf("\nDo you need any hints?  (y/n)");
            scanf(" %c",&hint);
            if(hint=='y'){
                printf("\n\n CARRIER SHIP");
                if(array[0]==1){
                    printf("\n\n      X\n      X\n      X\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X      X      X      X");
                }
                printf("\n\n BATTLE SHIP-1");
                if(array[1]==1){
                    printf("\n\n      X\n      X\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X      X      X      ");
                }
                printf("\n\n BATTLE SHIP-2");
                if(array[2]==1){
                    printf("\n\n      X\n      X\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X      X      X      ");
                }
                printf("\n\n CRUISER SHIP-1");
                if(array[3]==1){
                    printf("\n\n      X\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X      X");
                }
                printf("\n\n CRUISER SHIP-2");
                if(array[4]==1){
                    printf("\n\n      X\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X      X");
                }
                printf("\n\n SUBMARINE SHIP");
                if(array[5]==1){
                    printf("\n\n      X\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X      X");
                }
                printf("\n\n DESTROYER SHIP-1");
                if(array[6]==1){
                    printf("\n\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X");
                }
                printf("\n\n DESTROYER SHIP-2");
                if(array[7]==1){
                    printf("\n\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X");
                }
                printf("\n\n DESTROYER SHIP-3");
                if(array[8]==1){
                    printf("\n\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X");
                }
                printf("\n\n DESTROYER SHIP-4");
                if(array[9]==1){
                    printf("\n\n      X\n      X");
                }
                else{
                    printf("\n\n      X      X");
                }


            }
    }
        printf("\n     GAME OVER !  ^_^");
        printf("\n\n total number of tries  o   : %d",tries+1);
        printf("\n\n total number of hits  ^_^   : %d",hits+1);

        printf("\n\n total number of misses  o   : %d",misss+1);
        }

        printf("\nDo you want to play again? (yes=1/no=0)");
        scanf("%d",&choice);
}
}
//function for player to guess and checks if guess is a duplicate one
int userguess(char *board,int ships[30],int *trial,int tri){
    int fle=0,i,flag=0,flag2=0;
    int shipguess=0;
    printf("\n Player1. Enter row number and column number to guess ships position.");
    do {
        printf("\n Row Number [1 - 10]:");
        scanf("\n%d",&xl);
    }while(xl<1 || xl>10);
    do {
        printf("\n Column Number:");
        scanf("%d",&yl);
    }while(yl<1 || yl>10);
    printf("%d",xl);
    printf("%d",yl);
    shipguess=guess(xl,yl);
    if(tri==0){
        trial[0]=shipguess;
    }
    else{

        for(i=0;i<tri;i++){

            if(shipguess==trial[i]){

                flag2=1;
            }
        }
    }
    if(flag2==0){
        if(tri!=0){
            trial[tri]=shipguess;
        }
        else{

        }
        for(i=0;i<30;i++){
        if(ships[i]==shipguess){
                flag=1;
        }
        else{
        }
    }
    if(flag==0){
        miss();
    }
    else{
        hit();
        fle=1;
    }

    return fle;
    }
    else{
        printf("\nCant enter already entered box\n");
        userguess(board,ships,trial,tri);
    }


}
//function for p1 to guess and checks if guess is a duplicate one
int userguess1(char *board1,int ships1[20],int *trial1,int tri1){
    int fle=0,i,flag=0,flag2=0;
    int shipguess=0;
    printf("\n Player1. Enter row number and column number to guess ships position.");
    do {
        printf("\n Row Number [1 - 10]:");
        scanf("\n%d",&p);
    }while(p<1 || p>10);
    do {
        printf("\n Column Number:");
        scanf("%d",&q);
    }while(q<1 || q>10);
    shipguess=guess(p,q);
    if(tri1==0){
        trial1[0]=shipguess;
    }
    else{

        for(i=0;i<tri1;i++){

            if(shipguess==trial1[i]){

                flag2=1;
            }
        }
    }
    if(flag2==0){
        if(tri1!=0){
            trial1[tri1]=shipguess;
        }
        else{

        }
        for(i=0;i<20;i++){
        if(ships1[i]==shipguess){
                flag=1;
        }
        else{
        }
    }
    if(flag==0){
        miss();
    }
    else{
        hit();
        fle=1;
    }

    return fle;
    }
    else{
        printf("\nCant enter already entered box\n");
        userguess1(board1,ships1,trial1,tri1);
    }


}
//function for p2 to guess and checks if guess is a duplicate one
int userguess2(char *board2,int ships2[20],int *trial2,int tri2){
    int fle=0,i,flag=0,flag2=0;
    int shipguess=0;
    printf("\n Player2. Enter row number and column number to guess ships position.");
    do {
        printf("\n Row Number [1 - 10]:");
        scanf("\n%d",&r);
    }while(r<1 || r>10);
    do {
        printf("\n Column Number:");
        scanf("%d",&s);
    }while(s<1 || s>10);
    shipguess=guess(r,s);
    if(tri2==0){
        trial2[0]=shipguess;
    }
    else{

        for(i=0;i<tri2;i++){

            if(shipguess==trial2[i]){

                flag2=1;
            }
        }
    }
    if(flag2==0){
        if(tri2!=0){
            trial2[tri2]=shipguess;
        }
        else{

        }
        for(i=0;i<20;i++){
        if(ships2[i]==shipguess){
                flag=1;
        }
        else{
        }
    }
    if(flag==0){
        miss();
    }
    else{
        hit();
        fle=1;
    }

    return fle;
    }
    else{
        printf("\nCant enter already entered box\n");
        userguess2(board2,ships2,trial2,tri2);
    }


}
//function to print MISS if guess is incorrect
void miss(){
    printf("\n                                                                                            ");
    printf("\n                                                                                            ");
    printf("\n                              |\\        /|  =======     =====    =====                       ");
    printf("\n                              | \\      / |     |       |         |               ");
    printf("\n                              |  \\    /  |     |       |----|    |----|                           ");
    printf("\n                              |   \\  /   |     |            |         |                   ");
    printf("\n                              |    \\/    |  =======    =====|    =====|           ");
    printf("\n                                                                                            ");
    printf("\n                                                                                            ");
}
//function to print HIT if guess is right
void hit(){
    printf("\n                                                                                            ");
    printf("\n                                                                                            ");
    printf("\n                                 |       |    =======     =======                       ");
    printf("\n                                 |       |       |           |                 ");
    printf("\n                                 |=======|       |           |                              ");
    printf("\n                                 |       |       |           |                             ");
    printf("\n                                 |       |    =======        |             ");
    printf("\n                                                                                            ");
    printf("\n                                                                                            ");
}

//function to convert row no. and column no. to a single grid number from 1-100
int guess(int r,int c){
    int n;
    if(r==1){
        n=c;
    }
    else if(c==10){
        n=r*10;
    }
    else{
        n=(r-1)*10+c;
    }
    return n;


}
//function to randomly place carrier on board
void carry(int *ships,int *carrier,int *array){
    int r,c,i,n;
    i=rand()%2;
    array[0]=i;
    if(i==0){
        //horizontal
        r=rand()%10+1;
        c=rand()%6+1;
        n=guess(r,c);
        for(i=0;i<5;i++){
            ships[i]=n;
            carrier[i]=n;
            n=n+1;
        }
    }
    else{
        //vertical
        r=rand()%6+1;
        c=rand()%10+1;
        n=guess(r,c);
        for(i=0;i<5;i++){
            ships[i]=n;
            carrier[i]=n;
            n=n+10;
        }
    }
}
//function to randomly place battleship on board
void batshp(int *ships,int *b,int count,int *array,int ind){
    int r,c,i,n,nn,flag=0;
    i=rand()%2;
    array[ind]=i;
    if(i==0){
        //horizontal
        r=rand()%10+1;
        c=rand()%7+1;
        n=guess(r,c);
        nn=n;
        for(i=0;i<count;i++){
            if(ships[i]==n || ships[i]==n+1 || ships[i]==n+2 || ships[i]==n+3 ){
                flag=1;
            }
        }
        if(flag==1){
            batshp(ships,b,count,array,ind);

        }
        else{
        for(i=count;i<count+4;i++){
            ships[i]=n;
            n=n+1;
        }
        for(i=0;i<4;i++){
            b[i]=nn;
            nn=nn+1;
        }
        }

    }
    else{
        //vertical
        r=rand()%7+1;
        c=rand()%10+1;
        n=guess(r,c);
        nn=n;
        for(i=0;i<count;i++){
            if(ships[i]==n || ships[i]==n+10 || ships[i]==n+20 || ships[i]==n+30 ){
                flag=1;
            }
        }
        if(flag==1){
            batshp(ships,b,count,array,ind);

        }
        else{
        for(i=count;i<count+4;i++){
            ships[i]=n;
            n=n+10;
        }
        for(i=0;i<4;i++){
            b[i]=nn;
            nn=nn+10;
        }
        }
 }

}

//function to randomly place cruiser on board
void crui(int *ships,int *b,int count,int *array,int ind){
    int r,c,i,n,nn,flag=0;
    i=rand()%2;
    array[ind]=i;
    if(i==0){
        //horizontal
        r=rand()%10+1;
        c=rand()%8+1;
        n=guess(r,c);
        nn=n;
        for(i=0;i<count;i++){
            if(ships[i]==n || ships[i]==n+1 || ships[i]==n+2 ){
                flag=1;
            }
        }
        if(flag==1){
            crui(ships,b,count,array,ind);

        }
        else{
        for(i=count;i<count+3;i++){
            ships[i]=n;
            n=n+1;
        }
        for(i=0;i<3;i++){
            b[i]=nn;
            nn=nn+1;
        }
        }

    }
    else{
        //vertical
        r=rand()%8+1;
        c=rand()%10+1;
        n=guess(r,c);
        nn=n;
        for(i=0;i<count;i++){
            if(ships[i]==n || ships[i]==n+10 || ships[i]==n+20){
                flag=1;
            }
        }
        if(flag==1){
            crui(ships,b,count,array,ind);

        }
        else{
        for(i=count;i<count+3;i++){
            ships[i]=n;
            n=n+10;
        }
        for(i=0;i<3;i++){
            b[i]=nn;
            nn=nn+10;
        }
        }
 }

}
//function to randomly place destroyer on board
void des(int *ships,int *b,int count,int *array,int ind){
    int r,c,i,n,nn,flag=0;
    i=rand()%2;
    array[ind]=i;
    if(i==0){
        //horizontal
        r=rand()%10+1;
        c=rand()%9+1;
        n=guess(r,c);
        nn=n;
        for(i=0;i<count;i++){
            if(ships[i]==n || ships[i]==n+1 ){
                flag=1;
            }
        }
        if(flag==1){
            des(ships,b,count,array,ind);

        }
        else{
        for(i=count;i<count+2;i++){
            ships[i]=n;
            n=n+1;
        }
        for(i=0;i<2;i++){
            b[i]=nn;
            nn=nn+1;
        }
        }

    }
    else{
        //vertical
        r=rand()%9+1;
        c=rand()%10+1;
        n=guess(r,c);
        nn=n;
        for(i=0;i<count;i++){
            if(ships[i]==n || ships[i]==n+10){
                flag=1;
            }
        }
        if(flag==1){
            des(ships,b,count,array,ind);

        }
        else{
        for(i=count;i<count+2;i++){
            ships[i]=n;
            n=n+10;
        }
        for(i=0;i<2;i++){
            b[i]=nn;
            nn=nn+10;
        }
        }
 }

}
//function to display board for user vs computer
int boardshow(char board[10][10]){
    int i,j;
    printf("\n                          1    2    3    4    5    6    7    8    9    10  \n");
    printf("                         _________________\n");
    printf("\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
                if(i==0 && j==0){
                printf("                     1  ");
            }
            printf("| %c |",board[i][j]);
        }
        if(i==9){
            printf("\n                       ");
        }
        else if(i==8){
            printf("\n                    %d  ",i+2);
        }
        else{
            printf("\n                     %d  ",i+2);
        }
    }
    printf("  _________________");
    return 0;
}

//function to display 2 boards side by side for user vs user
int boardshow2(char board1[10][10],char board2[10][10]){
    int i,j;
    printf("\n                          1    2    3    4    5    6    7    8    9    10                         1    2    3    4    5    6    7    8    9    10  \n");
    printf("                         _________________                       _________________\n                                ");
    printf("\n");
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
                if(i==0 && j==0){
                printf("                     1  ");
            }
            printf("| %c |",board1[i][j]);
        }
        for(j=0;j<10;j++){
                if(j==0){
                printf("                       ");
            }
            printf("| %c |",board2[i][j]);
        }
        if(i==9){
            printf("\n                       ");
        }
        else if(i==8){
            printf("\n                    %d  ",i+2);
        }
        else{
            printf("\n                     %d  ",i+2);
        }
    }
    printf("  _________________                       _________________");
    return 0;
}

//instructions for pvp
void instructions1(){
    printf("\n\n                Multi Player Mode : Player 1 vs Player 2.");
    printf("\n                    1. This game requires 2 players : User1 and User2.");
    printf("\n                    2. User1 starts by placing ships on grids of the board for User2 to guess.");
    printf("\n                    3. User2 continues by placing ships on grids of the board for User1 to guess.");
    printf("\n                    4. User1 then takes 1 turn to guess ship's position places by User2.");
    printf("\n                    5. User2 then takes 1 turn to guess ship's position places by User1.");
    printf("\n                    6. User1 and User2 guess alternatively in the same pattern uptill either one guesses all ships of the board.");
    printf("\n\n\n");
}

//instructions for comp vs user
void instructions2(){
    printf("\n\n                Single Player Mode : User vs Computer.");
    printf("\n                    1. This game requires 1 players : User1 and 2nd player: Computer.");
    printf("\n                    2. Computer shall randomly place a ships in 10x10 board for User1 to guess.");
    printf("\n                    3. User1 enter row number and column number to guess positions of ships.");
    printf("\n                    4. User1 wins when all ships are found and hence sunk.");
    printf("\n                    5. O implies User's guess is incorrect and no ship lies in that grid.");
    printf("\n                    6. X implies User's guess is correct and 1 ship lies in that grid.");
    printf("\n\n\n");
}