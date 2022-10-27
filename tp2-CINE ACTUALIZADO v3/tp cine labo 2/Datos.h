#ifndef DATOS_H_INCLUDED
#define DATOS_H_INCLUDED

class datos
{
private:
    int recaudacionTotal=0;
    int recaudacionTotalCine=0;
    int idRecaudado;
    int idtaquillera;
    int totalpeliculataquillera=0;
    float recaudacionporpelicula=0;
    char nombrePelicula[30];
    char nombreDirector[30];

    ventas reg;
    pelicula aux;
    director obj;
public:
    ///sets
    void setNombrePelicula (const char *Np){strcpy(nombrePelicula,Np);}
    void setRecaudacionporpelicula(int rt){recaudacionporpelicula=rt;}
    void setRecaudacionTotal(int rt){recaudacionTotal=rt;}
    void setIdRecaudado(int idR){idRecaudado=idR;}
    void setRecaudacionTotalCine(int rtc){recaudacionTotalCine=rtc;}
    void setNombreDirector (const char *Nd){strcpy(nombreDirector,Nd);}

    ///gets
    float getrecaudacionporpelicula(){return recaudacionporpelicula;}
    int getRecaudacionTotal(){return recaudacionTotal;}
    int getIdRecaudado(){return idRecaudado;}
    int getRecaudacionTotalCine(){return recaudacionTotalCine;}
    const char *getnombreDirector (){return nombreDirector;}
    ///funciones

//////////////////////////////PUNTO 1///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
float recpeli(int id){
    int pos=0;
    float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
                if(aux.getidPelicula()==id){
                    canttotal+=calcularRecaudacion(aux.getidPelicula());
                }

            }
            return canttotal;

    }
   void recaudacionpeliculas(){


            int pos=0;
        while(aux.leerEnDisco(pos++)==1){
                if(aux.getEstado()==true){
                    cout<<aux.getNombrePelicula()<<" RECAUDO UN TOTAL DE "<<recpeli(aux.getidPelicula())<<" PESOS"<<endl<<endl;
                }



        }

    }

//////////////////////////////PUNTO 2///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
 float recdir(int id){
    int pos=0;
    float canttotal=0;
        while(aux.leerEnDisco(pos++)==1){
                if(aux.getidDirector()==id){
                    canttotal+=calcularRecaudacion(aux.getidPelicula());
                }

            }
            return canttotal;

    }
    void recaudaciondirector(){
            int pos=0;
        while(obj.leerEnDisco(pos++)==1){
                if(obj.getEstado()==true){
                    cout<<"EL DIRECTOR "<<obj.getnombreDirector()<<" RECAUDO UN TOTAL DE "<<recdir(obj.getidDirector())<<" PESOS"<<endl<<endl;
                }



        }

    }

float calcularRecaudacion (int id)
{
    float sumaRecaudacion=0;
    int pos=0;
    while (reg.leerEnDisco(pos++))
    {
        if(reg.getidPelicula()==id)
        {
            sumaRecaudacion+=reg.getTotal();
        }

    }
    return(float)sumaRecaudacion;
}

//////////////////////////////////PUNTO 3//////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
void RecaudacionCine()
{
    int totalRecaudado=0;
    int pos=0;
    while(reg.leerEnDisco(pos++)==1)
    {
        setRecaudacionTotalCine(reg.getTotal());
        totalRecaudado+=getRecaudacionTotalCine();
    }
    cout<<"LA RECAUDACION TOTAL DEL CINE FUE DE: "<<totalRecaudado<<endl;
}



};

#endif // DATOS_H_INCLUDED
