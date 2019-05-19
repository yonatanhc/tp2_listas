#include "menu.h"

Menu::Menu(){
    opcion_usuario = MENU_ACTIVO;
    lista_principal = new Lista();
}

void Menu::iniciar_interfaz(char const* archivo){
    cargar_trabajador_desde_archivo(archivo);
    while(opcion_usuario != OPCION_SALIR){
        mostrar_menu();
        recibir_opcion();
        ejecutar_opcion();
    }
}

void Menu::cargar_empleado(Empleado* empleado,float sueldo_mensual,int llegadas_tarde,int ausencias){
    empleado->asignar_sueldo_mensual(sueldo_mensual);
    empleado->asignar_llegadas_tarde(llegadas_tarde);
    empleado->asignar_ausencias(ausencias);
    Trabajador* aux = empleado;
    aux->asignar_sueldo_a_cobrar(aux->liquidar_sueldo());
    lista_principal->agregar(aux);
}

void Menu::cargar_jornalero(Jornalero* jornalero,float sueldo_diario,int dias_trabajados){
    jornalero->asignar_sueldo_diario(sueldo_diario);
    jornalero->asignar_dias_trabajados(dias_trabajados);
    Trabajador* aux = jornalero;
    aux->asignar_sueldo_a_cobrar(aux->liquidar_sueldo()); 
    lista_principal->agregar(aux);
}

void Menu::cargar_consultor(Consultor* consultor,float sueldo_hora_catedra,int cantidad_horas_catedra,int dias_a_descontar){
    consultor->asignar_sueldo_hora_catedra(sueldo_hora_catedra);
    consultor->asignar_cantidad_horas_catedra(cantidad_horas_catedra);
    consultor->asignar_horas_a_descontar(dias_a_descontar);
    Trabajador* aux = consultor;
    aux->asignar_sueldo_a_cobrar(aux->liquidar_sueldo()); 
    lista_principal->agregar(aux);
}

void Menu::cargar_trabajador_desde_archivo(char const* archivo){
    int legajo=0, llegadas_tarde=0, ausencias=0, dias_trabajados=0, cantidad_horas_catedra=0, dias_a_descontar=0;
    string nombre;
    char tipo_de_trabajador='a';
    float sueldo_mensual=0, sueldo_diario=0, sueldo_hora_catedra=0;
    ifstream archivo_trabajadores(archivo);
    while(archivo_trabajadores >> tipo_de_trabajador){
        archivo_trabajadores >> legajo;
        archivo_trabajadores >> nombre;
        if(tipo_de_trabajador == TIPO_EMPLEADO){
            Empleado* empleado = new Empleado(legajo,nombre);
            archivo_trabajadores >> sueldo_mensual;      
            archivo_trabajadores >> llegadas_tarde;
            archivo_trabajadores >> ausencias;
            cargar_empleado(empleado,sueldo_mensual,llegadas_tarde,ausencias);  
        }else if(tipo_de_trabajador == TIPO_JORNALERO){
            Jornalero* jornalero = new Jornalero(legajo,nombre);
            archivo_trabajadores >> sueldo_diario;
            archivo_trabajadores >> dias_trabajados;
            cargar_jornalero(jornalero,sueldo_diario,dias_trabajados); 
        }else if(tipo_de_trabajador == TIPO_CONSULTOR){
            Consultor* consultor = new Consultor(legajo,nombre);
            archivo_trabajadores >> sueldo_hora_catedra;
            archivo_trabajadores >> cantidad_horas_catedra;
            archivo_trabajadores >> dias_a_descontar;
            cargar_consultor(consultor,sueldo_hora_catedra,cantidad_horas_catedra,dias_a_descontar);
        }
        else{
            cout << "ERROR, EN EL ARCHIVO DE TEXTO HAY UN TIPO DE EMPLEADO INVÁLIDO" << endl;
        }
    }
}

void Menu::recibir_opcion(){
    cin >> opcion_usuario;
    cout << endl << endl;
}

