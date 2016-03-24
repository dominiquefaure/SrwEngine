#ifndef __SRW_CORE_COMMON_MACROS_H__
#define __SRW_CORE_COMMON_MACROS_H__


#define SAFE_DELETE( X ) if( X != NULL )\
{\
	delete X;\
	X = NULL;\
}

#endif