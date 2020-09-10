#define MAX 100

struct bebida
{
    char nome[20];
    int volume;
    float preco;
};

typedef struct lista Lista;

Lista* inicializa();

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int insere_ord(Lista* li, struct bebida* b1);

int remove_ord(Lista* li, char* nome);

struct bebida get_pos(Lista* li, int pos);

