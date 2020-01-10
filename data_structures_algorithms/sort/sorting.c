/*
 * Nome: JONAS FREIRE DE ALCANTARA MARQUES DE BARROS    
 * EP: 1
 * Data: 13/06/2017
 * Disciplina: Algoritmos e Estruturas de dados
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// VARIAVEIS GLOBAIS
long int itera;
long int recur;
// FIM VARIAVEIS GLOBAIS

// FUNCOES AUXILIARES
/*
 * gerar numeros aleatorios
 */
void aleatorio(int v[], int n, int maximo) {
    srand(time(NULL));
    int k;
    for(k = 0; k < n; k++) {
        v[k] = rand() % (maximo + 1);
    }
}
/*
 * esta funcao transforma cria um vetor de tamanho n de forma crescente
 * 
 * @ parametro v --- vetor para ser criado
 * @ parametro n --- tamanho do vetor v
 */
void crescente(int v[], int n) {
    int k;
    for( k = 0; k < n; k++ ) {
        v[k] = k;
    }
}
/*
 * esta funcao transforma cria um vetor de tamanho n de forma decrescente
 * 
 * @ parametro v --- vetor para ser criado
 * @ parametro n --- tamanho do vetor v
 */
void decrescente(int v[], int n) {
    int k;
    for( k = n - 1; k >= 0; k-- ) {
        v[k] = k;
    }
}
/*
 * esta funcao copia os elementos do vetor v para outro vetor w
 * 
 * @ parametro v --- vetor origem
 * @ parametro w --- vetor destino
 * @ parametro n --- tamanho dos vetores (tamanhos iguais)
 */
void copy( int v[], int w[], int n) {
    int k;
    for( k = 0; k < n; k++ ) {
        w[k] = v[k];
    }
}
//mostrar array
void mostrar(int v[], int n) {
    int k = 0;
    while( k < n ) {
        if(k % 15 == 0) printf("\n");
        printf("%-5d  ", v[k]);
        k++;
    }
}
// trocar dois elementos
void trocar(int* e1, int* e2) {
    int aux = *e1;
    *e1 = *e2;
    *e2 = aux;
}
// verifica se o vetor esta em ordem crescente
int growing(int v[], int n) {
    int k;
    for( k = 1; k < n; ++k ) {
        if(v[k - 1] > v[k]) {
            return 0;
        }
    }
    return 1;
}
// FIM FUNCOES AUXILIARES




// ALGORITMOS
/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo de ordenacao por INSERCAO
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void insercao(int v[], int n) {
    int k;
    unsigned long int i, j;
    for(i = 1; i < n; i++) {
        k = v[i];
        j = i - 1;
        itera++;
        while( j >= 0 && v[j] > k ){
            v[j + 1] = v[j];
            j--;
            itera++;
        }
        v[j + 1] = k;
    }
}


/*
 * ALGORITMO RECURSIVO
 * 
 * algoritmo de ordenacao por INSERCAO
 *  este algoritmo funciona de forma recursiva
 *  e basicamente recebe uma posicao k e devolve
 *  uma posicao i tal que v[i - 1] <= v[k]
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 * @ parametro p --- posicao do desejado
 */
void insercaoRecursivo(int v[], int n, int p) {
    if( p >= n ) {
        return;
    } else if( n == 1 ) {
        return;
    }
    int k = v[p];
    int i = p - 1;
    while( i >= 0 && v[i] > k ) {
        v[i + 1] = v[i--];
    }
    v[i + 1] = k;
    insercaoRecursivo( v, n, p+1 ); recur++;
}


/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo de ordenacao por SELECAO
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void selecao(int v[], int n) {
    unsigned long int i, j;
    for( i = 0; i < n; i++ ) {
        for( j = i + 1; j < n; j++ ) {
            itera++;
            if( v[i] > v[j] ) trocar(v + i, v + j);
        }
    }
}


/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo que intercala dois vetores v1[a...b-1] e v2[b...c-1]
 *  ambos em ordem crescente em um vetor v[a...b...c-1] em ordem crescente
 * 
 *  Obs.: ambos os vetores v1 e v2 sao contiguos (um ao lado do outro)
 * 
 * 
 * @ parametro a --- inicio do vetor v1
 * @ parametro b --- inicio do vetor v2
 * @ parametro c --- fim    do vetor v2 (exclusivo)
 * 
 * @ parametro v --- vetor para ordenar
 */
void intercala(int a, int b, int c, int v[]) {
    int n = c - a,   k = 0;
    int l = b,       r = c;
    int i = a,       j = b;
    int aux[n];
    
    while( i < l && j < r ) {
        if( v[j] <= v[i] )   {  aux[k]  =  v[j]; k++; j++; }
        else                 {  aux[k]  =  v[i]; k++; i++; }
        itera++;
    }
    while( i < l ) {
        aux[k++]  =  v[i++];
        itera++;
    }
    while( j < r ) {
        aux[k++]  =  v[j++];
        itera++;
    }
    for( i = 0; i < n; i++ ) {
        v[i + a] = aux[i];
    }
        
}


