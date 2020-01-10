/*
 * Nome: Jonas Freire de Alcantara Marques de Barros
 * EP: 3
 * Data: 04/08/2017
 * Disciplina: Algoritmos e Estruturas de Dados
 */

#include <stdio.h>
#include <stdlib.h>


#define MAX_PILHA 40


/*
 * estrutura generica que suporta armazenar qualquer tipo de dado,
 * ela necessita apenas do primeiro endereco de memoria,
 * e do tamanho do objeto
 */
struct objeto {
    // ponteiro para objeto
    void* obj;
    // tamanho do objeto em bytes
    unsigned long int tam;
};

typedef struct objeto objeto;

// pilha lib
/*
 * esta pilha funciona da seguinte forma:
 *  recebe um ponteiro para uma posicao de memoria
 *  e o tamanho do objeto que se deseja manipular,
 *  por exemplo, se voce deseja armazenar um inteiro,
 *  deve passar o endereco da memoria para a variavel,
 *  e o tamanho, no caso sizeof(int)
 *  sera empilhado este valor.
 * 
 * Obs.1: Os valores serao empilhados por valor, e nao
 *        por referencia.
 * Obs.2: A capacidade maxima da pilha sera 40
 */

struct pilha {
    // array de objetos
    objeto plh[MAX_PILHA];
    // apontador para topo + 1
    int topo;
};

typedef struct pilha pilha;

/*
 * esta funcao retorna 1 se a pilha esta cheia, senao retorna 0
 * 
 * @ parametro plh --- endereco de memoria para pilha
 */
int pilhaCheia( pilha* plh ) {
    if( plh->topo == MAX_PILHA ) return 1;
                                 return 0;
}
/*
 * esta funcao retorna 1 se a pilha esta vazia, senao retorna 0
 * 
 * @ parametro plh --- endereco de memoria para pilha
 */
int pilhaVazia( pilha* plh ) {
    if( plh->topo == 0 ) return 1;
                         return 0;
}
/*
 * empilhar um novo objeto, na pilha plh de tamanho size
 * 
 * @ parametro novo    --- endereco de memoria para objeto
 * @ parametro tamanho --- tamanho do objeto em bytes
 * @ parametro plh     --- endereco de memoria para pilha
 */
void empilhar( void* novo, int tamanho, pilha* plh ) {
    
    if( pilhaCheia( plh ) ) {
        printf("ESTOURO DE PILHA\n");
        exit(1);
    }
    
    char* copia = malloc( tamanho );
    char* aux   = novo;
    
    
    int k = 0;
    
    while( k < tamanho ) {
        copia[k] = aux[k]; // valores serao passados por valor nao por referencia
        ++k;
    }
    
    plh->plh[ plh->topo   ].obj = copia; // passar endereco do endereco de memoria que recebeu a copia do valor
    plh->plh[ plh->topo++ ].tam = tamanho;
}
/*
 * desempilha o objeto que esta no topo, da pilha
 * 
 * @ parametro plh --- endereco de memoria para pilha
 * @ parametro tam --- endereco de memoria para variavel que armazenara
 *                          o tamanho de objeto em bytes, podera ser um valor NULL
 * 
 * Obs.: os objetos retornados sao alocados dinamicamente, portanto depois de usa-los
 *          utilize free() para desalocar memoria
 * 
 * @ retorna o primeiro endereco de memoria do byte
 * @ retorna NULL se a pilha esta vazia
 */
void* desempilhar( int* tam, pilha* plh ) {
    
    if( pilhaVazia( plh ) ) return NULL;
    
    if( tam != NULL ) *tam = plh->plh[ plh->topo - 1 ].tam; // tamanho do objeto
    
    plh->topo--;
    
    return plh->plh[ plh->topo ].obj;
}
/*
 * criar pilha alocar espaco de memoria para sua utilizacao
 * 
 * @ retorna endereco de memoria para pilha
 */
