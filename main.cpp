#include <Arduino.h>

// Función que suma los elementos de un arreglo sin punteros
int sumaArregloSinPunteros(int arr[], int size) {
  int suma = 0;
  for (int i = 0; i < size; i++) {
    suma += arr[i];
  }
  return suma;
}
// Función que suma los elementos de un arreglo utilizando un puntero
int sumaArreglo(int *arr, int size) {
  int suma = 0;
  for (int i = 0; i < size; i++) {
    suma += *arr; // Accede al valor apuntado por el puntero arr
    arr++; // Avanza el puntero al siguiente elemento del arreglo
  }
  return suma;
}

void setup() {
  Serial.begin(9600);

  int numeros[1000]; // Arreglo de 100 números

  // Llenar el arreglo con datos
  for (int i = 0; i < 1000; i++) {
    numeros[i] = i + 1;
  }

  unsigned long startTime;
  unsigned long endTime;

  // Medir el tiempo de ejecución de la función con punteros
  startTime = millis();
  int resultado1 = sumaArreglo(numeros, sizeof(numeros) / sizeof(numeros[0]));
  endTime = millis();

  Serial.print("Tiempo de ejecución de sumaArreglo con punteros: ");
  Serial.print(endTime - startTime);
  Serial.println(" ms");

  // Medir el tiempo de ejecución de la función sin punteros
  startTime = millis();
  int resultado2 = sumaArregloSinPunteros(numeros, sizeof(numeros) / sizeof(numeros[0]));
  endTime = millis();

  Serial.print("Tiempo de ejecución de sumaArregloSinPunteros: ");
  Serial.print(endTime - startTime);
  Serial.println(" ms");

  // Imprimir los resultados
  Serial.print("La suma de los elementos del arreglo con punteros es: ");
  Serial.println(resultado1);
  Serial.print("La suma de los elementos del arreglo sin punteros es: ");
  Serial.println(resultado2);
}

void loop() {
  // El bucle loop() no hace nada en este ejemplo
}