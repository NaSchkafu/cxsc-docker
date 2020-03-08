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

/* CVS $Id: cinterval.hpp,v 1.24 2014/01/30 17:23:44 cxsc Exp $ */

#ifndef _CXSC_CINTERVAL_HPP_INCLUDED
#define _CXSC_CINTERVAL_HPP_INCLUDED

#include <iostream>
#include <string>

// Headerfile for cinterval.

#include "except.hpp"
#include "real.hpp"
#include "complex.hpp"
#include "interval.hpp"

namespace cxsc {

class civector;
class cimatrix;
class civector_slice;
class cimatrix_slice;

//! The Scalar Type cinterval
/*!
The data type cinterval is used to store complex intervals. They are defined as rectangles of the form \f$ z = \left[ x \right] + i \left[ y \right] \in C \f$ (real part
\f$ \left[ x \right] \in R \f$ and imaginary part \f$ \left[ y \right] \in R \f$) with sides parallel to the
axes in the complex plane, as indicated in the figure below.

\image html "cinterval.png" "Complex Interval [3.0, 4.5] + [1.0, 2.0]i"
*/
class cinterval
{
   private:
      // ---- private data ----------------------------------------
      interval  re;
      interval  im;

   public:
      // ---- implicit constructors  ------------------------------
      //! Constructor of class cinterval
      inline cinterval(void)  noexcept           {}
      //! Constructor of class cinterval
      inline cinterval(const interval & a,const interval &b) noexcept; 
      //! Constructor of class cinterval
      inline cinterval(const complex & a,const complex & b)  noexcept(false); 

      // The following are defined in the specific vector, matrix-files
#if(CXSC_INDEX_CHECK) 
      //! Constructor of class cinterval
      INLINE cinterval(const civector &)       throw (ERROR_CIVECTOR_TYPE_CAST_OF_THICK_OBJ,ERROR_CIVECTOR_USE_OF_UNINITIALIZED_OBJ);
      //! Constructor of class cinterval
      INLINE cinterval(const civector_slice &) throw (ERROR_CIVECTOR_TYPE_CAST_OF_THICK_OBJ,ERROR_CIVECTOR_USE_OF_UNINITIALIZED_OBJ);
      //! Constructor of class cinterval
      INLINE cinterval(const cimatrix &)       throw (ERROR_CIMATRIX_TYPE_CAST_OF_THICK_OBJ,ERROR_CIMATRIX_USE_OF_UNINITIALIZED_OBJ);
      //! Constructor of class cinterval
      INLINE cinterval(const cimatrix_slice &) throw (ERROR_CIMATRIX_TYPE_CAST_OF_THICK_OBJ,ERROR_CIMATRIX_USE_OF_UNINITIALIZED_OBJ);
#else
      //! Constructor of class cinterval
      INLINE cinterval(const civector &)       noexcept;
      //! Constructor of class cinterval
      INLINE cinterval(const civector_slice &) noexcept;
      //! Constructor of class cinterval
      INLINE cinterval(const cimatrix &)       noexcept;
      //! Constructor of class cinterval
      INLINE cinterval(const cimatrix_slice &) noexcept;
#endif
      // ---- explicit constructors -------------------------------

      //! Constructor of class cinterval
      explicit inline cinterval(const real     & a)  noexcept;
      //! Constructor of class cinterval
      explicit inline cinterval(const interval & a)  noexcept;
      //! Constructor of class cinterval
      explicit inline cinterval(const complex  & a)  noexcept; 
      //! Constructor of class cinterval
      explicit        cinterval(const dotprecision &)  noexcept;
      //! Constructor of class cinterval
      explicit        cinterval(const cdotprecision &) noexcept;
      //! Constructor of class cinterval
      explicit        cinterval(const idotprecision &) noexcept;
      //! Constructor of class cinterval
      explicit        cinterval(const cidotprecision &) noexcept;
      //! Constructor of class cinterval
      explicit        cinterval(const l_cinterval&) noexcept;

      // ---- assignments -----------------------------------------

