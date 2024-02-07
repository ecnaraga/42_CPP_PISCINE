/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:03:46 by galambey          #+#    #+#             */
/*   Updated: 2024/02/07 14:51:31 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileReplace.hpp"

int	main(int ac, char **av) {
	
	if (ac != 4) {
		std::cout << "Expected three parameters" << std::endl;
		return (1);
	}

	FileReplace f_new;
	
	if (f_new.create_name(av[1]))
		return (1);
	if (f_new.open_filestream(av[1]))
		return (1);
	f_new.write_to_f_dst(av[2], av[3]);
	
	return (0);
}
