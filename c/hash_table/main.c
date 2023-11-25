#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Function that prints the data of the hash table
void printTable(HASH_TABLE_PTR H){
	if(isEmpty(H)) {
		printf("*empty\n");
		return;
	}

	for(int index=0; index<H->tableSize; index++){
		printf("Cell#%d: ", index);
		if(H->list[index]){
			printf("%s\n", H->list[index]);
		}else{
			printf("*empty*\n");
		}
	}
}

//Create your own hash functions

int computeKey(STRING key){
	int length = strlen(key);
	int hashValue = 0;

	for (int i = 0; i < length; i++) {
		if ((int)(key[i]) % 2 == 0) hashValue += (int)(key[i]);  // add to hash value if the ascii value of letter is even
	}
	return hashValue;
}

int hashFunction(HASH_TABLE_PTR H, STRING key) {
	return computeKey(key) % H->tableSize; 
}

int secondHashFunction(HASH_TABLE_PTR H, STRING key, int i) {
	return (hashFunction(H, key) + (i * (17 + computeKey(key) % strlen(key)))) % H->tableSize;
}


//Insert the implementations of the functions found in the header file
HASH_TABLE_PTR createHashTable(int tableSize) {
	// tableSize is unsigned

	HASH_TABLE_PTR new = (HASH_TABLE_PTR) malloc(sizeof(HASH_TABLE));
	new->tableSize = tableSize; //intialize size of hash table
	new->size = 0; // current number of elements
	new->list = (STRING_ARRAY_PTR) malloc(sizeof(STRING) * tableSize); //allocate memory for the list of data that will be stored

	return new;
}

int isEmpty(HASH_TABLE_PTR H) {
	return (H->size == 0); // return true if the hash table is empty
}

int isFull(HASH_TABLE_PTR H) {
	return (H->size == H->tableSize); //return true if the hash table is full
}

void put(HASH_TABLE_PTR H, STRING key, STRING data) {
	if (H == NULL){
		printf("No hash table initialized.\n");
		return;
	}

	if (isFull(H)){
		printf("Hash table is full.\n");
		return;
	}

	int count = 0; // number of interations, tracked to avoid possible indices with non termination pattern 
	int index = hashFunction(H, key);
	
	while (count != H->tableSize){  // set maximum number of interations less than the size of the hash table
		if (H->list[index] == NULL) { // condition if current cell is empty
			H->list[index] = malloc(sizeof(char) * 100); 
			strcpy(H->list[index], data); // add data to hash table
			H->size++; // +1 element
			break;
 		}else{
			count++; // +1 iteration
			index = secondHashFunction(H, key, count); // implement double hash function
        } 
     }
}

STRING find(HASH_TABLE_PTR H, STRING key, STRING data) {
	if (H == NULL){
		printf("No hash table initialized.\n");
		return NULL;
	}

	if (key == NULL){
		printf("Key input is null.\n");
		return NULL;
	}

	if (data == NULL){
		printf("Data input is empty.\n");
		return NULL;
	}

	int index = hashFunction(H, key); // get hash value of key, assuming there is no collision
	
	if (strcmp(H->list[index], data) == 0){
		return H->list[index]; // if data exists, return 
	}
	
	for (int c = 1; c < H->tableSize; c++) {  // since number of collsion(s) is unknown iterate to check
		index = secondHashFunction (H, key, c); // get double hash value  
		if (H->list[index] != NULL && strcmp(H->list[index], data) == 0){
			return H->list[index]; //return if data exists
		}
	}
	return NULL;
}

STRING erase(HASH_TABLE_PTR H, STRING key, STRING data) {
	if (H == NULL){
		printf("No hash table initialized.\n");
		return NULL;
	}

	if (key == NULL){
		printf("Key input is null.\n");
		return NULL;
	}

	if (data == NULL){		
		printf("Data input is empty.\n");
		return NULL;
	}

	STRING toDel = find(H, key, data);
	// STRING temp;
	// for (int i=0; i < strlen(toDel); i++){
	// 	temp[i] = toDel[i];
	// }
	free(toDel);

	return NULL;
}

void destroy(HASH_TABLE_PTR H){
	if (H == NULL){
		printf("No hash table initialized.\n");
		return;
	}

	free(H->list);
	free(H);
}

int main(){

	char command;
	STRING key;
	STRING data;
	STRING result;

	unsigned int tsize;
	HASH_TABLE_PTR H;
	
	// get table size then maxsize
	scanf("%d\n", &tsize); 
	H = createHashTable(tsize);

	// assume max key size is 20
	key = (STRING)malloc(sizeof(char)*20);
	key[0] = '\0';
	// assume max data size is 100
	data = (STRING)malloc(sizeof(char)*100);
	data[0] = '\0';

	while(1){
		scanf(" %c", &command);

		switch(command){
			case '+':
				scanf(" k:%s d:%s", key, data);
				printf("Inserting data %s with key %s\n", data, key);
				put(H, key, data);
				break;
			case '-':
				scanf(" %s", key);
				printf("Deleting data with key %s\n", key);
				result = erase(H, key, data); 
				// result is unused. print if u want
				printf("Deleted: %s\n", result);
				break;
			case '?':
				scanf(" k:%s d:%s", key, data);
				printf("Searching data with key: %s. Location: %p\n", key, find(H, key, data));
				// (nil) means NULL pointer
				break;
			case 'p':
				printf("Hash Table: \n");
				printTable(H);
				printf("\n");
				break;
			case 'E':
				printf("Hash table %s empty.\n", isEmpty(H)?"is":"is not");
				break;
			case 'F':
				printf("Hash table %s full.\n", isFull(H)?"is":"is not");
				break;
			case 'C':
				printf("Deleting all contents.\n");
				destroy(H);
				break;
			case 'Q':
				free(key); free(data);
				destroy(H); // ensure deletion
				free(H->list);
				free(H);
				return 0;
			default:
				printf("Unknown command: %c\n", command);
		}
	}
	
	return 0;
}
