//Compiladores
//Integrantes: María José Borjón Ibarra & César Iván Martínez Martínez
//Fecha: 7 de Febrero de 2019
#include <bits/stdc++.h>
#include "TSimbolos.cpp"
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
	    bool aux17(string a);/// Nota ¿porqué  tiene un parametro STRING ?
		bool aux18();
		bool aux19(string aux);/// Nota ¿porqué  tiene un parametro STRING ?
		bool aux20();
	    bool aux22(string a);
		bool aux26(string a);
		bool aux27();
		bool aux28();	
		bool aux30(string a);
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
		}/// inicia con una letra
		else if(aux==32){
			  
				return generarCadena();
		}	
		else { // inicia con un numero o un punto   
		     return numeros();
		}
	
		
	}else{  /// Nota: para que es este ELSE 
		
		char a = (char) aux;
		string regreso="";
		regreso=a;
		return regreso;
	}	
}

//funcion para evitar errores
bool validarAux(char a){
	if(a!='='&&a!='?'&&a!='!'&&a!='#'&&a!='&'&&a!='+'&&a!='-'&&a!='*'&&a!='/'&&a!='('&&a!=')'&&a!='{'&&a!='}'&&a!='_'&&a!='@')	return true;
	else return false;
}

string Compilador::palabras(){
	string regresa;
	
	regresa=cadena[i-1];
     int aux = (int) encontrarValor();
     
	 while (aux != 32 ){
	 	if(validarAux(cadena[i-1])){
	 			regresa+=cadena[i-1];
		        aux = (int) encontrarValor();
		 }else{
		 	i--;
		 	return regresa;
		 }
			
	}
	i--;
	 return regresa;
}


string Compilador::numeros(){
	int punto = 0;
	bool tieneLetra = false;
	string regresa;
	int aux = (int) encontrarValor();
	regresa+=cadena[i-2];
	
	//Numeros de 48-57   while (aux != 32 && !(aux>=65&&aux<=90||aux>=97&&aux<=122)){
	//while (aux != 32 && !(aux>=65&&aux<=90||aux>=97&&aux<=122||aux>=58&&aux<=64||aux==40||aux==41)){
    while (aux != 32 ){
	  	
	  	if(validarAux(cadena[i-1])){
	  		  	if((int)cadena[i-1]==46){
	 				punto++;
				}
	 	
	 	if(punto<2){
	 			regresa+=cadena[i-1];
	            aux = (int) encontrarValor();
		 }else{
		 	while(aux!=32) aux = (int) encontrarValor();
		 	regresa="";
		 	break;
		  } 
		}else{
		 	break;
		 }		
	}
	
	i--;
	
     ///cout<<"Longitud: "<<regresa.size()<<endl;
  /// Verificar punto al final Punto al final 	
	if((int)regresa[regresa.size()-1]==46){
	//	cout<<"Punto al final";
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
	        return a;
	}

}


//Funciones del BNF

  	    void Compilador::programa(){
  	    	  if(bloque()){
  	    	  	//Bye
  	    	  	printf("Todo bien");
				}else{
			      if(generarCadena()=="BYE")
			        printf("Todo bien");
			        else
			      printf("Todo mal");
				}	  
		  }
		  
		  
		bool Compilador::bloque(){   
		     ///Faltaria follows
  	          if(aux1()){
  	          	cout<<"BLOQUE 1"<<endl;
  	          	 //cout<<"Donde queda: "<<generarCadena()<<endl;
  	            	if(aux6()){
  	            			cout<<"BLOQUE 6"<<endl;
  	            		if(aux10()){
  	            			 	cout<<"BLOQUE 10"<<endl;
  	            			if(instruccion()){
  	            				 	cout<<"BLOQUE I"<<endl;
  	            				return true;
							  }else{
							  	return false;
							  }
						  }else{
						  	return false;
						  }
					  }else{
					  	return false;
					  }
				}else{
				   return false;	
				} 
  	        
            }
		  
