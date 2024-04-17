#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct{
    int ProductoID; // Numerado en ciclo interactivo
    int Cantidad; // Entre 1 y 10
    char *TipoProducto; // Algun valor del arreglo TiposProductos
    float PrecioUnitario; // Entre 10 y 100
}Producto;

typedef struct{
    int ClienteID; // Numerado en ciclo interactivo
    char *NombreCliente; // Ingresado por el usuario
    int CantidadProductosAPedir; //  En numero entre 1 y 5
    Producto *productos; // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
}Cliente;               // (O sea el dinamico)

float precioUnitario(Producto producto);

int main(){
    char nombreAux[50];
    int CantClientes = 0;
    Cliente *pClientes;
    srand(time(NULL));
    float totalP;

    do{
        printf("\nIngresar la cantidad de clientes (no pueden ser mas de 5)\n");
        scanf("%d", &CantClientes);
    }while(CantClientes > 5);    //en este ciclo filtro que siempre sea mayor a 5

    pClientes = (Cliente *) malloc (sizeof(Cliente) * CantClientes);  //Asigno memoria dinamica a mi vble pClientes que son la cantidad de clientes a ingresar
    

    for (int i = 0; i < CantClientes; i++)
    {
        pClientes[i].ClienteID = (i + 1);
        printf("\nIngresar el nombre del cliente\n");
        fflush(stdin);
        gets(nombreAux);
        pClientes[i].NombreCliente = (char *) malloc (sizeof(char) * (strlen(nombreAux) + 1));
        strcpy(pClientes[i].NombreCliente, nombreAux);
        pClientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        pClientes[i].productos = (Producto *) malloc (sizeof(Producto) * pClientes[i].CantidadProductosAPedir);
        for (int j = 0; j < pClientes[i].CantidadProductosAPedir; j++)
        {
            pClientes[i].productos[j].ProductoID = (j + 1);
            pClientes[i].productos[j].Cantidad = 1 + rand() % 10;
            pClientes[i].productos[j].TipoProducto = TiposProductos[(rand() % 4)];
            pClientes[i].productos[j].PrecioUnitario = (1000 + rand() % 9001)/100;
            totalP += precioUnitario(pClientes[i].productos[j]);
        }
    }

    // muestro en pantalla
    for (int i = 0; i < CantClientes; i++)
    {
        printf("\nEl ID del cliente es: %d \n", pClientes[i].ClienteID);
        printf("\nNombre del cliente: ");
        puts(pClientes[i].NombreCliente);
        printf("\nCantidad de productos a pedir: %d \n", pClientes[i].CantidadProductosAPedir);
        for (int j = 0; j < pClientes[i].CantidadProductosAPedir; j++)
        {
            printf("\nEl ID del producto es: %d \n", pClientes[i].productos[j].ProductoID);
            printf("\nCantidad de productos: %d \n", pClientes[i].productos[j].Cantidad);
            printf("\nNombre del producto: ");
            puts(pClientes[i].productos[j].TipoProducto);
            printf("\nPrecio unitario del producto: %.2f \n", pClientes[i].productos[j].PrecioUnitario);
        }
        
    }
    printf("\nEl costo total de todos los productos es: %.2f \n ", totalP);

    free(pClientes);

    return 0 ;
}


float precioUnitario(Producto producto){

    float total = (producto.Cantidad) * (producto.PrecioUnitario);

    return total;
}

