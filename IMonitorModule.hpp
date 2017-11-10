/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaplyar <akaplyar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:36:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/10 16:36:00 by akaplyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "ft_gkrellm.h"

class IMonitorModule {

public:

	IMonitorModule() {}

	virtual ~IMonitorModule() {}

	virtual void refresh() = 0;

private:

	IMonitorModule(const IMonitorModule &) {};

	IMonitorModule &operator=(const IMonitorModule &rhs);

};


#endif
