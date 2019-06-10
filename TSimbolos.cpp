#include <bits/stdc++.h>

bool flagNum=false;
int conErrores=0;
using namespace std;

struct dato{
	string tipo;
	string nombre;
};




static vector<string> vSimbolos;
static vector<dato>  datos;

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
	bool verificaTiposIguales(dato d, dato e){
		bool flag;
		
		if(d.tipo==e.tipo){
			flag=true;
			
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
			 if(flagAux) return flag;	
			  
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
							
							return flag;
					 
   }	




	



