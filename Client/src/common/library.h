#pragma once

#ifndef _LIBRARY_HEADER_
#define _LIBRARY_HEADER_

#include "../../library/include/data.h"
#include "../../library/include/quazip.h"
#include "../../library/include/Hades.h"
#include "../../library/include/Poseidon.h"
#include "../../library/include/sigslot_liangshi.h"

//�������ַ���һ��������ʵ���Բ���v8,����qtscript,����Ҳ��v8�����򵥶��ˣ����Ҳ��ÿ���ƽ̨����
/*
#define WIN32_LEAN_AND_MEAN
#define _WINSOCKAPI_

#include "../../library/include/script.h"
using namespace v8;
*/
#if defined(Q_OS_WIN32)
	//COM header files, windows is too big
	#include<ObjBase.h>

	#if defined(_LiangshiDLL)
		#define LIANGSHIEXPORT __declspec(dllexport)
	#else
		#if !defined(_LiangshiNoExport)
			#define LIANGSHIEXPORT __declspec(dllimport)
		#else
			#define LIANGSHIEXPORT
		#endif
	#endif

	#ifdef QT_DEBUG
		#define LIB_PATH	"../../library/lib/Win32/Debug/"
	#else
		#define LIB_PATH	"../../library/lib/Win32/Release/"
	#endif

	#pragma comment(lib, LIB_PATH"Hades.lib")
	#pragma comment(lib, LIB_PATH"Poseidon.lib")
#else
	#define LIANGSHIEXPORT __attribute__ ((visibility("default")))
#endif

#endif /* _LIBRARY_HEADER_ */
