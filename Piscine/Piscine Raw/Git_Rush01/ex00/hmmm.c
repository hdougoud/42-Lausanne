#include <unistd.h>
#include <stdio.h>

int get_col_up(int col, char **argv)
{
	return(argv[1][col * 2] - 48);
}

int get_col_down(int col, char **argv)
{
	return(argv[1][8 + col * 2] - 48);
}

int get_row_left(int row, char **argv)
{
	return(argv[1][16 + row * 2] - 48);
}

int get_row_right(int row, char **argv)
{
	return(argv[1][24 + row * 2] - 48);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void display_error()
{
	write(1, "Error\n", 6);
}

void show_solution(int map[4][4])
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			ft_putchar(map[j][i] + 48);
			if(j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int check_args(char argc, char **argv)
{
	int i;

	if(argc != 2)
	{
		display_error();
		return (1);
	}
	i = 0;
	while(argv[1][i])
	{
		if(!(argv[1][i] == ' ' || (argv[1][i] >= '1' && argv[1][i] <= '4')))
		{
			display_error();
			return (1);
		}
		i++;
	}
	if(i != 31)
	{
		display_error();
		return (1);
	}
	return (0);
}

int is_valid(int map[4][4], int col, int row, int val)
{
	int i;
	int j;
	int count;

	i = 0;
	while(i < 4)
	{
		if(map[i][row] == val && i != col)
			return (0);
		i++;
	}
	i = 0;
	while(i < 4)
	{
		if(map[col][i] == val && i != row)
			return (0);
		i++;
	}
	i = 0;
	j = 1;
	count = 1;
	while(i < row && j < row)
	{
		if(map[col][i + j] > map[col][i])
		{
			count++;
			i++;
		}
		else
			j++;
	}
	printf("%d\n\n", count);
	if(count > 2)
	{
		return (0);
	}
	return (1);
}

// int compare_boxes(int map[4][4], int col, int row, int col2, int row2)
// {

//     if(map[col2][row2] - map[col][row] > 0)
//         return (1);
//     else
//         compare_boxes(map, col, row, col2, row2 + 1);
//     return (0);
// }


int place_box(int map[4][4], int col, int row, int val)
{
	if(col > 3)
	{
		show_solution(map);
		return (1);
	}
	while(val <= 4)
	{
		if (is_valid(map, col, row, val))
		{
			map[col][row] = val;
			show_solution(map);
			printf("\n");
			if(row == 3)
			{
				if(place_box(map, col + 1, 0, 1))
					return (1);
			}
			else
			{
				if(place_box(map, col, row + 1, 1))
					return (1);
			}
			map[col][row] = 0;
		}
		val++;
	}
	return (0);
}

void initialize_map(int map[4][4])
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
}


int main(int argc, char **argv)
{
	int map[4][4];

	if(check_args(argc, argv))
		return (0);
	initialize_map(map);
	if(!place_box(map, 0, 0, 1))
		display_error();
}