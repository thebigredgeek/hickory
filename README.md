Hickory VM
==========

#### Building

To build the VM:

    $ make


#### Instruction Set


Input/Output Operations

`10XX` READ - Read a word from the keyboard and store it in location `XX`

`11XX` WRITE - Write a word to the screen from location `XX`


Memory Operations

`20XX` LOAD - Load the word stored in the location location `XX` into the accumulator

`21XX` STORE - Store a word from the accumulator into location `XX`


Arithmetic Operations

`30XX` ADD - Add the word stored in the location `XX` to the value in the accumulator

`31XX` SUBTRACT - Subtract the word stored in the location `XX` from the value in the accumulator

`32XX` DIVIDE - Divide the value in the accumuliator by the word stored in the location `XX`

`33XX` MULTIPLY - Multiple the value in the accumulator by the word stored in the location `XX`


Transfer-of-Control Operations

`40XX` BRANCH - Branch to location `XX`

`41XX` BRANCHNEG - Branch to location `XX` if the value in the accumulator is negative

`42XX` BRANCHZERO - Branch to location `XX` if the value in the accumulator is zero

`43XX` HALT - Stop execution and dump accumulator to the location `XX` (or purge if zero)  


#### Running the sample program

The sample program takes two inputs, adds them together, and displays the output.  It is located in `test.ssc`.
To run it, after you have built:

    $ ./build test.ssc


#### Roadmap

I'll be adding more instructions, bound to various libraries, over time.  I also plan on branding an actual language name, as well as building a compiler and switching to binary storage instead of ascii characters.

Enjoy

-TBRG