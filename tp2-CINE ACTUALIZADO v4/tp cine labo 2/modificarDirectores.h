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
    cout<<"MODIFICAR NOMBRE"<<endl;
    cout<<"MODIFICAR NACIONALIDAD"<<endl;
    cout<<"MODIFICAR FECHA DE NACIMIENTO"<<endl;
    //cout<<""<<endl;
    cout<<endl;
    cout<<"ELIJA UNA OPCION: "endl;
    cin>>opc;
    while(true)
    {
        switch(opc)
        {
        case 1: if( modificarNombre()==0){cout<<"EL NOMBRE HA SIDO MODIFICADO CORRECTAMENTE"<<endl}
        else{cout<<"EL NOMBRE NO FUE MODIFICADO"};

            break;
        case 2: modificarNacionalidad();
            break;
        case 3: modificarFnacimiento();
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
  obj.leerEnDisco(pos++)
  {
     if(id==obj.getidDirector()&& obj.getEstado()==true)
     {
         cout<<"INGRESE EL NOMBRE DEL DIRECTOR: ";
         cargarCadena(nombre,29);
         obj.setnombreDirector(nombre);
         return 0;
     }
  }
  return 1;
}




#endif // MODIFICARDIRECTORES_H_INCLUDED
