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

/* CVS $Id: intvector.hpp,v 1.20 2014/01/30 17:23:45 cxsc Exp $ */

#ifndef _CXSC_INTVECTOR_HPP_INCLUDED
#define _CXSC_INTVECTOR_HPP_INCLUDED

#include "xscclass.hpp"
#include "dot.hpp"
#include "idot.hpp"
#include "cdot.hpp"
#include "cidot.hpp"
#include "except.hpp"
#include "vector.hpp"

#include <iostream>

namespace cxsc{

int abs(int a);

class intvector_slice;

//! The Data Type intvector
/*!
The vectors of C-XSC are one dimensional arrays of the corresponding scalar base type. 

\sa rvector
*/
class intvector
{
	friend class intvector_slice;
	friend class intmatrix;
	friend class intmatrix_subv;
//#if(CXSC_INDEX_CHECK)
	//------------ Templates --------------------------------------------------
#ifdef _CXSC_FRIEND_TPL
template <class V,class MS,class S> friend  void _vmsconstr(V &v,const MS &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__TYPE_CAST_OF_THICK_OBJ<MS>);
#else
	noexcept;
#endif
template <class V,class M,class S> friend  void _vmconstr(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__TYPE_CAST_OF_THICK_OBJ<M>);
#else
	noexcept;
#endif
 template <class V> friend 	 void _vresize(V &rv) noexcept;
 template <class V,class S> friend 	 void _vresize(V &rv, const int &len)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__WRONG_BOUNDARIES<V>);
#else
	noexcept;
#endif
 template <class V,class S> friend 	 void _vresize(V &rv, const int &lb, const int &ub)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__WRONG_BOUNDARIES<V>);
#else
	noexcept;
