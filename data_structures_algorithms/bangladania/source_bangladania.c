/*
 * Nome:       Jonas Freire de Alcantara Marques de Barros
 * EP:         2
 * Data:       10/07/2017
 * Disciplina: Algoritmos e Estruturas de Dados 2017/1
 */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

// VARIAVEIS
/*
 * estrutura que representa uma cidade
 * 
 * i --- indice da cidade
 * x --- valor da abscissa
 * y --- valor da ordenada
 */
struct cidade{
    int i;    // indice
    double x; // abscissa
    double y; // ordenada
};
typedef struct cidade cidade; // criar alias para estrutura
// FIM VARIAVEIS


// FUNCOES AUXILIARES
/*
 * esta funcao troca o valor de duas variaveis
 * 
 * a e b --- variaveis para comutarem o valor
 * Obs.: a variavel e do tipo cidade
 */
void trocar( cidade* a, cidade* b ){
    cidade aux = *a;
    *a = *b;
    *b = aux;
}
/*
 * esta funcao retorna o minimo entre dois numeros
 * 
 * @ parametro v1 --- primeiro valor
 * @ parametro v2 --- segundo  valor
 */
double minimo( double v1, double v2 ) {
    if( v1 < v2 ) return v1;
    else          return v2;
}
/*
 * esta funcao ler um arquivo chamado [trembala.dat] e
 *  retorna um array contendo ponto do tipo cidades
 *  'ver acima '
 * 
 * Obs.: lembre-se de limpar o buffer de memoria apos
 *       utilizar esta variavel mapa com a funcao <free>
 * 
 * @ parametro mapa     --- variavel onde sera posto o mapa
 * @ parametro tamanho  --- tamanho do mapa -> por referencia
 */
void carregarMapa( cidade** mapa, int* size ) {
    
    FILE *f = NULL;
    
    if( (f = fopen( "trembala.dat", "r")) == NULL ) {
        *mapa = NULL;
        return;
    }
    
    
    int line = 0;
    char ch;
    
    
    fscanf( f, "%d", size);
    if( fgetc( f ) == '\r' ) fgetc( f );
    
    if( *size < 1 ) {
        *mapa = NULL;
        return;
    }
    
    *mapa = malloc( sizeof(cidade) * (*size) );
    
    int a;
    
    for( a = 0; a < (*size); a++ ) {
        (*mapa)[a].i = a+1;
        fscanf( f, "%lf", &(*mapa)[a].x );
        if( fgetc( f ) == '\r' ) fgetc( f );
    }
    for( a = 0; a < (*size); a++ ) {
        fscanf( f, "%lf", &(*mapa)[a].y );
        if( fgetc( f ) == '\r' ) fgetc( f );
    }
    
    
    fclose(f);
}
/*
// FIM FUNCOES AUXILIARES





// ALGORITMOS
/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo que intercala dois vetores v1[a...b-1] e v2[b...c-1]
 *  ambos em ordem crescente em um vetor v[a...b...c-1] em ordem crescente
 * 
 * a ordenacao e feita a partir da abscissa
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
void intercalaX( int a, int b, int c, cidade v[] ) {
    int n = c - a,   k = 0;
    int l = b,       r = c;
    int i = a,       j = b;
    cidade aux[n];
    
    while( i < l && j < r ) {
        if( v[j].x <= v[i].x )   {  aux[k]  =  v[j]; k++; j++; }
        else                     {  aux[k]  =  v[i]; k++; i++; }
    }
    while( i < l ) {
        aux[k++]  =  v[i++];
    }
    while( j < r ) {
        aux[k++]  =  v[j++];
    }
    for( i = 0; i < n; i++ ) {
        v[i + a] = aux[i];
    }
        
}
/*
 * ALGORITMO RECURSIVO
 * 
 * algoritmo de ordenacao mergesort (intercalacao)
 * 
 * ordenacao e feita a partir da abscissa
 *
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void mergesortX( cidade v[], int n ) {
    if( n <= 1 ) {
        return;
    }
    int m = n/2;
    mergesortX( v,   m   );
    mergesortX( v+m, n-m );
    intercalaX( 0, m, n, v );
}
/*
 * ALGORITMO ITERATIVO
 * 
 * algoritmo que intercala dois vetores v1[a...b-1] e v2[b...c-1]
 *  ambos em ordem crescente em um vetor v[a...b...c-1] em ordem crescente
 * 
 *  ordenacao e feita a partir da ordenada
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
void intercalaY( int a, int b, int c, cidade v[] ) {
    int n = c - a,   k = 0;
    int l = b,       r = c;
    int i = a,       j = b;
    cidade aux[n];
    
    while( i < l && j < r ) {
        if( v[j].y <= v[i].y )   {  aux[k]  =  v[j]; k++; j++; }
        else                     {  aux[k]  =  v[i]; k++; i++; }
    }
    while( i < l ) {
        aux[k++]  =  v[i++];
    }
    while( j < r ) {
        aux[k++]  =  v[j++];
    }
    for( i = 0; i < n; i++ ) {
        v[i + a] = aux[i];
    }
        
}
/*
 * ALGORITMO RECURSIVO
 * 
 * algoritmo de ordenacao mergesort (intercalacao)
 *
 * ordenacao e feita a partir da ordenada
 * 
 * @ parametro v --- vetor para ordenar
 * @ parametro n --- tamanho do vetor v
 */