/// En AUX1 se ha agregado auxi
		  
		bool Compilador::aux1(){
		      int auxi=i;	  
		      string aux = generarCadena();
		       if(aux=="-"){
		       		cout<<"a1 1"<<endl;
		       	 if(aux2()){
		       	 	  	cout<<"a1 2"<<endl;
					if(aux3()){
						  	cout<<"a1 3"<<endl;	  	 
					    if(generarCadena()=="!"){
					    	 	cout<<"a1 4"<<endl;
					         return true;
							}else{
						 	return false;	
							}
						}else{
					 	return false;	
						}
					}else{
					 return false;	
					}
			   }else{
			     	///Funcion para regresar a un estado anterior ///Utilizar una flag que guarde el estado anterior o simplemente el valor de i
			   	  if(aux=="@"||aux=="declara."||aux=="go."||aux=="cuando"||
					aux=="Sii"||aux=="}"||aux=="?"||aux=="BYE"||aux!="") {
				     i=auxi;
				    cout<<"a1 follow"<<endl;
					 return true;}  /// p
				   else return false;
			   }
	    }
	    
	    
	    /// En AUX2 no es necesario agregar auxi
		bool Compilador::aux2(){
			string aux = generarCadena();
  	     if(aux=="entero"||aux=="decimal"||aux=="bool"||aux=="cadena"||
		    aux=="simbolo"||aux=="void") return true;
	       else return false;
		  }
		  
		/// En aux 3 no es necesario agregar auxi porque no tiene fallows --> checar
		bool Compilador::aux3(){
		       	///Saber que es un identificador osea un nombre de una variable o de alguna funcion
			string aux = generarCadena();
  	    		   //cout <<"Aux "<<aux<<endl;
			   if(aux!=""){
			   	  	cout<<"a2 1"<<endl;
			   	 if(aux4()){
			   	 	 	cout<<"a2 2"<<endl;
			   	 	 return true;
				  }else{
					return false;
				  } 
			   }else{
			   	 return false;
			   }
		  }
		  
	
		  ///En aux4 no es necesario agregar auxi, porque su unico follow es !	  
		bool Compilador::aux4(){
		    int auxi = i;
			string aux = generarCadena();
		//	cout<<aux<<" hola"<<endl;
			if(aux=="!"){
					cout<<"a4 follow"<<endl;
				//Follow debemos regresar posicion, aqui podría ser el final por el ! que es equivalente al punto y coma.
				i=auxi;
				return true;
			}else{
				 //if(aux!=""){
				 //	  	cout<<"a4 1"<<endl;
				 	  	    //string aux2 = generarCadena();
				 	  		//cout<<"aux2"<<aux2<<endl;
				 	if(aux=="?"){
				 		 	cout<<"a4 1"<<endl;
				 		if(aux3()){
				 			 	cout<<"a4 2"<<endl;
				 			return true;
						 }else{
						 	return false;
						 }
					 }else{
					 	return false;
					 }
			//	 }else{
			//	 	return false;
			//	 }
			}
			 
		  }
		  
	
	/// aux 6 ya tiene el auxi	  
		bool Compilador::aux6(){
	        int auxi=i;	  	
			string aux = generarCadena();
			
			  if(aux=="@"){
			  	cout<<"a6 1"<<endl;
			  	  if(aux2()){
			  	  	 cout<<"a6 2"<<endl;
			  	  	  if(aux7()){
			  	  	  	 cout<<"a6 3"<<endl;
			  	  	  	  if(generarCadena()=="!"){
			  	  	  	  	 cout<<"a6 4"<<endl;
			  	  	  	  	  return true;
							}else{
								return false;
							}
						  }else{
						  	return false;
						  }
					}else{
						return false;
					}
			  }else{
			  	//Follow mantener posision
			  		if(aux=="declara."||aux=="go."||aux=="cuando"|| aux=="Sii"||
					  aux=="}"||aux=="?"||aux=="BYE"||aux!="") {
					  		i=auxi;
					  	return true;
					  
					  }
				    else return false;
			  }
		}


