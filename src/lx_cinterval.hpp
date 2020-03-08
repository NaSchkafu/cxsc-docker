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

/* CVS $Id: lx_cinterval.hpp,v 1.9 2014/01/30 17:23:47 cxsc Exp $ */


/*
**  F. Blomquist, University of Wuppertal, 19.09.2007;
*/

/*
**  Implementation of the classes
**
**  lx_cinterval  with all tools and elementary functions for complex
**                point and interval aruments
**
*/

#ifndef _CXSC_LX_CINTERVAL_HPP_INCLUDED
#define _CXSC_LX_CINTERVAL_HPP_INCLUDED

#include <iostream>
#include <except.hpp>
#include <l_cinterval.hpp>
#include <l_complex.hpp>
#include "lx_interval.hpp"
#include "lx_complex.hpp"

namespace cxsc {
	
// --------------------------------------------------------------------------
//      Class lx_cinterval
// --------------------------------------------------------------------------

class lx_cinterval
{
private:
    // ----------------- private data elements -------------------------------
    lx_interval re, im;
    // (re,im) is a complex number:  re + i*im, i = sqrt(-1).
public:
    // ------------- Constructors --------------------------------------------

    //! Constructor of class lx_cinterval
    inline lx_cinterval(void)  noexcept { }
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const lx_interval &, const lx_interval &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const l_interval &, const l_interval &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const interval &,   const interval &)   noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const l_real &,     const l_real &)     noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const lx_real &,     const lx_real &)     noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const real &,       const real &)       noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const l_cinterval &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const cinterval &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const complex &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const l_complex &) noexcept;
    //! Constructor of class lx_cinterval 
    inline lx_cinterval(const lx_complex &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const lx_complex&, const lx_complex&)
	noexcept(false);
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const l_complex&, const l_complex&)
	noexcept(false);
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const complex&, const complex&)
	noexcept(false);
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const real&, const l_interval&, const real&, const l_interval&) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const real&, const l_interval&) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const real&, const l_interval&, const lx_interval&) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const lx_interval&, const real&, const l_interval&) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const real&, const string&, const real&, const string&) noexcept;
    //! Constructor of class lx_cinterval
    explicit inline lx_cinterval(const lx_interval &) noexcept;
    //! Constructor of class lx_cinterval
    explicit inline lx_cinterval(const l_interval &) noexcept;
    //! Constructor of class lx_cinterval
    inline lx_cinterval(const interval &) noexcept;
    //! Constructor of class lx_cinterval
    explicit inline lx_cinterval(const lx_real &) noexcept;
    //! Constructor of class lx_cinterval
    explicit inline lx_cinterval(const l_real &) noexcept;
    //! Constructor of class lx_cinterval
    explicit inline lx_cinterval(const real &) noexcept;
    //! Constructor of class lx_cinterval

    // ------------- Assignments ---------------------------------------------

    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const lx_cinterval & ) noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const l_cinterval & ) noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const cinterval & )   noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const lx_interval & )  noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const l_interval & )  noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const interval & )    noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const lx_real & )      noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const l_real & )      noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const real & )        noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const lx_complex & )   noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const l_complex & )   noexcept;
    //! Implementation of standard assigning operator
    inline lx_cinterval & operator = (const complex & )     noexcept;

// ----------------------- Output --------------------------------------------

//! Implementation of standard output method
friend inline std::ostream& operator << (std::ostream& s,const lx_cinterval& a) 
    noexcept;
// A value a of type lx_cinterval is written to the output channel.

//! Implementation of standard output method
friend inline std::string & operator << (std::string &s,const lx_cinterval& a) 
    noexcept;
// The value of a variable a of type lx_cinterval is copied to a string s.
// s has the form:  {ex,li}


// ---------------------- Arithmetic operators ------------------------------

//! Implementation of standard algebraic negative sign operation
friend inline lx_cinterval operator -(const lx_cinterval &) noexcept;

//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &,const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &,const l_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const l_cinterval &,const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const cinterval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const lx_interval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_interval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const l_interval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const l_interval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const lx_real &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const l_real &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const l_real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const real &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const complex &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const complex &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const l_complex &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const l_complex &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_cinterval &, const lx_complex &) 
    noexcept;
//! Implementation of standard algebraic addition operation
friend inline lx_cinterval operator + (const lx_complex &, const lx_cinterval &) 
    noexcept;


