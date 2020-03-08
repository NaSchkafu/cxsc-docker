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

/* CVS $Id: lx_civector.hpp,v 1.9 2014/01/30 17:23:47 cxsc Exp $ */

#ifndef _CXSC_LX_CIVECTOR_HPP_INCLUDED
#define _CXSC_LX_CIVECTOR_HPP_INCLUDED 

#include <xscclass.hpp>
#include <real.hpp>
#include <except.hpp>
#include "lx_cinterval.hpp"

#include <iostream>

namespace cxsc {
	
//! The Multiple-Precision Data Type lx_civector
/*!
	The vectors of C-XSC are one dimensional arrays of the corresponding scalar base type. 

	\sa lx_ivector
 */	
	
class lx_civector
{	
	private:
		lx_cinterval *dat;
		int l,u,size;
		
	public:
	//------ Konstruktoren ----------------------------------------------------
		
	//! Constructor of class lx_civector
	inline lx_civector () noexcept;
		
	/*!
	\param i Dimension of vector
	Creation of a variable of type lx_civector with length \f$ n = i \f$ and index bounds \f$ lb = 1 \f$, and \f$ ub = i \f$. The values of the elements are undefined.
	*/
	explicit inline lx_civector(int i) noexcept;
		
	//! Constructor of class lx_civector
	explicit inline lx_civector(int i1, int i2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR_IVECTOR_WRONG_BOUNDARIES,ERROR_IVECTOR_NO_MORE_MEMORY);
#else
		noexcept;
#endif
		
	//! Constructor of class lx_civector
	explicit inline lx_civector(const lx_cinterval &) noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const l_cinterval &) noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const cinterval &) noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const lx_complex &) noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const l_complex &) noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const complex &) noexcept;
		
	//! Constructor of class lx_civector
	explicit inline lx_civector(const lx_interval &) noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const l_interval &)  noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const interval &)    noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const lx_real &)     noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const l_real &)      noexcept;
	//! Constructor of class lx_civector
	explicit inline lx_civector(const real &)        noexcept;
	
	//! Constructor of class lx_civector
	inline lx_civector(const lx_civector &) noexcept;
		
	
	//! Implementation of standard assigning operator
	inline lx_civector & operator = (const lx_civector &) noexcept;
	
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const lx_cinterval &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const l_cinterval &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const cinterval &) noexcept;
		//! Implementation of standard assigning operator
	inline lx_civector & operator =(const lx_complex &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const l_complex &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const complex &) noexcept;
	
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const lx_interval &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const l_interval &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const interval &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const lx_real &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const l_real &) noexcept;
	//! Implementation of standard assigning operator
	inline lx_civector & operator =(const real &) noexcept;
	
	//--------- Destruktor ----------------------------------------------------
	inline ~lx_civector() { delete [] dat; }
	
	
	//! Operator for accessing the single elements of the vector
	inline lx_cinterval & operator [](const int &i)
#if(CXSC_INDEX_CHECK)
			throw(ERROR_IVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the single elements of the vector
	inline const lx_cinterval & operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	throw(ERROR_IVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	
//------ Standardfunktionen -----------------------------------------------
	
//! Returns the lower bound of the vector
friend inline int Lb(const lx_civector &a) noexcept { return a.l; }
//! Returns the upper bound of the vector
friend inline int Ub(const lx_civector &a) noexcept { return a.u; }
//! Returns the dimension of the vector
friend inline int VecLen(const lx_civector &a) noexcept { return a.size; }
//! Sets the lower bound of the vector
friend inline lx_civector& SetLb(lx_civector &a, int l) noexcept 
{ a.l=l; a.u=l+a.size-1; return a; }
//! Sets the upper bound of the vector
friend inline lx_civector & SetUb(lx_civector &a, int u) noexcept
{ a.u=u; a.l=u-a.size+1; return a; }

//! Resizes the vector
friend inline void Resize(lx_civector &rv, int lb, int ub)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__WRONG_BOUNDARIES<lx_civector>);
#else
		noexcept;
#endif

//! Resizes the vector	
friend inline void Resize(lx_civector &rv, int len)
#if(CXSC_INDEX_CHECK)
				throw(ERROR__WRONG_BOUNDARIES<lx_civector>);
#else
		noexcept;
#endif		
	
}; // End of class lx_civector

//! Doubles the vector size
inline void DoubleSize(lx_civector&) noexcept;

inline void Resize(lx_civector &rv, int lb, int ub)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__WRONG_BOUNDARIES<lx_civector>);
#else
		noexcept;
#endif
		
		inline void Resize(lx_civector &rv, int len)
#if(CXSC_INDEX_CHECK)
				throw(ERROR__WRONG_BOUNDARIES<lx_civector>);
#else
		noexcept;
#endif		

} // End namespace cxsc
 

#include "lx_civector.inl"
					
#endif