#endif
 template <class V1,class V2,class S> friend 	 V1 &_vvassign(V1 &rv1,const V2 &rv2) noexcept;
 template <class V,class S> friend 	 V & _vsassign(V &rv,const S &r) noexcept;
 template <class V,class VS,class S> friend 	 V & _vvsassign(V &rv,const VS &sl) noexcept;
 template <class VS,class V> friend 	 VS & _vsvassign(VS &sl,const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
template <class V,class M,class S> friend  V &_vmassign(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__TYPE_CAST_OF_THICK_OBJ<M>);
#else
	noexcept;
#endif
template <class M,class V,class S> friend  M &_mvassign(M &m,const V &v) noexcept;
template <class MV,class V> friend  MV &_mvvassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
template <class MV,class V> friend  V _mvabs(const MV &mv) noexcept;

	//-------- vector-vector -----------------
 template <class DP,class V1,class V2> friend 	 void _vvaccu(DP &dp, const V1 & rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
 template <class DP,class VS,class V> friend 	 void _vsvaccu(DP &dp, const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
 template <class V,class S> friend 	 V &_vsmultassign(V &rv,const S &r) noexcept;
 template <class VS,class S> friend 	 VS &_vssmultassign(VS &rv,const S &r) noexcept;
 template <class VS,class S> friend 	 VS &_vssdivassign(VS &rv,const S &r) noexcept;
 template <class V1,class V2,class E> friend 	 E _vvplus(const V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V,class VS,class E> friend 	 E _vvsplus(const V &rv,const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsplus(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsminus(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V1,class V2> friend 	 V1 &_vvplusassign(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvsplusassign(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvplusassign(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsplusassign(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsminusassign(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V1,class V2> friend 	 V1 &_vvminusassign(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvsminusassign(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvminusassign(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class V> friend 	 V _vminus(const V &rv) noexcept;
 template <class VS,class V> friend 	 V _vsminus(const VS &sl) noexcept;
 template <class V1,class V2,class E> friend 	 E _vvminus(const V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class V,class VS,class E> friend 	 E _vvsminus(const V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS,class V,class E> friend 	 E _vsvminus(const VS &sl,const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class MV1,class MV2,class E> friend 	 E _mvmvplus(const MV1 &rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class MV,class V,class E> friend 	 E _mvvplus(const MV &rv1, const V &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class MV,class V,class E> friend 	 E _mvvminus(const MV &rv1, const V &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class V,class MV,class E> friend 	 E _vmvminus(const V &rv1, const MV &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class MV1,class MV2,class E> friend 	 E _mvmvminus(const MV1 &rv1, const MV2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvplusassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvminusassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif

	
template <class DP,class V,class SV> friend 	 void _vmvaccu(DP &dp, const V & rv1, const SV &rv2)
#if(CXSC_INDEX_CHECK)
		throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//--------- vector-scalar ----------------
 template <class V,class S,class E> friend 	 E _vsdiv(const V &rv, const S &s) noexcept;
 template <class V,class S> friend 	 V &_vsdivassign(V &rv,const S &r) noexcept;
 template <class VS,class S,class E> friend 	 E _vssdiv(const VS &sl, const S &s) noexcept;
 template <class MV,class S,class E> friend 	 E _mvsmult(const MV &rv, const S &s) noexcept;
 template <class V,class S,class E> friend 	 E _vsmult(const V &rv, const S &s) noexcept;
 template <class VS,class S,class E> friend 	 E _vssmult(const VS &sl, const S &s) noexcept;
 template <class V1,class V2> friend 	 bool _vveq(const V1 &rv1, const V2 &rv2) noexcept;
 template <class VS,class V> friend 	 bool _vsveq(const VS &sl, const V &rv) noexcept;
 template <class V1,class V2> friend 	 bool _vvneq(const V1 &rv1, const V2 &rv2) noexcept;
 template <class VS,class V> friend 	 bool _vsvneq(const VS &sl, const V &rv) noexcept;
 template <class V1,class V2> friend 	 bool _vvless(const V1 &rv1, const V2 &rv2) noexcept;
 template <class VS,class V> friend 	 bool _vsvless(const VS &sl, const V &rv) noexcept;
 template <class V1,class V2> friend 	 bool _vvleq(const V1 &rv1, const V2 &rv2) noexcept;
 template <class VS,class V> friend 	 bool _vsvleq(const VS &sl, const V &rv) noexcept;
 template <class V,class VS> friend 	 bool _vvsless(const V &rv, const VS &sl) noexcept;
 template <class V,class VS> friend 	 bool _vvsleq(const V &rv, const VS &sl) noexcept;
 template <class V> friend 	 bool _vnot(const V &rv) noexcept;
 template <class V> friend 	 void *_vvoid(const V &rv) noexcept;
 template <class V,class E> friend 	 E _vabs(const V &rv) noexcept;
 template <class VS,class E> friend 	 E _vsabs(const VS &sl) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvseq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsneq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsless(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsleq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS> friend 	 bool _vsnot(const VS &sl) noexcept;
 template <class VS> friend 	 void *_vsvoid(const VS &sl) noexcept;
 template <class V> friend 	std::ostream &_vout(std::ostream &s, const V &rv) noexcept;
 template <class V> friend 	std::istream &_vin(std::istream &s, V &rv) noexcept;

template <class V,class MV2,class S> friend  V &_vmvassign(V &v,const MV2 &rv) noexcept;
 template <class MV,class S,class E> friend 	 E _mvsdiv(const MV &rv, const S &s) noexcept;
	
#endif

	private:
	int *dat;
	int l,u,size;

	public:
	//------ Konstruktoren ----------------------------------------------------
	//! Constructor of class intvector
	INLINE intvector () noexcept;
#ifdef OLD_CXSC
	//! Constructor of class intvector
	explicit INLINE intvector(const class index &i) throw(); // for backwards compatibility
#endif
	//! Constructor of class intvector
	explicit INLINE intvector(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_WRONG_BOUNDARIES,ERROR_INTVECTOR_NO_MORE_MEMORY);
#else
	noexcept;
#endif
	//! Constructor of class intvector
	INLINE intvector(const intmatrix_subv &) noexcept;
	//! Constructor of class intvector
	explicit INLINE intvector(const int &) noexcept;
	//! Constructor of class intvector
	explicit INLINE intvector(const intmatrix &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Constructor of class intvector
	explicit INLINE intvector(const intmatrix_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Constructor of class intvector
	INLINE intvector(const intvector_slice &rs) noexcept;
	//! Constructor of class intvector
	INLINE intvector(const intvector &v) noexcept;
	//! Implementation of standard assigning operator
	INLINE intvector &operator =(const intvector &rv) noexcept;
	//! Implementation of standard assigning operator
	INLINE intvector &operator =(const intvector_slice &sl) noexcept;
	//! Implementation of standard assigning operator
	INLINE intvector &operator =(const int &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE intvector &operator =(const intmatrix &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE intvector &operator =(const intmatrix_slice &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE intvector &operator =(const intmatrix_subv &) noexcept;

	//--------- Destruktor ----------------------------------------------------
	INLINE ~intvector() { delete [] dat; }

	//------ Standardfunktionen -----------------------------------------------
	
	//! Returns the lower bound of the vector
	friend INLINE int Lb(const intvector &rv) noexcept { return rv.l; }
	//! Returns the upper bound of the vector
	friend INLINE int Ub(const intvector &rv) noexcept { return rv.u; }
	//! Returns the dimension of the vector
        friend INLINE int VecLen(const intvector &rv) noexcept { return rv.size; }
	//! Sets the lower bound of the vector
	friend INLINE intvector &SetLb(intvector &rv, const int &l) noexcept { rv.l=l; rv.u=l+rv.size-1; return rv; }
	//! Sets the upper bound of the vector
	friend INLINE intvector &SetUb(intvector &rv, const int &u) noexcept { rv.u=u; rv.l=u-rv.size+1; return rv; }
	//! Operator for accessing the single elements of the vector
	INLINE int & operator [](const int &i)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the single elements of the vector
	INLINE const int &operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the whole vector
	INLINE intvector & operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the vector
	INLINE intvector_slice operator ()(const int &i)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the vector
	INLINE intvector_slice operator ()(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	
	INLINE operator void*() noexcept;
//#else
//#endif
};

//! The Data Type intvector_slice
/*!
This data type represents a partial intvector.

\sa intvector
*/
class intvector_slice
{
	friend class intvector;
	friend class intmatrix;
	private:
	int *dat;
	int l,u,size;
	int start,end;

	public:
//#if(CXSC_INDEX_CHECK)	
#ifdef _CXSC_FRIEND_TPL
//------------------------- Templates -------------------------------------------
 template <class VS1,class VS2> friend 	 VS1 & _vsvsassign(VS1 &sl1,const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V,class VS,class S> friend 	 V & _vvsassign(V &rv,const VS &sl) noexcept;
 template <class VS,class V> friend 	 VS & _vsvassign(VS &sl,const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS,class S> friend 	 VS & _vssassign(VS &sl,const S &r) noexcept;
	//-------- vector-scalar ------------------
 template <class VS,class S> friend 	 VS &_vssmultassign(VS &rv,const S &r) noexcept;
 template <class VS,class S> friend 	 VS &_vssdivassign(VS &rv,const S &r) noexcept;
	
 template <class VS,class V> friend 	 bool _vsveq(const VS &sl, const V &rv) noexcept;
 template <class VS,class V> friend 	 bool _vsvneq(const VS &sl, const V &rv) noexcept;
 template <class VS,class V> friend 	 bool _vsvless(const VS &sl, const V &rv) noexcept;
 template <class VS,class V> friend 	 bool _vsvleq(const VS &sl, const V &rv) noexcept;
 template <class V,class VS> friend 	 bool _vvsless(const V &rv, const VS &sl) noexcept;
 template <class V,class VS> friend 	 bool _vvsleq(const V &rv, const VS &sl) noexcept;
 template <class VS,class E> friend 	 E _vsabs(const VS &sl) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvseq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsneq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsless(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsleq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS> friend 	 bool _vsnot(const VS &sl) noexcept;
 template <class VS> friend 	 void *_vsvoid(const VS &sl) noexcept;
 template <class V> friend 	std::ostream &_vsout(std::ostream &s, const V &rv) noexcept;
 template <class V> friend 	std::istream &_vsin(std::istream &s, V &rv) noexcept;
	//------- vector-matrix ----------------
	//------- vector-vector -----------------
 template <class DP,class VS,class V> friend 	 void _vsvaccu(DP &dp, const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
 template <class DP,class VS1,class VS2> friend 	 void _vsvsaccu(DP &dp, const VS1 & sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
 template <class VS,class S,class E> friend 	 E _vssdiv(const VS &sl, const S &s) noexcept;
 template <class VS,class S,class E> friend 	 E _vssmult(const VS &sl, const S &s) noexcept;
 template <class VS,class V,class E> friend 	 E _vsvmult(const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class V,class VS,class E> friend 	 E _vvsplus(const V &rv,const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsplus(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsminus(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvsplusassign(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvplusassign(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsplusassign(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsminusassign(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvsminusassign(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvminusassign(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 V _vsminus(const VS &sl) noexcept;
 template <class V,class VS,class E> friend 	 E _vvsminus(const V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS,class V,class E> friend 	 E _vsvminus(const VS &sl,const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsmult(const VS1 & sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif

#endif
	
	
	//--------------------- Konstruktoren -----------------------------------
	//! Constructor of class intvector_slice
	explicit INLINE intvector_slice(intvector &a, const int &lb, const int &ub) noexcept:dat(a.dat),l(a.l),u(a.u),size(ub-lb+1),start(lb),end(ub) { }
	//! Constructor of class intvector_slice
	explicit INLINE intvector_slice(intvector_slice &a, const int &lb, const int &ub) noexcept:dat(a.dat),l(a.l),u(a.u),size(ub-lb+1),start(lb),end(ub) { }
	public: 
	//! Constructor of class intvector_slice
	INLINE intvector_slice(const intvector_slice &a) noexcept:dat(a.dat),l(a.l),u(a.u),size(a.size),start(a.start),end(a.end) { }
	public:
	//! Constructor of class intvector_slice
	INLINE intvector_slice & operator =(const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE intvector_slice & operator =(const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE intvector_slice & operator =(const int &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE intvector_slice & operator =(const intmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>,ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE intvector_slice & operator =(const intmatrix_slice &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>,ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE intvector_slice &operator =(const intmatrix_subv &) noexcept;

	//--------------------- Standardfunktionen ------------------------------

	//! Returns the lower bound of the vector
	friend INLINE int Lb(const intvector_slice &sl) noexcept { return sl.start; }
	//! Returns the upper bound of the vector
	friend INLINE int Ub(const intvector_slice &sl) noexcept { return sl.end; }
	//! Returns the dimension of the vector
        friend INLINE int VecLen(const intvector_slice &sl) noexcept { return sl.end-sl.start+1; }
	//! Operator for accessing the single elements of the vector
	INLINE int & operator [](const int &i)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the single elements of the vector
	INLINE const int & operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the whole vector
	INLINE intvector_slice & operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the vector
	INLINE intvector_slice operator ()(const int &i)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the vector
	INLINE intvector_slice operator ()(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	
	//! Implementation of division and allocation operation
	INLINE intvector_slice &operator /=(const int &r) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE intvector_slice &operator *=(const int &r) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE intvector_slice &operator *=(const intmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_INTMATRIX_OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE intvector_slice &operator +=(const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE intvector_slice &operator +=(const intvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE intvector_slice &operator -=(const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE intvector_slice &operator -=(const intvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	INLINE operator void*() noexcept;
//#else
//#endif
};

//======================== Vector Functions =============================

	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE intvector _intvector(const int &r) noexcept; 
//	INLINE intvector _intvector(const intmatrix &m) throw(ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);
//	INLINE intvector _intvector(const intmatrix_slice &sl) throw(ERROR_INTMATRIX_TYPE_CAST_OF_THICK_OBJ);

	//! Resizes the vector
	INLINE void Resize(intvector &rv) noexcept;
	//! Resizes the vector
	INLINE void Resize(intvector &rv, const int &len)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__WRONG_BOUNDARIES<intvector>);
#else
	noexcept;
#endif
	//! Resizes the vector
	INLINE void Resize(intvector &rv, const int &lb, const int &ub)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__WRONG_BOUNDARIES<intvector>);
#else
	noexcept;
#endif
	
	//! Returns the absolute value of the vector
	INLINE intvector abs(const intvector &rv) noexcept;
	//! Returns the absolute value of the vector
	INLINE intvector abs(const intvector_slice &sl) noexcept;
	//! Implementation of standard negation operation
	INLINE bool operator !(const intvector &rv) noexcept;
	//! Implementation of standard negation operation
	INLINE bool operator !(const intvector_slice &sl) noexcept;

//======================= Vector / Scalar ===============================

	//! Implementation of multiplication operation
	INLINE intvector operator *(const intvector &rv, const int &s) noexcept;
	//! Implementation of multiplication operation
	INLINE intvector operator *(const intvector_slice &sl, const int &s) noexcept;
	//! Implementation of multiplication operation
	INLINE intvector operator *(const int &s, const intvector &rv) noexcept;
	//! Implementation of multiplication operation
	INLINE intvector operator *(const int &s, const intvector_slice &sl) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE intvector &operator *=(intvector &rv,const int &r) noexcept;

	//! Implementation of division operation
	INLINE intvector operator /(const intvector &rv, const int &s) noexcept;
	//! Implementation of division operation
	INLINE intvector operator /(const intvector_slice &sl, const int &s) noexcept;
	//! Implementation of division and allocation operation
	INLINE intvector &operator /=(intvector &rv,const int &r) noexcept;

//======================= Vector / Vector ===============================



	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const intvector & rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const intvector & rv1, const intmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const intmatrix_subv & rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp,const intvector_slice &sl,const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp,const intvector &rv,const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const intvector_slice & sl1, const intvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif


	//! Implementation of multiplication operation
	INLINE int operator *(const intvector & rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE int operator *(const intvector_slice &sl, const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE int operator *(const intvector &rv, const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE int operator *(const intvector_slice & sl1, const intvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	
	//! Implementation of positive sign operation
	INLINE const intvector &operator +(const intvector &rv) noexcept;
	//! Implementation of positive sign operation
	INLINE intvector operator +(const intvector_slice &sl) noexcept;
	//! Implementation of addition operation
	INLINE intvector operator +(const intvector &rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE intvector operator +(const intvector &rv, const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE intvector operator +(const intvector_slice &sl, const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE intvector operator +(const intvector_slice &sl1, const intvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE intvector & operator +=(intvector &rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE intvector &operator +=(intvector &rv, const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif

	//! Implementation of negative sign operation
	INLINE intvector operator -(const intvector &rv) noexcept;
	//! Implementation of negative sign operation
	INLINE intvector operator -(const intvector_slice &sl) noexcept;
	//! Implementation of subtraction operation
	INLINE intvector operator -(const intvector &rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE intvector operator -(const intvector &rv, const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE intvector operator -(const intvector_slice &sl, const intvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE intvector operator -(const intvector_slice &sl1, const intvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE intvector & operator -=(intvector &rv1, const intvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE intvector &operator -=(intvector &rv, const intvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<intvector>);
#else
	noexcept;
#endif

	//! Implementation of standard equality operation
	INLINE bool operator ==(const intvector &rv1, const intvector &rv2) noexcept;
	//! Implementation of standard equality operation
	INLINE bool operator ==(const intvector_slice &sl1, const intvector_slice &sl2) noexcept;
	//! Implementation of standard equality operation
	INLINE bool operator ==(const intvector_slice &sl, const intvector &rv) noexcept;
	//! Implementation of standard equality operation
	INLINE bool operator ==(const intvector &rv, const intvector_slice &sl) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const intvector &rv1, const intvector &rv2) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const intvector_slice &sl1, const intvector_slice &sl2) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const intvector_slice &sl, const intvector &rv) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const intvector &rv, const intvector_slice &sl) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator <(const intvector &rv1, const intvector &rv2) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator <(const intvector_slice &sl1, const intvector_slice &sl2) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator < (const intvector_slice &sl, const intvector &rv) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator < (const intvector &rv, const intvector_slice &sl) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const intvector &rv1, const intvector &rv2) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const intvector_slice &sl1, const intvector_slice &sl2) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const intvector_slice &sl, const intvector &rv) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const intvector &rv, const intvector_slice &sl) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const intvector &rv1, const intvector &rv2) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const intvector_slice &sl1, const intvector_slice &sl2) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const intvector_slice &sl, const intvector &rv) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const intvector &rv, const intvector_slice &sl) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const intvector &rv1, const intvector &rv2) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const intvector_slice &sl1, const intvector_slice &sl2) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const intvector_slice &sl, const intvector &rv) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const intvector &rv, const intvector_slice &sl) noexcept;

	//! Implementation of standard output method
	INLINE std::ostream &operator <<(std::ostream &s, const intvector &rv) noexcept;
	//! Implementation of standard output method
	INLINE std::ostream &operator <<(std::ostream &o, const intvector_slice &sl) noexcept;
	//! Implementation of standard input method
	INLINE std::istream &operator >>(std::istream &s, intvector &rv) noexcept;
	//! Implementation of standard input method
	INLINE std::istream &operator >>(std::istream &s, intvector_slice &rv) noexcept;


        INLINE intvector perminv(const intvector&);

extern void     DoubleSize ( intvector& );
//! Implementation of standard output method
extern std::ostream& operator<< ( std::ostream&, intvector& );


 
} // namespace cxsc
	
#ifdef _CXSC_INCL_INL
#include "intvector.inl"
#include "vector.inl"
#endif


#endif

