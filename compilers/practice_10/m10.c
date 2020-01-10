#include <stdio.h>
#include <time.h>

/**
 * Maquina de inteiros
 * + combinadores de Turner
 * + operacoes aritmeticas
 */

#define N 100000000

#define fim_string -1
#define AP -2 //Abre Parenteses
#define FP -3 //Fecha Parenteses
#define K -4
#define S -5
#define I -6
#define B -7
#define C -8
#define D -9
#define E -10
#define F -11

#define True -12
#define False -13
#define gt -14
#define lt -15
#define eq -16
#define add -17
#define sub -18
#define mul -19
#define div -20


#ifdef FACTORIAL
static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, mul, FP, FP, FP, FP, 10, fim_string};
#else
static int entrada[N] = {S, AP, K, AP, S, I, I, FP, FP, AP, S, AP, S, AP, K, S, FP, K, FP, AP, K, AP, S, I, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, lt, FP, FP, FP, FP, AP, K, I, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 1, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, K, K, FP, I, FP, FP, AP, S, AP, S, AP, K, S, FP, AP, S, AP, S, AP, K, S, FP, AP, K, I, FP, FP, AP, S, AP, K, K, FP, AP, K, 2, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, sub, FP, FP, FP, FP, FP, FP, AP, S, AP, K, K, FP, AP, K, add, FP, FP, FP, FP, 5, fim_string};
#endif

static int saida[N];

/**
 * Objetivo de debug
 */
void printar_array_integer(unsigned int * array1) {
    int i;
    for (i = 0; i < 300; i++) {
        printf("%d -> %d\n", i, array1[i]);
    }
}

void printar_array(unsigned int *array1) {
    int i;
    unsigned int fimString = -1;
    for(i = 0;array1[i] != fimString;i++){
        switch (array1[i]){
            case S:
                printf("S");
                break;
            case K:
                printf("K");
                break;
            case I:
                printf("I");
                break;
            case B:
                printf("B");
                break;
            case C:
                printf("C");
                break;
            case D:
                printf("D");
                break;
            case E:
                printf("E");
                break;
            case F:
                printf("F");
                break;
            case FP:
                printf(")");
                break;
            case AP:
                printf("(");
                break;
            case True:
                printf("True");
                break;
            case False:
                printf("False");
                break;
            case lt:
                printf("lt");
                break;
            case gt:
                printf("gt");
                break;
            case eq:
                printf("eq");
                break;
            case add:
                printf("add");
                break;
            case sub:
                printf("sub");
                break;
            case mul:
                printf("mul");
                break;
            case div:
                printf("div");
                break;
            case fim_string:
                break;
            default:
                printf("%u", array1[i]);
                break;
        }
        // printf(" ");
    }
    printf("\n");
}

/**
 * Copia toda a array1 para a array2
 */
void copiar_array(int *array1, int *array2) {
    int k = 0;

    while (array1[k] != fim_string) {
        array2[k] = array1[k];
        k++;
    }

    array2[k] = fim_string;
}


/*
 * Remove o parenteses da posição 0 e seu oposto
 */
void remove_parenteses(int *array1){
    int p = 0;
    int paren = 1;

    while (paren) {
        array1[p] = array1[p+1];
        p++;
        if(array1[p] == AP){
            paren++;
        }else if(array1[p] == FP){
            paren--;
        }
    }
    p--;

    while(array1[p+1] != fim_string && array1[p+2] != fim_string){
        array1[p] = array1[p+2];
        p++;
    }
    array1[p] = fim_string;
}

/*
 * Procura o fim do conjunto de inteiros
 */
void casa_parenteses(int* array1, int* p) {
    int paren = 1;
    int a = *p;
    while (paren) {
        // unsigned int c  = array1[a];
        int c  = array1[a];
        if(c == AP){
            paren++;
        }else if(c == FP){
            paren--;
        }
        a++;
    }
    *p = a;
}

/*
 * Verifica se a posicao do array é um inteiro ou um conjunto de inteiros
 */
void acha_argumento(int *array1, int *p){
    int c = (*p)++;
    if (array1[c] == AP) {
        casa_parenteses(array1,p);
    }
}


///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
// OPERACOES BOOLEANAS
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

/*
 * Operacao booleana T: T a b => a
 */
