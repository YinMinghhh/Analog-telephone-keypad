/*
 * File: bitset.h
 * Purpose: implementation of bitset in C
 * Author: puresky
 * Date: 2011/05/03
 */

#ifndef _BIT_SET_H
#define _BIT_SET_H

#define BITS_PER_CHAR 8

typedef struct BitSetStruct BitSet;
struct BitSetStruct
{
      char *_mblock; // a block of memmery
      int _len; //the number of bits specified by users
      int _len2;//the number of bytes in the _mblock 
      int _count; //the number of bits that is set to 1 in the _mblock
};

BitSet *bitset_new(BitSet *const bs, int bitsCount);
BitSet *bitset_new2(BitSet *const bs, const char *bits);
void bitset_free(BitSet *bs);
int bitset_size(BitSet *bs);
int bitset_count(BitSet *bs);
void bitset_reset(BitSet *bs, int pos);
void bitset_reset_all(BitSet *bs);
void bitset_set(BitSet *bs, int pos);
void bitset_set_all(BitSet *bs);
void bitset_reset(BitSet *bs, int pos);
int bitset_isset(BitSet *bs, int pos);
void bitset_print(BitSet *bs);
char *bitset_to_str(BitSet *bs);
#endif
