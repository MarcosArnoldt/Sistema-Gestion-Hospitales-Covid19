#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define AZULC 3
#define ROJO 4
#define BLANCO 15
#define AMARILLO 14
#define BLINK 128

using namespace std;
struct pacientes{                     //registro de pacientes
	char nombre[50], apellido[50], numero_contacto[20]; 
	int edad, obra_social, estado, dni, riesgo, ubicado, borrado;
};
struct cama{                         //registro de camas
	int tipo_sala, estado, borrado; 
};
struct equipo_medico{               //registro de especialidades
	char especialidad[50]; 
	int cant_medicos,borrado; 
};
struct cant_stock{                 //registro de cantidad de paquetes en stock
	int tipo_paquete, cantidad_paquete, borrado; 
};
struct respiradores{
	int estado_r,borrado; 
};
void cero(pacientes *v){
	//funcion para inicializar el vector. 
	for(int i=0; i<100; i++){
		v[i].dni=0; 
		v[i].edad=0; 
		v[i].estado=0; 
		strcpy(v[i].numero_contacto, " "); 
		v[i].obra_social=0; 
		v[i].riesgo=0; 
		v[i].ubicado=0; 
		strcpy(v[i].apellido, " "); 
		strcpy(v[i].nombre, " "); 
	}
}
void altas_pacientes(){
	//carga de pacientes. 
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE); 
	system("cls"); 
	int n=0, i=0, esta=0, obra_social=0, estado=0, ubicado=0, riesgo=0, band=0; 
	FILE *p;
	SetConsoleTextAttribute(consola, BLINK); //cambio de color 
	cout<<"------Programa de carga para el archivo de informacion de pacientes en un hospital COVID------"<<endl; 
	SetConsoleTextAttribute(consola, BLANCO); //cambio de color
	p = fopen ("pacientes.dat" , "a+b");
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura del archivo";
		cout << "Presione una tecla... ";
		SetConsoleTextAttribute(consola, AMARILLO);
		fclose(p);
		exit (1);
	}else{
		pacientes v[100];
		pacientes r;
		//mover los datos del registro al vector para saber si existe. 
		while (feof(p) == 0){
            strcpy(v[i].apellido, r.apellido);
			strcpy(v[i].nombre, r.nombre);
			v[i].dni=r.dni;
			v[i].edad=r.edad;
			v[i].estado=r.estado;
			strcpy(v[i].numero_contacto, r.numero_contacto);
			v[i].obra_social=r.obra_social;
			v[i].riesgo=r.riesgo;
			v[i].ubicado=r.ubicado;
			i++;
			fread (&r, sizeof(pacientes), 1, p);
		}
		SetConsoleTextAttribute(consola, AZULC); //cambio de color	
		cout<<"Ingrese cantidad de pacientes: "; 
		cin>>n; 
		for(i=0; i<n; i++){
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
			cout<<"Paciente #"<<i<<endl;
			cout<<"Ingrese el apellido: "; 
			SetConsoleTextAttribute(consola, BLANCO); //cambio de color
			cin>>r.apellido; 
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
			cout<<"Ingrese el nombre: "; 
			SetConsoleTextAttribute(consola, BLANCO); //cambio de color
			cin>>r.nombre; 
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
			cout<<"Ingrese el DNI: "; 
			SetConsoleTextAttribute(consola, BLANCO); //cambio de color 
			cin>>r.dni;
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
			cout<<"Ingrese la edad: "; 
			SetConsoleTextAttribute(consola, BLANCO); //cambio de color
			cin>>r.edad;
			do{
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"¿Tiene obra social? (1- Si/ 0- NO): ";
				SetConsoleTextAttribute(consola, BLANCO); //cambio de color
				cin>>obra_social;
				if (obra_social>-1 && obra_social<2){
					r.obra_social=obra_social;
					obra_social=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO); //cambio de color
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				}
			}while (obra_social<0 || obra_social>1);
			do{
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"Ingrese el estado de la enfermedad (1- GRAVE/ 0- LEVE): ";
				SetConsoleTextAttribute(consola, BLANCO); //cambio de color
				cin>>estado;
				if (estado>-1 && estado<2){
					r.estado=estado;
					estado=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO); //cambio de color
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				}
			}while (estado<0 || estado>1);
			do{
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"Ingrese si es paciente de riesgo (1- SI/ 0- NO): "; 
				SetConsoleTextAttribute(consola, BLANCO); //cambio de color
				cin>>riesgo;
				if (riesgo>-1 && riesgo<2){
					r.riesgo=riesgo;
					riesgo=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO); //cambio de color
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				}
			}while (riesgo<0 || riesgo>1);
			do{
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"Ingrese la sala donde esta ubicado el paciente (1- SALA COMUN /0- TERAPIA INTENSIVA): "; 
				SetConsoleTextAttribute(consola, BLANCO); //cambio de color
				cin>>ubicado;
				if (ubicado>-1 && ubicado<2){
					r.ubicado=ubicado;
					ubicado=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO); //cambio de color
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				}
			}while (ubicado<0 || ubicado>1); 
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
			cout<<"Ingrese un numero de contacto: "; 
			SetConsoleTextAttribute(consola, BLANCO); //cambio de color
			cin>>r.numero_contacto; 
			cout<<endl; 
			for(int i=0; i<100; i++){
				if(v[i].dni==r.dni){
					band=1; 
				}
			}
			if(band==0){
				fwrite (&r, sizeof (pacientes), 1, p);
			}else{
				SetConsoleTextAttribute(consola, ROJO); //cambio de color
				cout<<"Ese paciente ya existe"<<endl;
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"Presione ENTER para continuar..."<<endl;
				std :: cin.ignore ();    
				std :: cin.get (); 
			}
		}			
	}
	fclose(p);	 
}		
void altas_camas(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *c; 
	SetConsoleTextAttribute(consola, BLINK); //cambio de color
	cout<<"------Programa de carga para el archivo de informacion de camas en un hospital COVID------"<<endl;
	SetConsoleTextAttribute(consola, BLANCO); //cambio de color 
	c = fopen ("camas.dat" , "a+b");
	if (c == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		SetConsoleTextAttribute(consola, AMARILLO);
		fclose(c);
		exit (1);
	}else{	
		int n=0, tipo_sala=0, estado=0;
		SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
		cout<<"Ingrese cantidad de camas: "; 
		SetConsoleTextAttribute(consola, BLANCO); //cambio de color
	 cin>>n; 
		cama r;
		for(int i=0; i<n; i++){
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
			cout<<"Cama #"<<i+1<<endl;
			do{
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"Ingrese el tipo de sala (1- SALA COMUN /0- TERAPIA INTENSIVA): "; 
				SetConsoleTextAttribute(consola, BLANCO); //cambio de color
			    cin>>tipo_sala;
				if (tipo_sala>-1 && tipo_sala<2){
					r.tipo_sala=tipo_sala;
					tipo_sala=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO); //cambio de color
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				}
			}while (tipo_sala<0 || tipo_sala>1); 
			SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
		    do{
				SetConsoleTextAttribute(consola, AMARILLO); //cambio de color
				cout<<"Ingrese el estado (1-Ocupado/ 0-Disponible): "; 
				SetConsoleTextAttribute(consola, BLANCO); //cambio de color
				cin>>estado;
				if (estado>-1 && estado<2){
					r.estado=estado;
					estado=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO); //cambio de color
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
					SetConsoleTextAttribute(consola, BLANCO); //cambio de color
				}
			}while (estado<0 || estado>1);  
			cout<<endl; 
			fwrite (&r, sizeof (cama), 1, c);
		}
	}
	fclose(c); 
}
void altas_equipo_medico(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *e; 
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"------Programa de carga para el archivo de informacion de especialidades en un hospital COVID------"<<endl;
	SetConsoleTextAttribute(consola, BLANCO); 
	e = fopen ("equipos.dat" , "a+b");
	if (e == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		SetConsoleTextAttribute(consola, AMARILLO);
		fclose(e);
		exit (1);
	}else{
		int n=0;	
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<"Ingrese cantidad de especialidades medicas: ";
		SetConsoleTextAttribute(consola, BLANCO); 
 	cin>>n;	
		equipo_medico r;
		for(int i=0; i<n; i++){
			SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Ingrese la especialidad medica: "; 
			SetConsoleTextAttribute(consola, BLANCO);
			cin>>r.especialidad; 
			SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Ingrese la cantidad de medicos: "; 
			SetConsoleTextAttribute(consola, BLANCO);
			cin>>r.cant_medicos; 
			cout<<endl; 
			fwrite (&r, sizeof (equipo_medico), 1, e);
		}
	}
	fclose(e); 
}
void altas_stock(){ 
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *s; 
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"------Programa de carga para el archivo de informacion de stock en un hospital COVID------"<<endl; 
	s = fopen ("stock.dat" , "a+b");
	if (s == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		SetConsoleTextAttribute(consola, AMARILLO);
		fclose(s);
		exit (1);
	}else{	
		int tipo_paquete=0, n=0;
		SetConsoleTextAttribute(consola, AZULC);
		cout<<endl; 
		cout<<"-----------Tipos de paquetes-----------"<<endl;
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<"1-Paquetes de materiales de testeo"<<endl;
		cout<<"2-Paquetes de insumos personales del paciente"<<endl;
		cout<<"3-Paquetes de medicamentos para el tratamiento"<<endl;
		cout<<"4-Paquetes de insumos medicos"<<endl;
		cout<<endl;
		do{
			SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Ingrese cuantos tipos de paquetes desea cargar: "; 
			SetConsoleTextAttribute(consola, BLANCO);
			cin>>n;
			if (n<1 || n>4){
				SetConsoleTextAttribute(consola, ROJO);
				cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				SetConsoleTextAttribute(consola, BLANCO);
				n=0;
			}
		}while (n<1 || n>4); 
		cant_stock r;
		for(int i=0; i<n; i++){
			do{
				SetConsoleTextAttribute(consola, AMARILLO);
				cout<<"Ingrese el tipo de paquete a cargar (opcion 0 - 5) : "; 
				SetConsoleTextAttribute(consola, BLANCO);
				cin>>tipo_paquete;
				if (tipo_paquete>0 && tipo_paquete<5){
					r.cantidad_paquete=tipo_paquete;
					tipo_paquete=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO);
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
				}
			}while (tipo_paquete<0 || tipo_paquete>1); 
			SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Ingrese la cantidad de paquetes en stock: "; 
			SetConsoleTextAttribute(consola, BLANCO);
			cin>>r.cantidad_paquete; 
			cout<<endl; 
			fwrite (&r, sizeof (cant_stock), 1, s);
		}
	}
	fclose(s); 
}
void altas_respiradores(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); 
	FILE *l; 
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"------Programa de carga para el archivo de informacion de respiradores en un hospital COVID------"<<endl; 
	l = fopen ("respiradores.dat" , "a+b");
	if (l == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		fclose(l);
		exit (1);
	}else{	
		int estado_r=0, n=0;
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<"Ingrese cantidad de respiradores: "; 
		SetConsoleTextAttribute(consola, BLANCO);
		cin>>n; 
		respiradores r;
		for(int i=0; i<n; i++){
			SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Respirador numero: "<<i+1<<endl;
			do{
				SetConsoleTextAttribute(consola, AMARILLO);
				cout<<"Ingrese el estado (1-Ocupado/ 0-Disponible): "; 
				SetConsoleTextAttribute(consola, BLANCO);
				cin>> estado_r;
				if (0 > estado_r || estado_r<=2){
					r.estado_r=estado_r;
					estado_r=0;
				}else{
					SetConsoleTextAttribute(consola, ROJO);
					cout<<"La opcion ingresada no es valida, intentelo de nuevo..."<<endl;
					SetConsoleTextAttribute(consola, BLANCO);
				}
			}while (estado_r<0 || estado_r>1);
			cout<<endl; 
			fwrite (&r, sizeof (respiradores), 1, l);
		}
	}
	fclose(l); 
}
void ordenar(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	int i=0;
	char aux[50], aux1[50], aux7[20]; 
	FILE *p;
	pacientes v[100]; 
	//inicializar el vector en 0 para que no traiga basura. 
	cero(v);
	p = fopen ("pacientes.dat","rb");
	cout<<endl; 
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(p);
	}else{
		SetConsoleTextAttribute(consola, BLANCO);
	    pacientes r;
	    fread(&r, sizeof(pacientes), 1, p);
	    while (feof(p) == 0){
			strcpy(v[i].apellido, r.apellido);
			strcpy(v[i].nombre, r.nombre);
			v[i].dni=r.dni;
			v[i].edad=r.edad; 
			v[i].estado=r.estado; 
			strcpy(v[i].numero_contacto, r.numero_contacto); 
			v[i].obra_social=r.obra_social; 
			v[i].riesgo=r.riesgo;   
			i++; 
			fread (&r, sizeof(pacientes), 1, p);
	    }
	    	for (i=0;i<100;i++){
        		for (int j=i+1;j<100;j++){
            		if (v[i].apellido>v[j].apellido){
            			strcpy(v[i].apellido,aux); 
            			strcpy(v[j].apellido, v[i].apellido);
                		strcpy(aux, v[j].apellido);
                		
                		strcpy(v[i].nombre,aux1); 
            			strcpy(v[j].nombre, v[i].nombre);
                		strcpy(aux1, v[j].nombre);
                		
                		int aux2=v[i].dni;
                		v[i].dni=v[j].dni;
                		v[j].dni=aux2;
                		
                		int aux3=v[i].edad;
                		v[i].edad=v[j].edad;
                		v[j].edad=aux3;
                		
						int aux4=v[i].obra_social;
                		v[i].obra_social=v[j].obra_social;
                		v[j].obra_social=aux4;
                		
						int aux5=v[i].estado;
                		v[i].estado=v[j].estado;
                		v[j].estado=aux5;
                		
						int aux6=v[i].riesgo;
                		v[i].riesgo=v[j].riesgo;
                		v[j].riesgo=aux6;
                		
                		int aux8=v[i].ubicado; 
                		v[i].ubicado=v[j].ubicado; 
                		v[j].ubicado=aux8; 
                		
						strcpy(v[i].numero_contacto, aux7); 
            			strcpy(v[j].numero_contacto, v[i].numero_contacto);
                		strcpy(aux7, v[j].numero_contacto);                 		
            		}
				}
			}
			SetConsoleTextAttribute(consola, BLINK);
    		cout<<"Listado de pacientes ordenados alfabeticamente"<<endl;
			cout<<endl;  
    		for(i=0; i<100; i++){
    			if(v[i].dni>0){
    				SetConsoleTextAttribute(consola, BLANCO);
    				cout<<"Paciente numero: "<<i+1<<endl;
    				cout<<"Apellido: "<<v[i].apellido<<endl; 
    				cout<<"Nombre: "<<v[i].nombre<<endl; 
    				cout<<"DNI: "<<v[i].dni<<endl; 
    				cout<<"Edad: "<<v[i].edad<<endl; 
    				cout<<"Obra Social (1-Si/0-NO): "<<v[i].obra_social<<endl; 
    				cout<<"Estado de la enfermedad (1- GRAVE / 0- LEVE): "<<v[i].estado<<endl; 
    				cout<<"Paciente de riesgo (1-Si/0-NO): "<<v[i].riesgo<<endl; 
    				cout<<"Donde esta ubicado el paciente (1-SALA COMUN / 0-TERAPIA INTENSIVA): "<<v[i].ubicado<<endl; 
    				cout<<"Numero de contacto: "<<v[i].numero_contacto<<endl; 
    				SetConsoleTextAttribute(consola, AMARILLO);
    				cout<<"----------------------"<<endl; 
    				SetConsoleTextAttribute(consola, BLANCO);
				}
    			
			}
		
	    fclose (p);
	}
	system("pause");	
}
int buscar(int x, pacientes *v){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	int i=0, esta=-1;
	FILE *p;
	p = fopen ("pacientes.dat","rb");
	cout<<endl; 
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(p);
	}else{
	    pacientes r;
	    fread(&r, sizeof(pacientes), 1, p);
	    while (feof(p) == 0){
			strcpy(v[i].apellido, r.apellido);
			strcpy(v[i].nombre, r.nombre);
			v[i].dni=r.dni;
			v[i].edad=r.edad; 
			v[i].estado=r.estado; 
			strcpy(v[i].numero_contacto, r.numero_contacto); 
			v[i].obra_social=r.obra_social; 
			v[i].riesgo=r.riesgo;   
			v[i].ubicado=r.ubicado; 
			i++; 
			fread (&r, sizeof(pacientes), 1, p);
		}
		for (i = 0; i < 100; i++){          
        	if(x == v[i].dni) {
        		esta=i; 
			}
		}   
		SetConsoleTextAttribute(consola,BLANCO); 
    	cout<<"Apellido: "<<v[esta].apellido<<endl; 
    	cout<<"Nombre: "<<v[esta].nombre<<endl; 
    	cout<<"DNI: "<<v[esta].dni<<endl; 
    	cout<<"Edad: "<<v[esta].edad<<endl; 
    	cout<<"Obra Social (1-Si/0-NO): "<<v[esta].obra_social<<endl; 
    	cout<<"Estado de la enfermedad (1- GRAVE / 0- LEVE): "<<v[esta].estado<<endl; 
    	cout<<"Paciente de riesgo (1-Si/0-NO): "<<v[esta].riesgo<<endl; 
    	cout<<"Donde esta ubicado el paciente (1-SALA COMUN / 0-TERAPIA INTENSIVA): "<<v[esta].ubicado<<endl; 
    	cout<<"Numero de contacto: "<<v[esta].numero_contacto<<endl; 	  
	    fclose (p);
	}	
	cout<<" "<<endl;
	system("pause");
	return esta;
	
}
void pacientes_riesgo(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int cont=0; 
	FILE *p;
	p = fopen ("pacientes.dat","rb");
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"Listado de pacientes de riesgo"<<endl; 
  	if (p == NULL) {
  		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(p);
	}else{
	    pacientes r;
	    fread(&r, sizeof(pacientes), 1, p);
	    while (feof(p) == 0){
	    	if (r.riesgo==1){
	    		SetConsoleTextAttribute(consola, BLANCO);
	    		cout<<"Apellido: "<<r.apellido<<endl; 
	    		cout<<"Nombre: "<<r.nombre<<endl;
				cout<<"DNI: "<<r.dni<<endl; 
				cout<<"Edad: "<<r.edad<<endl; 
				cout<<"Obra Social (1-Si/0-NO): "<<r.obra_social<<endl; 
				cout<<"Estado de la enfermedad (1- GRAVE / 0- LEVE): "<<r.estado<<endl; 
				cout<<"Paciente de riesgo (1-Si/0-NO): "<<r.ubicado<<endl; 
				cout<<"Donde esta ubicado el paciente (1-SALA COMUN / 0-TERAPIA INTENSIVA): "<<endl;
				cout<<"Numero de contacto: "<<r.numero_contacto<<endl; 
				cont++; 
				cout<<endl;		 
			}
			fread (&r, sizeof(pacientes), 1, p);
		}
		if (cont==0){
			SetConsoleTextAttribute(consola, ROJO);
			cout<<"no se han encontrado pacientes de riesgo"<<endl; 
			SetConsoleTextAttribute(consola, BLANCO);
			cout<<"Precione ENTER para continuar";
		    std :: cin.ignore();
	     	std :: cin.get();
	     	cout<<endl; 
		}
	}
	fclose(p);
	cout<<" "<<endl;
	system("pause"); 
}
void cant_camas(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int cont=0, cont1=0, cont2=0; 
	FILE *c;
	c = fopen ("camas.dat","rb");
	if (c == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(c);
	}else{
	    cama r;
	    fread(&r, sizeof(cama), 1, c);
	    while (feof(c) == 0){
	    	if (r.estado==1){
	    		cont++; 
			}
			if(r.estado==1 && r.tipo_sala==0){
				cont1++; 
			}
			if(r.estado==1 && r.tipo_sala==1){
				cont2++; 
			}
			fread (&r, sizeof(cama), 1, c);
		}
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<"La cantidad de camas ocupadas es de: "<<cont<<endl; 
		cout<<endl;
		cout<<"La cantidad de camas de Terapia Intensiva ocupadas es de: "<<cont1<<endl; 
		cout<<endl;
		cout<<"La cantidad de camas en Sala Comun ocupadas es de: "<<cont2<<endl;
		SetConsoleTextAttribute(consola, BLANCO); 
	}
	fclose(c);
	cout<<" "<<endl;
	system("pause");
}
void porcentaje(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int i=0, band=0;  
	float cont1=0, cont2=0, p_ti=0, p_sc=0;
	FILE *p;
	pacientes v[100]; 
	p = fopen ("pacientes.dat","rb");
	cout<<endl; 
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(p);
	}else{
	    pacientes r;
	    fread(&r, sizeof(pacientes), 1, p);
	    while (feof(p) == 0){  
			v[band].ubicado=r.ubicado; 
			band++;  
			fread (&r, sizeof(pacientes), 1, p);
		}
		for(i=0; i<band; i++){
			if(v[i].ubicado==0){
				cont1++; 
			}
			if(v[i].ubicado==1){
				cont2++; 
			}
		}
		p_ti=(cont1*100)/i; 
		p_sc=(cont2*100)/i;
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<"-------"<<endl; 
		cout<<"El porcentaje de pacientes en Terapia Intensiva es: "<<p_ti<<"%"<<endl; 
		cout<<endl; 
		cout<<"El porcentaje de pacientes en Sala Comun es: "<<p_sc<<"%"<<endl; 
		cout<<endl; 
		SetConsoleTextAttribute(consola, BLANCO);
	}
	fclose(p);
	cout<<" "<<endl;
	system("pause");
}
void graves(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *p;
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"Listado de pacientes en estado grave"<<endl; 
	cout<<endl; 
	p = fopen ("pacientes.dat","rb");
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(p);
	}else{
	    pacientes r;
	    fread(&r, sizeof(pacientes), 1, p);
	    while (feof(p) == 0){
	    	if(r.estado==1){
	    		SetConsoleTextAttribute(consola, AMARILLO);
	    		cout<<"Apellido: "<<r.apellido<<endl; 
	    		cout<<"Nombre: "<<r.nombre<<endl; 
	    		cout<<"DNI: "<<r.dni<<endl;
				cout<<endl; 
				SetConsoleTextAttribute(consola, BLANCO); 
			}
			fread (&r, sizeof(pacientes), 1, p);
		}	 
	}
	fclose(p);
	cout<<" "<<endl;
	system("pause");	
}
void disp_respiradores(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int cont1=0, cont2=0;
	FILE *l;
	respiradores v[100]; 
	l = fopen ("respiradores.dat","rb");
	cout<<endl; 
	if (l == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		exit (1);
		fclose(l);
	}else{
	    respiradores r;
	    fread(&r, sizeof(respiradores), 1, l);
	    while (feof(l) == 0){  
		    if(r.estado_r==0){
		    	cont1++; 
		    }
		    cont2++;
		    fread(&r, sizeof(respiradores), 1, l);
	    }
	    SetConsoleTextAttribute(consola, AMARILLO);
	    cout<<"Respiradores disponibles: "<<cont1<<"/"<<cont2<<endl;
	    SetConsoleTextAttribute(consola, BLANCO);
	}
	fclose(l);
	cout<<" "<<endl;
	system("pause");
}

