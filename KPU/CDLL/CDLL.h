// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CDLL_EXPORTS
#define CDLL_API __declspec(dllexport)
#else
#define CDLL_API __declspec(dllimport)
#endif

// This class is exported from the CDLL.dll
class CDLL_API CCDLL {
public:
	CCDLL(void);
	// TODO: add your methods here.
};

extern CDLL_API int nCDLL;

CDLL_API int fnCDLL(void);
