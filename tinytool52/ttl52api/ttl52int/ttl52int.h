// tinytool52 Copyright 2026 baibhav Bhattacharya
// Apache License version 2.0
// ttl52int.h is an implementation of stdint.h on 8051 and 8052 architectures

#ifndef ttl52int_h
#define ttl52int_h

#define INT24T_SIZE 3
#define INT40T_SIZE 5
#define INT48T_SIZE 6
#define INT56T_SIZE 7
#define INT64T_SIZE 8

#define UINT24T_SIZE 3
#define UINT40T_SIZE 5
#define UINT48T_SIZE 6
#define UINT56T_SIZE 7
#define UINT64T_SIZE 8

#define INT24T_MAX_VALUE 8388607
#define INT40T_MAX_VALUE 549755813887
#define INT48T_MAX_VALUE 140737488355327
#define INT56T_MAX_VALUE 36028797018963967
#define INT64T_MAX_VALUE 9223372036854775807

#define UINT24T_MAX_VALUE 16777215
#define UINT40T_MAX_VALUE 1099511627775
#define UINT48T_MAX_VALUE 281474976710655
#define UINT56T_MAX_VALUE 72057594037927935
#define UINT64T_MAX_VALUE 18446744073709551615




#define UINT24(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF \
} }


#define UINT40(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF, \
    ((x) >> 24) & 0xFF, \
    ((x) >> 32) & 0xFF, \
} }


#define UINT48(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF, \
    ((x) >> 24) & 0xFF, \
    ((x) >> 32) & 0xFF, \
    ((x) >> 40) & 0xFF \
} }


#define UINT56(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF, \
    ((x) >> 24) & 0xFF, \
    ((x) >> 32) & 0xFF, \
    ((x) >> 40) & 0xFF, \
    ((x) >> 48) & 0xFF \
} }



#define INT24(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF \
} }


#define INT40(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF, \
    ((x) >> 24) & 0xFF, \
    ((x) >> 32) & 0xFF, \
} }


#define INT48(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF, \
    ((x) >> 24) & 0xFF, \
    ((x) >> 32) & 0xFF, \
    ((x) >> 40) & 0xFF \
} }


#define INT56(x) { { \
    (x) & 0xFF, \
    ((x) >> 8) & 0xFF , \
    ((x) >> 16) & 0xFF, \
    ((x) >> 24) & 0xFF, \
    ((x) >> 32) & 0xFF, \
    ((x) >> 40) & 0xFF, \
    ((x) >> 48) & 0xFF \
} }



// TYPE DEFINITIONS
typedef unsigned char uint8t;      // Unsigned Integer 8 Bits
typedef unsigned int uint16t;      // Unsigned Integer 16 Bits
typedef unsigned long uint32t;     // Unsigned Integer 32 Bits
typedef unsigned long long uint64t; // Unsigned Integer 64 Bits

typedef struct{
    uint8t bytes[1];
}ttl52IntTemplate;

typedef struct{
   uint8t bytes[3];
}uint24t;                          // 24 Bit Unsigned Integer

typedef struct{
    uint8t bytes[5];
}uint40t;                          // 40 bit Unsigned Integer

typedef struct{      
    uint8t bytes[6];
}uint48t;                          // 48 Bit Unsigned Integer

typedef struct{
   uint8t bytes[7];
}uint56t;                          // 56 Bit Unsigned Integer



/*                                                                  SIGNED INTEGERS                                                                                      */

typedef char int8t;                // Integer 8 Bits
typedef int int16t;                // Integer 16 Bits
typedef long int32t;               // Integer 32 Bits
typedef long long int64t;          // Integer 64 Bits

void ADDUINTC(uint8t* out , const uint8t* inp1 , const uint8t* inp2 , uint8t size) __reentrant;
void ADDUINTC_IDATA(uint8t __idata* out , const uint8t __idata* inp1 , const uint8t __idata* inp2 , uint8t size);
void ADDUINTC_XDATA(uint8t __xdata* out , const uint8t __xdata* inp1 , const uint8t __xdata* inp2 , uint8t size);
void ADDUINTC_STATIC_IDATA(uint8t __idata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size);
void ADDUINTC_STATIC_XDATA(uint8t __xdata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size);

