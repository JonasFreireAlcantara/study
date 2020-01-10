#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * ALUNO: JONAS FREIRE DE ALCANTARA MARQUES DE BARROS
 * EPº: 4
 * DATA: 05/09/2017
 * DISCIPLINA: ALGORITMOS E ESTRUTURAS DE DADOS
 */

/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////// ESTRUTURA DE DADO LISTA LIGADA INICIO
/**
 * elemento da lista ligada
 */
struct elemento {
    char* palavra;
    int ocorrencia;
    struct elemento* proximo;
    struct elemento* anterior;
};
typedef struct elemento elemento;

/**
 * lista ligada
 */
struct lista {
    elemento* cabeca;
    elemento* final;
};
typedef struct lista lista;

/////////////////// PROTOTIPOS LISTA INICIO
lista* listaInicializar();
int listaVazia(lista* lst);
void listaInserir(lista* lst, elemento* add);
void listaRemover(lista* lst, elemento* del);
void listaDestruir(lista* lst);
elemento* listaBuscar(lista* lst, char* plv);
/////////////////// PROTOTIPOS LISTA FIM

/*
 * inicializa lista vazia e a retorna
 * complexidade no pior caso O(1)
 */
lista* listaInicializar() {
    
    lista* lst = malloc(sizeof(lista));
    
    elemento* cabeca = malloc(sizeof(elemento));
    cabeca->ocorrencia   = 0;
    cabeca->palavra      = NULL;
    cabeca->proximo      = NULL;
    cabeca->anterior     = NULL;
    
    lst->cabeca = cabeca;
    lst->final  = cabeca;
    
    return lst;
}

/**
 * retorna 1 se a lista esta vazia, senao 0
 * 
 * @ parametro lst --- lista que se deseja verificar
 * complexidade no pior caso O(1)
 */
int listaVazia(lista* lst) {
    if(lst->cabeca == lst->final)
        return 1;
    
    return 0;
}

/**
 * inserir novo elemento no inicio da lista ligada
 * 
 * @ parametro lst --- lista que se deseja inserir
 * @ parametro add --- elemento que se deseja inserir
 * complexidade no pior caso O(1)
 */
void listaInserir(lista* lst, elemento* add) {
    add->proximo  = lst->cabeca->proximo;
    add->anterior = lst->cabeca;
    
    lst->cabeca->proximo = add;
    if( add->proximo != NULL )
        add->proximo->anterior = add;
}

/**
 * remover elemento da lista ligada
 * 
 * @ parametro lst --- lista de onde se deseja remover
 * @ parametro del --- elemento que se deseja remover
 * complexidade no pior caso O(1)
 */
void listaRemover(lista* lst, elemento* del) {
    if( lst->final == del )
        lst->final = del->anterior;
    
    if( del->proximo != NULL )
        del->proximo->anterior = del->anterior;
    del->anterior->proximo = del->proximo;
    del->proximo  = NULL;
    del->anterior = NULL;
}

/**
 * destruir lista ligada, e desalocar espacos de memoria
 * 
 * @ parametro lst --- cabeca da lista que se deseja destruir
 * complexidade no pior caso O(n) onde n é a quantidade de elementos em lst
 */
void listaDestruir(lista* lst) {
    elemento* aux = lst->cabeca;
    while( lst->cabeca != lst->final ) {
         aux = aux->proximo;
        free(aux->anterior);
    }
    free(lst);
}

/**
 * retorna elemento passando palavra como argumento,
 *  se elemento nao existir retorna NULL
 * 
 * @ parametro lst --- lista onde se deseja procurar
 * @ parametro plv --- palavra que se deseja procurar
 * complexidade no pior caso O(n) onde n é a quantidade de elementos em lst
 */
elemento* listaBuscar(lista* lst, char* plv) {
    if( lst == NULL ) return NULL;
    elemento* aux = lst->cabeca->proximo;
    while( aux != NULL && aux->palavra != NULL ) {
        if( strcmp(aux->palavra, plv) == 0 )
            return aux;
        aux = aux->proximo;
    }
    return NULL;
}

/////////////////// ESTRUTURA DE DADO LISTA LIGADA FIM
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////// ESTRUTURA DE DADO TABELA HASH INICIO
/**
 * estrutura de dados de hash para ajudar na busca,
 *  embora no pior caso a complexidade de computacao
 *  total sera sera O(n)
 */
#define TAMANHO 97
struct tabela {
    lista* chaves[TAMANHO];
};
typedef struct tabela tabela;
/////////////////// PROTOTIPOS HASH INICIO
tabela* tabelaInicializar();
void tabelaInserir(tabela* tbl, elemento* add);
int tabelaComputarHash(int valor);
void tabelaRemover(tabela* tbl, elemento* del);
elemento* tabelaBuscarPalavra(tabela* tbl, char* plv);
char* sistemaCarregarPalavra(FILE* arquivo);
void sistemaNucleo(tabela* tbl, FILE* arquivo);
/////////////////// PROTOTIPOS HASH FIM

