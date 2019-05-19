#include <iostream>
#include <stdlib.h>
#include "menu.h"

//El primer argumento que se enviará por línea de comando, será el nombre del archivo que se quiere analizar. Es decir trabajadores.txt.

int main(int argc, char const *argv[]){
    system("clear");
    Menu* menu_actual = new Menu();
    menu_actual->iniciar_interfaz(argv[1]);

    delete menu_actual;
    
    return 0;
}