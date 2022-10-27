#ifndef PELICULASSALAS_H_INCLUDED
#define PELICULASSALAS_H_INCLUDED

class peliculasSalas{
private:
    int idPelicula, idSala, cantidadSalas;
    bool ocupado;
    bool estado;

public:
     ///sets()

     void setidPelicula(int p){idPelicula=p;}
     void setidSala(int S){idSala=S;}
     void setCantidadSalas(int cs){cantidadSalas=cs;}
     void setOcupado(bool o){ocupado=o;}
     void setEstado(bool e){estado=e;}

     ///gets()

     int getidPelicula(){return idPelicula;}
     int getidSala(){return idSala;}
     int getCantidadSalas(){return cantidadSalas;}
     bool getOcupado(){return ocupado;}
     bool getEstado(){return estado;}


    ///disco
      void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      int grabarEnDisco();
      int leerEnDisco(int);
      void mostrarDeDisco();
      int LeerDeDiscobkp(int);
      bool backupPeliculasSala();
      bool recuPeliculasSala();

       bool cargarPeliculasSalas()
      {
          FILE *s;
          bool escribio;
          peliculasSalas reg;
          s=fopen("peliculassalas.dat","ab");
          if (s==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,s);
              fclose(s);
              return escribio;

      }


void cargar(){
    estado=true;
    ocupado=false;
    cout<<"INGRESE UN ID DE PELICULA: "<<endl;
    cin>>idPelicula;
    ///validacion
    cout<<"INGRESE UNA CANTIDAD DE SALAS PARA LA PROYECCION DE LA PELICULA"<<endl;
    cin>>cantidadSalas;
    for(int i=0;i<cantidadSalas;i++)
    {
        cout<<"INGRESE UN ID DE SALA"<<endl;
        cin>>idSala;
        ///validacion
        ocupado=true;
    }
}
void  mostrar(){
    if(estado==true)
       {
           if(ocupado==true)
           {
               cout<<"ID DE PELICULA: "<<idPelicula<<endl;
               cout<<"CANTIDAD DE SALAS PARA LA PROYECCTION: "<<cantidadSalas<<endl;
               for(int j=0;j<cantidadSalas;j++)
               {
                   cout<<"ID DE SALA: "<<idSala<<endl;
               }
           }
       }

}

};
void peliculasSalas::EliminarDeDisco(){
       int pos=0;
       int idS;
        cout<<"INTRODUZCA EL ID DE SALA A ELIMINAR: ";cin>>idS;
        while(leerEnDisco(pos)==1){
                if(getidSala()==idS){
                        cout<<"EL ID DE SALA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}
int peliculasSalas::ModificarEnDisco(int pos)
{

    FILE *s;
    s=fopen("peliculassalas.dat","rb+");
    if (s==NULL) return -1;
    fseek(s,sizeof(peliculasSalas)*pos,0);
    int escribio=fwrite(this,sizeof(peliculasSalas),1,s);
    fclose(s);
    return escribio;
}
int peliculasSalas::grabarEnDisco()
{
    FILE *s;
    s=fopen("peliculassalas.dat","ab");
    if (s==NULL) return -1;
    int escribio=fwrite(this,sizeof(peliculasSalas),1,s);
    fclose(s);
    return escribio;
}

int peliculasSalas::leerEnDisco(int pos)
{
    FILE *s;
    s=fopen("peliculassalas.dat","rb");
    if (s==NULL) return -1;
    fseek(s,sizeof(peliculasSalas)*pos,0);
    int leyo=fread(this,sizeof(peliculasSalas),1,s);
    fclose(s);
    return leyo;
}
void peliculasSalas::mostrarDeDisco(){
    int pos=0;
    while(leerEnDisco(pos++)==1){

        mostrar();
        cout<<endl;

    }



}

///BACKUP
int peliculasSalas::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/peliculassala.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(peliculasSalas)*pos,0);
    int leyo=fread(this,sizeof(peliculasSalas),1,A);
    fclose(A);
    return leyo;


}

bool peliculasSalas::backupPeliculasSala(){

int pos=0;
FILE *b;
    b=fopen("backup/peliculassala.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(peliculasSalas),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool peliculasSalas::recuPeliculasSala(){
int pos=0;
FILE *br;
    br=fopen("peliculassalas.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(peliculasSalas),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }

#endif // PELICULASSALAS_H_INCLUDED
