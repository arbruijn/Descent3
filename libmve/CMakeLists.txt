set(HEADERS
  console.h
  decoders.h
  libmve.h
  mve_audio.h
  mvelib.h)

#  mvegfx.h
#  mvelibi.h
#  mvelibl.h
#  platform.h
#  snd8to16.h
#  SystemInterfaces.h)

set(CPPS
  decoder16.cpp
  decoder8.cpp
  mve_audio.cpp
  mvelib.cpp
  mveplay.cpp)

set(PLATFORM_CPPS)

if(UNIX)
  set(PLATFORM_CPPS "lnxdsound.cpp")
endif()

add_library(libmve STATIC ${HEADERS} ${CPPS} ${PLATFORM_CPPS})

