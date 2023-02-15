#include <iostream>

enum class byte : std::uint8_t {};

// Estructura que se encargará de almacenar la información del nodo del arbol
struct list_data {
    char *key;
    byte *data;
    int  data_size;
    list_data *next = NULL;
};

class TreeData {
    list_data *data = NULL;
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
        void add( list_data *element ){
            if (this->data == NULL){
                this->data = element;
            } else {
                list_data *last_element = this->get_last();
                last_element->next = element;
            }
        }
//Busca un elemento en la lista
        list_data *find( char key[] ){
            list_data *current = this->data;
            
            if (current == NULL) return NULL;

            while (true){
                if (current->key == key) return current;
                
                if (current->next == NULL) return NULL;
                
                current = current->next;
            }
            return NULL;
        }

//Busca el elemento anterior al especificado
        list_data *find_prev( char key[] ){
            list_data *current = this->data;
            
            if (current == NULL) return NULL;

            while (true){
                if (current->next == NULL) return NULL;
                
                if (current->next->key == key){
                    return current;
                }
                
                current = current->next;
            }
            return NULL;
        }

//Quita un elemento de la lista 
        void unset( char key[] ){
            list_data *prev = this->find_prev( key );
            
            if (prev == NULL) return;
            
            list_data *aux = prev->next;
            list_data *sig = prev->next->next;
            delete aux;
            prev->next = sig;
        }
};

struct tree {
    int id;
    TreeData data;
    tree *left,*right;
};

class Foo{
    public:
        void bar(){

            list_data *element;
            byte data[4];
            data[2] = (byte)45;

            char key[] = "hola sdf";
            element->key       = key;
            element->data      = data;
            element->data_size = 4;

            tree arbol;
            arbol.data.add( element );

            list_data *encontrado = arbol.data.find( element->key );
            std::cout << (int)encontrado->data[2] << std::endl;
        }
};
 
extern "C" {
    Foo* Foo_new(){ return new Foo(); }
    void Foo_bar(Foo* foo){ foo->bar(); }
}
