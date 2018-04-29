#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
//codigo sacado de stackoverflow.com

char* substr(char* cadena, int comienzo, int longitud)
{
    if (longitud == 0) 
        longitud = strlen(cadena)-comienzo;
    
    char *nuevo = (char*)malloc(sizeof(char) * (longitud+1));
    nuevo[longitud] = '\0';
    strncpy(nuevo, cadena + comienzo, longitud);
    
    return nuevo;
}
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}
//Desde aquí empieza mi codigo
int isIn(char * array, char charCompare){
    int sz;
    int i = 0;
    sz = sizeof(array);
    for (i = 0; i < sz ; i++ ) {
        if (array[i] == charCompare)
            return i;

    }
    return -1;
}
void printGramar(char *noTerm ,char **rules[] , int numberTerm){
    int i = 0;
    for (i = 0; i < numberTerm; i++){
            printf("Regla  ° %c :",  noTerm[i]);
            int j = 0;
            for (j = 0; *(rules[i] + j ); j++)
                printf("%s |", *(rules[i] + j) );
        }

}
typedef struct ElementoLista {
    char mainData; //No terminal como A,B,C
    int opcion; //Enumera la opción actual
    int posR; //Posicion de la regla actual
    int posS; //En caso  de que falle algo mas adelante tendra que retornar el ultimo string valido
    struct ElementoLista *siguiente;
}Elemento;
void addNextE(struct ElementoLista from, struct ElementoLista to );
void initEl(struct  ElementoLista * e, char dt, int possR, int possS);

typedef struct ListaUbicacion{
    Elemento *inicio;
    int size;
} Pila;

void initPila(Pila * pl);
int add(Pila * pl , Elemento * el);
int pop(Pila * pl);

bool accepted(char * test, char *noTerm ,char **rules[] , int numberTerm){
    Elemento  elementoInicial;
    Pila  pl;
    int t = 0;
    initEl(&elementoInicial, noTerm[0], 0, 0 );

    initPila( & pl);
    
    //t = add(&pl , &elementoInicial);
    
    //t = pop(&pl );
     //initEl(&elementoInicial, noTerm[1], 1, 1 );
    
     printf("%d", elementoInicial.mainData);
   //    printf("%d", pl.size);
   // printf("%d", t);
     // printf("%c" , pl.inicio ->mainData);
   
}
int main()
{
    /*
    En resumen cargamos un archivo, leemos las reglas gramaticales y las separamos en dos partes
    El primero es un arreglo que contiene el conjunto de los no terminales (A, B , C)

    La segunda es un arreglo que tiene cada uno de las reglas 
    */
    int countLine, i;
    char line[256];
    char *test; 
    FILE *file;
    file = fopen("gram","r");
    countLine = 0;
    i = 0;
    //Si abre el archivo entonces cargamos a memoria las reglas
    if (file) {
        while ( fgets(line , sizeof(line),file))
            countLine++; //contamos las lineas
            //Se supoen que hay n reglas (countLines)    
        char noTerm[countLine];  //declaramos las reglas segun cuantas lineas hay
        char ** rules[countLine];
        
        rewind(file);
        //Volvemos al principio del documento para cargar las reglas
        while ( fgets(line , sizeof(line),file)){
            noTerm[i] =line[0] ;
            test =  substr(line , 4,strlen(line)-5);
        
            rules[i] = str_split(test , '|');
            int j = 0;
            i++;
        }
        fclose(file);

        //noTerm = conjunto de los no terminales
        //rules = producciones
/*        for (i = 0; i < countLine; i++){
            printf("Regla  ° %c :",  noTerm[i]);
            int j = 0;
            for (j = 0; *(rules[i] + j ); j++)
                printf("%s |", *(rules[i] + j) );
        }
*/
        accepted("hola", noTerm, rules, countLine);


    }//fin el if principal
    
}

void addNextE( struct ElementoLista from, struct ElementoLista to ){
    from.siguiente = &to;
}

void initEl(struct ElementoLista *e, char dt, int possR, int possS){
    e -> mainData = dt;
    e -> posR = possR;
    e -> posS = possS;
    e -> opcion = 1;
    e -> siguiente = NULL;
    
}
void initPila(Pila * pl){
    pl ->inicio = NULL;
    pl ->size = 0;

}
int add(Pila * pl , Elemento * el){
    Elemento * es;
   /*
    strcpy(es -> opcion, el-> opcion );
    strcpy(es -> posS, el->posS );
    strcpy(es -> posR, el->posR );
    strcpy(es -> siguiente, el->siguiente );
    
   */ 
    el -> siguiente = pl -> inicio;
    pl -> inicio  = es;
    pl -> size++;
    return pl->size;
} 
int pop(Pila * pl){
    Elemento *sup_elemento;
    if (pl->size == 0)
        return -1;
    sup_elemento = pl->inicio;
    printf("%c", sup_elemento->mainData);
    pl->inicio = pl->inicio->siguiente;
   // free (sup_elemento->mainData);
    
    //free (sup_elemento);
    pl->size--;
    return pl->size;
}
