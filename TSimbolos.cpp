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


    bool buscarSimbolo(string aux){
    	int a =(int)aux[0];
    	if(find(vSimbolos.begin(), vSimbolos.end(), aux)!=vSimbolos.end()){
    	//	cout<<"Encontrado"<<endl;
    	  flagNum=false;
    	  return true;
		}else{
		//	cout<<"NOOO Encontrado"<<endl;
		    if(aux=="sp"){
			 return true;
			}else if(aux.length()>1){
				//No se le concatenen letras a los numeros
				if(a>47&&a<58){
					cout<<"Es numero"<<endl;
					flagNum=true;
					return true;
				}else{
					
					if(flagNum&&(a>64&&a<91||a>96&&a<123)){
						cout<<"Es complicado"<<endl;
						flagNum=false;
						conErrores++;
						cout<<aux<<endl;
						return false;
					}
					
					cout<<"Es palabra"<<endl;
					flagNum=false;
					return true;
				}
			}else{
				//cout<<"Error de compilacion"<<endl;
				conErrores++;
				return false;
			}
		   
		}
	}



