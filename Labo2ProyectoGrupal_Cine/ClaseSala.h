#ifndef CLASESALA_H_INCLUDED
#define CLASESALA_H_INCLUDED

class Sala{
private:

int Idsala;
int cantidadbutacas;

public:
        void setSala(int s){Idsala=s;}
        void setCantidadbutacas(int b){cantidadbutacas=b;}

        int getSala(){return Idsala;}
        int getCantidadbutacas(return cantidadbutacas;)

        void Cargar(){
        cout<<"INGRESE EL NUMERO DE SALA"<<endl;
        cin>>Idsala;
        cout<<"INGRESE LA CANTIDAD DE BUTACAS"<<endl;/// CANTIDAD DE BUTACAS O NUMERO DE BUTACAS?
        cin>>cantidadbutacas;}

        void Mostrar(){
        cout<<"NUMERO DE SALA: "<< Idsala<<endl;
        cout<<"NUMERO TOTAL DE BUTACAS EN LA SALA: "<<cantidadbutacas<<endl;
        cout<<endl;}

bool leerDeDisco(int pos){
    FILE *p;
    p=fopen("salas.dat", "rb");
    if(p==NULL) return false;
    fseek(p, pos * sizeof (Sala), 0);
    bool leyo=fread(this, sizeof (Sala), 1, p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco(){
    FILE *p;
    p=fopen("salas.dat", "ab");
    if(p==NULL) return false;
    bool escribio=fwrite(this, sizeof (Sala), 1, p);
    fclose(p);
    return escribio;
}

};


#endif // CLASESALA_H_INCLUDED
