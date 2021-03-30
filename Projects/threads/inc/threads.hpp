#ifndef THREADS_H
#define THREADS_H
#define SWAP(a, b) {a ^= b; b ^= a; a ^= b;};

int numthreads;
char ** inFiles;
char ** outFiles;

#endif
