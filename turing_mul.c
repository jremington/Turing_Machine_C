#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Turing machine simulator, translation of BASIC code by Isaac Malitz, Byte Nov 1987 p 345.
// S. J. Remington, long ago

// The follow initialization statements implements integer multiply
// divides string P by string Q, result string T

// data tape
char tape[] = "PPbbQQQbbbbbbbbbbbbbbbbbbbb"; //data and output tape for multiply
char state = '0'; //machine state
char mark = 0; //symbol read

// state table "state, symbol read, '-', new symbol, new state, action", 7 characters per state
char state_table[][7]={"0P-E1R","0R-Q0L","0b-b0L","0E-E..","1Q-R2R","1b-b1R","1P-P1R","1T-T0L",\
"2b-T3L","2Q-Q2R","2T-T2R","3R-R1R","3Q-Q3L","3T-T3L"}; //state table for multiply
// end of application-specific initialization

int p = 0; //starting position on tape
char r[7];  //current state table entry

int main() {

    int state_table_size = sizeof(state_table)/7; //max index
    printf("state table size %d\n",state_table_size);
    int i;

    while(1) {

//  print tape and pointer
    printf("%s\n",tape);
    i=p;
    while(i)
        {
        i--;
        printf(" ");
        }
    printf("^\n");

//  check state for stop
    if (state == '.') break;

//  read tape
    mark = tape[p];

    printf("s %c t %c\n",state,mark);

// state table lookup. Look for combination of state and symbol read
    for(i=0; i<state_table_size; i++)
    {
        memcpy(r,&state_table[i],7); // copy table entry

        if ( state==r[0] && mark==r[1]) break; //found an entry
        if (i == state_table_size-1) printf("state table error\n");
    }

// current instruction entry
    printf("r %s\n",r);

// rewrite symbol on tape according to instruction
    tape[p]=r[3];

// move tape head as instructed
    if (r[5] == 'L') p--;
    if (r[5] == 'R') p++;

// determine new machine state
    state = r[4];
    }
 return 0;
}
