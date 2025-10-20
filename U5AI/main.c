#include <stdio.h>
#include <stdlib.h>

int main(){
	//solicitar una longitud din�mica al usuario
	printf("Cuantos elementos quieres almacenar?\n");
	int longitud;
	scanf("%d", &longitud);
	
	//asingar la memoria dinamica, en este caso un array de flotantes del tama�o que el usuario solicito
	float*  valores = (float*) malloc(longitud * sizeof(float));
	//validaci�n para ver si malloc devolvio algo valida
	if(valores == NULL){
		printf("No tienes suficiente memoria\n");
		return 1;
	}
	
	//probar la nueva longitud del m�xcio
	int i;
	for (i=0; i < longitud; i++){
		valores[i] = 5.55E5;
	}
	
	printf("Todo esta correcto\n");
	//limpiar memoria
	free(valores);
	return 0;
}
