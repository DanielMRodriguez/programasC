#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

//estructura principal
typedef struct {
	char 	nombre[10];
	char 	apellido[10];
	char	nombrePersonaje[20];
	float 	vida;
	float 	estamina;
	char  	profesion[10];
} Jugador;

//Constantes del juego
#define VIDA_INICIAL 50.0f
#define ESTAMINA_INICIAL 50.0f
#define ARCH_TXT "jugadores.txt"

// flujos
void inicio(void);
void fin(void);
void pausar(void);
// funciones del juego
int estaVivo(Jugador *j);
int contarVivos(Jugador *jug, int n);
int elegirObjetivo(int idxAtacante, Jugador *jug, int n);
void mostrarEstado(Jugador *jug, int n);
void revisarTurno(int turno);
void atacar(Jugador *atacante, Jugador *defensor);

// Manejo del archivo
void verResultadosAnteriores(void);
void guardarResultadoFinal(Jugador *jugadores, int n);
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
		printf("Selecciona una opcion:\n1) Ver ganadores anteriores\n2) Iniciar nueva partida\n0) Salir\n");
		scanf("%d", &partidaIniciada);
		system("cls");
		//iniciar partida
		if(partidaIniciada==2){
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
				//Profesion
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
				if (estaVivo(&jugadores[turnoActual]) == 0) {
					//pasar al siguiente jugador pero si el jugador siguiente no existe, volver al incio
                    turnoActual = (turnoActual + 1) % cant_jugadores;
					continue; 
                }
                
                pausar();
                printf("\nSi deseas salir de la batalla presiona 9, cualquier otro numero para continuar: ");
                int salirBatalla;
		        if (scanf("%d", &salirBatalla) == 1 && salirBatalla == 9) {
		            printf("Saliendo de la batalla...\n");
		            salir = 1;
		            break;  // rompe el while de la batalla
		        }
		        
                system("cls");
                printf("=== TURNO %d ===\n", turno);
                printf("Estado actual de jugadores:\n");
                mostrarEstado(jugadores, cant_jugadores);

                // Elegir objetivo a atacar en este turno
                int objetivo = elegirObjetivo(turnoActual, jugadores, cant_jugadores);
                if (objetivo != -1) {
                    atacar(&jugadores[turnoActual], &jugadores[objetivo]);
                } else {
                    printf("No hay objetivo disponible.\n");
                }     

                turno++;
    			turnoActual = (turnoActual + 1) % cant_jugadores;
                
			}
			//Guardar la partida
		   	guardarResultadoFinal(jugadores, cant_jugadores);
			
			printf("\nLa batalla termino.\n");
			free(jugadores);
			salir = 1;
		}else if(partidaIniciada == 0){ //salir
			salir = 1;
			printf("De acuerdo, vuelve mas tarde...\n");
		}
		else if(partidaIniciada == 1){ //ver resultados anteriores
			verResultadosAnteriores();
    		salir = 1;
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


void fin(){
	printf("Gracias por participar\n");
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


void pausar(void){
    system("pause");
}

void mostrarEstado(Jugador *jug, int n){
	int d;
    for (d = 0; d < n; d++){
        printf("[%d] %s %s | PJ: %s | Prof: %s | Vida:%.2f | Est:%.2f %s\n",
               d,
               jug[d].nombre,
               jug[d].apellido,
               jug[d].nombrePersonaje,
               jug[d].profesion,
               jug[d].vida,
               jug[d].estamina,
               estaVivo(&jug[d]) ? "" : "(MUERTO)");
    }
}

//elegir el jugadors siguiente que no este muerto y que no sea el jugador actual
int elegirObjetivo(int idxAtacante, Jugador *jug, int n){
	int i;
    for ( i= 0; i < n; i++){
        if (i == idxAtacante) continue;
        if (estaVivo(&jug[i])) return i;
    }
    return -1;
}

// Mecanica de ataque:
// El atacante le reste un valor aleatorio de vida entre el 0 y el 10
// Que al atacante se le reste un valor de estamina aleatorio entre 0 y 5
// Sí el atacante no tiene estanima, no puede atacar ese turno pero recupera un valor de estamina entre 0 y 5

void atacar(Jugador *atacante, Jugador *defensor){
    if (atacante->estamina <= 0.0f) {
        int recupera = rand() % 6; /* 0..5 */
        atacante->estamina += (float)recupera;
        printf("%s No puede atacar por falta de estamina. Estamina ahora: %.2f\n",
               atacante->nombrePersonaje, atacante->estamina);
        return;
    }
    
    // Daño aleatorio 0 a 10 y gasto de estamina 0 a 5
    int dano = rand() % 11;   
    int gasto = rand() % 6;
    
    defensor->vida -= (float)dano;
    if (defensor->vida < 0.0f){
    	defensor->vida = 0.0f;
	}
	
	atacante->estamina -= (float)gasto;
	if (atacante->estamina < 0.0f){
		atacante->estamina = 0.0f;
	}
	
	printf("%s ataca a %s: dano %d, estamina gastada %d.\n",
           atacante->nombrePersonaje, defensor->nombrePersonaje, dano, gasto);
    printf("Vida de %s ahora: %.2f | Estamina de %s: %.2f\n",
           defensor->nombrePersonaje, defensor->vida,
           atacante->nombrePersonaje, atacante->estamina);

    if (!estaVivo(defensor)) {
        printf("%s HA MUERTO!\n", defensor->nombrePersonaje);
    }
}

void verResultadosAnteriores(void){
    FILE *f = fopen(ARCH_TXT, "r");
    system("cls");
    printf("=== Historial de batallas (%s) ===\n\n", ARCH_TXT);

    if (!f){
        printf("No hay historial aun (%s no existe).\n", ARCH_TXT);
        return;
    }

    int c;
    while ((c = fgetc(f)) != EOF){
        putchar(c);
    }
    fclose(f);
}

void guardarResultadoFinal(Jugador *jugadores, int n){
    /* Buscamos al ganador */
    int idxGanador = -1;
    int i;
    for (i = 0; i < n; i++){
        if (jugadores[i].vida > 0){
            idxGanador = i;
        }
    }

    FILE *f = fopen(ARCH_TXT, "a+");
    if (!f){
        printf("No se pudo guardar\n", ARCH_TXT);
        return;
    }
	
    fprintf(f, "=== Resultado ===\n");

    for (i = 0; i < n; i++){
        const char *rol = (i == idxGanador) ? "GANADOR" : "PERDEDOR";
        fprintf(f, "[%s] %s %s | PJ:%s | Prof:%s | Vida:%.2f | Est:%.2f\n",
                rol,
                jugadores[i].nombre,
                jugadores[i].apellido,
                jugadores[i].nombrePersonaje,
                jugadores[i].profesion,
                jugadores[i].vida,
                jugadores[i].estamina);
    }
    fprintf(f, "\n");
    fclose(f);
    printf("\nResultado guardado en %s\n", ARCH_TXT);
}

