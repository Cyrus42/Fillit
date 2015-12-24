/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 16:15:27 by gahubaul          #+#    #+#             */
/*   Updated: 2015/12/10 16:15:30 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "../Libft/libft.h"
#define BUFF_SIZE 545
#include <stdio.h>

void  ft_error_exit(char *str)
{
  int i;
  char c;
  
  i = 0;
  while (str[i])
  {
	  c = str[i];
	  write(1, &c, 5);
	  i++;
  }
  write(1, "\n", 1);
  exit(0);
}
void	ft_print_buff(char *buff)
{
	int i;
	
	i = 0;
	while(buff[i])
	{
		write(1, &buff[i], 1);
		i++;
	}
}
int		ft_count_sharp(char *buff)
{
	int i;
	int counter;
	
	i = 0;
	counter = 0;
	while (buff[i])
	{
		if (buff[i] == '#')
			counter++;
		i++;		
	}
	if ((counter %4) != 0)
		return (0);
	return (1);
}

int		ft_count_char(char *buff)
{
	int i;
	int j;
	int new;
	
	i = 0;
	j = 0;
	new = 0;
	while (buff[i])
	{
		while (new < 5)
		{
			while (buff[i] != '\n')
			{
				j++;
				i++;
			}
			new++;
			i++;
		}
		if (j != 4)
			return (0);
		new = 0;
		j = 0;
		i++;
	}
	return (1);
}

void    ft_error(char *argv)
{
	char	buff[BUFF_SIZE + 1];
	char	**tab;
	int   	file_descriptor;
	int		read_result;
	int		tetri_nomber;
	int		counter;
	int   	x;
	int   	y;
	int   	k;
	int 	sharp;

	if ((file_descriptor = open(argv, O_RDONLY)) == -1)
		ft_error_exit("error1");
	if ((read_result = read(file_descriptor, buff, BUFF_SIZE)) == -1)
  		ft_error_exit("error2");
	buff[read_result] = '\0';
	if (close(file_descriptor) == -1)
		ft_error_exit("error3");
	if (((read_result + 1) % 21) != 0)
		ft_error_exit("error4");
	if (ft_count_sharp(buff) == 0)
		ft_error_exit("error5");
	if (ft_count_char(buff) == 0)
		ft_error_exit("error5");
	
	ft_print_buff(buff);
}

int     main(int argc, char **argv)
{ 
  if (argc == 2)
	ft_error(argv[1]);
  else if (argc != 2)
    ft_error_exit("erreur");
  return (0);
}
