#ifdef DLLEXPORT
#define  DLLIO __declspec(dllexport)
#else
#define DLLIO __declspec(dllimport)
#endif