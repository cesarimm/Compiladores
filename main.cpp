#include "Cadenas.cpp"
#include "TSimbolos.cpp"
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
	
	//cout<<"Referencia :"<<comp.ref<<endl;
	bool error; //= true;
	

	/*do{
		 error=buscarSimbolo(comp.generarCadena());
		 if(!error)
		 cout<<"Con errores: "<<conErrores<<endl;
			 
		//cout<<comp.i<<endl;	 
	}while(comp.ref!=comp.i);*/
	
	
	return 0;
}
