# Binary-Search-Tree :deciduous_tree: in C
This is a homework assignment for Computer Architecture CS 3432. Implement a Binary Search Tree in C. I added a hint of creativity to the description of the homework assignment.

# Description 
Electric Fetus, a music store located in Minneapolis, is in need for a employee system. The system requires the ability for the Manager to hire, fire and view employees. The only condition is that the current system Electric Fetus has is extremely slow, linear time. They are in need for a faster system.

What was the hardest part?
  > I suppose understanding pointers, headers and the Makefile. This was actually my second C program, so the learning curve appeared steep at first, but after some time I felt like I got the hang of it. It took me about 7 days or about 23 hours to complete this assignment. 
  
# About the program 
A brief description is the system needs to somehow store data for employee information. This data will contain first and last names of employees currently working at Electric Fetus Music Store - [For example](https://github.com/utep-2017-spr-arch1/project-1-personnel-management-oiricaud/blob/master/Binary-Search-Tree/ListOfEmployees.txt). The manager will be able to either hire or fire employees through a user interface.
 
> The [main.c](https://github.com/utep-2017-spr-arch1/project-1-personnel-management-oiricaud/blob/master/Binary-Search-Tree/main.c) contains the code where the manager is be able to 
      
      Use the system
      read the list of employees
      write inside the text file  
      create a binary search tree from the list of employees file 
      remove Employees and update the list of employees
      quit system
   
> The [bstHeader.h](https://github.com/utep-2017-spr-arch1/project-1-personnel-management-oiricaud/blob/master/Binary-Search-Tree/bstHeader.h) contains the Binary Search Tree code. 
   
     create nodes
     insert nodes
     remove nodes
     print tree pretty

### The Actual Project Description

> Attention students,

  > You’ve been recruited by ACME Solutions to help with developing a prototype for their new personnel management system.  Each of you will develop an implementation for the core functionality of the system along with a few additional features to demonstrate that it is operating correctly.  

> Github links to obtain the following will be distributed via the course mailing list. 
 > * an empty repository to fill with your lab
  
 > * a repository initialized with demo code (see below) 


### Requirements

> Your implementation should aim to accomplish the following:

    Store the names of all the employees in the company.
> * This data should be structured using a binary search tree..

    Provide a simple user interface so that a user may:
> * Add a new employee name
> * Remove an employee name
> * List all employee names

    Read and write employee names to and from a file. 
> * in a manner that preserves the BST's structure.
  
> Your source code should be logical, well commented, and include a readme file on how to operate the program.  You may collaborate with each other; however, if you obtain a piece of code from an outside source (i.e. anything not written by you) that performs anything more than a trivial mathematical expression, you must document where you found it.  

### Due Date and Grading Criteria
  > You will demo your lab to the TA during the following week.  
  Expect to be asked to checkout your project from your rep, compile it, explain how your code works and be able to perform a live modification.  Your will be evaluated based on the following criteria:

> * Tools (efficiently utilize bash, emacs, make, the compiler, and git)
> * Written Communication (appropriate documentation)
> * Mature Programming (proper code hygiene, appropriate algorithms, modularization, header files)
> * Variable Allocation (appropriate use of variables, scope, allocation)
> * Subroutine Linkage & Separate Compilation 

> Please refer to the Grading and Course Learning Outcomes webpage for an in depth explanation of the grading criteria.

### Getting started: Linked List Demo

We have provided a [linked list demo](https://github.com/utep-2017-spr-arch1/project-1-personnel-management-oiricaud/tree/master/Arch1-Linked-List-Demo) to help enure that you are familiar with pointers, structures, and what's expected of a "professional" code delivery.  We encourage you to examine it carefully.

Its contents are described in a README.  That readme also suggests a few practice problems that you should consider attempting prior to starting this lab.

Pseudocode
=========

This was written the first & second day when I started the project.

Searching
> Before we can insert or delete employees, we must first find out if there are any employee that belong to the Electric Fetus music store. If there is an instance where all employees have been terminated, our system will notify our client that employees do not exist, and suggest hiring a few people. There could also be an instance where Electric Fetus music store has many employees. If we happen to be searching for an employee and he/she is found we can either terminate that employee or hire an employee. 
   
Insertion 
> There are only two cases where we can insert, that is either the left or right subtree and do nothing else for the alternative case. 
    
Deletion
> To delete an employee we must figure out where the employee is located in the binary search tree structure. If the employee is the root then we must check if the BST has a left subtree if it does we must travese down the left subtree and find the right most child. If we happen to have an empty left subrtree then simply do a swap with the right subtree. 

# Resources 
*Ideas are seperated from the human mind. Ideas are products of mental activity. Windley introduced the Binary Search Tree in the 1960's along with Booth and Colin. All credit goes to these great individuals. Please view my [resources-page](https://github.com/utep-2017-spr-arch1/project-1-personnel-management-oiricaud/blob/master/Binary-Search-Tree/References.md) for detailed information.*
