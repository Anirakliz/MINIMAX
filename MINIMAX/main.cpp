#include <iostream>
#include <vector>

using namespace std;

// Función que verifica si todos los palitos han sido tomados
bool gameOver(const vector<int>& sticks) {
    for (int i = 0; i < sticks.size(); i++) {
        if (sticks[i] > 0) {
            return false;
        }
    }
    return true;
}

// Función que muestra el estado actual de los palitos
void displaySticks(const vector<int>& sticks) {
    cout << "Palitos: ";
    for (int i = 0; i < sticks.size(); i++) {
        cout << sticks[i] << " ";
    }
    cout << endl;
}

// Función que realiza el movimiento del jugador humano
void playerMove(vector<int>& sticks) {
    int pile, count;
    cout << "Elige la pila (0-indexada): ";
    cin >> pile;
    cout << "Elige la cantidad de palitos a tomar: ";
    cin >> count;
    sticks[pile] -= count;
}

// Función que realiza el movimiento de la IA utilizando el algoritmo MiniMax
void aiMove(vector<int>& sticks) {
    int nimSum = 0;
    for (int i = 0; i < sticks.size(); i++) {
        nimSum ^= sticks[i];
    }

    for (int i = 0; i < sticks.size(); i++) {
        int target = nimSum ^ sticks[i];
        if (target < sticks[i]) {
            sticks[i] = target;
            break;
        }
    }
}

int main() {
    int numPiles;
    cout << "Ingrese el número de pilas: ";
    cin >> numPiles;

    vector<int> sticks(numPiles);
    for (int i = 0; i < numPiles; i++) {
        cout << "Ingrese el número de palitos en la pila " << i << ": ";
        cin >> sticks[i];
    }

    while (!gameOver(sticks)) {
        displaySticks(sticks);
        playerMove(sticks);

        if (gameOver(sticks)) {
            cout << "¡Has ganado!" << endl;
            break;
        }

        aiMove(sticks);

        if (gameOver(sticks)) {
            cout << "¡La IA ha ganado!" << endl;
            break;
        }
    }

    return 0;
}
