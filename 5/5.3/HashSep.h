#ifndef _HashSep_H

#define MinTableSize 10

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

typedef int ElementType;

HashTable InitializeTable(int tableSize);
void DestoryTable(HashTable h);
Position Find(ElementType key, HashTable h);
void Insert(ElementType key, HashTable h);
ElementType Retrieve(Position p);

#endif /* _HashSep_H */
