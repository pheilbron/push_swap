void	print_all_stacks(t_ps_context *c)
{
	t_ps_node	*n;

	n = c->a->top;
	ft_printf("A\n");
	while (n)
	{
		ft_printf("%p\t%d\n", n, n->content);
		n = ps_stack_get_next(n);
	}
	n = c->b->top;
	ft_printf("B\n");
	while (n)
	{
		ft_printf("%p\t%d\n", n, n->content);
		n = ps_stack_get_next(n);
	}
	n = c->commands->top;
	ft_printf("Commands\n");
	while (n)
	{
		ft_printf("%p\t%d\n", n, n->content);
		n = ps_stack_get_next(n);
	}
}
