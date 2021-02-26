#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Turing machine simulator, translation of TM1.BAS Isaac Malitz, Byte Nov 1989 p 345.
// S. J. Remington, long ago

// The follow initialization statements implement the TM1.BAS "even/odd" checker from the above article
// The program counts the number of X entries and reports whether the number is even or odd

// data tape
char tape[] = "XXXXbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"; //data and output tape for even/odd checker
char state = '0'; //machine state
char mark = 0; //symbol read

// state table "state, symbol read, '-', new symbol, new state, action", 7 characters per state
char state_table[][7]={ "0X-b1R", "0b-E..", "1X-b0R", "1b-O.."}; //state table for odd/even checker
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
