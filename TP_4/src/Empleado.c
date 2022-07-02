#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Empleado.h"
#include "../inc/LinkedList.h"


eEmpleado* new_empleado()
{
    eEmpleado* empleado = NULL;
    empleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(empleado != NULL)
    {
        empleado->id = 0;
        strcpy(empleado->nombre,"NN");
        strcpy(empleado->apellido,"NN");
        empleado->dni = 0;
        empleado->sexo = 'N';
        empleado->edad = 0;
        empleado->sueldo = 0;
    }
    return empleado;
}
eEmpleado* new_empleadoParam(int id, char* nombre, char* apellido, int dni, char sexo, int edad, float sueldo)
{
    eEmpleado* empleado = new_empleado();
    if(!(empleado_SetId(empleado,id) &&
         empleado_SetNombre(empleado, nombre)&&
         empleado_SetApellido(empleado, apellido)&&
         empleado_SetDni(empleado, dni)&&
         empleado_SetSexo(empleado, sexo)&&
         empleado_SetEdad(empleado, edad)&&
         empleado_SetSueldo(empleado, sueldo)))
    {
        empleado_Delete(empleado);
        empleado = NULL;
    }
    return empleado;
}
void empleado_Delete(eEmpleado* empleado)
{
    free(empleado);
}
int empleado_SetId(eEmpleado* empleado, int id)
{
    int isOk = 0;
    if(empleado != NULL && id > 0)
    {
        empleado->id = id;
        isOk = 1;
    }
    return isOk;
}
int empleado_SetNombre(eEmpleado* empleado,char* nombre)
{
    int isOk = 0;
    if(empleado != NULL && nombre != NULL && strlen(nombre) > 0 && strlen(nombre) < 20)
    {
        strlwr(nombre);
		nombre[0] = toupper(nombre[0]);
        strcpy(empleado->nombre, nombre);
        isOk = 1;
    }
    return isOk;
}
int empleado_SetApellido(eEmpleado* empleado,char* apellido)
{
    int isOk = 0;
    if(empleado != NULL && apellido != NULL && strlen(apellido) > 0 && strlen(apellido) < 20)
    {
        strlwr(apellido);
		apellido[0] = toupper(apellido[0]);
        strcpy(empleado->apellido, apellido);
        isOk = 1;
    }
    return isOk;
}
int empleado_SetDni(eEmpleado* empleado, int dni)
{
    int isOk = 0;
    if(empleado != NULL && dni > 0)
    {
        empleado->dni = dni;
        isOk = 1;
    }
    return isOk;
}
int empleado_SetSexo(eEmpleado* empleado, char sexo)
{
    int isOk = 0;
    if(empleado != NULL && (sexo == 'm' || sexo == 'f'))
    {
        empleado->sexo = sexo;
        isOk = 1;
    }
    return isOk;
}
int empleado_SetEdad(eEmpleado* empleado, int edad)
{
    int isOk = 0;
    if(empleado != NULL && edad > 0)
    {
        empleado->edad = edad;
        isOk = 1;
    }
    return isOk;
}
int empleado_SetSueldo(eEmpleado* empleado, float sueldo)
{
    int isOk = 0;
    if(empleado != NULL && sueldo > 0)
    {
        empleado->sueldo = sueldo;
        isOk = 1;
    }
    return isOk;
}
int empleado_GetId(eEmpleado* empleado, int* id)
{
    int isOk = 0;
    if(empleado != NULL && id != NULL)
    {
        *id = empleado->id;
        isOk = 1;
    }
    return isOk;
}
int empleado_GetNombre(eEmpleado* empleado, char* nombre)
{
    int isOk = 0;
    if(empleado != NULL && nombre != NULL)
    {
        strcpy(nombre,empleado->nombre);
        isOk = 1;
    }
    return isOk;
}
int empleado_GetApellido(eEmpleado* empleado, char* apellido)
{
    int isOk = 0;
    if(empleado != NULL && apellido != NULL)
    {
        strcpy(apellido,empleado->apellido);
        isOk = 1;
    }
    return isOk;
}
int empleado_GetDni(eEmpleado* empleado, int* dni)
{
    int isOk = 0;
    if(empleado != NULL && dni != NULL)
    {
        *dni = empleado->dni;
        isOk = 1;
    }
    return isOk;
}
int empleado_GetSexo(eEmpleado* empleado,char* sexo)
{
    int isOk = 0;
    if(empleado != NULL && sexo != NULL)
    {
        if(empleado->sexo == 'm')
        {
            strcpy(sexo,"Masculino");
            isOk = 1;
        }
        else if(empleado->sexo == 'f')
        {
            strcpy(sexo,"Femenino");
            isOk = 1;
        }
    }
    return isOk;
}
int empleado_GetEdad(eEmpleado* empleado,int* edad)
{
    int isOk = 0;
    if(empleado != NULL && edad != NULL)
    {
        *edad = empleado->edad;
        isOk = 1;
    }
    return isOk;
}
int empleado_GetSueldo(eEmpleado* empleado, float* sueldo)
{
    int isOk = 0;
    if(empleado != NULL && sueldo != NULL)
    {
        *sueldo = empleado->sueldo;
        isOk = 1;
    }
    return isOk;
}
void empleado_Show(eEmpleado* empleado)
{
    char empleado_sexo[20];
    if(empleado != NULL)
    {
        empleado_GetSexo(empleado,empleado_sexo);
        printf("ID:       %d\n"
               "NOMBRE:   %s\n"
               "APELLIDO: %s\n"
               "DNI:      %d\n"
               "SEXO:     %s\n"
               "EDAD:     %d\n"
               "SUELDO:   %.2f\n",
               empleado->id,
               empleado->nombre,
               empleado->apellido,
               empleado->dni,
               empleado_sexo,
               empleado->edad,
               empleado->sueldo);
    }
}
void empleado_ShowRow(eEmpleado* empleado)
{
    char empleado_sexo[20];
    if(empleado != NULL)
    {
        empleado_GetSexo(empleado,empleado_sexo);
        printf("%4d  %-15s %-15s  %8d     %-10s  %2d  %10.2f\n",
               empleado->id,
               empleado->nombre,
               empleado->apellido,
               empleado->dni,
               empleado_sexo,
               empleado->edad,
               empleado->sueldo);
    }
}
int empleado_Lister(LinkedList* lista)
{
    int isOk = 0;
    if(lista != NULL)
    {
        printf("                         LISTA DE EMPLEADOS\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf(" ID    NOMBRE        APELLIDO             DNI         SEXO     EDAD    SUELDO\n");
		printf("-----------------------------------------------------------------------------------\n");

		for( int i = 0; i < ll_len(lista); i++)
		{
			empleado_ShowRow(ll_get(lista, i));
		}
		isOk = 1;
    }
    return isOk;
}
int empleado_CargaForzada(LinkedList* lista)
{
    int isOk = 0;
    if(lista != NULL)
    {
        eEmpleado listaEmpleado[21] =
        {
            {100,"Gonzalo","Lopez",38712333,'m',27,10000},
            {101,"Tomas","Lopez",40363989,'m',25,10000},
            {102,"Julia","Perez",39125635,'f',26,20000},
            {103,"Matias","Rodriguez",33254236,'m',35,30000},
            {104,"Martin","Cosecha",33125485,'m',35,10000},
            {105,"Ana","Martinez",41365852,'f',19,30000},
            {106,"Maria","Lopez",27025898,'f',40,10000},
            {107,"Juan","Perez",15236589,'m',53,30000},
            {108,"Lucas","Martinez",16951814,'m',50,20000},
            {109,"Malena","Cosecha",35418888,'f',30,10000},
            {110,"Camila","Perez",35498488,'f',30,10000},
            {111,"Rocio","Lopez",29629595,'f',39,30000},
            {112,"Fernando","Martinez",26984296,'m',45,20000},
            {113,"Luis","Rodriguez",12229959,'m',70,10000},
            {114,"Norma","Lopez",38941891,'f',27,30000},
            {115,"Carolina","Perez",22959599,'f',31,10000},
            {116,"Federico","Rodriguez",35648948,'m',30,20000},
            {117,"Victoria","Martinez",36528485,'f',29,10000},
            {118,"Gabriela","Lopez",31825895,'f',33,10000},
            {119,"Mariano","Perez",28948589,'m',42,2000},
            {120,"Denise","Rodriguez",18895895,'f',60,30000}
        };

        for(int i = 0; i < 21; i++)
        {
            eEmpleado* empleado = new_empleadoParam(listaEmpleado[i].id,listaEmpleado[i].nombre,listaEmpleado[i].apellido,
                                                    listaEmpleado[i].dni,listaEmpleado[i].sexo,listaEmpleado[i].edad,listaEmpleado[i].sueldo);
            if(empleado != NULL)
            {
                ll_add(lista,empleado);
            }
        }
        isOk = 1;
    }
    return isOk;
}
int empleado_SortById(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(empleado1->id == empleado2->id)
        {
            isOk = 0;
        }
        else if(empleado1->id > empleado2->id)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}
int empleado_SortByNombre(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(!strcmp(empleado1->nombre, empleado2->nombre))
        {
            isOk = 0;
        }
        else if(strcmp(empleado1->nombre, empleado2->nombre)>0)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}
int empleado_SortByApellido(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(!strcmp(empleado1->apellido, empleado2->apellido))
        {
            isOk = 0;
        }
        else if(strcmp(empleado1->apellido, empleado2->apellido)>0)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}
int empleado_SortByDni(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(empleado1->dni == empleado2->dni)
        {
            isOk = 0;
        }
        else if(empleado1->dni > empleado2->dni)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}
int empleado_SortBySexo(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(empleado1->sexo == empleado2->sexo)
        {
            isOk = 0;
        }
        else if(empleado1->sexo > empleado2->sexo)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}
int empleado_SortByEdad(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(empleado1->edad == empleado2->edad)
        {
            isOk = 0;
        }
        else if(empleado1->edad > empleado2->edad)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}
int empleado_SortBySueldo(void* a, void* b)
{
    int isOk = 0;
    if(a != NULL && b != NULL)
    {
        eEmpleado* empleado1 = (eEmpleado*)a;
        eEmpleado* empleado2 = (eEmpleado*)b;
        if(empleado1->sueldo == empleado2->sueldo)
        {
            isOk = 0;
        }
        else if(empleado1->sueldo > empleado2->sueldo)
        {
            isOk = 1;
        }
        else
        {
            isOk = -1;
        }
    }
    return isOk;
}


