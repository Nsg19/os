Ques. Design a scheduler that can schedule the processes arriving system at periodical intervals. Every process is assigned with a fixed time slice t milliseconds. If it is not able to complete its execution within the assigned time quantum, then automated timer generates an interrupt. The scheduler will select the next process in the queue and dispatcher dispatches the process to processor for execution. Compute the total time for which processes were in the queue waiting for the processor. Take the input for CPU burst, arrival time and time quantum from the user.

Ans. 1. First declare and initialize the array of burst time, arrival time, and process.
     2. Create the two queue for insertion and deletion.
     3. Sort the array of burst time, arrival time and process on the basis of arrival time in the increasing order.
     4. Insert the process index in the queue and remove from the queue and apply Round Robin Algorithm.
     5. Calculate waiting time:
                  Waiting time= Completion time - Burst time - arrival time
