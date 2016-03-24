#ifndef __SRW_CORE_SINGLETON_H__
#define __SRW_CORE_SINGLETON_H__

#include "../Base/CommonMacros.h"

namespace SrwCore
{
	template <typename T> 
	class Singleton
	{
	public:

		//------------------------------------------------------------
		static inline void CreateInstance()
		{
			//Todo : Add Assert

			s_instance										=	new T();

			s_instance->OnInit();
		}
		//------------------------------------------------------------

		//------------------------------------------------------------
		static inline void DestroyInstance()
		{
			SAFE_DELETE( s_instance );
		}
		//------------------------------------------------------------

		//------------------------------------------------------------
		static inline T& GetInstance()
		{
			return s_instance;
		}
		//------------------------------------------------------------

		//------------------------------------------------------------
		/*
		* Allow custom initializations
		*/
		virtual void OnInit()
		{
		}
		//------------------------------------------------------------

	protected:

		Singleton(){}
		virtual ~Singleton(){}

	private:
		static T* s_instance;
	};

	template<typename T> T* Singleton<T>::s_instance	=	NULL;
}

#endif