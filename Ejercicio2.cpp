#include <stdio.h>

int main() {
    int NumeroFactura, Localidad, CantidadEntradas, Cedula;
    char Nombre[50];
    double PrecioEntrada, Subtotal, CargosServicios, TotalPagar;
    double AcumuladoLocalidad1 = 0, AcumuladoLocalidad2 = 0, AcumuladoLocalidad3 = 0;
    int ContadorLocalidad1 = 0, ContadorLocalidad2 = 0, ContadorLocalidad3 = 0;
    char Continuar = 's';

    while (Continuar == 's' || Continuar == 'S') {
    	
    	
        printf("\nIngrese el número de factura: ");
        scanf("%d", &NumeroFactura);


        printf("Ingrese la cédula del comprador: ");
        scanf("%d", &Cedula);


        printf("Ingrese el nombre del comprador: ");
        scanf(" %[^\n]", Nombre);

        printf("Seleccione la localidad:\n");
        printf("1: Sol Norte/Sur\n");
        printf("2: Sombra Este/Oeste\n");
        printf("3: Preferencial\n");
        scanf("%d", &Localidad);

        if (Localidad < 1 || Localidad > 3) {
            printf("Digite una localidad válida.\n");
            continue;
        }

        printf("Ingrese la cantidad de entradas (máximo 4): ");
        scanf("%d", &CantidadEntradas);

        if (CantidadEntradas < 1 || CantidadEntradas > 4) {
            printf("Ingrese una cantidad válida.\n");
            continue;
        }

        switch (Localidad) {
            case 1:
                PrecioEntrada = 10500;
                ContadorLocalidad1 += CantidadEntradas;
                AcumuladoLocalidad1 += PrecioEntrada * CantidadEntradas;
                break;
            case 2:
                PrecioEntrada = 20500;
                ContadorLocalidad2 += CantidadEntradas;
                AcumuladoLocalidad2 += PrecioEntrada * CantidadEntradas;
                break;
            case 3:
                PrecioEntrada = 25500;
                ContadorLocalidad3 += CantidadEntradas;
                AcumuladoLocalidad3 += PrecioEntrada * CantidadEntradas;
                break;
        }

        Subtotal = CantidadEntradas * PrecioEntrada;
        CargosServicios = 1000 * CantidadEntradas;
        TotalPagar = Subtotal + CargosServicios;

        printf("\nResultados de la venta:\n");
        printf("Número de factura: %d\n", NumeroFactura);	
        printf("Cédula: %d\n", Cedula);
        printf("Nombre del comprador: %s\n", Nombre);
        printf("Localidad: %d\n", Localidad);
        printf("Cantidad de entradas: %d\n", CantidadEntradas);
        printf("Subtotal: %.2f colones\n", Subtotal);
        printf("Cargos por servicios: %.2f colones\n", CargosServicios);
        printf("Total a pagar: %.2f colones\n", TotalPagar);

        printf("\n¿Desea ingresar otra venta? (s/n): ");
        scanf(" %c", &Continuar);
    }

    printf("\nEstadísticas finales:\n");
    printf("Cantidad de entradas en la localidad Sol Norte/Sur: %d\n", ContadorLocalidad1);
    printf("Acumulado de dinero en la localidad Sol Norte/Sur: %.2f colones\n", AcumuladoLocalidad1);
    printf("Cantidad de entradas en la localidad Sombra Este/Oeste: %d\n", ContadorLocalidad2);
    printf("Acumulado de dinero en la localidad Sombra Este/Oeste: %.2f colones\n", AcumuladoLocalidad2);
    printf("Cantidad de entradas en la localidad preferencial: %d\n", ContadorLocalidad3);
    printf("Acumulado de dinero en la localidad preferencial: %.2f colones\n", AcumuladoLocalidad3);

    return 0;
}


