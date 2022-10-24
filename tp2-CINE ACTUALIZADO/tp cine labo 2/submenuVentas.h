#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

void SubMenuVentas();

void SubMenuVentas(){
    int opc;
    ventas lol;
    while(true){


        system("cls");
        cout<<"MENU VENTAS : "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR VENTA "<<endl;
        cout<<"2) MOSTRAR VENTAS "<<endl;
        cout<<"3) ELIMINAR VENTAS "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: lol.cargar();
                if(lol.grabarEnDisco()==true)
            {
                cout << "REGISTRO AGREGADO! "<<endl;
            }
            else
            {
                cout <<"ERROR AL AGREGAR REGISTRO! "<<endl;
            }
            system("pause");
                    break;
            case 2: lol.mostrarVentas();
                system("pause");
                    break;
            case 3:
                lol.EliminarDeDisco();
                system("pause");
            case 0: return;
                    break;


            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}

#endif // SUBMENUVENTAS_H_INCLUDED
