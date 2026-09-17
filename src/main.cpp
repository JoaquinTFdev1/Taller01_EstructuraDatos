#include <iostream>
#include "Hospital.h"

using namespace std;


int main() {

    cout << "================================" << endl;
    cout << "       HOSPITAL MARMAJA         " << endl;
    cout << "================================" << endl;


    Hospital hospital;


    cout
        << "\nServicios registrados:"
        << endl;


    hospital.mostrarServicios();


    return 0;
}