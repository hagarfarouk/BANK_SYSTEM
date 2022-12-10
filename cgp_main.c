/*
 * cgp_main.c
 *
 *  Created on: Dec 10, 2022
 *      Author: Hagar
 */
#include <stdio.h>
#include "STD_Types.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "cgp_Interface.h"


void main(){
	int x;
	while (1)
	{
	printf("\n\t\t\t\tWelcome To ITI Bank\n");
	printf("If you are one of our team Please Press 1: \n");
	printf("If You are One of our Custmers Please Press 2: \n");
	printf("If You are One of our Custmers Please Press 0: \n");
	scanf("%d",&x);
	if (x==1)
		admin();
	else if (x==0) break;
	else client();

}}

