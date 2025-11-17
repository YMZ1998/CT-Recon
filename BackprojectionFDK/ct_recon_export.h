#pragma once

#ifdef WIN32
#ifdef CT_RECON_CORE_SHARED_LIBS_EXPORT
#define ct_recon_core_export __declspec(dllexport)
#else
#define ct_recon_core_export __declspec(dllimport)
#endif
#endif
