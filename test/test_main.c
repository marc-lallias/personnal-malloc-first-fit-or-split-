/*
** test_main.c for  in /home/darkmark/rendu/PSU_2016_malloc
** 
** Made by DarKmarK
** Login   <marc.lallias@epitech.eu>
** 
** Started on  Tue Jan 24 15:34:55 2017 DarKmarK
** Last update Wed Jan 25 16:14:07 2017 pierre.peixoto
*/

#include <stdlib.h>
#include <stdio.h>
#include "test_malloc.h"

int main()
{
  void *addr_main;
  const char addr_cstr[3] = { 'I','L',0 };
  char *addr_str;
  int *addr_int;

  addr_main = test_malloc(0);
  addr_str = test_malloc(3);
  addr_int = test_malloc(sizeof(int));
  *addr_int = 8;
  printf("main:%p<END>cstr:%p<END>addr_int:%p<END>str:%p<END>\n", addr_main, addr_cstr, addr_int, addr_str);
}
