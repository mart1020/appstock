

#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

void guardarProductosEnArchivo(int codigos[], char nombres[][MAX_NOMBRE], int stock[], int n) {
    FILE *archivo = fopen("productos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
  
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "Codigo: %d | Nombre: %s | Stock: %d\n", codigos[i], nombres[i], stock[i]);
    }

    fclose(archivo);
    printf("Productos guardados en 'productos.txt'.\n");
}

int main() {
    int codigos[MAX_PRODUCTOS];
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    int stock[MAX_PRODUCTOS];
    int cantidadProductos = 0;
    
    while (1) {
        int codigoProducto;
        
        
        printf("Ingrese el codigo del producto (0 para terminar): ");
        scanf("%d", &codigoProducto);

        // 0, salimos del ciclo
        if (codigoProducto == 0) {
            break;
        }

        // límite de productos
        if (cantidadProductos >= MAX_PRODUCTOS) {
            printf("No se pueden registrar más productos.\n");
            break;
        }

        // Pedimos el nombre del producto
        printf("Ingrese el nombre del producto: ");
        getchar(); 
        fgets(nombres[cantidadProductos], MAX_NOMBRE, stdin);
      
        nombres[cantidadProductos][strcspn(nombres[cantidadProductos], "\n")] = '\0';

       
        printf("Ingrese la cantidad de stock: ");
        scanf("%d", &stock[cantidadProductos]);

       
        codigos[cantidadProductos] = codigoProducto;
        cantidadProductos++;
    }

    
    guardarProductosEnArchivo(codigos, nombres, stock, cantidadProductos);

    return 0;
}
