#include "Cadenas.cpp"
//#include "TSimbolos.cpp"
#include <bits/stdc++.h>

//Desactrivar bandera a tiempo
//bandera para el final del documento
int main(){
	llenar();
	Compilador comp;
	comp.extraerTexto();
	
	cout<<comp.cadena<<endl;
	//cout<<comp.generarCadena()<<endl;	
	//cout<<comp.generarCadena()<<endl;
	/*cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;
	cout<<comp.generarCadena()<<endl;*/
	// vector<string> vSimbolo;  //("simbolo", "cadena", "entero", "void", "cuando", "sii", "quiza", "noo", "go.", "declara.");
	// vSimbolo.push_back("hola");
	// agregar();
	//cout<<vSimbolo[0];
	//	cout<<vSimbolo[1];
	//cout<<vSimbolos[0];
		
	/*do{
		 error=buscarSimbolo(comp.generarCadena());
		 if(!error)
		 cout<<"Con errores: "<<conErrores<<endl;	 
		//cout<<comp.i<<endl;	 
	}while(comp.ref!=comp.i);*/
	 	comp.programa();
	 	
	//cout<<comp.generarCadena()<<endl;
	//cout<<comp.generarCadena()<<endl;
	//cout<<comp.generarCadena()<<endl;
	//cout<<comp.generarCadena()<<endl;
    //cout<<comp.generarCadena()<<endl;
    //cout<<comp.generarCadena()<<endl;
    //if(buscarSimbolo("hola"))
   // if(buscarSimbolo("123"))
    //if(buscarSimbolo(" "))
      // cout<<"Si sirve"<<endl;
	
	return 0;
}
