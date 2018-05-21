
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50
#define TAMPRO 15

typedef struct
{
    int codProve;
    char descripcion[TAM];

} eProveedores;

typedef struct
{
    int codProducto;
    char descripcion[TAM];
    float importe;
    int cantidad;
    int isEmpty;
    int idProve;
    eProveedores prove;

} eProductos;







int main()
{
    int salir = 0;
    eProductos productos[TAMPRO] = {{0, "huggies", 102, 35, 0, 1,{1, "p&g"}},{1, "Pampers", 90, 5, 0, 1,{1, "p&g"}},{2, "leche", 32, 10,0,3,{3, "La Serenisima"}},{3, "yogur", 46, 5,0,3,{3, "La Serenisima"}},{4, "manteca", 22, 3,0,3,{3, "La Serenisima"}},{5, "Queso", 120, 6,0,4,{4,"Sancor"}},{6, "Pan hamburguesa", 55, 5,0,5,{5,"Bimbo"}},{7, "cafe", 60, 16,0,2,{2,"Nescafe"}},{8, "capuccino", 75, 4,0,2,{2,"Nescafe"}}};
    eProveedores proveedores[]= {{1, "p&g"},{2,"Nescafe"},{3, "La Serenisima"},{4,"Sancor"},{5,"Bimbo"}};
    inicializarProductos(productos, TAMPRO);



    for(int i=0; i<TAMPRO; i++)
    {
        while(productos[i].isEmpty!=1 && productos[i].codProducto>0)
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
            mostrarProductos(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;
        case 5:
            ejercicioCuatro(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;
        case 6:
            listar(productos, TAMPRO, proveedores, 5);
            system("pause");
            break;
        case 7:
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
    printf("4- Mostrar\n");
    printf("5- Informar\n");
    printf("6- Listar\n");
    printf("7- Salir\n");

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
    vec[0].isEmpty=0;
    vec[1].isEmpty=0;
    vec[2].isEmpty=0;
    vec[3].isEmpty=0;
    vec[4].isEmpty=0;
    vec[5].isEmpty=0;
    vec[6].isEmpty=0;
    vec[7].isEmpty=0;
    vec[8].isEmpty=0;
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



int buscarProducto(eProductos vec[], int tam, int codProduc)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].codProducto == codProduc)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


void mostrarProducto(eProductos pro, int tamProd, eProveedores proveedor[], int tamProv)
{
    int i;
    int indice;

        for(i=0; i<tamProv;i++)
        {
            if(pro.idProve == proveedor[i].codProve )
            {
                printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", pro.codProducto, pro.descripcion, pro.cantidad, pro.importe, pro.idProve, proveedor[i].descripcion);

                indice = i;
                break;

            }
        }



}


void mostrarProductos(eProductos pro[], int tamProd, eProveedores prov[],int tamProv)
{
    system("cls");
    printf("      ---Lista de Productos---\n\n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");
    for(int i=0; i< tamProd; i++)
    {
        if(pro[i].isEmpty == 0)
        {
            mostrarProducto(pro[i], tamProd, prov, tamProv);
        }
    }

}










int pedirProveedor(eProveedores proveedores[], int tam)
{
    int idProv = 0;

    while(idProv<1 || idProv>5)
    {
        printf("Lista de proveedores: \n\n");
        printf("id  // nombre \n\n");

        printf("1- p&g \n");
        printf("2- Nescafe \n");
        printf("3- La serenisima \n");
        printf("4- Sancor \n");
        printf("5- Bimbo \n");


        printf(" Elija opcion \n");

        fflush(stdin);
        scanf("%d", &idProv);

    }

    return idProv;
}






void altaProducto(eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{

    eProductos nuevoProducto;

    int indice;
    int esta;
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
        codProdu = indice + 1000;

        esta = buscarProducto(vec, tamPro, codProdu);

        if(esta != -1)
        {
            printf("\nEl producto %d ya esta dado de alta en el sistema\n", codProdu);
            mostrarProducto(vec[esta], tamPro, proveedor, tamProv);
        }
        else
        {

            nuevoProducto.isEmpty = 0;
            nuevoProducto.codProducto = codProdu;

            printf("Ingrese descripcion de producto: ");
            fflush(stdin);
            gets(nuevoProducto.descripcion);

            printf("Ingrese importe del producto: ");
            scanf("%f", &nuevoProducto.importe);

            printf("Ingrese la cantidad del producto: ");
            scanf("%d", &nuevoProducto.cantidad);


            nuevoProducto.idProve = pedirProveedor(proveedor, tamProv);
            vec[indice] = nuevoProducto;

            printf("\nAlta exitosa!!!\n\n");



        }
    }

}






void modificacionProducto(eProductos vec[], int tamPro, eProveedores proveedores[], int tamProve)
{
    int salir;
    int codProducto;
    int indice;
    char confirma;
    int opcionModificacion;

    system("cls");
    printf("---Modificacion producto---\n\n");

    mostrarProductos(vec, tamPro, proveedores, tamProve);
    printf("\n Ingrese codProducto: ");
    scanf("%d", &codProducto);

    indice = buscarProducto(vec, tamPro, codProducto);

    if(indice == -1)
    {
        printf("\nEl codigo de producto %d no se encuentra en el sistema\n\n", codProducto);

    }
    else
    {
        printf("\n  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");
        mostrarProducto(vec[indice], tamPro, proveedores, tamProve);

        opcionModificacion = menuModificacion();


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

}

int menuModificacion()
{
    int opcion;


    printf("\n  \t***Modificar*** \n\n");
    printf("\n1- \tmodificar descripcion: \n");
    printf("\n2- \tmodificar importe: \n");
    printf("\n3- \tmodificar cantidad: \n");
    printf("\n4- \tcancelar modificacion: \n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void modificaDescripcion(eProductos vec[], int indice)
{
    char confirma;
    char descripcion[50];



    printf("\nIngrese nueva descripcion:  ");
    fflush(stdin);
    scanf("%s", descripcion);

    printf("\nConfirma Modificacion?:   (s/n) ");
    fflush(stdin);
    scanf("%c", &confirma);

    if(confirma == 's')
    {
        strcpy(descripcion, vec[indice].descripcion);
        printf("\nSe ha modificado la descripcion\n\n");
    }
    else
    {
        printf("\nSe ha cancelado la modificacion\n\n");
    }


}


void modificaImporte(eProductos vec[], int indice)
{
    char confirma;
    float importe;


    printf("\nIngrese nuevo importe: ");
    scanf("%f", &importe);

    printf("\nConfirma Modificacion?: (s/n) ");
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

void modificaCantidad(eProductos vec[], int indice)
{
    char confirma;
    int cantidad;


    printf("\nIngrese nueva cantidad: ");
    scanf("%d", &cantidad);

    printf("\nConfirma Modificacion?: (s/n)");
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






void bajaProducto(eProductos vec[], int tamPro, eProveedores proveedores[], int tamProve)
{
    int codProducto;
    int esta;
    char confirma;

    system("cls");
    printf("---Baja Producto---\n\n");

    printf("Ingrese codProducto: ");
    scanf("%d", &codProducto);

    esta = buscarProducto(vec, tamPro, codProducto);

    if(esta == -1)
    {
        printf("\nEl Producto %d no se encuentra en el sistema\n\n", codProducto);

    }
    else
    {

        mostrarProducto(vec[esta], tamPro, proveedores, tamProve);

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


int validarNumero(char dato[])
{
    int largo;
    int esNumero = 0;

    largo = strlen(dato);

    for(int i=0; i<largo; i++)
    {
        if(isdigit(dato[i])== 0)
        {

            esNumero= 1;

        }

    }


    return esNumero;
}





















void ejercicioCuatro(eProductos vec[], int tamPro)
{
    float total=0;
    float cantidad = 0;
    float promedio=0;
    int superan=0;
    int noSuperan=0;
    int stockMenor=0;
    int stockMayor=0;


    for(int i=0; i<tamPro; i++)
    {

        if(vec[i].isEmpty == 0)
        {
            total = total + vec[i].importe;
            cantidad = cantidad + 1;

        }

        if(vec[i].isEmpty == 0 && vec[i].cantidad<=10)
        {
            stockMenor = stockMenor + 1;
        }

        if(vec[i].isEmpty == 0 && vec[i].cantidad>=10)
        {
            stockMayor = stockMayor + 1;
        }


    }

    promedio = total / cantidad;

    for(int j=0; j<tamPro; j++)
    {

        if(vec[j].importe<=promedio)
        {
            noSuperan = noSuperan + 1;
        }else{
            superan = superan + 1;
        }

    }

    printf("\nInformar\n\n");
    printf("\n A: total y promedio de los importes y cuantos productos superan ese promedio: \n");
    printf("Total       promedio     superan\n");
    printf("\t%.2f   %.0f    %d\n", total, promedio, superan);
    printf("\n B: total y promedio de los importes y cuantos productos NO superan ese promedio: \n");
    printf("Total       promedio     No superan\n");
    printf("\t%.2f   %.0f    %d\n", total, promedio, noSuperan);
    printf("\n C: Cantidad de productos cuyo stock es menor o igual a 10 \n");
    printf("menor stock\n");
    printf("\t%d\n", stockMenor);
    printf("\n D: Cantidad de productos cuyo stock es Mayor a 10 \n");
    printf("Mayor Stock\n");
    printf("\t%d\n", stockMayor);


}










void listar (eProductos vec[], int tamPro, eProveedores proveedores[], int tamProve)
{

        int opcion;

        printf("Listar: \n\n");
        printf("1--- A- realizar un solo listado de los productos ordenados por Importe (descendentemente) y descripcion(ascendentemente)\n");
        printf("2--- B- Todos los productos que en cantidad son menor o igual a 10 \n");
        printf("3--- C- Todos los productos que en cantidad son mayor a 10 \n");
        printf("4--- D- Todos los productos que superan el promedio de los importes \n");
        printf("5--- E- todos los productos que no superan el promedio de los importes \n");
        printf("6--- F- Todos los proveedores cuya cantidad de producto es menor o igual a 10 \n");
        printf("7--- G- todos los productos provistos por cada proveedor \n");
        printf("8--- H- todos los productos provistos por un proveedor determinado \n");
        printf("9--- I- El proveedor que provee mas productos, mostrando los productos \n");
        printf("10-- J- el proveedor que provee menos productos, mostrando los productos \n");
        printf("11-- K- el proveedor que provee el producto mas caro \n");
        printf("12-- L- el proveedor que provee el producto mas barato, mostrando ese producto \n");
        printf("Para salir elija cualquier otro numero \n\n");
        printf(" Elija opcion entre 1 y 12\n");


        fflush(stdin);
        scanf("%d", &opcion);



        switch(opcion)
            {
            case 1:
                    puntoA(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 2:
                    puntoB(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 3:
                    puntoC(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 4:
                    puntoD(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 5:
                    puntoE(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 6:
                    puntoF(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 7:
                    puntoG(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 8:
                    puntoH(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 9:
                    puntoI(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 10:
                    puntoJ(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 11:
                    puntok(vec, tamPro, proveedores, tamProve);
                    system("pause");
                break;
            case 12:
                    puntoL(vec, tamPro, proveedores, tamProve);
                    system("pause");
            default:
                break;
            }


}



void puntoA(eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{





}
























void puntoB (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{


    printf("\n  Todos los productos que en cantidad son igual o menor a 10\n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");
    for(int i=0; i<tamPro; i++)
    {
        if(vec[i].idProve == proveedor[i].codProve )
        {
            if(vec[i].cantidad<= 10)
            {
                printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[i].codProducto, vec[i].descripcion, vec[i].cantidad, vec[i].importe, vec[i].idProve, proveedor[i].descripcion);
            }
        }

    }


}



void puntoC (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{



    printf("\n  Todos los productos que en cantidad mayor a 10\n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");
    for(int i=0; i<tamPro; i++)
    {

         if(vec[i].idProve == proveedor[i].codProve )
        {

            if(vec[i].cantidad> 10)
            {
                printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[i].codProducto, vec[i].descripcion, vec[i].cantidad, vec[i].importe, vec[i].idProve, proveedor[i].descripcion);
            }
        }

    }



}


void puntoD (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
    float cantidad=0;
    float total=0;
    float promedio=0;


      for(int i=0; i<tamPro; i++)
    {

        if(vec[i].isEmpty == 0)
        {
            total = total + vec[i].importe;
            cantidad = cantidad + 1;

        }
    }

    promedio = total / cantidad;

    printf("\n  Todos los productos que superan el promedio de los importes\n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");

    for(int j =0; j<tamPro; j++)
    {
        if(vec[j].importe> promedio)
        {
            if(vec[j].idProve == proveedor[j].codProve )
            {
                printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[j].codProducto, vec[j].descripcion, vec[j].cantidad, vec[j].importe, vec[j].idProve, proveedor[j].descripcion);
            }
        }

    }


}


void puntoE (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
    int cantidad=0;
    float total=0;
    float promedio=0;


      for(int i=0; i<tamPro; i++)
    {

        if(vec[i].isEmpty == 0)
        {
            total = total + vec[i].importe;
            cantidad = cantidad + 1;

        }
    }

    promedio = total / cantidad;

    printf("\n  Todos los productos que NO superan el promedio de los importes\n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");

    for(int j =0; j<tamPro; j++)
    {
        if(vec[j].importe<promedio)
        {
            if(vec[j].idProve == proveedor[j].codProve )
            {
                printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[j].codProducto, vec[j].descripcion, vec[j].cantidad, vec[j].importe, vec[j].idProve, proveedor[j].descripcion);
            }
        }

    }


}



void puntoF (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
    printf("\n Todos los proveedores cuya cantidad de producto es menor o igual a 10 \n");
    printf("    Descripcion    \n\n");
    for(int i=0; i<tamPro; i++)
    {
        if(vec[i].cantidad <= 10)
        {
            printf("%s\n", proveedor[i].descripcion);
        }

    }



}



void puntoG (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{

     printf("\n Todos los productos provistos por cada proveedor \n");
     printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");

    for(int i=0; i<tamProv; i++)
    {
        for(int j=0; j<tamPro; j++)
        {
            if(vec[j].isEmpty==0 && vec[j].idProve == proveedor[i].codProve)
            {
               printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[j].codProducto, vec[j].descripcion, vec[j].cantidad, vec[j].importe, vec[j].idProve, proveedor[j].descripcion);

            }


        }



    }


}


void puntoH (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
    int opcion;
    int indice;

        printf("Lista de proveedores: \n\n");
        printf("1- p&g \n");
        printf("2- Nescafe \n");
        printf("3- La serenisima \n");
        printf("4- Sancor \n");
        printf("5- Bimbo \n");
        printf(" Elija opcion proveedor para mostrar\n");


        fflush(stdin);
        scanf("%d", &opcion);

        indice = opcion;

        printf("\n Todos los productos provistos por un proveedor determinado \n");
        printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");


    for(int i=0; i<tamPro; i++)
    {
        if(vec[i].isEmpty== 0)
        {
            for(int j=0; j<tamPro; j++)
            {
                if(vec[j].idProve == proveedor[indice].codProve)
                {
                     printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[j].codProducto, vec[j].descripcion, vec[j].cantidad, vec[j].importe, vec[j].idProve, proveedor[j].descripcion);
                }

            }

        }
    }
}


void puntoI (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
   int idProve;
   int contador=0;
   int maximo=0;

    printf("\n El proveedor que provee mas productos, mostrando los productos \n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");

    for(int i=0; i<tamProv; i++)
    {

        for(int j=0; j<tamPro; j++)
        {

            if(vec[j].idProve == proveedor[i].codProve && vec[j].isEmpty==0)
            {
                contador++;
            }

        }
        if(contador>maximo)
        {
            maximo = contador;
            idProve = proveedor[i].codProve;
        }

    }


    for(int i = 0; i<tamPro; i++)
    {

        if(vec[i].idProve == idProve && vec[i].isEmpty==0)
        {
            printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[i].codProducto, vec[i].descripcion, vec[i].cantidad, vec[i].importe, vec[i].idProve, proveedor[i].descripcion);
        }

    }



}



void puntoJ (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
   int idProve;
   int contador=0;
   int minimo=0;

    printf("\n El proveedor que provee menos productos, mostrando los productos \n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");

    for(int i=0; i<tamProv; i++)
    {

        for(int j=0; j<tamPro; j++)
        {

            if(vec[j].idProve == proveedor[i].codProve && vec[j].isEmpty==0)
            {
                contador++;
            }

        }
        if(contador<minimo)
        {
            minimo = contador;
            idProve = proveedor[i].codProve;
        }

    }


    for(int i = 0; i<tamPro; i++)
    {

        if(vec[i].idProve == idProve && vec[i].isEmpty==0)
        {
            printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[i].codProducto, vec[i].descripcion, vec[i].cantidad, vec[i].importe, vec[i].idProve, proveedor[i].descripcion);
        }

    }



}



void puntok (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{
   int idProve;
   int maximo;
   int masCaro;

    printf("\n El proveedor que provee el producto mas caro, mostrando ese productos \n");
    printf("  cod Producto  Descripcion   cantidad   Importe   Id Proveedor  Proveedor \n\n");

    for(int i=0; i<tamProv; i++)
    {

        for(int j=0; j<tamPro; j++)
        {

            if(vec[j].idProve == proveedor[i].codProve && vec[j].isEmpty==0)
            {
                if(maximo<masCaro)
                {
                     masCaro = maximo;
                     idProve = proveedor[i].codProve;
                }
            }

        }



    }


    for(int i = 0; i<tamPro; i++)
    {

        if(vec[i].idProve == idProve && vec[i].isEmpty==0)
        {
            printf("  %4d    /  %12s   /   %2d  / %6.2f   /   %2d /    %10s\n", vec[i].codProducto, vec[i].descripcion, vec[i].cantidad, vec[i].importe, vec[i].idProve, proveedor[i].descripcion);
        }

    }



}


void puntoL (eProductos vec[], int tamPro, eProveedores proveedor[], int tamProv)
{


}
