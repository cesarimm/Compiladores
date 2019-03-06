//Compiladores
//Integrantes: María José Borjón Ibarra & César Iván Martínez Martínez
//Fecha: 7 de Febrero de 2019
#include <bits/stdc++.h>

using namespace std;


class Compilador{
	public:
		//Variables
		string cadena; // arreglo donde queda guardado lo que se extrajo
        int i=0; // el contador en el arreglo
        int j; //Contador para los strings
        
        //Metodos
        void extraerTexto();
        char encontrarValor(); // no hay parametro porque esta la fadd
		string palabras();
    	string numeros();
		string generarCadena();		
};


//Segunda entrega
string Compilador::generarCadena(){
	
	int aux = (int) encontrarValor();
	
	if(aux>=65&&aux<=90||aux>=97&&aux<=122|| aux>=48&&aux<=57 || aux==46||aux==32){ // comprueba si el primer caracter es valido 
		
		if(aux>=65&&aux<=90||aux>=97&&aux<=122){	
				return palabras();
		}/// inicia con una letr
		else if(aux==32){
				return "espacio";
		}	
		else { // inicia con un numero o un punto   
		     return numeros();
		}
	
		
	}else{
		
		char a = (char) aux;
		string regreso="";
		regreso=a;
		return regreso;
	}
	
}


string Compilador::palabras(){
	string regresa;
	
	regresa=cadena[i-1];
     int aux = (int) encontrarValor();
	 while (aux != 32 ){
		regresa+=cadena[i-1];
		 aux = (int) encontrarValor();
		
	}
	i--;
	 return regresa;
}


string Compilador::numeros()
{
	int punto = 0;
	bool tieneLetra = false;
	string regresa;
	int aux = (int) encontrarValor();
	regresa+=cadena[i-2];
	
	//Numeros de 48-57   while (aux != 32 && !(aux>=65&&aux<=90||aux>=97&&aux<=122)){
	 while (aux != 32 && !(aux>=65&&aux<=90||aux>=97&&aux<=122||aux>=58&&aux<=64)){
	 	
	 	if((int)cadena[i-1]==46){
	 		punto++;
		}
	 	
	 	if(punto<2){
	 			regresa+=cadena[i-1];
	            aux = (int) encontrarValor();
		 }else{
		 	regresa="";
		 	break;
		 }		
	}
	
	i--;
	
	//	cout<<(int)'.';
	
	if((int)regresa[i]==46){
		cout<<"Punto al final";
		string aux="";
		for(int k=0;k<regresa.size()-1;k++)
		  aux+=regresa[k];
		  
		  regresa=aux;
	}
	    
	
	 return regresa;	
}


//Primera entrega
void Compilador::extraerTexto(){	
		ifstream documento;		
        documento.open("pruebas.txt", ios::in);
	
				if(documento.fail()){
					cout<<"No se pudo encontrar el documento"<<endl;	
					}else{
		
							while(!documento.eof()){
							getline(documento, cadena);	
	      					}
	
					documento.close();
				}		   
       }
					


char Compilador::encontrarValor(){
	
	char a;
	
	if(i<cadena.size()){
			 a = cadena[i];
	i++;
	}

    return a;
}



/*int main(){
	Compilador comp;
	comp.extraerTexto();
	cout<<comp.generarCadena()<<endl;	
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	Imprimir();
	return 0;
}*/
