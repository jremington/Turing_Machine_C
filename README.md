# Turing_Machine_C

C programs to emulate a Turing Machine. 

I dug this up off an old disk; project inspired by an excellent, insightful article (Isaac Malitz, Byte 11/87 p 345, PDF article scan included). The article provided IBM PC Basic code for the emulator, along with a couple of TM examples. A couple of challenges were posed. (Indeed, a contest! I never got around to submitting my solutions, and to my knowledge, no one else did either, as I was not able to find any published results from the contest).

Read the article here: https://github.com/jremington/Turing_Machine_C/files/6052568/Turing_Byte_1987_11.pdf

The program requires 

1. a "data tape", an ASCII character array which is initialized with the data to be processed and after termination, stores the result of the calculation.
2. A "state table", a 2D character array. The specific program for the TM is encoded in the state table.

The C code posted as turing_evenodd.c implements an odd/even checker, the C translation of the BASIC program TM1.BAS described in the article. 
The C code posted as turing_mul.c implements integer multiply.

For other machines, you can copy the data statements and "tape" T$ from the corresponding BASIC program, posted as a text file. The machines include integer divide, mod function and string copy.

Very educational, but fun too!
