#include <stdio.h>
#include <string.h>
#define N_MAX 1000 //define o tamanho da lista

typedef struct{//registro de dados
    char str[N_MAX];//dados
    int f;//n de registros ocupados
}NODO;//estrutura tipo NODO

//void entrada_dados(char padrao[], NODO *lista);//funçoes declaradas
//void excluir_ponto( int posi, NODO *lista );//funçoes declaradas
void cria_lista(int *fim);//funçoes declaradas
int dima(NODO *lista);//funçoes declaradas


int main() {//funcção main(PRINCIPAL)
    NODO lista;
    char solo[N_MAX];
    int result, inputs;
    int i, proximo_teste = 0;

    fflush(stdin);//limpar teclado
    printf("\n\|---------------------------------------------------|\n\n\t <> ...DIAMANTES E AREIA.... <>\n\n|---------------------------------------------------|");
    printf("\nExemplos de entradas:\n\t <.. ><.<.. >>\n ou\n\t<<<.. <...... <<<<.... >");
    printf("\n\nDigite a quantidade de casos de teste: ");
    scanf("%d", &inputs); // quantidade de casos testes
    for(i=0;i<inputs;i++){//se for 1 teste ele continua, se for +1 teste ele passa por essa validção
        if (inputs == ',')
            printf("ENtrada invalida");
        fflush(stdin);
        proximo_teste++;//incrementa o proximo teste
        printf("Digite o teste %d: ", proximo_teste);
        scanf("%s", solo); // string
        cria_lista( &lista.f );
        entrada_dados(solo, &lista);
        result = dima(&lista);
        printf("%d\n", result);
    }

    return 0;
}
// converte a string em uma lista
void entrada_dados(char solo[], NODO *lista){
    int i, lenstr;
    lenstr = strlen(solo);
    for(i=0;i<lenstr;i++){
        lista->str[i] = solo[i];
        lista->f++;
    }
}
// exclui nodo na posicao
void excluir_ponto( int posi, NODO *lista ){
    int i;

	for( i = posi; i < lista->f-1; i++)
		lista->str[ i ] = lista->str[ i + 1 ];
	lista->f--;
}
// cria lista
void cria_lista(int *fim){
    *fim=0;
}

// conta diamantes
int dima(NODO *lista){
	int dima=0;
	int i=0, j=1, y;
	// i -> primeiro caractere a ser analisado, j-> último.
	while((lista->f != 0)){  // se i = ultimo elemento ou se a lista estiver com apenas 1 nodo
		if(j == lista->f)
			break;
		if( ( lista->str[i] == '<') && ( lista->str[j] == '>') ){
			dima++; // achou um diamante <.<..>
			for(y=0;y<=j-i;y++)  // j-i -> distancia do nodo i ao j
				excluir_ponto(i, lista); // exclui os nodos entre i e j. Ao excluir o nodo = i, todos os nodos = -1, por isso sempre é excluido o nodo i
			i=0;// volta para o começo da string
			j=1;
		}
		else if( ( lista->str[i] == '<') && ( lista->str[j] == '.') )  // verifica se o ultimo caractere da substring é .,E se sim.//entao compara com o proximo
			j++;//entao compara com o proximo
		else if( ( lista->str[i] == '<') && ( lista->str[j] == '<') ){  // verifica se o ultimo caractere da substring é <,E se sim começa a analisar a partir do ultimo elemento da substring
			i = j;
			j++;
			}
		else if( ( lista->str[i] == '>') || ( lista->str[i] == '.') ){ // verifica se o primeiro caractere da substring é ou . ou >, se sim começa a analisar a partir do ultimo elemento da substring
			i = j;
			j++;
            }
	}
	return dima;
}
