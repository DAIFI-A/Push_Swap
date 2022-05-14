/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 23:01:38 by adaifi            #+#    #+#             */
/*   Updated: 2022/05/13 17:33:45 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_stack	*creat_node(void)
{
	t_stack	*head;

	head = (t_stack *)malloc(sizeof(t_stack));
	head->deff = 1;
	head->num = 0;
	head->next = NULL;
	return (head);
}

t_stack	*stack_fillin(int argc, char **argv)
{
	int		i;
	t_stack	*head;
	t_stack	*tmp;

	i = 1;
	head = creat_node();
	tmp = head;
	while (i < argc)
	{
		tmp->num = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp->next = creat_node();
			tmp = tmp->next;
			tmp->deff = 1;
		}
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	int		len;

	stack2 = NULL;
	stack1 = stack_fillin(argc, argv);
	if (!(stack1))
	{
		write(1, "error", 6);
		return (0);
	}
	len = stack_len(stack1);
	if (len == 1)
		return (0);
	else if (len == 2 && stack1->num > stack1->next->num)
		sort_3_sa(&stack1);
	else if (len == 3)
		sort_3(&stack1);
	else if (len == 4)
		sort_4(stack1, stack2);
	else if (len == 5)
		sort_five(stack1, stack2);
	else if (len > 5)
		sort_big_stack(stack1, stack2);
	stack2 = NULL;
	return (0);
}