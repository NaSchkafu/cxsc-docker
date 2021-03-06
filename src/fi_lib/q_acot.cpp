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

/* CVS $Id: q_acot.cpp,v 1.15 2014/01/30 17:23:54 cxsc Exp $ */

#ifndef Q_ACOT_CPP
#define Q_ACOT_CPP

#include "fi_lib.hpp" 

namespace fi_lib {

 using cxsc::real;
 
 real q_acot(real x){
  real res;

  if(NANTEST(x))                                       /* Test: x=NaN */
      res=q_abortnan(INV_ARG,&x,17);
  else {
  /* main program with different cases */
    if ((-1e-17<x)&&(x<1e-17)) res=q_piha;
    else if (x<0) res=q_pi+q_atn1(1.0/x);
    else if (x<1e10) res= q_atn1(1.0/x); 
         else        res=1.0/x;     
  }  

  return(res);
 }
 
} // Namespace

#endif





