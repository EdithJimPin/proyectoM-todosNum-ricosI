#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void tabula(double a, double b, int intervalos);	// Muestra un # tabulado de intervalos
double f(double x);	// Retorna el valor de la función evaluada en x
double f_derivada(double x); // Retorna la derivada de la función evaluada en x
void newton_raphson(double x0, double tolerancia, int max_interaciones);	// Función que calcula la raiz aproximada de una función
void metodoSecante();

int main (void) {
	int opc;
	do{
	system("cls");
	printf("\t******************Proyecto FInal Equipo 6 **********************\n");
	printf("\tIntegrantes del Equipo: \n");
	printf("\tJimenez Pineda Edith\n");
	printf("\tMarquez Sanchez Arturo Jovani\n");
	printf("\tPineda Rodriguez Alexis Cristian\n\n");
	
	printf("Metodos vistos en clase:\n");
	printf("1. Metodo de Newton\n" );
	printf("2.Metodo de la secante\n");
	printf("3.Metodo de Gauss\n");
	printf("4.Metodo de intercambio\n");
	printf("5.Metodo de Crout\n");
	printf("6.Salir \n");
	printf("Opcion a escoger \n");
	scanf("%d",&opc);
		switch(opc){
			case 1: 
				printf("\tMetodo de Newton ");
					double a;
				double b;
				double tolerancia;	// Tolerancia
				double x0; // Primera aproximación
				
				cout << setprecision(PRECISION);	// Se establece la precisión
				cout << "\nCalculo de las raices de una funcion aplicando el metodo de Newton - Raphson\n";
				cout << "\nIngrese el intervalo inicial [a,b]:" << endl;
				
				// Se ingresa el intervalo
				cout << "\na = ";
				cin >> a;
				
				cout << "b = ";
				cin >> b;
				
				// Se tabulan los valores de f para INTERVALOS intervalos
				tabula(a, b, INTERVALOS);
				
				// Se pide elegir una aproximación inicial
				cout << "\nEscoja el punto inicial adecuado:   x0 = ";
				cin >> x0;
				
				// Se pide ingresar la tolerancia
				cout << "Tolerancia = ";
				cin >> tolerancia;
				
				// Newton Raphson
				newton_raphson(x0, tolerancia, MAX_ITERACIONES);
				
				cin.get();
				cin.get();
				return 0;
				system("pause");
				
				break;
			case 2: 
				system("cls");
				printf("\tMetodo de la secante ");
				metodoSecante();
				system("pause");
				
				break;
			case 3: 
				printf("\tMetodo de Gauss ");
				
				system("pause");
				
				break;
			case 4: 
				printf("\tMetodo de intercambio ");
				
				system("pause");
				
				break;
			case 5: 
				printf("\tMetodo de Crout ");
				
				system("pause");
				
				break;
			case 6:
				break;
			default :
				system("cls");
				printf("La opcion que ingreso es incorrecta");
				getch();
				break;	
		}	
	}while (opc !=6);
	return 0;
}


