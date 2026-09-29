/**
 * A application to simulate a non-preemptive scheduler for a single-core CPU
 * using a heap-based implementation of a priority queue
 * @author William Duncan, Elaina Andrews
 * @see PQueue.h, PCB.h
 * <pre>
 * Date: 09-29-2026
 * Course: csc 3102
 * Programming Project # 1
 * Instructor: Dr. Duncan
 * File:SingleCoreScheduler.cpp
 * Usage: SingleCoreScheduler <number of cylces> <-R or -r> <probability of a  process being created per cycle>  or,
 *        SingleCoreScheduler <number of cylces> <-F or -f> <file name of file containing processes>,
 *        The simulator runs in either random (-R or -r) or file (-F or -f) mode
 * </pre>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "PQueue.h"
#include "PQueue.cpp"
#include "PCB.h"
// for precise decimal spaces
#include <iomanip>
// for time of day
#include <ctime>


using namespace std;
/**
 * Single-core processor with non-preemptive scheduling simulator
 * @param argc the number of command line arguments
 * @param argv an array of array of chanracters containing command line arguments
 * argv[0] - this file name
 * argv[1] - number of cyles to run the simulation
 * argv[2] - the mode: -r or -R for random mode and -f or -F for file mode
 * argv[3] - if the mode is random, this entry contains the probability that
 *           a process is created per cycle and if the simulator is running in
 *           file mode, this entry contains the name of the file containing the
 *           the simulated jobs. In file mode, each line of the input file is 
 *           in this format:
 * <process ID> <priority value> <cycle of process creation> <time required to execute>
 * @return exit_status
 */
