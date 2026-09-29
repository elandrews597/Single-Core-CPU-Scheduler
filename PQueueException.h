/**
 * A customized exception class for reporting 
 * PQueue ADT excptions
 * @author Duncan
 * <pre>
 * File: PQueueException.h
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
 
 * </pre>
 */
 

#include <string>
#include <iostream>
#include <utility>

#ifndef PQUEUEEXCEPTION_H
#define PQUEUEEXCEPTION_H

using namespace std;

/**
* Definition of the a customized exception
* class for reporting PQueue exceptions
*/
class PQueueException
{
   private:
   /**
    * A description of why this exception occurs
    */
   string message;    
   public:
   /**
    * Creates an exception instance
    * @param msg - the message when this exception is thrown
    */
   PQueueException(const string& msg);
   
   /**
    * Overloaded copy assignment operator
    * @param other a reference to an object of this class
    * @return a reference to an object of this class
    */
   PQueueException& operator=(const PQueueException& other);
	
   /**
    * Gives a description of this exception
    * @return a description of why this exception was thrown
    */
   string what() const;
};
#endif //PQUEUEEXCEPTION_H