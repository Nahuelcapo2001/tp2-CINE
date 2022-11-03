#ifndef MODIFICARDIRECTORES_H_INCLUDED
#define MODIFICARDIRECTORES_H_INCLUDED
void modificarDirector();
bool modificarNombre();
bool modificarNacionalidad();
bool modificarFnacimiento();

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
            if(modificarNacionalidad()==true)
            {
                cout<<"LA NACIONALIDAD HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                return;
            }
            else
            {
                cout<<"EL ID DE DIRECTOR NO ES VALIDO"<<endl;
            }

            break;
        case 3:
            if (modificarFnacimiento()==true)
            {
                cout<<"LA FECHA DE NACIMIENTO HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                return;
            }
            else
            {
                cout<<"EL ID DE DIRECTOR NO ES VALIDO"<<endl;
            }
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

bool modificarNacionalidad()
{
  director obj;
    int pos=0,id;
    char nac[20];
    cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR A MODIFICAR: ";
    cin>>id;
    while(obj.leerEnDisco(pos++))
    {
        if(id==obj.getidDirector()&& obj.getEstado()==true)
        {
            cout<<"INGRESE LA NACIONALIDAD DEL DIRECTOR: ";
            cargarCadena(nac,19);
            obj.setNacionalidad(nac);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;

}
bool modificarFnacimiento()
{
director obj;
    int pos=0,id;
    Fecha nac;
    cout<<"INGRESE EL NUMERO DE ID DEL DIRECTOR A MODIFICAR: ";
    cin>>id;
    while(obj.leerEnDisco(pos++))
    {
        if(id==obj.getidDirector()&& obj.getEstado()==true)
        {
            cout<<"INGRESE LA FECHA DE NACIMIENTO DEL DIRECTOR: ";
            nac.Cargar();
            obj.setFechaNacimiento(nac);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
}


#endif // MODIFICARDIRECTORES_H_INCLUDED
