/**
 * The implementation file for functions of the parametric PQueue ADT class
 * @author Duncan, Elaina Andrews
 * @see PQueue.h, Car.h
 * <pre>
 * File: FleetOrganizer.cpp
 * Date: 09/29/2026
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

#include "PQueue.h"
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
   #include <sstream>
using namespace std;

template<typename T,typename U> 
void PQueue<T,U>::heapifyUp(int index, int size)
{
    while (index > 0) {
		int parent = (index - 1)/2;
	

		if (comp(container[index], container[parent])) {
		std::swap(container[index], container[parent]);
		index = parent;
	} else {
		break;
	}
}
}

template<typename T,typename U> 
void PQueue<T,U>::heapifyDown(int index, int size)
{
	while (true) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
	
	if (left >= size) {
		break;
		}

	int priorityChild = left;

	if (right < size && comp(container[right], container[priorityChild])) {
		priorityChild = right;
	}

	if (comp(container[priorityChild], container[index])){
		std::swap(container[priorityChild], container[index]);
		index = priorityChild;
		
	} else {
		break;
	}
	}


}

template<typename T,typename U> 
PQueue<T,U>::PQueue()
{
    comp = [](const T& a, const T& b) {
		return a > b;
		};
}

template<typename T,typename U> 
PQueue<T,U>::PQueue(function<bool (const T&,const T&)> fn)
{
	comp = fn;
}


template<typename T,typename U> 
PQueue<T,U>::~PQueue()
{
   container.clear();
}

template<typename T,typename U> 
PQueue<T,U>::PQueue(const PQueue<T,U>& other)
{
   copy((other.container).begin(), (other.container).end(), back_inserter(container));
   comp = other.comp;
}

template<typename T,typename U> 
PQueue<T,U>::PQueue(PQueue<T,U>&& other) noexcept
{
   other.comp = std::exchange(comp,other.comp);
   other.container = std::exchange(container,other.container);
}

template<typename T,typename U> 
PQueue<T,U>& PQueue<T,U>::operator=(const PQueue<T,U>& other)
{
	if (this != &other)
	{
		(*this).~PQueue();
		*this = PQueue(other);
	}
	return *this;
}

template<typename T,typename U> 
PQueue<T,U>& PQueue<T,U>::operator=(PQueue<T,U>&& other) noexcept
{
	if(this != &other)
	{
	    other.container = std::exchange(container,other.container);
	    other.comp = std::exchange(comp,other.comp);
    }
	return *this;
}

template<typename T,typename U> 
bool PQueue<T,U>::empty() const
{
	return container.size() == 0;
}

template<typename T,typename U> 
void PQueue<T,U>::push(T item)
{
	container.push_back(item);
	heapifyUp(container.size() - 1, container.size());
}

template<typename T,typename U> 
const T& PQueue<T,U>::top() const
{
	if (empty()) {
		throw PQueueException("Priority Queue is empty.");
	}
	return container[0];
}

template<typename T,typename U> 
void PQueue<T,U>::pop()
{
	if (empty()) {
		throw PQueueException("Priority Queue is empty");
	}
	container[0] = container[container.size() - 1];
	container.pop_back();
	if (!empty()){
		heapifyDown(0, container.size());
	}
}

template<typename T,typename U> 
int PQueue<T,U>::size() const
{
	return container.size();
}

template<typename T,typename U> 
void PQueue<T,U>::swap(PQueue<T,U>& other)
{
    std::swap(container, other.container);
	std::swap(comp, other.comp);
}