/**
 * inicializa tabela hash e a retorna
 * complexidade no pior caso O(1)
 */
tabela* tabelaInicializar() {
    tabela* nova = malloc(sizeof(tabela));
    int k = 0;
    while( k < TAMANHO ) nova->chaves[k++] = NULL;
    
    return nova;
}

/**
 * inserir novo elemento na tabela hash
 * 
 * @ parametro add --- elemento para ser adicionado a tabela
 * @ parametro tbl --- tabela onde se deseja adicionar
 * complexidade no pior caso O(n) onde n é a quantidade de elementos na posicao hash
 */
void tabelaInserir(tabela* tbl, elemento* add) {
    int posicao = tabelaComputarHash(add->ocorrencia);
    elemento* aux = NULL;
    if( tbl->chaves[posicao] == NULL ) {
        tbl->chaves[posicao] =  listaInicializar();
    }
    else {
        aux = tabelaBuscarPalavra( tbl, add->palavra );
        if( aux != NULL ) {
            tabelaRemover( tbl, add ); // remover elemento da lista de ocorrencias atual
            aux->ocorrencia++;
            tabelaInserir( tbl, add ); // inserir elemento na nova lista de ocorrencias atualizadas
            return;
        }
    }
    listaInserir( tbl->chaves[posicao], add );

}

/**
 * retorna um inteiro que corresponde a posicao, do elemento 'elem'
 *  no vetor, neste caso, o inteiro associado a palavra sera
 *  o numero de ocorrencia do mesmo na fonte de dados.
 * 
 * @ parametro val --- valor que se deseja extrair a hash
 * complexidade no pior caso O(1) 
 */
int tabelaComputarHash(int valor) {
    return valor % TAMANHO;
}

/**
 * remover elemento de uma tabela hash
 * 
 * OBS.: se o elemento nao fizer parte da tabela hash
 *        nada acontecera.
 *  
 * @ parametro del --- elemento que se deseja remover
 * @ parametro tbl --- tabela onde se deseja remover
 * complexidade no pior caso O(1)
 */
void tabelaRemover(tabela* tbl, elemento* del) {
    int posicao = tabelaComputarHash(del->ocorrencia);
    listaRemover( tbl->chaves[posicao], del );
}

/**
 * retornar elemento dado uma palavra, como argumento
 * 
 * @ parametro plv --- string com palavra procurada
 * @ parametro tbl --- tabela onde se deseja buscar
 * 
 * @ retorna elemento, se encontrado, senao NULL
 * complexidade no pior caso O(n) onde n é a quantidade de elementos na posicao
 */
elemento* tabelaBuscarPalavra(tabela* tbl, char* plv) {
    int k = -1; elemento* aux;
    while( ++k < TAMANHO )
        if( (aux = listaBuscar( tbl->chaves[k], plv )) != NULL )
            return aux;
    return NULL;
}

/////////////////// ESTRUTURA DE DADO TABELA HASH FIM
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////// FUNCOES AUXILIARES INICIO 

/////////////////// PROTOTIPOS SISTEMA INICIO
char* sistemaCarregarPalavra(FILE* arquivo);
void sistemaNucleo(tabela* tbl, FILE* arquivo);
void imprimirTudo(tabela* tbl);
void imprimirOcorrencia(tabela* tbl, int n);
void quebraLinhas (int n);
/////////////////// PROTOTIPOS SISTEMA FIM

/**
 * retornar palavra do arquivo, se nao houver
 *  mais palavras no arquivo, retorna NULL.
 * 
 * OBS.: ARQUIVO ABERTO NO MODO = TEXTO - LEITURA 
 * 
 * @ parametro arquivo --- buffer da entrada dos dados
 * 
 * @ retorna NULL se nao houver palavra encontrada
 * complexidade no pior caso O(1)
 */
char* sistemaCarregarPalavra(FILE* arquivo) {
    char* aux = malloc(sizeof(char) * 1000);
    fscanf(arquivo, "%s", aux);
    if( strlen(aux) == 0 ) return NULL;
    return aux;
}

/**
 * esta funcao devolve a quantidade de palavras
 * 
 * OBS.: ARQUIVO ABERTO NO MODO = TEXTO - LEITURA 
 * 
 * @ parametro arquivo --- buffer da entrada dos dados
 * complexidade no pior caso O(n) onde n é a quantidade de palavras no arquivo
 */
int sistemaQuantidadePalavras(FILE* arquivo) {
    char* plv; int k = 0;
    while( (plv = sistemaCarregarPalavra(arquivo)) != NULL ) k++;
    fseek(arquivo, 0, SEEK_SET);
    return k;
}

/**
 * esta função efetua n quebra de linhas
 * 
 * @ parametro n --- quantidade de vezes que se deseja quebrar linhas
 * complexidade no pior caso O(n) onde n é a quantidade de linhas a serem quebradas
 */
