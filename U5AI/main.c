#include <stdio.h>
#include <stdlib.h>

int main(){
	//solicitar una longitud dinámica al usuario
	printf("Cuantos elementos quieres almacenar?\n");
	int longitud;
	scanf("%d", &longitud);
	
	//asingar la memoria dinamica, en este caso un array de flotantes del tamaño que el usuario solicito
	float*  valores = (float*) malloc(longitud * sizeof(float));
	//validación para ver si malloc devolvio algo valida
	if(valores == NULL){
		printf("No tienes suficiente memoria\n");
		return 1;
	}
	
	//probar la nueva longitud del méxcio
	int i;
	for (i=0; i < longitud; i++){
		valores[i] = 5.55E5;
	}
	
	printf("Todo esta correcto\n");
	//limpiar memoria
	free(valores);
	return 0;
}
