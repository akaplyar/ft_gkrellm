/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshakula <hshakula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:37:00 by akaplyar          #+#    #+#             */
/*   Updated: 2017/11/11 22:34:24 by hshakula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.hpp"


// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //

DateModule::DateModule(int height, Monitor &monitor) : AModule("Date") {
	int w, h;
	IMonitorDisplay *display;

	lines.push_back(new Line("Date", ""));
	this->height = static_cast<int>(lines.size() + 1);
	this->refresh();
	display = monitor.getDisplay();
	display->getMaxYX(h, w);
//	if ((h - height) < this->height) {
//		throw MyException("Can't fit data in window. Please increase height");
//	}
//	else if (w < width) {
//		throw MyException("Can't fit data in window. Please increase width");
//	}
	if (w > width)
		width = w;
	win = display->getWindowNum(this->height, this->width, height, 0);
}


// * DESTRUCTORS ************************************************************ //

DateModule::~DateModule() {}

// * OPERATORS ************************************************************** //

DateModule &DateModule::operator=(DateModule const &assign) {
	if (this != &assign) {}
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //

void DateModule::refresh() {
	time_t tim = time(NULL);
	tm *t = localtime(&tim);
	char str[80];

	strftime(str, 80, "[%F %X] ", t);
	lines[2]->setValue(str);
	width = lines[2]->getSize();
}

// * NESTED_CLASSES ********************************************************* //
