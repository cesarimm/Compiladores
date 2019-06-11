#include <bits/stdc++.h>

bool flagNum=false;
int conErrores=0;
using namespace std;

struct dato{
	string tipo;
	string nombre;
};

struct funcion{
	string nombre;
	vector<string> tiposVar;
};



static vector<string> vSimbolos;
static vector<dato>  datos;
static vector<funcion> funciones;

		void llenar(){	
		
			vSimbolos.push_back("simbolo");	
			vSimbolos.push_back("cadena");	
			vSimbolos.push_back("entero");	
			vSimbolos.push_back("decimal");	
			vSimbolos.push_back("void");	
			vSimbolos.push_back("cuando");	
			vSimbolos.push_back("sii");	
			vSimbolos.push_back("quiza");	
			vSimbolos.push_back("noo");
			vSimbolos.push_back("go.");	
			vSimbolos.push_back("declara.");
			vSimbolos.push_back("=");	
			vSimbolos.push_back("?");	
			vSimbolos.push_back("!");
			vSimbolos.push_back("#");	
			vSimbolos.push_back("&");
			vSimbolos.push_back("+");	
			vSimbolos.push_back("-");
			vSimbolos.push_back("*");	
			vSimbolos.push_back("/");
			vSimbolos.push_back("(");	
			vSimbolos.push_back(")");
			vSimbolos.push_back("{");	
			vSimbolos.push_back("}");
			vSimbolos.push_back("_");
			vSimbolos.push_back("@");	
			///NOTA Se remplaza por el @ vSimbolos.push_back("'\'");
       }
	   
	  	bool validarNumero(string aux){
			int error=0;
			char a;
			 for(int i=0;i<aux.size();i++){
			 	a=aux[i];
			 	if(!((int)a>45&&(int)a<58))
			         error++;
			    if((int)a==47)
			     error++;
			 }
		if(error==0)return true;
		else return false;	 
	 }
	
		
	 bool buscarSimbolo(string aux){
    	int a =(int)aux[0];
    	if(find(vSimbolos.begin(), vSimbolos.end(), aux)!=vSimbolos.end()){
    	//	cout<<"Encontrado"<<endl;
    	  flagNum=false;
    	  return true;
		}else{
		//	cout<<"NOOO Encontrado"<<endl;
		       if(aux.length()>1){
				//No se le concatenen letras a los numeros
				if(a>47&&a<58){
				     ///Si es un número
				    return validarNumero(aux);
				}else{
					 //Si es una palabra
					return true;
				}
			}else{
				conErrores++;
				return false;
			}
		   
		}
	}
	
		
					
   bool verificarDato(dato d){ 	
   	/// en esta parte checa que no pertenezca a nuestra tabla de simbolos
   	bool flag = false;
   	 if(find(vSimbolos.begin(), vSimbolos.end(), d.nombre)!=vSimbolos.end()){
   		   flag=true;
	   }
	   else{
		   	if(datos.size()!=0){	
		       	for(int i=0; i<datos.size(); i++){
					    if(datos[i].nombre==d.nombre){
							flag=true;
							break;
						}
				}		
			}
		}			
		return flag;	
	}
	
	
		
	void agregarDato(string tipo, string nombre){	
		dato d;
		d.nombre=nombre;
		d.tipo=tipo;
		
		if(!verificarDato(d))		
		datos.push_back(d);	
		else
		cout<<"La variable "+d.nombre+" ya esta declarada."<<endl;	
	}
	
  	
	/// Verficar tipo de dato con el valor del dato
	bool verificaTiposIguales(string d,string e){
		bool flag;	
		
		dato a, b;
		
		for(int i=0;i<datos.size();i++){
			if(datos[i].nombre==d){
				a=datos[i];
				break;
			}		
		}
		
			for(int i=0;i<datos.size();i++){
			if(datos[i].nombre==e){
				b=datos[i];
				break;
			}		
		}
		
		if(a.tipo==b.tipo){
			cout<<"Datos compatibles"<<endl;
			return true;
		}else{
			 cout<<"Datos no compatibles para la comparacion"<<endl;
			return false;
		}		
	}


   bool verificarTipo(string nombre, string valor){
   	  bool flag = false, flagAux=true;
   	  dato dAux;
   	  
   	  for(int i=0;i<datos.size();i++){
   	  	   if(datos[i].nombre==nombre){
                flagAux=false;
   	  	   	    dAux=datos[i];
   	  	   	    break;
				}
		 }
		 
		 //En caso de que no este la varable
			 if(flagAux) {
			 cout<<nombre<<" No ha sido declarada"<<endl;
			 return flag;		
			 }
			  
			  if(dAux.tipo=="entero"){
		    	if(validarNumero(valor)){
					flag=true;
				}
				else {
					flag=false;
				}
		    	
			}
				else if(dAux.tipo=="decimal"){
					cout<<"Entre aquí!"<<endl;
					if(validarNumero(valor)){
						flag=true;
					}
					else {
						flag=false;
					}			
					
				}
					else if(dAux.tipo=="simbolo"){
						
						if(valor.size()==1){
							flag=true;
						}
						else {
							flag=false;
						}
						
					}
					    else{
					    	if(valor.size()>=1){
								flag=true;
							}
							else {
								flag=false;
						 }
							}
							
						if(!flag){
								cout<<nombre<<" Tipo de dato incompatible"<<endl;	
							}
							
							return flag;
					 
   }	


	void agregarFuncion(funcion f){	
		funciones.push_back(f);
	}


   bool verificarFuncion(funcion f){ 	
   	bool flag = false;
		   	if(datos.size()!=0){	
		       	for(int i=0; i<funciones.size(); i++){
					    if(funciones[i].nombre==f.nombre){
							flag=true;
							break;
						}
				}		
			}
					
		return flag;	
	}
	
		bool verificarTipoFuncion(string aux, string f){
			cout<<"Verificar Funcion "<<aux<<" "<<f<<endl;
			
		bool flag = false;
		dato d;
		
		for(int i=0;i<datos.size();i++){
			if(datos[i].nombre==f){
				 if(datos[i].tipo==aux){
				 	flag = true;
				 	break;
				 }
			}
		}
		
		return flag;	
	}
	
	
	bool comprobarGo(funcion f){
		bool flag=false;
		
		funcion aux;
		
		for(int i=0;i<funciones.size();i++){			
		    if(funciones[i].nombre==f.nombre){
		    	aux=funciones[i];
		    	break;
			}
		}
		
		///Comprobar que tengan el mismo numero de parametros
		if(aux.tiposVar.size()==f.tiposVar.size()){
			///comprobar que cumplan el tipo
			for(int i=0;i<aux.tiposVar.size();i++){
				if(verificarTipoFuncion(aux.tiposVar[i], f.tiposVar[i])){
					flag=true;
				}else{
					flag=false;
					break;
				}
			}
		}
		
		if(!flag){
			cout<<"La funcion declarada contiene errores en sus parametros"<<endl;
		}
				
		return flag;
	}
	
	

	



