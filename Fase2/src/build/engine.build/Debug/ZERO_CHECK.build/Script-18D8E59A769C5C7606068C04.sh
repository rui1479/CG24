#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/flaviodrsousa/Desktop/CG24/Fase2/src
  make -f /Users/flaviodrsousa/Desktop/CG24/Fase2/src/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/flaviodrsousa/Desktop/CG24/Fase2/src
  make -f /Users/flaviodrsousa/Desktop/CG24/Fase2/src/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/flaviodrsousa/Desktop/CG24/Fase2/src
  make -f /Users/flaviodrsousa/Desktop/CG24/Fase2/src/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/flaviodrsousa/Desktop/CG24/Fase2/src
  make -f /Users/flaviodrsousa/Desktop/CG24/Fase2/src/CMakeScripts/ReRunCMake.make
fi