//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &,const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &,const l_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const l_cinterval &,const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const cinterval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const lx_interval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_interval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const l_interval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const l_interval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const lx_real &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const l_real &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const l_real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const real &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const complex &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const complex &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const l_complex &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const l_complex &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_cinterval &, const lx_complex &) 
    noexcept;
//! Implementation of standard algebraic subtraction operation
friend inline lx_cinterval operator - (const lx_complex &, const lx_cinterval &) 
    noexcept;


//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_cinterval &,const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_cinterval &, const lx_interval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_interval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_cinterval &, const l_interval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const l_interval &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_cinterval &, const lx_real &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_cinterval &, const l_real &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const l_real &, const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const lx_cinterval &, const real &) 
    noexcept;
//! Implementation of standard algebraic multiplication operation
friend inline lx_cinterval operator * (const real &, const lx_cinterval &) 
    noexcept;

//! Implementation of standard algebraic division operation
friend inline lx_cinterval operator / (const lx_cinterval &,const lx_cinterval &) 
    noexcept;
//! Implementation of standard algebraic division operation
friend inline lx_cinterval operator / (const lx_cinterval &, const lx_interval &) 
    noexcept;
//! Implementation of standard algebraic division operation
friend inline lx_cinterval operator / (const lx_cinterval &, const l_interval &) 
    noexcept;
//! Implementation of standard algebraic division operation
friend inline lx_cinterval operator / (const lx_cinterval &, const l_real &) 
    noexcept;
//! Implementation of standard algebraic division operation
friend inline lx_cinterval operator / (const lx_cinterval &, const lx_real &) 
    noexcept;
//! Implementation of standard algebraic division operation
friend inline lx_cinterval operator / (const lx_cinterval &, const real &) 
    noexcept;

//! Implementation of standard negation operation
friend inline bool operator ! (const lx_cinterval&) noexcept;

//! Implementation of standard equality operation
friend inline bool operator == (const lx_cinterval &, const lx_cinterval &) 
    noexcept;

//! Implementation of negated standard equality operation
friend inline bool operator != (const lx_cinterval &, const lx_cinterval &) 
    noexcept;


    // --------------------- Functions ---------------------------------------

    //! Returns the real interval of the complex interval
    friend inline lx_interval Re(const lx_cinterval &) noexcept;
    //! Returns the imaginary interval of the complex interval
    friend inline lx_interval Im(const lx_cinterval &) noexcept;

    //! Returns the infinum of a complex interval
    friend inline lx_complex Inf(const lx_cinterval &) noexcept;
    //! Returns the supremum of a complex interval
    friend inline lx_complex Sup(const lx_cinterval &) noexcept;

    //! Sets the real interval of the complex interval
    friend inline lx_cinterval & SetRe(lx_cinterval&, const lx_interval&);
    //! Sets the real interval of the complex interval
    friend inline lx_cinterval & SetRe(lx_cinterval&, const l_interval&);
    //! Sets the real interval of the complex interval
    friend inline lx_cinterval & SetRe(lx_cinterval&, const interval&);
    //! Sets the real interval of the complex interval
    friend inline lx_cinterval & SetRe(lx_cinterval&, const lx_real&);
    //! Sets the real interval of the complex interval
    friend inline lx_cinterval & SetRe(lx_cinterval&, const l_real&);
    //! Sets the real interval of the complex interval
    friend inline lx_cinterval & SetRe(lx_cinterval&, const real&); 

    //! Sets the imaginary interval of the complex interval
    friend inline lx_cinterval & SetIm(lx_cinterval&, const lx_interval&);
    //! Sets the imaginary interval of the complex interval
    friend inline lx_cinterval & SetIm(lx_cinterval&, const l_interval&);
    //! Sets the imaginary interval of the complex interval
    friend inline lx_cinterval & SetIm(lx_cinterval&, const interval&);
    //! Sets the imaginary interval of the complex interval
    friend inline lx_cinterval & SetIm(lx_cinterval&, const lx_real&);
    //! Sets the imaginary interval of the complex interval
    friend inline lx_cinterval & SetIm(lx_cinterval&, const l_real&);
    //! Sets the imaginary interval of the complex interval
    friend inline lx_cinterval & SetIm(lx_cinterval&, const real&);

    //! Returns the infimum of the real interval of the complex interval
    friend inline lx_real InfRe(const lx_cinterval&) noexcept; 
    //! Returns the infimum of the imaginary interval of the complex interval
    friend inline lx_real InfIm(const lx_cinterval&) noexcept;
    //! Returns the supremum of the real interval of the complex interval
    friend inline lx_real SupRe(const lx_cinterval&) noexcept;
    //! Returns the supremum of the imaginary interval of the complex interval
    friend inline lx_real SupIm(const lx_cinterval&) noexcept;

    //! Returns the rounded middle of the complex interval
    friend inline lx_complex mid(const lx_cinterval &) noexcept;
    //! Returns the rounded diameter of the complex interval
    friend inline lx_complex diam(const lx_cinterval &) noexcept;
    //! Returns the exponent of the real part of the complex interval
    friend inline real expo_Re(const lx_cinterval &) noexcept;
    //! Returns the exponent of the imaginary part of the complex interval
    friend inline real expo_Im(const lx_cinterval &) noexcept;
    //! Returns the li_part of the real part of the complex interval
    friend inline l_interval li_part_Re(const lx_cinterval &) noexcept;
    //! Returns the li_part of the imaginary part of the complex interval
    friend inline l_interval li_part_Im(const lx_cinterval &) noexcept;
    //! Returns the absolute value of a complex interval
    friend inline lx_interval abs(const lx_cinterval &) noexcept;
    //! matches the precision of a complex interval to the actual stagprec value
    friend inline lx_cinterval adjust(const lx_cinterval &) noexcept;
    //! Returns the conjugated complex interval 
    friend inline lx_cinterval conj(const lx_cinterval &) noexcept;
    //! Multiplication of an interval with \f$ 2^n \f$
    friend inline void times2pown(lx_cinterval& , const real&) noexcept;
    //! Returns 1 if the argument is an empty interval
    friend inline bool IsEmpty(const lx_cinterval&) noexcept;

