#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "instrumento.h"
#define LLENO 1
#define VACIO -1

static int generarIdInstrumento(void)
{
    static int id2=0;
    return id2++;
}
int inicializarArrayIns(Instrumento *array, int cant)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        array[i].isEmpty=VACIO;
        ret=0;
    }
    return ret;
}
int buscarElVacioIns(Instrumento *array,int cant,int *indice)
{
    int ret;
    int i;
    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty==VACIO)
        {
            *indice=i;
            ret=0;
            break;
        }
        ret=-1;
    }
    return ret;
}
int altaIns(Instrumento *array,int cant,int posLibre)
{
    int ret;

    char tipAut[10];

    int auxTip;

    int posicion;

    if (!getName(array[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",5,51,1))
    {
          if(!getInt("ingrese el tipo(1:CUERDAS,2:VIENTO-MADERA,3:VIENTO-METAL,4:PERCUSION.): ","\nerror,vuelva a intentar",1,5,1,tipAut))
            {
                auxTip=atoi(tipAut);
                array[posLibre].tipo=auxTip;
                array[posLibre].id=generarIdInstrumento();
                printf("id:%d",array[posLibre].id);
                array[posLibre].isEmpty=LLENO;
                ret=0;
            }
    }

    else
    {
        ret=1;
    }
    return ret;
}
void imprimirInstrumento(Instrumento *array,int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(array[i].isEmpty!=VACIO)
        {
            printf("nombre:%s tipo:%d id:%d\n",array[i].nombre,array[i].tipo,array[i].id);
        }
    }
}
