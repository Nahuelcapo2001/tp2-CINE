#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <windows.h>
using namespace std;
#include "protoFunciones.h"
#include "fecha.h"
#include "directores.h"
#include "salas.h"
#include "peliculas.h"
#include "ventas.h"
#include "salasPorPelicula.h"
#include "submenuSalas.h"
#include "submenuPeliculas.h"
#include "submenuDirectores.h"
#include "submenuVentas.h"
#include "submenuSalasPorPelicula.h"
#include "submenuConfiguracion.h"
#include "funcionesGlobales.h"




int main(){
    int opc;
    director obj;
    ventas lol;
    while(true){

        cout<<("MENU PRINCIPAL ")<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MENU DIRECTORES "<<endl;
        cout<<"2) MENU SALAS "<<endl;
        cout<<"3) MENU PELICULAS"<<endl;
        cout<<"4) MENU VENTAS ENTRADAS"<<endl;
        cout<<"5) MENU SALAS POR PELICULA"<<endl;
        cout<<"6) MENU CONFIGURACION"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: SubMenuDirector();
                    break;
            case 2: SubMenuSalas();
                break;
            case 3: SubMenuPeliculas();
                    break;
            case 4: SubMenuVentas();
                    break;
            case 5: SubMenuSalasPorPelicula();
                    break;
            case 6: SubmenuConfiguracion();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;

    }

    return 0;
}
