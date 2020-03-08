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

/* CVS $Id: l_rvector.hpp,v 1.19 2014/01/30 17:23:46 cxsc Exp $ */

#ifndef _CXSC_LRVECTOR_HPP_INCLUDED
#define _CXSC_LRVECTOR_HPP_INCLUDED

#include "xscclass.hpp"
#include "except.hpp"
#include "dot.hpp"
#include "idot.hpp"
#include "l_real.hpp" // used for declaration of Inf, Sup,...
//#include "cxscmatr.hpp"
#include "rvector.hpp"
#include "vector.hpp"


#include <iostream>

//#include "matrix.hpp" // hat hier eigentlich nichts zu suchen, sonst aber Internal Compiler Error #9

namespace cxsc {

class l_rvector_slice;

//! The Multiple-Precision Data Type l_rvector
/*!
The vectors of C-XSC are one dimensional arrays of the corresponding scalar base type. 

\sa l_rvector
*/
class l_rvector
{
	friend class l_rvector_slice;
	friend class l_rmatrix;
	friend class l_rmatrix_subv;
	friend class l_ivector;
	friend class l_imatrix;
	private:
	l_real *dat;
	int l,u,size;

	public:
//#if(CXSC_INDEX_CHECK)

template<typename S, typename T>
friend inline void addDot(const S &x, const T &y, dotprecision &val);


#ifdef _CXSC_FRIEND_TPL
	//------------ Templates --------------------------------------------------
	// l_real
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
 template <class V> friend 	 V _vconj(const V &rv) noexcept;
 template <class VS,class E> friend 	 E _vsconj(const VS &sl) noexcept;
 template <class V,class E> friend 	 E _vabs(const V &rv) noexcept;
 template <class VS,class E> friend 	 E _vsabs(const VS &sl) noexcept;
template <class MV,class V> friend  V _mvabs(const MV &mv) noexcept;

//-------- vector-vector -----------------------
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
 template <class V1,class V2,class E> friend 	 E _vvlmult(const V1 & rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class VS,class V,class E> friend 	 E _vsvlmult(const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class V,class S> friend 	 V &_vsmultassign(V &rv,const S &r) noexcept;
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
 template <class V,class MV,class S> friend 	 S _vmvlmult(const V &rv1, const MV &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
 template <class V1,class V2,class E> friend 	 E _vvconv(const V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class V,class VS,class E> friend 	 E _vvsconv(const V &rv,const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsconv(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
	//--------- vector-scalar -----------------
 template <class V,class S,class E> friend 	 E _vsdiv(const V &rv, const S &s) noexcept;
 template <class V,class S> friend 	 V &_vsdivassign(V &rv,const S &r) noexcept;
 template <class VS,class S,class E> friend 	 E _vssdiv(const VS &sl, const S &s) noexcept;
 template <class V,class S,class E> friend 	 E _vsmult(const V &rv, const S &s) noexcept;
 template <class VS,class S,class E> friend 	 E _vssmult(const VS &sl, const S &s) noexcept;
 template <class MV,class S,class E> friend 	 E _mvsmult(const MV &rv, const S &s) noexcept;
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
 template <class MV,class S,class E> friend 	 E _mvsdiv(const MV &rv, const S &s) noexcept;
template <class MV,class V> friend  MV &_mvvassign(MV &v,const V &rv)
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
 template <class VS1,class VS2> friend 	 bool _vsvseq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsneq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsless(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsleq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS> friend 	 bool _vsnot(const VS &sl) noexcept;
 template <class VS> friend 	 void *_vsvoid(const VS &sl) noexcept;
 template <class V> friend 	std::ostream &_vout(std::ostream &s, const V &rv) noexcept;
 template <class V> friend 	std::istream &_vin(std::istream &s, V &rv) noexcept;

	//------------- vector-matrix ---------------
template <class V,class MV2,class S> friend  V &_vmvassign(V &v,const MV2 &rv) noexcept;
 template <class M,class V,class E> friend 	 E _mvlmult(const M &m,const V &v)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<M>);
#else
	noexcept;
#endif
 template <class V,class M,class E> friend 	 E _vmlmult(const V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<M>);
#else
	noexcept;
#endif
 template <class V,class M,class S> friend 	 V &_vmlmultassign(V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<M>);
#else
	noexcept;
#endif
 template <class MS,class V,class E> friend 	 E _msvlmult(const MS &ms,const V &v)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
 template <class V,class MS,class E> friend 	 E _vmslmult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
 template <class V,class MS,class S> friend 	 V &_vmslmultassign(V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
	
	// interval -----------------
	// vector-vector
 template <class V1,class V2,class E> friend 	 E _vvlimult(const V1 & rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class VS,class V,class E> friend 	 E _vsvlimult(const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvslimult(const VS1 & sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V1,class V2,class E> friend 	 E _vvsect(const V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V,class VS,class E> friend 	 E _vvssect(const V &rv,const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvssect(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif

	// vector-matrix
 template <class M,class V,class E> friend 	 E _mvlimult(const M &m,const V &v)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<M>);
#else
	noexcept;
#endif
 template <class V,class M,class E> friend 	 E _vmlimult(const V &v,const M &m)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<M>);
#else
	noexcept;
#endif
 template <class MS,class V,class E> friend 	 E _msvlimult(const MS &ms,const V &v)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
 template <class V,class MS,class E> friend 	 E _vmslimult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
	
	// l_interval -----------------
 template <class V1,class V2> friend 	 V1 &_vvsetinf(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V1,class V2> friend 	 V1 &_vvsetsup(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V1,class V2> friend 	 V1 &_vvusetinf(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V1,class V2> friend 	 V1 &_vvusetsup(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvsetinf(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvsetsup(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvusetinf(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvusetsup(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvsetinf(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvsetsup(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvusetinf(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvusetsup(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
 template <class V,class E> friend 	 E _vmid(const V &rv) noexcept;
 template <class V,class E> friend 	 E _vinf(const V &rv) noexcept;
 template <class V,class E> friend 	 E _vsup(const V &rv) noexcept;
 template <class V,class E> friend 	 E _vdiam(const V &rv) noexcept;
 template <class VS,class E> friend 	 E _vsmid(const VS &sl) noexcept;
 template <class VS,class E> friend 	 E _vsinf(const VS &sl) noexcept;
 template <class VS,class E> friend 	 E _vssup(const VS &sl) noexcept;
 template <class VS,class E> friend 	 E _vsdiam(const VS &sl) noexcept;
template <class MV,class V> friend  V _mvdiam(const MV &mv) noexcept;
template <class MV,class V> friend  V _mvmid(const MV &mv) noexcept;
template <class MV,class V> friend  V _mvinf(const MV &mv) noexcept;
template <class MV,class V> friend  V _mvsup(const MV &mv) noexcept;

	// vector-vector
 template <class V1,class V2> friend 	 V1 &_vvconvassign(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V1,class V2> friend 	 V1 &_vvsectassign(V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvconvassign(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 VS &_vsvsectassign(VS &sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS>);
#else
	noexcept;
#endif

template <class MV,class V> friend  MV &_mvvconvassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif
template <class MV,class V> friend  MV &_mvvsectassign(MV &v,const V &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<MV>);
#else
	noexcept;
#endif


#endif

	//------ Konstruktoren ----------------------------------------------------
	//! Constructor of class l_rvector
	INLINE l_rvector () noexcept;
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const int &i) noexcept;
#ifdef OLD_CXSC
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const class index &i) throw(); // for backwards compatibility
#endif
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_WRONG_BOUNDARIES,ERROR_LRVECTOR_NO_MORE_MEMORY);
#else
	noexcept;
#endif
	//! Constructor of class l_rvector
	INLINE l_rvector(const l_rmatrix_subv &) noexcept;
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const l_real &) noexcept;
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const l_rmatrix &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const l_rmatrix_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Constructor of class l_rvector
	INLINE l_rvector(const l_rvector_slice &rs) noexcept;
	//! Constructor of class l_rvector
	INLINE l_rvector(const l_rvector &v) noexcept;
	// Real
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const real &) noexcept;
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const rvector_slice &rs) noexcept;
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const rvector &v) noexcept;
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const rmatrix &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const rmatrix_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Constructor of class l_rvector
	explicit INLINE l_rvector(const rmatrix_subv &) noexcept;
	
	// l_real
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const l_rvector &rv) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const l_rvector_slice &sl) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const l_real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const l_rmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const l_rmatrix_slice &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const l_rmatrix_subv &) noexcept;
	// Real
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const rvector &rv) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const rvector_slice &sl) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const rmatrix_slice &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector &operator =(const rmatrix_subv &) noexcept;

	//--------- Destruktor ----------------------------------------------------
	INLINE ~l_rvector() { delete [] dat; }

	//------ Standardfunktionen -----------------------------------------------
	
	friend INLINE l_real::l_real(const l_rvector &)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_TYPE_CAST_OF_THICK_OBJ,ERROR_LRVECTOR_USE_OF_UNINITIALIZED_OBJ);
#else
	noexcept;
#endif
	//! Returns the lower bound of the vector
	friend INLINE int Lb(const l_rvector &rv) noexcept { return rv.l; }
	//! Returns the upper bound of the vector
	friend INLINE int Ub(const l_rvector &rv) noexcept { return rv.u; }
	//! Returns the dimension of the vector
        friend INLINE int VecLen(const l_rvector &rv) noexcept { return rv.size; }
	//! Sets the lower bound of the vector
	friend INLINE l_rvector & SetLb(l_rvector &rv, const int &l) noexcept { rv.l=l; rv.u=l+rv.size-1; return rv;}
	//! Sets the upper bound of the vector
	friend INLINE l_rvector & SetUb(l_rvector &rv, const int &u) noexcept { rv.u=u; rv.l=u-rv.size+1; return rv;}
	//! Operator for accessing the single elements of the vector
	INLINE l_real & operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the whole vector
	INLINE l_rvector & operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the vector
	INLINE l_rvector_slice operator ()(const int &i)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the vector
	INLINE l_rvector_slice operator ()(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	INLINE operator void*() noexcept;
//#else
//#endif
};


//! The Multiple-Precision Data Type l_rvector_slice
/*!
This data type represents a partial rvector.

\sa l_rvector
*/
class l_rvector_slice
{
	friend class l_rvector;
	friend class l_rmatrix;
	friend class l_ivector;
	friend class l_imatrix;
	private:
	l_real *dat;
	int l,u,size;
	int start,end;

	public:
//#if(CXSC_INDEX_CHECK)	

template<typename S, typename T>
friend inline void addDot(const S &x, const T &y, dotprecision &val);


#ifdef _CXSC_FRIEND_TPL
//------------------------- Templates -------------------------------------------
// l_real / l_real

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

 template <class VS,class V,class E> friend 	 E _vsvlmult(const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS,class S> friend 	 VS &_vssmultassign(VS &rv,const S &r) noexcept;
 template <class VS,class S> friend 	 VS &_vssdivassign(VS &rv,const S &r) noexcept;
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
 template <class V,class VS,class E> friend 	 E _vvsconv(const V &rv,const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvsconv(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS,class V> friend 	 bool _vsveq(const VS &sl, const V &rv) noexcept;
 template <class VS,class V> friend 	 bool _vsvneq(const VS &sl, const V &rv) noexcept;
 template <class VS,class V> friend 	 bool _vsvless(const VS &sl, const V &rv) noexcept;
 template <class VS,class V> friend 	 bool _vsvleq(const VS &sl, const V &rv) noexcept;
 template <class V,class VS> friend 	 bool _vvsless(const V &rv, const VS &sl) noexcept;
 template <class V,class VS> friend 	 bool _vvsleq(const V &rv, const VS &sl) noexcept;
 template <class VS,class E> friend 	 E _vsabs(const VS &sl) noexcept;
 template <class VS1,class VS2,class E> friend 	 E _vsvslmult(const VS1 & sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 bool _vsvseq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsneq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsless(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS1,class VS2> friend 	 bool _vsvsleq(const VS1 &sl1, const VS2 &sl2) noexcept;
 template <class VS> friend 	 bool _vsnot(const VS &sl) noexcept;
 template <class VS> friend 	 void *_vsvoid(const VS &sl) noexcept;
 template <class V> friend 	std::ostream &_vsout(std::ostream &s, const V &rv) noexcept;
 template <class V> friend 	std::istream &_vsin(std::istream &s, V &rv) noexcept;

 template <class VS,class M,class S> friend 	 VS &_vsmlmultassign(VS &v,const M &m)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<M>);
#else
	noexcept;
#endif
	
	// l_real / Real
 template <class V,class MS,class E> friend 	 E _vmslmult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
	
 template <class V,class VS,class E> friend 	 E _vvssect(const V &rv,const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvssect(const VS1 &s1,const VS2 &s2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif

	// interval -----------
	// vector-vector -------
 template <class V1,class V2,class E> friend 	 E _vvlimult(const V1 & rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class VS,class V,class E> friend 	 E _vsvlimult(const VS & sl, const V &rv)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS1,class VS2,class E> friend 	 E _vsvslimult(const VS1 & sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class V1,class V2,class E> friend 	 E _vvplus(const V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V1>);
#else
	noexcept;
#endif
 template <class V1,class V2,class E> friend 	 E _vvminus(const V1 &rv1, const V2 &rv2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<E>);
#else
	noexcept;
#endif

	// vector-matrix -------
  /*   friend TINLINE l_ivector _mvslimult<imatrix,l_rvector_slice,l_ivector>(const imatrix &m,const l_rvector_slice &v)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_IMATRIX_OP_WITH_WRONG_DIM);
#else
	throw();
	#endif */
  /*   friend TINLINE l_ivector _vsmlimult<l_rvector_slice,imatrix,l_ivector>(const l_rvector_slice &v,const imatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LIMATRIX_OP_WITH_WRONG_DIM);
#else
	throw();
	#endif */

	// l_interval -- vector-vector
 template <class V,class VS> friend 	 V &_vvsconvassign(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvssectassign(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsconvassign(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvssectassign(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
#endif
	
	//--------------------- Konstruktoren -----------------------------------
	//! Constructor of class l_rvector_slice
	explicit INLINE l_rvector_slice(l_rvector &a, const int &lb, const int &ub) noexcept:dat(a.dat),l(a.l),u(a.u),size(ub-lb+1),start(lb),end(ub) { }
	//! Constructor of class l_rvector_slice
	explicit INLINE l_rvector_slice(l_rvector_slice &a, const int &lb, const int &ub) noexcept:dat(a.dat),l(a.l),u(a.u),size(ub-lb+1),start(lb),end(ub) { }
	public:
	//! Constructor of class l_rvector_slice
	INLINE l_rvector_slice(const l_rvector_slice &a) noexcept:dat(a.dat),l(a.l),u(a.u),size(a.size),start(a.start),end(a.end) { }
	public:
	// l_real
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const l_real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const l_rmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>,ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const l_rmatrix_slice &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>,ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice &operator =(const l_rmatrix_subv &) noexcept;
	// Real
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const real &r) noexcept;
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<rvector>,ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice & operator =(const rmatrix_slice &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<rvector>,ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
#else
	noexcept;
#endif
	//! Implementation of standard assigning operator
	INLINE l_rvector_slice &operator =(const rmatrix_subv &mv) noexcept;

	// l_interval --------
 template <class V,class VS> friend 	 V &_vvssetinf(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvssetsup(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvsusetinf(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class V,class VS> friend 	 V &_vvsusetsup(V &rv, const VS &sl)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<V>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvssetinf(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvssetsup(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsusetinf(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif
 template <class VS1,class VS2> friend 	 VS1 &_vsvsusetsup(VS1 &sl1, const VS2 &sl2)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<VS1>);
#else
	noexcept;
#endif

	// l_interval -- vector-vector
 template <class V,class MS,class E> friend 	 E _vmslimult(const V &v,const MS &ms)
#if(CXSC_INDEX_CHECK)
		throw(ERROR__OP_WITH_WRONG_DIM<MS>);
#else
	noexcept;
#endif
	// l_interval -- vector-matrix


	//--------------------- Standardfunktionen ------------------------------

	friend INLINE l_real::l_real(const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_TYPE_CAST_OF_THICK_OBJ,ERROR_LRVECTOR_USE_OF_UNINITIALIZED_OBJ);
#else
	noexcept;
#endif
	//! Returns the lower bound of the vector
	friend INLINE int Lb(const l_rvector_slice &sl) noexcept { return sl.start; }
	//! Returns the upper bound of the vector
	friend INLINE int Ub(const l_rvector_slice &sl) noexcept { return sl.end; }
	//! Returns the dimension of the vector
        friend INLINE int VecLen(const l_rvector_slice &sl) noexcept { return sl.end-sl.start+1; }
	//! Operator for accessing the single elements of the vector
	INLINE l_real & operator [](const int &i) const
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_ELEMENT_NOT_IN_VEC);
#else
	noexcept;
#endif
	//! Operator for accessing the whole vector
	INLINE l_rvector_slice & operator ()() noexcept { return *this; }
	//! Operator for accessing a part of the vector
	INLINE l_rvector_slice operator ()(const int &i)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	//! Operator for accessing a part of the vector
	INLINE l_rvector_slice operator ()(const int &i1,const int &i2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRVECTOR_SUB_ARRAY_TOO_BIG);
#else
	noexcept;
#endif
	
	//! Implementation of division and allocation operation
	INLINE l_rvector_slice &operator /=(const l_real &r) noexcept;
	//! Implementation of division and allocation operation
	INLINE l_rvector_slice &operator /=(const real &r) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE l_rvector_slice &operator *=(const l_real &r) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE l_rvector_slice &operator *=(const l_rmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_LRMATRIX_OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE l_rvector_slice &operator *=(const rmatrix &m)
#if(CXSC_INDEX_CHECK)
	throw(ERROR_RMATRIX_OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! Implementation of multiplication and allocation operation
	INLINE l_rvector_slice &operator *=(const real &r) noexcept;
	//! Implementation of addition and allocation operation
	INLINE l_rvector_slice &operator +=(const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE l_rvector_slice &operator +=(const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector_slice &operator -=(const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector_slice &operator -=(const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE l_rvector_slice &operator |=(const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE l_rvector_slice &operator |=(const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the intersection of the arguments to the first argument
	INLINE l_rvector_slice &operator &=(const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the intersection of the arguments to the first argument
	INLINE l_rvector_slice &operator &=(const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	
	//! Implementation of addition and allocation operation
	INLINE l_rvector_slice &operator +=(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE l_rvector_slice &operator +=(const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector_slice &operator -=(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector_slice &operator -=(const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE l_rvector_slice &operator |=(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the convex hull of the arguments to the first argument
	INLINE l_rvector_slice &operator |=(const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the intersection of the arguments to the first argument
	INLINE l_rvector_slice &operator &=(const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Allocates the intersection of the arguments to the first argument
	INLINE l_rvector_slice &operator &=(const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	INLINE operator void*() noexcept;
//#else
//#endif
};

//=======================================================================
//======================== Vector Functions =============================

	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE l_rvector _l_rvector(const l_real &r) noexcept;
//	INLINE l_rvector _l_rvector(const l_rmatrix &m) throw(ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
//	INLINE l_rvector _l_rvector(const l_rmatrix_slice &sl) throw(ERROR_LRMATRIX_TYPE_CAST_OF_THICK_OBJ);
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE l_rvector _l_rvector(const real &r) noexcept;
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE l_rvector _l_rvector(const rvector_slice &rs) noexcept;
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE l_rvector _l_rvector(const rvector &rs) noexcept;
//	INLINE l_rvector _l_rvector(const rmatrix &m) throw(ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
//	INLINE l_rvector _l_rvector(const rmatrix_slice &sl) throw(ERROR_RMATRIX_TYPE_CAST_OF_THICK_OBJ);
	//! Deprecated typecast, which only exist for the reason of compatibility with older versions of C-XSC
	INLINE l_rvector _l_rvector(const rmatrix_subv &rs) noexcept;

	//! Resizes the vector
	INLINE void Resize(l_rvector &rv) noexcept;
	//! Resizes the vector
	INLINE void Resize(l_rvector &rv, const int &len)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__WRONG_BOUNDARIES<l_rvector>);
#else
	noexcept;
#endif
	//! Resizes the vector
	INLINE void Resize(l_rvector &rv, const int &lb, const int &ub)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__WRONG_BOUNDARIES<l_rvector>);
#else
	noexcept;
#endif
	
	//! Returns the absolute value of the vector
	INLINE l_rvector abs(const l_rvector &rv) noexcept;
	//! Returns the absolute value of the vector
	INLINE l_rvector abs(const l_rvector_slice &sl) noexcept;
	//! Implementation of standard negation operation
	INLINE bool operator !(const l_rvector &rv) noexcept;
	//! Implementation of standard negation operation
	INLINE bool operator !(const l_rvector_slice &sl) noexcept;

//======================= Vector / Scalar ===============================

//----------------------------- l_real ---------------------------

	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_rvector &rv, const l_real &s) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_rvector_slice &sl, const l_real &s) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_real &s, const l_rvector &rv) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_real &s, const l_rvector_slice &sl) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE l_rvector &operator *=(l_rvector &rv,const l_real &r) noexcept;

	//! Implementation of division operation
	INLINE l_rvector operator /(const l_rvector &rv, const l_real &s) noexcept;
	//! Implementation of division operation
	INLINE l_rvector operator /(const l_rvector_slice &sl, const l_real &s) noexcept;
	//! Implementation of division and allocation operation
	INLINE l_rvector &operator /=(l_rvector &rv,const l_real &r) noexcept;

//---------------------------- Real --------------------------------------

	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_rvector &rv, const real &s) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_rvector_slice &sl, const real &s) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const real &s, const l_rvector &rv) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const real &s, const l_rvector_slice &sl) noexcept;
	//! Implementation of multiplication and allocation operation
	INLINE l_rvector &operator *=(l_rvector &rv,const real &r) noexcept;

	//! Implementation of division operation
	INLINE l_rvector operator /(const l_rvector &rv, const real &s) noexcept;
	//! Implementation of division operation
	INLINE l_rvector operator /(const l_rvector_slice &sl, const real &s) noexcept;
	//! Implementation of division and allocation operation
	INLINE l_rvector &operator /=(l_rvector &rv,const real &r) noexcept;

	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const rvector &rv, const l_real &s) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const rvector_slice &sl, const l_real &s) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_real &s, const rvector &rv) noexcept;
	//! Implementation of multiplication operation
	INLINE l_rvector operator *(const l_real &s, const rvector_slice &sl) noexcept;

	//! Implementation of division operation
	INLINE l_rvector operator /(const rvector &rv, const l_real &s) noexcept;
	//! Implementation of division operation
	INLINE l_rvector operator /(const rvector_slice &sl, const l_real &s) noexcept;

//======================= Vector / Vector ===============================


	//! Implementation of standard output method
	INLINE std::ostream &operator <<(std::ostream &s, const l_rvector &rv) noexcept;
	//! Implementation of standard output method
	INLINE std::ostream &operator <<(std::ostream &o, const l_rvector_slice &sl) noexcept;
	//! Implementation of standard input method
	INLINE std::istream &operator >>(std::istream &s, l_rvector &rv) noexcept;
	//! Implementation of standard input method
	INLINE std::istream &operator >>(std::istream &s, l_rvector_slice &rv) noexcept;
	
//----------------------- l_real / l_real ---------------------------

	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector_slice & sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rmatrix_subv & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rmatrix_subv & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector_slice & sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector_slice & sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rmatrix_subv & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector_slice & sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rmatrix_subv & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif


	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector_slice &sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector_slice & sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	
	//! Implementation of positive sign operation
	INLINE const l_rvector &operator +(const l_rvector &rv) noexcept;
	//! Implementation of positive sign operation
	INLINE l_rvector operator +(const l_rvector_slice &sl) noexcept;

	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector &rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector_slice &sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector_slice &sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE l_rvector & operator +=(l_rvector &rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE l_rvector &operator +=(l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

	//! Implementation of negative sign operation
	INLINE l_rvector operator -(const l_rvector &rv) noexcept;
	//! Implementation of negative sign operation
	INLINE l_rvector operator -(const l_rvector_slice &sl) noexcept;
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector &rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector_slice &sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector_slice &sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector & operator -=(l_rvector &rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector &operator -=(l_rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

	//! Implementation of standard equality operation
	INLINE bool operator ==(const l_rvector &rv1, const l_rvector &rv2) noexcept;
	//! Implementation of standard equality operation
	INLINE bool operator ==(const l_rvector_slice &sl1, const l_rvector_slice &sl2) noexcept;
	//! Implementation of standard equality operation
	INLINE bool operator ==(const l_rvector_slice &sl, const l_rvector &rv) noexcept;
	//! Implementation of standard equality operation
	INLINE bool operator ==(const l_rvector &rv, const l_rvector_slice &sl) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const l_rvector &rv1, const l_rvector &rv2) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const l_rvector_slice &sl1, const l_rvector_slice &sl2) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const l_rvector_slice &sl, const l_rvector &rv) noexcept;
	//! Implementation of standard negated equality operation
	INLINE bool operator !=(const l_rvector &rv, const l_rvector_slice &sl) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator <(const l_rvector &rv1, const l_rvector &rv2) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator <(const l_rvector_slice &sl1, const l_rvector_slice &sl2) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator < (const l_rvector_slice &sl, const l_rvector &rv) noexcept;
	//! Implementation of standard less-than operation
	INLINE bool operator < (const l_rvector &rv, const l_rvector_slice &sl) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const l_rvector &rv1, const l_rvector &rv2) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const l_rvector_slice &sl1, const l_rvector_slice &sl2) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const l_rvector_slice &sl, const l_rvector &rv) noexcept;
	//! Implementation of standard less-or-equal-than operation
	INLINE bool operator <=(const l_rvector &rv, const l_rvector_slice &sl) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const l_rvector &rv1, const l_rvector &rv2) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const l_rvector_slice &sl1, const l_rvector_slice &sl2) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const l_rvector_slice &sl, const l_rvector &rv) noexcept;
	//! Implementation of standard greater-than operation
	INLINE bool operator >(const l_rvector &rv, const l_rvector_slice &sl) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const l_rvector &rv1, const l_rvector &rv2) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const l_rvector_slice &sl1, const l_rvector_slice &sl2) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const l_rvector_slice &sl, const l_rvector &rv) noexcept;
	//! Implementation of standard greater-or-equal-than operation
	INLINE bool operator >=(const l_rvector &rv, const l_rvector_slice &sl) noexcept;

//-------------------------------- l_real / Real --------------------------------


	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector & rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rvector & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rvector_slice & sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp,const l_rvector_slice &sl,const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rvector & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector & rv1, const rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rvector_slice & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector_slice & rv1, const rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp,const l_rvector &rv,const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rmatrix_subv & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rmatrix_subv & rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rmatrix_subv & rv1, const l_rvector_slice &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rmatrix_subv & rv1, const rvector_slice &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rvector_slice & sl1, const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rvector_slice & sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const rmatrix_subv & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(dotprecision &dp, const l_rmatrix_subv & rv1, const rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif

	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector & rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rvector & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rvector_slice & sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp,const l_rvector_slice &sl,const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rvector & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector & rv1, const rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rvector_slice & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector_slice & rv1, const rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp,const l_rvector &rv,const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rmatrix_subv & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rmatrix_subv & rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rmatrix_subv & rv1, const l_rvector_slice &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rmatrix_subv & rv1, const rvector_slice &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rvector_slice & sl1, const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rvector_slice & sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const rmatrix_subv & rv1, const l_rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif
	//! The accurate scalar product of the last two arguments added to the value of the first argument
	INLINE void accumulate(idotprecision &dp, const l_rmatrix_subv & rv1, const rmatrix_subv &rv2)
#if(CXSC_INDEX_CHECK)
	throw(OP_WITH_WRONG_DIM);
#else
	noexcept;
#endif

	//! Implementation of multiplication operation
	INLINE l_real operator *(const rvector & rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const rvector_slice &sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const rvector_slice & sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector & rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector_slice &sl, const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector &rv, const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of multiplication operation
	INLINE l_real operator *(const l_rvector_slice & sl1, const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	
	//! Implementation of addition operation
	INLINE l_rvector operator +(const rvector &rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const rvector_slice &sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const rvector_slice &sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector &rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector &rv, const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector_slice &sl, const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition operation
	INLINE l_rvector operator +(const l_rvector_slice &sl1, const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

	//! Implementation of addition and allocation operation
	INLINE l_rvector & operator +=(l_rvector &rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of addition and allocation operation
	INLINE l_rvector &operator +=(l_rvector &rv, const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const rvector &rv1, const l_rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const rvector &rv, const l_rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const rvector_slice &sl, const l_rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const rvector_slice &sl1, const l_rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector &rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector &rv, const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector_slice &sl, const rvector &rv)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction operation
	INLINE l_rvector operator -(const l_rvector_slice &sl1, const rvector_slice &sl2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector & operator -=(l_rvector &rv1, const rvector &rv2)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif
	//! Implementation of subtraction and allocation operation
	INLINE l_rvector &operator -=(l_rvector &rv, const rvector_slice &sl)
#if(CXSC_INDEX_CHECK)
	throw(ERROR__OP_WITH_WRONG_DIM<l_rvector>);
#else
	noexcept;
#endif

} // namespace cxsc 

#ifdef _CXSC_INCL_INL
#include "vector.inl"
#include "l_rvector.inl"
#endif
		
#ifdef _CXSC_RMATRIX_HPP_INCLUDED
# ifdef _CXSC_INCL_INL
#  include "lrvecrmat.inl"
# else
#  include "lrvecrmat.hpp"
# endif
#endif

#ifdef _CXSC_IMATRIX_HPP_INCLUDED
# ifdef _CXSC_INCL_INL
#  include "cvecimat.inl"
# else
#  include "cvecimat.hpp"
# endif
#endif

#ifdef _CXSC_IVECTOR_HPP_INCLUDED
# ifdef _CXSC_INCL_INL
#  include "lrvecivec.inl"
# else
#  include "lrvecivec.hpp"
# endif
#endif


#endif

