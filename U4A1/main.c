#include <stdio.h>
#include <time.h> 
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//Constantes
const int DIAS = 10;
const float TASA_IVA = .16f;
const float TASA_IMPUESTOS = .12f;
const float PPN_SENCILLA = 599.00f;
const float PPN_DOBLE = 850.00f;
const float PPN_SUITE = 1059.00f;
//estructuras
typedef struct {
	char cliente[50];
	int noches;
	char tipoHabitacion[20];
	float subtotal;
	float total;
} Reservacion;
//Variables
int DIA_ACTUAL;
int cap_resevas = 50;
int num_reservas = 0;

//acumuladores
float TOTAL_IMPUESTOS;
float TOTAL_IVA;
float TOTAL_SUBTOTAL;
float TOTAL;

//funciones a utilizar
float calcular_subtotal(float precioPorNoche, int noches);
float calcular_total(float subtotal);
void confirmarReservacion(Reservacion r);

int main (){
	//inicia estrcutura para guardar las reservaciones;
	Reservacion reservaciones[50];
	
	srand(time(NULL));
	//Inicia simulación de los 30 dias
	for(DIA_ACTUAL = 1; DIA_ACTUAL <= DIAS; DIA_ACTUAL++){
		bool sigDia = false;
		int menu;
		//Inicia simulación del día actual
		while(!sigDia){
			printf("Buen dia, este es el dia %d del mes\n", DIA_ACTUAL);
			printf("Menu: Elgie alguna accion:\n");
			printf("1 | Hacer una reservacion\n2 | Pasar al siguiente dia\n");
			scanf("%d", &menu);
			if(menu == 1){
				
			    if (num_reservas >= cap_resevas) {
			        printf("No hay espacio para mas reservaciones (capacidad %d).\n", cap_resevas);
			        system("cls");
			        continue;
			    }
			    //variables temporales para guardar las entradas del usuarios
			    char tmpCliente[50];
				int  tmpNoches = 0;
				char tmpTipoHabitacion[20];
				int  opcionHabitacion = 0;
				float tmpPrecioPorNoche = 0.0f;
				float tmpSubtotal = 0.00f;
				float tmpTotal = 0.00f;
				
				system("cls");
				printf("Necesitas los siguientes datos para llenar la reservacion:\n- Nombre del cliente\n- Cantidad de noches:\n- Tipo de habitacion, vamos 1 por 1:\n");
				printf("Cual es el nombre del cliente?\n");
    			scanf(" %49[^\n]", tmpCliente);
    			
    			printf("Cuantas noches se quedara?\n");
    			scanf("%d", &tmpNoches);
    			printf("Que tipo de habitación quiere?\n");
        		printf("1 | Sencilla\n");
    			printf("2 | Doble\n");
        		printf("3 | Suite\n");
				scanf("%d", &opcionHabitacion);
				
				switch (opcionHabitacion) {
					case 1: 
						strcpy(tmpTipoHabitacion, "Sencilla");
						tmpPrecioPorNoche = PPN_SENCILLA;
						break;
					case 2:
						strcpy(tmpTipoHabitacion, "Doble");
						tmpPrecioPorNoche = PPN_DOBLE;
						break;
					case 3:
						strcpy(tmpTipoHabitacion, "Suite");
						tmpPrecioPorNoche = PPN_SUITE;
						break;
				}
				
				tmpSubtotal = calcular_subtotal(tmpPrecioPorNoche, tmpNoches);
    			tmpTotal = calcular_total(tmpSubtotal);
    			// Crear reservacion
    			Reservacion nueva = {0};
    			strcpy(nueva.cliente, tmpCliente);
    			nueva.noches = tmpNoches;
    			strcpy(nueva.tipoHabitacion, tmpTipoHabitacion);
    			nueva.subtotal = tmpSubtotal;
    			nueva.total = tmpTotal;

    			reservaciones[num_reservas++] = nueva;
    			confirmarReservacion(nueva);
    			
				system("cls");			
			}else{
				sigDia = true;
			}
		}
		system("cls");	
	}	
	
	printf("Total de datos financieros del mes:\n");
	printf("Subtotal: $ %.2f \n",TOTAL_SUBTOTAL);
	printf("Total: $ %.2f \n",TOTAL);
	return 0;
}


//implementación de las funciones
float calcular_subtotal(float precioPorNoche, int noches){
	
	return precioPorNoche * noches;
}

float calcular_total(float subtotal){
	float impuestos = subtotal * TASA_IMPUESTOS;
	float iva = subtotal * TASA_IVA;
	TOTAL_IVA = TOTAL_IVA + iva;
	TOTAL_SUBTOTAL = TOTAL_SUBTOTAL + subtotal;
	TOTAL_IMPUESTOS = TOTAL_IMPUESTOS + impuestos;
	TOTAL = impuestos + iva + subtotal + TOTAL;
	return subtotal + impuestos + iva;
}

void confirmarReservacion(Reservacion r){
	printf("\nReserva creada:\n");
    printf("Cliente:    %s\n", r.cliente);
    printf("Habitación: %s\n", r.tipoHabitacion);
    printf("Noches:     %d\n", r.noches);
    printf("Subtotal:   $ %.2f\n", r.subtotal);
    printf("Total:      $ %.2f\n\n", r.total);
}

