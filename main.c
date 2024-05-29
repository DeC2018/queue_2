#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int capacity;
    char full;
    char *head, *tail;
    char dec[0];
}Dec;

Dec* createDec(int cap);

void printDec(Dec * dec);

int isDecFull(Dec *dec);

int isDecEmpty(Dec *dec);

void pushT(Dec * dec, char *);

char * popH(Dec *dec);

Dec* createDec(int cap){

    Dec *dec = (Dec *) calloc(1, sizeof(Dec) + sizeof(char) * cap);

    dec->capacity = cap;

    dec->head = dec->dec;
    dec->tail = dec->dec;

    dec->full = 0;
    return dec;
}

void printDec(Dec * dec){
    char * bp = (char*) dec->head;

    if(!bp || isDecEmpty(dec))
        return;

    for ( int i = 0; i < dec->full; bp = dec->dec + ((int)(bp - dec->dec + 1)) % dec->capacity, i++)
    {
        printf("%d ", bp[0]);
    }
    printf("\n");
}

int isDecFull(Dec *dec){

    return dec->full >= dec->capacity;
};

int isDecEmpty(Dec *dec){

    if (dec->full == 0){
            dec->head = dec->dec;
            dec->tail = dec->dec;
            return 1;
    }
    return  0;
};

void pushBack(Dec *dec, char z){
    if( isDecFull(dec)){
        return;
    }
    dec->tail[0] = z;
    dec->full ++;
    dec->tail = dec->dec + (int)(dec->tail - dec->dec + 1) % dec->capacity;
};

char popHead(Dec * dec){
    char get = dec->head[0];
    dec->head = dec->dec + (int)(dec->head - dec->dec + 1) % dec->capacity;
    dec->full--;
    return get;
}

void print(char * a, int n){
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
        printf("\n");
}

void destroyDec(Dec* dec)
{
    free(dec);
};

int main(){
    Dec *dc = 0;

    dc = createDec(5);

    dc->head  +=  3;
    dc->tail= dc->head;

    for( int i = 0; i < 6; i++)
    {
        pushBack(dc, i + 1);
        printf("array: ");
        print(dc->dec, 5);
        printf("dec: ");
        printDec(dc);
    }

    for( int i = 0; !isDecEmpty(dc) && i < 6; i++)
    {
        printf("get%d: %hhu\n",i,  popHead(dc));
        printf("array: ");
        print(dc->dec, 5);
        printf("dec: ");
        printDec(dc);
    }

    destroyDec(dc);
    return 0;
}

