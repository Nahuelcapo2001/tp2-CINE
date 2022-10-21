#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

class pelicula
{
    private:
      int idPelicula,idDirector, duracion, precio, idioma;
      char nombrePelicula[30], genero[20];
      Fecha fechaIni;
      fechaFin fin;
      director direc;
      Salas salaNum;
       bool estado;
    public:
        ///sets()
      void setidPelicula (int idP){idPelicula=idP;}
      void setidDirector (int idD) {idDirector=idD;}
      void setIdioma (int I) {idioma=I;}
      void setDuracion (int d) {duracion=d;}
      void setPrecio (int p) {precio=p;}
      void setFechaIni (Fecha I) {fechaIni=I;}
      void setFechaFin(fechaFin FI) {fin=FI;}
      void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
      void setGenero (const char *g){strcpy(genero,g);}
      void setEstado(bool e){estado=e;}
      ///gets()
      int getidPelicula (){return idPelicula;}
      int getidDirector () {return idDirector;}
      int getIdioma() {return idioma;}
      int getDuracion () {return duracion;}
      int getPrecio () {return precio;}
      const char *getNombrePelicula (){return nombrePelicula;}
      const char *getGenero (){return genero;}
      Fecha getFechaIni () {return fechaIni;}
      fechaFin getFechaFin () {return fin;}
      bool getEstado(){return estado;}
      ///disco
      int ModificarEnDisco(int pos);
      void EliminarDeDisco();
      int grabarEnDisco();
      int leerEnDisco(int);
      int LeerDeDiscobkp(int pos);
      bool backuppelicula();
      bool recupelicula();

      bool cargarPeliculas()
      {
          FILE *p;
          bool escribio;
          pelicula reg;
          p=fopen("pelicula.dat","ab");
          if (p==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,p);
              fclose(p);
              return escribio;

      }

void mostrarPeliculas()
{
    FILE *p;
    p=fopen("pelicula.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (pelicula),1,p)==1)
    {
        mostrar();
    }
    fclose(p);
}

void cargar()
{
    precio=500;
    estado=true;
    fflush(stdin);
    cout<<"INGRESE ID: "<<endl;
    cin>> idPelicula;
    cin.ignore();
    cout<<"INGRESE EL NOMBRE DE LA PELICULA: " << endl;
    cin.getline(nombrePelicula,30,'\n');
    fflush(stdin);
    cout <<"INGRESE EL GENERO: "<<endl;
    cin.getline(genero,20,'\n');
    fflush(stdin);
    cout<<"INGRESE EL IDIOMA [ (1=Castellano) , (2=subtitulado) ] :"<<endl;
    cin>>idioma;
    fflush(stdin);
    cout<<"INGRESE LA DURACION [minutos]: "<<endl;
    cin>>duracion; ///en minutos
    cout<<"INGRESE EL ID DEL DIRECTOR: "<<endl;
    cin>>idDirector; /// si el id de director ya existe, no cargar nada mas, en cambio si no existe, cargar los datos del directos
    cout<<"INGRESAR LA EMISION INICIAL DE LA PELICULA:"<<endl;
    fechaIni.Cargar();
    cout<<"INGRESAR LA EMISION FINAL DE LA PELICULA:"<<endl;
    fin.Cargar();
    cout<<"PRECIO DE LA ENTRADA: "<<precio<<endl;

}
void mostrar()
{
    if(estado==true)
    {
       cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
        cout<<"NOMBRE DE LA PELICULA: ";
        cout<<nombrePelicula<<endl;
        cout<<"GENERO: ";
        cout<<genero<<endl;
        cout<<"IDIOMA: ";
        cout<<idioma<<endl;
        cout<<"DURACION: ";
        cout<<duracion<<" MINUTOS"<<endl;
        cout<<endl;
        cout<<"FECHA INICIAL DE LA PROYECCION: ";
        fechaIni.Mostrar();
        cout<<"FECHA FINAL DE LA PROYECCION: ";
        fin.Mostrar();
        cout<<"PRECIO DE LA ENTRADA: ";
        cout<<precio<<endl;
        cout<<""<<endl<<endl;

    }


}
};
void pelicula::EliminarDeDisco(){
       int pos=0;
       int id;
        cout<<"INTRODUZCA EL ID DE PELICULA A ELIMINAR: ";cin>>id;
        while(leerEnDisco(pos)==1){
                if(getidPelicula()==id){
                        cout<<"EL ID DE PELICULA TIENE LOS SIGUIENTES DATOS"<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}
int pelicula::ModificarEnDisco(int pos)
{

    FILE *p;
    p=fopen("pelicula.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(pelicula)*pos,0);
    int escribio=fwrite(this,sizeof(pelicula),1,p);
    fclose(p);
    return escribio;
}
int pelicula::grabarEnDisco()
{
    FILE *p;
    p=fopen("pelicula.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(pelicula),1,p);
    fclose(p);
    return escribio;
}

int pelicula::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("pelicula.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(pelicula)*pos,0);
    int leyo=fread(this,sizeof(pelicula),1,p);
    fclose(p);
    return leyo;
}
///BACKUP
int pelicula::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/pelicula.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(pelicula)*pos,0);
    int leyo=fread(this,sizeof(pelicula),1,A);
    fclose(A);
    return leyo;


}

bool pelicula::backuppelicula(){

int pos=0;
FILE *b;
    b=fopen("backup/pelicula.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(pelicula),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool pelicula::recupelicula(){
int pos=0;
FILE *br;
    br=fopen("pelicula.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(pelicula),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }

#endif // PELICULAS_H_INCLUDED
