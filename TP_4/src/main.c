/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Empleado.h"


int main(void)
{
	/*
	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort
	*/
	 //setbuf(stdout,NULL);

	LinkedList* listaEmpleado = ll_newLinkedList();
	if(listaEmpleado == NULL)
	{
		printf("NO SE CONSIGUIO MEMORIA\n");
		exit(1);
	}
	else
	{
		printf("- CREE UNA LISTA USANDO ll_newLinkedList()\n");
	}
	empleado_CargaForzada(listaEmpleado);
	printf("- CARGO EMPLEADOS USANDO ll_add\n\n");
	empleado_Lister(listaEmpleado);
	printf("\n- LISTO LOS EMPLEADO USANDO ll_get y ll_len\n");
	LinkedList* listaEmpleado_copia = NULL;
	listaEmpleado_copia = ll_clone(listaEmpleado);
	printf("- CLONO MI LISTA USANDO ll_clone\n");
	if(ll_containsAll(listaEmpleado,listaEmpleado_copia))
	{
		printf("- COMPRUEBO QUE LA LISTA SEAN IGUALES CON ll_containsAll\n");
	}
	ll_pop(listaEmpleado_copia,ll_indexOf(listaEmpleado_copia,(eEmpleado*)ll_get(listaEmpleado_copia,11)));
	empleado_Lister(listaEmpleado_copia);
	printf("\n- ELIMINO EL EMPLEADO CON ID 110 DE LA COPIA DE LA LISTA USANDO CON ll_pop, ll_indexOf y ll_get\n");
	if(ll_contains(listaEmpleado_copia,(eEmpleado*)ll_get(listaEmpleado_copia,11)))
	{
		printf("- **EMPLEADO 110 NO ESTA EN LA LISTA**\n");
	}
	printf("- USO ll_contains PARA VER SI EL EMPLEADO ESTA EN LISTA\n");
	ll_push(listaEmpleado_copia,ll_indexOf(listaEmpleado,(eEmpleado*)ll_get(listaEmpleado,11)),(eEmpleado*)ll_get(listaEmpleado,11));
	empleado_Lister(listaEmpleado_copia);
	printf("\n- VUELVO A AGREGAR AL EMPLEADO A LISTA USANDO ll_push\n");
	ll_clear(listaEmpleado_copia);
	printf("- LIMPIO LA COPIA DE LA LISTA USANDO ll_clear\n");
	if(ll_isEmpty(listaEmpleado_copia))
	{
		printf("- ME FIJO SI LA LISTA ESTA VACIA CON ll_isEmpty\n\n");
	}
	empleado_Show(ll_get(listaEmpleado,19));
	printf("\n- PISO LOS DATOS DEL EMPLEADO ID 119 USANDO ll_set\n\n");
	eEmpleado a[1] ={{119,"Liliana","Plantamura",13615924,'f',68,30000}};
	eEmpleado* aux = new_empleadoParam(a->id,a->nombre,a->apellido,a->dni,a->sexo,a->edad,a->sueldo);
	ll_set(listaEmpleado,19,aux);
	empleado_Show(ll_get(listaEmpleado,19));
	empleado_Lister(listaEmpleado);
	printf("\n- MUESTRO LOS NUEVOS DATOS DEL EMPLEADO ID 119\n\n");
	ll_remove(listaEmpleado,20);
	empleado_Lister(listaEmpleado);
	printf("\n- REMUEVO EL EMPLEADO CON ID 120 USANDO ll_remove\n\n");
	ll_sort(listaEmpleado,empleado_SortByEdad,1);
	empleado_Lister(listaEmpleado);
	printf("\n- ORDENO LA LISTA POR EDAD Y SUELDOS USANDO ll_sort\n\n");
	ll_deleteLinkedList(listaEmpleado);
	ll_deleteLinkedList(listaEmpleado_copia);
	printf("\n- ELIMINO LAS LISTAS USANDO ll_deleteLinkedList\n\n");

	printf("\n----------------------------------- FIN ---------------------------------------\n");

    return 0;
}

































