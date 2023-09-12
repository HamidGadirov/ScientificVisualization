/// <copyright file="grid_type.h" company="Visualisierungsinstitut der Universitat Stuttgart">
/// Copyright (c) 2017 Visualisierungsinstitut der Universitat Stuttgart. Alle Rechte vorbehalten.
/// </copyright>
/// <author>Christoph Muller</author>

#pragma once


namespace datraw {

    /// <summary>
    /// Possible grid types supported by the library.
    /// </summary>
    enum class grid_type {
        cartesian = 1,
        rectilinear,
        tetrahedral
    };

}
