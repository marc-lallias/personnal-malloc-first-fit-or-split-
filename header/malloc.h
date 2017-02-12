/*
** malloc.h for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 18:41:24 2017 DarKmarK
** Last update Sun Feb 12 11:24:36 2017 pierre.peixoto
*/

#ifndef MALLOC_H
# define MALLOC_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

#define SIZE_META_DATA	sizeof(struct s_meta_data)
#define PAGE_SIZE	getpagesize()

/*
** Structures
*/
typedef struct					s_meta_data
{
  struct s_meta_data				*next;
  struct s_meta_data				*prev;
  size_t					size;
  bool						is_free;
  bool						page_begin;
}						t_meta_data;

/*
** Static globals
*/
extern t_meta_data	*start;
extern pthread_mutex_t	mutex;

/*
 * MALLOC
 */
void		*my_malloc(size_t size);

/*
 * FREE
 */
void		my_free(void *ptr);

/*
** REALLOC
*/
void		*my_realloc(void *ptr, size_t size);

/*
 * TOOLS
 */
int		my_put_str(const char *str);
void		my_put_nbr(const unsigned int nb);
void		show_alloc_mem(void);

/*
 * MALLOC
 */
void		*malloc(size_t size);

/*
 * FREE
 */
void		free(void *ptr);

/*
** REALLOC
*/
void		*realloc(void *ptr, size_t size);

/*
** CALLOC
*/
void		*calloc(size_t nelem, size_t elsize);

#endif /* !MALLOC_H_ */
