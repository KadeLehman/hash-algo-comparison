# Performance Comparison of Various Hashing Algorithms

This project will put two hashing algorithms to the test; one is trivial, one is non-trivial.
Here is a description of the trivial algorithm, as stated on Wikipedia:

> If the keys are uniformly or sufficiently uniformly distributed over the key space,
so that the key values are essentially random, they may be considered to be already 'hashed'.
In this case, any number of any bits in the key may be dialed out and collated as an index
into the hash table. A simple such hash function would be to mask off the bottom m bits
to use as an index into a table of size 2m.

Here is a description of the Fowler–Noll–Vo algorithm (I chose the 1a version, because data hashed
through version 1 is easier to decrypt and has the same runtime as version 1a):

> 