/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo de ordenacao mergesort
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void mergesort(int v[], int n) {
    
    int  k = n,  j,     q = 1;
    int  a,      b,     c;
    
    while( k > 1 ) {
        for( j = 0; j < n/(q*2); j++ ) {
            a = j * 2 * q;
            b = a + q;
            c = b + q;
            intercala(a, b, c, v);
        }
        q *= 2; // tamanho  dos subvetores
        k /= 2; // numero   dos subvetores
        if( c != n ) {
            b = c;
            c = n;
            intercala(a, b, c, v);
        }
    }
}

/*
 * ALGORITMO RECURSIVO
 * 
 * algoritmo de ordenacao mergesort (intercalacao) recursivo
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void mergesortRecursivo(int v[], int n) {
    if( n <= 1 ) {
        return;
    }
    int m = n/2;
    mergesortRecursivo( v,   m   ); recur++;
    mergesortRecursivo( v+m, n-m ); recur++;
    intercala( 0, m, n, v );
}


/*
 * ALGORITMO ITERATIVO
 * 
 * parte do algoritmo de ordenacao heapsort
 * 
 * funcao peneira que poe um no no seu respectivo lugar
 *  na heap
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 * @ parametro d --- no desejado
 */
void peneira(int v[], int n, int d) {
    int largest;
    while( d*2 + 1 < n ) {
        itera++;
        if( d*2 + 2 < n && v[d*2 + 2] > v[d*2 + 1] )  largest = d*2 + 2;
        else                                          largest = d*2 + 1;
        if( v[d] < v[largest] ) {
            trocar( v+d, v+largest );
            d = largest;
        } else {
            break;
        }
    }
}

/*
 * ALGORITMO RECURSIVO
 * 
 * funcao peneira que poe um no no seu respectivo lugar
 *  na heap
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 * @ parametro d --- no desejado
 */
void peneiraRecursiva(int v[], int n, int d) {
    int l;
    if( 2*d + 1 < n ) {
        if( 2*d + 2 < n && v[2*d + 1] < v[2*d + 2] ) {
            l = 2*d + 2;
        } else {
            l = 2*d + 1;
        }
        if( v[d] < v[l] ) {
            trocar( v+d, v+l );
            peneiraRecursiva( v, n, l ); recur++;
        }
    }
}



/*
 * ALGORITMO ITERATIVO
 * 
 * parte do algoritmo de ordenacao heapsort
 * 
 * funcao que transforma um array qualquer de inteiros em uma heap
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void constroiHeap(int v[], int n) {
    int k = (n / 2) - 1;
    while( k >= 0 ) {
        peneira(v, n, k);
        k--;
    }
}

/*
 * ALGORITMO RECURSIVO
 * 
 * parte do algoritmo de ordenacao heapsort
 * 
 * funcao que transforma um array qualquer de inteiros em uma heap
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void constroiHeapRecursivo(int v[], int n) {
    int k = (n / 2) - 1;
    while( k >= 0 ) {
        peneiraRecursiva(v, n, k); recur++;
        k--;
    }
}

/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo de ordenacao heapsort
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void heapsort(int v[], int n) {
    constroiHeap(v, n);
    int f = n - 1;
    while( f > 0 ) {
        trocar( v, v+f );
        peneira( v, f, 0 );
        --f;
    }
}


/*
 * ALGORITMO RECURSIVO
 * 
 * algoritmo de ordenacao heapsort
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void heapsortRecursivo(int v[], int n) {
    constroiHeap(v, n);
    int f = n - 1;
    while( f > 0 ) {
        trocar( v, v+f );
        peneiraRecursiva( v, f, 0 ); recur++;
        --f;
    }
}


/*
 * ALGORITMO ITERATIVO
 * 
 * parte do algoritmo de ordenacao quicksort
 * 
 * esta funcao coloca o pivo numa posicao tal que
 * 
 * |<=|<=|<=|<=|<=|<=|p|>|>|>|>| ---> onde p e o pivo
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro r --- posicao do ultimo elemento do vetor v
 * @ parametro p --- posicao do pivo
 * 
 * @ retorna   j --- posicao final do pivo
 */
int separa (int v[], int p, int r)
{
    int i = p + 1,  j = r,  pivot = v[p];
    while( 1 ) {
        
        while( i <= j && v[i] <= pivot ) {
            i++;
            itera++;
        }
        while( i <= j && v[j] > pivot ) {
            j--;
            itera++;
        }
        if( i < j ) {
            trocar( v+i, v+j );
        } else {
            break;
        }
    }
    if( j != p ) {
        trocar( v+j, v+p );
    }
    return j;
}

