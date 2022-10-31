#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

void SubmenuConfiguracion();

 void SubmenuConfiguracion(){
   director aux;
   pelicula obj;
   Salas salaux;
   ventas reg;
     int opc;
     while(true){



cout<<"MENU CONFIGURACION"<<endl;
cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE DIRECTORES"<<endl;
cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO SALAS"<<endl;
cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO PELICULAS"<<endl;
cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO VENTAS"<<endl;
cout<<"5) RESTAURAR DATOS DE DIRECTORES"<<endl;
cout<<"6) RESTAURAR DATOS DE SALAS"<<endl;
cout<<"7) RESTAURAR DATOS DE PELICULAS"<<endl;
cout<<"8) RESTAURAR DATOS DE VENTAS"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cout<<"SELECCIONE UNA DE LAS OPCIONES: "<<endl;
cin>>opc;
        switch (opc)
        {
        case 1:

            if(aux.backupdirector()==true){cout<<"COPIA DE DIRECTOR REALIZADA";}
            break;
        case 2:

            if(salaux.backupsala()==true){cout<<"COPIA DE SALA REALIZADA";}
            break;
        case 3:

            if(obj.backuppelicula()==true){cout<<"COPIA DE PELICULA REALIZADA";}
            break;
        case 4:

            if(reg.backupventa()==true){cout<<"COPIA DE VENTA REALIZADA;";}
            break;
        case 5:

            if(aux.backupdirector()==true){cout<<"RECUPERACION  DE DIRECTORES REALIZADA";}
            break;
        case 6:

            if(salaux.recusala()==true){cout<<"RECUPERACION DE SALAS  REALIZADA";}
            break;
        case 7:

            if(obj.recupelicula()==true){cout<<"RECUPERACION DE PELICULAS REALIZADA";}
            break;
            case 8:

            if(reg.recuventa()==true){cout<<"RECUPERACION DE VENTAS REALIZADA";}
            break;
        case 0:
                return;
            break;

        default:
            break;
        }
        cout <<endl;
        system("pause");
        system("cls");

}


 }

#endif // SUBMENUCONFIGURACION_H_INCLUDED
