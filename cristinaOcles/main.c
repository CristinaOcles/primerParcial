
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAMPRO 10

typedef struct
{
    int codProve;
    char descripcion[50];

} eProveedores;

typedef struct
{
    int codProducto;
    char descripcion[50];
    float importe;
    int cantidad;
    int isEmpty;
    eProveedores codigoProve;

} eProductos;







int main()
{
    int salir = 0;
    eProductos productos[5];
    eProveedores proveedores[]={{1, "manaos"},{2,"Coca"},{3, "pinky"},{4,"tang"},{5,"cligth"}};
    inicializarProductos(productos, 5);

    for(int i=0; i<TAMPRO; i++)
    {
        while(productos[i].isEmpty!=1 && productos[i].codProducto>-1)
        {
            productos[i].codProducto = i+1;

        }
    }


    do
    {
        switch(menu())
        {

        case 1:
            altaProducto(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;
        case 2:
            bajaProducto(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;
        case 3:
            modificacionProducto(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;
        case 4:
            mostrarProducto(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;

        case 5:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }
    }
    while(salir != 1);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("      ---Stock---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}









void inicializarProductos(eProductos vec[], int tam)
{

    for(int i=0; i< tam; i++)
    {
        vec[i].isEmpty = 1;

    }
}


int buscarLibre(eProductos vec[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarProducto(eProductos vec[], int tam, int codProducto)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].codProducto == codProducto)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void mostrarProducto(eProductos vec, int tam, eProveedores proveedor[], int tamProv)
{
    int i;
    int indice;
    for(i=0; i< tamProv; i++)
    {
        if(vec.codProducto == proveedor[i].codProve )
        {
            indice = i;
            break;
        }
    }
    printf("  %4d  / %15s   /  %2d  /%6.2f   /  %2d /  %10s\n", vec.codProducto, vec.descripcion, vec.cantidad, vec.importe, vec.codigoProve, proveedor[i].descripcion);
}



int pedirProveedor(eProveedores proveedores[], int tam)
{

    int idProv;

    printf("\nProveedores\n\n");

    for(int i=0; i< tam; i++)
    {
        printf("%d- / %s\n", proveedores[i].codProve, proveedores[i].descripcion );
    }
    printf("\nIndique Sector: ");
    fflush(stdin);
    scanf("%d", &idProv);

    return idProv;
}






void altaProducto(eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{

    eProductos nuevoProducto;

    int indice;
    int codProdu;

    system("cls");
    printf("---Alta Productos--\n\n");

    indice = buscarLibre(vec, tamPro);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a productos nuevos.\n\n");
    }
    else
    {
        printf("Ingrese codigo de producto: ");
        scanf("%d", &codProdu);

        indice = buscarProducto(vec, tamPro, codProdu);

        if(indice != -1)
        {
            printf("\nEl producto %d ya esta dado de alta en el sistema\n", codProdu);
            mostrarProducto(vec[indice], proveedor, tamp);
        }
        else
        {

            nuevoProducto.isEmpty = 0;
            nuevoProducto.codProdu = codProdu;

            printf("Ingrese descripcion de producto: ");
            fflush(stdin);
            gets(nuevoProducto.descripcion);

            printf("Ingrese importe del producto: ");
            scanf("%f", &nuevoProducto.importe);

            printf("Ingrese la cantidad del producto: ");
            scanf("%d", &nuevoProducto.cantidad);

            printf("Ingrese el codigo del proveedor: ");
            scanf("%d", &nuevoProducto.codigoProve);

            nuevoProducto.codProducto = pedirProveedor(proveedor, tamProv);
            vec[indice] = nuevoProducto;

            printf("\nAlta exitosa!!!\n\n");



        }
    }

}






void modificacionProducto(eProductos vec[], int tamPro, eProveedores proveedores[], int tamProve)
{
    int codProducto;
    int indice;
    char confirma;
    int opcionModificacion;

    system("cls");
    printf("---Modificacion producto---\n\n");

    printf("Ingrese codProducto: ");
    scanf("%d", &codProducto);

    indice = buscarProducto(vec, tamPro, codProducto);

    if(indice == -1)
    {
        printf("\nEl codigo de producto %d no se encuentra en el sistema\n\n", codProducto);

    }
    else
    {

        mostrarProducto(vec[indice], proveedores, tamProve);
        opcionModificacion = menuModificacion();

        do
        {
            switch(opcionModificacion)
            {
            case 1:
                modificaDescripcion(vec, indice);

                break;
            case 2:
                modificaImporte(vec, indice);
                break;
            case 3:
                modificaCantidad(vec, indice);
                break;
            case 4:
                printf("\nSalir\n\n");
                salir = 1;
                break;
            default:
                break;

            }
        }
        while(salir != 1);


}


void menuModificacion()
{
    int opcion;

    system("cls");
    printf("\n  \t***Modificar*** \n\n");
    printf("\n1- \tmodificar descripcion: \n");
    printf("\n2- \tmodificar importe: \n");
    printf("\n3- \tmodificar cantidad: \n");
    printf("\n4- \tcancelar modificacion: \n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void modificaDescripcion(eProductos vec, int indice)
{
    char confirma;
    char descripcion[50];


    printf("\nIngrese nueva descripcion: ");
    scanf("%s", descripcion);

    printf("\nConfirma Modificacion?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    if(confirma == 's')
    {
        vec[indice].descripcion = descripcion;
        printf("\nSe ha modificado la descripcion\n\n");
    }
    else
    {
        printf("\nSe ha cancelado la modificacion\n\n");
    }


}


void modificaImporte(eProductos vec, int indice)
{
    char confirma;
    float importe;


    printf("\nIngrese nuevo importe: ");
    scanf("%.2f", &importe);

    printf("\nConfirma Modificacion?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    if(confirma == 's')
    {
        vec[indice].importe = importe;
        printf("\nSe ha modificado el importe\n\n");
    }
    else
    {
        printf("\nSe ha cancelado la modificacion\n\n");
    }


}

void modificaCantidad(eProductos vec, int indice)
{
    char confirma;
    int cantidad;


    printf("\nIngrese nueva cantidad: ");
    scanf("%d", &cantidad);

    printf("\nConfirma Modificacion?: ");
    fflush(stdin);
    scanf("%c", &confirma);

    if(confirma == 's')
    {
        vec[indice].cantidad = cantidad;
        printf("\nSe ha modificado la cantidad\n\n");
    }
    else
    {
        printf("\nSe ha cancelado la modificacion\n\n");
    }


}






void bajaProducto(eProductos vec[], int tam, eProveedores proveedores[], int tamProve)
{
    int codProducto;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Producto---\n\n");

    printf("Ingrese codProducto: ");
    scanf("%d", &codProducto);

    esta = buscarProducto(vec, tam, codProducto);

    if(esta == -1)
    {
        printf("\nEl Producto %d no se encuentra en el sistema\n\n", codProducto);

    }
    else
    {

        mostrarProducto(vec[esta], proveedores , tamProve);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].isEmpty = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}
