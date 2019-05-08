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
		int ref; 
        int j; //Contador para los strings
        
        //Metodos
        void extraerTexto();
        char encontrarValor(); // no hay parametro porque esta la fadd
		string palabras();
    	string numeros();
		string generarCadena();
		
		//Funciones BNF
		void programa();
		bool bloque();
		bool aux1();
		bool aux2();
		bool aux3();
		bool aux4();
		bool aux6();
		bool aux7();
		bool aux8();
		bool aux10();
		bool aux12();
		bool aux13();
	    bool aux14();
		bool aux15();
	    bool instruccion();
	    bool aux17();
		bool aux18();
		bool aux19();
		bool aux20();
	    bool aux22();
		bool aux26();
		bool aux27();
		bool aux28();	
		bool aux30();
		bool aux31();
		bool aux32();
		bool condicion();	
		bool aux34();
		bool aux35();
		bool aux36();		
};


//Segunda entrega
string Compilador::generarCadena(){
	
	int aux = (int) encontrarValor();
	
	if(aux>=65&&aux<=90||aux>=97&&aux<=122|| aux>=48&&aux<=57 || aux==46||aux==32){ // comprueba si el primer caracter es valido 
		
		if(aux>=65&&aux<=90||aux>=97&&aux<=122){	
				return palabras();
		}/// inicia con una letr
		else if(aux==32){
				return "sp";
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
	                     ref=cadena.length();
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


//Funciones del BNF

  	    void Compilador::programa(){
  	    	  if(!bloque()){
  	    	  	//Bye
  	    	  	printf("Todo bien");
				}else{
			      //Error
			      printf("Todo mal");
				}	  
		  }
		  
		bool Compilador::bloque(){
  	    	if(aux1()){
  	    		 if(aux6()){
  	    		 	 if(aux10()){
  	    		 	 	  if(instruccion()){
  	    		 	 	  	  //Todas se cumplieron de la forma correcta
  	    		 	 	  	   return true;
							  }else
							  //Hay error
							  return false;
						}else
						//Hay error 
					    return false;
				   }else
				    //Hay error
				    return false;
			  }else
			  	//Hay un error
			  	return false;	  
        }
		  
		bool Compilador::aux1(){
  	    	 //if(generarCadena()=="prnft"){
  	    
  	    	 return false;
		  }
		  
		bool Compilador::aux2(){
  	    	return false;
		  }
		  
		bool Compilador::aux3(){
  	    	return false;
		  }
		  
		bool Compilador::aux4(){
  	    	return false;
		  }
		  
		bool Compilador::aux6(){
  	    	return false;
		  }
		  
		bool Compilador::aux7(){
  	    	return false;
		  }
		  
		bool Compilador::aux8(){
  	       return false;	
		  }
		  
		bool Compilador::aux10(){
  	    	return false;
		  }
		  
		bool Compilador::aux12(){
  	    	return false;
		  }
		  
		bool Compilador::aux13(){
  	    	 return false;
		  }
		  
	    bool Compilador::aux14(){
  	    	return false;
		  }
		  
		bool Compilador::aux15(){
  	    	return false;
		  }
		  
	    bool Compilador::instruccion(){
  	    	return false;
		  }
		  
	    bool Compilador::aux17(){
  	    	return false;
		  }
		  
		bool Compilador::aux18(){
  	    	return false;
		  }
		  
		bool Compilador::aux19(){
  	    	return false;
		  }
		  
		bool Compilador::aux20(){
			return false;	
		  }
		  
	    bool Compilador::aux22(){
  	    	return false;
		  }
		  
		bool Compilador::aux26(){
  	    	return false;
		  }
		  
		bool Compilador::aux27(){
  	    	return false;
		  }
		  
		bool Compilador::aux28(){
  	    	return false;
		  }
		  	
		bool Compilador::aux30(){
  	    	return false;
		  }
		  
		bool Compilador::aux31(){
  	    	return false;
		  }
		  
		bool Compilador::aux32(){
  	    	return false;
		  }
		  
		bool Compilador::condicion(){
  	    	return false;
		  }
		  	
		bool Compilador::aux34(){
  	        return false;	
		  }
		  
		bool Compilador::aux35(){
		   return false;
		  }
		  
		bool Compilador::aux36(){
  	    	return false;
		  }

