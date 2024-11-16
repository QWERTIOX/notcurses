// Based on tools/builddef.h.in

#if defined(USE_FFMPEG) || defined(USE_OIIO)
#define NOTCURSES_USE_MULTIMEDIA
#endif
// TODO: What is this even doing
#define NOTCURSES_SHARE "@CMAKE_INSTALL_FULL_DATADIR@/notcurses"