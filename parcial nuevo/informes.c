#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "orquesta.h"
#include "validaciones.h"
#include "musico.h"
#include "instrumento.h"
#include "informes.h"
#define LLENO 1
#define VACIO -1
void informes(Orquesta *arrayOrq,Instrumento *arrayIns,Musico *arrayMus,int cantOrq,int cantMus,int cantIns)
{
    int informe;


    printf("                   :::::::::::::::::::::::::::\n");
    printf("                   :   1) INFORMES: A         :\n");
    printf("                   :   2) INFORME: b        :\n");
    printf("                   :   3) INFORME: D         :\n");
    printf("                   :   4) INFORME: E         :\n");
    printf("                   :   5) INFORME: F         :\n");
    printf("                   :   6) INFORME: G         :\n");
    printf("                   :   7) INFORME: H         :\n");
    printf("                   :   8) INFORME: I         :\n");
    printf("                   :   9) INFORME: J         :\n");
    printf("                   :::::::::::::::::::::::::::\n");

    printf("ingrese un informe... ");
    scanf("%d",&informe);

    switch(informe)
    {
    case 1:
        informeA( arrayOrq,cantOrq);
        break;
    case 2:
        informeB(arrayMus,cantMus,arrayIns,arrayOrq,cantOrq,cantIns);
        break;
    case 3:
        informeC(arrayOrq,cantOrq,arrayMus,cantMus);
        break;
    case 4:
        informeD( arrayOrq,cantOrq,arrayIns,cantIns,arrayMus,cantMus);
        break;

    }
}
void informeA(Orquesta *arrayOrq,int cantOrq)
{
    char auxLugar[50];
    int i;

    getDireccion(auxLugar,"ingrese un lugar: ","error, vuelva a ingresar\n\n",1,51,1);

    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty==LLENO && strcmp(arrayOrq[i].lugar,auxLugar)==0)
        {
            printf("id:%d nombre:%s tipo:%d lugar:%s \n",arrayOrq[i].id,arrayOrq[i].nombre,arrayOrq[i].tipo,arrayOrq[i].lugar);

        }
    }
}
void informeB(Musico *arrayMus,int cantMus,Instrumento *arrayIns,Orquesta *arrayOrq,int cantOrq,int cantIns)
{

    int i;
    int j;
    int k;

    for(i=0; i<cantMus; i++)
    {
        if(arrayMus[i].isEmpty==LLENO && arrayMus[i].edad < 25)
        {
            for(j=0; j<cantOrq; j++)
            {
                if(arrayOrq[j].id==arrayMus[i].idOrq)
                {
                    for(k=0; k<cantIns; k++)
                    {
                        if(arrayIns[k].id==arrayMus[i].idIns)
                        {
                            if(arrayIns[i].tipo==1)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:cuerdas\n",arrayMus[i].id,arrayMus[i].nombre,arrayMus[i].apellido,arrayMus[i].edad,arrayOrq[j].nombre);
                                break;
                            }
                            if(arrayIns[i].tipo==2)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:viento-madera\n",arrayMus[i].id,arrayMus[i].nombre,arrayMus[i].apellido,arrayMus[i].edad,arrayOrq[j].nombre);
                                break;
                            }
                            if(arrayIns[i].tipo==3)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:viento-metal\n",arrayMus[i].id,arrayMus[i].nombre,arrayMus[i].apellido,arrayMus[i].edad,arrayOrq[j].nombre);
                                break;
                            }
                            if(arrayIns[i].tipo==4)
                            {
                                printf(" id:%d nombre:%s apellido:%s edad:%d nombre de la orquesta:%s nombre de intrumento:percusion\n",arrayMus[i].id,arrayMus[i].nombre,arrayMus[i].apellido,arrayMus[i].edad,arrayOrq[j].nombre);
                                break;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
}
void informeC(Orquesta *arrayOrq,int cantOrq,Musico *arrayMus,int cantMus)
{
    int i;
    int j;
    int k;
    int cont=0;

    for(i=0; i<cantMus; i++)
    {

            for(j=0; j<cantOrq; j++)
            {
                if(arrayMus[i].idOrq==arrayOrq[j].id )
                {
                    cont++;
                  //  break;
                }
            }

    }
    for(k=0;k<cantOrq; k++)
    {
        if(cont<6)
        {
            printf("id:%d nombre:%s tipo:d lugar:%s \n",arrayOrq[k].id,arrayOrq[k].nombre,arrayOrq[k].tipo,arrayOrq[k].lugar);
        }
    }
}
void informeD(Orquesta *arrayOrq,int cantOrq,Instrumento *arrayIns,int cantIns,Musico *arrayMus,int cantMus)
{
    char idAut[50];
    int auxAut;
    int i;
    int j;
    int k;
    getInt("ingrese el id de la orquesta: ","\nerror,vuelva a intentar",0,20,1,idAut);
    auxAut=atoi(idAut);

    for(i=0; i<cantOrq; i++)
    {
        if(arrayOrq[i].isEmpty==LLENO && auxAut==arrayOrq[i].id)
        {
            for(j=0; j<cantMus; j++)
            {
                if(arrayMus[j].isEmpty==LLENO && arrayOrq[i].id==arrayMus[j].idOrq)
                {
                    for(k=0; k<cantIns; k++)
                    {
                        if(arrayIns[k].isEmpty==LLENO &&arrayMus[j].idIns==arrayIns[k].id)
                        {
                            if(arrayIns[k].tipo==1)
                            {
                                printf("nombre:cuerdas tipo:%d nombre de musico:%s\n",arrayIns[k].tipo,arrayMus[j].nombre);
                                //  break;
                            }
                            if(arrayIns[k].tipo==2)
                            {
                                printf("nombre:viento-madera tipo:%d nombre de musico:%s\n",arrayIns[k].tipo,arrayMus[j].nombre);
                                //   break;
                            }
                            if(arrayIns[k].tipo==3)
                            {
                                printf("nombre:viento-metal tipo:%d nombre de musico:%s\n",arrayIns[k].tipo,arrayMus[j].nombre);
                                //      break;
                            }
                            if(arrayIns[k].tipo==4)
                            {
                                printf("nombre:percusion tipo:%d nombre de musico:%s\n",arrayIns[k].tipo,arrayMus[j].nombre);
                                //        break;
                            }
                        }
                    }
                    break;
                }
            }
        }


    }
}
