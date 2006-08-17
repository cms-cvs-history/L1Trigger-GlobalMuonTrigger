//-------------------------------------------------
//
//   Class: L1MuGMTLFSortRankPtQLUT
//
// 
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

//-----------------------
// This Class's Header --
//-----------------------
#include "L1Trigger/GlobalMuonTrigger/src/L1MuGMTLFSortRankPtQLUT.h"

//---------------
// C++ Headers --
//---------------

#include <iostream>

//-------------------------------
// Collaborating Class Headers --
//-------------------------------
//#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuTriggerScales.h"
//#include "SimG4Core/Notification/interface/Singleton.h"

//-------------------
// InitParameters  --
//-------------------

void L1MuGMTLFSortRankPtQLUT::InitParameters() {
//  m_theTriggerScales = Singleton<L1MuTriggerScales>::instance();
};

//--------------------------------------------------------------------------------
// Sort Rank LUT, Pt-q part
//
// This LUT determines the dependency of the sort rank on Pt and Quality. 
// It gives the main contrubution to the over-all sort rank
//
// Inputs:  Pt(5 bit) and Quality(3 bit)
// Outputs: Rank contribution 7-bit
//
//
//--------------------------------------------------------------------------------

unsigned L1MuGMTLFSortRankPtQLUT::TheLookupFunction (int idx, unsigned q, unsigned pt) const {
  // idx is DT, BRPC, CSC, FRPC
  // INPUTS:  q(3) pt(5)
  // OUTPUTS: rank_ptq(7) 
  int isRPC = idx % 2;
  //  int isFWD = idx / 2;

  unsigned int quality = q;         // DT  has: 1..7
  if ( isRPC ) quality = q*2 + 1;   // RPC has: 0,1,2,3
  if ( idx==2 ) quality = q*3 - 2;  // CSC has: 1,2,3

  if (quality > 7) quality = 7;

  unsigned int rank_ptq = 3*pt + quality*5;

  if (rank_ptq > 127) rank_ptq = 127;
  return rank_ptq;
}; 


