/// Aux 7 no tiene auxi --> no tiene follow
		  
		bool Compilador::aux7(){
			
			//Falta validar que sean identificadores o que sean numeros 
  	      /*   if(generarCadena()!="" && generarCadena()=="="&&  generarCadena()!="" && aux8() && generarCadena()=="!"){
  	          	 	return true;	
  	          	 } else return false; */
  	              string aux77 = generarCadena();
  	              cout<<"Aux7::"<<aux77<<endl;
  	              if(aux77!=""){
  	              	cout<<"a7 1"<<endl;
  	              	  if(generarCadena()=="="){
  	              	  	 cout<<"a7 2"<<endl;
  	              	  	 if(generarCadena()!=""){
  	              	  	 	cout<<"a7 3"<<endl;
  	              	  	 	 if(aux8()){
  	              	  	 	 	cout<<"a7 4"<<endl;
  	              	  	 	 	 int auxi = i;
  	              	  	 	 	 string auxiliar = generarCadena();
  	              	  	 	 	 if(auxiliar=="!"){
  	              	  	 	 	 	cout<<"a7 5"<<endl;
  	              	  	 	 	 	  	i=auxi;
  	              	  	 	 	 	     return true;
										}else{
										 	return false;
										}
								}else{
									return false;
								}
							}else{
								return false;
							}
						  }else{
						  	return false;
						  }
					}else{
						return false;
					}
				    
		}
				
		  ///  Aux8 está exento de auxi debido a queno tiene follow
		bool Compilador::aux8(){
			int auxi = i;
		string aux = generarCadena();
			 
			 if(aux=="?"){
			 	if(aux7())return true;
			 	else return false;
			 }else{ /// aquí no es necesario poner AUXI
			 	if(aux=="!"){
			 		i=auxi;
			 	    return true;	
				 }
			 	else return false;
			 }	
		}
		
		///En aux10 Ya ha sido agregado auxi  
		bool Compilador::aux10(){	
		      int auxi=i;  
			  string aux = generarCadena();
			  if(aux=="declara."){
			  	cout<<"a10 1"<<endl;
			  	if(aux2()){
			  		cout<<"a10 2"<<endl;
			  		if(generarCadena()!=""){
			  			cout<<"a10 3"<<endl;
			  			if(generarCadena()=="(" ){
			  				cout<<"a10 4"<<endl;
			  				if(aux12()){
			  					cout<<"a10 5"<<endl;
			  				   	if(generarCadena()==")" ){
			  				   		cout<<" a10 6"<<endl;
			  				    	if(generarCadena()=="{"){
			  				    		cout<<"  a10 7"<<endl;
			  				           if( aux14()){
			  				           	  cout<<"a10 8"<<endl;
			  				              if(generarCadena()=="}"){
			  				              	 cout<<"a10 9"<<endl;
			  				                if(aux10()){
			  				                	cout<<"a10 10"<<endl;
			  				                     if(generarCadena()=="!"){
			  				                     	cout<<"a10 11"<<endl;
			  				                            return true;
													  }else{
													  	return false;
													}
												  }else{
												  	return false;
												}
											  }else{
											  	return false;
											}
										  }else{
										  	return false;
										}
									  }else{
									  	return false;
									}
								  }else{
								  	return false;
								}
							  }else{
							  	return false;
							  }
						  }else{
						  	return false;
						  }
					  }else{
					  	 return false;
					  }
				  }else{
				  	return false;
				  }
			  }else{
			  	 	if(aux=="go."||aux=="cuando"|| aux=="Sii"||
				    aux=="}"||aux=="!"||aux=="BYE"||aux!="") {
				    i=auxi;
					return true;
				}
				   else return false;
			  }
		  }
		  
		/// En aux 12 No es necesario el uso de auxi
		bool Compilador::aux12(){
			    string auxiliar = generarCadena();
			    cout<<"F12::"<<auxiliar<<endl;
			  if(auxiliar!=""){
			  	 cout<<"a12 1"<<endl;
			  	if(aux13()) {
			  	cout<<"a12 2"<<endl;
			  	  return true;	
				  }
			  	else return false;
			  }else{
			  	return false;
			  }	  
		}
		  
		/// Tiene auxi pero no estoy segura  de que sea necesario  
		bool Compilador::aux13(){
			int auxi=i;
			  string aux = generarCadena();
			  cout<<"F13::"<<aux<<endl;
			  if(aux=="?"){
			  	cout<<"a13 1"<<endl;
			  	if(aux12()){
			  		cout<<"a13 2"<<endl;
			  		return true;
				  }else{
				  	return false;
				  }
			  }else{
			  		if(aux==")"){
			  			i=auxi;
			  			cout<<"a13 follow"<<endl;
			  			return true;
			  			
					  } 
					else return false;
			  }
		}
	
	///No es necesario el uso de auxi pues no tiene FOLLOWS 	  
	    bool Compilador::aux14(){
	    	if(instruccion()) {
	    		cout<<"a14 i"<<endl;
	    		if(aux15()){
	    		cout<<"a14 2"<<endl;	
	    			return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
	   }

///Tiene auxi, hay que checarque tan necesario es 
		  
		bool Compilador::aux15(){
		   int auxi=i;		
			string aux = generarCadena();
			
			cout<<"F15::"<<aux<<endl;
		
			if(aux=="?"){
				cout<<"a15 1"<<endl;
				if(aux14()){
						cout<<"a15 2"<<endl;
					return true;
				}else{
					return false;
				}
			}else{
				cout<<"Prueba"<<endl;
				if(aux=="}"||aux=="BYE") {
				    cout<<"a15 follow"<<endl;
					i= auxi;
					return true;
				}
				 else 	return false;
			}
		}
		  
		  //// ejemplo
		  
		  /// La funcion instrucción ya tiene agregado auxi
   bool Compilador::instruccion(){
   	/// en las intrucciones debe de llevar el parametro de ( la funcion a evaluar en lugar de generarla en cada funcion de intruccion 
   	        int auxi=i;
		  	string aux = generarCadena(); 	  ///Este aux es el que se usara en las diferentes funciones ...
		  	cout<<aux+" es la instrucción"<<endl;
		  	if(aux17(aux)) {
		  		 cout<<"ins 1"<<endl;
		  		if (aux22(aux)){
		  			 cout<<"ins 2"<<endl;
		  			if(aux26(aux)){
		  				 cout<<"ins 3"<<endl;
		  				if(aux30(aux)){
		  					 cout<<"ins 4"<<endl;
		  					return true;
						  }
						else return false;
		  				
					  }
					else return false;
				  }
				else return false;
			  }
			  else{
			  	
			   if (aux=="?"||aux=="}"||aux=="BYE") {
			   	 cout<<"ins follow"<<endl;
			   	i=auxi;
			   	
			   	return true; }
			  
			  else return false;
	   }
	}
		 
	
	///La funcion aux17 ya tiene auxi
	    bool Compilador::aux17(string aux){
	    	/// No olvidar que la comparacion a diferente de vacio es para el "nombre " que nosostros otorguemos a la variable = IDENT		
		    
		    int auxi=i;
		   // string aux = generarCadena(); 
	
			if(aux=="go."){
				  cout<<"a17 1"<<endl;
               if(generarCadena()!=""){
               	 cout<<"a17 2"<<endl;
               	 if(generarCadena()=="("){
               	 	cout<<"a17 3"<<endl;
               	 	if(aux18()){		
               	 		 string hola = generarCadena();
               	 		 cout<<"a17 4 "<<hola<<endl;
               	 		 if(hola==")"){
               	 		 	cout<<"a17 5"<<endl;
               	 		 	if(generarCadena()=="!"){
               	 		 		cout<<"a17 6"<<endl;
               	 		 		return true;
								 }else{
								 	return false;
								 }
							 }else{
							 	return false;
							 }
						}else{
							return false;
						}
					}else{
						return false;
					}
			   }else{
			   	return false;
			   }				
			}else{
				
			   if(aux=="cuando" || aux=="Sii"||aux=="?"||aux=="}"||aux=="BYE" ||aux!=""){
			   	cout<<"a17 follow"<<endl;
			    i=auxi;	
			   	return true;
			   }  else return false;	
			}
		  }
		  
   ///Aux18 no tiene auxi por que solo tiene ! como follow
		bool Compilador::aux18(){
			
			int auxi=i;
			string aux = generarCadena();
							  
				  if(aux==")"||aux=="!"){
				  	cout<<"a18 follow"<<endl;
				  	i=auxi;
				  	 return true;
				  }else{
				  	if(aux19(aux)){
				  		cout<<"a18 1"<<endl;
				  		if(aux20()){
				      		cout<<"a18 2"<<endl;
				  			return true;
						  }else{
						  	return false;
						  }
					  }else{
					  	return false;
					  }
				  }
		  }
		
		
		///Aux 19 no utiliza auxi, ya que no tiene follows  
		bool Compilador::aux19(string aux){
			cout<<"a19 checa "+aux<<endl;
  	       if(aux!=""){
  	       	cout<<"a19 "<<endl;  ///checho la variabl
			  return true;
			 } 		
	       else  return false;
        }
		
		/// Aux 20 no tiene auxi porque no es necesario ya que solo tiene ! como follow  
		bool Compilador::aux20(){			  
				  string aux = generarCadena();
				  
				  if(aux=="?"){
				  	cout<<"a20 1"<<endl;
				  	if(aux18()){
				  		cout<<"a20 2"<<endl;
	
				  		return true;
					  }else{
					  	return false;
					  }
				  }else{
				  	 if(aux=="!"){
					   
				  	 cout<<"a20 follow"<<endl;
					    return true;}
				  	 else return false;
				  }
        }
		  
		  //// AUX22 ya tiene auxi 
	    bool Compilador::aux22(string aux){
		 // string aux = generarCadena();
		  int auxi=i;

		  if(aux=="cuando"){
		  	cout<<"a22 1"<<endl;
		  	   if(aux19(generarCadena())){
		  	   	  cout<<"a22 2"<<endl;
		  	   	   if(generarCadena()=="!"){
		  	   	   	cout<<"a22 3"<<endl;
		  	   	   	     if(condicion()){
		  	   	   	     	cout<<"a22 4"<<endl;
		  	   	   	     	  if( generarCadena()=="!"){
		  	   	   	     	  	cout<<"a22 5"<<endl;
		  	   	   	     	       if(instruccion() ){
		  	   	   	     	       	cout<<"a22 6"<<endl;
		  	   	   	     	           if(	generarCadena()=="{"){
		  	   	   	     	           	cout<<"a22 7"<<endl;
		  	                               if(aux14()){
		  	                               	cout<<"a22 8"<<endl;
		  	                                   if(generarCadena()=="}"){
		  	                                   	cout<<"a22 9"<<endl;
		  	                                        if(generarCadena()=="!"){
		  	                                        	cout<<"a22 10"<<endl;
		  	                                             return true;
													  }else{
													  	return false;
													  }
												  }else{
												  	return false;
												  }
											  }else{
											  	return false;
											  }
										  }else{
										  	return false;
										  }
								    }else{
									  	return false;
									  }
							  }else{
							  	return false;
							  }
						  }else{
						  	return false;
						  }
						}else{
							return false;
						}
				 }else{
				 	return false;
				 }
		  }else{
		  	      if(aux=="Sii"||aux!="" ||aux=="?" ||aux=="}" ||aux=="BYE") {
		  	      	cout<<"a22 follow  "<<endl;
                    i= auxi;
		  	      	return true;
					}
  	              else return false;
		  }  
	  }
		  
		  
		  /// Aux26 ya tiene el auxi
		bool Compilador::aux26(string aux){
		int auxi=i;	
	   
		//string aux = generarCadena();	
		cout<<"El aux es "+aux<<endl;
	  
			 if(aux=="Sii"){
			 	cout<<"a26 1 checo si"<<endl;
			 	if(generarCadena()=="(" ){
			 		cout<<"a26 2  checo ( "<<endl;
			 		
			 	   	if(condicion()){
			 	   		cout<<"a26 ya checo condicion"<<endl;
			 	   	//	i--;
			 	   		string fun26=generarCadena();
			 	   		 cout<<"Fun26 "<<fun26<<" "<<generarCadena()<<endl;
			 		   if(fun26==")"){
			 		   	cout<<"a26 4"<<endl;
			 		       if(generarCadena()=="{"){
			 		       	cout<<"a26 5"<<endl;
			 		          if(aux14() ){
			 		          	cout<<"a26 6"<<endl;
			 		              if(generarCadena()=="}"){
			 		              	cout<<"a26 7"<<endl;
			 		                 if(aux27()){
			 		                 	cout<<"a26 8"<<endl;
			 		                     if(aux28()){		 		                     	
			 		                     	   string hola = generarCadena();
			 		                     	    cout<<"a26 9 "<<hola<<endl;
			 		                         if(generarCadena()=="!" ){
			 		                         	cout<<"a26 10"<<endl;
			 		                             return true;
												 }else{
												 	return false;
												 }
											 }else{
											 	return false;
											 }
										 }else{
										 	return false;
										 }
									 }else{
									 	return false;
									 }
								 }else{
								 	return false;
								 }	
							 }else{
							 	return false;
							 }	
						 }else{
						 	return false;
						 }	
					 }else{
					 	return false;
					 }	
				 }else{
				 	return false;
				 }
			 }else{
			 	if(aux=="BYE" ||aux=="?" ||aux=="}" ||aux!="") {
			 		cout<<"a26 follow"<<endl;
			    i=auxi;
			 	return true;	
				 }
  	            else return false;
			 }
	   }
		  
	//// Aux27 tiene auxi	  
		bool Compilador::aux27(){  
		         int auxi=i;
			  string aux = generarCadena();
			 
			  if(aux=="Quiza"){
			  	cout<<"a27 1"<<endl;
			  	    if(generarCadena()=="("){
			  	   	  	cout<<"a27 2"<<endl;

			  	    	 if(condicion()){
			  	   	  	cout<<"a27 3"<<endl;

			  	    	    if(generarCadena()==")"){
			  	    	    	  	cout<<"a27 4"<<endl;

			  	    	        if(generarCadena()=="{"){
			  	    	        	 	  	cout<<"a27 5"<<endl;

			  	    	            if(aux14()){
			  	    	            	 	cout<<"a27 6"<<endl;

			  	    	                if(generarCadena()=="}"){
			  	    	              	   	  	cout<<"a27 7"<<endl;

			  	    	                    if( aux27()){
			  	    	                  	   	  	cout<<"a27 8"<<endl;

			  	    	                       if(generarCadena()=="!"){
			  	    	                       			 	cout<<"a27 9"<<endl;

			  	    	                          return true;
												  }else{
												  	return false;
												  }
											  }else{
											  	return false;
											  }
										  }else{
										  	return false;
										  }
									  }else{
									  	return false;
									  }
								  }else{
								  	return false;
								  }
							  }else{
							  	return false;
							  }
						  }else{
						  	return false;
						  }
					  }else{
					  	return false;
					  }
			  }else{
			  	 if(aux=="Noo" ||aux=="!"||aux=="}") {
		  	   	  	cout<<"a27 follow"<<endl;

			  	 	i=auxi;
			  	 	return true;
				   }
  	              else return false;
			  }
  	    	
		  }
		  
		  
		////Aux28 tiene  no tiene auxi porque el unico follow es !
		bool Compilador::aux28(){
			int auxi=i;
			string aux = generarCadena();
			
			if(aux=="Noo"){
		  	   	  	cout<<"a28 1"<<endl;

				if( generarCadena()=="{"){
			  	   	  	cout<<"a28 2"<<endl;

					if(aux14()){
		       	   	  	cout<<"a28 3"<<endl;

					   	if(generarCadena()=="}"){
					   	   cout<<"a28 4"<<endl;	
					       return true;
							}else{
								return false;
							}
						}else{
							return false;
						}
				}else{
					return false;
				}
			}else{
				if(aux=="!"||aux=="}") { 
				i=auxi;
				cout<<"a28 follow"<<endl;return true;
				}
				else return false ;
			}
	   }
	
	///Aqui no estoy segura de si lleva auxi debido a que el follow está primero	  	
		bool Compilador::aux30(string aux){
			 // string aux = generarCadena(); 
			 if(aux!="?" ||aux=="BYE" ){
			 	cout<<"a30 follow"<<endl;
				 return true;
			 }
			 else{
			 	if(aux!=""){
			 		cout<<"a30 1"<<endl;
			 		if(generarCadena()=="=" ){
			 			cout<<"a30 2"<<endl;
			 		  if(aux31()){
			 		  	cout<<"a30 3"<<endl;
			 		      if(generarCadena()=="!"){
			 		      	cout<<"a30 4"<<endl;
			 		          return true;
							 }else{
							 	return false;
							 }
						 }else{
						 	return false;
						 }
					 }else{
					 	return false;
					 }
				 }else{
				 	return false;
				 }
			 }
		  }
	
	
	///Aux31 no lleva auxi	  
		bool Compilador::aux31(){
  	    	if(aux19(generarCadena())){
  	    		cout<<"a31 1"<<endl;
  	    		if(aux32()){
  	    			cout<<"a31 2"<<endl;
  	    			return true;
				  }else{
				  	return false;
				  }
			  }else{
			  	if(generarCadena()=="!" ) 
				  {
				  cout<<"a31 follow"<<endl;
				  return true;
				  }
  	              else return false;
			  }
		  }
		  
	
		///Aux32 no lleva auxi	  
	  
		bool Compilador::aux32(){
			string aux = generarCadena();
			if (aux=="+" || aux=="-" || aux=="*" || aux=="/" ){
				  cout<<"a32 1"<<endl;
				
				if(aux31()) {
					cout<<"a32 2"<<endl;
					return true;
				}
				else return false;
			} else{
				if (generarCadena()=="!") {
						cout<<"a32 follow"<<endl;
					return true;
				}
				else return false;	
								}
	   }
	
	
	
	///La funcion condicion no requiere auxi	  
		bool Compilador::condicion(){
			
		
			    	if(aux34()){ 
			  	    	cout<<"cond 2  Num IDENT"<<endl;
                               
                           //  string aux=generarCadena();
                            // cout<<aux<<endl;
			    	      return true;
					
			     	}else{
                          	 return false;		
				}
		  }
		  	
		  	
		//// Ya tiene auxi
		bool Compilador::aux34(){
				/// No tiene un folow directo 
				int auxi=i;
				string aux=generarCadena();
				if(aux19(aux)){
				cout<<"a34 1 varieble="+aux<<endl;
			      if(aux35()){
			      	cout<<"a34 2"<<endl;
			    	if(aux19(generarCadena())){
			    		cout<<"a34 3"<<endl;
			    	  if(aux36()){
			    	  	cout<<"a34 4"<<endl;
			    	          return true;
							}else{
								return false;
							}        
						}else{
							return false;
						}      
					}else{
						return false;
					}	          
				}else{
                if (generarCadena()==")") {
               	
                     i=auxi;
                     cout<<"a34 follow"<<endl;
                return true;	
				}
				else return false;					}				
		  }
		  
		 	///La funcion aux35 no requiere auxi	  
		bool Compilador::aux35(){
		   	 string aux = generarCadena();
		     string aux2=aux+generarCadena();
		   	 
			
				  	  if(aux2=="!=" ||aux2=="<=" || aux2=="=>" ||aux2=="==") {
				  	  	 cout<<"a35 2"<<endl;
				  		 return true;
				      }
				      // Nota i = auxi;
  	                 else{
					      if(aux=="<"|| aux==">"){
					   	  return true;
					   }
					   return false;
					   }
				 
		  }
		  
		  
		  ///Aux32 TIENE auxi
		bool Compilador::aux36(){
			int auxi=i;
			string aux = generarCadena();
			cout<<"El aux36 maneja"+aux<<endl;
  	    	if (aux=="#"|| aux=="&"){
			     if(aux34()){
  	    		cout<<"a36 1"<<endl;
			 return true;}
			}else{
				if (aux==")"){
					cout<<"follow a36 2"<<endl;
					i=auxi;
					return true;
				} 
				else return false;
					        }
		}

