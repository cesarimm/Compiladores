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
	    bool aux17(string);/// Nota ¿porqué  tiene un parametro STRING ?
		bool aux18();
		bool aux19(string);/// Nota ¿porqué  tiene un parametro STRING ?
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
			      //Error
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
  	              cout<<"Aux77::"<<aux77<<endl;
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
			  				   		cout<<"a10 6"<<endl;
			  				    	if(generarCadena()=="{"){
			  				    		cout<<"a10 7"<<endl;
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
				    aux=="}"||aux=="!"||aux!="") {
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
			  	if(aux12()){
			  		return true;
				  }else{
				  	return false;
				  }
			  }else{
			  		if(aux==")"){
			  			i=auxi;
			  			return true;
					  } 
					else return false;
			  }
		}
	
	///No es necesario el uso de auxi pues no tiene FOLLOWS 	  
	    bool Compilador::aux14(){
	    	if(instruccion()){
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
			cout<<"F15::"<<aux<<" "<<generarCadena()<<" "<<generarCadena()<<" "<<generarCadena()<<endl;
			if(aux=="?"){
				cout<<"a15 1"<<endl;
				if(aux14()){
						cout<<"a15 2"<<endl;
					return true;
				}else{
					return false;
				}
			}else{
				if(aux==")") {
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
		  	string aux = generarCadena();
		  	int auxi=i;
		  	if(aux17(aux)) {
		  		if (aux22()){
		  			if(aux26()){
		  				if(aux30()){
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
			   	i=auxi;
			   	return true; }
			  
			  else return false;
	   }
	}
		 
	
	///La funcion aux17 ya tiene auxi
	    bool Compilador::aux17(string aux){
	    	/// No olvidar que la comparacion a diferente de vacio es para el "nombre " que nosostros otorguemos a la variable = IDENT		
		    
		    int auxi=i;
		    
			if(aux=="go."){
               if(generarCadena()!=""){
               	 if(generarCadena()=="("){
               	 	if(aux18()){
               	 		 if(generarCadena()==")"){
               	 		 	if(generarCadena()=="!"){
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
			    i=auxi;	
			   	return true;
			   }  else return false;	
			}
		  }
		  
   ///Aux18 no tiene auxi por que solo tiene ! como follow
		bool Compilador::aux18(){
			
			string aux = generarCadena();
							  
				  if(aux=="!"){
				  	 return true;
				  }else{
				  	if(aux19(aux)){
				  		if(aux20()){
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
  	       if(aux!="") return true;
	       else  return false;
        }
		
		/// Aux 20 no tiene auxi porque no es necesario ya que solo tiene ! como follow  
		bool Compilador::aux20(){			  
				  string aux = generarCadena();
				  
				  if(aux=="?"){
				  	if(aux18()){
				  		return true;
					  }else{
					  	return false;
					  }
				  }else{
				  	 if(aux=="!") return true;
				  	 else return false;
				  }
        }
		  
		  //// AUX22 ya tiene auxi 
	    bool Compilador::aux22(){
		  string aux = generarCadena();
		  int auxi=i;
		  if(aux=="cuando"){
		  	   if(aux19(generarCadena())){
		  	   	   if(generarCadena()=="!"){
		  	   	   	     if(condicion()){
		  	   	   	     	  if( generarCadena()=="!"){
		  	   	   	     	       if(instruccion() ){
		  	   	   	     	           if(	generarCadena()=="{"){
		  	                               if(aux14()){
		  	                                   if(generarCadena()=="}"){
		  	                                        if(generarCadena()=="!"){
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
                    i= auxi;
		  	      	return true;
					}
  	              else return false;
		  }  
	  }
		  
		  
		  /// Aux26 ya tiene el auxi
		bool Compilador::aux26(){
				  
		string aux = generarCadena();
	    int auxi=i;
		 		  
			 if(aux=="Sii"){
			 	if(generarCadena()=="(" ){
			 	   	if(condicion()){
			 		   if(generarCadena()==")"){
			 		       if(generarCadena()=="{"){
			 		          if(aux14() ){
			 		              if(generarCadena()=="}"){
			 		                 if(aux27()){
			 		                     if(aux28()){
			 		                         if(generarCadena()=="!" ){
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
			    i=auxi;
			 	return true;	
				 }
  	            else return false;
			 }
	   }
		  
	//// Aux27 tiene auxi	  
		bool Compilador::aux27(){  
			  string aux = generarCadena();
			  int auxi=i;
			  if(aux=="Quiza"){
			  	    if(generarCadena()=="("){
			  	    	 if(condicion()){
			  	    	    if(generarCadena()==")"){
			  	    	        if(generarCadena()=="{"){
			  	    	            if(aux14()){
			  	    	                if(generarCadena()=="}"){
			  	    	                    if( aux27()){
			  	    	                       if(generarCadena()=="!"){
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
			  	 if(aux=="Noo" ||aux=="!" ) {
			  	 	i=auxi;
			  	 	return true;
				   }
  	              else return false;
			  }
  	    	
		  }
		  
		  
		////Aux28 tiene  no tiene auxi porque el unico follow es !
		bool Compilador::aux28(){
			string aux = generarCadena();
			
			if(aux=="Noo"){
				if( generarCadena()=="{"){
					if(aux14()){
					   	if(generarCadena()=="}"){
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
				if(aux=="!") return true;
				else return false ;
			}
	   }
	
	///Aqui no estoy segura de si lleva auxi debido a que el follow está primero	  	
		bool Compilador::aux30(){
			  string aux = generarCadena(); 
			 if(aux!="?" ||aux=="BYE" ) return true;
			 else{
			 	if(aux!=""){
			 		if(generarCadena()=="=" ){
			 		  if(aux31()){
			 		      if(generarCadena()=="!"){
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
  	    		if(aux32()){
  	    			return true;
				  }else{
				  	return false;
				  }
			  }else{
			  	if(generarCadena()=="!" ) return true;
  	              else return false;
			  }
		  }
		  
	
		///Aux32 no lleva auxi	  
	  
		bool Compilador::aux32(){
			string aux = generarCadena();
			if (aux=="+" || aux=="-" || aux=="*" || aux=="/" ){
				if(aux31()) return true;
				else return false;
			} else{
				if (generarCadena()=="!") return true;
				else return false;	
								}
	 }
	
	
	
	///La funcion condicion no requiere auxi	  
		bool Compilador::condicion(){
			
		/*		if(generarCadena()=="(" && aux34() && generarCadena()==")" && generarCadena()=="!")return true;
			    else return false;*/
			    
			    if(generarCadena()=="("){
			    	if(aux34()){
			    	  if(generarCadena()==")"){
			    	        if(generarCadena()=="!"){
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
                if (generarCadena()=="!") return true;
				else return false;		
							}
		  }
		  	
		  	
		//// Ya tiene auxi
		bool Compilador::aux34(){
				/// No tiene un folow directo 
				int auxi=i;
				if(aux19(generarCadena())){
			      if(aux35()){
			    	if(aux19(generarCadena())){
			    	  if(aux36()){
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
                return true;	
				}
				else return false;					}				
		  }
		  
		 	///La funcion aux35 no requiere auxi	  
		bool Compilador::aux35(){
		   	string aux = generarCadena();
				  if(aux!="!=" ||aux=="<" || aux!=">" ||aux=="<=" || aux!="=>" ||aux=="=="  ) return true;
  	              else return false;
		  }
		  
		  
		  ///Aux32 TIENE auxi
		bool Compilador::aux36(){
			string aux = generarCadena();
			int auxi=1;
			
  	    	if ((aux=="#" || aux=="&")&&aux34()){
			 return true;
			}else{
				if (aux==")"){
					i=auxi;
					return true;
				} 
				else return false;
					        }
		}

