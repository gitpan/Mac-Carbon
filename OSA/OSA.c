/*
 * This file was generated automatically by xsubpp version 1.9508 from the 
 * contents of OSA.xs. Do not edit this file, edit OSA.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "OSA.xs"
/* $Header: /cvsroot/macperl/perl/macos/ext/Mac/OSA/OSA.xs,v 1.3 2002/12/10 02:12:06 pudge Exp $
 *
 *    Copyright (c) 1996 Matthias Neeracher
 *
 *    You may distribute under the terms of the Perl Artistic License,
 *    as specified in the README file.
 *
 * $Log: OSA.xs,v $
 * Revision 1.3  2002/12/10 02:12:06  pudge
 * Add Carbon support
 *
 * Revision 1.2  2000/09/09 22:18:28  neeri
 * Dynamic libraries compile under 5.6
 *
 * Revision 1.1  2000/08/14 03:39:32  neeri
 * Checked into Sourceforge
 *
 * Revision 1.2  1997/11/18 00:53:06  neeri
 * MacPerl 5.1.5
 *
 * Revision 1.1  1997/04/07 20:50:21  neeri
 * Synchronized with MacPerl 5.1.4a1
 *
 */

#define MAC_CONTEXT

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#ifndef MACOS_TRADITIONAL
#include "../Carbon.h"
#endif
#include <Types.h>
#include <Memory.h>
#include <OSA.h>
#include <OSAGeneric.h>

#line 49 "OSA.c"
XS(XS_Mac__OSA_OSALoad)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSALoad(scriptingComponent, scriptData, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	scriptData;
	long	modeFlags = (long)SvIV(ST(2));
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&scriptData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("scriptData is not of type AEDesc");
#line 64 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSALoad(scriptingComponent, &scriptData, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 70 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAStore)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAStore(scriptingComponent, scriptID, desiredType, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptID = (unsigned long)SvUV(ST(1));
	OSType	desiredType;
	long	modeFlags = (long)SvIV(ST(3));
	AEDesc	RETVAL;

	memcpy(&desiredType, SvPV_nolen(ST(2)), sizeof(OSType));
#line 86 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAStore(scriptingComponent, scriptID, desiredType, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 93 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAExecute)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAExecute(scriptingComponent, compiledScriptID, contextID, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	compiledScriptID = (unsigned long)SvUV(ST(1));
	OSAID	contextID = (unsigned long)SvUV(ST(2));
	long	modeFlags = (long)SvIV(ST(3));
	OSAID	RETVAL;
	dXSTARG;
#line 109 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAExecute(scriptingComponent, compiledScriptID, contextID, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 116 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSADisplay)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSADisplay(scriptingComponent, scriptValueID, desiredType, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptValueID = (unsigned long)SvUV(ST(1));
	OSType	desiredType;
	long	modeFlags = (long)SvIV(ST(3));
	AEDesc	RETVAL;

	memcpy(&desiredType, SvPV_nolen(ST(2)), sizeof(OSType));
#line 132 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSADisplay(scriptingComponent, scriptValueID, desiredType, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 139 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAScriptError)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAScriptError(scriptingComponent, selector, desiredType)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSType	selector;
	OSType	desiredType;
	AEDesc	RETVAL;

	memcpy(&selector, SvPV_nolen(ST(1)), sizeof(OSType));

	memcpy(&desiredType, SvPV_nolen(ST(2)), sizeof(OSType));
#line 157 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAScriptError(scriptingComponent, selector, desiredType, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 164 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSADispose)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSADispose(scriptingComponent, scriptID)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptID = (unsigned long)SvUV(ST(1));
	OSAError	RETVAL;
	dXSTARG;

	RETVAL = OSADispose(scriptingComponent, scriptID);
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSASetScriptInfo)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSASetScriptInfo(scriptingComponent, scriptID, selector, value)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptID = (unsigned long)SvUV(ST(1));
	OSType	selector;
	long	value = (long)SvIV(ST(3));
	OSAError	RETVAL;
	dXSTARG;

	memcpy(&selector, SvPV_nolen(ST(2)), sizeof(OSType));

	RETVAL = OSASetScriptInfo(scriptingComponent, scriptID, selector, value);
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetScriptInfo)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetScriptInfo(scriptingComponent, scriptID, selector)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptID = (unsigned long)SvUV(ST(1));
	OSType	selector;
	long	RETVAL;
	dXSTARG;

	memcpy(&selector, SvPV_nolen(ST(2)), sizeof(OSType));
