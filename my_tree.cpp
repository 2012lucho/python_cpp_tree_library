#include <iostream>
#include <string.h>

using namespace std;

// Estructura que se encargará de almacenar la información del nodo del arbol
struct list_data {
    string key;
    byte *data;
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
        list_data *find( string key ){
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
        list_data *find_prev( string key ){
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
        void unset( string key ){
            list_data *prev = this->find_prev( key );
            
            if (prev == NULL) return;
            
            list_data *aux = prev->next;
            list_data *sig = prev->next->next;
            delete aux;
            prev->next = sig;
        }
};

struct TreeNode {
    int id;
    TreeData data;
    TreeNode *left  = NULL;
    TreeNode *right = NULL;
};

class Tree {
    TreeNode *root = NULL;

    public:
        void add( TreeNode *node ){
            if (this->root == NULL) {
                this->root = node;
                return;
            }

            TreeNode *current_node = this->root;
            while(true){
//Si es mayor
                if (current_node->id > node->id) {
                    if (current_node->right == NULL) {
                        current_node->right = node;
                        return;
                    }
                    current_node = current_node->right;
//Si es menor
                } else {
                    if (current_node->left == NULL) {
                        current_node->left = node;
                        return;
                    }
                    current_node = current_node->left;
                }
            }
        }

        char *test( char* node ){
            //std::cout << node << std::endl;
            return node;
        }
};

class Foo{
    public:
        void bar(){
            byte data[4];
            data[2] = (byte)45;

            list_data *element, d;
            element = &d;
            (*element).key  = "hola sdf";
            (*element).data = data;
 
            TreeNode *arbol_node, refN;
            arbol_node = &refN;
            (*arbol_node).id = 50;
            (*arbol_node).data.add( element );

            Tree arbol;
            arbol.add(arbol_node);

            list_data *encontrado = arbol_node->data.find( element->key );
            int date_e = (int)encontrado->data[2];
            
            std::cout << date_e << std::endl;
        }
};
 
extern "C" {
    TreeNode* Tree_node_new(){ return new TreeNode(); }

    Tree* Tree_new(){ return new Tree(); }
    char *Tree_add(Tree* tree, char* test){ return tree->test( test ); }
}
