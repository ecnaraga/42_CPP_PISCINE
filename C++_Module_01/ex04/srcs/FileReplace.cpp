/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:55:33 by galambey          #+#    #+#             */
/*   Updated: 2024/02/09 14:42:13 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FileReplace.hpp"

FileReplace::FileReplace(void) {
	
}

FileReplace::~FileReplace(void) {
	
	delete [] this->_f_dst;
}

/* SECOND WAY */
/* A la place de la fonction replace de la class string:: */
void	FileReplace::_replace(std::string &line, const std::string &s1, const std::string &s2) {
	
	if (!s1.empty() && s1 != s2) {
		std::size_t len1 = s1.length();
		std::size_t len2 = s2.length();
		std::size_t found = 0;
		while (1)
		{
			found = line.find(s1, found);
			if (found!=std::string::npos) {
				line.erase(found, len1);
				line.insert(found, s2);
				found += len2;
			}
			else
				break;
		}
	}
}

// /* FIRST WAY */
// /* A la place de la fonction replace de la class string:: */
// void	FileReplace::_replace(std::string &line, const std::string &s1, const std::string &s2) {
	
// 	if (!s1.empty() && s1 != s2) {
// 		std::size_t len = s1.length();
// 		std::string tmp;
// 		std::string tmp2;
// 		while (s1 != s2)
// 		{
// 			std::size_t found = line.find(s1);
// 			if (found!=std::string::npos) {
// 				tmp2 = line.substr(0, found);
// 				tmp += tmp2;
// 				tmp += s2;
// 				line = line.substr(found + len);
// 			}
// 			else {
// 				if (!line.empty())
// 					tmp += line;
// 				line = tmp;				
// 				break;
// 			}
// 		}
// 	}
// }

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

int	FileReplace::_open_filestream(void) {
	
	/* Creation et ouverture du <filename>.replace */
	this->_fs_new.open(this->_f_dst, std::ofstream::binary); // ouvre le fichier en ecriture et le cree s'il n existe pas
	// this->_fs_new.open(this->_f_dst, std::ios_base::out);  // IDEM
	if (!this->_fs_new.is_open()) {
		std::cout << "Failed to open \"" << this->_f_dst << "\"" << std::endl;
		return (1);
	}
	return (0);
}

/* UTILISATION DE GETLINE */
void	FileReplace::write_to_f_dst(const std::string &s1, const std::string &s2, const char *f_src) {
	
	std::ifstream fs_old (f_src, std::ifstream::binary);
	
	if (fs_old) {
		if (this->_open_filestream()) {
			fs_old.close();
			return ;
		}
		
		std::string line;
		getline(fs_old >> std::noskipws, line, '\0'); 	// Lit tous le fichier jusqu a la fin du fichier ou on rencontre le '\0'
														// ps : std::noskipws = Do not skip whitespaces != std::skipws = skip whitespaces
		this->_replace(line, s1, s2);
		this->_fs_new << line;
		
		fs_old.close();
		this->_fs_new.close();
	}
	else
		std::cout << "Failed to open \"" << f_src << "\"" << std::endl;
}

/* OTHER WAY : LECTURE DU FICHIER EN UTILISANT READ DE HERITE de ISTREAM */
// void	FileReplace::write_to_f_dst(const std::string &s1, const std::string &s2, const char *f_src) {
	
// 	std::ifstream fs_old (f_src, std::ifstream::binary);
	
// 	if (fs_old) {
// 		/* Pour caluler la taille du fd */
// 		fs_old.seekg(0, fs_old.end);
// 		int len = fs_old.tellg();
// 		fs_old.seekg (0, fs_old.beg);
		
// 		if (this->_open_filestream()) {
// 			fs_old.close();
// 			return ;
// 		}
		
// 		char *buffer = new char [len + 1];
// 		std::cout << len << std::endl;
// 		fs_old.read(buffer, len);
// 		buffer[len] = '\0';
		
// 		std::string	line = buffer;
// 		this->_replace(line, s1, s2);
// 		this->_fs_new << line;
// 		delete [] buffer;
		
// 		fs_old.close();
// 		this->_fs_new.close();
// 	}
// }
