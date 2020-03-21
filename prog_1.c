#include<iostream>
#include<conio.h>
#include<stdlib.h>
 
using namespace std;
 
 struct Nodo{
 	int dato;
 	Nodo *siguiente;
 	
 };
 void menu();
 void insertarLista(Nodo *&,int);
 void mostrarLista(Nodo*);
 void eliminarNodo(Nodo *&,int);
 void eliminarLista(Nodo *&,int &);	
 
 Nodo *lista = NULL;
 
 int main (){
 
 	menu();
 	
 	getch();
 	return 0;
 }
 
void menu(){
 	int opcion, dato, t, i;
 	
 	do{
 		cout<< "::MENU:: "<<endl;
 		cout<<"1. Insertar archivo"<<endl;
 		cout<<"2. Mostrar archivo"<<endl;
 		cout<<"3. Borrar archivo"<<endl;
 		cout<<"4. Eliminar todo"<<endl;
 		cout<<"5. SALIR "<<endl;
 		cout<<"Selecciona una opcion "<<endl;
 		cin>>opcion;
 		
 		switch(opcion){
 			
 			case 1:
		 	cout<<"Ingresa el tamano del archivo"<<endl;
    		cin>>t;
   			for (i=0; i<t; i++){		
			cout<<"Digite el los bloques "<<endl;
 			cin>>dato;
 			insertarLista(lista,dato);
 			system("pause");
			}
 			break;
 			
 			case 2: 
 			 	mostrarLista(lista);
 			system("pause");
 			break;
			
			case 3: 
			cout<<"Digita la el archivo que deseas eliminar"<<endl;
			cin>>dato;
			eliminarNodo(lista,dato);
			cout<<"Archivo "<<dato<<" eliminado"<<endl;
			system("pause");
			break;
			
			case 4:
			while(lista != NULL){
				eliminarLista(lista,dato);
				cout<<dato<<"->";
			}
			system("pause");
			break;
		 }
		 system("cls");
	 }
	 while(opcion != 5);
}
 
 void insertarLista(Nodo *&lista, int n){
 	Nodo *nuevo_nodo = new Nodo();
 	nuevo_nodo->dato = n;  
 	
 	Nodo *aux1=lista;
 	Nodo *aux2;
 	
 	while((aux1 != NULL) && (aux1->dato < n)){
 		aux2 = aux1;
 		aux1 = aux1->siguiente;
	 }
	
	if(lista == aux1){
		lista=nuevo_nodo;
	}
	
	else{
		aux2->siguiente = nuevo_nodo;
	}
	
	nuevo_nodo->siguiente = aux1;
	
	cout<<"Elemento "<<n<<" ha sido almacenado correctamnete "<<endl;
 }
 
 void mostrarLista(Nodo *lista){
 	if(lista != NULL){
 	Nodo *actual = new Nodo();
 	actual = lista;
	 
 	while(actual != NULL){
 		cout<<actual->dato<<" -> ";
 		actual = actual->siguiente;
		}
	}
	
	else{
		cout<<"No hay ninguna archivo"<<endl;
	}
}

void eliminarNodo(Nodo *&lista, int n){
	Nodo *aux_borrar;
	Nodo *anterior = NULL;
	
	aux_borrar = lista;
	
	while((aux_borrar != NULL) && (aux_borrar->dato != n)){
		anterior = aux_borrar;
		aux_borrar = aux_borrar->siguiente;
	}
	
	if(aux_borrar == NULL){
		cout<<"No se encontro el bloque"<<endl;
	}
	
	else if(anterior == NULL){
		lista = lista->siguiente;
		delete aux_borrar;
	}
	else{
		anterior->siguiente = aux_borrar->siguiente;
		delete aux_borrar;
	}
}

void eliminarLista(Nodo *&lista, int &n){
	Nodo *aux = lista;
	n = aux->dato;
	lista = aux->siguiente;
	delete aux;
	
}
