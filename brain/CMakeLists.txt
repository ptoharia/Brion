# Copyright (c) 2013-2016, EPFL/Blue Brain Project
#                          Juan Hernando <jhernando@fi.upm.es>
#
# This file is part of Brion <https://github.com/BlueBrain/Brion>
#

set(BRAIN_PUBLIC_HEADERS
  circuit.h
  neuron/morphology.h
  neuron/section.h
  neuron/soma.h
  neuron/types.h
  spikeReportReader.h
  spikeReportWriter.h
  spikes.h
  types.h
  )

set(BRAIN_HEADERS
  detail/spikes.h
  neuron/morphologyImpl.h
  )

set(BRAIN_SOURCES
  circuit.cpp
  neuron/morphology.cpp
  neuron/morphologyImpl.cpp
  neuron/section.cpp
  neuron/soma.cpp
  spikeReportReader.cpp
  spikeReportWriter.cpp
  spikes.cpp
)

set(BRAIN_PUBLIC_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})
set(BRAIN_LINK_LIBRARIES PUBLIC Brion vmmlib)
set(BRAIN_INCLUDE_NAME brain)
set(BRAIN_NAMESPACE brain)

if(TARGET MVDTool)
  list(APPEND BRAIN_LINK_LIBRARIES PRIVATE MVDTool)
endif()
common_library(Brain)
if(TARGET MVDTool)
  target_compile_definitions(Brain PUBLIC BRAIN_USE_MVD3)
endif()

add_subdirectory(python)