void Menu::ejecutar_opcion(){
    switch(opcion_usuario){
        case OPCION_CONSULTAR_LEGAJO:
            consultar_existencia_de_legajo();
            break;
        case OPCION_DAR_DE_BAJA:
            dar_de_baja_numero_legajo();
            break;
        case OPCION_DE_ALTA:
            menu_alta_trabajador();
            break;
        case OPCION_LISTAR_TRABAJADORES:
            listar_todos_los_trabajadores();
            break;
        case OPCION_SUELDO_MAXIMO:
            indicar_sueldo_maximo();
            break;
        case OPCION_SUELDO_MINIMO:
            indicar_sueldo_minimo();
            break;
        case OPCION_SUMAR_SUELDO:
            indicar_sumatoria_sueldo();
            break;
        case OPCION_SALIR:
            cout << "Saliendo del Menú." << endl <<endl;
            break;
        default:
            cout << "Ingreso invalido. Recuerde que debe ingresar una de las opciones del Menú." << endl << endl;
    }
}

void Menu::mostrar_menu(){
    opcion_usuario = MENU_ACTIVO;
    cout << endl << endl;
    cout << " ******************************************* " << endl;
    cout << " *     Menú de acciones en lista           * " <<endl;	
    cout << " *  Seleccionar una opción del Menú        * " << endl;
    cout << endl;
    cout << " * Consultar si un número de legajo existe [a]" << endl;
    cout << " * Dar de baja cierto número de legajo	   [b]" << endl;
    cout << " * Dar de alta a un trabajador		   [c]" << endl;
    cout << " * Listar todos los trabajadores	   [d]" << endl;
    cout << " * Indicar sueldo máximo 		   [e]" << endl;
    cout << " * Indicar sueldo mínimo                   [f]" << endl;
    cout << " * Sumar todos los sueldos                 [g]" << endl;
    cout << " * Salir 			           [s]" << endl << endl;
    cout << "********************************************"<< endl;
    cout <<endl<< "Por favor ingrese su opción:" << endl <<endl ;
}

void Menu::consultar_existencia_de_legajo(){
    int legajo=0;
    cout << "Ingrese el nÚmero de legajo para verificar si existe o no: " <<endl<<endl;
    cin >> legajo;
    Trabajador* aux = lista_principal->consultar_legajo(legajo);
    if(aux){
        cout<<endl<<"El legajo que usted marcó existe y corresponde a:"<<endl<<endl;
        aux->a_cadena();
    }
    else{
        cout <<endl<< "El legajo que usted marcó no existe. Inténtelo nuevamente! " << endl;
    }
}

void Menu::dar_de_baja_numero_legajo(){
    int legajo=0;
    cout << "Ingrese el numero del legajo a eliminar: " << endl<<endl;
    cin >> legajo;
    bool eliminado = lista_principal->dar_de_baja(legajo);
    if(eliminado){
        cout<<endl<<"El legajo que usted marcó ha sido eliminado correctamente. "<<endl;
    }
    else{
        cout<<endl<<"El legajo que usted marcó no existe. Inténtelo nuevamente! "<<endl;
    }
}

void Menu::listar_todos_los_trabajadores(){
    cout<<"Lista de todos los trabajadores: "<<endl<<endl;
    for (int i = 1; i <= lista_principal->tamanio(); i++){
        Trabajador* aux = lista_principal->obtener_trabajador(i);
        aux->a_cadena();
    }
}

void Menu::indicar_sueldo_maximo(){
    cout<<"El trabajador con el sueldo máximo es: "<<endl<<endl;
    Trabajador* aux = lista_principal->sueldo_maximo();
    aux->a_cadena();
}

void Menu::indicar_sueldo_minimo(){
    cout<<"El trabajador con el sueldo mínimo es: "<<endl<<endl;
    Trabajador* aux = lista_principal->sueldo_minimo();
    aux->a_cadena();
}
            
void Menu::indicar_sumatoria_sueldo(){
    cout <<"La sumatoria de todos los sueldos es $"<< lista_principal->sumar_sueldo() << endl;
}