pilha* criarPilha() {
    
    pilha* novaPilha = malloc( sizeof(pilha) );
    
    novaPilha->topo = 0;
    
    return novaPilha;
}
/*
 * retornar toda a pilha, como um array de objetos
 * 
 * @ parametro plh --- endereco de memoria para pilha
 * @ parametro tam --- tamanho em bytes dos objetos nela armazenados
 * 
 * @ retorna array de objetos, lembre-se de desalocar
 *  espaço da memoria se o programa estiver longe do fim
 */
objeto* retornarPilha( pilha* plh ) {
    
    return plh->plh;
}
/*
 * destruir pilha e desalocar espaco de memoria por ela utilizado
 */
void destruirPilha( pilha* plh ) {
    
    int k;
    
    while( k < MAX_PILHA ) {
        
        if( plh->plh[k].obj != NULL ) free( plh->plh[k].obj ); // desalocar espaco de memoria do objeto
        
        ++k;
    }
    
    free( plh );
}
// pilha lib fim



//////////////////////////



// lista ligada lib

/*
 * elemento armazenado pela lista ligada
 */
struct elemento {
    // valor armazenado pelo elemento
    int valor;
    // ponteiro para o proximo elemento
    struct elemento* prox;
};

typedef struct elemento elemento;

/*
 * a estrutura de dados lista ligada sera uma estrutura
 *  que contera um ponteiro para a cabeca da lista
 *  e um iterador para lista atual, por onde o usuario
 *  podera percorrer a lista
 */
struct lista {
    // ponteiro para cabeca da lista
    elemento* cabeca;
    // ponteiro para elemento atual da lista
    elemento* iterador;
};

typedef struct lista lista;

// prototipos
lista* inicializarLista();
lista* novaListaBaseada( lista* lst );
int fimLista( lista* lst );
int listaVazia( lista* lst );
void inserir( lista* lst, int valor );
elemento* iterador( lista* lst );
void iteradorAjustar( lista* lst, elemento* posicao );
void iteradorInicio( lista* lst );
elemento* proximo( lista* lst );
void remover( lista* lst );
void destruirLista( elemento* lst );


/*
 * criar lista
 * 
 * @ retorna endereco da lista
 */
lista* inicializarLista() {
    
    lista* lst = malloc( sizeof(lista) );
    
    elemento* cabeca = malloc( sizeof(elemento) );
    
    cabeca->valor = 0;
    cabeca->prox  = NULL;
    
    lst->cabeca   = cabeca;
    lst->iterador = cabeca;
    
    return lst;
}
/*
 * criar lista baseado em uma lista preexistente
 *  seta o iterador para o inicio
 * 
 * @ parametro lst --- lista ao qual a lista sera baseada
 * 
 * @ retorna endereco para nova lista
 */
lista* novaListaBaseada( lista* lst ) {
    
    lista* nova = malloc( sizeof(lista) ); 
    
    int k = 0;
    
    elemento* cabeca = malloc( sizeof(elemento) );
    
    cabeca->valor  = 0;
    cabeca->prox   = NULL;
    
    nova->cabeca   = cabeca;
    nova->iterador = cabeca;
    
    elemento* aux  = lst->cabeca; 
    
    while( aux->prox != NULL ) {
        
        aux = aux->prox;
        
        inserir( nova, aux->valor );
    }
    
    return nova;
}
/*
 * esta funcao retorna 1 se a lista chegou ao fim, senao retorna 0
 */
int fimLista( lista* lst ) {
    if( lst->iterador == NULL ) return 1;
                                return 0;
}
/*
 * festa funcao retorna 1 se a lista esta vazia, senao retorna 0
 * 
 * @ parametro lst --- endereco de memoria para lista
 */
int listaVazia( lista* lst ) {
    
    if( lst->cabeca->prox == NULL ) return 1;
                                    return 0;
}
/*
 * inserir um novo elemento no final da lista
 * 
 * @ parametro lst   --- endereco de memoria para lista
 * @ parametro valor --- valor inteiro que sera adicionado
 */
void inserir( lista* lst, int valor ) {
    
    elemento* iterador = lst->cabeca;
    
    while( iterador->prox != NULL ) iterador = iterador->prox;
    
    elemento* novo   = malloc( sizeof(elemento) );
    
    novo->valor = valor;
    
    iterador->prox = novo;
    novo->prox     = NULL;
}
/*
 * retornar referencia para o iterador
 * 
 * @ parametro lst --- endereco de memoria para lista
 */
