# Performance Comparison of Two Hashing Algorithms with Integer Keys

This project will put two hashing algorithms to the test; one is trivial, one is not. The program will insert
an unevenly distributed list of integers from 100,000 to 599,999 (500,000 total integers)
into my custom hash table. The program is designed to display how much time and collisions the hash tables
take when inserting the same integers. 

## Trivial Hashing

Here is a description of the trivial algorithm, as stated on Wikipedia:

> If the keys are uniformly or sufficiently uniformly distributed over the key space,
so that the key values are essentially random, they may be considered to be already 'hashed'.
In this case, any number of any bits in the key may be dialed out and collated as an index
into the hash table. A simple such hash function would be to mask off the bottom m bits
to use as an index into a table of size 2^m.

For simplicity, I will implement the "simple" version as stated above in the last sentence. Note that the
trivial hash function will cause many hashtable collisions if the collection of integers
to be inserted is unevenly distributed. This is how my data is, so this weakness is reflected in the
slower runtime of inserting my data into the trivial hash table. Also, any hash function will cause
collisions when duplicate values are inserted, but both of my hash tables receive the same duplicates.
As a result, this has tiny effect on the difference number of collision using the trivial versus non-trivial
hashing algorithm.

Since the program is inserting 500,000
integers, it will round up the number 500,000 to the nearest power of two, which is 2^19 (524,288). I then
divide this by 4 so that the hash table takes up less space, since the program then makes the hash table
this size (in number of forward_lists). The program then takes the log-base-two of this new number to get
17, the number of bits to use as the hash for any given element being inserted into the table. The first
two bits of each inserted integer are ignored, so the hash function just returns hash values in the range
of zero to (tableSize - 1).

## FNV-1a Hashing

Below is an adapted description of the Fowler–Noll–Vo-1a hash algorithm. I chose the 1a version, because data
hashed through this version is harder to decrypt and has the same runtime as FNV-1. However, this
algorithm is still relatively easy to crack and is regarded as a non-cryptographic hash function:

> Start with an initial hash value of the FNV offset basis. For each byte in the input, XOR
> (exclusive-or) the hash value with the byte from input, then multiply it by the FNV prime.

Both the FNV offset basis and FNV prime are pre-determined values based on what "bit flavor" of
FNV you choose and were created through mathematical procedures that the creators of FNV developed.
The FNV numbers help naturally reduce collisions since they help spread inserted values evenly across the
key space of the hash table. The "bit flavor" of FNV algorithm I implement is the 32-bit flavor, because my
largest integer value I may be inserting is 599,999. This number is 2^20 when rounded up to the nearest power of two.
Because I can combine the FNV algorithm with xor-folding, a topic explained by FNV creator Landon Curt Noll at
http://www.isthe.com/chongo/tech/comp/fnv/index.html#xor-fold, the FNV table only has to hold about 2^20
singly-linked lists. Before inserting values, this initially takes up eight times more memory space than the
trivial table. However, since STL forward_lists don't take up much space to begin with, the cost of space is well
worth the lower collision rate when inserting 500,000 integers.

##Conclusion

On average, it takes about the same amount of time to insert 500,000 integers when the set of integers is
distributed as specified in my program. However, far less collisions occur with the FNV hash function.
This means that searching and/or deleting of a large number of integers in the FNV table will take
much less time relative to the trivial table overall.