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

#ifndef VOXEL_GAME_BLOCK_H
#define VOXEL_GAME_BLOCK_H

#include <voxel/fwdecl.h>
#include <array>
#include <variant>

namespace voxel
{
    enum class face_t : blt::u32
    {
        NORTH, SOUTH, EAST, WEST, UP, DOWN, COUNT
    };
    
    constexpr inline blt::u32 face_to_int(face_t face)
    {
        return static_cast<blt::u32>(face);
    }
    
    class textured_block_t
    {
        public:
            explicit textured_block_t(texture_id_t id)
            {
                for (auto& f : faces)
                    f = id;
            }
            
            explicit textured_block_t(texture_id_t top, texture_id_t id)
            {
                for (auto& f : faces)
                    f = id;
                faces[face_to_int(face_t::UP)] = top;
            }
            
            explicit textured_block_t(texture_id_t top, texture_id_t bottom, texture_id_t sides)
            {
                for (auto& f : faces)
                    f = sides;
                faces[face_to_int(face_t::UP)] = top;
                faces[face_to_int(face_t::DOWN)] = bottom;
            }
            
            explicit textured_block_t(std::array<texture_id_t, face_to_int(face_t::COUNT)> faces): faces(faces)
            {}
            
            texture_id_t get_texture_facing(face_t face)
            {
                return faces[face_to_int(face)];
            }
        
        private:
            std::array<texture_id_t, face_to_int(face_t::COUNT)> faces{};
    };
    
    class block_model_t
    {
        public:
        
        private:
        
    };
    
    /**
     * Defines data about a block
     */
    class block_t
    {
        public:
        private:
            block_id_t id;
            std::variant<block_model_t, textured_block_t> model;
    };
}

#endif //VOXEL_GAME_BLOCK_H
