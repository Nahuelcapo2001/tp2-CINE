#ifndef MODIFICARDIRECTORES_H_INCLUDED
#define MODIFICARDIRECTORES_H_INCLUDED
void modificarDirector();
bool modificarNombre();
void modificarNacionalidad();
void modificarFnacimiento();

void modificarDirector()
{
    int opc;
    cout<<endl;
    cout<<"MENU MODIFICAR DIRECTOR"<<endl;
    cout<<endl;
    cout<<"1) MODIFICAR NOMBRE"<<endl;
    cout<<"2) MODIFICAR NACIONALIDAD"<<endl;
    cout<<"3) MODIFICAR FECHA DE NACIMIENTO"<<endl;
    cout<<endl;
    cout<<"0) VOLVER A DIRECTORES"<<endl;
    cout<<"ELIJA UNA OPCION: "<<endl;
    cin>>opc;
    while(true)
    {
        switch(opc)
        {
        case 1:
            if( modificarNombre()==true)
            {
                cout<<"EL NOMBRE HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                return;
            }
            else
            {
                cout<<"EL ID DE DIRECTOR NO ES VALIDO"<<endl;
            }

            break;
        case 2:
            modificarNacionalidad();
            break;
        case 3:
            modificarFnacimiento();
            break;
        case 0:
            return;
            break;
        default:
            cout<<"OPCION INCORRECTA"<<endl;
            break;

        }
    }
}
bool modificarNombre()
{
    director obj;
    int pos=0,id;
    char nombre[30];
    cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR A MODIFICAR: ";
    cin>>id;
    while(obj.leerEnDisco(pos++))
    {
        if(id==obj.getidDirector()&& obj.getEstado()==true)
        {
            cout<<"INGRESE EL NOMBRE DEL DIRECTOR: ";
            cargarCadena(nombre,29);
            obj.setnombreDirector(nombre);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;

}

void modificarNacionalidad()
{

}
void modificarFnacimiento()
{

}


#endif // MODIFICARDIRECTORES_H_INCLUDED
