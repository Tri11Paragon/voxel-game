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
#include <blt/gfx/window.h>
#include "blt/gfx/renderer/resource_manager.h"
#include "blt/gfx/renderer/batch_2d_renderer.h"
#include "blt/gfx/renderer/camera.h"
#include <imgui.h>
#include <voxel/chunk.h>
#include <thread>

blt::gfx::matrix_state_manager global_matrices;
blt::gfx::resource_manager resources {VOXEL_RES_DIR};
blt::gfx::batch_renderer_2d renderer_2d(resources, global_matrices);
blt::gfx::first_person_camera camera;

void init(const blt::gfx::window_data&)
{
    using namespace blt::gfx;
    
    texture_array block_array{"blocks", voxel::IMAGE_SIZE, voxel::IMAGE_SIZE};
    block_array.add_texture("ham.png", "ham");
    
    resources.with(texture_info{"ham.png", "ham"}.set_desired_width(voxel::IMAGE_SIZE).set_desired_height(voxel::IMAGE_SIZE));
    resources.with(std::move(block_array));
    
    global_matrices.create_internals();
    resources.load_resources(std::thread::hardware_concurrency());
    renderer_2d.create();
}

void update(const blt::gfx::window_data& data)
{
    global_matrices.update_perspectives(data.width, data.height, 90, 0.1, 2000);
    
    camera.update();
    camera.update_view(global_matrices);
    global_matrices.update();
    
    renderer_2d.drawRectangleInternal("ham", {50, 50, voxel::IMAGE_SIZE, voxel::IMAGE_SIZE});
    
    renderer_2d.render(data.width, data.height);
}

int main(int, const char**)
{
    blt::gfx::init(blt::gfx::window_data{"My Sexy Window", init, update}.setSyncInterval(1));
    global_matrices.cleanup();
    resources.cleanup();
    renderer_2d.cleanup();
    blt::gfx::cleanup();
}