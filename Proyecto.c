
#include <stdio.h>
#include <stdlib.h>

#define num_pueblos 100
#define num_bebidas 8

void leer_bebidas(int arr[num_pueblos][num_bebidas]) {
    int i, var1, var2;

    // Inicializar matriz de bebidas con 0
    for (i = 0; i < num_pueblos; i++) {
        for (int j = 0; j < num_bebidas; j++) {
            arr[i][j] = 0;
        }
    }
    printf("La matriz se inicializó correctamente.\n");

    // Llenar la matriz con la cantidad de bebidas por pueblo
    for (i = 0; i < num_pueblos; i++) {
        printf("Pueblo %d:\n", i + 1);
        printf("Ingrese el tipo de bebida (0 a 7, -1 para terminar): ");
        scanf("%d", &var1);
        while (var1 != -1) {
            if (var1 < 0 || var1 >= num_bebidas) {
                printf("Tipo de bebida inválido. Intente de nuevo.\n");
            } else {
                printf("Ingrese la cantidad en litros: ");
                scanf("%d", &var2);
                arr[i][var1] = var2;
            }
            printf("Ingrese otra bebida (0 a 7, -1 para terminar): ");
            scanf("%d", &var1);
        }
    }
}

void calcular_total_bebidas(int arr[num_pueblos][num_bebidas], int total[num_bebidas]) {
    int i, j;

    // Inicializar el arreglo de totales con 0
    for (i = 0; i < num_bebidas; i++) {
        total[i] = 0;
    }

    // Calcular el total de cada bebida consumida por todos los pueblos
    for (i = 0; i < num_pueblos; i++) {
        for (j = 0; j < num_bebidas; j++) {
            total[j] += arr[i][j];
        }
    }
}

void bebida_mas_consumida(int total[num_bebidas]) {
    int i, max = 0, bebida;

    // Determinar la bebida más consumida
    for (i = 0; i < num_bebidas; i++) {
        if (total[i] > max) {
            max = total[i];
            bebida = i;
        }
    }

    // Mostrar el resultado
    printf("La bebida más consumida es la bebida %d con %d litros.\n", bebida, max);
}

void bebida_mas_consumida_sin_refresco_y_energeticos(int arr[num_pueblos][num_bebidas], int total2[num_bebidas]) {
    int i, j, acum;

    // Inicializar el arreglo de totales sin refresco ni energéticos
    for (i = 0; i < num_bebidas; i++) {
        total2[i] = 0;
    }

    // Calcular el total de cada bebida sin refresco (1) ni energéticos (6)
    for (i = 0; i < num_bebidas; i++) {
        if (i != 1 && i != 6) {  // Excluir refrescos y energéticos
            acum = 0;
            for (j = 0; j < num_pueblos; j++) {
                acum += arr[j][i];
            }
            total2[i] = acum;
        }
    }
}

void pueblo_que_mas_bebe_alcohol(int arr[num_pueblos][num_bebidas], int total3[num_pueblos]) {
    int i, j, acum2, max3 = 0, pueblo;

    // Inicializar el arreglo de totales por pueblo
    for (i = 0; i < num_pueblos; i++) {
        total3[i] = 0;
    }

    // Calcular el total de alcohol consumido por cada pueblo (sin refresco ni energéticos)
    for (i = 0; i < num_pueblos; i++) {
        acum2 = 0;
        for (j = 0; j < num_bebidas; j++) {
            if (j != 1 && j != 6) {  // Excluir refrescos y energéticos
                acum2 += arr[i][j];
            }
        }
        total3[i] = acum2;
    }

    // Determinar el pueblo que más alcohol consume
    for (i = 0; i < num_pueblos; i++) {
        if (total3[i] > max3) {
            max3 = total3[i];
            pueblo = i;
        }
    }

    // Mostrar el resultado
    printf("El pueblo %d consume más alcohol con %d litros.\n", pueblo, max3);
}

int main() {
    int arr[num_pueblos][num_bebidas];  // Matriz para almacenar el consumo de bebidas por pueblo
    int total[num_bebidas];              // Total de consumo de cada bebida
    int total2[num_bebidas];             // Total de consumo sin refrescos ni energéticos
    int total3[num_pueblos];             // Total de alcohol consumido por cada pueblo

    // Llamar a las funciones
    leer_bebidas(arr);
    printf("\n");

    calcular_total_bebidas(arr, total);
    bebida_mas_consumida(total);
    printf("\n");

    bebida_mas_consumida_sin_refresco_y_energeticos(arr, total2);
    printf("\n");

    pueblo_que_mas_bebe_alcohol(arr, total3);
    
    return 0;
}
