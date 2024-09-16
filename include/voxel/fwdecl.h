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

#ifndef VOXEL_GAME_FWDECL_H
#define VOXEL_GAME_FWDECL_H

#include <blt/std/types.h>
#include <cmath>

namespace voxel
{
    
    inline constexpr blt::u64 CHUNK_SIZE = 32;
    inline constexpr blt::i32 IMAGE_SIZE = 64;
    inline const blt::u64 CHUNK_MASK = static_cast<blt::u64>(std::log2(CHUNK_SIZE));
    
    using block_id_t = blt::u64;
    using texture_id_t = blt::u64;
    using vid_t = blt::u16;
    
    class block_t;
    class chunk_t;
    
}

#endif //VOXEL_GAME_FWDECL_H
