#ifndef INCLUDED_OS
#define INCLUDED_OS

// detect OS via predefined macros. rationale:
// - these macros have consistent names and numerical values; using
//   them saves other code from having to know the obscure predefined macros.
// - we'd like to use #if/#elif/#endif chains for e.g. OS_* to allow warning
//   if none is selected, but there's no good way to #define all inapplicable
//   settings to 0. doing so up front is hard to maintain and would require
//   #undef before setting any one to 1. #ifndef afterwards for each setting
//   is ugly and brittle as well. we therefore use #if/#else/#endif.

// Windows
#if defined(_WIN64)
# define OS_WIN64 1
#else
# define OS_WIN64 0
#endif
#if defined(_WIN32)
# define OS_WIN 1
#else
# define OS_WIN 0
#endif
// Linux
#if defined(linux) || defined(__linux) || defined(__linux__)
# define OS_LINUX 1
#else
# define OS_LINUX 0
#endif
// Android (subset of Linux)
#if defined(__ANDROID__)
# define OS_ANDROID 1
#else
# define OS_ANDROID 0
#endif
// Mac OS X
#if (defined(__APPLE__) && defined(__MACH__))
# define OS_MACOSX 1
#else
# define OS_MACOSX 0
#endif
// BSD
#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD_kernel__)
# define OS_BSD 1
#else
# define OS_BSD 0
#endif
// Solaris
#if defined(sun) || defined(__sun)
# define OS_SOLARIS 1
#else
# define OS_SOLARIS 0
#endif
// BeOS
#if defined(__BEOS__)
# define OS_BEOS 1
#else
# define OS_BEOS 0
#endif
// Mac OS 9 or below
#if defined(macintosh)
# define OS_MAC 1
#else
# define OS_MAC 0
#endif
// Amiga
#if defined(AMIGA)
# define OS_AMIGA 1
#else
# define OS_AMIGA 0
#endif
// Unix-based
#if defined(unix) || defined(__unix) || defined(__unix__) || defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE)
# define OS_UNIX 1
#else
# define OS_UNIX 0
#endif

// convenience: additionally set OS_UNIX for Unix-based OSes
// note: doing this in an separate section instead of adding the extra define
// to all affected OSes saves a few undefs or macro redefinition warnings.
#if OS_LINUX || OS_MACOSX || OS_BSD || OS_SOLARIS
# undef OS_UNIX
# define OS_UNIX 1
#endif

// convenience: additionally set OS_BSD for BSD-based OSes. see note above.
#if OS_MACOSX
# undef OS_BSD
# define OS_BSD 1
#endif

#endif  // #ifndef INCLUDED_OS