void metodoSecante(){
	float 	coeficientes[100],
			inicial=0,
			final=0,
			xn = 0,
			xn_1 = 0,
			tol = 0.00001, 
			existeRaiz =0,
			f_xn=0,
			f_xn_1=0,
			restafx=0,
			Xn=0,
			Ea=100,
			restaPuntos=0;
	int 	SI=1, grado=0, max_ite = 0,
			i=0, j=0, n=1;
		
	printf("\n\n¿Grado de su funcion?  \n"); 
	scanf("%i", &grado);
	//j=grado;
	for(i=0; i<=grado; i++){
		printf("Digite el coeficiente de su funcion para el termino de grado %i: " ,i); 
		//j--;
		scanf("%f", &coeficientes[i]);	
		//printf("%f\n",coeficientes[i] );
	}		
	printf("Desea ingresar un rango para saber si tiene raiz? SI[1] NO[2]n \n");
		scanf("%d",&SI);
	if(SI==1){
		printf("Inserte el valor inicial del rango \n");
		scanf("%f", &inicial);
		printf("Inserte el valor final del rango \n");
		scanf("%f", &final);
	
		for(j=inicial; j<=final; j++){
			for(i=0; i<=grado; i++){ //hasta el tamaño del arreglo	
				existeRaiz += coeficientes[i]*pow(inicial,i);
				printf("resultado %f \n",existeRaiz);
				printf("%f\n",coeficientes[i] );	
			}
			if(existeRaiz<0){
				printf("Si existe raiz dentro del rango \n\n" ,xn);	
				break;
			}
			printf("resultado %f \n",existeRaiz);
			inicial++;	
			existeRaiz=0; //hay que ver la forma de sacarlo y hacer el if
		}
	}
	printf("Aproximaciones iniciales \n");
	printf("	x0: ");
	scanf("%f", &xn_1);
	printf("	x1: ");		
	scanf("%f", &xn);
	 
	printf("	Limite de iteraciones: ");
	scanf("%i", &max_ite);
	printf("	Tolerancia(0.0000 %% - 100.0000%%): ");
	scanf("%f", &tol);
	 
	float funcion_xn=0, funcion_xn_1=0;
	
	do{
		for(i=0; i<=grado; i++){ //termina hasta el tamaño del arreglo	
			
			funcion_xn_1 += coeficientes[i]*pow(xn_1,i);
			funcion_xn	+= coeficientes[i]*pow(xn,i);
			//printf("%f",coeficientes[i] );
		}
		printf("puntos pasados %f %f \n" ,xn_1,xn);
		f_xn_1=funcion_xn_1;
		f_xn=funcion_xn;
		if(n==1){
			float esCero = f_xn_1*f_xn;
			printf("Entro al if %f \n" ,esCero);
			if(esCero==0){
				printf("Una raiz de la ecuacion dada es uno de los extremos del intervalo %f \n" ,esCero);
				return;
			}
		}
		printf("f_xn %f %f\n" ,f_xn, f_xn_1);
		if(f_xn==0){
			printf("Una raiz de la ecuacion dada es Xn %f \n" ,xn);
			return;
		}
		if(n>1){
			Ea=fabs((xn-xn_1)/xn)*100;
			printf("El error absoluto es %f \n" ,Ea);
			if(Ea<=tol){
				printf("Una raiz aproximada de la ecuacion dada es %f \n" ,xn);
				return;
			}
		}		
		//printf("resultado %f %f \n" ,f_xn_1 ,f_xn);//esta ok
		restafx=f_xn-f_xn_1;
		Xn = xn-(f_xn*(xn-xn_1)/restafx);
		xn_1 = xn;
		xn = Xn;
		printf("Xn %f \n" ,Xn);
		printf("puntoss actuales %f %f \n" ,xn_1,xn);
		funcion_xn_1=0;
		funcion_xn=0;
		n++;
	}while(n<=max_ite);
	printf("El metodo no converge a una raiz");
};

void tabula(double a, double b, int intervalos)
{
	int puntos = intervalos + 1;
	
	double ancho = (b - a) / intervalos;
	
	cout << "\n\tx\t\tf(x) " << endl;
	for (int i = 0; i < puntos; i++) {
		cout << "\t" << a << "\t\t" << f(a) << endl;
		a = a + ancho;
	}
}


double f(double x)
{
	return cos(x);
	//return exp(-x) + 3 * x - 3;
}


double f_derivada(double x)
{
	return -sin(x);
	//return -1 * exp(-x) + 3;
}


void newton_raphson(double x0, double tolerancia, int max_iteraciones)
{
	double x1; // Siguiente aproximación
	double error;	// Diferencia entre dos aproximaciones sucesivas: x1 - x0
	int iteracion; // # de iteraciones
	bool converge = true;
	
	// Se imprimen los valores de la primera aproximación
	cout << "\nAproximacion inicial:\n";
	cout << "x0 = " << x0 << "\n"
		<< "f(x0) = " << f(x0) << "\n"
		<< "f'(x0) = " << f_derivada(x0) << endl;
	
	iteracion = 1;
	do {
	
		if (iteracion > max_iteraciones) {
			converge = false;	// Se sobrepasó la máxima cantidad de iteraciones permitidas
			break;
		
		} else {
			x1 = x0 - f(x0) / f_derivada(x0); // Cálculo de la siguiente aproximación
			error = fabs(x1 - x0);	// El error es la diferencia entre dos aproximaciones sucesivas
			
			// Se imprimen los valores de la siguiente aproximación x1, f(x1), f_derivada(x1), error
			cout << "\a";
			Sleep(500);
			cout << "\n\nIteracion #" << iteracion << endl;
			cout << "\nx" << iteracion << "     = " << x1 << "\n"
				<< "f(x" << iteracion << ")  = " << f(x1) << "\n"
				<< "f'(x" << iteracion << ") = " << f_derivada(x1) << "\n"
				<< "error  = " << error << endl;
			
			// La diferencia entre dos aproximaciones sucesivas es también conocida como error.
			// La condición de terminación consiste en que que el error debe ser <= que la tolerancia dada
			// Si se cumple la condición de terminación, se ha encontrado la raiz aproximada buscada.
			if (error <= tolerancia) { // Condición de terminación
				converge = true;
				break;
			
			// Si no se cumple el criterio de terminación, se pasa a la siguiente iteración
			} else {
				x0 = x1;
				iteracion++;
			}
		}
	
	} while (1);
	
	// Respuesta final
	cout << "\a";
	Sleep(500);
	if (converge) {
		cout << "\n\nPara una tolerancia de " << tolerancia << " la RAIZ APROXIMADA de f es = " << x1 << endl;
	
	} else {
		cout << "\n\nSe sobrepasó la máxima cantidad de iteraciones permitidas" << endl;
	}
}
