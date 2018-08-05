typedef struct tree_node_struct {
    char description[255];
    char value[255];
    int node_brother_count;
    struct tree_node_struct *father, *brother, *child;
} NODE;

// Estrutura usada para adicionar um novo no na arvore
typedef struct description_and_value_data_for_the_tree {
    char description[255];
    char value[255];
} description_and_value_data_for_the_tree;

// Estrutura usada para adicionar novas linhas na Tabela de Símbolos:
typedef struct data_for_the_symbol_table {
    char name[255];
    char type[255];
    char category[255];
    int isFormalArg;
} data_for_the_symbol_table;

// Tabela de Símbolos:
typedef struct symbol_table_struct {
    char name[255];
    char value[255];
    // o escopo pode ser global (no caso de funções) ou o nome da função em que está (no caso de variáveis)
    char scope[255];
    char type[255];
    char category[255];
    int isFormalArg;
    struct symbol_table_struct *previous, *next;
} symbol_table_struct;