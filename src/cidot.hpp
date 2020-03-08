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

/* CVS $Id: cidot.hpp,v 1.33 2014/01/30 17:23:43 cxsc Exp $ */

#ifndef _CXSC_CIDOT_HPP_INCLUDED
#define _CXSC_CIDOT_HPP_INCLUDED

#include <iostream>
#include <string>
#include "dot.hpp"
#include "idot.hpp"
#include "cdot.hpp"
#include "cinterval.hpp"

namespace cxsc {

// ---------------------------------------------------------------------------
// ----                                                                   ----
// ---- class cidotprecision (declaration)                                ----
// ----                                                                   ----
// ---------------------------------------------------------------------------

//! The Data Type cidotprecision
/*!
The data types dotprecision, idotprecision, cdotprecision and cidotprecision
are based on the scalar data types real, interval, complex, and cinterval, 
respectively. Variables of these data types permit the exact representation 
of products of two arbitrary numbers of the corresponding scalar base type 
and the exact summation of an arbitrary number of such products in a 
dotprecision accumulator, i.e. in a fixed-point format of suitable size.

Since C-XSC Version 2.3.0, the precision for dot products computed with the dotprecision types can be choosen by the user. The default is precision k=0, which means maximum precision (the behaviour of older C-XSC Versions). For k=1, pure floating point operations are used and an error bound is computed using manipulation of the rounding mode of the processor. For k>=2, the so called DotK algorithm is used, simulating higher precision computations and also computing an error bound. When calling the rnd() function, the error bound will be added to the result interval. The resulting intervals will be wider for lower k, but computations will be significantly faster than with maximum precision (k=0).

\sa cxsc::dotprecision
*/
class cidotprecision
{
   private:
      // ---- Datenelemente ---------------------------------------
      dotprecision reinf,resup,iminf,imsup;
      int k;

   public:
      // ---- Constructors  ---------------------------------------
      //! Constructor of class cidotprecision
      cidotprecision() : k(0) {}
      //! Constructor of class cidotprecision
               inline cidotprecision(const cidotprecision &) noexcept;
      
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const real &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const dotprecision &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const interval &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const idotprecision &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const complex &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const cdotprecision &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const cinterval &) noexcept;
      //! Constructor of class cidotprecision
      explicit inline cidotprecision(const idotprecision &, const idotprecision &) noexcept;

