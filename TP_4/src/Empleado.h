#include "../inc/LinkedList.h"

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    int dni;
    char sexo;
    int edad;
    float sueldo;

}eEmpleado;


#endif // EMPLEADO_H_INCLUDED

eEmpleado* new_empleado();
eEmpleado* new_empleadoParam(int id, char* nombre, char* apellido, int dni, char sexo, int edad, float sueldo);
void empleado_Delete();

int empleado_SetId(eEmpleado* empleado, int id);
int empleado_SetNombre(eEmpleado* empleado,char* nombre);
int empleado_SetApellido(eEmpleado* empleado,char* apellido);
int empleado_SetDni(eEmpleado* empleado, int dni);
int empleado_SetSexo(eEmpleado* empleado, char sexo);
int empleado_SetEdad(eEmpleado* empleado, int edad);
int empleado_SetSueldo(eEmpleado* empleado, float sueldo);

int empleado_GetId(eEmpleado* empleado, int* id);
int empleado_GetNombre(eEmpleado* empleado, char* nombre);
int empleado_GetApellido(eEmpleado* empleado, char* apellido);
int empleado_GetDni(eEmpleado* empleado, int* dni);
int empleado_GetSexo(eEmpleado* empleado,char* sexo);
int empleado_GetEdad(eEmpleado* empleado,int* edad);
int empleado_GetSueldo(eEmpleado* empleado, float* sueldo);

void empleado_Show(eEmpleado* empleado);
void empleado_ShowRow(eEmpleado* empleado);
int empleado_Lister(LinkedList* lista);
int empleado_CargaForzada(LinkedList* lista);

int empleado_SortById(void* a, void* b);
int empleado_SortByNombre(void* a, void* b);
int empleado_SortByApellido(void* a, void* b);
int empleado_SortByDni(void* a, void* b);
int empleado_SortBySexo(void* a, void* b);
int empleado_SortByEdad(void* a, void* b);
int empleado_SortBySueldo(void* a, void* b);
