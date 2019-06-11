#include "Cadenas.cpp"
//#include "TSimbolos.cpp"
#include <bits/stdc++.h>

//Desactrivar bandera a tiempo
//bandera para el final del documento
int main(){
	llenar();
	llenar();
	Compilador comp;
	comp.extraerTexto();        
     comp.programa();	
     
     for(int i=0;i<comp.var.size();i++){
     	cout<<"elementos del vector "<<comp.var[i]<<endl;
	 }
     
/* dato d;
 d.nombre="var1";
 d.tipo="simbolo";
 
 agregarDato("cadena", "var1");
 cout<<datos[0].nombre+" "+datos[0].tipo<<endl;
 
 agregarDato("decimal", "var2");
  //cout<<datos[1].nombre+" "+datos[1].tipo<<endl;
  
 if(verificarTipo("var2","a")){
 	cout<<"El tipo es valido"<<endl;
 	
 }
 else{
 	 	cout<<"El tipo es invalido"<<endl;
 }*/
 
 
	return 0;
}
