# Binary-Search-Tree
BST written in C. Let's see how fast I can write this. ~ It took me about 21 hours, much longer than I anticipated. 

Project Description
======

Attention students,

You’ve been recruited by ACME Solutions to help with developing a prototype for their new personnel management system.  Each of you will develop an implementation for the core functionality of the system along with a few additional features to demonstrate that it is operating correctly.  

Github links to obtain the following will be distributed via the course mailing list. 

- an empty repository to fill with your lab
- a repository initialized with demo code (see below) 


Requirements
============

Your implementation should aim to accomplish the following:

- Store the names of all the employees in the company.
  - This data should be structured using a binary search tree..

- Provide a simple user interface so that a user may:
  - Add a new employee name
  - Remove an employee name
  - List all employee names

- Read and write employee names to and from a file. 
  - in a manner that preserves the BST's structure.
  
Your source code should be logical, well commented, and include a readme file on how to operate the program.  You may collaborate with each other; however, if you obtain a piece of code from an outside source (i.e. anything not written by you) that performs anything more than a trivial mathematical expression, you must document where you found it.  

Due Date and Grading Criteria
=============================

You will demo your lab to the TA during the following week.  Expect to be asked to checkout your project from your rep, compile it, explain how your code works and be able to perform a live modification.  Your will be evaluated based on the following criteria:

- Tools (efficiently utilize bash, emacs, make, the compiler, and git)
- Written Communication (appropriate documentation)
- Mature Programming (proper code hygiene, appropriate algorithms, modularization, header files)
- Variable Allocation (appropriate use of variables, scope, allocation)
- Subroutine Linkage & Separate Compilation 

Please refer to the Grading and Course Learning Outcomes webpage for an in depth explanation of the grading criteria.

Getting started: Linked List Demo
=================================

We have provided a "linked list demo" to help enure that you are familiar with pointers, structures, and what's expected of a "professional" code delivery.  We encourage you to examine it carefully.

Its contents are described in a README.  That readme also suggests a few practice problems that you should consider attempting prior to starting this lab.

Resources 
=========

Pseudocode
=========

After reading the assignment and requirements, I realized it is very boring and dry. Lets make this lab a little more interesting. Let's call this company Electric Fetus, a music store located in Minneapolis that is in need for a new system. This system requires the ability for the user to create, remove and list employees. 

The following is information the client does not need to know. We will be implementing this task by following a Binary Search Tree structure. With a BST the average time to search, insert and removing employees is Big-O logn. 

Implementation of a B-Tree

 - Searching
    - Before we can insert or delete employees, we must first find out if there are any employee that belong to the Electric Fetus music store. If there is an instance where all employees have been terminated, our system will notify our client that employees do not exist, and suggest hiring a few people. There could also be an instance where Electric Fetus music store has many employees. If we happen to be searching for an employee and he/she is found we can either terminate that employee or hire an employee. 
   
 - Insertion 
    To hire an employee we must first verify that our root of the tree is not the employee we are trying to insert. If this is the case we can return "What are you doing employee already exists Insert an employee at the correct 
    
    
 - Deltion 





