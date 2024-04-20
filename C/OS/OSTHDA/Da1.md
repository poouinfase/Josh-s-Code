
[Q1](https://www.geeksforgeeks.org/structures-of-directory-in-operating-system/)

Tree Directory structure is a simple and popular method of file sorting.
First we have the Root Directory, under that we have the user directories and system directories. Each of these then has numerous sub-directories and other files within it.

Acyclic structure is similar to Tree Directory structure in the basic organization. The only exception is that files may have more than one location, being shared between multiple sub-directories or user directories.

In Tree directories files must have only one single location but in Acyclic directories by using symbolic links, hard links and aliases, we can share files between multiple locations.

Advantages of tree:
This directory structure allows subdirectories inside a directory.
The searching is easier.
File sorting of important and unimportant becomes easier.
This directory is more scalable than the other two directory structures explained.

Disadvantages of tree:
As the user is not allowed to access other user’s directory, this prevents the file sharing among users.
As the user has the capability to make subdirectories, if the number of subdirectories increase the searching may become complicated.
Users cannot modify the root directory data.
If files do not fit in one, they might have to be fit into other directories.


Advantages of Acyclic:
Sharing of files and directories is allowed between multiple users.
Searching becomes too easy.
Flexibility is increased as file sharing and editing access is there for multiple users.

Disadvantages of Acyclic:
Because of the complex structure it has, it is difficult to implement this directory structure.
The user must be very cautious to edit or even deletion of file as the file is accessed by multiple users.
If we need to delete the file, then we need to delete all the references of the file inorder to delete it permanently.

[FILE ALLOCATION](https://www.geeksforgeeks.org/file-allocation-methods/):

1) Contiguous Allocation:
A file's blocks are written into memory in sequence.
Thus a file's directory entry must include: Address of starting block and length of allocated portion, thus allowing for random access at the cost of flexibility.

2) Linked List Allocation:
A file's block are written into memory with a pointer to the next block of memory.
Thus the file blocks are written in random order all throughout memory, thus allowing for lots of flexibility but prevents random access.

3) Indexed Allocation:
A file's blocks are written randomly into memory and the pointer to all the blocks are written into one index file, allowing for random non-sequential access with high flexibility.

---

[Q2](https://www.geeksforgeeks.org/architecture-of-linux-operating-system/)

---

[Q3](file:///C:/Users/catte/Downloads/OperatingSystemConcepts-10th[1].pdf)

The idea of virtualisation is to abstract away most of the hardware specifics of a machine, allowing for a single computer's resources are divided into several independent execution environments.

The main functions of a virtual machine are as follows:

-> It allows for more efficient use of hardware as it can be used to share resources between multiple environments. This is called system consolidation. This means that multiple light loads can be combined and served by one heavy machine, which can adaptively provision resources as needed.

-> It helps increase security as the hosts are unaffected by the actions of the guest environments, and the virtual machines are unaffected by each other. Thus if a security breach occurs in a VM, the host and other VMs are unaffected as they are all effectively isolated from one another. Making it a protected and safe environment.

-> One useful feature of a VM is the ability to suspend a running machine and in some cases even save snapshots or copies of the virtual machine that can be resumed at anytime. Helping prevent data loss due to malfunction by using rollbacks.

-> VMs are also a useful developer tool as testing and iteration can be done on the machines without interrupting the normal workflow.

-> The versatility of VMs can be seen in another case, where workloads can be moved from one physical system to another with minimal interruption allowing for high availability and fault tolerance. This feature is called live migration.