// ------------------------- Set Operators -----------------------------------

friend inline bool operator < (const lx_cinterval &, const lx_cinterval &) 
    noexcept;
friend inline bool operator <= (const lx_cinterval &, const lx_cinterval &) 
    noexcept;

// ------------------------- Intersection ------------------------------------

friend inline lx_cinterval operator & (const lx_cinterval& a, 
				      const lx_cinterval& b) noexcept;

// -------------------------- Convex Hull ------------------------------------

friend inline lx_cinterval operator | (const lx_cinterval& a,
			       const lx_cinterval& b) noexcept;

// ---------------------------- Others --------------------------------------

friend inline lx_cinterval & SetInf(lx_cinterval& a, const lx_complex& b) 
    noexcept(false);
friend inline lx_cinterval & SetInf(lx_cinterval& a, const l_complex& b) 
    noexcept(false);
friend inline lx_cinterval & SetInf(lx_cinterval& a, const complex& b) 
    noexcept(false);
friend inline lx_cinterval & SetInf(lx_cinterval& a, const lx_real & b) 
    noexcept(false);
friend inline lx_cinterval & SetInf(lx_cinterval& a, const l_real & b) 
	noexcept(false);
friend inline lx_cinterval & SetInf(lx_cinterval& a, const real & b) 
	noexcept(false);

friend inline lx_cinterval & SetSup(lx_cinterval& a, const lx_complex& b) 
    noexcept(false);
friend inline lx_cinterval & SetSup(lx_cinterval& a, const l_complex& b) 
    noexcept(false);
friend inline lx_cinterval & SetSup(lx_cinterval& a, const complex& b) 
    noexcept(false);
friend inline lx_cinterval & SetSup(lx_cinterval& a, const lx_real & b) 
    noexcept(false);
friend inline lx_cinterval & SetSup(lx_cinterval& a, const l_real & b) 
	noexcept(false);
friend inline lx_cinterval & SetSup(lx_cinterval& a, const real & b) 
	noexcept(false);

}; // end of class lx_cinterval

// ***************************************************************************
// ***************************************************************************

// ---------------------------------------------------------------------------
// ------- friend functions declared inside the class lx_cinterval ------------
// ---------------------------------------------------------------------------

    //! Implementation of standard algebraic negative sign operation
    inline lx_cinterval operator-(const lx_cinterval &) noexcept;

    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &,const l_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const l_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const l_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const lx_real &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const l_real &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const l_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const real &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const l_complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_cinterval &, const lx_complex &) 
	noexcept;
    //! Implementation of standard algebraic addition operation
    inline lx_cinterval operator + (const lx_complex &, const lx_cinterval &) 
	noexcept;

    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &,const l_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const l_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const l_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const lx_real &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const l_real &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const l_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const real &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const l_complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_cinterval &, const lx_complex &) 
	noexcept;
    //! Implementation of standard algebraic subtraction operation
    inline lx_cinterval operator - (const lx_complex &, const lx_cinterval &) 
	noexcept;

    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const l_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const l_real &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const l_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const lx_real &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const real &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const real &, const lx_cinterval &) 
	noexcept;

    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const l_real &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const lx_real &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const real &)
	noexcept;

    //! Implementation of standard negation operation
    inline bool operator ! (const lx_cinterval&) noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const lx_cinterval &) 
	noexcept;
//! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const lx_cinterval &) 
	noexcept;

    // ---------------------- Set Operators ---------------------------------

    //! Implementation of standard less-than operation
    inline bool operator < (const lx_cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <= (const lx_cinterval &, const lx_cinterval &) 
    noexcept;

// -------------- friend Functions declared in lx_cinterval ------------------

    //! Returns the infimum of the real and imaginary part
    inline lx_complex Inf(const lx_cinterval &) noexcept;
    //! Returns the supremum of the real and imaginary part
    inline lx_complex Sup(const lx_cinterval &) noexcept;
    //! Returns the real part of the complex interval

    inline lx_interval Re(const lx_cinterval &) noexcept;
    //! Returns the imaginary part of the complex interval
    inline lx_interval Im(const lx_cinterval &) noexcept;
    //! Returns the complex valued centre of the complex interval

    //! Sets the real interval of the complex interval
    inline lx_cinterval & SetRe(lx_cinterval&, const lx_interval&);
    //! Sets the real interval of the complex interval
    inline lx_cinterval & SetRe(lx_cinterval&, const l_interval&);
    //! Sets the real interval of the complex interval
    inline lx_cinterval & SetRe(lx_cinterval&, const interval&);
    //! Sets the real interval of the complex interval
    inline lx_cinterval & SetRe(lx_cinterval&, const lx_real&);
    //! Sets the real interval of the complex interval
    inline lx_cinterval & SetRe(lx_cinterval&, const l_real&);
    //! Sets the real interval of the complex interval
    inline lx_cinterval & SetRe(lx_cinterval&, const real&);

    //! Sets the imaginary interval of the complex interval
    inline lx_cinterval & SetIm(lx_cinterval&, const lx_interval&);
    //! Sets the imaginary interval of the complex interval
    inline lx_cinterval & SetIm(lx_cinterval&, const l_interval&);
    //! Sets the imaginary interval of the complex interval
    inline lx_cinterval & SetIm(lx_cinterval&, const interval&);
    //! Sets the imaginary interval of the complex interval
    inline lx_cinterval & SetIm(lx_cinterval&, const lx_real&);
    //! Sets the imaginary interval of the complex interval
    inline lx_cinterval & SetIm(lx_cinterval&, const l_real&);
    //! Sets the imaginary interval of the complex interval
    inline lx_cinterval & SetIm(lx_cinterval&, const real&);

    //! Returns the infimum of the real interval of the complex interval
    inline lx_real InfRe(const lx_cinterval&) noexcept; 
    //! Returns the infimum of the imaginary interval of the complex interval
    inline lx_real InfIm(const lx_cinterval&) noexcept;
    //! Returns the supremum of the real interval of the complex interval
    inline lx_real SupRe(const lx_cinterval&) noexcept;
    //! Returns the supremum of the imaginary interval of the complex interval
    inline lx_real SupIm(const lx_cinterval&) noexcept;

    //! Returns the complex middle of the complex interval
    inline lx_complex mid(const lx_cinterval &) noexcept;
    //! Returns the complex valued diameter of the complex interval
    inline lx_complex diam(const lx_cinterval &) noexcept;
    //! Returns the exponent n of the real part of the complex interval
    inline real expo_Re(const lx_cinterval &a) noexcept;
    //! Returns the exponent n of the imaginary part of the complex interval
    inline real expo_Im(const lx_cinterval &a) noexcept;
    //! Returns the l_interval of the real part of the complex interval
    inline l_interval li_part_Re(const lx_cinterval &) noexcept;
    //! Returns the l_interval of the imaginary part of the complex interval
    inline l_interval li_part_Im(const lx_cinterval &) noexcept;
    //! Sets the precision of a specific long datatype value
    inline lx_cinterval adjust(const lx_cinterval &) noexcept;
    //! Returns the conjugated complex interval
    inline lx_cinterval conj(const lx_cinterval &) noexcept;
    //! Multiplication of interval with \f$ 2^n \f$
    inline void times2pown(lx_cinterval& , const real&) noexcept;
    //! Returns the absolute value of the complex interval
    inline lx_interval abs(const lx_cinterval &) noexcept; 
    //! Returns the intersection of the two complex interval operands
    inline lx_cinterval operator & (const lx_cinterval& a, 
				    const lx_cinterval& b) noexcept;
    //! Returns the convex hull of the two complex interval operands
    inline lx_cinterval operator | (const lx_cinterval& a,
				    const lx_cinterval& b) noexcept;

    //! Returns the complex interval with the new given infimum value
    inline lx_cinterval & SetInf(lx_cinterval& a, const lx_complex& b) 
	noexcept(false);
    //! Returns the complex interval with the new given infimum value
    inline lx_cinterval & SetInf(lx_cinterval& a, const l_complex& b) 
	noexcept(false);
    //! Returns the complex interval with the new given infimum value
    inline lx_cinterval & SetInf(lx_cinterval& a, const complex& b) 
	noexcept(false);
    //! Returns the complex interval with the new given infimum value
    inline lx_cinterval & SetInf(lx_cinterval& a, const lx_real & b) 
	noexcept(false);
    //! Returns the complex interval with the new given infimum value
    inline lx_cinterval & SetInf(lx_cinterval& a, const l_real & b) 
	noexcept(false);
    //! Returns the complex interval with the new given infimum value
    inline lx_cinterval & SetInf(lx_cinterval& a, const real & b) 
	noexcept(false);

    //! Returns the complex interval with the new given supremum value
    inline lx_cinterval & SetSup(lx_cinterval& a, const lx_complex& b) 
	noexcept(false);
    //! Returns the complex interval with the new given supremum value
    inline lx_cinterval & SetSup(lx_cinterval& a, const l_complex& b) 
	noexcept(false);
    //! Returns the complex interval with the new given supremum value
    inline lx_cinterval & SetSup(lx_cinterval& a, const complex& b) 
	noexcept(false);
    //! Returns the complex interval with the new given supremum value
    inline lx_cinterval & SetSup(lx_cinterval& a, const lx_real & b) 
	noexcept(false);
    //! Returns the complex interval with the new given supremum value
    inline lx_cinterval & SetSup(lx_cinterval& a, const l_real & b) 
	noexcept(false);
    //! Returns the complex interval with the new given supremum value
    inline lx_cinterval & SetSup(lx_cinterval& a, const real & b) 
	noexcept(false);

    //! Returns 1 if the argument is an empty interval
    inline bool IsEmpty(const lx_cinterval&) noexcept;

// ***************************************************************************
// ---------------------------------------------------------------------------
// -------- Functions declared only outside the class lx_cinterval ------------
// ---------------------------------------------------------------------------
// ***************************************************************************

    //! Implementation of standard algebraic positive sign operation 
    inline lx_cinterval operator+(const lx_cinterval &) noexcept;

    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const lx_cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const lx_interval &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const l_interval &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const l_cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const l_real &b) noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const lx_real &b) noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const real &b) noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const interval &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const complex &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const l_complex &b) 
	noexcept;
    //! Implementation of standard algebraic addition and allocation operation
    inline lx_cinterval & operator +=(lx_cinterval &a, const lx_complex &b) 
	noexcept;

    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const lx_cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const lx_interval &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const l_interval &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const l_cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const l_real &b) noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const lx_real &b) noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const real &b) noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const interval &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const complex &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const l_complex &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation
    inline lx_cinterval & operator -=(lx_cinterval &a, const lx_complex &b) 
	noexcept;
    //! Implementation of standard algebraic subtraction and allocation operation

    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &,const l_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const l_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const l_complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_cinterval &, const lx_complex &) 
	noexcept;
    //! Implementation of standard algebraic multiplication operation
    inline lx_cinterval operator * (const lx_complex &, const lx_cinterval &) 
	noexcept;

    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const lx_cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const lx_interval &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const l_interval &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const l_cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const l_real &b) noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const lx_real &b) noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const real &b) noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const interval &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const cinterval &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const complex &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const l_complex &b) 
	noexcept;
    //! Implementation of standard algebraic multiplication and allocation operation
    inline lx_cinterval & operator *=(lx_cinterval &a, const lx_complex &b) 
	noexcept;

    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &,const l_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const l_cinterval &,const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const l_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const l_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const l_complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_cinterval &, const lx_complex &) 
	noexcept;
    //! Implementation of standard algebraic division operation
    inline lx_cinterval operator / (const lx_complex &, const lx_cinterval &) 
	noexcept;

    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const l_cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const l_real &) noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const lx_real &) noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const real &) noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const interval &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard algebraic division and allocation operation
    inline lx_cinterval & operator /=(lx_cinterval &, const lx_complex &) 
	noexcept;


    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const l_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const l_cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const l_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const l_real &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const l_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const lx_real &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const real &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const interval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const l_complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_cinterval &, const lx_complex &) 
	noexcept;
    //! Implementation of standard equality operation
    inline bool operator == (const lx_complex &, const lx_cinterval &) 
	noexcept;


    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const l_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const l_cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const lx_interval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const l_interval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const l_interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const l_real &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const l_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const lx_real &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const real &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const real &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const interval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const interval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const cinterval &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const complex &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const l_complex &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const l_complex &, const lx_cinterval &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_cinterval &, const lx_complex &) 
	noexcept;
    //! Implementation of standard negated equality operation
    inline bool operator != (const lx_complex &, const lx_cinterval &) 
	noexcept;


