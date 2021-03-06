/*
**  CXSC is a C++ library for eXtended Scientific Computing (V 2.5.4)
**
**  Copyright (C) 1990-2000 Institut fuer Angewandte Mathematik,
**                          Universitaet Karlsruhe, Germany
**            (C) 2000-2014 Wiss. Rechnen/Softwaretechnologie
**                          Universitaet Wuppertal, Germany   
**
**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Library General Public
**  License as published by the Free Software Foundation; either
**  version 2 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Library General Public License for more details.
**
**  You should have received a copy of the GNU Library General Public
**  License along with this library; if not, write to the Free
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* CVS $Id: a_mod_.c,v 1.21 2014/01/30 17:24:02 cxsc Exp $ */

/****************************************************************/
/*                                                              */
/*      Filename        : a_mod_.c                              */
/*                                                              */
/*      Entries         : a_intg a_mod_(i,j)                    */
/*                        a_intg i,j;                           */
/*                                                              */
/*      Arguments       : i = left integer argument             */
/*                        j = right integer argument            */
/*                                                              */
/*      Description     : Integer modulo according to           */
/*                        PASCAL Standard:                      */
/*                           error if j is non-positive         */
/*                           0 <= i mod j = i-k*j < j           */
/*                                          for integral k      */
/*                                                              */
/*      Note            : 0 returned in case of error           */
/*                                                              */
/****************************************************************/

#ifndef ALL_IN_ONE
#ifdef AIX
#include "/u/p88c/runtime/o_defs.h"
#else
#include "o_defs.h"
#endif
#define local
#endif

#ifdef LINT_ARGS
local a_intg a_mod_(a_intg i,a_intg j)
#else
local a_intg a_mod_(i,j)

a_intg i;
a_intg j;
#endif
        {
        a_intg res;

        E_TPUSH("a_mod_")

        if (j<=0)
           {
           e_trap(INV_ARG,6,E_TMSG,22,E_TINT+E_TEXT(1),&i,
                                      E_TINT+E_TEXT(2),&j);
           res = 0;
           }
        else if (i<0)
           {
           if (i==MININT) i += j;
           if ((res = i+j+((-i)/j)*j)==j) res = 0;
           }
        else
           res = i-(i/j)*j;

        E_TPOPP("a_mod_")
        return(res);
        }





