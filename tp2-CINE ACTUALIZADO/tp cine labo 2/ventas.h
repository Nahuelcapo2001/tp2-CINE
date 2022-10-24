#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int Nventa, CantEntradas,idPelicula, Pago;
      int Total;
       pelicula obj;
       Salas aux;
       fechaAct fechaVenta;
       bool estado;
    public:
        ///sets()
      void setidPelicula (int id){idPelicula=id;}
      void setNventa (int Nv){Nventa=Nv;}
      void setCantEntradas (int CantE){CantEntradas=CantE;}
      void setPago (int P){Pago=P;}
      void setFechaVenta(fechaAct F) {fechaVenta=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula(){return idPelicula;}
      int getNventa (){return Nventa;}
      int getCantEntradas (){return CantEntradas;}
      int getTotal (){return Total;}
      int getPago (){return Pago;}
      fechaAct getFecha () {return fechaVenta;}

      bool getEstado(){return estado;}
      ///disco

      void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      int grabarEnDisco();
      int leerEnDisco(int);
      bool recuventa();
      bool backupventa();
      int LeerDeDiscobkp(int pos);

    bool cargarVentas()
      {
          FILE *p;
          bool escribio;
          ventas reg;
          p=fopen("ventas.dat","ab");
          if (p==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,p);
              fclose(p);
              return escribio;

      }



void mostrarVentas()
{
    FILE *p;
    p=fopen("ventas.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (ventas),1,p)==1)
    {
        mostrar();
    }
    fclose(p);
}


void cargar(){
    estado=true;
    Nventa=autonumericoIDVentas()+1;
    cout<<"NUMERO DE VENTA : "<<Nventa<<endl;
    cout<<"INGRESE EL ID DE LA PELICULA: " <<endl;//falta validacion
    cin>>idPelicula;
        while(validacionIDpelicula(idPelicula)==1){
        cout <<"\n EL ID INGRESADO YA EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;
        cin>>idPelicula;
    }
    cout<<endl;
    cout<<"FECHA DE VENTA"<<endl;
    fechaVenta.Cargar();
    cout<<"INGRESE CANTIDAD DE ENTRADAS: ";
    cin>>CantEntradas;
    cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]"<<endl;
    cin >>Pago;
    cout<<"EL IMPORTE ES DE: ";
    int importe;
    importe=aux.getPrecio();
    Total=validacionPrecio(Pago,importe);
    Total=Total*CantEntradas;
    cout<< Total<<endl;


}


void mostrar()
{
    if(estado==true)
    {

    cout<<"NUMERO DE VENTA: "<<Nventa<<endl;
    cout<<"ID DE LA PELICULA: ";
    cout<<idPelicula<<endl;
    cout<<"FECHA DE VENTA"<<endl;
    fechaVenta.Mostrar();
    cout<<"CANTIDAD DE ENTRADAS: ";
    cout<<CantEntradas<<endl;
    cout<<"METODO DE PAGO: ";
    cout<<Pago<<endl;
    cout<<"IMPORTE: ";
    cout<< Total<<endl;
    cout<<endl;
    }

}

};
void ventas::EliminarDeDisco(){
       int pos=0;
       int idV;
        cout<<"INTRODUZCA EL ID DE VENTA A ELIMINAR: ";cin>>idV;
        while(leerEnDisco(pos)==1){
                if(getNventa()==idV){
                        cout<<"EL ID DE VENTA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}
int ventas::ModificarEnDisco(int pos)
{

    FILE *p;
    p=fopen("ventas.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(ventas)*pos,0);
    int escribio=fwrite(this,sizeof(ventas),1,p);
    fclose(p);
    return escribio;
}
int ventas::grabarEnDisco()
{
    FILE *p;
    p=fopen("ventas.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(ventas),1,p);
    fclose(p);
    return escribio;
}

int ventas::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("ventas.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(ventas)*pos,0);
    int leyo=fread(this,sizeof(ventas),1,p);
    fclose(p);
    return leyo;
}
///BACKUP
int ventas::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/ventas.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(ventas)*pos,0);
    int leyo=fread(this,sizeof(ventas),1,A);
    fclose(A);
    return leyo;


}

bool ventas::backupventa(){

int pos=0;
FILE *b;
    b=fopen("backup/ventas.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(ventas),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool ventas::recuventa(){
int pos=0;
FILE *br;
    br=fopen("ventas.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(ventas),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }

#endif // VENTAS_H_INCLUDED