#line 207 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetScriptInfo(scriptingComponent, scriptID, selector, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 226 "OSA.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAScriptingComponentName)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAScriptingComponentName(scriptingComponent)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	RETVAL;
#line 226 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAScriptingComponentName(scriptingComponent, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 244 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSACompile)
{
    dXSARGS;
    if (items < 3 || items > 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSACompile(scriptingComponent, sourceData, modeFlags, previousScriptID = 0)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	sourceData;
	long	modeFlags = (long)SvIV(ST(2));
	OSAID	previousScriptID;
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&sourceData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("sourceData is not of type AEDesc");

	if (items < 4)
	    previousScriptID = 0;
	else {
	    previousScriptID = (unsigned long)SvUV(ST(3));
	}
#line 250 "OSA.xs"
	RETVAL = previousScriptID;
	if (gMacPerl_OSErr = (short) OSACompile(scriptingComponent, &sourceData, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 279 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSACopyID)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSACopyID(scriptingComponent, fromID, toID = 0)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	fromID = (unsigned long)SvUV(ST(1));
	OSAID	toID;
	OSAID	RETVAL;
	dXSTARG;

	if (items < 3)
	    toID = 0;
	else {
	    toID = (unsigned long)SvUV(ST(2));
	}
#line 271 "OSA.xs"
	RETVAL = toID;
	if (gMacPerl_OSErr = (short) OSACopyID(scriptingComponent, fromID, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 307 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetSource)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetSource(scriptingComponent, scriptID, desiredType = 'TEXT')");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptID = (unsigned long)SvUV(ST(1));
	OSType	desiredType;
	AEDesc	RETVAL;

	if (items < 3)
	    desiredType = 'TEXT';
	else {
	    memcpy(&desiredType, SvPV_nolen(ST(2)), sizeof(OSType));
	}
#line 291 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetSource(scriptingComponent, scriptID, desiredType, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 333 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSACoerceFromDesc)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSACoerceFromDesc(scriptingComponent, scriptData, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	scriptData;
	long	modeFlags = (long)SvIV(ST(2));
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&scriptData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("scriptData is not of type AEDesc");
#line 310 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSACoerceFromDesc(scriptingComponent, &scriptData, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 360 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSACoerceToDesc)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSACoerceToDesc(scriptingComponent, scriptID, desiredType, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	scriptID = (unsigned long)SvUV(ST(1));
	OSType	desiredType;
	long	modeFlags = (long)SvIV(ST(3));
	AEDesc	RETVAL;

	memcpy(&desiredType, SvPV_nolen(ST(2)), sizeof(OSType));
#line 331 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSACoerceToDesc(scriptingComponent, scriptID, desiredType, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 383 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSASetDefaultTarget)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSASetDefaultTarget(scriptingComponent, target)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	target;
	OSAError	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&target, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("target is not of type AEDesc");

	RETVAL = OSASetDefaultTarget(scriptingComponent, &target);
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAStartRecording)
{
    dXSARGS;
    if (items < 1 || items > 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAStartRecording(scriptingComponent, compiledScriptToModifyID = 0)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	compiledScriptToModifyID;
	OSAID	RETVAL;
	dXSTARG;

	if (items < 2)
	    compiledScriptToModifyID = 0;
	else {
	    compiledScriptToModifyID = (unsigned long)SvUV(ST(1));
	}
#line 365 "OSA.xs"
	RETVAL = compiledScriptToModifyID;
	if (gMacPerl_OSErr = (short) OSAStartRecording(scriptingComponent, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 433 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAStopRecording)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAStopRecording(scriptingComponent, compiledScriptID)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	compiledScriptID = (unsigned long)SvUV(ST(1));
	OSAError	RETVAL;
	dXSTARG;

	RETVAL = OSAStopRecording(scriptingComponent, compiledScriptID);
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSALoadExecute)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSALoadExecute(scriptingComponent, scriptData, contextID, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	scriptData;
	OSAID	contextID = (unsigned long)SvUV(ST(2));
	long	modeFlags = (long)SvIV(ST(3));
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&scriptData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("scriptData is not of type AEDesc");
#line 407 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSALoadExecute(scriptingComponent, &scriptData, contextID, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 477 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSACompileExecute)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSACompileExecute(scriptingComponent, sourceData, contextID, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	sourceData;
	OSAID	contextID = (unsigned long)SvUV(ST(2));
	long	modeFlags = (long)SvIV(ST(3));
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&sourceData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("sourceData is not of type AEDesc");
#line 431 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSACompileExecute(scriptingComponent, &sourceData, contextID, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 504 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSADoScript)
{
    dXSARGS;
    if (items != 5)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSADoScript(scriptingComponent, sourceData, contextID, desiredType, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	sourceData;
	OSAID	contextID = (unsigned long)SvUV(ST(2));
	OSType	desiredType;
	long	modeFlags = (long)SvIV(ST(4));
	AEDesc	RETVAL;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&sourceData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("sourceData is not of type AEDesc");

	memcpy(&desiredType, SvPV_nolen(ST(3)), sizeof(OSType));
#line 455 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSADoScript(scriptingComponent, &sourceData, contextID, desiredType, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 533 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSASetCurrentDialect)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSASetCurrentDialect(scriptingComponent, dialectCode)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	short	dialectCode = (short)SvIV(ST(1));
	OSAError	RETVAL;
	dXSTARG;

	RETVAL = OSASetCurrentDialect(scriptingComponent, dialectCode);
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetCurrentDialect)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetCurrentDialect(scriptingComponent)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	short	RETVAL;
	dXSTARG;
#line 483 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetCurrentDialect(scriptingComponent, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 570 "OSA.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAAvailableDialects)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAAvailableDialects(scriptingComponent)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	RETVAL;
#line 500 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAAvailableDialects(scriptingComponent, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 588 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetDialectInfo)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetDialectInfo(scriptingComponent, dialectCode, selector)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	short	dialectCode = (short)SvIV(ST(1));
	OSType	selector;
	AEDesc	RETVAL;

	memcpy(&selector, SvPV_nolen(ST(2)), sizeof(OSType));
#line 521 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetDialectInfo(scriptingComponent, dialectCode, selector, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 611 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAAvailableDialectCodeList)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAAvailableDialectCodeList(scriptingComponent)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	RETVAL;
#line 538 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAAvailableDialectCodeList(scriptingComponent, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 630 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAExecuteEvent)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAExecuteEvent(scriptingComponent, theAppleEvent, contextID, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	theAppleEvent;
	OSAID	contextID = (unsigned long)SvUV(ST(2));
	long	modeFlags = (long)SvIV(ST(3));
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&theAppleEvent, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("theAppleEvent is not of type AEDesc");
#line 559 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAExecuteEvent(scriptingComponent, &theAppleEvent, contextID, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 658 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSADoEvent)
{
    dXSARGS;
    if (items != 4)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSADoEvent(scriptingComponent, theAppleEvent, contextID, modeFlags)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	theAppleEvent;
	OSAID	contextID = (unsigned long)SvUV(ST(2));
	long	modeFlags = (long)SvIV(ST(3));
	AEDesc	RETVAL;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&theAppleEvent, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("theAppleEvent is not of type AEDesc");
#line 583 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSADoEvent(scriptingComponent, &theAppleEvent, contextID, modeFlags, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 684 "OSA.c"
	ST(0) = sv_newmortal();
	sv_setref_pvn(ST(0), "AEDesc", (void*)&RETVAL, sizeof(AEDesc));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAMakeContext)
{
    dXSARGS;
    if (items < 2 || items > 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAMakeContext(scriptingComponent, contextName, parentContext = 0)");
    {
	ComponentInstance	scriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	contextName;
	OSAID	parentContext;
	OSAID	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&contextName, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("contextName is not of type AEDesc");

	if (items < 3)
	    parentContext = 0;
	else {
	    parentContext = (unsigned long)SvUV(ST(2));
	}
#line 603 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAMakeContext(scriptingComponent, &contextName, parentContext, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 717 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetDefaultScriptingComponent)
{
    dXSARGS;
    if (items != 1)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetDefaultScriptingComponent(genericScriptingComponent)");
    {
	ComponentInstance	genericScriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSType	RETVAL;
	dXSTARG;
#line 624 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetDefaultScriptingComponent(genericScriptingComponent, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 736 "OSA.c"
	XSprePUSH; PUSHp((char *) &RETVAL, 4);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSASetDefaultScriptingComponent)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSASetDefaultScriptingComponent(genericScriptingComponent, scriptingSubType)");
    {
	ComponentInstance	genericScriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSType	scriptingSubType;
	OSAError	RETVAL;
	dXSTARG;

	memcpy(&scriptingSubType, SvPV_nolen(ST(1)), sizeof(OSType));

	RETVAL = OSASetDefaultScriptingComponent(genericScriptingComponent, scriptingSubType);
	XSprePUSH; PUSHi((IV)!(gMacPerl_OSErr = (short)(RETVAL)));
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetScriptingComponent)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetScriptingComponent(genericScriptingComponent, scriptingSubType)");
    {
	ComponentInstance	genericScriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSType	scriptingSubType;
	ComponentInstance	RETVAL;
	dXSTARG;

	memcpy(&scriptingSubType, SvPV_nolen(ST(1)), sizeof(OSType));
#line 660 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetScriptingComponent(genericScriptingComponent, scriptingSubType, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 777 "OSA.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGetScriptingComponentFromStored)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGetScriptingComponentFromStored(genericScriptingComponent, scriptData)");
    {
	ComponentInstance	genericScriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	AEDesc	scriptData;
	OSType	RETVAL;
	dXSTARG;

	if (sv_isa(ST(1), "AEDesc"))
	    memcpy(&scriptData, SvPV_nolen((SV*)SvRV(ST(1))), sizeof(AEDesc));
	else
	    croak("scriptData is not of type AEDesc");
#line 679 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGetScriptingComponentFromStored(genericScriptingComponent, &scriptData, &RETVAL)) {
		XSRETURN_UNDEF;
	}
#line 802 "OSA.c"
	XSprePUSH; PUSHp((char *) &RETVAL, 4);
    }
    XSRETURN(1);
}

XS(XS_Mac__OSA_OSAGenericToRealID)
{
    dXSARGS;
    if (items != 2)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSAGenericToRealID(genericScriptingComponent, genericScriptID)");
    SP -= items;
    {
	ComponentInstance	genericScriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	genericScriptID = (unsigned long)SvUV(ST(1));
#line 698 "OSA.xs"
	ComponentInstance	exactScriptingComponent;
#line 819 "OSA.c"
#line 700 "OSA.xs"
	if (gMacPerl_OSErr = (short) OSAGenericToRealID(genericScriptingComponent, &genericScriptID, &exactScriptingComponent)) {
		XSRETURN_EMPTY;
	}
	EXTEND(sp, 1);
	++sp;
	*sp = sv_newmortal();
	sv_setuv(*sp, (UV)(genericScriptID));
	EXTEND(sp, 1);
	++sp;
	*sp = sv_newmortal();
	sv_setiv(*sp, (IV)(exactScriptingComponent));
#line 832 "OSA.c"
	PUTBACK;
	return;
    }
}

XS(XS_Mac__OSA_OSARealToGenericID)
{
    dXSARGS;
    if (items != 3)
	Perl_croak(aTHX_ "Usage: Mac::OSA::OSARealToGenericID(genericScriptingComponent, theScriptID, theExactComponent)");
    {
	ComponentInstance	genericScriptingComponent = INT2PTR(ComponentInstance,SvIV(ST(0)));
	OSAID	theScriptID = (unsigned long)SvUV(ST(1));
	ComponentInstance	theExactComponent = INT2PTR(ComponentInstance,SvIV(ST(2)));
	OSAID	RETVAL;
	dXSTARG;
#line 723 "OSA.xs"
	RETVAL = theScriptID;
	if (gMacPerl_OSErr = (short) OSARealToGenericID(genericScriptingComponent, &RETVAL, theExactComponent)) {
		XSRETURN_UNDEF;
	}
#line 854 "OSA.c"
	XSprePUSH; PUSHu((UV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Mac__OSA)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        newXS("Mac::OSA::OSALoad", XS_Mac__OSA_OSALoad, file);
        newXS("Mac::OSA::OSAStore", XS_Mac__OSA_OSAStore, file);
        newXS("Mac::OSA::OSAExecute", XS_Mac__OSA_OSAExecute, file);
        newXS("Mac::OSA::OSADisplay", XS_Mac__OSA_OSADisplay, file);
        newXS("Mac::OSA::OSAScriptError", XS_Mac__OSA_OSAScriptError, file);
        newXS("Mac::OSA::OSADispose", XS_Mac__OSA_OSADispose, file);
        newXS("Mac::OSA::OSASetScriptInfo", XS_Mac__OSA_OSASetScriptInfo, file);
        newXS("Mac::OSA::OSAGetScriptInfo", XS_Mac__OSA_OSAGetScriptInfo, file);
        newXS("Mac::OSA::OSAScriptingComponentName", XS_Mac__OSA_OSAScriptingComponentName, file);
        newXS("Mac::OSA::OSACompile", XS_Mac__OSA_OSACompile, file);
        newXS("Mac::OSA::OSACopyID", XS_Mac__OSA_OSACopyID, file);
        newXS("Mac::OSA::OSAGetSource", XS_Mac__OSA_OSAGetSource, file);
        newXS("Mac::OSA::OSACoerceFromDesc", XS_Mac__OSA_OSACoerceFromDesc, file);
        newXS("Mac::OSA::OSACoerceToDesc", XS_Mac__OSA_OSACoerceToDesc, file);
        newXS("Mac::OSA::OSASetDefaultTarget", XS_Mac__OSA_OSASetDefaultTarget, file);
        newXS("Mac::OSA::OSAStartRecording", XS_Mac__OSA_OSAStartRecording, file);
        newXS("Mac::OSA::OSAStopRecording", XS_Mac__OSA_OSAStopRecording, file);
        newXS("Mac::OSA::OSALoadExecute", XS_Mac__OSA_OSALoadExecute, file);
        newXS("Mac::OSA::OSACompileExecute", XS_Mac__OSA_OSACompileExecute, file);
        newXS("Mac::OSA::OSADoScript", XS_Mac__OSA_OSADoScript, file);
        newXS("Mac::OSA::OSASetCurrentDialect", XS_Mac__OSA_OSASetCurrentDialect, file);
        newXS("Mac::OSA::OSAGetCurrentDialect", XS_Mac__OSA_OSAGetCurrentDialect, file);
        newXS("Mac::OSA::OSAAvailableDialects", XS_Mac__OSA_OSAAvailableDialects, file);
        newXS("Mac::OSA::OSAGetDialectInfo", XS_Mac__OSA_OSAGetDialectInfo, file);
        newXS("Mac::OSA::OSAAvailableDialectCodeList", XS_Mac__OSA_OSAAvailableDialectCodeList, file);
        newXS("Mac::OSA::OSAExecuteEvent", XS_Mac__OSA_OSAExecuteEvent, file);
        newXS("Mac::OSA::OSADoEvent", XS_Mac__OSA_OSADoEvent, file);
        newXS("Mac::OSA::OSAMakeContext", XS_Mac__OSA_OSAMakeContext, file);
        newXS("Mac::OSA::OSAGetDefaultScriptingComponent", XS_Mac__OSA_OSAGetDefaultScriptingComponent, file);
        newXS("Mac::OSA::OSASetDefaultScriptingComponent", XS_Mac__OSA_OSASetDefaultScriptingComponent, file);
        newXS("Mac::OSA::OSAGetScriptingComponent", XS_Mac__OSA_OSAGetScriptingComponent, file);
        newXS("Mac::OSA::OSAGetScriptingComponentFromStored", XS_Mac__OSA_OSAGetScriptingComponentFromStored, file);
        newXS("Mac::OSA::OSAGenericToRealID", XS_Mac__OSA_OSAGenericToRealID, file);
        newXS("Mac::OSA::OSARealToGenericID", XS_Mac__OSA_OSARealToGenericID, file);
    XSRETURN_YES;
}

