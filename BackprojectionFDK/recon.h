/**
*  Copyright ?[2011], Empa, Juergen Hofmann
*/

/**********************************************************
*
* $Log: recon.h $
* Revision 1.2  2010/12/21 06:47:32  Hofmann
* remove not used keywords
*
* Revision 1.1  2010/12/15 09:52:49  Hofmann
* Initial revision
*
* Revision 1.1  2010/10/19 13:16:00  Hofmann
* Initial revision
*
*
**********************************************************/
#ifndef _RECON_H
#define _RECON_H

#include "cuda.h"
#include "typesFDK.h"
//#include "cutil_inline.h"
#include <cuda_runtime_api.h>
#include <vector>

#include "ct_recon_export.h"

#define _ASYNC_IO

ct_recon_core_export int runFDK(BackProjParam param, int devNo, float* minGray,
                                float* maxGray, FILE* fpVol);

ct_recon_core_export void GetGraphicCardProp(
    std::vector<GraphicCardProp>& gpuPropV);

ct_recon_core_export void HandleError(cudaError_t err, const char* file,
                                      int line);

#define HANDLE_ERROR(err) (HandleError(err, __FILE__, __LINE__))

#endif  // _RECON_H