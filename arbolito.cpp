#include <iostream>
#include <queue>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

void imprimirMayores(Nodo* nodo, int x){
    if(nodo==nullptr){
        return;
    }
    imprimirMayores(nodo->derecha,x);
    if(nodo->valor>x){
        cout << nodo->valor <<":";
    }
    if ( nodo->valor>x){
        imprimirMayores(nodo->izquierda,x);

    }
        

    }
void imprimirPorNivel(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }
    queue<Nodo*> cola;
    cola.push(raiz);
    while (!cola.empty()) {
        Nodo* actual = cola.front();
        cola.pop();
        cout << actual->valor << " ";
        if (actual->izquierda != nullptr) {
            cola.push(actual->izquierda);
        }
        if (actual->derecha != nullptr) {
            cola.push(actual->derecha);
        }
    }
    cout << endl;
}


int main() {
    Nodo* raiz = new Nodo(10);
    raiz->izquierda = new Nodo(5);
    raiz->derecha = new Nodo(15);
    raiz->izquierda->izquierda = new Nodo(3);
    raiz->izquierda->derecha = new Nodo(7);
    raiz->derecha->izquierda = new Nodo(12);
    raiz->derecha->derecha = new Nodo(18);

    int x=10;
    cout << " mayores a 10";
    cout << endl;
    imprimirMayores(raiz,x);
    cout << " Niveles";
    imprimirPorNivel(raiz);
    
    
    
    delete raiz->izquierda->izquierda;
    delete raiz->izquierda->derecha;
    delete raiz->derecha->izquierda;
    delete raiz->derecha->derecha;
    delete raiz->izquierda;
    delete raiz->derecha;
    delete raiz;

    return 0;
}
