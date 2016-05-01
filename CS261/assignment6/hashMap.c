#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{  
	/*write this*/
	struct hashLink* temp;

	for(int i = 0; i < ht->tableSize; i++){
		while (ht->table[i] != NULL){
			temp = ht->table[i];
			ht->table[i] = ht->table[i]->next;
			free(temp);
		}
	}
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/* 
Resizes the hash table to be the size newTableSize 
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/
	struct hashMap* newTable = createMap(newTableSize);
	int i;

	for (i = 0; i < ht->tableSize; i++){
		if (ht->table[i] != NULL){
			struct hashLink* copier = ht->table[i];
			struct hashLink* remover;
			while (copier != NULL){
				insertMap(newTable, copier->key, copier->value);
				remover = copier;
				copier = copier->next;
				free(remover);
			}
		}
	}
	free(ht->table);

	ht->tableSize = newTableSize;
	ht->table = newTable->table;
	ht->count = newTable->count;

}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".
 
 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.
 
 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  
	/*write this*/
	assert(ht != NULL);

	struct hashLink* newLink = malloc(sizeof(struct hashLink));
	assert(newLink != NULL);

	int hashIndex;

	if (HASHING_FUNCTION == 1){
		hashIndex = stringHash1(k) % ht->tableSize;
	} 
	else if (HASHING_FUNCTION == 2){
		hashIndex = stringHash2(k) % ht->tableSize;
	}

	newLink->next = NULL;
	newLink->key = k;
	newLink->value = v;

	if (containsKey(ht, k)){
		removeKey(ht, k);
	}

	if (ht->table[hashIndex] == NULL){
		ht->table[hashIndex] = newLink;
		ht->count++;
	}
	else{
		struct hashLink* current = ht->table[hashIndex];

		while (current->next){
			current = current->next;
		}
		current->next = newLink;
		ht->count++;
	}

	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD){
		_setTableSize(ht, ht->tableSize * 2);
	}

}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.
 
 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.
 
 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{ 
	/*write this*/
	int hashIndex;
	if (HASHING_FUNCTION == 1){
		hashIndex = stringHash1(k) % ht->tableSize;
	}
	else if (HASHING_FUNCTION == 2){
		hashIndex = stringHash2(k) % ht->tableSize;
	}

	struct hashLink* current = ht->table[hashIndex];
	ValueType* valAddr = NULL;

	while (current != NULL) {
		if (strcmp(current->key, k) == 0){
			valAddr = &current->value;
			break;
		}

		current = current->next;
	}

	return valAddr;
}

/*
 a simple yes/no if the key is in the hashtable. 
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	int hashIndex;
	struct hashLink* current;
	if (HASHING_FUNCTION == 1){
		hashIndex = stringHash1(k) % ht->tableSize;
	}
	else if (HASHING_FUNCTION == 2){
		hashIndex = stringHash2(k) % ht->tableSize;
	}

	current = ht->table[hashIndex];
	while (current != NULL){
		if (strcmp(current->key,k) == 0){
			return 1;
		}
		current = current->next;
	}

	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{  
	/*write this*/
	int hashIndex;
	if (HASHING_FUNCTION == 1){
		hashIndex = stringHash1(k) % ht->tableSize;
	}
	else if (HASHING_FUNCTION == 2){
		hashIndex = stringHash2(k) % ht->tableSize;
	}

	struct hashLink *current, *last;
	if (containsKey(ht, k)){
		current = last = ht->table[hashIndex];
		
		while (current != 0){
			if (strcmp(current->key, k) == 0){
				if (current == ht->table[hashIndex]){
					ht->table[hashIndex] = current->next;
				}
				else{
					last->next = current->next;
				}
				free(current);
				current = NULL;
			}
			else{
				last = current;
				current = current->next;
			}
		}
	}
	else{
		return;
	}

}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{  
	/*write this*/
	return ht->count;
	
}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{  
	/*write this*/
	return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{  
	/*write this*/
	int numEmpty = 0;

	for (int i = 0; i < ht->tableSize; i++){
		if (ht->table[i] == NULL){
			numEmpty++;
		}
	}

	return numEmpty;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)
 
 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{  
	/*write this*/
	return (float) ht->count / (float) ht->tableSize;
}
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;	
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {		
			printf("\nBucket Index %d -> ", i);		
		}
		while(temp != 0){			
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;			
		}		
	}
}


