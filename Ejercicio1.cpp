#include <stdio.h>
#include <stdlib.h>

int main() {
    int Cedula;
    char Nombre[50];
    int Tipo, HorasLaboradas, ContOperarios = 0, ContTecnicos = 0, ContProfesionales = 0;
    double PrecioHora, SalarioOrdinario, Aumento, SalarioBruto, DeduccionCCSS, SalarioNeto, PromedioOperarios, PromedioTecnicos, PromedioProfesionales;
    double AcumSalarioOperarios = 0, AcumSalarioTecnicos = 0, AcumSalarioProfesionales = 0;
    char Continuar = 's';

    while (Continuar == 's' || Continuar == 'S') {
    	
        printf("\nIngrese la cédula del empleado: ");
        scanf("%d", &Cedula);

        printf("Ingrese el nombre completo del empleado: ");
        scanf(" %[^\n]", Nombre);
        
        printf("Ingrese el tipo de empleado (1-Operario, 2-Técnico, 3-Profesional): ");
        scanf("%d", &Tipo);
        
        printf("Ingrese la cantidad de horas laboradas: ");
        scanf("%d", &HorasLaboradas);
        
        printf("Ingrese el precio por hora: ");
        scanf("%lf", &PrecioHora);

        SalarioOrdinario = HorasLaboradas * PrecioHora;

        switch (Tipo) {
            case 1:
                Aumento = SalarioOrdinario * 0.15;
                ContOperarios++;
                AcumSalarioOperarios += SalarioOrdinario + Aumento;
                break;
            case 2:
                Aumento = SalarioOrdinario * 0.10;
                ContTecnicos++;
                AcumSalarioTecnicos += SalarioOrdinario + Aumento;
                break;
            case 3:
                Aumento = SalarioOrdinario * 0.05;
                ContProfesionales++;
                AcumSalarioProfesionales += SalarioOrdinario + Aumento;
                break;
            default:
                continue;
        }

        SalarioBruto = SalarioOrdinario + Aumento;
        DeduccionCCSS = SalarioBruto * 0.0917;
        SalarioNeto = SalarioBruto - DeduccionCCSS;

        printf("\nResultados:\n");
        printf("Cédula: %d\n", Cedula);
        printf("Nombre: %s\n", Nombre);
        printf("Tipo de empleado: %d\n", Tipo);
        printf("Salario por hora: %.2f\n", PrecioHora);
        printf("Horas laboradas: %d\n", HorasLaboradas);
        printf("Salario ordinario: %.2f\n", SalarioOrdinario);
        printf("Aumento: %.2f\n", Aumento);
        printf("Salario bruto: %.2f\n", SalarioBruto);
        printf("Deducción CCSS: %.2f\n", DeduccionCCSS);
        printf("Salario neto: %.2f\n", SalarioNeto);

        printf("\n¿Desea ingresar otro empleado? (s/n): ");
        scanf(" %c", &Continuar);
    }


    if (ContOperarios > 0) {
        PromedioOperarios = AcumSalarioOperarios / ContOperarios;
    } else {
        PromedioOperarios = 0.0;
    }

    if (ContTecnicos > 0) {
        PromedioTecnicos = AcumSalarioTecnicos / ContTecnicos;
    } else {
        PromedioTecnicos = 0.0;
    }

    if (ContProfesionales > 0) {
        PromedioProfesionales = AcumSalarioProfesionales / ContProfesionales;
    } else {
        PromedioProfesionales = 0.0;
    }

    printf("\nEstadísticas Finales:\n");
    printf("Cantidad de operarios: %d\n", ContOperarios);
    printf("Cantidad de técnicos: %d\n", ContTecnicos);
    printf("Cantidad de profesionales: %d\n", ContProfesionales);
    printf("Promedio salario neto operarios: %.2f\n", PromedioOperarios);
    printf("Promedio salario neto técnicos: %.2f\n", PromedioTecnicos);
    printf("Promedio salario neto profesionales: %.2f\n", PromedioProfesionales);

    return 0;
}