// ------------------------- Set Operators ------------------------------

    //! Implementation of standard greater-than operation
    inline bool operator > (const lx_cinterval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >= (const lx_cinterval &, const lx_cinterval &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const l_cinterval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation 
    inline bool operator  >(const l_cinterval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const l_cinterval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const l_cinterval &, const lx_cinterval &) noexcept; 
    //! Implementation of standard less-than operation
    inline bool operator  <(const lx_cinterval &, const l_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const l_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_cinterval &, const l_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const l_cinterval &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const cinterval &, const lx_cinterval &) noexcept; 
    //! Implementation of standard greater-than operation
    inline bool operator  >(const cinterval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const cinterval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const cinterval &, const lx_cinterval &) noexcept; 
    //! Implementation of standard less-than operation
    inline bool operator  <(const lx_cinterval &, const cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_cinterval &, const cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const cinterval &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const lx_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation 
    inline bool operator  >(const lx_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-than operation 
    inline bool operator  <(const lx_cinterval &, const lx_interval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const lx_interval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_cinterval &, const lx_interval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const lx_interval &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const l_interval &, const lx_cinterval &) noexcept; 
    //! Implementation of standard greater-than operation
    inline bool operator  >(const l_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const l_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const l_interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-than operation 
    inline bool operator  <(const lx_cinterval &, const l_interval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const l_interval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_cinterval &, const l_interval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const l_interval &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const interval &, const lx_cinterval &) noexcept; 
    //! Implementation of standard greater-than operation
    inline bool operator  >(const interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const interval &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const interval &, const lx_cinterval &) noexcept; 
    //! Implementation of standard less-than operation
    inline bool operator  <(const lx_cinterval &, const interval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const interval &) noexcept;
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_cinterval &, const interval &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const interval &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const lx_real &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation 
    inline bool operator <=(const lx_real &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const lx_real &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const lx_real &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const l_real &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation 
    inline bool operator <=(const l_real &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const l_real &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const l_real &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const real &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation 
    inline bool operator <=(const real &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const real &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const real &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const complex &, const lx_cinterval &) noexcept;
    //! Implementation of standard less-or-equal-than operation 
    inline bool operator <=(const complex &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const complex &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const complex &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const l_complex &, const lx_cinterval &) noexcept; 
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const l_complex &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const l_complex &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const l_complex &) noexcept;

    //! Implementation of standard less-than operation
    inline bool operator  <(const lx_complex &, const lx_cinterval &) noexcept; 
    //! Implementation of standard less-or-equal-than operation
    inline bool operator <=(const lx_complex &, const lx_cinterval &) noexcept;
    //! Implementation of standard greater-than operation
    inline bool operator  >(const lx_cinterval &, const lx_complex &) noexcept;
    //! Implementation of standard greater-or-equal-than operation
    inline bool operator >=(const lx_cinterval &, const lx_complex &) noexcept;

// ------------------------- Convex Hull ---------------------------------

    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const lx_cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const lx_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_real&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const lx_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const l_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_real&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const l_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const real&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const l_cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_cinterval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const l_cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const cinterval& a, const lx_cinterval& b) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const lx_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_interval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const lx_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const l_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_interval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const l_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const interval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const lx_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_complex&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const lx_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const l_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_complex&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const l_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_cinterval&, const complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const complex&, const lx_cinterval&) 
	noexcept;
    //! Allocates the convex hull of the arguments to the first argument
    inline lx_cinterval & operator |= (lx_cinterval&, const complex&) 
	noexcept;

    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_interval&, const complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | ( const complex&, const lx_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_interval&, const lx_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | ( const lx_complex&, const lx_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_interval&, const l_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | ( const l_complex&, const lx_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_real&, const cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const cinterval&, const lx_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_real&, const l_cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_cinterval&, const lx_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_interval&, const cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const cinterval&, const lx_interval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_interval&, const l_cinterval&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_cinterval&, const lx_interval&) 
	noexcept;

    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_real&, const complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const complex&, const lx_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_real&, const l_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const l_complex&, const lx_real&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_real&, const lx_complex&) 
	noexcept;
    //! Returns the convex hull of the arguments
    inline lx_cinterval operator | (const lx_complex&, const lx_real&) 
	noexcept;

// ------------------------- Intersection ----------------------------------

    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const lx_cinterval&) 
	noexcept(false);
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const lx_real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_real&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const lx_real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const l_real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_real&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const l_real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const real&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const l_cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_cinterval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const l_cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const cinterval& a, const lx_cinterval& b) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const lx_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_interval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const lx_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const l_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_interval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const l_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const interval&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_complex&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const l_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_complex&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const l_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_cinterval&, const complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const complex&, const lx_cinterval&) 
	noexcept;
    //! Allocates the intersection of the arguments to the first argument
    inline lx_cinterval & operator &= (lx_cinterval&, const complex&) 
	noexcept;

    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_interval&, const complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const complex&, const lx_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_interval&, const l_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const l_complex&, const lx_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_interval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const lx_complex&, const lx_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_real&, const cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const cinterval&, const lx_real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_real&, const l_cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_cinterval&, const lx_real&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_interval&, const cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const cinterval&, const lx_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const lx_interval&, const l_cinterval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_cinterval&, const lx_interval&) 
	noexcept;


    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_interval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const lx_complex&, const l_interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const l_cinterval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const lx_complex&, const l_cinterval&) 
	noexcept;

    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const interval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const lx_complex&, const interval&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & (const cinterval&, const lx_complex&) 
	noexcept;
    //! Returns the intersection of the arguments
    inline lx_cinterval operator & ( const lx_complex&, const cinterval&) 
	noexcept;