int main(int argc, char** argv) 
{
   if (argc != 4)
   {
      cerr<<"Usage: SingleCoreScheduler <number of cylces> <-R or -r> <probability of a  process being created per cycle>  or "<<endl
          <<"       SingleCoreScheduler <number of cylces> <-F or -f> <file name of file containing processes>"<<endl;
      cerr<<"The simulator runs in either random (-R or -r) or file (-F or -f) mode."<<endl;
      exit(1);
   }
  srand(time(0));
  
  //Complete the implementation of this function  
   int cycles = atoi(argv[1]); 
   

   bool fileMode(argv[2][1] == 'F' || argv[2][1] == 'f');
   bool randomMode(argv[2][1] == 'R' || argv[2][1] == 'r');

   //Error messsage for if file mode or random mode is not used
   if (!fileMode && !randomMode) {
      cerr << "Invalid mode. Use -f/-F for file mode or -r/-R for random mode." << endl;
      exit(1);
   }

   ifstream input;

   if (argv[2][1] == 'F' || argv[2][1] == 'f') {
      input.open(argv[3]);

      if (!input.is_open()) {
         cerr << "Error. Unable to open file." << endl;
         exit(1);
      }
   }

   double propability = 0.0;

   if (randomMode) {
      propability = atof(argv[3]);
      
      if (propability < 0.01 || propability > 1.0) {
         cerr << "Error. Propability must be between 0.01 and 1.0." << endl;
         exit(1);
      }
   }

      //Ready queue and CPU
      PQueue<PCB> readyQ([](const PCB& a, const PCB& b) {

         if (a.getPriority() != b.getPriority()) {
         return a.getPriority() < b.getPriority();
            }
            return a.getArrival() < b.getArrival();
      });
      PCB currentJob;
      
      bool cpuBusy = false;

      //Information for the next job in the input cycle
      int pid, priority, arrival, burst;
      bool hasJob = false;

      // Burst time/Amount of cycles job takes to execute
      int executedCycles = 0;

      //initiates the total turn around time to use to calculate the average turnaround time
      int totalturnaroundTime = 0;

      // initiates the amount of terminated cycles so that it can be used to calculate the average
      // turnaround time
      int terminatedProcesses = 0;

      // initiates totalWaitTime to calculate average wait time
      int totalWaitTime = 0;

      // initiates total response time in order to calculate average response time
      int totalResponseTime = 0;

      // initiates amount of created processes to be used to calculate the total amount of created
      // processes.
      int createdProcesses = 0;

      // initiates total burst time in order to calculate throughput??
      int totalBurstTime = 0;


      if (fileMode) {
         //Read the first job
       if (input >> pid >> priority >> arrival >> burst) {
               hasJob = true;
            } else {
               hasJob = false;
            }
      }
      
            // Simulate each CPU cycle
             for (int cycle = 0; cycle < cycles; cycle++) {
                cout << "*** Cycle #: " << cycle << endl;
               // CPU Activity !!
               // If cpu is free and has a process waiting, give the cpu the highest priority process
               if (!cpuBusy && !readyQ.empty()) {

                  currentJob = readyQ.top();
                  readyQ.pop();

                  cpuBusy = true;
                  executedCycles = 0;

                  currentJob.execute();
                  currentJob.setStart(cycle);
                  currentJob.setWait(cycle - currentJob.getArrival());
                  }
               
               // if cpu is free and does not have a process waiting
               if (!cpuBusy && readyQ.empty()) {
               cout << "The CPU is idle." << endl;
               }
                  
               // if cpu has a process already
               if (cpuBusy) {
                  // has the process completed its burst?   
                     if (currentJob.getBurst() == executedCycles) {
                     cout << "Process #" << currentJob.getPid() << " has just terminated." << endl;
                     cpuBusy = false;

                     int exitTime = cycle;
                     int turnaroundTime = exitTime - currentJob.getArrival();

                     int responseTime = currentJob.getStart() - currentJob.getArrival();
                     totalResponseTime += responseTime;

                     // Update stats
                     totalturnaroundTime += turnaroundTime;
                     totalWaitTime += currentJob.getWait();
                     totalBurstTime +=currentJob.getBurst();
                     terminatedProcesses++;
                     
                     } else {
                     // Process executes for this cycle
                     cout << "Process #" << currentJob.getPid() << " is executing." << endl;
                     executedCycles++;
                     }
                  }
            
              

               if (fileMode){
                  // Process arrival
                  if (hasJob && arrival == cycle) {
                  //add the new job
                  PCB job(pid, priority, 0, arrival, burst);
                  readyQ.push(job);
                  createdProcesses++;

                  cout << "Adding job with pid #" << pid << " and priority " << priority <<
                  " and burst " << burst << "." << endl;

                  // Load next job from the file
                  if (input >> pid >> priority >> arrival >> burst) {
                  hasJob = true;
                  } else {
                  hasJob = false;
                  }
                  } else {
                  //no new job
                  cout << "No new job this cycle." << endl;
                     }
               }

               if (randomMode) {
                  double q = static_cast<double>(rand()) / RAND_MAX;

                  if (q <= propability) {
                     pid = createdProcesses + 1;
                     arrival = cycle;
                     priority = rand() % 40 -19;
                     burst = rand() % 100 + 1;
                     PCB job(pid, priority, 0, arrival, burst);
                     readyQ.push(job);
                     createdProcesses++;

                     cout << "Adding job with pid #" << pid << " and priority " << priority <<
                     " and burst " << burst << "." << endl;

                  } else {
                     cout << "No new job this cycle." << endl;
                  }
               }
            }
            // average calculations
            if (terminatedProcesses > 0) {
               double averageTurnaroundTime = static_cast<double>(totalturnaroundTime) / terminatedProcesses;
               double averageWaitTime = static_cast<double>(totalWaitTime) / terminatedProcesses;
               double averageResponseTime = static_cast<double>(totalResponseTime) / terminatedProcesses;
               double averageProcessesCreated = static_cast<double>(createdProcesses) / cycles;
               double throughput = static_cast<double>(totalBurstTime) / terminatedProcesses;

               
               cout << "The average number of process created per cycle is " << setprecision(16) << averageProcessesCreated << "." << endl;
               cout << "The throughput is " << setprecision(16) << throughput << " cycles." << endl;
               cout << "The average wait time per process is " << setprecision(17) << averageWaitTime << "." << endl;
            }
            
            if (fileMode) {
               input.close();
            }
   }


