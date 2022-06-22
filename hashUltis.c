
//TYPE CAST TREAMENT FOR HASHMAP DATA STRUTURE

void typeCastMap(hash_t *hashMap){

	uint8_t numType = hashMap->type;

	switch(hashMap->type){

		case UINT64_T:

			hashMap->mapInt64_t 	= (uint64_t*) hashMap->map;
			break;

		case UINT32_T:

			hashMap->mapInt32_t	= (uint32_t*) hashMap->map;
			break;

		case UINT16_T:

			hashMap->mapInt16_t	= (uint16_t*) hashMap->map;
			break;

		case UINT8_T:

			hashMap->mapInt8_t 	= (uint8_t*) hashMap->map;
			break;

		default:
			break;

	}


}

//IDENTIFIE THE HASHMAP TYPE MAP_COUNT | MAP_KEY TAKE ACTION

void mapTypeAction(hash_t *hashMap,uint64_t hash,uint64_t value){

	int64_t val;

	uint8_t mapType  = hashMap->type;
	bool    mapCount = hashMap->mapType == MAP_COUNT;

	if(mapCount){

		val = 1;
		
		switch(hashMap->type)
		{

			case UINT8_T:

				hashMap->mapInt8_t[hash] += val;
				break;

			case UINT16_T:

				hashMap->mapInt16_t[hash] += val;
				break;

			case UINT32_T:
				hashMap->mapInt32_t[hash] += val;
				break;

			case UINT64_T:
				hashMap->mapInt64_t[hash] += val;
				break;

			default:
				break;

		}

	}else{

		//MAP_KEY VALUE
		
		val = value;

		switch(hashMap->type)
		{

			case UINT8_T:

				hashMap->mapInt8_t[hash] = val;
				break;

			case UINT16_T:

				hashMap->mapInt16_t[hash] = val;
				break;

			case UINT32_T:
				hashMap->mapInt32_t[hash] = val;
				break;

			case UINT64_T:
				hashMap->mapInt64_t[hash] = val;
				break;

			default:
				break;

		}

	}

}

uint64_t checkSum(byte_t *byteSeq){

		uint64_t sum = 0;

		for(uint64_t byte=0;byte < byteSeq->size;byte++){

			sum += byteSeq->seq[byte];

		}

	return sum;

}

bit_t* bitField(byte_t *byteSeq){

	bit_t *field = (bit_t*) malloc(sizeof(bit_t));

	for(uint64_t byte=0;byte < byteSeq->size;byte++){

		for(uint8_t bit=0;bit < BYTE;bit++)
		{

			if(bitHouse[bit] & byteSeq->seq[byte]){

				field->set   += 1;

			}else{

				field->unset += 1;
			}

		}

	}

	return field;
}

bool oddField(byte_t *byteSeq){

	bit_t *field = bitField(byteSeq);
	return ((field->set + field->unset) % 2) == 0;

}
