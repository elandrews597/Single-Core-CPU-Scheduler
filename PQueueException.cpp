/**
 * The implementation file for functions of the PQueueException class
 * @author Duncan
 * @see PQueueException.h
 * Date: 99-99-99
 * Programming Project # 1
 * Course: csc 3102.001
 * Instructor: Dr. Duncan 
 *
 * DO NOT REMOVE THIS NOTICE (GNU GPL V2):
 * Contact Information: duncanw@lsu.edu
 * Copyright (c) 2026 William E. Duncan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/> 
 * <pre>
 */ 

#include "PQueueException.h"
#include <cstdlib>
#include <iostream>

PQueueException::PQueueException(const string& msg)
{
   message = msg;
}

PQueueException& PQueueException::operator=(const PQueueException& other)
{
	if (this != &other)
	{
		std::exchange(message,other.message);
	}
	return *this;
}

string PQueueException::what() const
{
   return message;
}