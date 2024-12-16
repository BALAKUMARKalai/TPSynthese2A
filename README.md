<ins>**ENSEASH - A Mini Shell in C**</ins>


<ins>**Introduction**</ins>


ENSEASH is a mini shell written in C that allows users to execute simple commands with
features such as:

   •   Displaying a custom prompt.
   •   Executing commands using child processes.
   •   Measuring command execution time.
   •   Managing specific commands (like exit).

This project provides multiple progressive versions, each adding new functionalities to the
shell.




<ins>**Features by Question**</ins>



<ins>Question 1: Basic ENSEASH Shell</ins>  

   •   Displays a welcome message.  
   •   Displays a custom prompt enseash %.  
   •   Reads and executes simple commands.  
   •   Supports the exit command to exit the shell.  
   •   Measures and displays the execution time of a command with an execution status
       (exit code or signal).  
           

<ins>Question 2: Predefined Commands</ins>  

   •   Added the fortune command to display a random quote (uses /usr/games/fortune).  
   •   Added the ls command to list directory contents.  
   •   Unrecognized commands display an appropriate error message.  

<ins>Question 3: Managing exit</ins>  

   •   The exit command displays a goodbye message Au revoir! before exiting the shell.

 
<ins>Question 4: Executing Commands with Arguments</ins>  

   •   Supports commands with arguments (e.g., ls -l or grep main file.txt).
   •   Handles errors when commands are not found.

<ins>Question 5: Measuring Execution Time</ins>  

   •   Precisely measures the execution time of commands using clock_gettime.
   •   Displays execution time in milliseconds along with the status (exit code or signal).

<ins>Question 6 : Executing a complex command</ins>  
   Done with the question 5



<ins>**Compilation and Execution Instructions**</ins>  

   1. Compile the program:

gcc -o enseash enseash.c


   2. Run the shell:

./enseash


   3. Use the commands:
         a. Enter standard commands like ls, pwd, or fortune.
         b. To exit the shell, type exit.



Included Files
   1. enseash_q1.c: Implementation for Question 1 (basic features).  
   2. enseash_q2_q3.c: Implementation for Questions 2 and 3 (predefined commands and  
      managing exit).  
   3. enseash_q4.c: Implementation for Question 4 (support for command arguments).  
   4. enseash_q5.c: Implementation for Question 5 (precise execution time).
      
<ins>**Internal Functionality**</ins>

<ins>**Core Structure

   1. Reading Commands:
          a. Uses read to capture user input.
          b. Removes the newline character (using commande[n-1] = '\0';).
   2. Parsing Arguments:
          a. Splits the command using strtok to extract arguments.
   3. Execution:
          a. Creates a child process with fork.
          b. Executes the command in the child process using execvp or execlp.
          c. Handles errors if the command is not found.
   4. Measuring Execution Time (Q5):
          a. Measures time before and after execution using clock_gettime.
          b. Calculates and displays the duration.
   5. Exit Status:
          a. Uses wait to retrieve the child process status.
          b. Displays either the return code or the signal that interrupted the command.
      6. Receiving our own IP address

<ins>**Author**</ins>
This project was developed by BALAKUMAR Kalai and ANEMICHE Nassim.

