#ifndef FEDRawData_FEDHeader_h
#define FEDRawData_FEDHeader_h

/** \class FEDHeader
 *  TEMPORARY helper class to interpret/create FED header words.
 *
 *  $Date: 2005/10/06 18:25:22 $
 *  $Revision: 1.3 $
 *  \author N. Amapane - CERN
 */

#include "interface/shared/fed_header.h"

class FEDHeader {
public:
  /// Constructor
  FEDHeader(const unsigned char* header);

  /// Destructor
  ~FEDHeader();

  /// Event Trigger type identifier
  int triggerType();

  /// Level-1 event number generated by the TTC system
  int lvl1ID();

  /// The bunch crossing number
  int bxID();

  /// Identifier of the FED
  int sourceID();

  /// Version identifier of the FED data format
  int version();

  /// 0 -> the current header word is the last one.
  /// 1-> other header words can follow 
  /// (always 1 for ECAL)
  bool moreHeaders();

  /// Check that the header is OK
  bool check();

  /// Set all fields in the header
  static void set(unsigned char* header,
		  int evt_ty,
		  int lvl1_ID,
		  int bx_ID,  
		  int source_ID,
		  int version=0,
		  bool H=false);

private:
  const fedh_t* theHeader;
};
#endif