      //! Get currently set precision for computation of dot products
      inline int get_k() const { return k; }
      //! Set precision for computation of dot products
      inline void set_k(unsigned int i) { k=i; reinf.set_k(i); resup.set_k(i); iminf.set_k(i); imsup.set_k(i);}
      //! Get currently set precision for computation of dot products
      inline int get_dotprec() const { return k; }
      //! Set precision for computation of dot products
      inline void set_dotprec(unsigned int i) { k=i; reinf.set_k(i); resup.set_k(i); iminf.set_k(i); imsup.set_k(i);}
                  
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const real & a)         noexcept { reinf=resup=a; iminf=imsup=0.0; return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const complex & a)      noexcept { reinf=resup=Re(a); iminf=imsup=Im(a); return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const interval & a)     noexcept { reinf=Inf(a),resup=Sup(a),iminf=imsup=0.0; return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const cinterval & a)    noexcept { reinf=Inf(Re(a)),resup=Sup(Re(a)),iminf=Inf(Im(a)),imsup=Sup(Im(a)); return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const dotprecision & a) noexcept { reinf=resup=a; iminf=imsup=0.0; return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const cdotprecision & a)noexcept { reinf=resup=Re(a),iminf=imsup=Im(a); return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const idotprecision & a)noexcept { reinf=Inf(a),resup=Sup(a),iminf=imsup=0.0; return *this; }
      //! Implementation of standard assigning operator
      inline cidotprecision & operator= (const cidotprecision& a)noexcept { reinf=a.reinf,resup=a.resup,iminf=a.iminf,imsup=a.imsup; return *this; }

      // ---- Destruktor    ----
      // ~cidotprecision() {} unnoetig

      // ---- Typwandlungen ----
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const complex &,const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const complex &,const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const real &,const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const interval &,const interval &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const interval &,const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const real &,const interval &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const interval &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const cinterval &) noexcept;
      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const idotprecision &,const idotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const cdotprecision &,const cdotprecision &) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const idotprecision &,const dotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const cdotprecision &,const dotprecision &) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const dotprecision &,const idotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const dotprecision &,const cdotprecision&) noexcept(false);
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const cdotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const idotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _cidotprecision(const dotprecision &) noexcept;
      
      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _unchecked_cidotprecision(const complex &, const complex &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _unchecked_cidotprecision(const complex &, const real &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _unchecked_cidotprecision(const real &, const complex &) noexcept;
      
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _unchecked_cidotprecision(const cdotprecision &, const cdotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _unchecked_cidotprecision(const cdotprecision &, const dotprecision &) noexcept;
      //! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
      friend inline cidotprecision _unchecked_cidotprecision(const dotprecision &, const cdotprecision &) noexcept;

      // ---- Ausgabefunkt. ---------------------------------------
      //! Implementation of standard input method
      friend std::istream& operator >> (std::istream& s, cidotprecision& a)       noexcept(false);
      //! Implementation of standard output method
      friend std::ostream& operator << (std::ostream& s, const cidotprecision& a) noexcept;
      //! Implementation of standard input method
      friend std::string&  operator >> (std::string&  s, cidotprecision& a)       noexcept(false);
      //! Implementation of standard output method
      friend std::string&  operator << (std::string&  s, const cidotprecision& a) noexcept;
      //! Implementation of standard input method
      friend void          operator >> (const std::string &s,cidotprecision& a)   noexcept(false);
      //! Implementation of standard input method
      friend void          operator >> (const char *s       ,cidotprecision& a)   noexcept(false);

      // ---- Standardfunkt ---- (arithmetische Operatoren)
      //! Implementation of standard algebraic negative sign operation
      friend inline cidotprecision operator -(cidotprecision) noexcept;
      //! Implementation of standard algebraic positive sign operation
      friend inline cidotprecision operator +(const cidotprecision &) noexcept;

      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const cidotprecision &) noexcept(false);

      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cdotprecision &,const cdotprecision &)  noexcept;

      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const cidotprecision &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const cidotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const cidotprecision &) noexcept(false);

      // CID-R
      
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const real &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const real &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const real &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const real &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const real &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const real &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const real &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const real &,const cidotprecision &) noexcept(false);
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const real &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const real &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const real &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const real &) noexcept(false);
      
      // CID-C

      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const complex &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const complex &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const complex &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const complex &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const complex &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const complex &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const complex &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const complex &,const cidotprecision &) noexcept(false);
      

      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const complex &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const complex &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const complex &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const complex &) noexcept(false);
      
      // CID-I

      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const interval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const interval &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const interval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const interval &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const interval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const interval &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const interval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const interval &,const cidotprecision &) noexcept(false);
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const interval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const interval &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const interval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const interval &) noexcept(false);

      // CID-CI

      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const cinterval &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cinterval &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cinterval &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const cinterval &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cinterval &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const cinterval &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cinterval &,const cidotprecision &) noexcept(false);
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const cinterval &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const cinterval &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const cinterval &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const cinterval &) noexcept(false);
      
      // CID-D
      
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const dotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const dotprecision &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const dotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const dotprecision &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const dotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const dotprecision &,const cidotprecision &) noexcept(false);
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const dotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const dotprecision &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const dotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const dotprecision &) noexcept(false);
      
      // CID-CD

      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const cdotprecision &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cdotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const cdotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cdotprecision &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const cdotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cdotprecision &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const cdotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cdotprecision &,const cidotprecision &) noexcept(false);
      

      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const cdotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const cdotprecision &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const cdotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const cdotprecision &) noexcept(false);
      
      // CID-ID

      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const cidotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic addition operation
      friend inline cidotprecision operator +(const idotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const cidotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction operation
      friend inline cidotprecision operator -(const idotprecision &,const cidotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const cidotprecision &,const idotprecision &) noexcept;
      //! Returns the convex hull of the arguments
      friend inline cidotprecision operator |(const idotprecision &,const cidotprecision &) noexcept;
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const cidotprecision &,const idotprecision &) noexcept(false);
      //! Returns the intersection of the arguments
      friend inline cidotprecision operator &(const idotprecision &,const cidotprecision &) noexcept(false);
      
      //! Implementation of standard algebraic addition and allocation operation
      friend inline cidotprecision & operator +=(cidotprecision &, const idotprecision &) noexcept;
      //! Implementation of standard algebraic subtraction and allocation operation
      friend inline cidotprecision & operator -=(cidotprecision &, const idotprecision &) noexcept;
      //! Allocates the convex hull of the arguments to the first argument
      friend inline cidotprecision & operator |=(cidotprecision &, const idotprecision &) noexcept;
      //! Allocates the intersection of the arguments to the first argument
      friend inline cidotprecision & operator &=(cidotprecision &, const idotprecision &) noexcept(false);

      // ---- Vergleichsop. ----
      //! Implementation of standard negation operation
      friend inline bool operator !(const cidotprecision &) noexcept;
