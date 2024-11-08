#include <iostream>
using namespace std;



struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};


void insertar(Nodo*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new Nodo(valor);
    } else if (valor < nodo->valor) {
        insertar(raiz->izquierda, valor);
    } else if {
        insertar(raiz->derecha, valor);
    } else{
        return raiz; // es un nodo duplicado ( mismo valor)
    }
    
}
int altura(Nodo* raiz) {
    if (!nodo) return 0;

    int alturaIzquierda = altura(nodo->izquierda);
    int alturaDerecha = altura(nodo->derecha);

    if (alturaIzquierda > alturaDerecha)
        return 1 + alturaIzquierda;
    else
        return 1 + alturaDerecha;
}

int factorBalance(Nodo* raiz) {
    if (!raiz) return 0;
    return altura(raiz->izquierda) - altura(raiz->derecha);
}

Nodo* balancearNodo(Nodo* raiz) {
    int balance = factorBalance(raiz);

    if (balance > 1 && factorBalance(raiz->izquierda) >= 0) {
        return rotacionDerecha(raiz);
    }

    if (balance < -1 && factorBalance(raiz->derecha) <= 0) {
        return rotacionIzquierda(raiz);
    }

    if (balance > 1 && factorBalance(raiz->izquierda) < 0) {
        return rotacionIzquierdaDerecha(raiz);
    }

    if (balance < -1 && factorBalance(raiz->derecha) > 0) {
        return rotacionDerechaIzquierda(raiz);
    }

    return raiz;
}

int main() {
    Nodo* raiz = nullptr;

    
   

    return 0;
}