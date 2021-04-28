/*
** Copyright (c) 2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "decode/dx12_object_mapping_util.h"

#include "decode/dx12_object_info.h"
#include "decode/custom_dx12_struct_decoders.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(object_mapping)

void MapGpuVirtualAddress(D3D12_GPU_VIRTUAL_ADDRESS& address, const util::GpuVaMap& gpu_va_map)
{
    address = gpu_va_map.GetReplayGpuVa(address);
}

void MapGpuVirtualAddresses(D3D12_GPU_VIRTUAL_ADDRESS* addresses,
                            size_t                     addresses_len,
                            const util::GpuVaMap&      gpu_va_map)
{
    for (size_t i = 0; i < addresses_len; ++i)
    {
        MapGpuVirtualAddress(addresses[i], gpu_va_map);
    }
}

GFXRECON_END_NAMESPACE(object_mapping)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