void motrar_pacientes(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *p; 
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"------Archivos de pacientes------"<<endl; 
	p = fopen ("pacientes.dat" , "rb");
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		fclose(p);
		exit (1);
	}else{	
		ordenar();			
		}
	fclose(p); 
	cout<<" "<<endl;
	system("pause");
}
void mostrar_camas(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *c; 
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"------Archivos de camas------"<<endl; 
	c = fopen ("camas.dat" , "rb");
	if (c == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		fclose(c);
		exit (1);
	}else{	
		cama r;
		fread(&r, sizeof(cama), 1, c);
	    while (feof(c) == 0){
	    	SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Tipo de sala (1- SALA COMUN /0- TERAPIA INTENSIVA): "<<r.tipo_sala<<endl; 
			cout<<"Estado (1-Ocupado/ 0-Disponible): "<<r.estado<<endl; 
			cout<<endl; 
			SetConsoleTextAttribute(consola, BLANCO);
			fread(&r, sizeof(cama), 1, c);
		}
	}
	fclose(c);
	cout<<" "<<endl;
	system("pause");
}
void mostrar_equipo_medico(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *e;
	SetConsoleTextAttribute(consola, BLINK); 
	cout<<"------Archivos de Equipos Medicos------"<<endl; 
	e = fopen ("equipos.dat" , "rb");
	if (e == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		fclose(e);
		exit (1);
	}else{	
		equipo_medico r;
		fread(&r, sizeof(equipo_medico), 1, e);
	    while (feof(e) == 0){
	    	SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Especialidad medica: "<<r.especialidad<<endl;
			cout<<"Cantidad de medicos: "<<r.cant_medicos<<endl; 
			cout<<endl; 
			SetConsoleTextAttribute(consola, BLANCO);
			fread(&r, sizeof(equipo_medico), 1, e);
		}
	}
	fclose(e); 
	cout<<" "<<endl;
	system("pause");
}
void mostrar_stock(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *s;
	SetConsoleTextAttribute(consola, BLINK); 
	cout<<"------Archivos de Cantidad en Stock------"<<endl; 
	s = fopen ("stock.dat" , "rb");
	if (s == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		fclose(s);
		exit (1);
	}else{
		cant_stock r;	
		fread(&r, sizeof(cant_stock), 1, s);
	    while (feof(s) == 0){
	    	SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Tipo de paquete: "<<r.tipo_paquete<<endl; 
			cout<<"Cantidad de paquetes en stock: "<<r.cantidad_paquete<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			fread(&r, sizeof(cant_stock), 1, s);
		}
	}
	fclose(s);
	cout<<" "<<endl;
	system("pause"); 
}
void mostrar_respiradores(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *l; 
	SetConsoleTextAttribute(consola, BLINK);
	cout<<"------Archivos Respiradores------"<<endl; 
	l = fopen ("respiradores.dat" , "rb");
	if (l == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout << "Error de Apertura";
		cout << "Presione una tecla... ";
		fclose(l);
		exit (1);
	}else{	
		respiradores r;
		int a=0;
		fread(&r, sizeof(respiradores), 1, l);
	    while (feof(l) == 0){
	    	SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"Estado (1-Ocupado/ 0-Disponible): "<<r.estado_r<<endl;
			cout<<endl; 
			SetConsoleTextAttribute(consola, BLANCO);
			fread(&r, sizeof(respiradores), 1, l);
		}
	}
	fclose(l); 
	cout<<" "<<endl;
	system("pause");
}
void borrar_pacientes (pacientes *v){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	int tam = sizeof (pacientes), x=0, posicion=0, opcion=0;
	FILE *p;
	p = fopen ("pacientes.dat","r+b");
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		pacientes r;
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO);
		cout << "Ingrese DNI del paciente a buscar (cero = salir): ";
		SetConsoleTextAttribute(consola, BLANCO);
		cin >> x;
		cout<<endl;
		while (x!=0){
			posicion = buscar (x,v);
			if (posicion != -1){                           // lo encontró y lo lee
				fseek(p, posicion, SEEK_SET);
				fread (&r, tam, 1, p); 
			    //BORRADO
				do{
					SetConsoleTextAttribute(consola, AMARILLO);
					cout << "¿Esta  seguro de borrarlo (1 = SI/0 = NO)?: "<<endl;
					SetConsoleTextAttribute(consola, BLANCO);
					cin >> opcion;
					if (opcion!=0 && opcion!=1){
						SetConsoleTextAttribute(consola, ROJO);
						cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
						opcion=0;
					}
				}while (opcion!=0 && opcion!=1);
			   	if (opcion==1){                          
	    			r.borrado = 1;                       
					fseek(p, posicion, SEEK_SET);          
					fwrite(&r, tam, 1, p);
					FILE *t;
                    t = fopen ("nuevo.dat" , "wb");
	                if (t == NULL){
	                	SetConsoleTextAttribute(consola, ROJO);
	                    cout << "\n\nError de Apertura del archivo temporal";
	                    cout << "\nPresione una tecla... ";
		                getch();
	                    fclose(t);
						exit (1);
	                }else {
		                fread(&r,tam,1,p);
		                while (feof(p) == 0){
		                    if (r.borrado != 1){
						        fwrite (&r, tam, 1, t);           
                		        fread(&r,tam,1,p);
							}
	                    }
	                    fclose(p);
		                fclose(t);
		                remove("pacientes.dat");
		                rename("nuevo.dat", "pacientes.dat");
	                }
	                SetConsoleTextAttribute(consola, AMARILLO);
					cout << "Registro borrado"<<endl;
					SetConsoleTextAttribute(consola, BLANCO);
					cout << "Pulse una tecla"<<endl;
					
		    	}
		    }
	    }
    }
}
void modificar_pacientes (pacientes *v){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *p;
	p = fopen ("pacientes.dat","r+b");
	if (p == NULL) {
		SetConsoleTextAttribute(consola, ROJO);
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		pacientes r;
		int tam = sizeof (pacientes), posicion=0, opcion1=0, x=0, estado=0, riesgo=0, obra_social=0;
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO);
		cout << "Ingrese DNI del paciente a buscar (cero = salir): ";
		SetConsoleTextAttribute(consola, BLANCO);
		cin >> x;
		cout<<endl;
		while (x!=0){
			posicion = buscar (x,v);
			if (posicion != -1){                           // lo encontró y lo lee
				fseek(p, posicion, SEEK_SET);
				fread (&r, tam, 1, p);                  //muestra el registro como estaba
				//MODIFICAR
				do {
					cout<<endl; 
					SetConsoleTextAttribute(consola, AMARILLO);
					cout<<"1.Nombre"<<endl; 
					cout<<"2.Apellido"<<endl; 
					cout<<"3.DNI"<<endl;
					cout<<"4.Edad"<<endl;
					cout<<"5.Estado"<<endl; 
					cout<<"6.Numero de contacto"<<endl; 
					cout<<"7.Obra social"<<endl; 
					cout<<"8.Riesgo"<<endl; 
					cout<<"9.Ubicacion"<<endl; 
					cout<<"10.Terminar modificaciones"<<endl;
					cout<<endl; 
					do{
						SetConsoleTextAttribute(consola, AMARILLO);
						cout<< "Ingrese opción a modificar: "<<endl;
						SetConsoleTextAttribute(consola, BLANCO);
						cin >> opcion1;
						if (opcion1<1 || opcion1>10){
							SetConsoleTextAttribute(consola, ROJO);
							cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
							opcion1=0;
						}
					}while (opcion1<1 || opcion1>10);
					cout<<endl; 
					switch(opcion1){
						case 1: 
							SetConsoleTextAttribute(consola, AMARILLO);
							cout <<"Actualizacion Nombre: "<<endl;
							SetConsoleTextAttribute(consola, BLANCO);
							cin>>r.nombre;
							break;
						case 2: 
							SetConsoleTextAttribute(consola, AMARILLO);
							cout <<"Actualizacion Apellido: "<<endl;
							SetConsoleTextAttribute(consola, BLANCO);
							cin >>r.apellido;
							break;
						case 3:
							SetConsoleTextAttribute(consola, AMARILLO); 
							cout<<"Actualizacion DNI: "<<endl;
							SetConsoleTextAttribute(consola, BLANCO);
							cin>>r.dni;
							break;  
						case 4: 
							SetConsoleTextAttribute(consola, AMARILLO);
							cout<<"Actualizacion Edad: "<<endl;
							SetConsoleTextAttribute(consola, BLANCO);
							cin>>r.edad;
							break; 
						case 5: 
							do{
								SetConsoleTextAttribute(consola, AMARILLO);
								cout<<"Actualizacion Estado(1- GRAVE/ 0- LEVE): "<<endl;
								SetConsoleTextAttribute(consola, BLANCO);
								cin>>estado;
								if (estado>-1 && estado<2){
									r.estado=estado;
									estado=0;
								}else{
									SetConsoleTextAttribute(consola, ROJO);
									cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
								}
							}while (estado<0 || estado>1);
							break; 
						case 6:
							SetConsoleTextAttribute(consola, AMARILLO); 
							cout<<"Actualizacion Numero de contacto: "<<endl;
							SetConsoleTextAttribute(consola, BLANCO);
							cin>>r.numero_contacto;
							break; 
						case 7: 
							do{
								SetConsoleTextAttribute(consola, AMARILLO);
								cout<<"Actualizacion Obra Social (1- SI/ 0-NO): "<<endl;
								SetConsoleTextAttribute(consola, BLANCO);
								cin>>obra_social;
								if (obra_social>-1 && obra_social<2){
									r.obra_social=obra_social;
									obra_social=0;
								}else{
									SetConsoleTextAttribute(consola, ROJO);
									cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
								}
							}while (obra_social<0 || obra_social>1);
							break; 
						case 8: 
							do{
								SetConsoleTextAttribute(consola, AMARILLO);
								cout<<"Actualizacion Riesgo (1- SI/ 0-NO): "<<endl;
								SetConsoleTextAttribute(consola, BLANCO);
								cin>>riesgo;
								if (riesgo>-1 && riesgo<2){
									r.riesgo=riesgo;
									riesgo=0;
								}else{
									SetConsoleTextAttribute(consola, ROJO);
									cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
								}
							}while (riesgo<0 || riesgo>1);
							break; 
						case 9: 
							int ubicado=0;
							do{
								SetConsoleTextAttribute(consola, AMARILLO);
								cout<<"Actualizacion Ubicacion (1- SALA COMUN /0- TERAPIA INTENSIVA): "<<endl;
								SetConsoleTextAttribute(consola, BLANCO);
								cin>>ubicado;
								if (ubicado>-1 && ubicado<2){
									r.ubicado=ubicado;
									ubicado=0;
								}else{
									SetConsoleTextAttribute(consola, ROJO);
									cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
								}
							}while (ubicado<=-1 || ubicado>=2);
							break; 						
					}
					fseek(p, posicion, SEEK_SET);
					fwrite(&r, tam, 1, p);
                }while (opcion1 != 10);
			}else {
				SetConsoleTextAttribute(consola, ROJO);
				cout<<"El paciente no existe"<<endl;
				SetConsoleTextAttribute(consola, BLANCO);
			    cout<<"Pulse una tecla para continuar"<<endl;
			    getch();
			}
			system("cls");
			SetConsoleTextAttribute(consola, AMARILLO);
			cout << "Ingrese otro DNI (cero = salir): "<<endl;
			SetConsoleTextAttribute(consola, BLANCO);
			cin >> x;
		}
		fclose (p);
	}
}
void borrar_camas (){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *c;
	c = fopen ("camas.dat","r+b");
	if (c == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		cama r;
		int tam = sizeof (cama),contador=0, x=0, opcion=0, y=0;
		cout<<endl;
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<< "Ingrese el tipo de cama que desea eliminar (1- SALA COMUN /0- TERAPIA INTENSIVA)(2 = salir): "<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cin>>x;
			if (x>0 || x<2){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
				x=0;
			}
		}while (x>0 || x<2);
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<endl;  
		cout<<" ¿Cuantas camas deseas eliminar?"<<endl; 
		SetConsoleTextAttribute(consola, BLANCO); 
		cin>>y; 
		cout<<endl;
		while (x!=2){
			fread (&r, tam, 1, c); 
			//BORRADO
		    do{
		    	SetConsoleTextAttribute(consola, AMARILLO); 
				cout << " ¿Esta  seguro de borrarlo (1 = SI/0 = NO)?: "<<endl;
				SetConsoleTextAttribute(consola, BLANCO); 
				cin >> opcion;
				if (opcion!=0 && opcion!=1){
					SetConsoleTextAttribute(consola, ROJO); 
					cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
					opcion=0;
				}
			}while (opcion!=0 && opcion!=1);
			if (opcion==1){
				while (contador != y){
			   	   if (x==1 && r.tipo_sala==1){
			   	   	  r.borrado = 1;                                 
				      fwrite(&r, tam, 1, c);
					  FILE *t;
                      t = fopen ("nuevo.dat" , "wb");
	                  if (t == NULL){
	                  	SetConsoleTextAttribute(consola, ROJO); 
	                    cout << "\n\nError de Apertura del archivo temporal";
	                    cout << "\nPresione una tecla... ";
		                getch();
	                    fclose(t);
						exit (1);
	                  }else {
		                fread(&r,tam,1,c);
		                while (feof(c) == 0){
		                     if (r.borrado != 1){
						        fwrite (&r, tam, 1, t);           
                		        fread(&r,tam,1,c);
						      }
	                    }
	                    fclose(c);
		                fclose(t);
		                remove("camas.dat");
		                rename("nuevo.dat", "camas.dat");
		                contador++;
	                  }
				   }
				   if (x==0 && r.tipo_sala==0){
				  	  r.borrado = 1;         
					  fwrite(&r, tam, 1, c);
					  FILE *t;
                      t = fopen ("nuevo.dat" , "wb");
	                  if (t == NULL){
	                  	SetConsoleTextAttribute(consola, ROJO); 
	                     cout << "\n\nError de Apertura del archivo temporal";
	                     cout << "\nPresione una tecla... ";
		                 getch();
	                     fclose(t);
					     exit (1);
	                  }else {
		                 fread(&r,tam,1,c);
		                 while (feof(c) == 0){
		                     if (r.borrado != 1){
						         fwrite (&r, tam, 1, t);           
                		         fread(&r,tam,1,c);
							 }
	                     }
	                     fclose(c);
		                 fclose(t);
		                 remove("camas.dat");
		                 rename("nuevo.dat", "camas.dat");
	                     contador++;
					  }
				   }
				}                         
	        }
	        SetConsoleTextAttribute(consola, AMARILLO); 
			cout << "Registros borrado"<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cout << "Pulse una tecla"<<endl;
			getch();
		}
	}
}
void modificar_cama (){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *c;
	c = fopen ("camas.dat","r+b");
	if (c == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		cama r;
		int tam = sizeof (cama), opcion1=0, x=0, y=0, w=0, contador=0;
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<" ¿Cuantas camas deseas modificar?"<<endl; 
		SetConsoleTextAttribute(consola, BLANCO); 
		cin>>y;
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<< "Ingrese el tipo de cama que desea modificar (1- SALA COMUN /0- TERAPIA INTENSIVA)(2 = salir): "<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cin>>x;
			if (x>2 || x<0){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
			}
		}while (x<0 || x>2);
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<<" ¿Desea liberarlas u ocuparlas (1-Liberarlas/ 0-Ocuparlas)?"<<endl; 
			SetConsoleTextAttribute(consola, BLANCO); 
			cin>>w;
			if (w>1 || w<0){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
			}
		}while (w>1 || w<0);
		cout<<endl;
		while (x!=2){
			fread (&r, tam, 1, c);                  //muestra el registro como estaba
			//MODIFICAR
			while (contador==y){
				if (x==1 && r.tipo_sala==1){
					if (w==1 && r.estado==1){
						r.estado=0;
					}
					if (w==0 && r.estado==0){
						r.estado=1;
					}
				}
				if (x==0 && r.tipo_sala==0){
					if (w==1 && r.estado==1){
						r.estado=0;
					}
					if (w==0 && r.estado==0){
						r.estado=1;
					}
				}
				fwrite(&r, tam, 1, c);
				fread (&r, tam, 1, c);
				contador++;
			}
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<<"Proceso terminado, los cambios han sido guardados"<<endl;
			getch();
		}
		fclose (c);
	}
}
void borrar_equipo_medico (){ 
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *e;
	e = fopen ("equipos.dat","r+b");
	if (e == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		equipo_medico r;
		int tam = sizeof (equipo_medico), opcion=0;
		char x[50];
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<< "Ingrese la especialidad medica que desea eliminar: "<<endl;
		SetConsoleTextAttribute(consola, BLANCO); 
		cin>>x; 
		cout<<endl;
		while (feof(e) == 0){
			fread (&r, tam, 1, e);
			if (strcmp(r.especialidad,x)==1){
				//BORRADO
		        do{
		        	SetConsoleTextAttribute(consola, AMARILLO); 
					cout << "Está  seguro de borrarlo (1 = SI/0 = NO)?: "<<endl;
					SetConsoleTextAttribute(consola, BLANCO); 
					cin >> opcion;
					if (opcion!=0 && opcion!=1){
						SetConsoleTextAttribute(consola, ROJO); 
						cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
						opcion=0;
					}
				}while (opcion!=0 && opcion!=1);
		    	if (opcion==1){
		    		r.borrado = 1;          
				    fwrite(&r, tam, 1, e);
					FILE *t;
                    t = fopen ("nuevo.dat" , "wb");
	                if (t == NULL){
	                	SetConsoleTextAttribute(consola, ROJO); 
	                   cout << "\n\nError de Apertura del archivo temporal";
	                   cout << "\nPresione una tecla... ";
		               getch();
	                   fclose(t);
					   exit (1);
	                }else {
		               fread(&r,tam,1,e);
		               while (feof(e) == 0){
		                   if (r.borrado != 1){
					          fwrite (&r, tam, 1, t);           
                	          fread(&r,tam,1,e);
						   }
	                   }
	                   fclose(e);
		               fclose(t);
		               remove("equipos.dat");
		               rename("nuevo.dat", "equipos.dat");
		               SetConsoleTextAttribute(consola, AMARILLO); 
		               cout << "Registro borrado"<<endl;
	                }
				}
				                         
	        }else {
	        	SetConsoleTextAttribute(consola, ROJO); 
				cout<<"No se ha encontrado un registro con el nombre proporcionado"<<endl;
				SetConsoleTextAttribute(consola, BLANCO); 
				cout << "Pulse una tecla"<<endl;
				getch();
			}
		}
	}
}
void modificar_equipo_medico (){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *e;
	e = fopen ("equipos.dat","r+b");
	if (e == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		equipo_medico r;
		int tam = sizeof (equipo_medico);
		char x[50];
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<< "¿Que especialidad desea modificar?"<<endl;
		SetConsoleTextAttribute(consola, BLANCO); 
		cin>>x;
		cout<<endl;
		while (feof(e) == 0){
			fread (&r, tam, 1, e);
			if (strcmp(r.especialidad,x)==1){
				//MODIFICAR
				SetConsoleTextAttribute(consola, AMARILLO); 
			    cout<<"Ingrese los nuevos datos"<<endl;
			    cout<<"Nombre de la especialidad: ";
			    SetConsoleTextAttribute(consola, BLANCO); 
			    cin>>r.especialidad;
			    SetConsoleTextAttribute(consola, AMARILLO); 
			    cout<<"Cantidad de especialistas: ";
			    SetConsoleTextAttribute(consola, BLANCO); 
			    cin>>r.cant_medicos;
			    fwrite(&r, tam, 1, e);
			}
		}
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<"Proceso terminado, los cambios han sido guardados"<<endl;
		getch();
	}
	fclose (e);
}
void borrar_cant_stock (){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *s;
	s = fopen ("stock.dat","r+b");
	if (s == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		cant_stock r;
		int tam = sizeof (cant_stock), x=0, opcion=0;
		cout<<endl;
		SetConsoleTextAttribute(consola, AZULC); 
		cout<<"-----------Tipos de paquetes-----------"<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<"1-Paquetes de materiales de testeo"<<endl;
		cout<<"2-Paquetes de insumos personales del paciente"<<endl;
		cout<<"3-Paquetes de medicamentos para el tratamiento"<<endl;
		cout<<"4-Paquetes de isumos medicos"<<endl;
		cout<<endl;
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<<"¿Que tipo de paquete deseas eliminar?"<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cin>>x;
			if (x<1 || x>4){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
				x=0;
			}
		}while (x<1 || x>4); 
		cout<<endl;
		//BORRADO
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout << "Está  seguro de borrarlo (1 = SI/0 = NO)?: "<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cin >> opcion;
			if (opcion!=0 && opcion!=1){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
				opcion=0;
			}
		}while (opcion!=0 && opcion!=1);
		if (opcion==1){
			while (feof(s) == 0){
				if (r.tipo_paquete==x){
					r.borrado = 1;                                 
			   		fwrite(&r, tam, 1, s);
					FILE *t;
                	t = fopen ("nuevo.dat" , "wb");
	            	if (t == NULL){
	            		SetConsoleTextAttribute(consola, ROJO); 
						cout << "\n\nError de Apertura del archivo temporal";
	                	cout << "\nPresione una tecla... ";
		            	getch();
	                	fclose(t);
		 				exit (1);
	            	}else {
		            	if (r.borrado == 1){
					   		fwrite (&r, tam, 1, t);           
               		   		fread(&r,tam,1,s);
		            	}
		            	fclose(t);
	            	}
				} 
			}
			fclose(s);
		    remove("stock.dat");
		    rename("nuevo.dat", "stock.dat");                       
	    }
	    SetConsoleTextAttribute(consola, AMARILLO); 
		cout << "Registros borrado"<<endl;
		SetConsoleTextAttribute(consola, BLANCO); 
		cout << "Pulse una tecla"<<endl;
		getch();
	}
}
void modificar_cant_stock (){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *s;
	s = fopen ("camas.dat","r+b");
	if (s == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		cant_stock r;
		int tam = sizeof (cant_stock), x=0, opcion=0;
		cout<<endl;
		SetConsoleTextAttribute(consola, AZULC); 
		cout<<"-----------Tipos de paquetes-----------"<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<"1-Paquetes de materiales de testeo"<<endl;
		cout<<"2-Paquetes de insumos personales del paciente"<<endl;
		cout<<"3-Paquetes de medicamentos para el tratamiento"<<endl;
		cout<<"4-Paquetes de isumos medicos"<<endl;
		cout<<endl;
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<<"¿Que tipo de paquete deseas eliminar?"<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cin>>x;
			if (x<1 || x>4){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
				x=0;
			}
		}while (x<1 || x>4); 
		cout<<endl;
		while (feof(s) == 0){
			fread (&r, tam, 1, s);
			if (r.tipo_paquete==x){
				//MODIFICAR
				SetConsoleTextAttribute(consola, AMARILLO); 
				cout<<"Ingrese los nuevos datos"<<endl;
			    cout<<"Tipo de paqueted: ";
			    SetConsoleTextAttribute(consola, BLANCO); 
			    cin>>r.tipo_paquete;
			    SetConsoleTextAttribute(consola, AMARILLO); 
			    cout<<"Cantidad de paquetes en stock: ";
			    SetConsoleTextAttribute(consola, BLANCO); 
			    cin>>r.cantidad_paquete;
				fwrite(&r, tam, 1, s);
			}
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<<"Proceso terminado, los cambios han sido guardados"<<endl;
			getch();
		}
		fclose (s);
	}
}
void borrar_respiradores (){ 
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *l;
	l = fopen ("respiradores.dat","r+b");
	if (l == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		respiradores r;
		int tam = sizeof (respiradores),contador=0, x=0, opcion=0;
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<"¿Cuantas camas deseas eliminar?"<<endl;
		SetConsoleTextAttribute(consola, BLANCO); 
		cin>>x; 
		cout<<endl;
		//BORRADO
		do{
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout << "Está  seguro de borrarlo (1 = SI/0 = NO)?: "<<endl;
			SetConsoleTextAttribute(consola, BLANCO); 
			cin >> opcion;
			if (opcion!=0 && opcion!=1){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
				opcion=0;
			}
		}while (opcion!=0 && opcion!=1);
		if (opcion==1){
			while (contador != x){
		   	   	  fread(&r,tam,1,l);
				  r.borrado = 1;                                 
			      fwrite(&r, tam, 1, l);
				  FILE *t;
                  t = fopen ("nuevo.dat" , "wb");
	              if (t == NULL){
	              	SetConsoleTextAttribute(consola, ROJO); 
	                cout << "\n\nError de Apertura del archivo temporal";
	                cout << "\nPresione una tecla... ";
		            getch();
	                fclose(t);
		 			exit (1);
	              }else {
		            if (r.borrado == 1){
					   fwrite (&r, tam, 1, t);           
               		   fread(&r,tam,1,l);
		            }
		            contador++;
		            fclose(t);
	              }
			} 
			fclose(l);
		    remove("respiradores.dat");
		    rename("nuevo.dat", "respiradores.dat");                       
	    }
	    SetConsoleTextAttribute(consola, AMARILLO); 
		cout << "Registros borrado"<<endl;
		SetConsoleTextAttribute(consola, BLANCO); 
		cout << "Pulse una tecla"<<endl;
		getch();
	}
}
void modificar_respiradores (){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	FILE *l;
	l = fopen ("respiradores.dat","r+b");
	if (l == NULL) {
		SetConsoleTextAttribute(consola, ROJO); 
		cout<< "Error de apertura:";
		cout<< "\nPresione una tecla... ";
		getch();
		exit (1);
	}else{
		respiradores r;
		int tam = sizeof (respiradores), x=0, w=0, contador=0;
		cout<<endl;
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<"¿Cuantos respiradores deseas modificar?"<<endl; 
		SetConsoleTextAttribute(consola, BLANCO); 
		cin>>x;
		do{
			cout<<endl; 
			SetConsoleTextAttribute(consola, AMARILLO); 
			cout<<"¿Desea liberarlas u ocuparlas (1-Liberarlas/ 0-Ocuparlas)?"<<endl;
			SetConsoleTextAttribute(consola, BLANCO);  
			cin>>w;
			if (w>1 || w<0){
				SetConsoleTextAttribute(consola, ROJO); 
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
			}
		}while (w>1 || w<0);
		cout<<endl;
		fread (&r, tam, 1, l);                  //muestra el registro como estaba
		//MODIFICAR
		while (contador!=x){
			if (w==1 && r.estado_r==1){
				r.estado_r=0;
			}
			if (w==0 && r.estado_r==0){
				r.estado_r=1;
			}
			contador++;
		}
		fwrite(&r, tam, 1, l);
		fread (&r, tam, 1, l);
		SetConsoleTextAttribute(consola, AMARILLO); 
		cout<<"Proceso terminado, los cambios han sido guardados"<<endl;
		getch();
		fclose (l);
	}
}
int main(){
	HANDLE consola= GetStdHandle(STD_OUTPUT_HANDLE);  
	pacientes v[100];
	int x=0, ind1=0; 
	int opcion1=0, opcion2=0, opcion3=0, opcion4=0, opcion5=0, opcion6=0; 
	cero(v);
	do{
		system("cls");
		SetConsoleTextAttribute(consola, BLINK);
		cout<<"--------------------MENU PRINCIPAL--------------------"<<endl; 
		SetConsoleTextAttribute(consola, AMARILLO);
		cout<<"1. Carga de archivos"<<endl; 
		cout<<"2. Mostrar lista de pacientes alfabeticamente"<<endl; 
		cout<<"3. Buscar paciente por DNI"<<endl; 
		cout<<"4. Lista de pacientes de riesgo"<<endl; 
		cout<<"5. Camas ocupadas"<<endl; 
		cout<<"6. Pacientes en estado grave"<<endl; 
		cout<<"7. Disponibilidad de respiradores"<<endl; 
		cout<<"8. Modificaciones y borrado"<<endl; 
		cout<<"9. Muetra de archivos"<<endl; 
		cout<<"10. Salir"<<endl;
		cout<<endl;
		do{
			SetConsoleTextAttribute(consola, AMARILLO);
			cout<<"ELIGA LA OPCION QUE DESEE: "; 
			SetConsoleTextAttribute(consola, BLANCO);
			cin>>opcion1;
			if (opcion1>10 || opcion1<1){
				SetConsoleTextAttribute(consola, ROJO);
				cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
			}
		}while (opcion1>10 || opcion1<1);
		cout<<endl;  
		switch(opcion1){
			case 1:
				system("cls"); 
				do{
					SetConsoleTextAttribute(consola, AMARILLO);
					cout<<"1. Cargar paciente"<<endl; 
					cout<<"2. Cargar cama"<<endl; 
					cout<<"3. Cargar equipo medico"<<endl; 
					cout<<"4. Cargar stock"<<endl;
					cout<<"5. Cargar respiradores"<<endl; 
					cout<<"6. Salir"<<endl; 
					cout<<endl; 
					do{
						SetConsoleTextAttribute(consola, AMARILLO);
						cout<<"Eliga la opcion que desee"<<endl; 
						SetConsoleTextAttribute(consola, BLANCO);
						cin>>opcion2;
						if (opcion2>6 || opcion2<1){
							SetConsoleTextAttribute(consola, ROJO);
							cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
							SetConsoleTextAttribute(consola, BLANCO);
						}
					}while (opcion2>6 || opcion2<1);
					cout<<endl;  
					switch(opcion2){
						case 1: 
							altas_pacientes(); 
							break; 
						case 2:
							altas_camas();
							break; 
						case 3: 
							altas_equipo_medico();
							break; 
						case 4:
							altas_stock(); 
							break; 
						case 5: 
							altas_respiradores();
							break; 		
					}				
				}while (opcion2!=6); 
				break; 
			case 2: 
				ordenar(); 	
				break; 
			case 3: 
				SetConsoleTextAttribute(consola, BLINK);
				cout<<"Buscar un paciente con un DNI"<<endl;
				SetConsoleTextAttribute(consola, AMARILLO);
            	cout<<"ingrese el DNI: "<<endl;
            	SetConsoleTextAttribute(consola, BLANCO);
            	cin>>x;
            	ind1 = buscar(x,v);  
				SetConsoleTextAttribute(consola, ROJO); 
				if( ind1 == -1 ) cout << "No se encuentra el DNI.";    
            	else cout << "Si esta en el indice: " << ind1; 
            	cout << endl << endl; 
				break;
				SetConsoleTextAttribute(consola, BLANCO); 
			case 4: 
				pacientes_riesgo(); 
				break; 
			case 5: 
				cant_camas(); 
				porcentaje();
				break; 
			case 6:
				graves();  
				break; 
			case 7: 
				disp_respiradores();
				break; 
			case 8:
				system("cls");
				do{
					SetConsoleTextAttribute(consola, AMARILLO);
					cout<<"Desea borrar o modificar los datos (1 - BORRAR / 0 - MODIFICAR): ";
					SetConsoleTextAttribute(consola, BLANCO);
					cin >>opcion5;
					if (opcion5>1 || opcion5<0){
						SetConsoleTextAttribute(consola, ROJO);
						cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
					}
				}while (opcion5>1 || opcion5<0);
				if (opcion5==0){
					system("cls");
					do{
						SetConsoleTextAttribute(consola, AMARILLO);
					    cout<<"1. Modificar paciente"<<endl; 
				        cout<<"2. Modificar cama"<<endl; 
			        	cout<<"3. Modificar equipo medico"<<endl; 					        
						cout<<"4. Modificar stock"<<endl;
			    	    cout<<"5. Modificar respiradores"<<endl; 
			    	   	cout<<"6. Salir"<<endl;
				       	cout<<endl; 
						do{
							SetConsoleTextAttribute(consola, AMARILLO);
							cout<<"Eliga la opcion que desee"<<endl; 
							SetConsoleTextAttribute(consola, BLANCO);
    			  			cin>>opcion3;
							if (opcion3>6 || opcion3<1){
								SetConsoleTextAttribute(consola, ROJO);
								cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
							}
							SetConsoleTextAttribute(consola, BLANCO);
						}while (opcion3>6 || opcion3<1); 
	    		    	switch(opcion3){
		   	    			case 1: 
		    	    			modificar_pacientes(v); 
			        			break;
				        	case 2:
							    modificar_cama (); 
					   	    	break;
	    	    			case 3:
							    modificar_equipo_medico (); 
		        				break;
		    	    		case 4: 
		    	    			modificar_cant_stock ();
			        			break;
			    	    	case 5:
							    modificar_respiradores (); 
				    	    	break;	 	
	    		    	}
		    	   	}while(opcion3!=6);
				}else{
					system("cls");
					do{
						SetConsoleTextAttribute(consola, AMARILLO);
					    cout<<"1. Borrar paciente"<<endl; 
				        cout<<"2. Borrar cama"<<endl; 
			        	cout<<"3. Borrar equipo medico"<<endl; 
				        cout<<"4. Borrar stock"<<endl;
		    	    	cout<<"5. Borrar respiradores"<<endl; 
		    	    	cout<<"6. Salir"<<endl;
				       	cout<<endl; 
    			   		do{
    			   			SetConsoleTextAttribute(consola, AMARILLO);
							cout<<"Eliga la opcion que desee"<<endl;
							SetConsoleTextAttribute(consola, BLANCO); 
    			  			cin>>opcion6;
							if (opcion6>6 || opcion6<1){
								SetConsoleTextAttribute(consola, ROJO);
								cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
							}
							SetConsoleTextAttribute(consola, BLANCO);
						}while (opcion6>6 || opcion6<1);
	    		    	switch(opcion6){
		   	    			case 1: 
		    	    			borrar_pacientes(v); 
			        			break;
							case 2: 
							    borrar_camas ();
					   	    	break;
	    	    			case 3: 
	    	    			    borrar_equipo_medico ();
		        				break;
		    	    		case 4: 
		    	    			borrar_cant_stock ();
			        			break;
			    	    	case 5:
							    borrar_respiradores (); 	
							   	break;	 	
	    		    	}
		    	   	}while(opcion6!=6);
				}
				break;
			case 9:
				system("cls"); 
				do{
					SetConsoleTextAttribute(consola, AMARILLO);
					cout<<"1. Mostrar paciente"<<endl; 
					cout<<"2. Mostrar cama"<<endl; 
					cout<<"3. Mostrar equipo medico"<<endl; 
					cout<<"4. Mostrar stock"<<endl;
					cout<<"5. Mostrar respiradores"<<endl; 
					cout<<"6. Salir"<<endl; 
					cout<<endl;
					do{
						SetConsoleTextAttribute(consola, AMARILLO);
						cout<<"Eliga la opcion que desee"<<endl; 
						SetConsoleTextAttribute(consola, BLANCO);
    			  		cin>>opcion4;
						if (opcion4>6 || opcion4<1){
							SetConsoleTextAttribute(consola, ROJO);
							cout<<"La opcion ingresada no es valida, intentelo de nuevo"<<endl;
						}
						SetConsoleTextAttribute(consola, BLANCO);
					}while (opcion4>6 || opcion4<1);
					cout<<endl;  
					switch(opcion4){
						case 1: 
							motrar_pacientes(); 
							break; 
						case 2:
							mostrar_camas(); 
							break; 
						case 3: 
							mostrar_equipo_medico();
							break; 
						case 4:
							mostrar_stock(); 
							break; 
						case 5: 
							mostrar_respiradores();
							break; 		
					}				
				}while (opcion4!=6); 
				break; 					
		}
	}while(opcion1!=10);
	SetConsoleTextAttribute(consola, BLANCO);
	return 0; 
}
