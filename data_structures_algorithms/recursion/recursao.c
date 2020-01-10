// cabecalho

/*
    Nome: JONAS FREIRE DE ALCANTARA MARQUES DE BARROS
    Data: 11/05/2017
    EP número: 0
    Disciplina: Algoritmos e Estrutura de Dados
*/


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/////////////////////
// VARIAVEIS GLOBAIS
int iterativo = 0;
int recursivo = 0;
// FIM VARIAVEIS GLOBAIS
/////////////////////



/////////////////////
// MAXIMO
/*
    ALGORITMO ITERATIVO
    
    Esta funcao retorna o maximo inteiro em um vetor
    @ parametro v --- vetor com os inteiros
    @ parametro n --- tamanho do vetor de inteiros
    
    @ retorno max --- maior inteiro no inteiro
*/
int max(int n, int v[]){
    int max = v[0];
    int k;
    for(k = 1; k < n; k++){
        if(max < v[k])
            max = v[k];
        iterativo++;
    }
    
    return max;
}
/*
    ALGORITMO RECURSIVO
    
    Esta funcao retorna o maximo inteiro em um vetor
    @ parametro v --- vetor com os inteiros
    @ parametro n --- tamanho do vetor de inteiros
    
    @ retorno max --- maior inteiro no inteiro
*/
int maxR(int n, int v[]){
    recursivo++;
    if(n == 1)
        return v[0];
    int e, d;
    e = maxR( (n+1) / 2, v);
    d = maxR( n / 2, v + ((n+1) / 2 ));
    if( e < d )
        return d;
    else
        return e;
}
// FIM MAXIMO
/////////////////////





/////////////////////
// SEQUENCIA CRESCENTE
/*
    ALGORITMO ITERATIVO
    
    Esta funcao verifica se o vetor esta em ordem crescente
    @ parametro n --- tamanho do vetor
    @ parametro v --- vetor
    
    @ retorna 1 --- se o vetor esta em ordem crescente
    @ retorna 0 --- se o vetor nao esta em ordem crescente
*/
int crsc(int n, int v[]){
    int k;
    iterativo++;
    for(k = 0; k < (n - 1); k++){
        iterativo++;
        if(v[k] > v[k + 1])
            return 0;
    }
    return 1;
}
/*
    ALGORITMO RECURSIVO
    
    Esta funcao verifica se o vetor esta em ordem crescente
    @ parametro n --- tamanho do vetor
    @ parametro v --- vetor
    
    @ retorna 1 --- se o vetor esta em ordem crescente
    @ retorna 0 --- se o vetor nao esta em ordem crescente
*/
int crscR(int n, int v[]){
    recursivo++;
    if(n == 1) // se o vetor tem tamanho 1 a sequencia esta em ordem crescente
        return 1;
    else if(n == 2){
        if(v[0] > v[1])
            return 0;
        else
            return 1;
    }
    else if(n == 3){
        if(v[0] > v[1] || v[1] > v[2])
            return 0;
        else
            return 1;
    }
    int e, d;
    e = crscR((n + 1) / 2, v); d = crscR(n / 2, v + ((n + 1) / 2) );
    
                  // \/ esta parte de baixo verifica a intersecao entre os dois subvetores
    if( e && d && (v[n/2] <= v[(n/2) + 1])) // se ambos os lados estao em ordem crescente
        return 1;
    else
        return 0;
}
// FIM SEQUENCIA CRESCENTE
/////////////////////


/////////////////////
// 2 ELEVADO A N
/*
    ALGORITMO ITERATIVO
    
    Esta funcao computa 2 elevado a um inteiro n e retorna-o
    @ parametro n --- inteiro ao qual se deve elevar 2
    
    @ retorna 2 ^ n
*/
int pot(int n){
    iterativo++; // contador
    int k = 1;
    int a;
    for(a = 0; a < n; a++){
        iterativo++; // contador
        k *= 2;
    }
    return k;
}
/*
    ALGORITMO RECURSIVO
    
    Esta funcao computa 2 elevado a um inteiro n e retorna-o
    @ parametro n --- inteiro ao qual se deve elevar 2
    
    @ retorna 2 ^ n
*/
int potR(int n){
    recursivo++; // contador
    if(n == 0)
        return 1;
    else if(n == 1)
        return 2;
    
    return potR( (n + 1) / 2 ) * potR( n / 2);
}

// FIM 2 ELEVADO A N
/////////////////////


