Utils:
    int         ft_give_index(t_node **begin)


> sort la size de la stack et reassign son index
> list size mais en plus on assign i a la variable index


Quicksort:
    int         ft_still_in(t_node **stack, int median)
> a chaque fois qu'on trouve une valeur mediane, tant qu'une valeur est
> inferieure a la mediane on boucle, rotate / push
    void        ft_global_phase_1(t_node **stack_a, t_node **stack_b, char **buffer)
> appelle phase1 et swap sur la stack a si necessaire en sortie de la boucle
    void        ft_phase_1(t_node **stack_a, t_node **stack_b, char **buffer)
> appelle phase2
> (phase1 trouve la median et apppel phase2)
    void        ft_phase_2(t_node **stack_a, t_node **stack_b, int median, char **buf)
> Quicksort



Senpai:
    int         ft_dist(int size, int index)
> dist entre index et la ou il en est
    void        ft_assign_senpai(t_node **stack_a, t_node **stack_b);
> pour chaque node de b on cherche le senpai de a et on les assign ensemble.

    int         ft_index(t_node **stack_a, t_node **stack_b)
> return la valeur du senpai (c'est un ft_find_senpai)
> Cf. `assign_senpai` boucle avec ft_index pour assigner le senpai a
> chaque node.
    int         ft_right_index(t_node **stack_a, int value)
> return l'index du senpai / (utilite generale: retrouve l'index d'une
> valeur), 'right index' = 'bon index'.
    int         ft_index_small(t_node **stack)
> trouve l'index de la valeur la plus petite


# ----------------------------------- cost:

Find cost:
> assigne le cost
    int ft_dist(int size, int index) {
        int distance;
        distance = 1;
        if (size % 2 == 0)
        {
            if (index > size / 2)
                distance = size - index + 1;
            else
                distance = index + 1;
        }
        else
        {
            if (index > size / 2)
                distance = size - index + 1;
            else if (index == size / 2)
                distance = size - index;
            else
                distance = index + 1;
        }
        return (distance);
    }

    int ft_same_down(int index_a, int index_b, int size_a, int size_b)
    {
        if (index_a > size_a / 2 && index_b > size_b / 2)
            return (1);
        else if (index_a <= size_a / 2 && index_b <= size_b / 2)
            return (1);
        else
            return (0);
    }

    int ft_find_cost(int index_a, int index_b, int sz_a, int sz_b)
    {
        int cost;
        if (ft_same_down(index_a, index_b, sz_a, sz_b))
        {
            if (ft_dist(sz_a, index_a) > ft_dist(sz_b, index_b))
                cost = ft_dist(sz_a, index_a);
            else
                cost = ft_dist(sz_b, index_b);
        }
        else
            cost = ft_dist(sz_a, index_a) + ft_dist(sz_b, index_b) - 1;
        return (cost);
    }


Give cost:
> calcul le cost
    int ft_give_index(t_node **begin)
    {
        int     i;
        t_node  *tmp;
        i = 0;
        tmp = (*begin);
        if (!(*begin))
            return (0);
        while (tmp->next != NULL && tmp != NULL)
        {
            tmp->index = i;
            i++;
            tmp = tmp->next;
        }
        tmp->index = i;
        return (i + 1);
    }

    void    ft_give_cost(t_node **stack_a, t_node **stack_b)
    {
        t_node  *a;
        t_node  *b;
        int     sz_b;
        int     sz_a;
        sz_a = ft_give_index(stack_a);
        sz_b = ft_give_index(stack_b);
        ft_assign_senpai(stack_a, stack_b);
        b = (*stack_b);
        ft_give_index(&b);
        while (b != NULL)
        {
            a = (*stack_a);
            while (a != NULL)
            {
                if (a->value == b->senpai)
                    b->cost = ft_find_cost(a->index, b->index, sz_a, sz_b);
                a = a->next;
            }
            b = b->next;
        }
    }

