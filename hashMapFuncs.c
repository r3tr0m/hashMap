
//CHECK_HASH_MAP FUNCS

uint64_t hashCheckNum(hash_t *hashMap,uint64_t value){

	uint64_t index = hashSetNum(hashMap,value);

	//return hashMap->map[index];

}

uint64_t hashCheckStream(hash_t *hashMap,byte_t *byteSeq){

	uint64_t index = hashSetStream(hashMap,byteSeq);

	return ((unsigned char*) hashMap->map)[index];

}

//REMOVE HASH_MAP VALUES FUNCS

void hashMapRemoveNum(hash_t *hashMap,uint64_t value){

	uint64_t index = hashSetNum(hashMap,value);

	//hashMap->map[index] = 0x00;

}

void hashMapRemoveStream(hash_t *hashMap,byte_t *byteSeq){

	uint64_t index = hashSetStream(hashMap,byteSeq);

	((unsigned char*) hashMap->map)[index] = 0x00;

}
