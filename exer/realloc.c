//
// Created by 倪家棱 on 2021/11/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
typedef struct  _guess{
    int suspect;
    int location;
    int weapon;
}guess;
void ini(guess* answer);
int check(guess* answer,guess** guesses,int i);
int main(){
    guess* answer=malloc((size_t)1*sizeof(guess));
    int i=1,count=0;
    guess* guesses=malloc((size_t)1*sizeof(guess));
    ini(answer);
    if (guesses == NULL) { fprintf(stderr, "Error: out of memory");
        exit(1);
    }
    while(i <= 11){
        printf("Round %i\n",i);
        printf("Suspects: 1. Butcher 2. Hairdresser 3. Salesman 4. Banker 5. Student\n");
        printf("Locations: 1. Lounge 2. Lobby 3. Reception 4. Restaurant 5. Coffee shop\n");
        printf("Weapons: 1. Hammer 2. Fork 3. Knife 4. Poison 5. Candlestick\n");
        count=check(answer,&guesses,i);
        printf("You made %i correct guess(es)\n",count);
        if(count == 3){
            printf("you make it all correct");
            break;
        }
        i++;
    }
    free(guesses);guesses=NULL;
    free(answer);answer=NULL;
}
void ini(guess* answer){
    srand((unsigned int)time(NULL));
    answer->location=rand()%5+1;
    answer->suspect=rand()%5+1;
    answer->weapon=rand()%5+1;
}
int check(guess* answer,guess** guesses,int i){
    int location,suspect,weapon;guess* temp;int count=0;
    scanf("%i%i%i",&location,&suspect,&weapon);
    printf("%d\n",i);
    printf("%p %p\n",temp,*guesses);
    temp=realloc(*guesses,(unsigned long)i*sizeof(guess));
    printf("%p %p\n",temp,*guesses);
    if (temp == NULL) { fprintf(stderr, "Error: out of memory");
        exit(1);
    }
    (temp+i-1)->location=location;
    (temp+i-1)->weapon=weapon;
    (temp+i-1)->suspect=suspect;
//    free(*guesses);
    *guesses=temp;
    if(answer->suspect == suspect) count++;
    if(answer->weapon == weapon) count++;
    if(answer->location == location) count++;
    return count;
}
