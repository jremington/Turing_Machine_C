# Turing_Machine_C

C program to emulate a Turing Machine. 

I dug this up off an old disk inspired by an article in Byte magazine by Isaac Malitz (Byte Nov 1989 p 345, PDF article scan included). The article provided IBM Basic code for the simulator, along with a couple of TM examples. A couple of challenges were posed.

Read the article here: https://github.com/jremington/Turing_Machine_C/files/6052568/Turing_Byte_1987_11.pdf

The program requires 

1. a "data tape", an ASCII character array which is initialized with the data to be processed and after termination, stores the result of the calculation.
2. A "state table", a 2D character array. The specific program for the TM is encoded in the state table.

The C code posted implements an odd/even checker. For other machines, you can copy the data statement from the corresponding BASIC program, posted as a text file.
The programs include integer divide, the mod function, integer multiply and string copy.
