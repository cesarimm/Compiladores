//Compiladores
//Integrantes: María José Borjón Ibarra & César Iván Martínez Martínez
//Fecha: 7 de Febrero de 2019
#include <bits/stdc++.h>

using namespace std;

///Notas: Verificar ident y num!!!

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
  	    	  if(bloque()){
  	    	  	//Bye
  	    	  	printf("Todo bien");
				}else{
			      //Error
			      printf("Todo mal");
				}	  
		  }
		  
		  
		bool Compilador::bloque(){   
		     ///Faltaria follows
  	          if(aux1()&&aux6()&&aux10()&&instruccion()) return true;
  	           else return false;	
            }
		  

		  
		bool Compilador::aux1(){
			
  	    	 if(generarCadena()=="-"&&aux2()&&aux3()&&generarCadena()=="!"){
  	           return true;
  	    	 }else{
  	    	 	 //Es el follow de aux1
  	    	    	string aux = generarCadena();
  	    	 	   if(aux=="'\'"||aux=="declara."||aux=="go."||aux=="cuando"||
					  aux=="Sii"||aux=="IDENT"||aux=="}"||aux=="?"||aux=="BYE") return true;
				   else return false;
		      }
	  
	    }
	    
		bool Compilador::aux2(){
			string aux = generarCadena();
  	     if(aux=="entero"||aux=="decimal"||aux=="bool"||aux=="cadena"||
		    aux=="simbolo"||aux=="void") return true;
	       else return false;
		  }
		  
		bool Compilador::aux3(){
			///Saber que es un identificador osea un nombre de una variable o de alguna funcion
  	    	 if(gerenarCadena()!=""&&aux4()) return true;    
			 else return false;
		  }
		  
		bool Compilador::aux4(){
			///Saber que es un numero
  	         if(gerenarCadena()!=""&&generarCadena()=="?"&&aux3()) return true;	    
			else{
			 //Follow de aux4
				if(generarCadena()=="!")
				  return true;
				else return false;
			}
		  }
		  
		bool Compilador::aux6(){
						
			
  	     if(gerenarCadena()=="'\'"&&aux2()&&aux7()&&generarCadena()=="!"){
  	    	 return true;
			   }    
			else{
				string aux=generarCadena();
				if(aux=="declara."||aux=="go."||aux=="cuando"|| aux=="Sii"||
				    aux=="IDENT"||aux=="}"||aux=="?"||aux=="BYE") return true;
				   else return false;
			}
		  }
		  
		bool Compilador::aux7(){
			
			//Falta validar que sean identificadores o que sean numeros 
  	         if(generarCadena()!="" && generarCadena()=="="&&  generarCadena()!="" && aux8() && && generarCadena()=="!"){
  	          	 
  	          	 	return true;
  	          	 } else return false:
  	              
					}
				
		  
		bool Compilador::aux8(){
			 if(generarCadena()=="?"&& aux7()){
			 	return true;
			 }else{
			  if(generarCadena()=="!"){
			  return true;  
			  }
			  else return false;
			
			 }
			
  	      	
		  }
		  
		bool Compilador::aux10(){
              if(generarCadena()=="declara."&& aux2()&& generarCadena()!="" && generarCadena()=="(" 
			         && aux12() && generarCadena()==")" && generarCadena()=="{" && aux14() && && generarCadena()=="}" && aux10() && generarCadena()=="!"){
  	    	         return true;}
  	    	else {
  	    		string aux=generarCadena();
  	    		
  	    		/// No olvidar que IDENT se refiere a una variable( cualquier nombre que el usuario ponga)
				if(aux=="go."||aux=="cuando"|| aux=="Sii"||
				    aux=="IDENT"||aux=="}"||aux=="?"||aux=="BYE"||aux=="!") return true;
				   else return false;
  	    		
  	    		
			  }
		  }
		  
		bool Compilador::aux12(){
			
			if(generarCadena()!=""&& aux13() ) return true ;
			
  	    	else { return false;
			  }
		  }
		  
		bool Compilador::aux13(){
			if(generarCadena()=="?"&& aux12()){
				return true;
		}else {  /// Esto es parte de los follow de aux 13
			if (generarCadena()=="}") return true;
			else return false;
		  }
		  }
		  
	    bool Compilador::aux14(){
	    	if(instruccion()&& aux15()) return true;
  	    	else return false;
		  }
		  
		bool Compilador::aux15(){
			if(generarCadena()=="?"&& aux14()){
				return true;
			}
			else 
			{
				if(generarCadena()==")") return true;
				 
				 else 	return false;

			}
		  }
		  
	    bool Compilador::instruccion(){
  	    ///	cout<<"Instruccion"<<endl;
  	    	if(aux17()&& aux22() && aux26()  && aux26()) return true;
  	    	else {  /// Follow de instruccion 
  	    	string aux=generarCadena();
  	    		
  	          if (aux=="?" && aux=="BYE") return true;
  	            	 
			  else return false;}
		  }
		  
		  
		  
	    bool Compilador::aux17(){
	    	/// No olvidar que la comparacion a diferente de vacio es para el "nombre " que nosostros otorguemos a la variable = IDENT
	    	if(generarCadena()=="go." && generarCadena()!="" && generarCadena()=="(" && aux18() && generarCadena()==")" && generarCadena()=="!" ) return true;
	    	else {
	    		string aux=generarCadena();
  	    		
	    		if(aux=="cuando" || aux=="Sii"  || aux==""  || aux=="Sii"  || aux=="?" || aux=="}"  || aux=="BYE" ) return true;
				
				else return false;
			}
		  }
		  
		  
		bool Compilador::aux18(){
  	    		if(aux19()&& aux20()) return true;
  	    		else{/// Follow de aux18
  	    		     
  	    		     if (generarCadena()=="!") return true;
  	    		     else return false;
  	    			
				  }
		  }
		  
		bool Compilador::aux19(){
				string aux = generarCadena();
  	     if(aux=="NUM"||aux!="") return true;
	       else  return false;
  }
		  
		bool Compilador::aux20(){
			if (generarCadena()=="?"&& aux18() ) return true;
  	       
	    	else{/// Follow de aux20
  	    		     
  	      	    if (generarCadena()=="!") return true;
  	    	    else return false;
  	    			
				  }
		  }
		  
	    bool Compilador::aux22(){
	    	if (generarCadena()=="cuando"&& aux19() && generarCadena()=="!" && condicion() && generarCadena()=="!" && instruccion() &&
			generarCadena()=="{" && aux14() && generarCadena()=="}"  && generarCadena()=="!" ) return true;
  	       
	    	else{/// Follow de aux22
  	    		 
				  string aux = generarCadena();
  	              if(aux=="Sii"||aux!="" ||aux=="?" ||aux=="}" ||aux=="BYE") return true;
  	              else return false;	
  	    
		  }
		  
		bool Compilador::aux26(){
			
  	    	if(generarCadena()=="Sii" && generarCadena()=="(" && condicion() && generarCadena()==")" && generarCadena()=="{" && aux14() 
			  && generarCadena()=="}" && aux27() && aux28() && generarCadena()=="!" ) return true;
  	    	
			  else{ ///Este es el follow de aux26
  	    		string aux = generarCadena();
  	    		///Recordar que espacio vacio hace referencia a IDENT
  	              
				  if(aux!="" ||aux=="?" ||aux=="}" ||aux=="BYE") return true;
  	              else return false;
  	    		
			  }
		  }
		  
		  
		bool Compilador::aux27(){
				if(generarCadena()=="Quiza" && generarCadena()=="(" && condicion() && generarCadena()==")" && generarCadena()=="{" && aux14() 
			  && generarCadena()=="}" && aux27() && generarCadena()=="!" ) return true;
  	    	
			  else{ ///Este es el follow de aux27
  	    		string aux = generarCadena();
  	    		///Recordar que espacio vacio hace referencia a IDENT 
				  if(aux!="Noo" ||aux=="!" ) return true;
  	              else return false;
  	    		
			  }
  	    	
		  }
		  
		bool Compilador::aux28(){
			if(generarCadena()=="Noo" && generarCadena()=="{" && aux14() && generarCadena()=="}")return true;
			else { // Follow de aux28
				if(generarCadena()=="!") return true;
				else return false ;
			}
			
			
  	    
		  }
		  	
		bool Compilador::aux30(){
			///Recuerda: el espacio libre es el IDENT 
  	    	if(generarCadena()=="" && generarCadena()=="=" && aux31() && generarCadena()=="!")return true;
  	     else{ ///Este es el follow de aux30
  	    		string aux = generarCadena();
  	    		///Recordar que espacio vacio hace referencia a IDENT 
				  if(aux!="?" ||aux=="BYE" ) return true;
  	              else return false;
  	    		
			  }
		  }
		  
		bool Compilador::aux31(){
  	    	if( aux19() && aux32()) return true;
  	    	else return false;
		  }
		  
		bool Compilador::aux32(){
			if (generarCadena()=="+" || generarCadena()=="-" || generarCadena()=="*" || generarCadena()=="/" ){
				if(aux31()) return true;
			} else{
				if (generarCadena()=="!") return true;
				else return false;	}
	
	 }
	
		  
		bool Compilador::condicion(){
				if(generarCadena()=="(" && aux34() && generarCadena()==")" && generarCadena()=="!")return true;
			    else return false;

		  }
		  	
		bool Compilador::aux34(){
			
  	        if (aux19() && aux35() && aux19() &&  aux36()) return true ;
  	        else return false;
				/// No tiene un folow directo 
			
				
		  }
		  
		bool Compilador::aux35(){
		   	string aux = generarCadena();
				  if(aux!="!=" ||aux=="<" aux!=">" ||aux=="<=" aux!="=>" ||aux=="=="  ) return true;
  	              else return false;
		  }
		  
		bool Compilador::aux36(){
			
  	    	if (generarCadena()=="#" || generarCadena()=="&" ){
				if(aux34()) return true;
			
			} else{
				if (generarCadena()==")") return true;
				else return false;
					}
		  }

