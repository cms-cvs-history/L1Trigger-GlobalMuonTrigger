//-------------------------------------------------
//
/** \class L1MuGMTLFSortRankCombineLUT
 *
 *   LFSortRankCombine look-up table
 *          
 *   this class was automatically generated by 
 *     L1MuGMTLUT::MakeSubClass()  
*/ 
//   $Date: 2004/02/03 16:33:44 $
//   $Revision: 1.2 $
//
//   Author :
//   H. Sakulin            HEPHY Vienna
//
//   Migrated to CMSSW:
//   I. Mikulec
//
//--------------------------------------------------
#ifndef L1TriggerGlobalMuonTrigger_L1MuGMTLFSortRankCombineLUT_h
#define L1TriggerGlobalMuonTrigger_L1MuGMTLFSortRankCombineLUT_h

//---------------
// C++ Headers --
//---------------


//----------------------
// Base Class Headers --
//----------------------
#include "L1Trigger/GlobalMuonTrigger/src/L1MuGMTLUT.h"

//------------------------------------
// Collaborating Class Declarations --
//------------------------------------
//class L1MuTriggerScales;


//              ---------------------
//              -- Class Interface --
//              ---------------------

using namespace std;

class L1MuGMTLFSortRankCombineLUT : public L1MuGMTLUT {
  
 public:
  enum {DT, BRPC, CSC, FRPC};

  /// constuctor using function-lookup
  L1MuGMTLFSortRankCombineLUT() : L1MuGMTLUT("LFSortRankCombine", 
				       "DT BRPC CSC FRPC",
				       "rank_etaq(2) rank_ptq(7) rank_etaphi(2)",
				       "sort_rank(8)", 10, false) {
    InitParameters();
  } ;

  /// destructor
  virtual ~L1MuGMTLFSortRankCombineLUT() {};

  /// specific lookup function for sort_rank
  unsigned SpecificLookup_sort_rank (int idx, unsigned rank_etaq, unsigned rank_ptq, unsigned rank_etaphi) const {
    vector<unsigned> addr(3);
    addr[0] = rank_etaq;
    addr[1] = rank_ptq;
    addr[2] = rank_etaphi;
    return Lookup(idx, addr) [0];
  };

  /// specific lookup function for entire output field
  unsigned SpecificLookup (int idx, unsigned rank_etaq, unsigned rank_ptq, unsigned rank_etaphi) const {
    vector<unsigned> addr(3);
    addr[0] = rank_etaq;
    addr[1] = rank_ptq;
    addr[2] = rank_etaphi;
    return LookupPacked(idx, addr);
  };



  /// access to lookup function with packed input and output

  virtual unsigned LookupFunctionPacked (int idx, unsigned address) const {
    vector<unsigned> addr = u2vec(address, m_Inputs);
    return TheLookupFunction(idx ,addr[0] ,addr[1] ,addr[2]);

  };

 private:
  /// Initialize scales, configuration parameters, alignment constants, ...
  void InitParameters();

  /// The lookup function - here the functionality of the LUT is implemented
  unsigned TheLookupFunction (int idx, unsigned rank_etaq, unsigned rank_ptq, unsigned rank_etaphi) const;

  /// Private data members (LUT parameters);
//  L1MuTriggerScales *m_theTriggerScales; // pointer to L1MuTriggerScales Singleton
};
#endif



















