/*
** malloc.h for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 18:41:24 2017 DarKmarK
** Last update Mon Jan 30 16:54:54 2017 pierre.peixoto
*/

#ifndef MALLOC_H
# define MALLOC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE_META_DATA	sizeof(struct s_meta_data)//faire static passetr au puissance de 4ateur
#define PAGE_SIZE	getpagesize()//faire static passetr au puissance de 4ateur

/*
** Structures
*/
typedef struct __attribute__((__packed__))	s_meta_data
{
  struct s_meta_data				*next;
  struct s_meta_data				*prev;
  size_t					size;
  bool						is_free;
}						t_meta_data;

/*
** Static globals
*/
static t_meta_data	*start = NULL;
static void		*end = 0;

/*
 * FREE
 */
void		my_free(void *ptr);

/*
 * TOOLS
 */
void		show_alloc_mem(void);

/*
 * MALLOC
 */
t_meta_data	*alloc_block_end(t_meta_data *prev, size_t size);
t_meta_data	*go_next(t_meta_data *block);
t_meta_data	*found_space(size_t size);
void		*alloc(t_meta_data *block, size_t size);
void		*my_malloc(size_t size);

#endif
