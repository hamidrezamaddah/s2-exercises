#ifndef __BASICTYPES_H
#define __BASICTYPES_H	1

#ifdef __GNUC__
#ifdef __AVR__
#include "avr/pgmspace.h"
//#else
//#include "stdint.h"
#endif
#endif
#ifdef __SIMCOM_EAT__
#include "stdint.h"
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned short			UINT16;
typedef unsigned long			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;	
typedef signed short			INT16;
typedef signed long				INT32;
typedef unsigned long long		UINT64;
typedef long long				INT64;
typedef float					FLOAT32;
typedef double					FLOAT64;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#define PackedStruct			__packed struct
#define flash					const
#define PSTR
#define PROGMEM
#endif

#ifdef _MSC_VER
#include "stdint.h"
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned short			UINT16; 
typedef unsigned int			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;
typedef short					INT16;
typedef int						INT32;  
typedef float					FLOAT32;
typedef double					FLOAT64;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;


#define bit BOOLEAN
#define inline
#endif
#ifdef __CODEVISIONAVR__
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned int			UINT16;
typedef unsigned long			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;
typedef int						INT16;
typedef long					INT32;
typedef float					FLOAT32;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#endif
#ifdef __GNUC__
#ifdef __AVR__
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned int			UINT16; 
typedef unsigned long			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;	
typedef int						INT16;                                                            
typedef long					INT32;
typedef unsigned long long		UINT64;
typedef long long				INT64;
typedef float					FLOAT32;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#define flash
#define eeprom
#else
#define flash					const
#define eeprom
#define PROGMEM
#define PSTR
#endif

#if defined WINNT
#include "basetsd.h"
typedef char						CHAR;
typedef unsigned char				UCHAR;
//typedef unsigned char				UINT8;
//typedef __UINT16_TYPE__			UINT16;
//typedef unsigned long				UINT32;
//typedef volatile unsigned char	VUINT8;
//typedef signed char				INT8;
//typedef signed short				INT16;
//typedef signed long				INT32;
//typedef unsigned long long		UINT64;
//typedef long long					INT64;
typedef float						FLOAT32;
typedef unsigned char *				STRING;
typedef unsigned char				BOOLEAN;
#endif

#ifdef __ARM_EABI__
#include "stdint.h"
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef __UINT16_TYPE__			UINT16;
typedef unsigned long			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;
typedef signed short			INT16;
typedef signed long				INT32;
typedef unsigned long long		UINT64;
typedef long long				INT64;
typedef float					FLOAT32;
typedef double					FLOAT64;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#endif

#ifdef __ae32000__

#include "typedef.h"
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned short			UINT16;
typedef unsigned long			UINT32;
typedef volatile unsigned char	VUINT8;
typedef S8						INT8;
typedef S16						INT16;
typedef S32						INT32;
typedef U64						UINT64;
typedef long long				INT64;
typedef float					FLOAT32;
typedef double					FLOAT64;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#endif

#ifdef __XTENSA__
#include "stdint.h"
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned short			UINT16;
typedef unsigned int			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;
typedef signed short			INT16;
typedef signed int				INT32;
typedef unsigned long long		UINT64;
typedef long long				INT64;
typedef float					FLOAT32;
typedef double					FLOAT64;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#endif

#ifdef KEIL
#include "stdint.h"
typedef char					CHAR;
typedef unsigned char			UCHAR;
typedef unsigned char			UINT8;
typedef unsigned short			UINT16;
typedef unsigned int			UINT32;
typedef volatile unsigned char	VUINT8;
typedef signed char				INT8;
typedef signed short			INT16;
typedef signed int				INT32;
typedef unsigned long long		UINT64;
typedef long long				INT64;
typedef float					FLOAT32;
typedef double					FLOAT64;
typedef unsigned char *			STRING;
typedef unsigned char			BOOLEAN;
#endif

#endif

#define TRUE 1
#define FALSE 0

#endif
