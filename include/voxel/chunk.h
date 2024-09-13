#pragma once
/*
 *  Copyright (C) 2024  Brett Terpstra
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef VOXEL_GAME_CHUNK_H
#define VOXEL_GAME_CHUNK_H

#include <array>
#include <voxel/fwdecl.h>
#include <blt/std/hashmap.h>

namespace voxel
{
    enum class chunk_generation_state_t
    {
        empty,                  // no data exists in chunk
        empty_structure,        // chunk was created for the purpose of storing a structure
        biomes,                 // chunk generated biomes
        noise,                  // chunk generated noise map
        surface,                // chunk generated surface details
        carvers,                // rivers
        features,               // structure generation
        full
    };
    
    class chunk_t
    {
        public:
        private:
            chunk_generation_state_t state;
            std::array<vid_t, CHUNK_SIZE * CHUNK_SIZE * CHUNK_SIZE> blocks;
    };
}

#endif //VOXEL_GAME_CHUNK_H
