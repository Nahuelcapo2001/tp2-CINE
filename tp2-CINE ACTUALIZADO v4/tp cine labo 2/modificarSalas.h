#ifndef MODIFICARSALAS_H_INCLUDED
#define MODIFICARSALAS_H_INCLUDED

void modificarSalas();
bool modificarTipoSala();
bool modificarCantButacas();
bool modificarPrecioSala();

void modificarSalas()
{
    int opc;
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    cout<<"           MENU MODIFICAR SALAS"<<endl<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    cout<<"1)        MODIFICAR TIPO DE SALA"<<endl;
    cout<<"2)      MODIFICAR CANTIDAD DE BUTACAS"<<endl;
    cout<<"3)       MODIFICAR PRECIO DE LA SALA"<<endl;
    cout<<"0)          VOLVER MENU SALAS"<<endl;
    cout<<"--------------------------------------------------"<<endl<<endl;
    cout<<"ELIJA UNA OPCION: "<<endl;
    cin>>opc;
    while(true)
    {
        switch(opc)
        {
        case 1: if( modificarTipoSala()==true)
            {
                cout<<"EL TIPO DE SALA HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                return;
            }
            else
            {
                cout<<"EL ID DE SALA NO ES VALIDO"<<endl;
            }
            break;
        case 2:if( modificarCantButacas()==true)
            {
                cout<<"LA CANTIDAD DE BUTACAS HA SIDO MODIFICADA CORRECTAMENTE"<<endl;
                return;
            }
            else
            {
                cout<<"EL ID DE SALA NO ES VALIDO"<<endl;
            }
            break;
        case 3:if( modificarPrecioSala()==true)
            {
                cout<<"EL PRECIO DE SALA HA SIDO MODIFICADO CORRECTAMENTE"<<endl;
                return;
            }
            else
            {
                cout<<"EL ID DE SALA NO ES VALIDO"<<endl;
            }
            break;
        case 0:return;
            break;
        default:cout<<"ELIJA UNA OPCION VALIDA"<<endl;
            break;
        }
    }
}
bool modificarTipoSala()
{
   Salas obj;
    int pos=0,id;
    char tipo[3];
    cout<<"INGRESE EL NUMERO DE ID DE LA SALA A MODIFICAR: ";
    cin>>id;
    while(obj.leerEnDisco(pos++))
    {
        if(id==obj.getidSala()&& obj.getEstado()==true)
        {
            cout<<"INGRESE LA TIPO DE SALA: ";
            cargarCadena(tipo,2);
            obj.setTipo(tipo);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
}
bool modificarCantButacas()
{
Salas obj;
    int pos=0,id,cant;
    cout<<"INGRESE EL NUMERO DE ID DE LA SALA A MODIFICAR: ";
    cin>>id;
    while(obj.leerEnDisco(pos++))
    {
        if(id==obj.getidSala()&& obj.getEstado()==true)
        {
            cout<<"INGRESE LA CANTIDAD DE BUTACAS: ";
            cin>>cant;
            obj.setPlazas(cant);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
}
bool modificarPrecioSala()
{
Salas obj;
    int pos=0,id,prec;
    cout<<"INGRESE EL NUMERO DE ID DE LA SALA A MODIFICAR: ";
    cin>>id;
    while(obj.leerEnDisco(pos++))
    {
        if(id==obj.getidSala()&& obj.getEstado()==true)
        {
            cout<<"INGRESE EL PRECIO DE LA SALA: ";
            cin>>prec;
            obj.setPrecio(prec);
            obj.ModificarEnDisco(pos-1);
            return true;
        }
    }
    return false;
}



#endif // MODIFICARSALAS_H_INCLUDED
