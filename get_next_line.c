/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eraynald <eraynald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:12:29 by eraynald          #+#    #+#             */
/*   Updated: 2021/11/13 21:31:17 by eraynald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
#define BUFFER_SIZE 9

void	write_s(char *str)
{
	while (*str)
		write(1 , &*str++, 1);
}

char	*copy_from_mem(char *mem, char *e)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (mem[0] == '\0')
		return (NULL);
	while (mem[i] != '\n')
		i++;
	i++;
	e = (char *)malloc(sizeof(char) * (i + 1));
	if (e == NULL)
		return (NULL);
	while (j < i)
	{
		e[j] = mem[j];
		j++;
	}
	e[i] = '\0';
	return (e);
}

char	*delite_from_mem(char *mem)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (mem[0] == '\0')
		return (NULL);
	while (mem[i] != '\n')
		i++;
	while (mem[i + j + 1])
	{
		mem[j] = mem[i + j + 1];
		j++;
	}
	mem[j] = '\0';
	if (mem[0] == '\0')
		return (NULL);
	return (mem);
}

// int	buffer_checker(char *buffer)
// {
// 	if (!buffer)
// 		return (0);
// 	while (*buffer)
// 	{
// 		if (*buffer == '\n')
// 			return (1);
// 		buffer++;
// 	}
// 	return (0);
// }

char	*obed_string(char *mem, char *buffer)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	if (mem)
		while (mem[i])
			i++;
	while (buffer[j])
		j++;
	p = (char *)malloc(sizeof(char) * (i + j + 1));
	if (p == NULL)
		return (NULL);
	p[i + j] = '\0';
	i = -1;
	j = 0;
	if (mem)
		while (mem[j])
		{
			p[j] = mem[j];
			j++;
		}
	while (buffer[++i])
		p[j + i] = buffer[i];
	mem = p;
	free (p);
	return (mem);
}

// char	*read_str_in_buffer(int fd, int buffer_size, char *mem)
// {
// 	int		ret;
// 	char	*buffer;
// 	buffer = (char*)malloc(sizeof(char)*buffer_size);
// 	if (buffer == NULL)
// 		return (NULL);
// 	ret = 0;
// 	ret = read(fd, buffer, buffer_size);
// 	if (ret == 0)
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	buffer[ret] = '\0';
// 	if (buffer_checker(buffer) && mem[0] == '\0')
// 		mem = buffer;
// 	else
// 	{
// 		mem = obed_string(mem, buffer);
// 		if (!buffer_checker(mem))
// 			mem = read_str_in_buffer(fd, buffer_size, mem);
// 	}
// 	free(buffer);
// 	return (mem);
// }

int	mem_checker(char *mem)
{
	if (mem)
		while (*mem)
			{
				if (*mem == '\n')
					return (0);
				mem++;
			}
	return (1);
}

char	*read_str(int fd, int buffer_size, char *mem)
{
	int		ret;
	char	*buffer;

	buffer = (char*)malloc(sizeof(char)*buffer_size);
	if (buffer == NULL)
		return (NULL);
	while (mem_checker(mem))
	{
		ret = read(fd, buffer, buffer_size);
		if (ret == 0 && !mem)
			return (mem);
		if (ret == 0)
			return (NULL);
		mem = obed_string(mem, buffer);
	}
	//free(buffer);
	return (mem);
}

char	*get_next_line(int fd)
{
	char		*e;
	static char	*mem;

	if (fd < 0)
		return (NULL);
	if (mem_checker(mem))
	{
		mem = read_str(fd, BUFFER_SIZE, mem);
		if (mem == NULL)
			return (NULL);
	}
	e = (char*)malloc(sizeof(char*));
	if (e == NULL)
		return (NULL);
	e = copy_from_mem(mem, e);
	mem = delite_from_mem(mem);
	return (e);
}

int	main()
{
	int		fd;
	char	*e;
	int	q;
	q = 0;

	if((fd =open("hello.txt", O_RDONLY)) == -1)
		write(1,"Cant read file.\n",18);
	else
	{
		while (1)
		{
			e=get_next_line(fd);
			if (e == NULL)
			{
				write(1,"(NULL)\n",7);
				break ;
			}
			write_s(e);
			q++;
		}
	}
	//write(1,"\n\n",2);
	close(fd);
	return (0);
}