      //! Implementation of standard assigning operator
      inline cinterval & operator =(const real &) noexcept;
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const interval &) noexcept;
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const complex &) noexcept;
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const cinterval &) noexcept;
      
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const dotprecision &) noexcept;
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const idotprecision &) noexcept;
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const cdotprecision &) noexcept;
      //! Implementation of standard assigning operator
      inline cinterval & operator =(const cidotprecision &) noexcept;
      //! Implementation of standard assigning operator
             cinterval & operator = (const l_cinterval&) noexcept;      
      //! Implementation of standard assigning operator
             cinterval & operator = (const lx_cinterval&) noexcept;

      // ---- compatiblility typecasts ----------------------------

      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const interval &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const dotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const idotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const cdotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const cidotprecision &) noexcept;
      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const interval &,const interval &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const real &,const interval &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const interval &,const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const complex &,const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const real &,const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _cinterval(const complex &,const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _unchecked_cinterval(const complex &,const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _unchecked_cinterval(const real &,const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cinterval _unchecked_cinterval(const complex &,const real &) noexcept;

      // ---- Input/Output  ---------------------------------------

      //! Implementation of standard output method
      friend std::ostream & operator <<(std::ostream &,const cinterval &) noexcept;
      //! Implementation of standard input method
      friend std::istream & operator >>(std::istream &,cinterval &)       noexcept(false);
      //! Implementation of standard output method
      friend std::string &  operator <<(std::string &,const cinterval &)  noexcept;
      //! Implementation of standard input method
      friend std::string &  operator >>(std::string &,cinterval &)        noexcept(false);
      //! Implementation of standard input method
      friend void           operator >>(const char *,cinterval &)         noexcept(false);
      //! Implementation of standard input method
      friend void           operator >>(const std::string &,cinterval &)  noexcept(false);

      // ---- Std.Operators ---------------------------------------

      //! Implementation of standard algebraic negative sign operation
      friend inline cinterval operator -(const cinterval &) noexcept;
      //! Implementation of standard algebraic positive sign operation
      friend inline cinterval operator +(const cinterval &) noexcept;
      //! Implementation of standard negation operation
      friend inline bool operator!  (const cinterval & a)                    noexcept;

      // CI-CI

      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const cinterval &,const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const cinterval &,const cinterval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend        cinterval operator *(const cinterval &,const cinterval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend        cinterval operator /(const cinterval &,const cinterval &) noexcept(false);
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const cinterval &,const cinterval &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const cinterval &,const cinterval &) noexcept(false);
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cinterval & operator +=(cinterval &, const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cinterval & operator -=(cinterval &, const cinterval &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline cinterval & operator *=(cinterval &, const cinterval &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend inline cinterval & operator /=(cinterval &, const cinterval &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cinterval & operator |=(cinterval &, const cinterval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cinterval & operator &=(cinterval &, const cinterval &) noexcept(false);
      
      // CI-R
      
      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const cinterval &,const real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const real &,const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const cinterval &,const real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const real &,const cinterval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const cinterval &,const real &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const real &,const cinterval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const cinterval &,const real &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const real &,const cinterval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const cinterval &,const real &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const real &,const cinterval &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const cinterval &,const real &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const real &,const cinterval &) noexcept;
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cinterval & operator +=(cinterval &, const real &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cinterval & operator -=(cinterval &, const real &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline cinterval & operator *=(cinterval &, const real &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend inline cinterval & operator /=(cinterval &, const real &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cinterval & operator |=(cinterval &, const real &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cinterval & operator &=(cinterval &, const real &) noexcept;
      
      // CI-I

      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const cinterval &,const interval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const interval &,const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const cinterval &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const interval &,const cinterval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const cinterval &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const interval &,const cinterval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const cinterval &,const interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const interval &,const cinterval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const cinterval &,const interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const interval &,const cinterval &) noexcept;
      //! Returns the intersection cinterval of the arguments
      friend inline cinterval operator &(const cinterval &,const interval &) noexcept;
      //! Returns the intersection cinterval of the arguments
      friend inline cinterval operator &(const interval &,const cinterval &) noexcept;
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cinterval & operator +=(cinterval &, const interval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cinterval & operator -=(cinterval &, const interval &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline cinterval & operator *=(cinterval &, const interval &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend inline cinterval & operator /=(cinterval &, const interval &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cinterval & operator |=(cinterval &, const interval &) noexcept;
      //! Allocates the intersection cinterval of the arguments to the first argument
      friend inline cinterval & operator &=(cinterval &, const interval &) noexcept;

      // CI-C

      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const cinterval &,const complex &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const complex &,const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const cinterval &,const complex &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const complex &,const cinterval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const cinterval &,const complex &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const complex &,const cinterval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const cinterval &,const complex &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const complex &,const cinterval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const cinterval &,const complex &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const complex &,const cinterval &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const cinterval &,const complex &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const complex &,const cinterval &) noexcept;
      

      //! Implementation of standard algebraic addition and allocation operation
      friend inline cinterval & operator +=(cinterval &, const complex &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cinterval & operator -=(cinterval &, const complex &) noexcept;
      //! Implementation of standard algebraic multiplication and allocation operation
      friend inline cinterval & operator *=(cinterval &, const complex &) noexcept;
      //! Implementation of standard algebraic division and allocation operation
      friend inline cinterval & operator /=(cinterval &, const complex &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cinterval & operator |=(cinterval &, const complex &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cinterval & operator &=(cinterval &, const complex &) noexcept;
      
      // C-R

      //! Returns the union cinterval of the arguments
      friend inline cinterval operator |(const complex &,const real &) noexcept;
      //! Returns the union cinterval of the arguments
      friend inline cinterval operator |(const real &,const complex &) noexcept;

      // C-I

      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const complex &,const interval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cinterval operator +(const interval &,const complex &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const complex &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cinterval operator -(const interval &,const complex &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const complex &,const interval &) noexcept;
      //! Implementation of standard algebraic multiplication operation
      friend inline cinterval operator *(const interval &,const complex &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const complex &,const interval &) noexcept;
      //! Implementation of standard algebraic division operation
      friend inline cinterval operator /(const interval &,const complex &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const complex &,const interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cinterval operator |(const interval &,const complex &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const complex &,const interval &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cinterval operator &(const interval &,const complex &) noexcept;
      

      // C-C

      //! Returns the union cinterval of the arguments
      friend inline cinterval operator |(const complex &,const complex &) noexcept;

      // ---- Comp.Operat.  ---------------------------------------
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cinterval & a, const cinterval & b) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cinterval & a, const cinterval & b) noexcept;
      
      // CI-R
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cinterval & a, const real & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const real & a, const cinterval & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cinterval & a, const real & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const real & a, const cinterval & b)    noexcept;

      // CI-I
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cinterval & a, const interval & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const interval & a, const cinterval & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cinterval & a, const interval & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const interval & a, const cinterval & b)    noexcept;

      // CI-C
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cinterval & a, const complex & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const complex & a, const cinterval & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cinterval & a, const complex & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const complex & a, const cinterval & b)    noexcept;

      // ---- Set Operators ----
      
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cinterval &,const cinterval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cinterval &,const cinterval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cinterval &,const cinterval &) noexcept;
      //! Implementation of standard more-or-equal-than operation
      friend inline bool operator >=(const cinterval &,const cinterval &) noexcept;

      // CI-R

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const real &,const cinterval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const real &,const cinterval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const real &,const cinterval &) noexcept;
      //! Implementation of standard more-or-equal-than operation
      friend inline bool operator >=(const real &,const cinterval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cinterval &,const real &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cinterval &,const real &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cinterval &,const real &) noexcept;
      //! Implementation of standard more-or-equal-than operation
      friend inline bool operator >=(const cinterval &,const real &) noexcept;

      // CI-I

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const interval &,const cinterval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const interval &,const cinterval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const interval &,const cinterval &) noexcept;
      //! Implementation of standard more-or-equal-than operation
      friend inline bool operator >=(const interval &,const cinterval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cinterval &,const interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cinterval &,const interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cinterval &,const interval &) noexcept;
      //! Implementation of standard more-or-equal-than operation
      friend inline bool operator >=(const cinterval &,const interval &) noexcept;

      // CI-C

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const complex &,const cinterval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const complex &,const cinterval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const complex &,const cinterval &) noexcept;
      //! Implementation of standard more-or-equal-than operation
      friend inline bool operator >=(const complex &,const cinterval &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cinterval &,const complex &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cinterval &,const complex &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cinterval &,const complex &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cinterval &,const complex &) noexcept;

      // ---- Others   -------------------------------------------
      //! Returns the infimum of a complex interval
      friend inline complex    Inf(const cinterval &) noexcept;
      //! Returns the supremum of a complex interval
      friend inline complex    Sup(const cinterval &) noexcept;
      
      //! Returns the complex interval with the new given infimum value
      friend inline cinterval & SetInf(cinterval &,const complex &) noexcept(false);
      //! Returns the complex interval with the new given infimum value
      friend inline cinterval & SetInf(cinterval &,const real &) noexcept(false);
      //! Returns the complex interval with the new given supremum value
      friend inline cinterval & SetSup(cinterval &,const complex &) noexcept(false);
      //! Returns the complex interval with the new given supremum value
      friend inline cinterval & SetSup(cinterval &,const real &) noexcept(false);
      //! Returns the complex interval with the unchecked new given infimum value
      friend inline cinterval & UncheckedSetInf(cinterval &,const complex &) noexcept;
      //! Returns the complex interval with the unchecked new given infimum value
      friend inline cinterval & UncheckedSetInf(cinterval &,const real &)    noexcept;
      //! Returns the complex interval with the unchecked new given supremum value
      friend inline cinterval & UncheckedSetSup(cinterval &,const complex &) noexcept;
      //! Returns the cinterval with the unchecked new given supremum value
      friend inline cinterval & UncheckedSetSup(cinterval &,const real &)    noexcept;
      
      //! Returns the real interval of the complex interval
      friend inline interval & Re(cinterval & a)       noexcept;
      //! Returns the real interval of the complex interval
      friend inline interval   Re(const cinterval & a) noexcept;
      //! Returns the imaginary interval of the complex interval
      friend inline interval & Im(cinterval & a)       noexcept;
      //! Returns the imaginary interval of the complex interval
      friend inline interval   Im(const cinterval & a) noexcept;
      
      //! Sets the real interval of the complex interval
      friend inline cinterval & SetRe(cinterval & a,const interval & b);
      //! Sets the imaginary interval of the complex interval
      friend inline cinterval & SetIm(cinterval & a,const interval & b); 
      //! Sets the real interval of the complex interval
      friend inline cinterval & SetRe(cinterval & a,const real     & b);
      //! Sets the imaginary interval of the complex interval
      friend inline cinterval & SetIm(cinterval & a,const real     & b);

      //! Returns the infimum of the real interval of the complex interval
      friend inline real InfRe(const cinterval &a) noexcept;
      //! Returns the infimum of the imaginary interval of the complex interval
      friend inline real InfIm(const cinterval &a) noexcept;
      //! Returns the supremum of the real interval of the complex interval
      friend inline real SupRe(const cinterval &a) noexcept;
      //! Returns the supremum of the imaginary interval of the complex interval
      friend inline real SupIm(const cinterval &a) noexcept;
      
      //! Returns the infimum of the real interval of the complex interval
      friend inline real & InfRe(cinterval &a) noexcept;
      //! Returns the infimum of the imaginary interval of the complex interval
      friend inline real & InfIm(cinterval &a) noexcept;
      //! Returns the supremum of the real interval of the complex interval
      friend inline real & SupRe(cinterval &a) noexcept;
      //! Returns the supremum of the imaginary interval of the complex interval
      friend inline real & SupIm(cinterval &a) noexcept;
      
      //! Returns the absolute value of a complex interval
      friend        interval  abs(const cinterval &) noexcept;
      //! Returns the conjugated complex interval
      friend inline cinterval conj(const cinterval &) noexcept;
      //! Returns the rounded middle of the complex interval
      friend inline   complex mid(const cinterval &) noexcept;
      //! Returns the rounded diameter of the complex interval
      friend inline   complex diam(const cinterval &) noexcept;
};

//! Checks if first argument is part of second argument
extern int       in   ( const cinterval&, const cinterval& );
//! Performs an epsilon inflation
extern cinterval Blow ( cinterval, const real& );

// Additional declaration of friend functions outside class cinterval
interval  abs(const cinterval &) noexcept;

} // namespace cxsc 

#include "cinterval.inl"
#include "cimath.hpp"

#endif // _CXSC_CINTERVAL_HPP_INCLUDED
 
