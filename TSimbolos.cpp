#include <bits/stdc++.h>

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
			vSimbolos.push_back("'\'");
		}


    void buscarSimbolo(string aux){
    	if(find(vSimbolos.begin(), vSimbolos.end(), aux)!=vSimbolos.end()){
    		cout<<"Encontrado"<<endl;
		}else{
			cout<<"NOOO Encontrado"<<endl;
		}
	}