void mergesortY( cidade v[], int n ) {
    if( n <= 1 ) {
        return;
    }
    int m = n/2;
    mergesortY( v,   m   );
    mergesortY( v+m, n-m );
    intercalaY( 0, m, n, v );
}
/*
 * ALGORITMO ITERATIVO
 * 
 * esta funcao retorna a menor distancia existente entre as cidades entre subconjuntos
 *  o tamanho da distancia entre o centro e as extremidades laterais do subconjunto
 *  sera MENORDISTANCIA, ou seja, para a esquerda teremos MENORDISTANCIA unidades
 *                                      para a direita teremos MENORDISTANCIA 2 unidades
 * 
 * @ parametro mapa[]     --- contendo todas as cidades
 * @ parametro n          --- tamanho total de cidades no mapa 
 * @ parametro distancia  --- menor distancia para a funcao saber quanto sera a distancia
 *                              entre fronteira dos subconjuntos
 * 
 * @ parametro cidade1 e cidade2 --- par de cidade que tera a menor distancia
 */
double menorDistanciaFronteira( cidade mapa[], int n, double distancia, cidade* cidade1, cidade* cidade2 ) {
    
    cidade fronteira[n];
    
    int k = 0, i = 0;
    double limiteE, limiteD;
    
    limiteE = mapa[n/2].x - distancia; // limite esquerdo do subconjunto fronteira
    limiteD = mapa[n/2].x + distancia; // limite direito do subconjunto fronteira
    
    while( k < n ) {
        // se o ponto esta dentro do subconjunto fronteira
        if( mapa[k].x >= limiteE && mapa[k].x <= limiteD )   fronteira[i++] = mapa[k];
        k++;
    }
    
    
    
    mergesortY( fronteira, i ); // ordenar fronteira por ordenadas
    
    
    if( i < 2 )   return distancia;
    
    
    int a, b;
    
    if( n == 2 ) {
        *cidade1 = fronteira[0];
        *cidade2 = fronteira[1];
        return sqrt( pow( fronteira[0].x - fronteira[1].x, 2) + pow( fronteira[0].y - fronteira[1].y, 2) );
        
    } else if( n == 3 ) {
        
        double d01, d02, d12;
        
        
        d01 = sqrt( pow( fronteira[0].x - fronteira[1].x, 2) + pow(fronteira[0].y - fronteira[1].y, 2) );
        d02 = sqrt( pow( fronteira[0].x - fronteira[2].x, 2) + pow(fronteira[0].y - fronteira[2].y, 2) );
        d12 = sqrt( pow( fronteira[1].x - fronteira[2].x, 2) + pow(fronteira[1].y - fronteira[2].y, 2) );
        
        
        if( d01 <= d02 && d01 <= d12 ) {
            *cidade1 = fronteira[0];
            *cidade2 = fronteira[1];
            return d01;
        } else if( d02 <= d01 && d02 <= d12 ) {
            *cidade1 = fronteira[0];
            *cidade2 = fronteira[2];
            return d02;
        } else {
            *cidade1 = fronteira[1];
            *cidade2 = fronteira[2];
            return d12;
        }
    }
    
    
    
    double d, menor;
    
    menor = sqrt( pow(fronteira[0].x - fronteira[1].x, 2 ) + pow(fronteira[0].y - fronteira[1].y, 2 ) );
    *cidade1 = fronteira[0];
    *cidade2 = fronteira[1];
    
    
    for( a = 0; a < i; a++ ) {
        
        b = a + 1;
        while( b > 0 && b <= a + 7 && b < i ) {
            d = sqrt( pow(fronteira[b].x - fronteira[a].x, 2 ) + pow(fronteira[b].y - fronteira[a].y, 2 ) );
            
            if( d < menor ) {
                menor = d;
                *cidade1 = fronteira[a];
                *cidade2 = fronteira[b];
            }
            
            ++b;
        }
       
    }
    
    return menor;
}
/*
 * ALGORITMO RECURSIVO
 * 
 * esta funcao procura a menor distancia entre cidades
 * 
 * Obs.: as cidades deverao estar ordenadas em ordem crescente quando esta
 *       funcao for chamada para isso utilize a funcao [mergesortX]
 * 
 * @ parametro mapa[]    --- vetor contendo todas as cidades
 * @ parametro n         --- quantidade de cidades no vetor
 * @ parametro cidade1   --- primeira cidade do par
 * @ parametro cidade2   --- segunda  cidade do par
 * 
 * @ retorna distancia   --- distancia entre as cidades
 */
