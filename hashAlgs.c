
//BYTE SEQUESENCE HASHING

uint64_t polynominalHash(hash_t *hashMap,byte_t *byteSeq){

		uchar   *seqP = byteSeq->seq;
		uint64_t hash = 0;

		for(uint64_t byte=0;byte < byteSeq->size;byte++){

			hash += seqP[byte] * ( (uint64_t) pow(e,byte) );

		}

		return hash;

}

//O(N)

uint64_t mult_add_divHash(hash_t *hashMap,byte_t *byteSeq){

	uchar   *seqP = byteSeq->seq;
	uint64_t hash = 0;
	uint32_t A    = hashMap->size ^ hashMap->type ^ hashMap->hashAlg;


	for(uint64_t byte=0;byte < (byteSeq->size)-1;byte++){

		hash += (((A * seqP[byte]) ^ seqP[byte+1] ) % P) % N;

	}

}

//O(N.B)

uint64_t rehashingHash(hash_t *hashMap,byte_t *byteSeq){

	uint64_t byteSum = checkSum(byteSeq);
	uint64_t hash    = DEFAULT_HASH;

	//ROUND

	for(uint64_t round=0;round < (byteSum % 10);round++){

		for(uint64_t byte=0;byte < byteSeq->size;byte++)
		{
				hash ^= (byteSeq->seq[byte]<<round);
				printf("hash -> %llu\n",hash);
		}

	}

	return hash;

}

//NUMS HASHING

//O(1)

uint64_t prime_mod_n(uint64_t n){

	return ((n * DEFAULT_HASH) % P) % N;

}


