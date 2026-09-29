/**
 * Priority Queue class template
 * @author Duncan, Elaina Andrews
 * <pre>
 * File: PQueue.h
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
#include <vector>
#include <deque>
#include <functional>
#include "PQueueException.h"

#ifndef PQUEUE_H
#define PQUEUE_H

using namespace std;

/**
 * The definition of the PQueue ADT class
 * @param <T> - the PQueueu ADT data type 
 * @param <U> - the container type
*/
template<typename T,typename U = std::vector<T>> 
class PQueue
{
   private:   
   
   /**
    * The trichotomous greater than comparator for comparing
    * keys of this priority queue 
    */
   function<bool(const T&,const T&)> comp = nullptr;
   
   /**
    * Rebuild this priority queue from the 
    * specified index using a trickle up procedure
    * @param size the upperbound, exclusive, on 
    * the range of the underlying container to rebuild 
    */
   void heapifyUp(int index, int size);
   /**
    * Rebuild this priority queue from the 
    * specified index using a trickle down procedure
    * @param size the upperbound, exclusive, on 
    * the range of the underlying container to rebuild 
    */   
   void heapifyDown(int index, int size);

   /**
    * The data container
    */
   U container;
   
   
   public:
   /**
    * Constructs an empty max-priority queue
    */
   PQueue();
   
   /**
    * Creates an empty priority queue 
    * @param fn a comparator function used in ordering
    * the keys in this priority queue; if fn(a,b) is true,
    * then a goes above b in the priority queue
    */
   PQueue(function<bool (const T&,const T&)> fn);
	
   /**
    * destructor - returns the priority queue memory to the system
    */
   ~PQueue();
   
   /**
    * Copy constructor; clones the specified priority queue
    * @param the priority queue to clone	
    */
   PQueue(const PQueue<T,U>& other);
 
   /**
    * Moves constructor; creates a copy of this priority queue;
    * the specified priority queue is then made empty
    * @param other priority queue to move
    */
   PQueue(PQueue<T,U>&& other) noexcept;   

   /**
    * copy assignment operator
    * @param other a PQueue
    * @return a pointer to a priority queue that is
    * equivalent to the original contents of the specified priority queue.
    */
   PQueue<T,U>& operator=(const PQueue<T,U>& other);  
   
   /**
    * Move assignment operator
    * @param other a priority queue
    * @return a pointer to a priority queue that is
    * equivalent to the original contents of the specified priority queue.
    */
   PQueue<T,U>& operator=(PQueue<T,U>&& other) noexcept;   

   /**
    * Determines whether the priority queue is empty.
    * @return this function returns true if the priority queue is empty
    * otherwise, it returns false if the priority queue contains at least one node.
    */
   bool empty() const;	
   /**
    * Inserts an item into the priority queue.
    * @param item the value to be inserted.
    */
  void push(T item);	
   /**
    * Returns the item at the top of a non-empty priority queue or generates
    * an exception if the priority queue is empty.
    * @return item at the top of the priority queue.
    * @throws PQueueException when this priority queue is empty
    */
   const T& top() const;

   /**
    * Deletes the top-most item from the priority queue.
    * @throws PQueueExceptionException when this priority queue is empty.
    */
   void pop();
	
   /**
    * Gives the size of this priority queue.
    * @return the size of the priority queue
    */
   int size() const;
   
   /**
    * swap this priority queue with the specified priority queue 
    * @param other a priority queue
    */
   void swap(PQueue<T,U>& other);
};
#endif //PQUEUE_H