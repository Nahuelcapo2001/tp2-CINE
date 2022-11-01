#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

class ventas
{
    private:

      int Nventa, CantEntradas,idPelicula,idSala, Pago,butacastotal=0,butacasvendidas=0,butacassala=0;
      float Total;
       pelicula obj;
       Salas aux;
       SalasPorPelicula reg;
       fechaAct fechaVenta;
       bool estado;
    public:
        ///sets()
      void setidPelicula (int id){idPelicula=id;}
      void setidSala(int ids){idSala=ids;}
      void setNventa (int Nv){Nventa=Nv;}
      void setCantEntradas (int CantE){CantEntradas=CantE;}
      void setPago (int P){Pago=P;}
      void setFechaVenta(fechaAct F) {fechaVenta=F;}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula(){return idPelicula;}
      int getidSala(){return idSala;}
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
    int pos=0, pos1=0;
    Nventa=autonumericoIDVentas()+1;
    cout<<"NUMERO DE VENTA : "<<Nventa<<endl;
    cout<<"INGRESE EL ID DE LA PELICULA: " <<endl;//falta validacion
    cin>>idPelicula;
        while(validacionIDpelicula(idPelicula)==0){
        cout <<"\n EL ID INGRESADO NO EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;
        cin>>idPelicula;
    }
        while(validacionSalaPelicula(idSala,idPelicula)==1){
        cout <<"\n EL ID INGRESADO NO ESTA CARGADO EN NINGUNA SALA, CARGE OTRO ID DE PELICULA! "<< endl;
        system("pause");
        system("cls");
        return cargar();
    }
    cout<<endl;
    fechaPelicula(idPelicula);
    cout<<"FECHA DE VENTA"<<endl;
    fechaVenta.Cargar();
    int diaAct=getFecha().getDia();
    int mesAct=getFecha().getMes();
    int anioAct=getFecha().getAnio();
    while(validacionFecha(idPelicula,diaAct,mesAct,anioAct)==0){
        cout <<"LA FECHA INGRESADA NO ES CORRECTA"<< endl;
        system("pause");
        system("cls");
        fechaPelicula(idPelicula);
        fechaVenta.Cargar();
        diaAct=getFecha().getDia();
        mesAct=getFecha().getMes();
        anioAct=getFecha().getAnio();
    }

    while (reg.leerEnDisco(pos++)==1)
    {
        if(reg.getidPelicula()==idPelicula)
    {
        cout<<"SALAS DISPONIBLES: "<<reg.getidSala()<<endl;
    }
    }


    cout<<"ELIGA LA SALA EN DONDE VERA LA PELICULA: "<<endl;
    cin>>idSala;
    while(validacionSalaPelicula(idSala,idPelicula)==0){
        cout <<"\n EL ID INGRESADO NO EXISTE DENTRO DE LAS OPCIONES! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE SALA : " <<endl;
        cin>>idSala;
    }
    butacassala=cantButacasSala(idSala);
    ///butacasvendidas=calcularPlazas(idPelicula,diaAct,mesAct,anioAct);
    butacasvendidas=calcularVentas(idSala);
    butacastotal=butacassala-butacasvendidas;
    cout<<"CANTIDAD DE BUTACAS DISPONIBLES:"<<butacastotal<<endl;
    if(butacastotal<=0){
        cout<<"LA SALA YA SE ENCUENTRA COMPLETA"<<endl;
        system("pause");
        system("cls");
        return cargar();

    }
    cout<<"INGRESE CANTIDAD DE ENTRADAS: ";
    cin>>CantEntradas;
    while(CantEntradas>10){
        cout <<" SE PUEDEN COMPRAR HASTA 10 ENTRADAS! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE LA CANTIDAD DE ENTRADAS: " <<endl;
        cin>>CantEntradas;
    }
    while(CantEntradas>butacastotal){
         cout <<"NO HAY SUFICIENTES BUTACAS!"<< endl;
        cout<<"CANTIDAD DE BUTACAS DISPONIBLES:"<<butacastotal<<endl;
        system("pause");
        system("cls");
        cout<<"INGRESE LA CANTIDAD DE ENTRADAS: " <<endl;
        cin>>CantEntradas;
    }
    cout<<"INGRESE METODO DE PAGO [(1=EFECTIVO) (2=CREDITO) (3=DEBITO)]"<<endl;
    cin >>Pago;
    cout<<"EL IMPORTE ES DE: ";
    int importe;
     while (aux.leerEnDisco(pos1++)==1)
    {
        if(aux.getidSala()==idSala)
    {
        importe=aux.getPrecio();
    }
    }

    Total=validacionPrecio(importe,Pago);
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
    cout<<"ID DE LA SALA: ";
    cout<<idSala<<endl;
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