elemento* iterador( lista* lst ) {
    return lst->iterador;
}
/*
 * fazer com que o iterador da lista aponte para
 *  o endereco de memoria informado
 * 
 * @ parametro lst     --- endereco de memoria para lista
 * @ parametro posicao --- referencia para o iterador
 */
void iteradorAjustar( lista* lst, elemento* posicao ) {
    lst->iterador = (elemento*)posicao;
}
/*
 * fazer com que o iterador da lista va para o inicio
 */
void iteradorInicio( lista* lst ) {
    lst->iterador = lst->cabeca;
}
/*
 * devolver o proximo elemento
 * 
 * @ parametro lst --- endereco de memoria para lista
 * 
 * @ retorna NULL se nao existe mais elementos na lista
 */
elemento* proximo( lista* lst ) {
    
    if( lst->iterador == NULL ) return NULL;
    
    lst->iterador = lst->iterador->prox;
    
    return lst->iterador;
} 
/*
 * remover o elemento do inicio da lista
 * 
 * @ parametro lst --- endereco de memoria para lista
 */
void remover( lista* lst ) {
    
    if( listaVazia( lst ) ) return;
    
    elemento* cabeca  = lst->cabeca;
    
    elemento* remover = cabeca->prox;
    
    
    cabeca->prox = remover->prox;
    
    free( remover );
}
/*
 * destruir lista desalocara espaco na memoria, inclusive da cabeca
 * 
 * @ parametro lst --- endereco de memoria para lista
 */
void destruirLista( elemento* lst ) {
    
    elemento* remover  = lst->prox;
    
    while( remover != NULL ) {
        
        elemento* iterador = remover->prox;
        
        free( remover );
        
        remover = iterador;
    }
}
// lista ligada lib fim


// armazenar valores de chamada recursiva lib
/*
 * persistir valor das chamadas recursivas anteriormente computadas
 */
struct computado {
    double* valores[MAX_PILHA];
};

typedef struct computado computado;

/*
 * retorna referencia para nova estrutura de valores computados
 */
computado* inicializarComputado() {
    computado* novo = malloc( sizeof(computado) );
    
    int k;
    for( k = 0; k < MAX_PILHA; k++ ) novo->valores[k] = NULL;
    
    return novo;
}

/*
 * desaloca a estrutura computado valores
 * 
 * @ parametro valores --- endereco de memoria para estrutura computado
 */
void destruirComputado( computado* valores ) {
    free(valores);
}

/*
 * retorna um valor baseado no valor de n, de acordo com o enunciado E(n)
 *  se nao for encontrado sera retornado NULL
 * 
 * @ parametro n        --- procurar valor de E(n)
 * @ parametro valores  --- endereco de memoria para estrutura computado
 */
double* valorDeE(int n, computado* valores ) {
    return valores->valores[n];
}

/*
 * adicionar um novo valor E(n)
 * 
 * @ parametro n        --- valor de n
 * @ parametro valor    --- valor de E(n)
 * @ parametro valores  --- endereco de memoria para estrutura computado
 */
void adicionarValor( int n, double E, computado* valores ) {
    
    if( valores->valores[n] != NULL ) return;

    valores->valores[n] = malloc( sizeof(double) );
    
    *(valores->valores[n]) = E;
}


// armazenar valores de chamada recursiva lib fim

//////////////////////////

// funcoes auxiliares

struct contexto {
    // valor da incognita n
    int n;
    // referencia para pilha
    pilha* plh;
    // referencia para lista que armazena expressao
    lista* exp;
};

typedef struct contexto contexto;


// prototipos
void carregar( int* b, int** rcr, int* n, lista** lst );
void printPilhaContexto( pilha* plh );
int depurarInteiro( lista* lst );
void printPilhaValores( pilha* plh );
void printLista( lista *lst );