/////////////////////
// BUSCA BINARIA
/*
    ALGORITMO ITERATIVO
    
    Esta funcao retorna a posicao j de um elemento x no vetor tal que v[j - 1] < x <= v[j]
    @ parametro x --- elemento a ser procurado
    @ parametro n --- tamanho do vetor
    @ parametro v --- vetor
    
    @ retorna posicao j
*/
int bin(int x, int n, int v[]){
    int e, d, m;
    e = -1; d = n; // esquerda e -1 para poder procurar sobre o primeiro indice do vetor [0]
    while(e < d - 1){
        iterativo++;
        m = (e + d) / 2;
        if(v[m] > x)
            d = m;
        else if(v[m] < x)
            e = m;
        else
            return m; // posicao encontrada
    }
    
    if(d == n)
        return 0;
    else
        return d;
}
/*
    ALGORITMO RECURSIVO
    
    Esta funcao retorna a posicao j de um elemento x no vetor tal que v[j - 1] < x <= v[j]
    @ parametro x --- elemento a ser procurado
    @ parametro n --- tamanho do vetor
    @ parametro v --- vetor
    
    @ retorna posicao j
*/
int binR(int x, int n, int v[]){
    recursivo++;
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
        
    int m = n / 2;
    if(v[m] > x)
        return binR( x, ((n + 1) / 2) + 1, v - 1) - 1; // - 1 porque o valor devolvido pela funcao será a posicao aumentada de uma unidade
    else if(v[m] < x)
        return binR( x, (n + 1) / 2, v + (n/2)) + (n/2); // (n / 2) visto que o valor devolvido pela funcao sera a posicao relativa ao subvetor da direita
    else
        return m;
}
// FIM BUSCA BINARIA
/////////////////////


/////////////////////
// FUNCOES AUXILIARES
/*
    Funcao que gera numeros aleatorios
    @ parametro m --- valor maximo que pode ser armazenado
    @ parametro n --- tamanho do vetor desejado
    @ parametro v --- vetor para alocar numeros
*/
void rnd(int m, int n, int v[]){
    int a;
    srand(time(NULL)); // semente
    for(a = 0; a < n; a++){
        v[a] = rand() % m;
    }
}
/*
    Funcao que gera numeros em ordem crescente
    @ parametro n --- tamanho do vetor desejado
    @ parametro v --- vetor para alinhar numeros
*/
void seq(int n, int v[]){
    int a;
    for(a = 0; a < n; a++){
        v[a] = a;
    }
}
/*
    Esta e uma estrutura para ajudar a funcao de criar e salvar a tabela no arquivo
*/
typedef struct{
    int n; // tamanho do n --- no caso de 2 ^ n - a potencia de 2
    int x; // o valor procurado --- para o algoritmo de busca binaria
    int iteracoes; // numero de iteracoes do algoritmo
    int recursao; // numero de chamadas recursivas do algoritmo
}Dados;
/*
    Funcao que adiciona no final do arquivo uma tabela contendo o resultado dos algoritmos
    
    Algoritmo: <nome_do_algoritmo>
    
    Descricao: <descricao de variaveis>
    
    n | x | # iterativo | # recursivo | # (recursivo - iterativo)
  ----------------------------------------------------------------
    5 | 3 |      4      |       5     |              1
    --------------------------------------------------------------
    
    Conclusao: <esse campo sera preenchido posteriormente apos analise da tabela>
    
    @ parametro dados[]    --- vetor contendo estruturas dos testes do algoritmo
    @ parametro n          --- tamanho do vetor de testes (dados)
    @ parametro nome[]       --- nome do algoritmo
    @ parametro descricao[]  --- descricao do algoritmo
*/
void tbl(Dados dados[], int n, char nome[], char descricao[]){
    FILE* f = NULL;
    
    f = fopen("jonas_barros_ep0.txt", "a");
    
    fprintf(f, "\tAlgoritmo: %-70s\n\n", nome);
    
    fprintf(f, "\tDescricao: %-100s\n\n", descricao);
    
    fprintf(f, "\t  n  |  x  | # iterativo | # recursivo | # (recursivo - iterativo)\n");
    fprintf(f, "  ----------------------------------------------------------------\n");
    int a;
    for(a = 0; a < n; a++){
        fprintf(f, "\t%-5d|%-5d|%-13d|%-13d|%d\n", dados[a].n, dados[a].x, dados[a].iteracoes, dados[a].recursao, dados[a].recursao - dados[a].iteracoes);
        fprintf(f, "  ----------------------------------------------------------------\n");
    }
    
    fprintf(f, "\nConclusao: ");
    
    fprintf(f, "\n\n\n\n===================================================================================================\n\n\n\n");

    if(f != NULL)
        fclose(f);
}

