#ifndef SUBMENUDATOS_H_INCLUDED
#define SUBMENUDATOS_H_INCLUDED

void SubMenuDatos();

void SubMenuDatos(){
    int opc;
    datos reg;
    while(true){

        cout<<"MENU DATOS :"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) MOSTRAR RECAUDACION POR CADA PELICULA "<<endl;
        cout<<"2) MOSTRAR RECAUDACION POR CADA DIRECTOR"<<endl;
        cout<<"3) RECAUDACION TOTAL DE TEEMOPOLIS"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    reg.recaudacionpeliculas();
            system("pause");
                    break;
            case 2:
                reg.recaudaciondirector();
                system("pause");
                    break;
            case 3: reg.RecaudacionCine();
                    system("pause");
                    break;
            case 0: return ;
                    break;
            default: cout<<"OPCION INCORRECTA! "<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}

#endif // SUBMENUDATOS_H_INCLUDED
