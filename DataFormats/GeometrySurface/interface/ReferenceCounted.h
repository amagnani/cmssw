#ifndef SURFACE_REFERENCECOUNTED_H
#define SURFACE_REFERENCECOUNTED_H
// -*- C++ -*-
//
// Package:     Surface
// Class  :     ReferenceCounted
// 
/**\class ReferenceCounted ReferenceCounted.h DataFormats/GeometrySurface/interface/ReferenceCounted.h

 Description: <one line class summary>

 Usage:
    <usage>

*/
//
// Original Author:  Chris Jones
//         Created:  Fri Jul 15 09:17:20 EDT 2005
// $Id: ReferenceCounted.h,v 1.3 2008/10/21 13:37:10 innocent Exp $
//

// system include files
#include "boost/intrusive_ptr.hpp"

// user include files

// forward declarations

class ReferenceCounted
{

   public:
      ReferenceCounted() : referenceCount_(0) {}
      ReferenceCounted( const ReferenceCounted& iRHS ) : referenceCount_(0) {}

      const ReferenceCounted& operator=( const ReferenceCounted& ) {
	return *this;
      }
      virtual ~ReferenceCounted() {}

      // ---------- const member functions ---------------------

      void addReference() const { ++referenceCount_ ; }
      void removeReference() const { if( 0 == --referenceCount_ ) {
	  delete const_cast<ReferenceCounted*>(this);
	}
      }

      unsigned int  references() const {return referenceCount_;}

      // ---------- static member functions --------------------

      // ---------- member functions ---------------------------

   private:

      // ---------- member data --------------------------------
      mutable unsigned int referenceCount_;
};

template <class T> class ReferenceCountingPointer : 
  public boost::intrusive_ptr<T> 
{
 public:
  ReferenceCountingPointer(T* iT) : boost::intrusive_ptr<T>(iT) {}
  ReferenceCountingPointer() {}
};

template <class T> class ConstReferenceCountingPointer : 
  public boost::intrusive_ptr<const T> 
{
 public:
  ConstReferenceCountingPointer(const T* iT) : boost::intrusive_ptr<const T>(iT) {}
  ConstReferenceCountingPointer() {}
  ConstReferenceCountingPointer( const ReferenceCountingPointer<T>& other) :
    boost::intrusive_ptr<const T>(&(*other)) {}
};

inline void intrusive_ptr_add_ref( const ReferenceCounted* iRef ) {
  iRef->addReference();
}

inline void intrusive_ptr_release( const ReferenceCounted* iRef ) {
  iRef->removeReference();
}


// #define CMSSW_POOLALLOCATOR

#ifdef CMSSW_POOLALLOCATOR

#include "DataFormats/GeometrySurface/interface/BlockWipedAllocator.h"

class ReferenceCountedPoolAllocated :
 public BlockWipedPoolAllocated
{
      
   public:
      ReferenceCountedPoolAllocated() : referenceCount_(0) {}
      ReferenceCountedPoolAllocated( const ReferenceCountedPoolAllocated& iRHS ) : referenceCount_(0) {}
  
      const ReferenceCountedPoolAllocated& operator=( const ReferenceCountedPoolAllocated& ) {
        return *this;
      }
      virtual ~ReferenceCountedPoolAllocated() {}
  
      // ---------- const member functions ---------------------

      void addReference() const { ++referenceCount_ ; }
      void removeReference() const { if( 0 == --referenceCount_ ) {
          delete const_cast<ReferenceCountedPoolAllocated*>(this);
        }
      }
  
      unsigned int  references() const {return referenceCount_;}
  
      // ---------- static member functions --------------------

      // ---------- member functions ---------------------------
 
   private:

      // ---------- member data --------------------------------
      mutable unsigned int referenceCount_;
};

inline void intrusive_ptr_add_ref( const ReferenceCountedPoolAllocated* iRef ) {
  iRef->addReference();
}

inline void intrusive_ptr_release( const ReferenceCountedPoolAllocated* iRef ) {
  iRef->removeReference();
} 

#else
typedef ReferenceCounted  ReferenceCountedPoolAllocated;
#endif


#endif /* SURFACE_REFERENCECOUNTED_H */
