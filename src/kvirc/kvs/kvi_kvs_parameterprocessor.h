#ifndef _KVI_KVS_PARAMETERPROCESSOR_H_
#define _KVI_KVS_PARAMETERPROCESSOR_H_
//=============================================================================
//
//   File : kvi_kvs_parameterprocessor.h
//   Creation date : Sun 17 Apr 2005 16:47:09 by Szymon Stefanek
//
//   This file is part of the KVIrc IRC client distribution
//   Copyright (C) 2005-2008 Szymon Stefanek <pragma at kvirc dot net>
//
//   This program is FREE software. You can redistribute it and/or
//   modify it under the terms of the GNU General Public License
//   as published by the Free Software Foundation; either version 2
//   of the License, or (at your opinion) any later version.
//
//   This program is distributed in the HOPE that it will be USEFUL,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public License
//   along with this program. If not, write to the Free Software Foundation,
//   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
//
//=============================================================================

#include "kvi_settings.h"
#include "kvi_kvs_types.h"

class KviKvsHash;
class KviKvsArray;
class KviKvsArrayCast;
class KviKvsVariant;
class QStringList;
class QByteArray;
class QString;

// Data type: QString
// Default: QString()
#define KVS_PT_STRING 0

// Data type: QString
// Default: QString()
#define KVS_PT_NONEMPTYSTRING 1

// Data type: kvs_int_t
// Default: 0
#define KVS_PT_INT 2
	#define KVS_PT_INTEGER 2

// Data type: kvs_uint_t
// Default: 0
#define KVS_PT_UINT 3
	#define KVS_PT_UNSIGNEDINTEGER 3

// Data type: kvs_real_t
// default: 0.0
#define KVS_PT_DOUBLE 4
	#define KVS_PT_REAL 4

// Data type: bool
// default: false
#define KVS_PT_BOOL 5
	#define KVS_PT_BOOLEAN 5

// Data type: KviKvsHash *
// default: 0
#define KVS_PT_HASH 6

// Data type: KviKvsArrayCast
// default empty cast
#define KVS_PT_ARRAYCAST 7

// Data type: KviKvsVariant *
// default: 0
#define KVS_PT_VARIANT 8

// Data type: QByteArray
// default null string (0)
#define KVS_PT_CSTRING 9

// Data type: QByteArray
// default null string (0)
#define KVS_PT_NONEMPTYCSTRING 10

// Data type: QStringList
// default: list cleared
// This eats all the remaining params in the list!
#define KVS_PT_STRINGLIST 11

// Data type: KviKvsVariantList
// default: list cleared
// This eats all the remaining params in the list!
// The list has autodelete set to off since the copies are SHALLOW!
#define KVS_PT_VARIANTLIST 12

// Data type: kvs_hobject_t
// default: (kvs_hobject_t)0
#define KVS_PT_HOBJECT 13

// Data type: KviKvsArray *
// default 0
#define KVS_PT_ARRAY 14

// Data type: ignored
#define KVS_PT_IGNORE 15

// If omitted, set to default
#define KVS_PF_OPTIONAL 1
// Valid only for string types: it's the last parameter that eats all the remaining ones
#define KVS_PF_APPENDREMAINING 2

class KviKvsVariantList;
class KviKvsRunTimeContext;


namespace KviKvsParameterProcessor
{
	class KVIRC_API ParameterFormat
	{
	public:
		const char          * szName;
		const unsigned char   uType;
		const unsigned char   uFlags;
		void                * pContainer;
	public:
		// KVS_PT_STRING, KVS_PT_NONEMPTYSTRING
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,QString &szBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&szBuffer)) {};

		// KVS_PT_INTEGER (KVS_PT_INT)
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,kvs_int_t &iBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&iBuffer)) {};

		// KVS_PT_UNSIGNEDINTEGER (KVS_PT_UINT)
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,kvs_uint_t &uBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&uBuffer)) {};

		// KVS_PT_DOUBLE (KVS_PT_REAL)
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,kvs_real_t &dBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&dBuffer)) {};

		// KVS_PT_BOOL (KVS_PT_BOOLEAN)
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,bool &bBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&bBuffer)) {};

		// KVS_PT_HASH
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,KviKvsHash * &pBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&pBuffer)) {};

		// KVS_PT_ARRAYCAST
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,KviKvsArrayCast &oBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&oBuffer)) {};

		// KVS_PT_VARIANT
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,KviKvsVariant * &pBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&pBuffer)) {};

		// KVS_PT_CSTRING, KVS_PT_NONEMPTYCSTRING
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,QByteArray &szBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&szBuffer)) {};

		// KVS_PT_STRINGLIST
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,QStringList &lBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&lBuffer)) {};

		// KVS_PT_VARIANTLIST
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,KviKvsVariantList &lBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&lBuffer)) {};

		// KVS_PT_HOBJECT
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,kvs_hobject_t &hBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&hBuffer)) {};

		// KVS_PT_ARRAY
		ParameterFormat(const char * name,const unsigned char type,const unsigned char flags,KviKvsArray * &pBuffer)
			: szName(name), uType(type), uFlags(flags), pContainer((void *)(&pBuffer)) {};

		// KVS_PT_IGNORE
		ParameterFormat(const char * name)
			: szName(name), uType(KVS_PT_IGNORE), uFlags(0), pContainer(NULL) {}

		// terminator
		ParameterFormat()
			: szName(NULL), uType(KVS_PT_IGNORE), uFlags(0), pContainer(NULL) {};

		//ParameterFormat(const char * n,const unsigned char t,const unsigned char f,void * p)
		//: szName(n), uType(t), uFlags(f), pContainer(p) {};
	};

	KVIRC_API bool process(KviKvsVariantList * pVariantList,KviKvsRunTimeContext * pContext,KviKvsParameterProcessor::ParameterFormat * pFmtArray);
}


#define KVS_PARAMETERS_BEGIN(__name) \
		KviKvsParameterProcessor::ParameterFormat __name[] = \
		{

#define KVS_PARAMETERS_END \
			KviKvsParameterProcessor::ParameterFormat(0) \
		};

//#define KVS_PARAMETER(__name,__type,__flags,__void)
//			KviKvsParameterProcessor::ParameterFormat(__name,__type,__flags,((void *)(&(__void)))),

#define KVS_PARAMETER(__name,__type,__flags,__param) \
			KviKvsParameterProcessor::ParameterFormat(__name,__type,__flags,__param),

#define KVS_PARAMETER_IGNORED(__name) \
			KviKvsParameterProcessor::ParameterFormat(__name),

#endif //!_KVI_KVS_PARAMETERPROCESSOR_H_
