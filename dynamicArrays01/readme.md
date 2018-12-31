This is a C language sample for a simple dynamic two dimensions int array.

It explores two cases, the first one the second row points to the first; so they share memory space;

The second case both rows are independent.

To compile I used gcc (GCC) 4.8.5 20150623, but I think other gcc version shouldn't be an issue:

`gcc arrays.c`

To run:

`./a.out`