// ------------------------ Input --------------------------------------

    //! Implementation of standard input method
    std::string & operator >> (std::string&, lx_cinterval&) noexcept;
    //! Implementation of standard input method
    void operator >> (const std::string&, lx_cinterval&) noexcept;
    //! Implementation of standard input method
    void operator >> (const char *s, lx_cinterval&) noexcept;
    //! Implementation of standard input method
    std::istream & operator >> (std::istream&, lx_cinterval&) noexcept;
	 

// ---------------------------------------------------------------------------
// ----- Elementary functions related to lx_cinterval
// ---------------------------------------------------------------------------
	 
    //! Calculates \f$ [z]^2  \f$
	 lx_cinterval sqr(const lx_cinterval&) noexcept;
    //! Calculates \f$ \sqrt{[z]}  \f$
	 lx_cinterval sqrt(const lx_cinterval&) noexcept;
    //! Calculates \f$ \sqrt[n]{[z]} \f$
	 lx_cinterval sqrt(const lx_cinterval& ,int) noexcept; 
    //! Calculates \f$ \exp([z]) \f$
	 lx_cinterval exp(const lx_cinterval&) noexcept;
	 //! Calculates \f$ 2^{[z]} \f$
	 lx_cinterval exp2(const lx_cinterval&) noexcept;
	 //! Calculates \f$ 10^{[z]} \f$
	 lx_cinterval exp10(const lx_cinterval&) noexcept;
    //! Calculates \f$ \sin([z]) \f$
	 lx_cinterval sin(const lx_cinterval&) noexcept;
    //! Calculates \f$ \cos([z]) \f$
	 lx_cinterval cos(const lx_cinterval&) noexcept;

    //! Calculates \f$ \cosh([z]) \f$
	 lx_cinterval cosh(const lx_cinterval&) noexcept;
    //! Calculates \f$ \sinh([z]) \f$
	 lx_cinterval sinh(const lx_cinterval&) noexcept;

    //! Calculates \f$ \mbox{Arg}([z]) \f$
	 lx_interval Arg(const lx_cinterval&) noexcept;
    //! Calculates \f$ \mbox{arg}([z]) \f$
	 lx_interval arg(const lx_cinterval&) noexcept;

    //! Calculates \f$ \ln([z]) \f$
	 lx_cinterval Ln(const lx_cinterval& ) noexcept;
    //! Calculates \f$ \ln([z]) \f$
	 lx_cinterval ln(const lx_cinterval& ) noexcept;
	 
    //! Calculates \f$ \mbox{log2}([z]) \f$
	 lx_cinterval log2(const lx_cinterval& ) noexcept;
    //! Calculates \f$ \mbox{log10}([z]) \f$
	 lx_cinterval log10(const lx_cinterval& ) noexcept;

    //! Calculates \f$ [z]^n \f$
	 lx_cinterval power_fast( const lx_cinterval&, const real& ) noexcept;
    //! Calculates \f$ [z]^n \f$
	 lx_cinterval power( const lx_cinterval&, const real& ) noexcept;
    //! Calculates \f$ [z]^{[p]} \f$
	 lx_cinterval pow( const lx_cinterval& , const lx_interval& ) noexcept;
    //! Calculates \f$ [z]^{[w]} \f$
	 lx_cinterval pow( const lx_cinterval& , const lx_cinterval& ) noexcept;

    //! Calculates \f$ \tan([z]) \f$
	 lx_cinterval tan (const lx_cinterval& ) noexcept;
    //! Calculates \f$ \cot([z]) \f$
	 lx_cinterval cot (const lx_cinterval& ) noexcept;
    //! Calculates \f$ \tanh([z]) \f$
	 lx_cinterval tanh(const lx_cinterval& ) noexcept;
    //! Calculates \f$ \coth([z]) \f$
	 lx_cinterval coth(const lx_cinterval& ) noexcept;

    //! Calculates \f$ \arcsin([z]) \f$
	 lx_cinterval asin(const lx_cinterval& ) noexcept;
    //! Calculates \f$ \arccos([z]) \f$
	 lx_cinterval acos(const lx_cinterval& ) noexcept;
    //! Calculates \f$ \arctan([z]) \f$
	 lx_cinterval atan(const lx_cinterval& ) noexcept;
    //! Calculates \f$ \mbox{arccot}([z]) \f$
	 lx_cinterval acot(const lx_cinterval& ) noexcept;

    //! Calculates \f$ \mbox{arcsinh}([z]) \f$
	 lx_cinterval asinh( const lx_cinterval& ) noexcept;
    //! Calculates \f$ \mbox{arccosh}([z]) \f$
	 lx_cinterval acosh( const lx_cinterval& ) noexcept;
    //! Calculates \f$ \mbox{arctanh}([z]) \f$
	 lx_cinterval atanh( const lx_cinterval& ) noexcept;
    //! Calculates \f$ \mbox{arccoth}([z]) \f$
	 lx_cinterval acoth( const lx_cinterval& ) noexcept;
	 
    //! Calculates \f$ \mbox{sqrt}(1+[z]^2) \f$
	 lx_cinterval sqrt1px2(const lx_cinterval& z) noexcept;
    //! Calculates \f$ \mbox{sqrt}(1-[z]^2) \f$	 
	 lx_cinterval sqrt1mx2(const lx_cinterval& z) noexcept;
	 //! Calculates \f$ \mbox{sqrt}([z]^2-1) \f$
	 lx_cinterval sqrtx2m1(const lx_cinterval& z) noexcept;
	 //! Calculates \f$ \mbox{sqrt}([z]+1)-1 \f$
	 lx_cinterval sqrtp1m1(const lx_cinterval& z) noexcept;
	 //! Calculates \f$ \mbox{exp}([z])-1 \f$
	 lx_cinterval expm1(const lx_cinterval& z) noexcept;
	 //! Calculates \f$ \mbox{ln}(1+[z]) \f$	 
	 lx_cinterval lnp1(const lx_cinterval& z) noexcept;
	 //! Calculates \f$ \mbox{sqrt}([z]) \f$ and returns all possible solutions
	 std::list<lx_cinterval> sqrt_all( const lx_cinterval& z) noexcept;
	 //! Calculates \f$ \mbox{sqrt}[n][z] \f$ and returns all possible solutions
	 std::list<lx_cinterval> sqrt_all( const lx_cinterval& z, int n ) noexcept;
	 //! Calculates \f$ [z]^{[y]} \f$ and returns all possible solutions
	 std::list<lx_cinterval> pow_all( const lx_cinterval& z, const lx_interval& p ) noexcept;
}  // end namespace cxsc

#include "lx_cinterval.inl"

#endif // _CXSC_LX_CINTERVAL_HPP_INCLUDED
