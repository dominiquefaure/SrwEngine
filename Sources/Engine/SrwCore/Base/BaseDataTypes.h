#ifndef __SRW_CORE_BASE_DATA_TYPES_H__
#define __SRW_CORE_BASE_DATA_TYPES_H__

#ifdef WIN32
#include<Windows.h>
#endif

typedef bool				SrwBool;
typedef char				SrwChar;
typedef signed char			SrwSint8;
typedef unsigned char		SrwUint8;
typedef signed short		SrwSint16;
typedef unsigned short		SrwUint16;
typedef signed long			SrwSint32;
typedef unsigned long		SrwUint32;
typedef signed long	long	SrwSint64;
typedef unsigned long long	SrwUint64;
typedef float				SrwFloat32;
typedef double				SrwFloat64;


#endif