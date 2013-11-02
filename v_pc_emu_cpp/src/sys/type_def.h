#ifndef _TYPE_DEF_H_
#define _TYPE_DEF_H_

//TODO: remove not necessery things


/*****************************************************************************
                  Exported symbolic constants
*****************************************************************************/

#define SET   (1U)
#define RESET (0)

#define ON    (1U)
#define OFF   (0)

#define FALSE (0)
#define TRUE  (!FALSE)

/* ISO standard for signed and unsigned fixed-size integer data types */
typedef unsigned char     uint8_t;
typedef   signed char     int8_t;
typedef unsigned short    uint16_t;
typedef   signed short    int16_t;
typedef unsigned long     uint32_t;
typedef   signed long     int32_t;


typedef uint8_t  bitfield8_t;
typedef uint16_t bitfield16_t;
typedef uint32_t bitfield32_t;


//todo check is it needed
// Data type ranges:
#define MIN_UINT8         ((uint8_t)0x00U)  /*  8 bit unsigned */
#define MAX_UINT8         ((uint8_t)0xFFU)
#define MIN_INT8           ((int8_t)-128)   /*  8 bit signed   */
#define MAX_INT8            ((int8_t)127)
#define MIN_UINT16     ((uint16_t)0x0000U)  /* 16 bit unsigned */
#define MAX_UINT16     ((uint16_t)0xFFFFU)
#define MIN_INT16       ((int16_t)-32768)   /* 16 bit signed   */
#define MAX_INT16        ((int16_t)32767)
#define MIN_UINT32 ((uint32_t)0x00000000UL) /* 32 bit unsigned */
#define MAX_UINT32 ((uint32_t)0xFFFFFFFFUL)
#define MIN_INT32   ((int32_t)0x80000000L)  /* 32 bit signed   */
#define MAX_INT32   ((int32_t)0x7FFFFFFFL)

//todo: check is it neeeded.
/* Data type ranges for use with abs function / macro: */
#define MIN_INT8_ABS  ((int8_t) (MIN_INT8 + 1))
#define MAX_INT8_ABS  MAX_INT8
#define MIN_INT16_ABS ((int16_t)(MIN_INT16 + 1))
#define MAX_INT16_ABS MAX_INT16
#define MIN_INT32_ABS ((int32_t)(MIN_INT32 + 1))
#define MAX_INT32_ABS MAX_INT32


#define NIBBLE_SIZE (4U)            /* nibble size in bits */
#define NIBBLES_IN_BYTE (2U)        /* number of nibbles in byte */

#define NIBBLE_LOW_MASK        (0x0FU)    /* Mask for a lower nibble of a byte  */
#define NIBBLE_HIGH_MASK       (0xF0U)    /* Mask for a higher nibble of a byte */
#define U16_LOW_BYTE_MASK      0x00FFU
#define U16_HIGH_BYTE_MASK     0xFF00U
#define U32_LOW_BYTE_MASK      0x000000FFUL
#define U32_MID_LOW_BYTE_MASK  0x0000FF00UL
#define U32_MID_HIGH_BYTE_MASK 0x00FF0000UL
#define U32_HIGH_BYTE_MASK     0xFF000000UL

#define GET_U8_LOW_NIBBLE(a)       (uint8_t)((a) & NIBBLE_LOW_MASK)
#define GET_U8_HIGH_NIBBLE(a)      (uint8_t)(((a) & NIBBLE_HIGH_MASK) >> NIBBLE_SIZE) 
#define GET_U16_LOW_BYTE(a)        (uint8_t)((a) & (U16_LOW_BYTE_MASK))
#define GET_U16_HIGH_BYTE(a)       (uint8_t)((((a) & (U16_HIGH_BYTE_MASK))) >> 8U)
#define GET_U32_LOW_BYTE(a)        (uint8_t)((a) & (U32_LOW_BYTE_MASK))
#define GET_U32_MID_LOW_BYTE(a)    (uint8_t)((((a) & (U32_MID_LOW_BYTE_MASK))) >> 8U)
#define GET_U32_MID_HIGH_BYTE(a)   (uint8_t)((((a) & (U32_MID_HIGH_BYTE_MASK))) >> 16U)
#define GET_U32_HIGH_BYTE(a)       (uint8_t)((((a) & (U32_HIGH_BYTE_MASK))) >> 24U)

#endif /* _TYPE_DEF_H_ */

