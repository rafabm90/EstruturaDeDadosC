struct alunos
{
    unsigned int matricula;
    char nome[20];
    float media;
    int faltas;
};
typedef struct elemento* Lista;

Lista* inicializa();

int lista_cheia(Lista* li);

int lista_vazia(Lista* li);

int insere_elem(Lista* li, struct alunos *al);

int remove_elem(Lista* li, int mat);

struct alunos get_pos(Lista* li, int pos);

int size_lista(Lista* li);
