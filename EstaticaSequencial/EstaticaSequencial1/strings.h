
#define MAX 20

typedef struct lista Lista;


Lista* inicializar_lista();

void libera_lista(Lista *lst);

int lista_vazia(Lista *lst);

int lista_cheia(Lista *lst);

int insere_elem(Lista *lst, char str[10]);

int remove_elem(Lista *lst);

char *get_pos(Lista *lst, int pos);
