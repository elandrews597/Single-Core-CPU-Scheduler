/**
 * Models a process control block.
 * @author Duncan
 * <pre>
 * Date: 99-99-9999 
 * Course: csc 3102
 * Programming Project # 1
 * Instructor: Dr. Duncan
 * Note: DO NOT MODIFY THIS FILE
 * </pre>
 */
#include <string>
#include <iostream>
    
using namespace std;


class PCB
{
private:
    /**
     * the process ID
     */
    int pid;
    /**
     * the priority value of this process
     */
    int priority;
    /**
     * running status 
     */
    int running;
    /**
     * cycle during which this process was created
     */
    int arrived;
    /**
     * time this process will take to execute
     */
    int burst;
    /**
     * cycle during which this process begins executing
     */
    int start;
    /**
     * how long the process waits before it begins executing
     */
    int wait;    	
public:
   /**
    * Creates a simulated job with default values for its parameters.
    */
   PCB()
   {
      priority = 20;
      running = 0;
      arrived = 0;
      burst = 0;
   }

   /**
    * Creates a simulated job with the specified parameters.
    * @param iD the process id
    * @param pVal the priority value
    * @param run the running status
    * @param arr the arrival time
    * @param len the number of cycles this process takes to execute
    */
   PCB(int iD, int pVal, int run, int arr, int len)
   {  
      pid = iD;  
      priority = pVal;
      running = run;
      arrived = arr;
      burst = len; 
   }
   
   /**
    * Gives the ID of this job.
    * @return the process ID
    */
   int getPid() const
   {
      return pid;
   }
      
   /**
    * Gives the priority value of this process.
    * @return the priority value of this process
    */
   int getPriority() const
   {
      return priority;
   }
  
   /**
    * Indicates whether this process is executing..
    * @return the execution status of this process
    */
   bool isExecuting() const
   {  
      return running == 1;
   }
      
   /**
    * Sets the running status of this job.
    */
   void execute()
   {  
      running = 1;  
   }

   /**
    * Gives the cycle during which this process was creates
    * @return the cycle during which this process was created.
    */
   int getArrival() const
   {  
      return arrived;
   }  
      
   /**
    * Gives the number of cycles required to execute this process.
    * @return the number of cycles required to execute this process
    */
   int getBurst() const
   {  
      return burst;
   }  
      
   /**
    * Gives the cycle during which this process began executing.
    * @return the cycle during which this process began executing
    */
   int getStart() const
   {  
      return start;
   }  

   /**
    * Sets the cycle during which the process begins executing.
    * @param startCycle the cycle during which this process begins executing.
    */
   void setStart(int startCycle)
   {  
      start = startCycle;
   }  
      
   /**
    * Gives the number of cycles this process waited before executing.
    * @return  the number of cycles from the process creation to its execution
    */
   int getWait() const
   {  
      return wait;
   } 

   /**
    * Sets the wait time for this process
    * @param waitTime the number of cycles that this process waited
    */
   void setWait(int waitTime)
   {  
      wait = waitTime;
   }  

   /**
    * Determines whether two process control blocks are equal.
    * @param pcb1 a simulated process control block
	* @param pcb2 a simulated process control block	
	* @return true when the specified process control blocks 
	* are equal; otherwise, false.
	*/
   friend bool operator==(const PCB& pcb1, const PCB& pcb2);
   /**
    * Determines whether two process control blocks are not equal.
    * @param pcb1 a simulated process control block
	* @param pcb2 a simulated process control block	
	* @return true when the specified process control blocks 
	* are not equal; otherwise, false.
	*/   
   friend bool operator!=(const PCB& pcb1, const PCB& pcb2);
   /**
    * Determines whether the first process control block will
	* execute after the second.
    * @param pcb1 a simulated process control block
	* @param pcb2 a simulated process control block	
	* @return true when the first process control blocks 
	* will be executed after the second; otherwise, false.
	*/   
   friend bool operator>(const PCB& pcb1, const PCB& pcb2);
   /**
    * Determines whether the first process control block will
	* execute before the second.
    * @param pcb1 a simulated process control block
	* @param pcb2 a simulated process control block	
	* @return true when the first process control blocks 
	* will be executed before the second; otherwise, false.
	*/ 
   friend bool operator<(const PCB& pcb1, const PCB& pcb2);
   /**
    * Determines whether the first process control block will
	* execute after the second or is the same as the second.
    * @param pcb1 a simulated process control block
	* @param pcb2 a simulated process control block	
	* @return true when the first process control blocks 
	* will be executed after the second or is identical to
	* the second; otherwise, false.
	*/    
   friend bool operator>=(const PCB& pcb1, const PCB& pcb2);
   /**
    * Determines whether the first process control block will	
    * execute before the second or is the same as the second.
    * @param pcb1 a simulated process control block	
    * @param pcb2 a simulated process control block		
    * @return true when the first process control blocks 	
    * will be executed before the second or is identical to	
    * the second; otherwise, false.	
    */      
   friend bool operator<=(const PCB& pcb1, const PCB& pcb2);
};

bool operator==(const PCB& pcb1, const PCB& pcb2)
{ 
   return pcb1.priority == pcb2.priority;
}   

bool operator!=(const PCB& pcb1, const PCB& pcb2)
{   
   return !(pcb1 == pcb2);
}   

bool operator>(const PCB& pcb1, const PCB& pcb2)
{   
   if (pcb1.priority < pcb2.priority)
      return true;
   return false;
}   

bool operator<(const PCB& pcb1, const PCB& pcb2)
{   
   return (pcb1 != pcb2) && !(pcb1 > pcb2);
}   

bool operator<=(const PCB& pcb1, const PCB& pcb2)
{   
   return (pcb1 > pcb2) || (pcb1 == pcb2);
}   

bool operator>=(const PCB& pcb1, const PCB& pcb2)
{   
   return (pcb1 > pcb2) || (pcb1 == pcb2);
}   

