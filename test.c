#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "test.h"

void main()
{
	t_truc *truc;

	truc = (t_truc *)malloc(sizeof(truc));

	truc->x = 21;
	truc->oui.l = 42;
	truc->oui.non.tg = 84;
	printf("x: [%d]\nl: [%d]\ntg: [%d]\n", truc->x, truc->oui.l, truc->oui.non.tg);
}