// FIM FUNCOES AUXILIARES
/////////////////////





/////////////////////
// TESTE
/*int main(void){
    int SIZE = 1;
    int SEEK = 1;
    const int MAXIMUM = 51;
    printf("Size: ");
    scanf("%d", &SIZE);
    printf("Seek: ");
    scanf("%d", &SEEK);
    int v[SIZE];
    //rnd(MAXIMUM, SIZE, v);
    printf("Sorted array\n");
    int a;
    for(a = 0; a < SIZE; a++){
        v[a] = a;
    }
    for(a = 0; a < SIZE; a++){
        printf("%d - %d\n", a, v[a]);
    }
    
    
    
    printf("\nIterative\n");
    int m = max(SIZE, v);
    printf("The max is %d\n", m);
    printf("\nRecursive\n");
    m = maxR(SIZE, v);
    printf("The max is %d\n", m);
    
    printf("\nIterative: %d\n", iterativo);
    printf("Recursive: %d\n", recursivo);
    printf("Difference (iterative - recursivo): %d\n", iterativo - recursivo);
    
    

    printf("\n\nIterative: ");
    if(crsc(SIZE, v))
        printf("Yes");
    else
        printf("No");
    
    printf("\n");
    
    printf("\n\nRecursive: ");
    if(crscR(SIZE, v))
        printf("Yes");
    else
        printf("No");
    
    printf("\n");
    printf("Iterative: %d\n", iterativo);
    printf("Recursive: %d\n", recursivo);
    

    printf("\n\nIterative: ");
    
    printf("2 ^ %d = %d", SIZE, pot(SIZE));
    
    printf("\n");
    
    printf("\n\nRecursive: ");
    
    printf("2 ^ %d = %d", SIZE, potR(SIZE));
    
    printf("\n");
    printf("Iterative: %d\n", iterativo);
    printf("Recursive: %d\n", recursivo);

    
    printf("\n\nIterative: %d", bin(SEEK, SIZE, v));
    
    printf("\n");
    
    printf("\n\nRecursive: %d", binR(SEEK, SIZE, v));
    printf("\n");
    printf("Iterative: %d\n", iterativo);
    printf("Recursive: %d\n", recursivo);
    
    
    
    return 0;
}
*/
// FIM TESTE
/////////////////////





