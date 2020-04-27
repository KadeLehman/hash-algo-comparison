# Performance Comparison of Two Hashing Algorithms with Integer Keys

This project will put two hashing algorithms to the test; one is trivial, one is non-trivial.
Here is a description of the trivial algorithm, as stated on Wikipedia:

> If the keys are uniformly or sufficiently uniformly distributed over the key space,
so that the key values are essentially random, they may be considered to be already 'hashed'.
In this case, any number of any bits in the key may be dialed out and collated as an index
into the hash table. A simple such hash function would be to mask off the bottom m bits
to use as an index into a table of size 2^m.

Here is an adapted description of the Fowler–Noll–Vo hash algorithm (I chose the 1a version, because data
hashed through version 1 is easier to decrypt and has the same runtime as version 1a. However, this
algorithm is still relatively easy to crack and is regarded as a non-cryptographic hash function):

> Start with an initial hash value of FNV offset basis. For each byte in the input, XOR (exclusive or)
> the hash value with the byte from input, then multiply it by the FNV prime.

Both the FNV offset basis and FNV prime are pre-determined values based on what "bit flavor" of
FNV you choose and based on mathematical procedures that the creators of FNV have developed.

Note that the trivial hash function will cause many hashtable collisions if the key space contains
many clumps, i.e. that the collection of integers to be inserted is unevenly distributed. Also,
any hash function will cause many collisions if many duplicate values are inserted.