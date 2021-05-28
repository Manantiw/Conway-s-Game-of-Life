Conway's Game of Life
===

This project is an implementation of John Horton Conway's Game of Life.


Repository Layout
---

The source code the implementation 
should be in the `src/` directory.  

There are several sample input files in `inputs/`, mostly containing
well-known Life constructions.  You can parse them using the function
`parse_life()` in the given code (defined in `src/parser.c`, with usage
comments at its definition).

There are additionally expected outputs for particular generations of
several of the given inputs in `outputs/'.

Running Tests
---

You can test your implementation against a few of the expected outputs
by running `make test`.

Adding Source Files
---

If you would like to add source files to your implementation, create the
files in the `src/` directory and add the filenames to the `SOURCEFILES`
variable in the Makefile.  
