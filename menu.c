/**************************************************************************************************/
/* Copyright (C) xeeyung@163.com, sse@USTC, 2014-2015                                             */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  Xuyang                                                               */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  VC6.0                                                                */
/*  DATE OF FIRST RELEASE :  2014/09/15                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Xuyang, 2014/09/15
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN    1024
#define CMD_LEN     100

typedef struct DataNode
{
	char*   cmd;
	char*   desc;
	struct  DataNode *next;
} DataNode;

void main()
{   
	/*this is declaration of putMenuList*/
	void putMenuList(DataNode *a);
	/*this is declaration of putListOne*/
	void putListOne(DataNode *b , DataNode *c);
	static DataNode head[] =
	{
		{"help","this is help cmd.",&head[1]},
		{"search","this is search cmd.",&head[2]},
		{"copy","this is copy cmd.",&head[3]},
		{"version","menu progrram v2.0",NULL}
	};
	DataNode * p = head;
	printf("menu list : \n");
	putMenuList(p);
	putListOne(p , head);   
}

/*this is definition of putMenuList*/
void putMenuList(DataNode *a)
{
	while(a != NULL)
	{
		printf("%s - %s\n", a->cmd, a->desc);
		a = a->next;
	} 
}

/*this is definition of putListOne*/
void putListOne(DataNode *b , DataNode *c)
{
	while(1)
	{
		char cmd[CMD_LEN];
		printf("Input a cmd > ");
		scanf("%s", cmd);
		b = c;
		while(b != NULL)
		{
			if(!strcmp(b->cmd , cmd))
			{
				printf("%s - %s\n", b->cmd, b->desc);
				break;
			}
			b = b->next;
		}
		if(b == NULL)
		{
			printf("This is a wrong cmd !\n ");
		}
	}
}

