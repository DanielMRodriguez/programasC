#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 
//Definir funciones void
void fisica(int subAcc, float distancia, float tiempo, float velocidad);
void matematicas(int subAcc, float num1, float num2, int potencia);
void geometria(int subAcc, float base, float radio, float altura, float lado, float generatriz, float area);
void mainMenu();

const float PI = 3.1415f;

int main(){

	int Acc,subAcc,potencia;
	float distancia,altura,base,lado,radio,velocidad,tiempo,area,generatriz,num1,num2;
	
	mainMenu();
  	scanf("%d", &Acc);
	system("cls");
	while(Acc != 0){
		if(Acc == 0){
			break;
		}
		
		switch ( Acc ){
		   	case 1:
		   		fisica(subAcc, distancia,tiempo,velocidad);
		   		break;
		   	case 2:
		   		geometria(subAcc,base,radio,altura,lado,generatriz,area);
		   		break;
		   	case 3:
		   		matematicas(subAcc,num1,num2,potencia);
		   		break;
		    default:
			 	printf("Entrada no valida, volver a introducir \n");
				break;
		}
		mainMenu();
  		scanf("%i", &Acc);
  		sleep(1);
  		system("cls");
	}
	
	printf("Gracias por utilizar el sistema");
	return 0;
}


void mainMenu(){
	printf("Bienvenido a el sistema para hacer calculos matematicos :), introduce la opcion que necesitas: \n");
	printf("1 | Calculos de Fisica \n");
	printf("2 | Calculos de Geometria \n");
	printf("3 | Calculos de Matematicas \n");	
	printf("0 | Si deseas salir \n");
}

void fisica(int subAcc, float distancia, float tiempo, float velocidad){
	
	printf("Excelente, haremos calculos de fisica, el tema es movimiento rectilinea uniforme, elige algunos de los procesos disponibles \n");
	printf("1 | Calculo de Velocidad \n");
	printf("2 | Calculo de Distancia \n");
	printf("3 | Calculo de Tiempo \n");	
	printf("0 | Si deseas salir \n");

	scanf("%i", &subAcc);
	system("cls");
	if(subAcc == 0){
		return;
	}
	switch ( subAcc ){
		case 1:
			printf("Elegiste Calculo de velocidad \n");
			sleep(1);
			system("cls");
			printf("Ingresa la distancia recorrida en km \n");
			scanf("%f", &distancia);
			system("cls");
			printf("Ahora ingresa el tiempo transcurrido en horas \n");
			scanf("%f", &tiempo);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			velocidad = distancia/tiempo;
			printf("La furmular para hacer esta operación es: \n Velocidad = Distancia / tiempo \n Velocidad = %.2f km/h \n\n", velocidad);
			sleep(1);
			break;
		case 2:
			printf("Elegiste Calculo de Distancia recorrida \n");
			sleep(1);
			system("cls");
			printf("Ingresa la velocidad a la que se mueve en km/h \n");
			scanf("%f", &velocidad);
			system("cls");
			printf("Ahora ingresa el tiempo transcurrido en horas \n");
			scanf("%f", &tiempo);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			distancia = velocidad * tiempo;
			printf("La formula para obtener la distancia recorrida a determinada velocidad es: \n Distancia = Velocidad x Tiempo \n Distancia = %.2f km \n\n", distancia);
			sleep(1);
			break;
		case 3:
			printf("Elegiste Calculo del tiempo transcurrido Tiempo \n");
			sleep(1);
			system("cls");
			printf("Ingresa la velocidad a la que se mueve en km/h \n");
			scanf("%f", &velocidad);
			system("cls");
			printf("Ahora ingresa la distancia en km \n");
			scanf("%f", &distancia);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			tiempo = distancia/velocidad;
			printf("La formula para obtener el tiempo transcurrido a determinada es: \n Tiempo = Distancia / Velocidad \n Tiempo = %.2f horas \n\n", tiempo);
			sleep(1);
			break;
		default:
			printf("Entrada no valida, volver a introducir \n");
			break;
	}
}