void Menu::menu_alta_trabajador(){
    int legajo=0;
    string nombre;
    char tipo_de_trabajador='a', opcion='a';
    do {
        cout << "Ingrese nombre del trabajador:" << endl<<endl;
        cin >> nombre;
        cout <<endl<< "Ingrese legajo del trabajador:" << endl<<endl;
        cin >> legajo;
        tipo_de_trabajador='a';
        while(tipo_de_trabajador!='e' and tipo_de_trabajador!='j' and tipo_de_trabajador!='c'){
            cout <<endl<< "Elija el Tipo de Trabajador que desea Dar de Alta:" << endl;
            cout << "Empleado:" << "  " << "[e]" << endl;
            cout << "Jornalero:" << "  " << "[j]" << endl;
            cout << "Consultor:" << "  " << "[c]" << endl<<endl;
            cin >> tipo_de_trabajador;
            if(tipo_de_trabajador!='e' and tipo_de_trabajador!='j' and tipo_de_trabajador!='c'){
                cout<<endl<<"Recuerde que los tipos de trabajador únicamente son 'e' (Empleado), 'c' (Consultor) y 'j' (Jornalero).";
                cout<<" Inténtelo nuevamente."<<endl<<endl;
            }
        }    
        dar_de_alta_trabajador(tipo_de_trabajador,nombre,legajo);
        opcion='a';
        while(opcion!='s' and opcion!='n'){
            cout <<endl<< "¿ Dar de Alta a otro Trabajador ?" << "  " << " s / n" << endl;
            cin >> opcion;
            cout<<endl;
            if(opcion!='s' and opcion!='n'){
                cout<<endl<<"Recuerde que las posibles opciones son 's' (Sí) o n (No). Inténtelo nuevamente."<<endl<<endl;
            }
        }    
    }while(opcion == 's');
}

void Menu::dar_de_alta_trabajador(char tipo_de_trabajador,string nombre,int legajo){
    int llegadas_tarde=0, ausencias=0, dias_trabajados=0, cantidad_horas_catedra=0, dias_a_descontar=0;
    float sueldo_mensual=0, sueldo_diario=0, sueldo_hora_catedra=0;
    switch(tipo_de_trabajador){
        case 'e':
            Empleado* empleado;
            cout <<endl<< "Ingrese sueldo mensual del empleado" << endl<<endl;
            cin >> sueldo_mensual;
            cout <<endl<< "Ingrese llegadas tarde del empleado" << endl<<endl;
            cin >> llegadas_tarde ;
            cout <<endl<<"Ingrese ausencias del empleado" << endl<<endl;
            cin >> ausencias;
            empleado = new Empleado(legajo,nombre);
            cargar_empleado(empleado,sueldo_mensual,llegadas_tarde,ausencias);
            break;
        case 'j':
            Jornalero* jornalero;
            cout << endl<<"Ingrese sueldo diario del jornalero" << endl<<endl;
            cin >> sueldo_diario;
            cout <<endl<< "Ingrese dias trabajados del jornalero" << endl<<endl;
            cin >> dias_trabajados;
            
            jornalero = new Jornalero(legajo,nombre);
            cargar_jornalero(jornalero,sueldo_diario,dias_trabajados);
            break;
        case 'c':
            Consultor* consultor;
            cout << endl<<"Ingrese sueldo hora catedra" << endl<<endl;
            cin >> sueldo_hora_catedra;
            cout <<endl<< "Ingrese cantidad horas catedra" << endl<<endl;
            cin >> cantidad_horas_catedra ;
            cout << endl<<"Ingrese horas cátedra a descontar" << endl<<endl;
            cin >> dias_a_descontar;
            consultor = new Consultor(legajo,nombre);
            cargar_consultor(consultor,sueldo_hora_catedra,cantidad_horas_catedra,dias_a_descontar);
            break;
    }
}

Menu::~Menu(){
    delete lista_principal;
}