inline void ADDUINT24(uint24t* out , const  uint24t* inp1 , const  uint24t* inp2){
    ADDUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void ADDUINT24_IDATA(uint24t __idata* out , const  uint24t __idata* inp1 , const  uint24t __idata* inp2){
    ADDUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void ADDUINT24_XDATA(uint24t __xdata* out , const  uint24t __xdata* inp1 , const  uint24t __xdata* inp2){
    ADDUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void ADDUINT24_STATIC_IDATA(uint24t __idata* out , const  uint24t __code* inp1 , const  uint24t __code* inp2){
    ADDUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void ADDUINT24_STATIC_XDATA(uint24t __xdata* out , const  uint24t __code* inp1 , const  uint24t __code* inp2){
    ADDUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

/*                  UINT40                                                                        */
inline void ADDUINT40(uint40t* out , const  uint40t* inp1 , const  uint40t* inp2){
    ADDUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void ADDUINT40_IDATA(uint40t __idata* out , const  uint40t __idata* inp1 , const  uint40t __idata* inp2){
    ADDUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void ADDUINT40_XDATA(uint40t __xdata* out , const  uint40t __xdata* inp1 , const  uint40t __xdata* inp2){
    ADDUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void ADDUINT40_STATIC_IDATA(uint40t __idata* out , const  uint40t __code* inp1 , const  uint40t __code* inp2){
    ADDUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void ADDUINT40_STATIC_XDATA(uint40t __xdata* out , const  uint40t __code* inp1 , const  uint40t __code* inp2){
    ADDUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

/*                                                  UINT48                                                                                 */

inline void ADDUINT48(uint48t* out , const  uint48t* inp1 , const  uint48t* inp2){
    ADDUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void ADDUINT48_IDATA(uint48t __idata* out , const  uint48t __idata* inp1 , const  uint48t __idata* inp2){
    ADDUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void ADDUINT48_XDATA(uint48t __xdata* out , const  uint48t __xdata* inp1 , const  uint48t __xdata* inp2){
    ADDUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void ADDUINT48_STATIC_IDATA(uint48t __idata* out , const  uint48t __code* inp1 , const  uint48t __code* inp2){
    ADDUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void ADDUINT48_STATIC_XDATA(uint48t __xdata* out , const  uint48t __code* inp1 , const  uint48t __code* inp2){
    ADDUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

/*                                                       UINT56                                                                                           */
inline void ADDUINT56(uint56t* out , const  uint56t* inp1 , const  uint56t* inp2){
    ADDUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void ADDUINT56_IDATA(uint56t __idata* out , const  uint56t __idata* inp1 , const  uint56t __idata* inp2){
    ADDUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void ADDUINT56_XDATA(uint56t __xdata* out , const  uint56t __xdata* inp1 , const  uint56t __xdata* inp2){
    ADDUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void ADDUINT56_STATIC_IDATA(uint56t __idata* out , const  uint56t __code* inp1 , const  uint56t __code* inp2){
    ADDUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void ADDUINT56_STATIC_XDATA(uint56t __xdata* out , const  uint56t __code* inp1 , const  uint56t __code* inp2){
    ADDUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

/*                                        UINT64                                                                                                         */


/*                                    SUB UINT                                         */
void SUBUINTC(uint8t* out , const uint8t* inp1 , const uint8t* inp2 , uint8t size) __reentrant;
void SUBUINTC_IDATA(uint8t __idata* out , const uint8t __idata* inp1 , const uint8t __idata* inp2 , uint8t size);
void SUBUINTC_XDATA(uint8t __xdata* out , const uint8t __xdata* inp1 , const uint8t __xdata* inp2 , uint8t size);
void SUBUINTC_STATIC_IDATA(uint8t __idata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size);
void SUBUINTC_STATIC_XDATA(uint8t __xdata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size);

/*                                       UINT24                                                                               */

inline void SUBUINT24(uint24t* out , const  uint24t* inp1 , const  uint24t* inp2){
    SUBUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void SUBUINT24_IDATA(uint24t __idata* out , const  uint24t __idata* inp1 , const  uint24t __idata* inp2){
    SUBUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes,UINT24T_SIZE);
}

inline void SUBUINT24_XDATA(uint24t __xdata* out , const  uint24t __xdata* inp1 , const  uint24t __xdata* inp2){
    SUBUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void SUBUINT24_STATIC_IDATA(uint24t __idata* out , const  uint24t __code* inp1 , const  uint24t __code* inp2){
    SUBUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void SUBUINT24_STATIC_XDATA(uint24t __xdata* out , const  uint24t __code* inp1 , const  uint24t __code* inp2){
    SUBUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes ,UINT24T_SIZE);
}


/*                                                          UINT40                                                                */


inline void SUBUINT40(uint40t* out , const  uint40t* inp1 , const  uint40t* inp2){
    SUBUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void SUBUINT40_IDATA(uint40t __idata* out , const  uint40t __idata* inp1 , const  uint40t __idata* inp2){
    SUBUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void SUBUINT40_XDATA(uint40t __xdata* out , const  uint40t __xdata* inp1 , const  uint40t __xdata* inp2){
    SUBUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void SUBUINT40_STATIC_IDATA(uint40t __idata* out , const  uint40t __code* inp1 , const  uint40t __code* inp2){
    SUBUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void SUBUINT40_STATIC_XDATA(uint40t __xdata* out , const  uint40t __code* inp1 , const  uint40t __code* inp2){
    SUBUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

/*                                                              UINT 48                                                                                      */

inline void SUBUINT48(uint48t* out , const  uint48t* inp1 , const  uint48t* inp2){
    SUBUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void SUBUINT48_IDATA(uint48t __idata* out , const  uint48t __idata* inp1 , const  uint48t __idata* inp2){
    SUBUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void SUBUINT48_XDATA(uint48t __xdata* out , const  uint48t __xdata* inp1 , const  uint48t __xdata* inp2){
    SUBUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void SUBUINT48_STATIC_IDATA(uint48t __idata* out , const  uint48t __code* inp1 , const  uint48t __code* inp2){
    SUBUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void SUBUINT48_STATIC_XDATA(uint48t __xdata* out , const  uint48t __code* inp1 , const  uint48t __code* inp2){
    SUBUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}


/*                                                              UINT56                                                                                        */

inline void SUBUINT56(uint56t* out , const  uint56t* inp1 , const  uint56t* inp2){
    SUBUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void SUBUINT56_IDATA(uint56t __idata* out , const  uint56t __idata* inp1 , const  uint56t __idata* inp2){
    SUBUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void SUBUINT56_XDATA(uint56t __xdata* out , const  uint56t __xdata* inp1 , const  uint56t __xdata* inp2){
    SUBUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void SUBUINT56_STATIC_IDATA(uint56t __idata* out , const  uint56t __code* inp1 , const  uint56t __code* inp2){
    SUBUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void SUBUINT56_STATIC_XDATA(uint56t __xdata* out , const  uint56t __code* inp1 , const  uint56t __code* inp2){
    SUBUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}


/*                                                             UINT64                                                                           */



void MULUINTC(uint8t* out , const uint8t* inp1 , const uint8t* inp2 , uint8t size) __reentrant;
void MULUINTC_IDATA(uint8t __idata* out , const uint8t __idata* inp1 , const uint8t __idata* inp2 , uint8t size);
void MULUINTC_XDATA(uint8t __xdata* out , const uint8t __xdata* inp1 , const uint8t __xdata* inp2 , uint8t size);
void MULUINTC_STATIC_IDATA(uint8t __idata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size);
void MULUINTC_STATIC_XDATA(uint8t __xdata* out , const uint8t __code* inp1 , const uint8t __code* inp2 , uint8t size);


inline void MULUINT24(uint24t* out , const  uint24t* inp1 , const  uint24t* inp2){
    MULUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void MULUINT24_IDATA(uint24t __idata* out , const  uint24t __idata* inp1 , const  uint24t __idata* inp2){
    MULUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes,UINT24T_SIZE);
}

inline void MULUINT24_XDATA(uint24t __xdata* out , const  uint24t __xdata* inp1 , const  uint24t __xdata* inp2){
    MULUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void MULUINT24_STATIC_IDATA(uint24t __idata* out , const  uint24t __code* inp1 , const  uint24t __code* inp2){
    MULUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT24T_SIZE);
}

inline void MULUINT24_STATIC_XDATA(uint24t __xdata* out , const  uint24t __code* inp1 , const  uint24t __code* inp2){
    MULUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes ,UINT24T_SIZE);
}


/*                                                          UINT40                                                                */


inline void MULUINT40(uint40t* out , const  uint40t* inp1 , const  uint40t* inp2){
    MULUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void MULUINT40_IDATA(uint40t __idata* out , const  uint40t __idata* inp1 , const  uint40t __idata* inp2){
    MULUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void MULUINT40_XDATA(uint40t __xdata* out , const  uint40t __xdata* inp1 , const  uint40t __xdata* inp2){
    MULUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void MULUINT40_STATIC_IDATA(uint40t __idata* out , const  uint40t __code* inp1 , const  uint40t __code* inp2){
    MULUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

inline void MULUINT40_STATIC_XDATA(uint40t __xdata* out , const  uint40t __code* inp1 , const  uint40t __code* inp2){
    MULUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT40T_SIZE);
}

/*                                                              UINT 48                                                                                      */

inline void MULUINT48(uint48t* out , const  uint48t* inp1 , const  uint48t* inp2){
    MULUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void MULUINT48_IDATA(uint48t __idata* out , const  uint48t __idata* inp1 , const  uint48t __idata* inp2){
    MULUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void MULUINT48_XDATA(uint48t __xdata* out , const  uint48t __xdata* inp1 , const  uint48t __xdata* inp2){
    MULUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void MULUINT48_STATIC_IDATA(uint48t __idata* out , const  uint48t __code* inp1 , const  uint48t __code* inp2){
    MULUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}

inline void MULUINT48_STATIC_XDATA(uint48t __xdata* out , const  uint48t __code* inp1 , const  uint48t __code* inp2){
    MULUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT48T_SIZE);
}


/*                                                              UINT56                                                                                        */

inline void MULUINT56(uint56t* out , const  uint56t* inp1 , const  uint56t* inp2){
    MULUINTC(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void MULUINT56_IDATA(uint56t __idata* out , const  uint56t __idata* inp1 , const  uint56t __idata* inp2){
    MULUINTC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void MULUINT56_XDATA(uint56t __xdata* out , const  uint56t __xdata* inp1 , const  uint56t __xdata* inp2){
    MULUINTC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void MULUINT56_STATIC_IDATA(uint56t __idata* out , const  uint56t __code* inp1 , const  uint56t __code* inp2){
    MULUINTC_STATIC_IDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}

inline void MULUINT56_STATIC_XDATA(uint56t __xdata* out , const  uint56t __code* inp1 , const  uint56t __code* inp2){
    MULUINTC_STATIC_XDATA(out->bytes , inp1->bytes , inp2->bytes , UINT56T_SIZE);
}



#endif //ttl52int_h