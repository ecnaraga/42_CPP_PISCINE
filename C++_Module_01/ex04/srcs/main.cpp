/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:03:46 by galambey          #+#    #+#             */
/*   Updated: 2024/02/06 17:34:22 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/* a la place de la fonction replace de la class string:: */
void	ft_modif_line(std::string &line, const std::string &s1, const std::string &s2) {
	
	if (!s1.empty() && !s2.empty() && s1 != s2) {
		std::size_t len = s1.length();
		std::string tmp;
		while (s1 != s2)
		{
			std::size_t found = line.find(s1);
			if (found!=std::string::npos) {
				tmp = line.substr(0, found);
				tmp += s2;
				tmp += line.substr(found + len); // Cree une substring depuis l index found + len jusqu a la fin de la string
				line = tmp;
			}
			else
				break;
		}
	}
}

void	create_f_dst(std::string &f_dst, const std::string &f_src) {
	
	f_dst = f_src;
	f_dst.append(".replace"); // Concatene s avec la string passee en parametre
	// f_dst = f_src + ".replace" // Autre facon
}

int	open_filestream(std::fstream &fs_old, std::fstream &fs_new, const std::string &f_dst, const std::string &f_src) {
	
	/* Ouverture du <filename> */
	fs_old.open(f_src, std::ios_base::in); // ouvre le fichier en lecture
	if (!fs_old.is_open()) {
		std::cout << "Failed to open \"" << f_src << "\"" << std::endl;
		return (0);
	}
	
	/* Creation et ouverture du <filename>.replace */
	fs_new.open(f_dst, std::ios_base::out); // ouvre le fichier en ecriture et le cree s'il n existe pas
	if (!fs_new.is_open()) {
		std::cout << "Failed to open \"" << f_dst << "\"" << std::endl;
		fs_old.close();
		return (0);
	}
	return (1);
}

void	write_to_f_dst(std::fstream &fs_old, std::fstream &fs_new, const std::string &s1, const std::string &s2) {
	
	std::string	line;
	int i = 0;
	while (1) {
		line = "";
		if (!getline(fs_old, line)) // secu si pas arrive a la fin du fichier
			break;
		if (i > 0)
			fs_new << std::endl; // Pour ecrire dans le file associe au file stream
		ft_modif_line(line, s1, s2);
		fs_new << line;
		i++;
	}
}

int	main(int ac, char **av) {
	
	if (ac != 4) {
		std::cout << "Expected three parameters" << std::endl;
		return (1);
	}

	std::string		f_dst;
	create_f_dst(f_dst, av[1]);
	
	std::fstream	fs_old; // file stream > equivalent des fd en C
	std::fstream	fs_new;
	if (!open_filestream(fs_old, fs_new, f_dst, av[1]))
		return (1);
	
	write_to_f_dst(fs_old, fs_new, av[2], av[3]);

	fs_old.close();
	fs_new.close();
	return (0);
}
