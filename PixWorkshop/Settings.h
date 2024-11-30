#ifdef DLLEXPORT
#define  DLLIO __declspec(dllexport)
#else
#define DLLIO __declspec(dllimport)
#endif

#ifdef SDL2_FOUND
  #define SDL2
#elif OPENGL_FOUND
  #ifdef GLFW3_FOUND
    #define GLFW3
  #elif GLEW_FOUND
    #define GLEW
  #endif
#endif