//-------------------------------------------------
//
/** \class L1MuGMTLFPhiProEtaConvLUT
 *
 *   LFPhiProEtaConv look-up table
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
#ifndef L1TriggerGlobalMuonTrigger_L1MuGMTLFPhiProEtaConvLUT_h
#define L1TriggerGlobalMuonTrigger_L1MuGMTLFPhiProEtaConvLUT_h

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
class L1MuTriggerScales;
class L1MuGMTScales;


//              ---------------------
//              -- Class Interface --
//              ---------------------

using namespace std;

class L1MuGMTLFPhiProEtaConvLUT : public L1MuGMTLUT {
  
 public:
  enum {DT, BRPC, CSC, FRPC};

  /// constuctor using function-lookup
  L1MuGMTLFPhiProEtaConvLUT() : L1MuGMTLUT("LFPhiProEtaConv", 
				       "DT BRPC CSC FRPC",
				       "eta_in(6)",
				       "eta_out(4)", 6, true) {
    InitParameters();
  } ;

  /// destructor
  virtual ~L1MuGMTLFPhiProEtaConvLUT() {};

  /// specific lookup function for eta_out
  unsigned SpecificLookup_eta_out (int idx, unsigned eta_in) const {
    vector<unsigned> addr(1);
    addr[0] = eta_in;
    return Lookup(idx, addr) [0];
  };

  /// specific lookup function for entire output field
  unsigned SpecificLookup (int idx, unsigned eta_in) const {
    vector<unsigned> addr(1);
    addr[0] = eta_in;
    return LookupPacked(idx, addr);
  };



  /// access to lookup function with packed input and output

  virtual unsigned LookupFunctionPacked (int idx, unsigned address) const {
    vector<unsigned> addr = u2vec(address, m_Inputs);
    return TheLookupFunction(idx ,addr[0]);

  };

 private:
  /// Initialize scales, configuration parameters, alignment constants, ...
  void InitParameters();

  /// The lookup function - here the functionality of the LUT is implemented
  unsigned TheLookupFunction (int idx, unsigned eta_in) const;

  /// Private data members (LUT parameters);
  L1MuTriggerScales *m_theTriggerScales; // pointer to L1MuTriggerScales Singleton
  L1MuGMTScales *m_theGMTScales; // pointer to L1MuGMTScales Singleton
};
#endif



