void reduz_True(int *array1, int *array2) {
    int a, nA;
    int n = 1;

    a = n;
    acha_argumento(array1, &n);
    nA = n - 1;
    acha_argumento(array1, &n);

    // T a b => a
    int k = 0;
    int i;

    for (i = a; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao booleana F: F a b => b
 */
void reduz_False(int *array1, int *array2) {
    int b, nB;
    int n = 1;

    acha_argumento(array1, &n);
    b = n;
    acha_argumento(array1, &n);
    nB = n - 1;

    // T a b => b
    int k = 0;
    int i;

    for (i = b; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao booleana >: > a b => T, se a > b
 */
void reduz_gt(int *array1, int *array2) {
    int n = 3;
    int k = 1;

    if (array1[1] > array1[2]) {
        array2[0] = True;
    } else {
        array2[0] = False;
    }
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao booleana <: < a b => T, se a < b
 */
void reduz_lt(int *array1, int *array2) {
    int n = 3;
    int k = 1;

    if (array1[1] < array1[2]) {
        array2[0] = True;
    } else {
        array2[0] = False;
    }
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao booleana =: = a b => T, se a = b
 */
void reduz_eq(int *array1, int *array2) {
    int n = 3;
    int k = 1;

    if (array1[1] == array1[2]) {
        array2[0] = True;
    } else {
        array2[0] = False;
    }
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
// FIM OPERACOES BOOLEANAS
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////


///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
// OPERACOES ARITMETICAS
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

/*
 * Operacao aritmetica +: + a b => a+b
 */
void reduz_add(int *array1, int *array2) {
    int n = 3;
    int k = 1;

    array2[0] = array1[1] + array1[2];
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao aritmetica -: - a b => a-b
 */
void reduz_sub(int *array1, int *array2) {
    int n = 3;
    int k = 1;

    array2[0] = array1[1] - array1[2];
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao aritmetica *: * a b => a*b
 */
void reduz_mul(int *array1, int *array2) {
    int n = 3;
    int k = 1;

    array2[0] = array1[1] * array1[2];
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Operacao aritmetica /: / a b => a/b
 */
void reduz_div(int *array1, int *array2) {
    int n = 3;
    int k = 1;

#ifdef DEBUG
    if (array1[2] == 0)
        printf("Division per zero problem\n");
#endif

    array2[0] = array1[1] / array1[2];
    
    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

///////////////////////////////////
///////////////////////////////////
///////////////////////////////////
// FIM OPERACOES ARITMETICAS
///////////////////////////////////
///////////////////////////////////
///////////////////////////////////

/*
 * Operacao utilitaria sobre inteiro Int a b = a b Int
 */
void reduz_integer(int *array1, int *array2) {
    int a, nA;
    int b, nB;
    int n = 1;

    a = n;
    acha_argumento(array1,&n);
    nA = n - 1;
    
    b = n;
    acha_argumento(array1,&n);
    nB = n - 1;

    int k = 0;
    int i;

    for (i = a; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (i = b; i <= nB; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    array2[k] = array1[0];
    k++;

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}


/*
 * Kab = a
 */
void reduz_K(int* array1, int* array2) {
    int A, nA;
    int n = 1;

    A = n;
    acha_argumento(array1,&n);

    nA = n-1;
    acha_argumento(array1,&n);

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

/*
 * Sabc = ac(bc)
 */
void reduz_S(int *array1, int *array2) {
    int A, nA;
    int b, nb;
    int c, nc;
    int n = 1;
    A = n;
    acha_argumento(array1,&n);
    nA = n-1;
    b = n;
    acha_argumento(array1,&n);
    nb = n-1;
    c = n;
    acha_argumento(array1,&n);
    nc = n-1;

    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    for (i = c; i <= nc; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = AP;
    k++;

    for (i = b; i <= nb; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    for (i = c; i <= nc; i++) {
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;
    k++;

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }
    array2[k] = fim_string;
}

//Procedimento que recebe duas variaveis que apontam para
//dois arrays e executa a regra do combinador I: I a => a,
//copiando os argumentos do array1 para o array2.
void reduzI(int* array1, int* array2) {
    //I a => a
    int Id = 0;
    int i;
    
    for (i = 1; array1[i] != fim_string; i++) {
    	array2[Id] = array1[i];
    	Id++;
	}

    array2[Id] = fim_string;
}

//Procedimento que recebe duas variaveis que apontam para
//dois arrays e executa a regra do combinador B: B a b c => a ( b c ),
//copiando os argumentos do array1 para o array2.
void reduzB(int* array1, int* array2) {
    int A, nA;
    int b, nb;
    int c, nc;
    int n = 1;

    A = n;	// inicio do argumento
    acha_argumento(array1,&n); // endereco depois do fim do argumento
    nA = n-1; // endereco onde termina o argumento a
    b = n;	  // inicio do segundo argumento
    acha_argumento(array1,&n);	
    nb = n-1;
    c = n;
    acha_argumento(array1,&n);
    nc = n-1;

    //B a b c => a ( b c )
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {	// copia Argumento A para o array de saida
        array2[k] = array1[i];
        k++;
    }
  
    array2[k] = AP;	// coloca parentese para isolar argumento (bc)
    k++;

    for (i = b; i <= nb; i++) {	// copia argumento b para isolamento
        array2[k] = array1[i];
        k++;
    }
    for (i = c; i <= nc; i++) {	// copia argumento c para isolamento
        array2[k] = array1[i];
        k++;
    }

    array2[k] = FP;	// Fecha argumento
    k++;

    for (; array1[n] != fim_string; n++) {	// copia o restante da string
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

//Procedimento que recebe duas variaveis que apontam para
//dois arrays e executa a regra do combinador C: C a b c => a c b,
//copiando os argumentos do array1 para o array2.
void reduzC(int* array1, int* array2) {
    int A, nA;
    int b, nb;
    int c, nc;
    int n = 1;

    A = n;	// inicio do argumento
    acha_argumento(array1,&n); // endereco depois do fim do argumento
    nA = n-1; // endereco onde termina o argumento a
    b = n;	  // inicio do segundo argumento
    acha_argumento(array1,&n);	
    nb = n-1;
    c = n;
    acha_argumento(array1,&n);
    nc = n-1;

    //c a b c => a b c
    int k = 0;
    int i;

    for (i = A; i <= nA; i++) {	// copia Argumento A para o array de saida
        array2[k] = array1[i];
        k++;
    }
  
	for (i = c; i <= nc; i++) {	// // copia argumento c para o array de saida
        array2[k] = array1[i];
        k++;
    }

    for (i = b; i <= nb; i++) {	// copia argumento b para o array de saida
        array2[k] = array1[i];
        k++;
    }

    for (; array1[n] != fim_string; n++) {
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}


//Procedimento que recebe duas variaveis que apontam para
//dois arrays e executa a regra do combinador S1 de Turner: S1 a b c d => a (b d) (c d),
//nesse caso S1 representado por D, copiando os argumentos do array1 para o array2.
void reduzD(int* array1, int* array2) {
    int A, nA;
    int b, nb;
    int c, nc;
    int d, nd;
    int n = 1;

    A = n;	// inicio do argumento
    acha_argumento(array1,&n); // endereco depois do fim do argumento
    nA = n-1; // endereco onde termina o argumento a
    b = n;	  // inicio do segundo argumento, os mesmo passos para os argumentos seguintes
    acha_argumento(array1,&n);	
    nb = n-1;
    c = n;
    acha_argumento(array1,&n);
    nc = n-1;
    d = n;
    acha_argumento(array1,&n);
    nd = n-1;

    //D a b c d => a (b d) (c d)
    int k = 0;
    int i;

	// copia Argumento A para o array de saida
    for (i = A; i <= nA; i++) {	
        array2[k] = array1[i];
        k++;
    }
     
  	// coloca parentese para isolar argumento (b d)
    array2[k] = AP;
    k++;
    
    // copia argumento b para isolamento
    for (i = b; i <= nb; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    // copia argumento d para isolamento
    for (i = d; i <= nd; i++) {	// 
        array2[k] = array1[i];
        k++;
    }

	// Fecha argumento
    array2[k] = FP;
    k++;
    
    
    // coloca parentese para isolar argumento (c d)
    array2[k] = AP;
    k++;
    
    
    // copia argumento c para isolamento
	for (i = c; i <= nc; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    // copia argumento d para isolamento
    for (i = d; i <= nd; i++) {	// 
        array2[k] = array1[i];
        k++;
    }    
    
    // Fecha argumento
    array2[k] = FP;
    k++;

    for (n = n; array1[n] != fim_string; n++) {	// 
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}


//Procedimento que recebe duas variaveis que apontam para
//dois arrays e executa a regra do combinador B1 de Turner: B1 a b c d => a b (c d),
//nesse caso b1 representado por E, copiando os argumentos do array1 para o array2.
void reduzE(int* array1, int* array2) {
    int A, nA;
    int b, nb;
    int c, nc;
    int d, nd;
    int n = 1;

    A = n;	// inicio do argumento
    acha_argumento(array1,&n); // endereco depois do fim do argumento
    nA = n-1; // endereco onde termina o argumento a
    b = n;	  // inicio do segundo argumento, os mesmo passos para os argumentos seguintes
    acha_argumento(array1,&n);	
    nb = n-1;
    c = n;
    acha_argumento(array1,&n);
    nc = n-1;
    d = n;
    acha_argumento(array1,&n);
    nd = n-1;

    //E a b c d => a b (c d)
    int k = 0;
    int i;

	// copia Argumento A para o array de saida
    for (i = A; i <= nA; i++) {	
        array2[k] = array1[i];
        k++;
    }
    
    // copia argumento b para o array de saida
    for (i = b; i <= nb; i++) {
        array2[k] = array1[i];
        k++;
    }
     
  	// coloca parentese para isolar argumento (c d)
    array2[k] = AP;
    k++;
    
    
    // copia argumento c para isolamento
	for (i = c; i <= nc; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    // copia argumento d para isolamento
    for (i = d; i <= nd; i++) {	// 
        array2[k] = array1[i];
        k++;
    }    
    
    // Fecha argumento
    array2[k] = FP;
    k++;

    for (n = n; array1[n] != fim_string; n++) {	// 
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
} // FIM


//Procedimento que recebe duas variaveis que apontam para
//dois arrays e executa a regra do combinador C1 de Turner: C1 a b c d => a (b d) c ,
//nesse caso C1 representado por F, copiando os argumentos do array1 para o array2.
void reduzF(int* array1, int* array2) {
    int A, nA;
    int b, nb;
    int c, nc;
    int d, nd;
    int n = 1;

    A = n;	// inicio do argumento
    acha_argumento(array1,&n); // endereco depois do fim do argumento
    nA = n-1; // endereco onde termina o argumento a
    b = n;	  // inicio do segundo argumento, os mesmo passos para os argumentos seguintes
    acha_argumento(array1,&n);	
    nb = n-1;
    c = n;
    acha_argumento(array1,&n);
    nc = n-1;
    d = n;
    acha_argumento(array1,&n);
    nd = n-1;

    //d a b c d => a (b d) c
    int k = 0;
    int i;

	// copia Argumento A para o array de saida
    for (i = A; i <= nA; i++) {	
        array2[k] = array1[i];
        k++;
    }
     
  	// coloca parentese para isolar argumento (b d)
    array2[k] = AP;
    k++;
    
    // copia argumento b para isolamento
    for (i = b; i <= nb; i++) {
        array2[k] = array1[i];
        k++;
    }
    
    // copia argumento d para isolamento
    for (i = d; i <= nd; i++) {	// 
        array2[k] = array1[i];
        k++;
    }

	// Fecha argumento
    array2[k] = FP;
    k++;
    
    
    // copia argumento c para array de saida
	for (i = c; i <= nc; i++) {
        array2[k] = array1[i];
        k++;
    }   

    for (n = n; array1[n] != fim_string; n++) {	// 
        array2[k] = array1[n];
        k++;
    }

    array2[k] = fim_string;
}

int main(){
    int execute_swap = 0;

    int *array1, *array2, *array3;
    array1 = entrada;
    array2 = saida;

    while(array1[1] != fim_string){
        execute_swap = 1;
        switch (array1[0]){
            case AP:
                remove_parenteses(array1);
                execute_swap = 0;
                break;
            case K:
                reduz_K(array1, array2);
                break;
            case S:
                reduz_S(array1, array2);
                break;
            case I:
                reduzI(array1, array2);
                break;
            case B:
                reduzB(array1, array2);
                break;
            case C:
                reduzC(array1, array2);
                break;
            case D:
                reduzD(array1, array2);
                break;
            case E:
                reduzE(array1, array2);
                break;
            case F:
                reduzF(array1, array2);
                break;
            case gt:
                reduz_gt(array1, array2);
                break;
            case lt:
                reduz_lt(array1, array2);
                break;
            case eq:
                reduz_eq(array1, array2);
                break;
            case add:
                reduz_add(array1, array2);
                break;
            case sub:
                reduz_sub(array1, array2);
                break;
            case mul:
                reduz_mul(array1, array2);
                break;
            case div:
                reduz_div(array1, array2);
                break;
            case True:
                reduz_True(array1, array2);
                break;
            case False:
                reduz_False(array1, array2);
                break;
            default:
                reduz_integer(array1, array2);
                break;
        }
        
        if (execute_swap) {
            array3 = array1;
            array1 = array2;
            array2 = array3;
        }
    }
    printar_array(array1);
    float clks = CLOCKS_PER_SEC;
    printf("\nTempo = %f\n", (clock()/clks));

#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif

    return 0;
}

