#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<windows.h>
#include <string.h>

//estructura
typedef struct {
	char 	nombre[10];
	char 	apellido[10];
	char	nombrePersonaje[20];
	float 	vida;
	float 	estamina;
	char  	profesion[10];
} Jugador;

#define VIDA_INICIAL 50.0f
#define ESTAMINA_INICIAL 50.0f

//funciones

//void atacar(Jugador, Jugador);
//void guardarPartida(void);
//void revisarTurno(void);
//void inicio(void);
//void fin(void);

void atacar(Jugador *atacante, Jugador *defensor);
void guardarPartida(void);
void revisarTurno(int turno);
void inicio(void);
void fin(void);
int contarVivos(Jugador *jug, int n);
int buscarGanador(Jugador jugadores, int n);
int estaVivo(Jugador *j);

//Main
int main(){
	//datos iniciales, cargar base de datos archivo de texto
	// inicializar srand para hacer numeros random más adelante
	FILE *db;
	int salir = 0;
	int partidaIniciada = 0;
	int turno = 0;
	int cant_jugadores;
	srand(time(NULL));
	inicio();
	do{
		printf("Deseas inicar una nueva partida\nTeclea la opcion que prefieras:\nSi = 1\nNo = 0\n");
		scanf("%d", &partidaIniciada);
		system("cls");
		//iniciar partida
		if(partidaIniciada==1){
			// Preguntar cuantos jugadores habrá para registrar los usuarios de forma dinamica, según cuantos sean.
			printf("Excelente, comencemos\nCuantos jugadores seran?\n");
			scanf("%i",&cant_jugadores);
			Jugador* jugadores = (Jugador*) malloc((size_t)cant_jugadores * sizeof(Jugador));
			
			//registro de jugadores
			printf("Vamos a registrar a los jugadores uno por uno, iniciando por el jugador 1, luego el 2 y así sucesivamente\n");
			system("cls");
			int i;
			for(i = 0; i < cant_jugadores; i++){
				char temp_nombre[10];
				char temp_apellido[10];
				char temp_nombrePersonaje[20];
				printf("Dame el nombre del Jugador %d\n",i);
				scanf("%s", temp_nombre);
				//apellido
				printf("Dame el apellido del Jugador %d\n",i);
				scanf("%s", temp_apellido);
				//nombrePersonaje
				printf("Dame el nombre del personaje del Jugador %d\n",i);
				scanf("%s", temp_nombrePersonaje);
				system("cls");
				strcpy(jugadores[i].nombre,temp_nombre);
				strcpy(jugadores[i].apellido,temp_apellido);
				strcpy(jugadores[i].nombrePersonaje,temp_nombrePersonaje);
				strcpy(jugadores[i].profesion, "Guerrero");
				jugadores[i].vida = VIDA_INICIAL;
                jugadores[i].estamina = ESTAMINA_INICIAL;
			}
			
			printf("Estamos listos para inciciar la batalla\n");
			//Jugador con el turno actual
			int turnoActual = 0;
			int turno = 1;
			// hacer logíca de los turnos
			while (contarVivos(jugadores, cant_jugadores) > 1) {
				//saltar jugadores muertos
				if (estaVivo(&jugadores[turnoActual]) == 1) {
					//pasar al siguiente jugador pero si el jugador siguiente no existe, volver al incio
                   turnoActual = (turnoActual + 1) % cant_jugadores;
					continue; 
                }
                
                system("cls");
                printf("=== TURNO %d ===\n", turno);
                printf("Estado actual de jugadores:\n");
                
                turno++;
    			turnoActual = (turnoActual + 1) % cant_jugadores;
                
			}
			
			
			printf("\nLa batalla termino.\n");
			free(jugadores);
			salir = 1;
		}else if(partidaIniciada == 0){ //salir
			salir = 1;
			printf("De acuerdo, vuelve mas tarde...\n");
		}else{ //volver a pedir entrada
			printf("Entrada no valida, por favor vuelve a intentarlo");
		}
		
		
	} while(salir == 0);
	fin();
	return 0;
}


void inicio(){
	printf("Bienvenido al Battle World \n");
}

int estaVivo(Jugador *j){
    if(j->vida > 0.0f){
    	return 1;
	}else{
		return 0;
	}
}

int contarVivos(Jugador *jug, int n){
    int vivos = 0;
    int i;
    for ( i = 0; i < n; i++){
        if (estaVivo(&jug[i]) == 1){
        	vivos++;
		} 
    }
    return vivos;
}

void fin(){
	printf("Gracias por participar\n");
}
