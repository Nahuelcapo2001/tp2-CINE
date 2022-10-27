#ifndef SUBMENUPELICULASSALA_H_INCLUDED
#define SUBMENUPELICULASSALA_H_INCLUDED

void SubMenuPeliculasSalas();

void SubMenuPeliculasSalas(){
    int opc;
    peliculasSalas aux;
    while(true){


        system("cls");
        cout<<"MENU PELICULAS POR SALAS "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR PELICULAS A UNA SALA "<<endl;
        cout<<"2) MOSTRAR  LO CARGADO"<<endl;
        cout<<"3) ELIMINAR REGISTRO "<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                aux.cargar();
                if(aux.grabarEnDisco()==1){cout<<"REGISTRO AGREAGADO! "<<endl;}else{cout<<"ERROR AL GRABAR! "<<endl;}
                system("pause");
            break;

            case 2:
                aux.mostrarDeDisco();
                system("pause");
            break;
            case 3:
                aux.EliminarDeDisco();
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

#endif // SUBMENUPELICULASSALA_H_INCLUDED