/////////////////////
// ESCREVER NO ARQUIVO
/*
    Funcao principal
    Esta funcao ira executar os algoritmos capturar os dados e salva-los no arquivo
*/
int main(){
    
    int a;
    int m;
    int size;
    Dados dados[5];
    
    // algoritmo de maximo
    // 1
    size = 10;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        max(size, v);
        maxR(size, v);
        dados[0].n = size; dados[0].x = 0; dados[0].iteracoes = iterativo; dados[0].recursao = recursivo;
    }
    // 2
    size = 11;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        max(size, v);
        maxR(size, v);
        dados[1].n = size; dados[1].x = 0; dados[1].iteracoes = iterativo; dados[1].recursao = recursivo;
    }
    // 3
    size = 1000;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        max(size, v);
        maxR(size, v);
        dados[2].n = size; dados[2].x = 0; dados[2].iteracoes = iterativo; dados[2].recursao = recursivo;
    }
    // 4
    size = 1001;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        max(size, v);
        maxR(size, v);
        dados[3].n = size; dados[3].x = 0; dados[3].iteracoes = iterativo; dados[3].recursao = recursivo;
    }
    // 5
    size = 5000;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        max(size, v);
        maxR(size, v);
        dados[4].n = size; dados[4].x = 0; dados[4].iteracoes = iterativo; dados[4].recursao = recursivo;
    }
    tbl(dados, 5, "Maximo", "O n corresponde ao tamanho do vetor e a coluna x deve ser ignorada");
    
    
    
    
    // algoritmo de sequencia crescente
    // 1
    size = 10;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        crsc(size, v);
        crscR(size, v);
        dados[0].n = size; dados[0].x = 0; dados[0].iteracoes = iterativo; dados[0].recursao = recursivo;
    }
    // 2
    size = 11;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        crsc(size, v);
        crscR(size, v);
        dados[1].n = size; dados[1].x = 0; dados[1].iteracoes = iterativo; dados[1].recursao = recursivo;
    }
    // 3
    size = 1000;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        seq(size, v);
        crsc(size, v);
        crscR(size, v);
        dados[2].n = size; dados[2].x = 0; dados[2].iteracoes = iterativo; dados[2].recursao = recursivo;
    }
    // 4
    size = 1001;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        rnd(m, size, v);
        crsc(size, v);
        crscR(size, v);
        dados[3].n = size; dados[3].x = 0; dados[3].iteracoes = iterativo; dados[3].recursao = recursivo;
    }
    // 5
    size = 5000;
    m = 51;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        rnd(m, size, v);
        crsc(size, v);
        crscR(size, v);
        dados[4].n = size; dados[4].x = 0; dados[4].iteracoes = iterativo; dados[4].recursao = recursivo;
    }
    tbl(dados, 5, "Sequencia crescente", "O n corresponde ao tamanho do vetor e a coluna x deve ser ignorada");
    
    
    
    // algoritmo da computacao de 2 ^ n
    // 1
    size = 0;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        pot(size);
        potR(size);
        dados[0].n = size; dados[0].x = 0; dados[0].iteracoes = iterativo; dados[0].recursao = recursivo;
    }
    // 2
    size = 1;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        pot(size);
        potR(size);
        dados[1].n = size; dados[1].x = 0; dados[1].iteracoes = iterativo; dados[1].recursao = recursivo;
    }
    // 3
    size = 4;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        pot(size);
        potR(size);
        dados[2].n = size; dados[2].x = 0; dados[2].iteracoes = iterativo; dados[2].recursao = recursivo;
    }
    // 4
    size = 8;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        pot(size);
        potR(size);
        dados[3].n = size; dados[3].x = 0; dados[3].iteracoes = iterativo; dados[3].recursao = recursivo;
    }
    // 5
    size = 16;
    if(1){
        iterativo = 0; recursivo = 0;
        int v[size];
        pot(size);
        potR(size);
        dados[4].n = size; dados[4].x = 0; dados[4].iteracoes = iterativo; dados[4].recursao = recursivo;
    }
    tbl(dados, 5, "Computador de 2 ^ n", "O n corresponde a potencia ao qual 2 sera elevado e a coluna x deve ser ignorada");
    
    
    
    // algoritmo de busca binaria
    int x;
    // 1
    size = 4096;
    m = 4096;
    if(1){
        iterativo = 0; recursivo = 0;
        x = 1024;
        int v[size];
        seq(size, v);
        bin(x, size, v);
        binR(x, size, v);
        dados[0].n = size; dados[0].x = x; dados[0].iteracoes = iterativo; dados[0].recursao = recursivo;
    }
    // 2
    size = 8182;
    m = 4096;
    if(1){
        iterativo = 0; recursivo = 0;
        x = 512;
        int v[size];
        seq(size, v);
        bin(x, size, v);
        binR(x, size, v);
        dados[1].n = size; dados[1].x = x; dados[1].iteracoes = iterativo; dados[1].recursao = recursivo;
    }
    // 3
    size = 16364;
    m = 4096;
    if(1){
        iterativo = 0; recursivo = 0;
        x = 255;
        int v[size];
        rnd(m, size, v);
        bin(x, size, v);
        binR(x, size, v);
        dados[2].n = size; dados[2].x = x; dados[2].iteracoes = iterativo; dados[2].recursao = recursivo;
    }
    // 4
    size = 1024;
    m = 512;
    if(1){
        iterativo = 0; recursivo = 0;
        x = 127;
        int v[size];
        seq(size, v);
        bin(x, size, v);
        binR(x, size, v);
        dados[3].n = size; dados[3].x = x; dados[3].iteracoes = iterativo; dados[3].recursao = recursivo;
    }
    // 5
    size = 255;
    m = 127;
    if(1){
        iterativo = 0; recursivo = 0;
        x = 15;
        int v[size];
        seq(size, v);
        bin(x, size, v);
        binR(x, size, v);
        dados[4].n = size; dados[4].x = x; dados[4].iteracoes = iterativo; dados[4].recursao = recursivo;
    }
    tbl(dados, 5, "Busca binaria", "O n corresponde ao tamanho do vetor e a coluna x corresponde aos valor procurado");
    
    return 0;
}

// FIM ESCREVER NO ARQUIVO
/////////////////////






