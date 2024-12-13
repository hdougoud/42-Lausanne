#include "push_swap.h"

void print_list(t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	printf("\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("TAB_A	[%d] %d		",i , stack_a->nb);
			stack_a = stack_a->next;
		}
		else
			printf("TAB_A[]	NULL		");
		if (stack_b)
		{
			printf("TAB_B[%d] %d\n",i , stack_b->nb);	
			stack_b = stack_b->next;
		}
		else
			printf("TAB_B[]	NULL\n");
		i++;
	}
	printf("_____________________________________________\n");
}