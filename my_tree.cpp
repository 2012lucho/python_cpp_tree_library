#include <iostream>

// Estructura que se encargará de almacenar la información del nodo del arbol
struct list_data {
    char *key;
    bool *data;
    char *data_type;
    list_data *next = NULL;
};

class tree_data {
    list_data *data = NULL;
// Crea un nuevo elemnto a ser añadido a la lista
    list_data *new_element(){
        list_data *element;

        return element;
    }
//Obtiene el ultimo de la lista
    list_data *get_last(){
        list_data *current = this->data;
        while ( current->next != NULL ) {
            current = current->next;
        }
        return current;
    }

    public:
//Agrega un elemento a la lista
        void set(){
            list_data *element;
            element = this->new_element();

            if (this->data == NULL){
                this->data = element;
            } else {
                list_data *last_element = this->get_last();
                last_element->next = element;
            }
        }

        void unset( char key[] ){

        }
};

struct tree {
    int id;
    tree_data data;
    tree *left,*right;
};

class Foo{
    public:
        void bar(){
            list_data test;
            char key[] = "hola sdf";
            int data_size = 20;
            bool data[data_size];
            data[2] = 1;

            test.key = key;
            test.data = data;
            std::cout << test.data[2] << std::endl;
        }
};
 
extern "C" {
    Foo* Foo_new(){ return new Foo(); }
    void Foo_bar(Foo* foo){ foo->bar(); }
}
