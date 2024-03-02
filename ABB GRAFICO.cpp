#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>
#include <math.h>


struct Nodo{

	int dato;
	Nodo *der;
	Nodo *izq;
};


Nodo *CrearNodo(int);
int insertar(Nodo *&,int,int,int,int);
void mostrar(Nodo *,int,int,int);
bool busqueda(Nodo *,int);
void menu();

int cardinalidad=0;
Nodo *arbol=NULL;
int raiz;

int main(){

	srand(time(NULL));
	
	initwindow(1200,1000);
	menu();
}


void menu(){
	int dato,opcion=0,cont=0,nivel=0,lado=0;
	int tam;
	char card_cx[100];
	printf("dame la cantidad de elementos a insertar:");
				scanf("%d",&tam);
				printf("\n");		
				do{	
					dato=1+rand()%tam;
					if(busqueda(arbol,dato)==false){				
						raiz=insertar(arbol,dato,nivel,600,75);
						cont++;
					}
				}while(cont!=tam);		
					outtextxy(550,50,"ARBOL ABB");
					outtextxy(650,50,"raiz");
					printf("\n");
					printf("cantidad de elementos: %d\n",cardinalidad);
					
					outtextxy(100,850,"cantidad de elementos:");
					itoa(cardinalidad,card_cx,10);
					outtextxy(275,850,card_cx);
					system("pause");
}

//Crear nuevo nodo

Nodo *CrearNodo(int n){

	Nodo *nuevo_nodo=(struct Nodo*)malloc(sizeof(struct Nodo));
	
	nuevo_nodo->dato=n;
	nuevo_nodo->der=NULL;
	nuevo_nodo->izq=NULL;
	
	return nuevo_nodo;
}

//inserar elementos en arbol
int insertar(Nodo *&arbol,int n,int nivel,int dx,int dy){
char cx[100];
int valorRaiz;
	if(arbol==NULL){
		cardinalidad+=1;
		Nodo *nuevo_nodo=CrearNodo(n);
		arbol=nuevo_nodo;
		setcolor(LIGHTBLUE);
		setfillstyle(1,LIGHTBLUE);
		circle(dx+5,dy+5,15);
		floodfill(dx+5,dy+5,LIGHTBLUE);
		setbkcolor(LIGHTBLUE);
		setcolor(WHITE);
		itoa(arbol->dato,cx,10);
		outtextxy(dx,dy,cx);
		
	}else{
		valorRaiz=arbol->dato;
		if(n<valorRaiz){
			setcolor(YELLOW);
			line(dx,dy,dx-(300/(nivel+1)),dy+50);
			circle(dx+5,dy+5,16);
			insertar(arbol->izq,n,nivel+1,dx-(300/(nivel+1)),(dy+50));
			
		}else{
		
			setcolor(YELLOW);
			line(dx,dy,dx+(300/(nivel+1)),dy+50);
			circle(dx+5,dy+5,16);
			insertar(arbol->der,n,nivel+1,dx+(300/(nivel+1)),(dy+50));
		}
	}

	return valorRaiz;	
}


void mostrar(Nodo *arbol,int nivel,int dx,int dy){
	char cx[100];
	if(arbol==NULL){
		return;
	}else{	
		printf("nivel: %d ",nivel);
		printf("valor: %d ",arbol->dato);
		setcolor(YELLOW);
		if(arbol->izq !=NULL){	
			line(dx,dy,dx-(300/(nivel+1)),dy+50);
		}
		if(arbol->der !=NULL){
			line(dx,dy,dx+(300/(nivel+1)),dy+50);
		}
		setcolor(LIGHTBLUE);
		setfillstyle(1,LIGHTBLUE);
		circle(dx+5,dy+5,15);
		setcolor(WHITE);
		itoa(arbol->dato,cx,10);
		outtextxy(dx,dy,cx);
		printf("dx: %d, dy: %d\n",dx,dy);
		mostrar(arbol->izq,nivel+1,dx-(300/(nivel+1)),(dy+50));
		mostrar(arbol->der,nivel+1,dx+(300/(nivel+1)),(dy+50));
	}
}

bool busqueda(Nodo *arbol,int n){

	if(arbol==NULL){
	
		return false;
		
	}else if(arbol->dato==n){

		return	true;
		
	}else if(n< arbol->dato){
	
		return busqueda(arbol->izq,n);
		
	}else{
	
		return busqueda(arbol->der,n);
	}
	
	
}


