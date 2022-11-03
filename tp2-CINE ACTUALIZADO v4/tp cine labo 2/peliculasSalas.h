#ifndef PELICULASSALAS_H_INCLUDED
#define PELICULASSALAS_H_INCLUDED

class SalasPorPelicula
{
private:

    int idPelicula, idSala;
    char nombrePelicula[30];
    bool estado;

public:
    ///sets()

    void setidPelicula (int idP){idPelicula=idP;}
    void setidSala(int S){idSala=S;}
    void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
    void setEstado(bool e){estado=e;}

    ///gets()

     int getidPelicula (){return idPelicula;}
     int getidSala(){return idSala;}
     const char *getNombrePelicula (){return nombrePelicula;}
     bool getEstado(){return estado;}

    ///disco

     void EliminarDeDisco();
      int ModificarEnDisco(int pos);
      int grabarEnDisco();
      int leerEnDisco(int);
      bool recuSalaXpeli();
      bool backupSalaXpeli();
      int LeerDeDiscobkp(int pos);


         bool cargarSalasPorPelicula()
      {
          FILE *p;
          SalasPorPelicula reg;
          bool escribio;
          p=fopen("salasPorPelicula.dat","ab");
          if (p==NULL) return false;
              cargar();
              escribio=fwrite(this,sizeof reg, 1,p);
              fclose(p);
              return escribio;

      }



void mostrarSalasPorPelicula()
{
    FILE *p;
    p=fopen("salasPorPelicula.dat","rb");
    if (p==NULL) return;
    while(fread(this,sizeof (SalasPorPelicula),1,p)==1)
    {
        mostrar();
    }
    fclose(p);
}


void cargar(){
    estado=true;
    pelicula obj;
    int pos=0;
    cout<<"INGRESE EL ID DE LA PELICULA: " <<endl;
    cin>>idPelicula;
        while(validacionIDpelicula(idPelicula)==0){
        cout <<"\n EL ID INGRESADO NO EXISTE! "<< endl;
        system("pause");
        system("cls");
        cout<<"INGRESE EL ID DE LA PELICULA : " <<endl;
        cin>>idPelicula;
    }
    while(obj.leerEnDisco(pos++))
    {
        if(obj.getidPelicula()==idPelicula)
        {
            setNombrePelicula(obj.getNombrePelicula());
        }
    }
    cout<<"INGRESE ID DE SALA: ";
    cin>>idSala;
    while(validacionSala(idSala)!=1)
    {
    cout<<"EL ID DE SALA NO ES VALIDO" ;
    cout<<"INGRESE ID DE SALA: ";
    cin>>idSala;
    }
    cout<<endl;
    }


void mostrar()
{
    if(estado==true)
    {
    cout<<"ID DE LA PELICULA: "<<idPelicula<<endl;
    cout<<"NOMBRE DE LA PELICULA: ";
    cout<<nombrePelicula<<endl;
    cout<<"SALA EN LA QUE SE ENCUENTRA DISPONIBLE: "<<idSala<<endl;
    cout<<endl;
    }
}
};

void SalasPorPelicula::EliminarDeDisco(){
       int pos=0;
       int idP,idS;
        cout<<"INTRODUZCA EL ID PELICULA A ELIMINAR: ";
        cin>>idP;
        cout<<"INGRESE EL ID DE LA SALA A ELIMINAR: ";
        cin>>idS;
        while(leerEnDisco(pos)==1){
                if(getidPelicula()==idP&&getidSala()==idS){
                        cout<<"REGISTRO A ELIMINAR: "<<endl<<endl;
                        mostrar();
                        cout<<endl<<endl;
                        setEstado(false);
                        if(ModificarEnDisco(pos)==1){cout<<"REGISTRO ELIMINADO! ";}
                }
            pos++;
        }

}
int SalasPorPelicula::ModificarEnDisco(int pos)
{

    FILE *p;
    p=fopen("salasPorPelicula.dat","rb+");
    if (p==NULL) return -1;
    fseek(p,sizeof(SalasPorPelicula)*pos,0);
    int escribio=fwrite(this,sizeof(SalasPorPelicula),1,p);
    fclose(p);
    return escribio;
}
int SalasPorPelicula::grabarEnDisco()
{
    FILE *p;
    p=fopen("salasPorPelicula.dat","ab");
    if (p==NULL) return -1;
    int escribio=fwrite(this,sizeof(SalasPorPelicula),1,p);
    fclose(p);
    return escribio;
}

int SalasPorPelicula::leerEnDisco(int pos)
{
    FILE *p;
    p=fopen("salasPorPelicula.dat","rb");
    if (p==NULL) return -1;
    fseek(p,sizeof(SalasPorPelicula)*pos,0);
    int leyo=fread(this,sizeof(SalasPorPelicula),1,p);
    fclose(p);
    return leyo;
}
///BACKUP
int SalasPorPelicula::LeerDeDiscobkp(int pos){
    FILE *A;
        A=fopen("backup/salasPorPelicula.bkp","rb");
            if(A==NULL){cout<<"ERROR DE LECTURA!";return-1;}
    fseek(A,sizeof(SalasPorPelicula)*pos,0);
    int leyo=fread(this,sizeof(SalasPorPelicula),1,A);
    fclose(A);
    return leyo;


}

bool SalasPorPelicula::backupSalaXpeli(){

int pos=0;
FILE *b;
    b=fopen("backup/salasPorPelicula.bkp","wb");
    if(b==NULL){return false;}
    while(leerEnDisco(pos)==1){
        fwrite(this,sizeof(SalasPorPelicula),1,b);
        pos++;
    }
    fclose(b);
    if(pos==0){return false;}
    return true;
}
 bool SalasPorPelicula::recuSalaXpeli(){
int pos=0;
FILE *br;
    br=fopen("salasPorPelicula.dat","wb");
    if(br==NULL){return false;}
    while(LeerDeDiscobkp(pos)==1){
        fwrite(this,sizeof(SalasPorPelicula),1,br);
        pos++;
    }
    fclose(br);
    if(pos==0){return false;}
    return true;

 }

#endif // PELICULASSALAS_H_INCLUDED