/*
 * funcao que le os dados do arquivo lep.in
 * 
 * @ parametro b   --- referencia para variavel que armazenara
 *                      quantidade de valores para base da recursao
 * @ parametro rcr --- referencia para variavel onde sera armazenado
 *                      os valores base da recursao
 * @ parametro n   --- referencia para variavel que sera o valor
 *                      de n
 * @ parametro lst --- referencia para variavel ponteiro a lista
 *                      que contem a expressao
 *
 * Obs.: a variavel lst e rcr sera do tipo ponteiro para ponteiros,
 *       a quantidade de valores na base da recursao sera
 *          b + 1
 */
void carregar( int* b, int** rcr, int* n, lista** lst ) {
    
    FILE* f;
    
    f = fopen("lep.in", "r");
    
    if( f == NULL ) {
        printf("Problema para abrir arquivo lep.in, saindo\n\n");
        exit(1);
    }
    
    fscanf( f, "%d", b ); fgetc(f);
    
    
    *rcr = malloc( (*b + 1) * sizeof(int) );
    
    int k = 0;
    
    while( k <= *b ) {
        
        fscanf( f, "%d", &(*rcr)[k] ); fgetc(f); ++k;
        
    }
    
    
    
    
    *lst = inicializarLista();
    
    char ch;
    
    while( (ch = fgetc(f)) != '\n' ) inserir( *lst, ch );
    
    
    
    
    fscanf( f, "%d", n );
    fclose(f);
}
/*
 * esta funcao imprime toda a pilha de contexto
 * 
 * @ parametro plh --- endereco de memoria para pilha de contexto
 */
void printPilhaContexto( pilha* plh ) {
    
    objeto* p = retornarPilha( plh );
    
    int k = 0;
    
    contexto* aux;
    
    while( k < plh->topo ) {
        
        printf("------\n\n");
        
        aux = (contexto*)p[k++].obj;
        
        printf("(int*) n = %d\n\n", aux->n);
        
        printf("(pilha*) plh ---> %p\n", aux->plh);
        printPilhaValores( aux->plh );
        printf("\n");
        
        printf("(lista*) exp ---> %p\n", aux->exp);
        printLista( aux->exp );
        printf("\n\n");
        
        
    }
    
    printf("---------------------\n");
}
/*
 * esta funcao retorna um inteiro contendo o valor da expressao
 *  ela funciona atraves da leitura da lista em um ponto tal que
 *  o valor e inteiro, seja positivo ou negativo
 * 
 * 
 * por exemplo:
 *  posicoes  0123456   
 *            4 3 - 2
 * 
 *  se for passada para esta funcao uma lista no qual o iterador
 *  esta na posicao 0 ou 2 ou 6 ela retornara respectivamente
 *  4, 3, 2
 *
 * 
 *  outro exemplo:
 *  posicoes   0123456789  
 *             4 3 - -2 *
 * 
 *  se for passada para esta funcao uma lista no qual o iterador
 *  esta na posicao 0 ou 2 ou 6 ela retornara respectivamente
 *  4, 3, -2
 * 
 *  se for passado qualquer outra posicao a funcao encerrara o
 *  programa explicitando erro de programacao
 * 
 * @ parametro lst --- endereco de memoria para lista
 *                      o iterador da lista deve estar um elemento
 *                      anterior ao inicio da conversao
 * 
 * 
 * @ retorna valor do inteiro
 */
int depurarInteiro( lista* lst ) {
    
    elemento* elematual = iterador( lst );
    
    
    int k = 1, result = 0, negativo = 0;
    
    
    while( (proximo(lst))->valor != ' ' ) k *= 10;
    
    
    iteradorAjustar( lst, elematual );
    
    
    while( elematual->valor != ' ' ) {
        
        switch( elematual->valor ) {
            
            case '-':
                negativo = 1;
                break;
                
            default:
                result += (elematual->valor - 48) * k;
                k /= 10;
            
        }
        
        elematual = proximo(lst);
    }
    
    if(negativo)    result = result * (-1) / 10;
    
    return result;
}
/*
 * esta funcao imprime toda a pilha de valores
 * 
 * @ parametro plh --- endereco de memoria para pilha de valores
 */
void printPilhaValores( pilha* plh ) {
    
    objeto* p = retornarPilha( plh );
    
    int k = 0;
    
    while( k < plh->topo ) printf("%lf\n", *(double*)(p[k++].obj) );
}
/*
 * imprimir lista
 * 
 * @ parametro lst --- endereco de memoria para lista
 */
