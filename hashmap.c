#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "hashTypes.c"
#include "hashUltis.c"
#include "hashAlgs.c"


hash_t* CreateHashMap(size_t size,uint8_t type,uint32_t hashAlg,uint8_t mapType){

	hash_t  *hashMap 	= (hash_t*) malloc(sizeof(hash_t));
	void 	*hashArray 	= 			malloc(size * type);

	hashMap->map 		= hashArray;
	hashMap->size   	= size;
	hashMap->type 		= type;
	hashMap->hashAlg 	= hashAlg;
	hashMap->mapType    = mapType;

	typeCastMap(hashMap);

	return hashMap;

}

//BYTE SEQUENCE STREAM

uint64_t hashSetStream(hash_t *hashMap,byte_t *byteSeq){

	uint64_t hash  = DEFAULT_HASH;
	uint8_t CONFIG = hashMap->hashAlg;


	if (POLYNOMINAL & CONFIG){

		hash ^= polynominalHash(hashMap,byteSeq);


	} if(MULT_ADD_DIV & CONFIG){

		hash ^= mult_add_divHash(hashMap,byteSeq);


	} if(REHASHING & CONFIG){

		hash ^= rehashingHash(hashMap,byteSeq);

	}

	hash %= hashMap->size;

	//mapTypeAction(hashMap,hash,byteSeq);

	return hash;

}

//NUMS HASHING

uint64_t hashSetNum(hash_t *hashMap,uint64_t value){

	uint64_t hash  = DEFAULT_HASH;
	uint8_t CONFIG = hashMap->hashAlg;


	if(PRIME_MOD_N & CONFIG){

			hash = prime_mod_n(value);

	}

	hash %= hashMap->size;

	mapTypeAction(hashMap,hash,value);

	return hash;

}


int main(){

	hash_t *hash = CreateHashMap(256,UINT32_T,PRIME_MOD_N,MAP_COUNT);

	//hashSetNum(hash,30);
	//hashCheckNum(hash,30);
	#include "hashMapFuncs.c"
}