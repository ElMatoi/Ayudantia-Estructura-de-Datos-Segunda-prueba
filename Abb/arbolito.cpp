#include <iostream>
#include <queue>
using namespace std;

/* no se implementara la clase arbol, debido que para esta asignatura/prueba se evalua manejar los metodos utilizando "la struct del nodo":
    EJEMPLO DE EVALUACION: GENERE UN METODO PARA BUSCAR UN NODO EN EL ARBOL, UTILIZE LA SIGUIENTE FUNCION Y NO MODIFIQUE LOS PARAMETROS (20 PTS):
        NODO * BUSCARNODO ( NODO* RAIZ, INT VALOR)
 */

struct Nodo {
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int v) : valor(v), izquierda(nullptr), derecha(nullptr) {}
};

void insertar(Nodo*& nodo, int valor) {
    if (nodo == nullptr) {
        nodo = new Nodo(valor);
    } else if (valor < nodo->valor) {
        insertar(nodo->izquierda, valor);
    } else {
        insertar(nodo->derecha, valor);
    }
}

void imprimirMayores(Nodo* nodo, int x) {
    if (nodo == nullptr) {
        return;
    }
    imprimirMayores(nodo->derecha, x);
    if (nodo->valor > x) {
        cout << nodo->valor << " ";
    }
    if (nodo->valor > x) {
        imprimirMayores(nodo->izquierda, x);
    }
}

Nodo* buscarNodo(Nodo* nodo, int valor) {
    if (nodo == nullptr || nodo->valor == valor) {
        return nodo;
    }
    if (valor < nodo->valor) {
        return buscarNodo(nodo->izquierda, valor);
    } else {
        return buscarNodo(nodo->derecha, valor);
    }
}

void recorridoInOrder(Nodo* nodo) {
    if (nodo == nullptr) {
        return;
    }
    recorridoInOrder(nodo->izquierda);
    cout << nodo->valor << " ";
    recorridoInOrder(nodo->derecha);
}

int contarNodosTerminales(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
        return 1;
    }
    return contarNodosTerminales(nodo->izquierda) + contarNodosTerminales(nodo->derecha);
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

void eliminar(Nodo* nodo) {
    if (nodo != nullptr) {
        eliminar(nodo->izquierda);
        eliminar(nodo->derecha);
        delete nodo;
    }
}

int main() {
    Nodo* raiz = nullptr;
    insertar(raiz, 8);
    insertar(raiz, 3);
    insertar(raiz, 10);
    insertar(raiz, 14);
    insertar(raiz, 6);
    insertar(raiz, 1);
    insertar(raiz, 6);

    int x = 8;
    cout << "mayores a " << x << ;
    imprimirMayores(raiz, x);
    cout << endl;

    cout << " print por nivel: ";
    imprimirPorNivel(raiz);

    cout << "print por In-Order: ";
    recorridoInOrder(raiz);
    cout << endl;

    int valor = 6;
    Nodo* encontrado = buscarNodo(raiz, valor);
    if (encontrado != nullptr) {
        cout  << encontrado->valor << endl;
    } else {
        cout <<  valor << " no encontrado"

    cout << "Cantidad de nodos terminales: " << contarNodosTerminales(raiz) << endl;

    eliminar(raiz); 

    return 0;
}