//             inline      operator void *() const throw();

      //! Implementation of standard equality operation
      friend inline bool operator ==(const cidotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator !=(const cidotprecision &,const cidotprecision &) noexcept;

      // CID-R
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const real & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const real & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const real & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const real & a, const cidotprecision & b)    noexcept;

      // CID-C
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const complex & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const complex & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const complex & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const complex & a, const cidotprecision & b)    noexcept;

      // CID-I
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const interval & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const interval & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const interval & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const interval & a, const cidotprecision & b)    noexcept;

      // CID-CI
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const cinterval & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const cinterval & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const cinterval & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cinterval & a, const cidotprecision & b)    noexcept;
      
      // CID-D
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const dotprecision & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const dotprecision & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const dotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const dotprecision & a, const cidotprecision & b)    noexcept;

      // CID-CD
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const cdotprecision & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const cdotprecision & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const cdotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cdotprecision & a, const cidotprecision & b)    noexcept;

      // CID-ID
      
      //! Implementation of standard equality operation
      friend inline bool operator== (const cidotprecision & a, const idotprecision & b)    noexcept;
      //! Implementation of standard equality operation
      friend inline bool operator== (const idotprecision & a, const cidotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const cidotprecision & a, const idotprecision & b)    noexcept;
      //! Implementation of standard negated equality operation
      friend inline bool operator!= (const idotprecision & a, const cidotprecision & b)    noexcept;

      // ---- Set Operators ----
      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const cidotprecision &) noexcept;

      // CID-R

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const real &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const real &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const real &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const real &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const real &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const real &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const real &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const real &) noexcept;

      // CID-C

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const complex &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const complex &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const complex &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const complex &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const complex &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const complex &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const complex &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const complex &) noexcept;

      // CID-I

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const interval &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const interval &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const interval &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const interval &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const interval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const interval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const interval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const interval &) noexcept;

      // CID-CI

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cinterval &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cinterval &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cinterval &,const cidotprecision &) noexcept;
      friend inline bool operator >=(const cinterval &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const cinterval &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const cinterval &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const cinterval &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const cinterval &) noexcept;

      // CID-D

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const dotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const dotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const dotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const dotprecision &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const dotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const dotprecision &) noexcept;

      // CID-CD

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cdotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cdotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cdotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cdotprecision &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const cdotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const cdotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const cdotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const cdotprecision &) noexcept;

      // CID-ID

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const idotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const idotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const idotprecision &,const cidotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const idotprecision &,const cidotprecision &) noexcept;

      //! Implementation of standard less-than operation
      friend inline bool operator  <(const cidotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard greater-than operation
      friend inline bool operator  >(const cidotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard less-or-equal-than operation
      friend inline bool operator <=(const cidotprecision &,const idotprecision &) noexcept;
      //! Implementation of standard greater-or-equal-than operation
      friend inline bool operator >=(const cidotprecision &,const idotprecision &) noexcept;


      // ---- Funktionen    ----
      
      //! Returns the infimum of a complex dotprecison interval
      friend inline cdotprecision   Inf(const cidotprecision&) noexcept;
      //! Returns the supremum of a complex dotprecison interval
      friend inline cdotprecision   Sup(const cidotprecision&) noexcept;
      //! Returns the complex dotprecison interval with the new given infimum value
      friend inline cidotprecision& SetInf(cidotprecision&, const cdotprecision&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given supremum value
      friend inline cidotprecision& SetSup(cidotprecision&, const cdotprecision&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given infimum value
      friend inline cidotprecision& SetInf(cidotprecision&, const dotprecision&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given supremum value
      friend inline cidotprecision& SetSup(cidotprecision&, const dotprecision&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given infimum value
      friend inline cidotprecision& SetInf(cidotprecision&, const complex&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given supremum value
      friend inline cidotprecision& SetSup(cidotprecision&, const complex&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given infimum value
      friend inline cidotprecision& SetInf(cidotprecision&, const real&) noexcept(false);
      //! Returns the complex dotprecison interval with the new given supremum value
      friend inline cidotprecision& SetSup(cidotprecision&, const real&) noexcept(false);
      //! Returns the complex dotprecison interval with the unchecked new given infimum value
      friend inline cidotprecision& UncheckedSetInf(cidotprecision&, const cdotprecision&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given supremum value
      friend inline cidotprecision& UncheckedSetSup(cidotprecision&, const cdotprecision&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given infimum value
      friend inline cidotprecision& UncheckedSetInf(cidotprecision&, const dotprecision&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given supremum value
      friend inline cidotprecision& UncheckedSetSup(cidotprecision&, const dotprecision&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given infimum value
      friend inline cidotprecision& UncheckedSetInf(cidotprecision&, const complex&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given supremum value
      friend inline cidotprecision& UncheckedSetSup(cidotprecision&, const complex&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given infimum value
      friend inline cidotprecision& UncheckedSetInf(cidotprecision&, const real&) noexcept;
      //! Returns the complex dotprecison interval with the unchecked new given supremum value
      friend inline cidotprecision& UncheckedSetSup(cidotprecision&, const real&) noexcept;
   
      //! Returns the real part of the complex dotprecision interval
      friend inline idotprecision   Re(const cidotprecision &) noexcept;
      //! Returns the imaginary part of the complex dotprecision interval
      friend inline idotprecision   Im(const cidotprecision &) noexcept;
      
      //! Returns the infimum of the real part of the complex dotprecision interval
      friend inline const dotprecision & InfRe(const cidotprecision &) noexcept;
      //! Returns the infimum of the imaginary part of the complex dotprecision interval
      friend inline const dotprecision & InfIm(const cidotprecision &) noexcept;
      //! Returns the supremum of the real part of the complex dotprecision interval
      friend inline const dotprecision & SupRe(const cidotprecision &) noexcept;
      //! Returns the supremum of the imaginary part of the complex dotprecision interval
      friend inline const dotprecision & SupIm(const cidotprecision &) noexcept; 
      
      //! Returns the infimum of the real part of the complex dotprecision interval
      friend inline       dotprecision & InfRe(cidotprecision &) noexcept;
      //! Returns the infimum of the imaginary part of the complex dotprecision interval
      friend inline       dotprecision & InfIm(cidotprecision &) noexcept;
      //! Returns the supremum of the real part of the complex dotprecision interval
      friend inline       dotprecision & SupRe(cidotprecision &) noexcept;
      //! Returns the supremum of the imaginary part of the complex dotprecision interval
      friend inline       dotprecision & SupIm(cidotprecision &) noexcept;
      
      //! Sets the real part of the complex dotprecision interval
      friend inline cidotprecision& SetRe(cidotprecision&, const idotprecision&) noexcept;
      //! Sets the imaginary part of the complex dotprecision interval
      friend inline cidotprecision& SetIm(cidotprecision&, const idotprecision&) noexcept;
      //! Sets the real part of the complex dotprecision interval
      friend inline cidotprecision& SetRe(cidotprecision&, const dotprecision&) noexcept;
      //! Sets the imaginary part of the complex dotprecision interval
      friend inline cidotprecision& SetIm(cidotprecision&, const dotprecision&) noexcept;
      //! Sets the real part of the complex dotprecision interval
      friend inline cidotprecision& SetRe(cidotprecision&, const interval&) noexcept;
      //! Sets the imaginary part of the complex dotprecision interval
      friend inline cidotprecision& SetIm(cidotprecision&, const interval&) noexcept;
      //! Sets the real part of the complex dotprecision interval
      friend inline cidotprecision& SetRe(cidotprecision&, const real&) noexcept;
      //! Sets the imaginary part of the complex dotprecision interval
      friend inline cidotprecision& SetIm(cidotprecision&, const real&) noexcept;

      
      friend inline void rnd(const cidotprecision &,cinterval &) noexcept;
      friend inline cinterval rnd(const cidotprecision &) noexcept;
      
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend        void accumulate  (cidotprecision&, const cinterval&, const cinterval&) noexcept;

      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const cinterval&, const interval&) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const cinterval&, const complex&) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const cinterval&, const real&) noexcept;
      
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const interval &,const cinterval &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const complex &,const cinterval &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const real &,const cinterval&) noexcept;
      
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const complex &,const interval &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const interval &,const complex &) noexcept;

      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const interval &,const interval &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const interval &,const real &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const real &,const interval &) noexcept;

      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const complex &,const complex &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const real &,const complex &) noexcept;
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const complex &,const real &) noexcept;
      
      //! The accurate scalar product of the last two arguments added to the value of the first argument
      friend inline void accumulate  (cidotprecision&, const real &,const real &) noexcept;
};

// ---------------------------------------------------------------------------
// ----                                                                   ----
// ---- friend functions of class cdotprecision (not inline)              ----
// ----                                                                   ----
// ---------------------------------------------------------------------------

std::istream& operator >> (std::istream& s, cidotprecision& a)       noexcept(false);
std::ostream& operator << (std::ostream& s, const cidotprecision& a) noexcept;
std::string&  operator >> (std::string&  s, cidotprecision& a)       noexcept(false);
std::string&  operator << (std::string&  s, const cidotprecision& a) noexcept;
void          operator >> (const std::string &s,cidotprecision& a)   noexcept(false);
void          operator >> (const char *s       ,cidotprecision& a)   noexcept(false);

void accumulate  (cidotprecision&, const cinterval&, const cinterval&) noexcept;

// ---------------------------------------------------------------------------
// ----                                                                   ----
// ----  global CIDotprecision Akku's                                     ----
// ----                                                                   ----
// ---------------------------------------------------------------------------

//#define MAXCIDOTAKKU     (MAXDOTAKKU / 2)
//extern cidotprecision cidotakku[MAXCIDOTAKKU];
  
//----------------------------------------------------------------------
} // namespace cxsc 

#include "cidot.inl"

#endif // _CXSC_CIDOT_HPP_INCLUDED