/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo de ordenacao quicksort
 * 
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void quicksort(int v[], int n) {
    int  k = 0,  s[n],   p ;
    int  a = 0,  b = n - 1 ;
    s[k++] = a;
    s[k++] = b;
    while( k > 0 ) {
        b = s[--k];
        a = s[--k];
        if( a != b ) {
            p = separa( v, a, b);
            if( p == a ) {
                s[k++] = p + 1;
                s[k++] = b;
            } else if( p == b ) {
                s[k++] = a;
                s[k++] = p - 1;
            } else { 
                s[k++] = a;
                s[k++] = p - 1;
                s[k++] = p + 1;
                s[k++] = b;
            }
        }
    }
}


// FIM ALGORITMOS



int main() {
    
    system("clear");
    
    int tam;
    printf("Size: ");
    scanf("%d", &tam);
    getchar();
    
    
    int v1[tam];
    int v2[tam];
    
    int a, b;
    
    unsigned long int start, end;
    double iterativeTime, recursiveTime;
    
    aleatorio( v1, tam , 10000);
//     crescente( v1, tam );
    
    
    printf("Random Vectors:\n");
    
    
    
    
    
    // insertion sort
    
    copy ( v1, v2, tam );
    
    itera = 0;
    recur = 0;
    
    start = clock();
    insercao( v2, tam );
    end = clock();
    iterativeTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    a = growing( v2, tam );
   
    copy ( v1, v2, tam );
    
    start = clock();
    insercaoRecursivo( v2, tam, 1 );
    end = clock();
    recursiveTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    b = growing( v2, tam );
    
    printf("insertion:");
    if( a && b ) {
        
        
        printf("\niterations %-9ld\nrecursions %-9ld\nsize %-8d\niterative time ms ~ %f\nrecursive time ms ~ %f\n",
                                    itera, recur, tam, iterativeTime, recursiveTime );
        
    } else {
        printf(" Not growing vector \n");
    }
    
    printf("-----------------------\n\n");
    
    
    
    
    // selection sort
    
    copy ( v1, v2, tam );
    
    itera = 0;
    recur = 0;
    
    start = clock();
    selecao( v2, tam );
    end = clock();
    iterativeTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    a = growing( v2, tam );
    
    copy ( v1, v2, tam );
    
    
    printf("Selection:");
    if( a ) {
        
        
        printf("\niterations %-9ld\nsize %-8d\niterative time ms ~ %f\n",
                                    itera, tam, iterativeTime );
        
    } else {
        printf(" Not growing vector \n");
    }
    
    printf("-----------------------\n\n");
    
    
    
    
    // merge sort
    
    copy ( v1, v2, tam );
    
    itera = 0;
    recur = 0;
    
    start = clock();
    mergesort( v2, tam );
    end = clock();
    iterativeTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    a = growing( v2, tam );
    
    copy ( v1, v2, tam );
    
    start = clock();
    mergesortRecursivo( v2, tam );
    end = clock();
    recursiveTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    b = growing( v2, tam );
    
    printf("mergesort:");
    if( a && b ) {
        
        
        printf("\niterations %-9ld\nrecursions %-9ld\nsize %-8d\niterative time ms ~ %f\nrecursive time ms ~ %f\n",
                                    itera, recur, tam, iterativeTime, recursiveTime );
        
    } else {
        printf(" Not growing vector \n");
    }
    
    printf("-----------------------\n\n");
    
    
    
    
    // Heap sort
    
    copy ( v1, v2, tam );
    
    itera = 0;
    recur = 0;
    
    start = clock();
    heapsort( v2, tam );
    end = clock();
    iterativeTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    a = growing( v2, tam );
    
    copy ( v1, v2, tam );
    
    start = clock();
    heapsortRecursivo( v2, tam );
    end = clock();
    recursiveTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    b = growing( v2, tam );
    
    printf("heapsort:");
    if( a && b ) {
        
        
        printf("\niterations %-9ld\nrecursions %-9ld\nsize %-8d\niterative time ms ~ %f\nrecursive time ms ~ %f\n",
                                    itera, recur, tam, iterativeTime, recursiveTime );
        
    } else {
        printf(" Not growing vector \n");
    }
    
    printf("-----------------------\n\n");
    
    
    
    
    // quick sort
    
    copy ( v1, v2, tam );
    
    itera = 0;
    recur = 0;
    
    start = clock();
    quicksort( v2, tam );
    end = clock();
    iterativeTime = 1000 * ( (double)(end - start) / CLOCKS_PER_SEC ) ;
    a = growing( v2, tam );
    
    copy ( v1, v2, tam );
    
    
    printf("quicksort:");
    if( a ) {
        
        
        printf("\niterations %-9ld\nsize %-8d\niterative time ms ~ %f\n",
                                    itera, tam, iterativeTime );
        
    } else {
        printf(" Not growing vector \n");
    }
    
    
    
    printf("\n");
    return 0;
    
}
