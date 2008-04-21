
//-------------------------------------------------
//
//   \class L1MuGMTTree
/**
 *   Description:  Build GMT Tree
*/
//                
//   $Date: 2007/03/21 00:23:36 $
//   $Revision: 1.5 $
//
//   I. Mikulec            HEPHY Vienna
//
//--------------------------------------------------
#ifndef L1MU_GMT_DUMP_H
#define L1MU_GMT_DUMP_H

//---------------
// C++ Headers --
//---------------

#include <memory>
#include <string>

//----------------------
// Base Class Headers --
//----------------------
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"


//------------------------------------
// Collaborating Class Declarations --
//------------------------------------

#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuRegionalCand.h"
#include "DataFormats/L1GlobalMuonTrigger/interface/L1MuGMTReadoutCollection.h"
#include "FWCore/ParameterSet/interface/InputTag.h"

class TFile;
class TTree;

//              ---------------------
//              -- Class Interface --
//              ---------------------

    const int MAXGEN = 20;
    const int MAXRPC = 20;
    const int MAXDTBX = 20;
    const int MAXCSC = 20;    
    const int MAXGMT = 20;
 

class L1MuGMTTree : public edm::EDAnalyzer {

 
  public:

    // constructor
    explicit L1MuGMTTree(const edm::ParameterSet&);
    virtual ~L1MuGMTTree();

    // fill tree
    virtual void analyze(const edm::Event&, const edm::EventSetup&);
    void book();

    virtual void beginJob(const edm::EventSetup&);
    virtual void endJob();

  private:

    //GENERAL block
    int             runn;
    int             eventn;
    float           weight;
    float           pthat;
 
    //generator block
    int             ngen;
    float           pxgen[MAXGEN];
    float           pygen[MAXGEN];
    float           pzgen[MAXGEN];
    float           ptgen[MAXGEN];
    float           etagen[MAXGEN];
    float           phigen[MAXGEN];
    int             chagen[MAXGEN];
    float           vxgen[MAXGEN];
    float           vygen[MAXGEN];
    float           vzgen[MAXGEN];
    int             pargen[MAXGEN];
    
    //DTBX Trigger block
    int             ndt;
    int             bxd[MAXDTBX];
    float           ptd[MAXDTBX];
    int             chad[MAXDTBX];
    float           etad[MAXDTBX];
    int             etafined[MAXDTBX];
    float           phid[MAXDTBX];
    int             quald[MAXDTBX];
    int             tclassd[MAXDTBX];
    int             ntsd[MAXDTBX];

    //CSC Trigger block
    int             ncsc;
    int             bxc[MAXCSC];
    float           ptc[MAXCSC];
    int             chac[MAXCSC];
    float           etac[MAXCSC];
    float           phic[MAXCSC];
    int             qualc[MAXCSC];
    int             ntsc[MAXCSC];
    int             rankc[MAXCSC];

    //RPCb Trigger
    int             nrpcb ;
    int             bxrb[MAXRPC];
    float           ptrb[MAXRPC];
    int             charb[MAXRPC];
    float           etarb[MAXRPC];
    float           phirb[MAXRPC];
    int             qualrb[MAXRPC];

    //RPCf Trigger
    int             nrpcf ;
    int             bxrf[MAXRPC];
    float           ptrf[MAXRPC];
    int             charf[MAXRPC];
    float           etarf[MAXRPC];
    float           phirf[MAXRPC];
    int             qualrf[MAXRPC];

    //Global Muon Trigger
    int             ngmt;
    int             bxg[MAXGMT];
    float           ptg[MAXGMT];
    int             chag[MAXGMT];
    float           etag[MAXGMT];
    float           phig[MAXGMT];
    int             qualg[MAXGMT];
    int             detg[MAXGMT];
    int             rankg[MAXGMT];
    int             isolg[MAXGMT];
    int             mipg[MAXGMT];
    int             datawordg[MAXGMT];
    int             idxRPCb[MAXGMT];
    int             idxRPCf[MAXGMT];
    int             idxDTBX[MAXGMT];
    int             idxCSC[MAXGMT];

    TFile* m_file;
    TTree* m_tree;

    edm::InputTag m_inputTag;
    std::string m_outfilename;
      
};


#endif