double menorDistancia( cidade mapa[], int n, cidade* cidade1, cidade* cidade2 ) {
    
    if( n == 2 ) {
        *cidade1 = mapa[0];
        *cidade2 = mapa[1];
        return sqrt( pow( mapa[0].x - mapa[1].x, 2) + pow( mapa[0].y - mapa[1].y, 2) );
    }
    if( n == 3 ) {
        
        double d01, d02, d12;
        
        
        d01 = sqrt( pow( mapa[0].x - mapa[1].x, 2) + pow(mapa[0].y - mapa[1].y, 2) );
        d02 = sqrt( pow( mapa[0].x - mapa[2].x, 2) + pow(mapa[0].y - mapa[2].y, 2) );
        d12 = sqrt( pow( mapa[1].x - mapa[2].x, 2) + pow(mapa[1].y - mapa[2].y, 2) );
        
        
        if( d01 <= d02 && d01 <= d12 ) {
            *cidade1 = mapa[0];
            *cidade2 = mapa[1];
            return d01;
        } else if( d02 <= d01 && d02 <= d12 ) {
            *cidade1 = mapa[0];
            *cidade2 = mapa[2];
            return d02;
        } else {
            *cidade1 = mapa[1];
            *cidade2 = mapa[2];
            return d12;
        }
    }
    
    
    cidade e1, e2;
    cidade d1, d2;
    cidade f1, f2;
    
    double menorE = menorDistancia( mapa      , n/2      , &e1, &e2 );
    double menorD = menorDistancia( mapa + n/2, n - (n/2), &d1, &d2 );
    
    
    double minimoSubConjunto;
    
    if( menorE < menorD ) {
        minimoSubConjunto = menorE;
        *cidade1 = e1; *cidade2 = e2;
    } else {
        minimoSubConjunto = menorD;
        *cidade1 = d1; *cidade2 = d2;
    }
    
    
    double minimoFronteira = menorDistanciaFronteira( mapa, n, minimoSubConjunto, &f1, &f2 );
    
    
    if( minimoSubConjunto <= minimoFronteira ) {
        return minimoSubConjunto;
    } else {
        *cidade1 = f1;
        *cidade2 = f2;
        return minimoFronteira;
    }
}
// FIM ALGORITMOS





// FUNCAO MAIN
int main(void) {
    
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    
    
    int tamanho;
    
    cidade* mapa;
    
    
    // carregar mapa do arquivo
    carregarMapa( &mapa, &tamanho );
    
    
    if( mapa == NULL ) {
        printf("Erro para ler arquivo\n");
        return 0;
    }
    
    int a;
    
    // ordenar cidades a partir da abscissa
    mergesortX( mapa, tamanho );
    
    
    
    cidade c1, c2;
    double distancia;
    
    
    // computar menor distancia
    distancia = menorDistancia( mapa, tamanho, &c1, &c2);
    
    
    printf("%-3d %lf %lf\n", c1.i, c1.x, c1.y);
    printf("%-3d %lf %lf\n", c2.i, c2.x, c2.y);
    printf("%lf\n", distancia);

    
    free( mapa );
        
    
    return 0;
}
// FIM FUNCAO MAIN






