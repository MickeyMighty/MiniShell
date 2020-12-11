/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_excve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:28:46 by tidminta          #+#    #+#             */
/*   Updated: 2020/12/07 18:02:51 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		main(int argc, char *argv[], char *env[])
{
  if (argc > 1)
    if (execve(argv[1], argv + 1, env) == -1)
      perror("execve");

  printf("My pid is: %d\n", getpid());

  return 0;
}