void quebraLinhas (int n) {
    int k = 0;
    while (k < n) { 
        printf("\n");
        k++;
    }
}

/**
 * nucleo do programa, aqui todas as funcionalidade do sistema serao unidas
 * 
 * @ parametro tbl --- tabela hash
 * @ parametro arquivo --- buffer da entrada dos dados
 * complexidade no pior caso O(j*n) onde j é a quantidade de palavras no arquivo
 *  e n é a quantidade de palavras diferentes 
 */
void sistemaNucleo(tabela* tbl, FILE* arquivo) {
    char *plv, aux;
    elemento* novo;
    int total = sistemaQuantidadePalavras(arquivo);
    int atual = 0, rapido = 0;
    
    while( (plv = sistemaCarregarPalavra(arquivo)) != NULL ) {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
        novo = tabelaBuscarPalavra( tbl, plv );
        if( novo == NULL ) {
            novo = malloc(sizeof(elemento));
            novo->palavra = malloc(sizeof(char) * 50);
            strcpy( novo->palavra, plv );
            novo->ocorrencia = 1;
        }
        tabelaInserir( tbl, novo );
        
        
//         PARA EXECUTAR RAPIDAMENTE SOBRE UM ARQUIVO DESCOMENTE ISTO
//         NAO SERA POSSIVEL VERIFICAR OCORRENCIAS ENQUANTO
//         O ALGORITMO NAO TIVER SIDO COMPLETADO
//         printf("\rCOMPLETADO = %.2f%\n", atual*100.00 / total);
//         atual++;
//         rapido = 1;
        
//         E COMENTE ISTO
        imprimirTudo(tbl);
        printf("\n\nDigite s para verificar alguma ocorrencia: ");
        aux = getchar();
        if( aux == 's' ) {
            printf("Digite uma ocorrencia: ");
            int n; scanf("%d", &n); while(getchar() != '\n');
            quebraLinhas (35);
            imprimirOcorrencia( tbl, n );
            getchar();
            quebraLinhas (35);
        }
    }
    if( rapido ) 
        imprimirTudo(tbl);
   
}

/**
 * imprimir uma lista com todas as palavras na tabela de hash
 * 
 * @ parametro tbl --- tabela que se deseja imprimir
 * complexidade no pior caso O(n) onde n é a quantidade de palavras diferentes na tabela de hash
 */
void imprimirTudo(tabela* tbl) {
    printf("%15s ---- OCORRENCIA\n-------------------------------------------\n", "PALAVRA");
    elemento* aux; int k = -1;
    while( ++k < TAMANHO ) {
        if( tbl->chaves[k] == NULL )
            continue;
        aux = tbl->chaves[k]->cabeca->proximo;
        while( aux != NULL ) {
            printf("%15s ---- %d\n", aux->palavra, aux->ocorrencia);
            aux = aux->proximo;
        }
    }
    printf("-------------------------------------------\n");
}

/**
 * imprimir uma lista de palavras dados um numero n de ocorrencias na tabela de hash
 * 
 * @ parametro tbl --- tabela que se deseja procurar
 * @ parametro n   --- numero de ocorrencia que se deseja procurar
 * complexidade no pior caso O(n) onde n é a quantidade de elementos na posicao hash
 */
void imprimirOcorrencia(tabela* tbl, int n) {
    printf("OCORRENCIA = %d\n-------------------------------------------\n",  n);
    elemento* aux = NULL; int k = -1;
    while( ++k < TAMANHO ) {
        if( tbl->chaves[k] != NULL )
            aux = tbl->chaves[k]->cabeca->proximo;
        while( aux != NULL ) {
            if( aux->ocorrencia == n )
                printf("%s\n", aux->palavra);
            aux = aux->proximo;
        }
    }
    printf("-------------------------------------------\n");
}
/////////////////// FUNCOES AUXILIARES FIM
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////// FUNCAO PRINCIPAL INICIO
int main() {
    
    system("clear");
    printf("Entrada de dados padrao sera o teclado\n");
    printf("Digite o arquivo que sera fonte de dados: ");
    char arquivoNome[256]; scanf("%[^\n]", arquivoNome); while( getchar() != '\n' );
    
    FILE* arquivo = fopen(arquivoNome, "r");
    if( arquivo == NULL ) {
        printf("PROBLEMA PARA CARREGAR ARQUIVO '%s'\n", arquivoNome);
        exit(1);
    }
    
    tabela* tbl = tabelaInicializar();
    
    sistemaNucleo(tbl, arquivo);
    
    printf("Digite uma ocorrencia: ");
    int n; scanf("%d", &n); while(getchar() != '\n');
    imprimirOcorrencia( tbl, n );
    getchar();

    printf("\n\nFIM LEITURA\n");
    getchar();
    
    return 0;
}
/////////////////// FUNCAO PRINCIPAL FIM
