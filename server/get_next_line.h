/*
** get_next_line.h for osef in /home/noel_q/rendu/CPE_2015_getnextline
** 
** Made by Quentin Noël
** Login   <noel_q@epitech.net>
** 
** Started on  Wed Jan  6 09:37:24 2016 Quentin Noël
** Last update Mon Jul 17 18:54:42 2017 baud
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE 1
# endif /* !READ_SIZE*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H */
