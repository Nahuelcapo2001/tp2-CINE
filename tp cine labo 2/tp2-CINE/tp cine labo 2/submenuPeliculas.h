#ifndef SUBMENUPELICULAS_H_INCLUDED
#define SUBMENUPELICULAS_H_INCLUDED

void SubMenuPeliculas();

void SubMenuPeliculas(){
    int opc;
    pelicula reg;
    while(true){
        system("cls");
        cout<<"MENU PELICULAS"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR PELICULA "<<endl;
        cout<<"2) MOSTRAR PELICULAS "<<endl;
        cout<<"3) ELIMINAR PELICULA "<<endl;
        cout<<"-----------------------------"endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){

            case 1://AGREGAR PELICULA
                reg.cargar();
                if(reg.grabarEnDisco()==1){cout<<"REGISTRO AGREGADO! ";}else{"ERROR AL GRABAR! ";}
                system("pause");
            break;

            case 2://MOSTRAR PELICULAS
                reg.mostrarPeliculas();
                system("pause");
            break;
            case 3: //ELIMINAR PELICULA
                reg.EliminarDeDisco();
                system("pause");
            case 0: return ;
                    break;
            default: cout<<"OPCION INCORRECTA! "<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}

#endif // SUBMENUPELICULAS_H_INCLUDED
