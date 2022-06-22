
//HASH_MAP_REMOVE FUNCS

void* hashMapRemoveNum(hash_t *hashMap,uint64_t index){

	uint8_t hashPointer 	= &((uint8_t*) hashMap->map)[index];

	for(uint32_t byte=0;byte < (hashMap->type);byte++){

		hashPointer[byte] 	= 0x00;

	}

}

void* hashMapRemoveStream(hash_t *hashMap,byte_t *byteSeq){

	uint64_t index 			= hashSetStream(hashMap,byteSeq);
	uint8_t  hashPointer 	= &((uint8_t*) hashMap->map)[index];

	for(uint32_t byte=0;byte < (byteSeq->size);byte++){

		hashPointer[byte] = 0x00;

	}

}

//HASH_MAP_GET / CHECK FUNCS

byte_t* hashMapValue(hash_t *hashMap,uint64_t index){

	byte_t *byteSeq 	= (byte_t*) malloc(sizeof(byte_t));
	uchar  *byteStream  = (uchar*)  malloc(hashMap->type);

	byteSeq->seq  = byteStream;
	byteSeq->size = hashMap->type;

	memcpy(byteSeq->seq,&((uint8_t*) hashMap->map)[index],byteSeq->size);

	return byteSeq;

}

void* hashGetNum(hash_t *hashMap,uint64_t value){

	uint64_t index 	= hashSetNum(hashMap,value);
	byte_t *byteSeq = hashMapValue(hashMap,index);

	return byteSeq->seq;

}

hashCheckStream(hashMap,person);

uchar* hashGetStream(hash_t *hashMap,byte_t *byteSeq){

	uint64_t index = hashSetStream(hashMap,byteSeq);

	return &((unsigned char*) hashMap->map)[index];

}


bool hashCheckValue(hash_t *hashMap,uint64_t value){

	bool	 isContain  = true;
	uint64_t index 	 	= hashSetNum(hashMap,value);
	uint8_t  hashValue 	= ((uint8_t*) hashMap->map)[index];


	if(hashValue <= 1){

		isContain = false;
		hashValue--;

	}

	return isContain;
	
}

