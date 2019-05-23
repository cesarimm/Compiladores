#include <bits/stdc++.h>

bool flagNum=false;
int conErrores=0;
using namespace std;
static vector<string> vSimbolos;
//static string vSimbolo[24] = {"simbolo", "cadena", "entero", "void", "cuando", "sii", "quiza", "noo", "go.", "declara.", "?", "!","#","&","+","-","*","/",")","(","}","{","_","'\'"};
		void llenar(){	
			vSimbolos.push_back("simbolo");	
			vSimbolos.push_back("cadena");	
			vSimbolos.push_back("entero");	
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
	
	

	 
	 
/*	int main(){
		if(buscarSimbolo("abcd1234"))
		 cout<<"Numero valido"<<endl;
		 else cout<<"Numero invalido"<<endl;
		 
		return 0;
	} */
   



