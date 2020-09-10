
typedef struct elemento* Lista;

Lista* inicializa();

int lista_vazia(Lista* li);

int lista_cheia(Lista* li);

int insere_ord(Lista* li, int inteiro);

int remove_ord(Lista* li, int inteiro);

int remove_pos(Lista* li, int pos);

int get_pos(Lista* li, int pos);
