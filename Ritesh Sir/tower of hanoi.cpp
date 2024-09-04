#include <iostream>

using namespace std;

// FUNCTION TO SOLVE THE TOWER OF HANOI PROBLEM
void toh(int n, int from, int to, int aux) {
    // BASE CASE: ONLY ONE DISK TO MOVE
    if (n == 1) {
        cout << "Move disk 1 from rod " << from << " to rod " << to << endl;
        return;
    } 
    else {
        // RECURSIVE CALL TO MOVE N-1 DISKS FROM 'FROM' ROD TO 'AUX' ROD
        toh(n - 1, from, aux, to);

        // MOVE THE N-TH DISK FROM 'FROM' ROD TO 'TO' ROD
        cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;

        // RECURSIVE CALL TO MOVE N-1 DISKS FROM 'AUX' ROD TO 'TO' ROD
        toh(n - 1, aux, to, from);
    }
}

int main() {
    // SOLVING TOWER OF HANOI FOR 4 DISKS
    toh(4, 1, 3, 2);
    return 0;
}
