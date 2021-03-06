# Copyright (c) 2015-2016, EPFL/Blue Brain Project
#                          Stefan.Eilemann@epfl.ch
#
# This file is part of Brion <https://github.com/BlueBrain/Brion>
#

set(SPIKECONVERTER_HEADERS)
set(SPIKECONVERTER_SOURCES spikeConverter.cpp)
set(SPIKECONVERTER_LINK_LIBRARIES Brion)

common_application(spikeConverter)

set(MORPHOLOGYCONVERTER_HEADERS)
set(MORPHOLOGYCONVERTER_SOURCES morphologyConverter.cpp)
set(MORPHOLOGYCONVERTER_LINK_LIBRARIES Brion ${Boost_PROGRAM_OPTIONS_LIBRARY})

common_application(morphologyConverter)

if (MSVC)
  target_compile_definitions(morphologyConverter PRIVATE
    BOOST_PROGRAM_OPTIONS_DYN_LINK)
endif()

set(COMPARTMENTCONVERTER_HEADERS)
set(COMPARTMENTCONVERTER_SOURCES compartmentConverter.cpp)
set(COMPARTMENTCONVERTER_LINK_LIBRARIES Brion ${Boost_PROGRAM_OPTIONS_LIBRARY})
if(TARGET BBPTestData)
  list(APPEND COMPARTMENTCONVERTER_LINK_LIBRARIES BBPTestData)
endif()

common_application(compartmentConverter)

if (MSVC)
  target_compile_definitions(compartmentConverter PRIVATE
    BOOST_PROGRAM_OPTIONS_DYN_LINK)
endif()
