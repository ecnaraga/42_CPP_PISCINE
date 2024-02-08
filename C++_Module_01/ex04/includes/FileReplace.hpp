/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:58:42 by galambey          #+#    #+#             */
/*   Updated: 2024/02/08 18:26:26 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACE_HPP
# define FILEREPLACE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <new>

class FileReplace {
	
	private:
		char* _f_dst;
		std::fstream	_fs_old; // file stream > equivalent des fd en C
		std::fstream	_fs_new;
		void	_ft_modif_line(std::string &line, const std::string &s1, const std::string &s2);
	public:
		FileReplace();
		~FileReplace();
		int	create_name(const std::string &f_src);
		int		open_filestream(const char *f_src);
		void	write_to_f_dst(const std::string &s1, const std::string &s2);
};

#endif