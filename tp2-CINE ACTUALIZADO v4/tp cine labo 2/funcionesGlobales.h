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
int validacionSalaPelicula(int id, int idp){
    SalasPorPelicula aux;
    int pos=0;
        while(aux.leerEnDisco(pos++)==1)
        {
            if(aux.getidPelicula()==idp)
            {
                if(aux.getidSala()==id){
                    return 1;
            }


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
void fechaPelicula(int id){
    pelicula reg;
    int pos=0;
        int diaFin,mesFin,anioFin;
        int diaIni,mesIni,anioIni;
    while(reg.leerEnDisco(pos++)==1){
        if(reg.getidPelicula()==id){
                cout<<"ELIJA UNA FECHA  VALIDA "<<endl;
                    diaIni=reg.getFechaIni().getDia();
                    mesIni=reg.getFechaIni().getMes();
                    anioIni=reg.getFechaIni().getAnio();

                    diaFin=reg.getFechaFin().getDia();
                    mesFin=reg.getFechaFin().getMes();
                    anioFin=reg.getFechaFin().getAnio();

                    cout<<"INICIO DE PROYECION:"<<diaIni<<"/"<<mesIni<<"/"<<anioIni<<endl;
                    cout<<"FINAL DE PROYECION :"<<diaFin<<"/"<<mesFin<<"/"<<anioFin<<endl;


        }
    }
}
int validacionFecha(int id, int dia, int mes, int anio)
{
    pelicula reg;
        int pos=0, fechaIni, fechaFin, fechaActual;
        while(reg.leerEnDisco(pos++)==1){
            if(reg.getidPelicula()==id){
                    fechaIni=(reg.getFechaIni().getAnio()*10000)+(reg.getFechaIni().getMes()*100)+reg.getFechaIni().getDia();
                    fechaFin=(reg.getFechaFin().getAnio()*10000)+(reg.getFechaFin().getMes()*100)+reg.getFechaFin().getDia();
                    fechaActual=(anio*10000)+(mes*100)+dia;
                    if(fechaActual>=fechaIni && fechaActual<=fechaFin)
        {
            return 1;
        }
        else
        {
            return 0;
        }
            }

        }


return -1;
}

int calcularPlazas(int id,int dia, int mes, int anio){
    ventas obj;
    int canttotal=0;
    int pos=0;
    int diaIni,mesIni,anioIni;
        while(obj.leerEnDisco(pos++)==1){
                if(obj.getidPelicula()==id){
                    diaIni=obj.getFecha().getDia();
                    mesIni=obj.getFecha().getMes();
                    anioIni=obj.getFecha().getAnio();
                    if(anio==anioIni&&mes==mesIni&&dia==diaIni){
                        canttotal+=obj.getCantEntradas();
                    }

                }

        }

    return canttotal;
}
int cantButacasSala(int id){
    Salas aux;
    int cantbutacas=0;
        int pos=0;
        while(aux.leerEnDisco(pos++)==1){
                if(aux.getidSala()==id){
                    cantbutacas=aux.getPlazas();
                    return cantbutacas;

                }

            }
            return 0;
        }


int calcularVentas(int id){
    ventas obj;
    Salas reg;
    int ventas=0;
    int pos=0;
    int pos2=0;
        while(reg.leerEnDisco(pos++)==1){

            if(reg.getidSala()==id)
            {
                while(obj.leerEnDisco(pos2++)==1)
                {
                    if(obj.getidSala()==id)
                    {
                         ventas+=obj.getCantEntradas();
                    }

                }
            }



        }

    return ventas;

}
#endif // FUNCIONESGLOBALES_H_INCLUDED
