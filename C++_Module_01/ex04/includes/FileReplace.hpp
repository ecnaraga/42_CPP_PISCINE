/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:58:42 by galambey          #+#    #+#             */
/*   Updated: 2024/02/09 14:20:47 by galambey         ###   ########.fr       */
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
		std::ofstream	_fs_new;
		void	_replace(std::string &line, const std::string &s1, const std::string &s2);
		int		_open_filestream(void);
		
	public:
		FileReplace();
		~FileReplace();
		int	create_name(const std::string &f_src);
		void	write_to_f_dst(const std::string &s1, const std::string &s2, const char *f_src);
};

#endif