void printLista( lista *lst ) {
    
    elemento* posicao = iterador( lst );
    
    iteradorInicio( lst );
    
    elemento* ite = proximo(lst);
    
    while( !fimLista(lst) ) {
        
        printf("%c", ite->valor );
        
        ite = proximo(lst);
    }
    
    iteradorAjustar( lst, posicao );
}

//////////////////////////



int main() {
    
    system("clear");
    
    int b;      // armazenar quantidade de base de recursoes
    int n;      // valor da incognita n
    int* rcr;   // vetor para valores bases da recursao
    lista* lst; // lista com a expressao
    
    carregar( &b, &rcr, &n, &lst ); // carregar valores do arquivo e armazena-los nas variaveis
    
    
    
    pilha* plhcntx = criarPilha(); // pilha para armazenar os contextos
    
    
    
    pilha* plhval = criarPilha(); // pilha para armazenar operandos
    lista* lstatual;              // lista contendo expressao
    int atualn;                   // valor atual da incognita
    
    
    
    // variaveis para efetuar computacao
    double* a1;
    double* a2;
    double* result;
    elemento* elem;
    
    // estrutura para armazenar valores de chamadas recursivas ja computadas
    computado* valores = inicializarComputado();
    
    // criar e empilhar contexto inicial
    
    contexto* cntxatual = malloc( sizeof(contexto) );
    
    cntxatual->n = n;
    cntxatual->plh = plhval;
    cntxatual->exp = lst;
    
    empilhar( cntxatual, sizeof(contexto), plhcntx );
    
    
    double resultado = 0;   // resultado de uma chamada recursiva
    
    while( !pilhaVazia(plhcntx) ) {
        
        
        cntxatual = (contexto*)desempilhar( NULL, plhcntx ); // desempilhar ultimo contexto na pilha de contexto
        
        plhval   = cntxatual->plh;
        lstatual = cntxatual->exp;
        n   = cntxatual->n;
        
        // imprimir desempilhamento
        printf("desempilha | n = %d\n", cntxatual->n);
        
        
        // substituir valor da chamada recursiva, pelo resultado da mesma
        if( !pilhaVazia(plhval) ) {
            
            desempilhar( NULL, plhval );
            
            double* res = malloc(sizeof(double));
            
            *res = resultado;
            
            empilhar( res, sizeof(double), plhval );
            
            free(res);
        }
        
        
        
        while( (elem = proximo( lstatual )) != NULL ) {
            
            switch( elem->valor ) {
                
                case ' ':
                    break;
                    
                case '+': {
                    a1 = (double*)desempilhar( NULL, plhval );
                    a2 = (double*)desempilhar( NULL, plhval );
                    
                    result = malloc(sizeof(double));
                    
                    *result = (*a2) + (*a1);
                    
                    empilhar( result, sizeof(double), plhval);
                    
                    
                    
                    free(a1);
                    free(a2);
                    free(result);
                    
                    break;
                }
                    
                case '*': {
                    a1 = (double*)desempilhar( NULL, plhval );
                    a2 = (double*)desempilhar( NULL, plhval );
                    
                    result = malloc(sizeof(double));
                    
                    *result = (*a2) * (*a1);
                    
                    empilhar( result, sizeof(double), plhval);
                
                    
                    
                    free(a1);
                    free(a2);
                    free(result);
                    
                    break;
                }
                    
                case '/': {
                    a1 = (double*)desempilhar( NULL, plhval );
                    a2 = (double*)desempilhar( NULL, plhval );
                    
                    if( *a1 == 0 ) {
                        printf("DIVISOES POR ZERO NAO SAO PERMITIDAS\n\n");
                        exit(1);
                    }
                    
                    result = malloc(sizeof(double));
                    
                    *result = (*a2) / (*a1);
                    
                    empilhar( result, sizeof(double), plhval );
                    
                    
                    
                    free(a1);
                    free(a2);
                    free(result);
                    
                    break;
                }
                    
                case '-': {
                    
                    elemento* prox = proximo( lstatual );
                    
                    if( fimLista(lstatual) ) { // verificar se chegou ao final da lista ligada
                        
                        a1 = (double*)desempilhar( NULL, plhval );
                        a2 = (double*)desempilhar( NULL, plhval );
                        
                        result = malloc(sizeof(double));
                        
                        *result = (*a2) - (*a1);
                        
                        empilhar( result, sizeof(double), plhval);
                        
                        free(a1);
                        free(a2);
                        free(result);
                        
                        break;
                    }
                    
                    if( prox->valor == ' ' ) { // verificar se o proximo elemento e um espaco
                        
                        a1 = (double*)desempilhar( NULL, plhval );
                        a2 = (double*)desempilhar( NULL, plhval );
                        
                        result = malloc(sizeof(double));
                        
                        *result = (*a2) - (*a1);
                        
                        empilhar( result, sizeof(double), plhval);
                        
                        free(a1);
                        free(a2);
                        free(result);
                        
                        break;
                    }
                    
                    iteradorAjustar( lstatual, elem );
                    
                    a1 = malloc(sizeof(double));
                    a2 = malloc(sizeof(double));
                    
                    *a1 = depurarInteiro( lstatual );
                    
                    empilhar( a1, sizeof(double), plhval );
                    
                    
                    // chamada recursiva
                    
                    *a2 = n;
                    n  += *a1;
                    
//                     printf("n = %d\n", n);
                    
                    if( n < 0 ) n = 0;
                    
                    if( n <= b ) { // n esta na base da recursao
                        
                        desempilhar( NULL, plhval);
                        
                        *a1 = rcr[n];
                        
                        empilhar( a1, sizeof(double), plhval ); // empilhar valor da base da recursao na pilha de valores
                        
                        n = *a2;
                        
                        free(a1);
                        free(a2);
                        
                        break; // continuar a computar a expressao
                        
                    }
                    
                    
                   printf("empilha | n = %d\n", cntxatual->n);
                   
                   
                   // verificar por valor anteriormente computado
                   
                   double* anterior = valorDeE(n, valores ); 
                    
                    if( anterior != NULL ) { 
                        
                        desempilhar( NULL, plhval);
                        
                        empilhar( anterior, sizeof(double), plhval ); // empilhar valor anteriormente computado na pilha de valores
                        
                        n = *a2;
                        
                        free(a1);
                        free(a2);
                        
                        /** imprimir desempilhamento, sera considerado desempilhamento
                         *      pois de fato seria feito uma nova chamada recursiva,
                         *      mas como o valor ja foi computado, entao nao sera necessario
                         */
                        printf("desempilha | n = %d\n", cntxatual->n);
                        
                        break; // continuar a computar a expressao
                    }
                    
                    empilhar( cntxatual, sizeof(contexto), plhcntx ); // empilhar contexto atual
                    
                    plhval   = criarPilha();                    // criar nova pilha de valores para chamada recursiva
                    lstatual = novaListaBaseada( lstatual );    // criar nova lista da expressao
                    
                    // ajustar novo contexto
                    cntxatual->plh = plhval;
                    cntxatual->exp = lstatual;  
                    cntxatual->n   = n;
                    
                    
                    free(a1);
                    free(a2);
                    
                    
                    
                    continue; // reiniciar execucao da expressao
                
                }
                    
                case 'n':
                    
                    a1  = malloc(sizeof(double));
                    
                    *a1 = n;
                    
                    empilhar( a1, sizeof(double), plhval );
                    
                    free(a1);
                    
                    
                    
                    break;
                    
                    
                default:
                    
                    a1 = malloc(sizeof(double));
                    
                    *a1 = depurarInteiro( lstatual );
                    
                    empilhar( a1, sizeof(double), plhval ); // empilhar inteiro
                    
                    
                    
                    free(a1);
                    
            }
            
        }
        
        
        // armazenar resultado do calculo da expressao
        resultado = *(double*)desempilhar(NULL, plhval);
        
        adicionarValor( cntxatual->n, resultado, valores );
        
        
        
    }
    
    
    printf("Resultado = %lf\n", resultado);
    
    return 0;
}