void geometria (int subAcc, float base, float radio, float altura, float lado, float generatriz, float area){
	printf("Excelente, haremos calculos de Geografia, podemos calcular el area de distintas figuras, elige una de las siguientes opciones \n");
	printf("1 | Circulo \n");
	printf("2 | Cono \n");
	printf("3 | Cubo \n");	
	printf("0 | Si deseas salir \n");

	scanf("%i", &subAcc);
	system("cls");
	if(subAcc == 0){
		return;
	} 
	
	switch ( subAcc ){
		case 1:
			printf("Elegiste el Circulo, para calcular el area necesitamos los siguientes datos... \n");
			sleep(1.5);
			system("cls");
			printf("Ingresa el Radio del circulo en cm");
			scanf("%f", &radio);
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			area = PI * pow(radio,2);
			printf("La formula para obtener el area del circulo es: \n Area = PI * r^2 \n Area = %.2f cm^2 \n\n", area);
			sleep(1);
			break;
		case 2:
			printf("Elegiste el Cono, para calcular el area necesitamos los siguientes datos... \n");
			sleep(1.5);
			system("cls");
			printf("Ingresa el Radio (r) del circulo de la base en cm \n");
			scanf("%f", &radio);
			system("cls");
			printf("Ahora ingresa la generatriz (g) del cono en cm \n");
			scanf("%f", &generatriz);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			area = PI * pow(radio,2);
			float areaLateral;
			areaLateral = PI * radio * generatriz;
			area = area + areaLateral;
			printf("La formula para obtener el area del cono es: \n Area total =(PI * r * g) + (PI * r^2) \n Area = %.2f cm^2 \n\n", area);
			sleep(1);
			break;
		case 3:
			printf("Elegiste el Cubo, para calcular el área necesitamos los siguientes datos... \n");
			sleep(1.5);
			system("cls");
			printf("Ingresa el valor de un lado del cubo en cm \n");
			scanf("%f", &lado);
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			area = 6 * pow(lado,2);
			printf("La formula para obtener el area de un cubo es: \n Area = 6 * Lado^2 \n Area = %.2f cm^2 \n\n", area);
			sleep(1);
			break;
		default:
			printf("Entrada no valida, volver a introducir \n");
			break;
	}
}

void matematicas(int subAcc, float num1, float num2, int potencia){
	printf("Excelente, haremos calculos de Matematicas, elige una de las siguientes opciones \n");
	printf("1 | Suma \n");
	printf("2 | Residuo \n");
	printf("3 | Numero aleatorio \n");
	printf("4 | Potencia \n");
	printf("0 | Si deseas salir \n");

	scanf("%i", &subAcc);
	system("cls");
	if(subAcc == 0){
		return;
	}
	switch ( subAcc ){
		case 1:
			printf("Elegiste Suma, para hacer una suma necesitaremos 2 numeros: \n");
			sleep(1.5);
			system("cls");
			printf("Ingresa el primer numero \n");
			scanf("%f", &num1);
			printf("Ingresa el segundo numero \n");
			scanf("%f", &num2);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			float suma = num1 + num2;
			printf("El resultado de la suma es: %.2f + %.2f = %.2f \n\n", num1,num2,suma);
			sleep(1);
			break;
		case 2:
			printf("Elegiste Residuo, para hacer una resta necesitaremos 2 numeros: \n");
			sleep(1.5);
			system("cls");
			printf("Ingresa el primer numero \n");
			scanf("%f", &num1);
			printf("Ingresa el segundo numero \n");
			scanf("%f", &num2);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			float resta;
			resta = num1 - num2;
			printf("El resultado de la suma es: %.2f - %.2f = %.2f \n\n", num1,num2,suma);
			sleep(1);
			break;
		case 3:
			printf("¿Quieres un numero aleatorio? \n");
			sleep(1.5);
			system("cls");
			int i;
			char dots[6];
			for(i=0;i<6;i++){
				dots[i] = '.';
				dots[i+1] = '\0'; 
				printf("Muy bien, dejame pensar %s   \n", dots);
				sleep(1);
				system("cls");
			}
			srand(time(NULL));
			num1 = rand();
			printf("ESte es tu numero, disfrutalo: %0.f \n\n",num1);			
			sleep(1);
			break;
		case 4:
			printf("Elegiste potencia, para hacer una potencia necesitaremos la base y la potencia: \n");
			sleep(1);
			printf("Ingresa la base: \n");
			scanf("%f", &num1);
			system("cls");
			printf("Ingresa la potencia: \n");
			scanf("%f", &potencia);
			system("cls");
			printf("Calculando... \n");
			sleep(1);
			system("cls");
			float resultado;
			resultado = pow(num1,potencia);
			printf("El resultado es %2.f = %2.f^%d ",resultado,num1,potencia);
			break;

		default:
			printf("Entrada no valida, volver a introducir \n");
			break;
	}
}