# ----------------------------------- best cost:

    int ft_find_cheap(t_node *stack)
    {
        t_node  *tmp;
        int     cost;
        int     index;

        index = stack->index;
        cost = stack->cost;
        tmp = stack;
        while (tmp != NULL)
        {
            if (tmp->cost < cost)
            {
                index = tmp->index;
                cost = tmp->cost;
            }
            tmp = tmp->next;
        }
        return (index);
    }
> recupere le cost le plus interessant (si 2 coute le meme il prend le
> premier)
    static int  ft_find_cheap_value(t_node *stack)
    {
        t_node  *tmp;

        tmp = stack;
        while (tmp->index != ft_find_cheap(stack))
            tmp = tmp->next;
        return (tmp->value);
    }
> cherche val la moins chere

> trouve l'index du senpai qui correspond a cheapest value
    static int  ft_cheapest_senpai(t_node *stack)
    {
        t_node  *tmp;

        tmp = stack;
        while (tmp->index != ft_find_cheap(stack))
            tmp = tmp->next;
        return (tmp->senpai);
    }

> return l'index
    static int  ft_index_senpai(t_node *stack_a, t_node *stack_b)
    {
        t_node  *tmp;

        tmp = stack_a;
        while (tmp->value != ft_cheapest_senpai(stack_b))
            tmp = tmp->next;
        return (tmp->index);
    }


> (appel les costs en boucle entre 2 assignation)
> deplace le cheap et l'**envoi dans la stack b** (fonction en boucle: on
> a les valeurs que l'on veut en haut de a et de b, l'index donne dans
> quel sens on rotate, on a les cheapest et senpai correspondant =
> condition pour push remplit, si index est > que la stack on monte ou
> on descend...)

Part of move_cheap
    static void ft_move_a(t_data *data)
    {
        int size_a;

        size_a = ft_give_index(stack_a);
        if (ft_index_senpai(stack_a, stack_b) > size_a / 2)
            ft_rev_rotate_a(stack_a, 'a');
        else if (ft_index_senpai(stack_a, stack_b) <= size_a / 2)
            ft_rotate_a(stack_a, 'a');
    }

    void        ft_move_cheap(t_data *data)
    {
        int cheap_value;
        int senpai;
        int index_cheap;

        cheap_value = ft_find_cheap_value(data->stack_b);
        senpai = ft_cheapest_senpai(data->stack_b);
        index_cheap = ft_find_cheap(data->stack_b);
        while (data->stack_b->content != cheap_value || data->stack_a->content != senpai)
        {
            if (data->stack_b->content != cheap_value)
            {
                if (index_cheap > ft_give_index(data->stack_b) / 2)
                    ft_rev_rotate_b(data->stack_b, 'b');
                else if (index_cheap <= ft_give_index(data->stack_b) / 2)
                    ft_rotate_b(data->stack_b, 'b');
            }
            if (data->stack_a->content != senpai)
                ft_move_a(data->stack_a, data->stack_b, 'a');
            if (data->stack_b->content == cheap_value && data->stack_a->content == senpai)
                break ;
        }
        ft_push_a(data->stack_a, data->stack_b, 'a');
    }


# ------------------------

    static void ft_move_a(t_node **stack_a, t_node **stack_b, char **buffer)
> part of move_cheap
    int         ft_issort(t_node **stack)
> check
    void        ft_sort_small(t_node **stack_a, t_node **stack_b, char **buf)
    void        ft_sort3(t_node **stack, char **buf)
> small values 3 to 5 hardcode

Garbage:
    static int  ft_invert(t_node **stack)
> check si on doit swap ou pas (cas particulier apres le quicksort)
    int         ft_is_smallest(t_node **stack)
> assign une valeur arbitraire de comparaison a une variable
    int         ft_is_highest(t_node **stack_a)
> assign une valeur arbitraire de comparaison a une variable


main.c
    if (ft_issort(&stack_a))
        return (ft_exit(&stack_a), 0);
