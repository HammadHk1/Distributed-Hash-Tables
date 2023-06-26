# Distributed-Hash-Tables
## Introduction
We are considering a scenario where the data is not located on a single machine but rather stored on
multiple machines geo-distributed across the Internet. In such a scenario, searching or retrieval of data
is very challenging, as it is hard to determine on which machine the required data is stored. The data
structures used for efficiently search data stored on a single machine such as hash tables cannot be
directly employed in a distributed environment. The Figure 1 shows the concept of data storage and
lookup in a distributed environment.

![image](https://github.com/HammadHk1/Distributed-Hash-Tables/assets/117303560/51a379d7-7a7f-4a1d-8a85-ae8f809b67a2)

Typically, data is stored as a key, value pair. For example, key might be the name of the student or the
student ID and value is the complete information about the student. Likewise, the key can be the name
of the patient and value can be the medical record. Similarly, the key can be the name of an image file
and value represents the file itself.

## Ring DHT

- Ring DHT uses 160-bit circular identifier space using SHA-1. Figure 3 shows only a 4-bit
identifier space to simplify the explanation.
- Randomly chosen identifiers (ids in short) are assigned to machines (also called nodes in the
following): H(Node Address)  Node Id or Machine ID
Figure 3 shows 5 machines with ids 1, 4, 7, 12 and 15.
- Randomly chosen identifiers are assigned to data, i.e. (key, value) pairs: H(key)  Data Id
- Data with identifier e is stored on the node/machine with the smallest identifier p ≥ e. This
node/machine is called successor of e, denoted as succ(e). For example, Figure 3 depicts that
machine with id 12 is responsible for storing the data with ids 8,9,10,11 and 12, because all these
ids are less than or equal to the id of machine 12. The data with all these ids might not be available
for storage but if such a data arrives this machine, i.e., machine with id 12, will be used for the
storage. Likewise, machine with id 4 is responsible for storing data with ids 2, 3 and 4 (if
available).

![image](https://github.com/HammadHk1/Distributed-Hash-Tables/assets/117303560/7c0a38e0-40d9-418f-956c-3977b793d540)

## Search Algorithm
The request to search a data, i.e., given a key search for the value, can arrive on any machine. The
machine will first determine whether the data is locally stored, i.e., id e of the data is less than or equal
to the id p of the machine (p ≥ e). If data is not locally found, the search request is forwarded to the
next node in the circular linked list and so on. This very simple search algorithm is not very efficient
with a complexity of O(N) where N is the number of machines in the distributed system. Why?
To efficiently resolve data identifier e to machine succ(e), each machine p contains routing table FTp
of at most O(log N) entries, where N is the number of machines in the distributed system. Each
routing table entry i contains the shortcut/pointer to the distant node, i.e., FTp[i]=succ(p + 2i-1),
where i=1,...,l≤log(N). Figure 4 shows a 5-bit identifier space. The FT of machine 1 includes
the links (also called shortcuts or pointers) to the machines who are responsible, i.e., succ, for the ids
(1+1), (1+2), (1+4), (1+8), (1+16).
### Note: 
Figure 4 depicts the routing tables of machines with ids 1, 4, 9, 11, 14 and 28. Try to construct
these routing tables by hand to properly understand the concept of shortcuts.

![image](https://github.com/HammadHk1/Distributed-Hash-Tables/assets/117303560/57e555bf-d1e5-45ef-a058-b54ea784e83d)



## MAIN TO RUN THE CODE 
- When we start the project firstly we begin with singular Circular Linked List in which we did insertion for inserting machine in the circular-link list.It includes machine id and machine name.
- Then moving forward we make a class for AVL Tree in which we perform function for inserting to Tree.
- We made Doubly linked list for Routing table in which we did insertion and display it.
- Made separte Functions for conversion of string to ascii and taking mod and for calculating the number of line.

##  Code Type
- programmed in C++ using Visual Studio 2019.
- Download VS community edition from below link
```
https://visualstudio.microsoft.com/downloads/
```
