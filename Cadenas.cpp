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
	    bool aux17(string);
		bool aux18();
		bool aux19(string);
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
			  
				return generarCadena();
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
  	          if(aux1()) return true;
  	           else return false;	
            }
		  

		  
		bool Compilador::aux1(){	  
		      string aux = generarCadena();
		       if(aux=="-"){
		       	 if(aux2()){
					if(aux3()){
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
			     	///Funcion para regresar a un estado anterior ///Utilizar una flag que guarde el estado anterior o simplemente el valor de i
			   	  if(aux=="@"||aux=="declara."||aux=="go."||aux=="cuando"||
					aux=="Sii"||aux=="}"||aux=="?"||aux=="BYE"||aux!="") return true;
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
			string aux = generarCadena();
  	    		   
			   if(aux!=""){
			   	 if(aux4()){
			   	 	 return true;
				  }else{
					return false;
				  } 
			   }else{
			   	 return false;
			   }
		  }
		  
		  
		bool Compilador::aux4(){
		
			string aux = generarCadena();
			
			if(aux=="!"){
				//Follow debemos regresar posicion, aqui podría ser el final por el ! que es equivalente al punto y coma.
				return true;
			}else{
				 if(aux!=""){
				 	if(generarCadena()=="?"){
				 		if(aux3()){
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
			}
			 
		  }
		  
		  
		bool Compilador::aux6(){
							
			string aux = generarCadena();
			  if(aux=="@"){
			  	  if(aux2()){
			  	  	  if(aux7()){
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
			  	//Follow mantener posision
			  		if(aux=="declara."||aux=="go."||aux=="cuando"|| aux=="Sii"||
					  aux=="}"||aux=="?"||aux=="BYE"||aux!="") return true;
				    else return false;
			  }
		}
		  
		bool Compilador::aux7(){
			
			//Falta validar que sean identificadores o que sean numeros 
  	         if(generarCadena()!="" && generarCadena()=="="&&  generarCadena()!="" && aux8() && generarCadena()=="!"){
  	          	 	return true;	
  	          	 } else return false;
  	              
  	              if(generarCadena()!=""){
  	              	  if(generarCadena()=="="){
  	              	  	 if(validarNumero(generarCadena())){
  	              	  	 	 if(aux8()){
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
				    
		}
				
		  
		bool Compilador::aux8(){
			
		string aux = generarCadena();
			 
			 if(aux=="?"){
			 	if(aux7())return true;
			 	else return false;
			 }else{
			 	if(aux=="!") return true;
			 	else return false;
			 }	
		}
		  
		bool Compilador::aux10(){	  
			  string aux = generarCadena();
			  
			  if(aux=="declara."){
			  	if(aux2()){
			  		if(generarCadena()!=""){
			  			if(generarCadena()=="(" ){
			  				if(aux12()){
			  				   	if(generarCadena()==")" ){
			  				    	if(generarCadena()=="{"){
			  				           if( aux14()){
			  				              if(generarCadena()=="}"){
			  				                if(aux10()){
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
				  	return false;
				  }
			  }else{
			  	 	if(aux=="go."||aux=="cuando"|| aux=="Sii"||
				    aux=="}"||aux=="?"||aux=="BYE"||aux=="!"||aux!="") return true;
				   else return false;
			  }
		  }
		  
		bool Compilador::aux12(){
			  if(generarCadena()!=""){
			  	if(aux13()) return true;
			  	else return false;
			  }else{
			  	return false;
			  }	  
		}
		  
		bool Compilador::aux13(){
			  string aux = generarCadena();
			  if(aux=="?"){
			  	if(aux12()){
			  		return true;
				  }else{
				  	return false;
				  }
			  }else{
			  		if(aux=="}") return true;
					else return false;
			  }
		}
		  
	    bool Compilador::aux14(){
	    	if(instruccion()){
	    		if(aux15()){
	    			return true;
				}else{
					return false;
				}
			}else{
				return false;
			}
	   }
		  
		bool Compilador::aux15(){		
			string aux = generarCadena();
			if(aux=="?"){
				if(aux14()){
					return true;
				}else{
					return false;
				}
			}else{
				if(aux==")") return true;
				 else 	return false;
			}
		}
		  
		  ////Dudas y más dudas
	    bool Compilador::instruccion(){
			  ///Tengo una duda
			  string aux = generarCadena();
			  if(aux17(aux)){
			  	if(aux22()){
			  		if(aux26()){
			  			return true;
					  }else{
					  	return false;
					  }
				  }else{
				  	return false;
				  }
			  }else{
			  	if (aux=="?"||aux=="BYE") return true;	 
			    else return false;
			  }
		  }
		  
		  
		  
	    bool Compilador::aux17(string aux){
	    	/// No olvidar que la comparacion a diferente de vacio es para el "nombre " que nosostros otorguemos a la variable = IDENT		
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
			   if(aux=="cuando" || aux=="Sii"||aux=="?"||aux=="}"||aux=="BYE" ||aux!="") return true;
				else return false;	
			}
		  }
		  
		  
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
		  
		bool Compilador::aux19(string aux){
  	       if(aux!="") return true;
	       else  return false;
        }
		  
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
		  
		  ////
	    bool Compilador::aux22(){
		  string aux = generarCadena();
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
		  	      if(aux=="Sii"||aux!="" ||aux=="?" ||aux=="}" ||aux=="BYE") return true;
  	              else return false;
		  }  
	  }
		  
		bool Compilador::aux26(){
				  
		string aux = generarCadena();
			  
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
			 	if(aux=="BYE" ||aux=="?" ||aux=="}" ||aux!="") return true;
  	            else return false;
			 }
	   }
		  
		  
		bool Compilador::aux27(){  
			  string aux = generarCadena();
			  
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
			  	 if(aux!="Noo" ||aux=="!" ) return true;
  	              else return false;
			  }
  	    	
		  }
		  
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
		  
		bool Compilador::aux31(){
  	    	if(aux19(generarCadena())){
  	    		if(aux32()){
  	    			return true;
				  }else{
				  	return false;
				  }
			  }else{
			  	return false;
			  }
		  }
		  
		  
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
	
		  
		bool Compilador::condicion(){
			
				if(generarCadena()=="(" && aux34() && generarCadena()==")" && generarCadena()=="!")return true;
			    else return false;
			    
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
					return false;
				}
		  }
		  	
		bool Compilador::aux34(){
				/// No tiene un folow directo 
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
					return false;
				}				
		  }
		  
		  
		bool Compilador::aux35(){
		   	string aux = generarCadena();
				  if(aux!="!=" ||aux=="<" || aux!=">" ||aux=="<=" || aux!="=>" ||aux=="=="  ) return true;
  	              else return false;
		  }
		  
		  
		bool Compilador::aux36(){
			string aux = generarCadena();
  	    	if ((aux=="#" || aux=="&")&&aux34()){
			 return true;
			}else{
				if (aux==")") return true;
				else return false;
					        }
		}

