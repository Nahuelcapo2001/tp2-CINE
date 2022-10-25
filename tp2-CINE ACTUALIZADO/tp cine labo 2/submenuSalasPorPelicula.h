#ifndef SUBMENUSALASPORPELICULA_H_INCLUDED
#define SUBMENUSALASPORPELICULA_H_INCLUDED
void SubMenuSalasPorPelicula();

void SubMenuSalasPorPelicula()
{
    int opc;
    SalasPorPelicula obj;
    while(true){


        system("cls");
        cout<<"MENU SALAS POR PELICULA : "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR SALAS POR PELICULA "<<endl;
        cout<<"2) MOSTRAR SALAS POR PELICULA "<<endl;
        cout<<"3) ELIMINAR SALAS POR PELICULA "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: obj.cargar();
                if(obj.grabarEnDisco()==true)
            {
                cout << "REGISTRO AGREGADO! "<<endl;
            }
            else
            {
                cout <<"ERROR AL AGREGAR REGISTRO! "<<endl;
            }
            system("pause");
                    break;
            case 2: obj.mostrarSalasPorPelicula();
                system("pause");
                    break;
            case 3:
                obj.EliminarDeDisco();
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


#endif // SUBMENUSALASPORPELICULA_H_INCLUDED
