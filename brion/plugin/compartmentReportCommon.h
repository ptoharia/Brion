/* Copyright (c) 2013-2015, EPFL/Blue Brain Project
 *                          Daniel Nachbaur <daniel.nachbaur@epfl.ch>
 *
 * This file is part of Brion <https://github.com/BlueBrain/Brion>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BRION_PLUGIN_COMPARTMENTREPORTCOMMON
#define BRION_PLUGIN_COMPARTMENTREPORTCOMMON

#include "../pluginInitData.h"
#include "../types.h"
#include "../compartmentReportPlugin.h"

namespace brion
{
namespace plugin
{

class CompartmentReportCommon : public CompartmentReportPlugin
{
public:
    CompartmentReportCommon();
    ~CompartmentReportCommon() {}

    size_t getNumCompartments( size_t index ) const final;

protected:

    void _cacheNeuronCompartmentCounts( const GIDSet& gids );
    size_t _getFrameNumber( float timestamp ) const;

private:

    size_ts _neuronCompartments;
};

}
}

#endif
