#ifndef _CLASS_VBOX_H_
#define _CLASS_VBOX_H_
//=============================================================================
//
//   File : class_vbox.h
//   Creation date : Fri Mar 18 14:30:48 CEST 2005
//   by Tonino Imbesi(Grifisx) and Alessandro Carbone(Noldor)
//
//   This file is part of the KVirc irc client distribution
//   Copyright (C) 2005-2008 Alessandro Carbone (elfonol at gmail dot com)
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

#include "kvi_string.h"
#include "class_widget.h"
#include "object_macros.h"

class KviKvsObject_vbox : public KviKvsObject_widget
{
public:
	KVSO_DECLARE_OBJECT(KviKvsObject_vbox)
public:
	QWidget * widget() { return (QWidget *)object(); };
protected:
	virtual bool init(KviKvsRunTimeContext * pContext,KviKvsVariantList *pParams);
	bool setMargin(KviKvsObjectFunctionCall *c);
	bool setSpacing(KviKvsObjectFunctionCall *c);
	bool setStretchFactor(KviKvsObjectFunctionCall *c);
	bool addStretch(KviKvsObjectFunctionCall *c);
	bool setAlignment(KviKvsObjectFunctionCall *c);

};


#endif //_CLASS_HBOX_H_