#ifndef SUBMENUDIRECTORES_H_INCLUDED
#define SUBMENUDIRECTORES_H_INCLUDED

void SubMenuDirector();

void SubMenuDirector(){

    int opc;
    director reg;
    while(true){
        system("cls");




        cout<<"MENU DIRECTORES ";
        cout<<"-----------------------------"<<endl;
        cout<<"1) AGREGAR DIRECTOR"<<endl;
        cout<<"2) MOSTRAR DIRECTORES "<<endl;
        cout<<"3) ELIMINAR DIRECTOR"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES : "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                reg.cargar();
                if(reg.grabarEnDisco()==1){cout<<"\nREGISTRO AGREGADO"<<endl;}else{cout<<"\nERROR AL GRABAR"<<endl;}
                system("pause");
            break;
            case 2:
                reg.mostrardirectores();
                system("pause");
            break;
            case 3:
                reg.EliminarDeDisco();
                system("pause");
            case 0:
            return ;
            break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                    break;
        }
        cout <<endl;

    }

    return ;
}

#endif // SUBMENUDIRECTORES_H_INCLUDED
