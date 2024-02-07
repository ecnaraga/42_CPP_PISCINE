/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:55:33 by galambey          #+#    #+#             */
/*   Updated: 2024/02/07 18:42:20 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileReplace.hpp"

FileReplace::FileReplace(void) {
	
}

FileReplace::~FileReplace(void) {
	
	delete [] this->_f_dst;
}

/* a la place de la fonction replace de la class string:: */
void	FileReplace::_ft_modif_line(std::string &line, const std::string &s1, const std::string &s2) {
	
	if (!s1.empty() && s1 != s2) {
		std::size_t len = s1.length();
		std::string tmp;
		std::string tmp2;
		while (s1 != s2)
		{
			std::size_t found = line.find(s1);
			if (found!=std::string::npos) {
				tmp2 = line.substr(0, found);
				tmp += tmp2;
				tmp += s2;
				line = line.substr(found + len);
			}
			else {
				if (!line.empty())
					tmp += line;
				line = tmp;				
				break;
			}
		}
	}
}

int FileReplace::create_name(const std::string &f_src) {
	
	std::string		tmp;

	tmp = f_src;
	tmp.append(".replace"); // Concatene s avec la string passee en parametre
	// tmp = f_src + ".replace" // Autre facon
	
	size_t	len = tmp.length();
	this->_f_dst = new (std::nothrow) char[len + 1]; // METTRE SECU
	if (!this->_f_dst)
		return (1);
	for (size_t i = 0; i < len; i++) {
		this->_f_dst[i] = tmp[i];
		if (i + 1 == len)
			this->_f_dst[i + 1] = '\0';
	}
	return (0);
}

int	FileReplace::open_filestream(const char *f_src) {
	
	/* Ouverture du <filename> */
	this->_fs_old.open(f_src, std::ios_base::in); // ouvre le fichier en lecture
	if (!this->_fs_old.is_open()) {
		std::cout << "Failed to open \"" << f_src << "\"" << std::endl;
		return (1);
	}
	
	/* Creation et ouverture du <filename>.replace */
	this->_fs_new.open(this->_f_dst, std::ios_base::out); // ouvre le fichier en ecriture et le cree s'il n existe pas
	if (!this->_fs_new.is_open()) {
		std::cout << "Failed to open \"" << this->_f_dst << "\"" << std::endl;
		this->_fs_old.close();
		return (1);
	}
	return (0);
}

void	FileReplace::write_to_f_dst(const std::string &s1, const std::string &s2) {
	
	std::string	line;
	int i = 0;
	while (1) {
		line = "";
		if (!getline(this->_fs_old, line)) // secu si pas arrive a la fin du fichier
			break;
		if (i > 0)
			this->_fs_new << std::endl; // Pour ecrire dans le file associe au file stream
		this->_ft_modif_line(line, s1, s2);
		this->_fs_new << line;
		i++;
	}
	this->_fs_old.close();
	this->_fs_new.close();
}
