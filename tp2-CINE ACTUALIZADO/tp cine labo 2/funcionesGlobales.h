#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

int validacionIDpelicula(int id)
{
    pelicula reg;
        int pos=0;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==id){

                     return 1;

            }
        }
    return 0;
}
int validacionDir(int id){
    director aux;
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
            if(aux.getidDirector()==id&&aux.getEstado()==true){
                    cout<<"DIRECTOR:"<<aux.getnombreDirector();
                     return 1;

            }
        }
    return 0;


}
int validacionSala(int id){
    Salas aux;
    int pos=0;
        while(aux.leerEnDisco(pos++)==1)
        {
            if(aux.getidSala()==id){
                    return 1;

        }

        }
        return 0;
}
int validacionPrecio(int precio, int pago){
 int importe;
        importe=precio;
        if(pago==1){
            importe=importe*0.95;
        }else if(pago==2){
            importe=importe*1.20;
        }else{

            importe=importe*1.05;
        }

        return importe;


return 0;

}

int autonumericoIDdirectores(){
director obj;
int pos=0;
int c=0;
    while(obj.leerEnDisco(pos++)==1){
       c++;
    }

    return c;

}
int autonumericoIDPeliculas(){
pelicula obj;
int pos=0;
int c=0;
    while(obj.leerEnDisco(pos++)==1){
       c++;
    }

    return c;

}
int autonumericoIDSalas(){
Salas obj;
int pos=0;
int c=0;
    while(obj.leerEnDisco(pos++)==1){
       c++;
    }

    return c;

}
int autonumericoIDVentas(){
ventas obj;
int pos=0;
int c=0;
    while(obj.leerEnDisco(pos++)==1){
       c++;
    }

    return c;

}
#endif // FUNCIONESGLOBALES_H_INCLUDED
