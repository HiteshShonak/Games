//Stone Paper Scissors
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game_instructions(){
    printf("Enter 1 2 or 3 to choose a option\n");
    printf("\nRULES:\n");
    printf("1. Stone Beats Scissors\n");
    printf("2. Scissors Beats Paper\n");
    printf("3. Paper Beats Stone\n");
    printf("4. If Both Player and Computer Choose Same Option Then Draw\n");
}
int comp_input(){
    int comp_choice1=(rand()%3)+1;
    if(comp_choice1==1) printf("Computer Chose Stone\n");
    else if(comp_choice1==2) printf("Computer Chose Paper\n");
    else printf("Computer Chose Scissors\n");
    return comp_choice1;
}
int check_result(int user_choice,int comp_choice,char player_name[100]){
    if(user_choice==comp_choice){
        printf("Draw!!\n");
    }
    else if((user_choice==2&&comp_choice==1)||(user_choice==3&&comp_choice==2)||(user_choice==1&&comp_choice==3)){
        printf("%s Won!!!\n",player_name);
        return 1;
    }
    else{
        printf("Computer Won!\n");
        return 2;
    }
}
int choose(char player_name[100]){
    int spc;
    printf("Choose: ");
    scanf("%d",&spc);
    switch(spc){
        case 1:
        printf("%s chose Stone\n",player_name); return 1;
        case 2:
        printf("%s chose Paper\n",player_name); return 2;
        case 3:
        printf("%s Chose Scissors\n",player_name); return 3;
        default:
        printf("INVALID INPUT!\n"); return 0;
    }
}
int main(){
    srand(time(0));
    int play=0;
    while(1){
    int i;
    int rounds_of_game;
    int playagain;
    int user_win=0,comp_win=0;
    int user_choice,comp_choice;
    int result;
    int tie_breaker;
    char player_name[100];
    if(play==1){
        printf("\nRESTARTING GAME\n");
        printf("\nSTARTING GAME IN \n3\n2\n1\n\n");
    }
    game_instructions();
    printf("\nENTER PLAYER NAME: ");
    scanf("%99[^\n]",player_name);
    printf("\nHOW MANY ROUNDS YOU WANT TO PLAY: ");
    scanf("%d",&rounds_of_game);
    printf("This Game Will Be of %d Rounds\n",rounds_of_game);
    printf("\nYou Will Be Given 3 Options To Choose From\n");
    printf("Your options are \n1. Stone\n2. Paper\n3. Scissors\n");
    for(i=1;i<=rounds_of_game;i++){
    printf("\nRound %d\n",i);
    while(1){
        user_choice=choose(player_name);
        if(user_choice!=0)break;
        printf("Now Choose Again\n");
    }
    comp_choice=comp_input();
    result=check_result(user_choice,comp_choice,player_name);
    if(result==1) user_win++;
    if(result==2) comp_win++;}
    while(user_win==comp_win){
    printf("\nDo You Want To Break a Tie\nPress 1 for YES\nPress 2 for NO\n");
    scanf("%d",&tie_breaker);
    if(tie_breaker==1||tie_breaker==2) break;
    printf("INVALID INPUT\n");
    }
    while(user_win==comp_win){
        if(tie_breaker==2)break;
    while(user_win==comp_win){
        printf("\nTie Breaker Round\n");
        while(1){
        user_choice=choose(player_name);
    if(user_choice!=0) break;
        printf("Now Choose Again\n");
    }
    comp_choice=comp_input();
    result=check_result(user_choice,comp_choice,player_name);
    if(result==1) user_win++;
    if(result==2) comp_win++;
    if(user_win!=comp_win) break;
    printf("\nREMATCH\n");
    }}
    printf("\nFinal Results\n");
    printf("%s: %d     |   Computer: %d\n",player_name,user_win,comp_win);
    if(user_win>comp_win) printf("%s Won The Game\n",player_name);
    else printf("Computer Won The Game\n");
    while(1){
    printf("\nDO YOU WANT TO PLAY AGAIN\n");
    printf("Press 1 for YES\nPress 2 for NO\n");
    scanf("%d",&playagain);
        if(playagain==1||playagain==2) break;
        printf("\nINVALID INPUT\n");
    }
    play=1;
    if(playagain!=1) break;}
    printf("\nTHANKS FOR PLAYING");
    return 0;
}