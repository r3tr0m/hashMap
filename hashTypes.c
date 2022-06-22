
//GLOBAL VARIABLES

//MULT_ADD
const double e = 2.00;

//POLY_ALG
const unsigned int P = 1117;
const unsigned int N = 1571;

uint8_t bitHouse[] = {1,2,4,8,16,32,64,128};



//MACROS

#define DEFAULT_HASH 0b11111111

//UNSIGNED

#define UINT64_T 8
#define UINT32_T 4
#define UINT16_T 2
#define UINT8_T  1
#define BYTE     8

//SIGNED

#define INT64_T 8
#define INT32_T 4
#define INT16_T 2
#define INT8_T  1



//ALG

//-> byte sequence alg O(n)

#define POLYNOMINAL  0b00000001
#define MULT_ADD_DIV 0b00000010
#define REHASHING    0b00000100
#define KEYVALUE	 0b00001000

//-> nums alg O(1)

#define PRIME_MOD_N  0b00010000
#define MATRIX_FIELD 0b00100000

//MAP_TYPES

#define MAP_COUNT    0b00000001
#define MAP_KEY		 0b00000010



//DATA STRUTURES AND ANOTHER TYPES

typedef unsigned char uchar;

//MAIN DATA_STRUTURE

typedef struct HashMap{

	void  *map;
	size_t  size;

	uint8_t type;
	uint8_t hashAlg;
	uint8_t mapType;

	union{

		uint8_t	 *mapChar;
		uint64_t *mapInt64_t;
		uint32_t *mapInt32_t;
		uint16_t *mapInt16_t;
		uint8_t  *mapInt8_t;

	};

}hash_t;


//TREAT ANY KEY VALUE AS A BYTE STREAM


typedef struct ByteSeq{

	char 	*seq;
	uint64_t size;

}byte_t;


//ULTIS

typedef struct BitField {

	uint64_t set;
	uint64_t unset;

}bit_t;