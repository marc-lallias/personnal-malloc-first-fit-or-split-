/*
** test_malloc.h for test_malloc in /home/peixot_a/Documents/pierre.peixoto@epitech.eu/perso/PSU_malloc
** 
** Made by pierre.peixoto
** Login   <pierre.peixoto@epitech.eu>
** 
** Started on  Wed Jan 25 11:38:31 2017 pierre.peixoto
** Last update Thu Jan 26 16:33:01 2017 pierre.peixoto
*/

#ifndef TEST_MALLOC_H_
# define TEST_MALLOC_H_

#include <unistd.h>
#include <stddef.h>
#include <sys/resource.h>
#include <string.h>
#include <stdbool.h>

typedef struct		s_mdata
{
  void			*addr;
  size_t		size;
  struct s_mdata	*next;
  bool			is_used;
}			t_mdata;

void	*test_malloc(size_t size);
void	*allocate_new_data(size_t size);

#endif /* !TEST_MALLOC_H_ */
