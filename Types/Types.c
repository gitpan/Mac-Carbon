/*
 * This file was generated automatically by xsubpp version 1.9508 from the 
 * contents of Types.xs. Do not edit this file, edit Types.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "Types.xs"
/* $Header: /cvsroot/macperl/perl/macos/ext/Mac/Types/Types.xs,v 1.3 2002/11/13 02:04:53 pudge Exp $
 *
 *    Copyright (c) 1996 Matthias Neeracher
 *
 *    You may distribute under the terms of the Perl Artistic License,
 *    as specified in the README file.
 *
 * $Log: Types.xs,v $
 * Revision 1.3  2002/11/13 02:04:53  pudge
 * Aieeeeee!  Big ol' Carbon update.
 *
 * Revision 1.2  2000/09/09 22:18:29  neeri
 * Dynamic libraries compile under 5.6
 *
 * Revision 1.1  2000/08/14 03:39:34  neeri
 * Checked into Sourceforge
 *
 * Revision 1.2  1997/11/18 00:53:26  neeri
 * MacPerl 5.1.5
 *
 * Revision 1.1  1997/04/07 20:50:56  neeri
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

#line 46 "Types.c"
XS(XS_Mac__Types_Debugger)
{
    dXSARGS;
    if (items < 0 || items > 1)
	Perl_croak(aTHX_ "Usage: Mac::Types::Debugger(msg=NULL)");
    {
	SV *	msg;

	if (items < 1)
	    msg = NULL;
	else {
	    msg = ST(0);
	}
#line 51 "Types.xs"
	if (msg) {
		Str255 message;
		MacPerl_CopyC2P(SvPV_nolen(msg), message);
		DebugStr(message);
	} else
		Debugger();
#line 67 "Types.c"
    }
    XSRETURN_EMPTY;
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Mac__Types)
{
    dXSARGS;
    char* file = __FILE__;

    XS_VERSION_BOOTCHECK ;

        newXS("Mac::Types::Debugger", XS_Mac__Types_Debugger, file);
    XSRETURN_YES;
}
