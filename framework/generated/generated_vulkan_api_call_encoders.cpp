/*
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include <mutex>

#include "vulkan/vulkan.h"

#include "util/defines.h"
#include "format/api_call_id.h"
#include "encode/custom_encoder_commands.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "encode/parameter_encoder.h"
#include "layer/trace_layer.h"

#include "generated/generated_vulkan_api_call_encoders.h"

BRIMSTONE_BEGIN_NAMESPACE(brimstone)

VKAPI_ATTR VkResult VKAPI_CALL CreateInstance(
    const VkInstanceCreateInfo*                 pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkInstance*                                 pInstance)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateInstance>::Dispatch(encode::TraceManager::Get(), pCreateInfo, pAllocator, pInstance);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = dispatch_CreateInstance(pCreateInfo, pAllocator, pInstance);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateInstance);
        if (encoder)
        {
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pInstance);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateInstance>::Dispatch(encode::TraceManager::Get(), result, pCreateInfo, pAllocator, pInstance);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyInstance(
    VkInstance                                  instance,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyInstance>::Dispatch(encode::TraceManager::Get(), instance, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_instance_table(instance)->DestroyInstance(instance, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyInstance);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyInstance>::Dispatch(encode::TraceManager::Get(), instance, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDevices(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceCount,
    VkPhysicalDevice*                           pPhysicalDevices)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkEnumeratePhysicalDevices>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceCount, pPhysicalDevices);

    VkResult result = get_instance_table(instance)->EnumeratePhysicalDevices(instance, pPhysicalDeviceCount, pPhysicalDevices);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkEnumeratePhysicalDevices);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceCount);
        encoder->EncodeHandleIdArray(pPhysicalDevices, (pPhysicalDeviceCount != nullptr) ? (*pPhysicalDeviceCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkEnumeratePhysicalDevices>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceCount, pPhysicalDevices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures*                   pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceFeatures>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures(physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFeatures);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceFeatures>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties*                         pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties(physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkImageFormatProperties*                    pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties(physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encode_struct_ptr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties*                 pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties(physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties*                    pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties*           pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceMemoryProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties(physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMemoryProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceMemoryProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDevice(
    VkPhysicalDevice                            physicalDevice,
    const VkDeviceCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDevice*                                   pDevice)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDevice>::Dispatch(encode::TraceManager::Get(), physicalDevice, pCreateInfo, pAllocator, pDevice);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = dispatch_CreateDevice(physicalDevice, pCreateInfo, pAllocator, pDevice);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDevice);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(physicalDevice);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pDevice);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDevice>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pCreateInfo, pAllocator, pDevice);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDevice(
    VkDevice                                    device,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDevice>::Dispatch(encode::TraceManager::Get(), device, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyDevice(device, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDevice);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDevice>::Dispatch(encode::TraceManager::Get(), device, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue(
    VkDevice                                    device,
    uint32_t                                    queueFamilyIndex,
    uint32_t                                    queueIndex,
    VkQueue*                                    pQueue)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceQueue>::Dispatch(encode::TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);

    get_device_table(device)->GetDeviceQueue(device, queueFamilyIndex, queueIndex, pQueue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceQueue);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeUInt32Value(queueIndex);
        encoder->EncodeHandleIdPtr(pQueue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceQueue>::Dispatch(encode::TraceManager::Get(), device, queueFamilyIndex, queueIndex, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueSubmit(
    VkQueue                                     queue,
    uint32_t                                    submitCount,
    const VkSubmitInfo*                         pSubmits,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueueSubmit>::Dispatch(encode::TraceManager::Get(), queue, submitCount, pSubmits, fence);

    VkResult result = get_device_table(queue)->QueueSubmit(queue, submitCount, pSubmits, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueueSubmit);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(submitCount);
        encode_struct_array(encoder, pSubmits, submitCount);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueueSubmit>::Dispatch(encode::TraceManager::Get(), result, queue, submitCount, pSubmits, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueueWaitIdle(
    VkQueue                                     queue)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueueWaitIdle>::Dispatch(encode::TraceManager::Get(), queue);

    VkResult result = get_device_table(queue)->QueueWaitIdle(queue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueueWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueueWaitIdle>::Dispatch(encode::TraceManager::Get(), result, queue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DeviceWaitIdle(
    VkDevice                                    device)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDeviceWaitIdle>::Dispatch(encode::TraceManager::Get(), device);

    VkResult result = get_device_table(device)->DeviceWaitIdle(device);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDeviceWaitIdle);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDeviceWaitIdle>::Dispatch(encode::TraceManager::Get(), result, device);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateMemory(
    VkDevice                                    device,
    const VkMemoryAllocateInfo*                 pAllocateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDeviceMemory*                             pMemory)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkAllocateMemory>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pAllocator, pMemory);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->AllocateMemory(device, pAllocateInfo, pAllocator, pMemory);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkAllocateMemory);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pMemory);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkAllocateMemory>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pAllocator, pMemory);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkFreeMemory>::Dispatch(encode::TraceManager::Get(), device, memory, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->FreeMemory(device, memory, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkFreeMemory);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(memory);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkFreeMemory>::Dispatch(encode::TraceManager::Get(), device, memory, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize                                offset,
    VkDeviceSize                                size,
    VkMemoryMapFlags                            flags,
    void**                                      ppData)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkMapMemory>::Dispatch(encode::TraceManager::Get(), device, memory, offset, size, flags, ppData);

    VkResult result = get_device_table(device)->MapMemory(device, memory, offset, size, flags, ppData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkMapMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeVoidPtrPtr(ppData);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkMapMemory>::Dispatch(encode::TraceManager::Get(), result, device, memory, offset, size, flags, ppData);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UnmapMemory(
    VkDevice                                    device,
    VkDeviceMemory                              memory)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkUnmapMemory>::Dispatch(encode::TraceManager::Get(), device, memory);

    get_device_table(device)->UnmapMemory(device, memory);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkUnmapMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkUnmapMemory>::Dispatch(encode::TraceManager::Get(), device, memory);
}

VKAPI_ATTR VkResult VKAPI_CALL FlushMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkFlushMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    VkResult result = get_device_table(device)->FlushMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkFlushMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        encode_struct_array(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkFlushMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL InvalidateMappedMemoryRanges(
    VkDevice                                    device,
    uint32_t                                    memoryRangeCount,
    const VkMappedMemoryRange*                  pMemoryRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkInvalidateMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), device, memoryRangeCount, pMemoryRanges);

    VkResult result = get_device_table(device)->InvalidateMappedMemoryRanges(device, memoryRangeCount, pMemoryRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkInvalidateMappedMemoryRanges);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(memoryRangeCount);
        encode_struct_array(encoder, pMemoryRanges, memoryRangeCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkInvalidateMappedMemoryRanges>::Dispatch(encode::TraceManager::Get(), result, device, memoryRangeCount, pMemoryRanges);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceMemoryCommitment(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkDeviceSize*                               pCommittedMemoryInBytes)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceMemoryCommitment>::Dispatch(encode::TraceManager::Get(), device, memory, pCommittedMemoryInBytes);

    get_device_table(device)->GetDeviceMemoryCommitment(device, memory, pCommittedMemoryInBytes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceMemoryCommitment);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizePtr(pCommittedMemoryInBytes);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceMemoryCommitment>::Dispatch(encode::TraceManager::Get(), device, memory, pCommittedMemoryInBytes);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBindBufferMemory>::Dispatch(encode::TraceManager::Get(), device, buffer, memory, memoryOffset);

    VkResult result = get_device_table(device)->BindBufferMemory(device, buffer, memory, memoryOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBindBufferMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBindBufferMemory>::Dispatch(encode::TraceManager::Get(), result, device, buffer, memory, memoryOffset);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory(
    VkDevice                                    device,
    VkImage                                     image,
    VkDeviceMemory                              memory,
    VkDeviceSize                                memoryOffset)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBindImageMemory>::Dispatch(encode::TraceManager::Get(), device, image, memory, memoryOffset);

    VkResult result = get_device_table(device)->BindImageMemory(device, image, memory, memoryOffset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBindImageMemory);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeVkDeviceSizeValue(memoryOffset);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBindImageMemory>::Dispatch(encode::TraceManager::Get(), result, device, image, memory, memoryOffset);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetBufferMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, buffer, pMemoryRequirements);

    get_device_table(device)->GetBufferMemoryRequirements(device, buffer, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetBufferMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(buffer);
        encode_struct_ptr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetBufferMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, buffer, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    VkMemoryRequirements*                       pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pMemoryRequirements);

    get_device_table(device)->GetImageMemoryRequirements(device, image, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encode_struct_ptr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements(
    VkDevice                                    device,
    VkImage                                     image,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements*            pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageSparseMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    get_device_table(device)->GetImageSparseMemoryRequirements(device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageSparseMemoryRequirements);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageSparseMemoryRequirements>::Dispatch(encode::TraceManager::Get(), device, image, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkSampleCountFlagBits                       samples,
    VkImageUsageFlags                           usage,
    VkImageTiling                               tiling,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties*              pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties(physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(samples);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, samples, usage, tiling, pPropertyCount, pProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL QueueBindSparse(
    VkQueue                                     queue,
    uint32_t                                    bindInfoCount,
    const VkBindSparseInfo*                     pBindInfo,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueueBindSparse>::Dispatch(encode::TraceManager::Get(), queue, bindInfoCount, pBindInfo, fence);

    VkResult result = get_device_table(queue)->QueueBindSparse(queue, bindInfoCount, pBindInfo, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueueBindSparse);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfo, bindInfoCount);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueueBindSparse>::Dispatch(encode::TraceManager::Get(), result, queue, bindInfoCount, pBindInfo, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFence(
    VkDevice                                    device,
    const VkFenceCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateFence>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pFence);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateFence(device, pCreateInfo, pAllocator, pFence);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateFence);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pFence);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateFence>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFence(
    VkDevice                                    device,
    VkFence                                     fence,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyFence>::Dispatch(encode::TraceManager::Get(), device, fence, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyFence(device, fence, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyFence);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(fence);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyFence>::Dispatch(encode::TraceManager::Get(), device, fence, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkResetFences>::Dispatch(encode::TraceManager::Get(), device, fenceCount, pFences);

    VkResult result = get_device_table(device)->ResetFences(device, fenceCount, pFences);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkResetFences);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkResetFences>::Dispatch(encode::TraceManager::Get(), result, device, fenceCount, pFences);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceStatus(
    VkDevice                                    device,
    VkFence                                     fence)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetFenceStatus>::Dispatch(encode::TraceManager::Get(), device, fence);

    VkResult result = get_device_table(device)->GetFenceStatus(device, fence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetFenceStatus);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetFenceStatus>::Dispatch(encode::TraceManager::Get(), result, device, fence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL WaitForFences(
    VkDevice                                    device,
    uint32_t                                    fenceCount,
    const VkFence*                              pFences,
    VkBool32                                    waitAll,
    uint64_t                                    timeout)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkWaitForFences>::Dispatch(encode::TraceManager::Get(), device, fenceCount, pFences, waitAll, timeout);

    VkResult result = get_device_table(device)->WaitForFences(device, fenceCount, pFences, waitAll, timeout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkWaitForFences);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(fenceCount);
        encoder->EncodeHandleIdArray(pFences, fenceCount);
        encoder->EncodeVkBool32Value(waitAll);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkWaitForFences>::Dispatch(encode::TraceManager::Get(), result, device, fenceCount, pFences, waitAll, timeout);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSemaphore(
    VkDevice                                    device,
    const VkSemaphoreCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSemaphore*                                pSemaphore)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateSemaphore>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSemaphore);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateSemaphore(device, pCreateInfo, pAllocator, pSemaphore);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateSemaphore);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSemaphore);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateSemaphore>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSemaphore);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySemaphore(
    VkDevice                                    device,
    VkSemaphore                                 semaphore,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroySemaphore>::Dispatch(encode::TraceManager::Get(), device, semaphore, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroySemaphore(device, semaphore, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroySemaphore);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(semaphore);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroySemaphore>::Dispatch(encode::TraceManager::Get(), device, semaphore, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateEvent(
    VkDevice                                    device,
    const VkEventCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkEvent*                                    pEvent)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateEvent>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pEvent);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateEvent(device, pCreateInfo, pAllocator, pEvent);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateEvent);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pEvent);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateEvent>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pEvent);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyEvent(
    VkDevice                                    device,
    VkEvent                                     event,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyEvent>::Dispatch(encode::TraceManager::Get(), device, event, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyEvent(device, event, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyEvent);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(event);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyEvent>::Dispatch(encode::TraceManager::Get(), device, event, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetEventStatus(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetEventStatus>::Dispatch(encode::TraceManager::Get(), device, event);

    VkResult result = get_device_table(device)->GetEventStatus(device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetEventStatus);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetEventStatus>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkSetEvent>::Dispatch(encode::TraceManager::Get(), device, event);

    VkResult result = get_device_table(device)->SetEvent(device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkSetEvent>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetEvent(
    VkDevice                                    device,
    VkEvent                                     event)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkResetEvent>::Dispatch(encode::TraceManager::Get(), device, event);

    VkResult result = get_device_table(device)->ResetEvent(device, event);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkResetEvent>::Dispatch(encode::TraceManager::Get(), result, device, event);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateQueryPool(
    VkDevice                                    device,
    const VkQueryPoolCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkQueryPool*                                pQueryPool)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateQueryPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pQueryPool);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateQueryPool(device, pCreateInfo, pAllocator, pQueryPool);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateQueryPool);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pQueryPool);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateQueryPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pQueryPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyQueryPool(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyQueryPool>::Dispatch(encode::TraceManager::Get(), device, queryPool, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyQueryPool(device, queryPool, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyQueryPool);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(queryPool);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyQueryPool>::Dispatch(encode::TraceManager::Get(), device, queryPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetQueryPoolResults(
    VkDevice                                    device,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    size_t                                      dataSize,
    void*                                       pData,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetQueryPoolResults>::Dispatch(encode::TraceManager::Get(), device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    VkResult result = get_device_table(device)->GetQueryPoolResults(device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeSizeTValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetQueryPoolResults>::Dispatch(encode::TraceManager::Get(), result, device, queryPool, firstQuery, queryCount, dataSize, pData, stride, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBuffer(
    VkDevice                                    device,
    const VkBufferCreateInfo*                   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBuffer*                                   pBuffer)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateBuffer>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pBuffer);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateBuffer(device, pCreateInfo, pAllocator, pBuffer);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateBuffer);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pBuffer);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateBuffer>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pBuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBuffer(
    VkDevice                                    device,
    VkBuffer                                    buffer,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyBuffer>::Dispatch(encode::TraceManager::Get(), device, buffer, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyBuffer(device, buffer, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyBuffer);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(buffer);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyBuffer>::Dispatch(encode::TraceManager::Get(), device, buffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateBufferView(
    VkDevice                                    device,
    const VkBufferViewCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkBufferView*                               pView)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateBufferView>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateBufferView(device, pCreateInfo, pAllocator, pView);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateBufferView);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pView);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateBufferView>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyBufferView(
    VkDevice                                    device,
    VkBufferView                                bufferView,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyBufferView>::Dispatch(encode::TraceManager::Get(), device, bufferView, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyBufferView(device, bufferView, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyBufferView);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(bufferView);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyBufferView>::Dispatch(encode::TraceManager::Get(), device, bufferView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImage(
    VkDevice                                    device,
    const VkImageCreateInfo*                    pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImage*                                    pImage)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateImage>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pImage);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateImage(device, pCreateInfo, pAllocator, pImage);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateImage);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pImage);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateImage>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pImage);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImage(
    VkDevice                                    device,
    VkImage                                     image,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyImage>::Dispatch(encode::TraceManager::Get(), device, image, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyImage(device, image, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyImage);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(image);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyImage>::Dispatch(encode::TraceManager::Get(), device, image, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetImageSubresourceLayout(
    VkDevice                                    device,
    VkImage                                     image,
    const VkImageSubresource*                   pSubresource,
    VkSubresourceLayout*                        pLayout)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageSubresourceLayout>::Dispatch(encode::TraceManager::Get(), device, image, pSubresource, pLayout);

    get_device_table(device)->GetImageSubresourceLayout(device, image, pSubresource, pLayout);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageSubresourceLayout);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(image);
        encode_struct_ptr(encoder, pSubresource);
        encode_struct_ptr(encoder, pLayout);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageSubresourceLayout>::Dispatch(encode::TraceManager::Get(), device, image, pSubresource, pLayout);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateImageView(
    VkDevice                                    device,
    const VkImageViewCreateInfo*                pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkImageView*                                pView)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateImageView>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pView);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateImageView(device, pCreateInfo, pAllocator, pView);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateImageView);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pView);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateImageView>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pView);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyImageView(
    VkDevice                                    device,
    VkImageView                                 imageView,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyImageView>::Dispatch(encode::TraceManager::Get(), device, imageView, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyImageView(device, imageView, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyImageView);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(imageView);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyImageView>::Dispatch(encode::TraceManager::Get(), device, imageView, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateShaderModule(
    VkDevice                                    device,
    const VkShaderModuleCreateInfo*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkShaderModule*                             pShaderModule)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateShaderModule>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pShaderModule);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateShaderModule(device, pCreateInfo, pAllocator, pShaderModule);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateShaderModule);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pShaderModule);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateShaderModule>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pShaderModule);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyShaderModule(
    VkDevice                                    device,
    VkShaderModule                              shaderModule,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyShaderModule>::Dispatch(encode::TraceManager::Get(), device, shaderModule, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyShaderModule(device, shaderModule, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyShaderModule);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(shaderModule);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyShaderModule>::Dispatch(encode::TraceManager::Get(), device, shaderModule, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineCache(
    VkDevice                                    device,
    const VkPipelineCacheCreateInfo*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineCache*                            pPipelineCache)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreatePipelineCache>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineCache);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreatePipelineCache(device, pCreateInfo, pAllocator, pPipelineCache);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreatePipelineCache);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pPipelineCache);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreatePipelineCache>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineCache(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyPipelineCache>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyPipelineCache(device, pipelineCache, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyPipelineCache);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyPipelineCache>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPipelineCacheData(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPipelineCacheData>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, pDataSize, pData);

    VkResult result = get_device_table(device)->GetPipelineCacheData(device, pipelineCache, pDataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPipelineCacheData);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipelineCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPipelineCacheData>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL MergePipelineCaches(
    VkDevice                                    device,
    VkPipelineCache                             dstCache,
    uint32_t                                    srcCacheCount,
    const VkPipelineCache*                      pSrcCaches)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkMergePipelineCaches>::Dispatch(encode::TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    VkResult result = get_device_table(device)->MergePipelineCaches(device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkMergePipelineCaches);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkMergePipelineCaches>::Dispatch(encode::TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateGraphicsPipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkGraphicsPipelineCreateInfo*         pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateGraphicsPipelines>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateGraphicsPipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateGraphicsPipelines);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encoder->EncodeUInt32Value(createInfoCount);
            encode_struct_array(encoder, pCreateInfos, createInfoCount);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateGraphicsPipelines>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateComputePipelines(
    VkDevice                                    device,
    VkPipelineCache                             pipelineCache,
    uint32_t                                    createInfoCount,
    const VkComputePipelineCreateInfo*          pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkPipeline*                                 pPipelines)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateComputePipelines>::Dispatch(encode::TraceManager::Get(), device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateComputePipelines(device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateComputePipelines);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineCache);
            encoder->EncodeUInt32Value(createInfoCount);
            encode_struct_array(encoder, pCreateInfos, createInfoCount);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdArray(pPipelines, createInfoCount);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateComputePipelines>::Dispatch(encode::TraceManager::Get(), result, device, pipelineCache, createInfoCount, pCreateInfos, pAllocator, pPipelines);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipeline(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyPipeline>::Dispatch(encode::TraceManager::Get(), device, pipeline, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyPipeline(device, pipeline, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyPipeline);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipeline);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyPipeline>::Dispatch(encode::TraceManager::Get(), device, pipeline, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreatePipelineLayout(
    VkDevice                                    device,
    const VkPipelineLayoutCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkPipelineLayout*                           pPipelineLayout)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreatePipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pPipelineLayout);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreatePipelineLayout(device, pCreateInfo, pAllocator, pPipelineLayout);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreatePipelineLayout);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pPipelineLayout);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreatePipelineLayout>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pPipelineLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyPipelineLayout(
    VkDevice                                    device,
    VkPipelineLayout                            pipelineLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyPipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pipelineLayout, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyPipelineLayout(device, pipelineLayout, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyPipelineLayout);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(pipelineLayout);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyPipelineLayout>::Dispatch(encode::TraceManager::Get(), device, pipelineLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSampler(
    VkDevice                                    device,
    const VkSamplerCreateInfo*                  pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSampler*                                  pSampler)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateSampler>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSampler);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateSampler(device, pCreateInfo, pAllocator, pSampler);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateSampler);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSampler);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateSampler>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSampler);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySampler(
    VkDevice                                    device,
    VkSampler                                   sampler,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroySampler>::Dispatch(encode::TraceManager::Get(), device, sampler, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroySampler(device, sampler, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroySampler);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(sampler);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroySampler>::Dispatch(encode::TraceManager::Get(), device, sampler, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorSetLayout(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorSetLayout*                      pSetLayout)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSetLayout);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateDescriptorSetLayout(device, pCreateInfo, pAllocator, pSetLayout);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorSetLayout);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSetLayout);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSetLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorSetLayout(
    VkDevice                                    device,
    VkDescriptorSetLayout                       descriptorSetLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, descriptorSetLayout, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyDescriptorSetLayout(device, descriptorSetLayout, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorSetLayout);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorSetLayout);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDescriptorSetLayout>::Dispatch(encode::TraceManager::Get(), device, descriptorSetLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorPool(
    VkDevice                                    device,
    const VkDescriptorPoolCreateInfo*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorPool*                           pDescriptorPool)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorPool);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateDescriptorPool(device, pCreateInfo, pAllocator, pDescriptorPool);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorPool);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pDescriptorPool);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDescriptorPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyDescriptorPool(device, descriptorPool, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorPool);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorPool);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetDescriptorPool(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    VkDescriptorPoolResetFlags                  flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkResetDescriptorPool>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, flags);

    VkResult result = get_device_table(device)->ResetDescriptorPool(device, descriptorPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkResetDescriptorPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(descriptorPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkResetDescriptorPool>::Dispatch(encode::TraceManager::Get(), result, device, descriptorPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateDescriptorSets(
    VkDevice                                    device,
    const VkDescriptorSetAllocateInfo*          pAllocateInfo,
    VkDescriptorSet*                            pDescriptorSets)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkAllocateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pDescriptorSets);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->AllocateDescriptorSets(device, pAllocateInfo, pDescriptorSets);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkAllocateDescriptorSets);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocateInfo);
            encoder->EncodeHandleIdArray(pDescriptorSets, pAllocateInfo->descriptorSetCount);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkAllocateDescriptorSets>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pDescriptorSets);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL FreeDescriptorSets(
    VkDevice                                    device,
    VkDescriptorPool                            descriptorPool,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkFreeDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorPool, descriptorSetCount, pDescriptorSets);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->FreeDescriptorSets(device, descriptorPool, descriptorSetCount, pDescriptorSets);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkFreeDescriptorSets);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorPool);
            encoder->EncodeUInt32Value(descriptorSetCount);
            encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkFreeDescriptorSets>::Dispatch(encode::TraceManager::Get(), result, device, descriptorPool, descriptorSetCount, pDescriptorSets);

    return result;
}

VKAPI_ATTR void VKAPI_CALL UpdateDescriptorSets(
    VkDevice                                    device,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites,
    uint32_t                                    descriptorCopyCount,
    const VkCopyDescriptorSet*                  pDescriptorCopies)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkUpdateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    get_device_table(device)->UpdateDescriptorSets(device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkUpdateDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        encode_struct_array(encoder, pDescriptorWrites, descriptorWriteCount);
        encoder->EncodeUInt32Value(descriptorCopyCount);
        encode_struct_array(encoder, pDescriptorCopies, descriptorCopyCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkUpdateDescriptorSets>::Dispatch(encode::TraceManager::Get(), device, descriptorWriteCount, pDescriptorWrites, descriptorCopyCount, pDescriptorCopies);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateFramebuffer(
    VkDevice                                    device,
    const VkFramebufferCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFramebuffer*                              pFramebuffer)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateFramebuffer>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pFramebuffer);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateFramebuffer(device, pCreateInfo, pAllocator, pFramebuffer);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateFramebuffer);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pFramebuffer);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateFramebuffer>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pFramebuffer);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyFramebuffer(
    VkDevice                                    device,
    VkFramebuffer                               framebuffer,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyFramebuffer>::Dispatch(encode::TraceManager::Get(), device, framebuffer, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyFramebuffer(device, framebuffer, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyFramebuffer);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(framebuffer);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyFramebuffer>::Dispatch(encode::TraceManager::Get(), device, framebuffer, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass(
    VkDevice                                    device,
    const VkRenderPassCreateInfo*               pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateRenderPass>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateRenderPass(device, pCreateInfo, pAllocator, pRenderPass);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateRenderPass);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pRenderPass);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateRenderPass>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyRenderPass(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyRenderPass>::Dispatch(encode::TraceManager::Get(), device, renderPass, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyRenderPass(device, renderPass, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyRenderPass);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(renderPass);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyRenderPass>::Dispatch(encode::TraceManager::Get(), device, renderPass, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetRenderAreaGranularity(
    VkDevice                                    device,
    VkRenderPass                                renderPass,
    VkExtent2D*                                 pGranularity)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetRenderAreaGranularity>::Dispatch(encode::TraceManager::Get(), device, renderPass, pGranularity);

    get_device_table(device)->GetRenderAreaGranularity(device, renderPass, pGranularity);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetRenderAreaGranularity);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(renderPass);
        encode_struct_ptr(encoder, pGranularity);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetRenderAreaGranularity>::Dispatch(encode::TraceManager::Get(), device, renderPass, pGranularity);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateCommandPool(
    VkDevice                                    device,
    const VkCommandPoolCreateInfo*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkCommandPool*                              pCommandPool)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateCommandPool>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pCommandPool);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateCommandPool(device, pCreateInfo, pAllocator, pCommandPool);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateCommandPool);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pCommandPool);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateCommandPool>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pCommandPool);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyCommandPool(device, commandPool, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyCommandPool);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(commandPool);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolResetFlags                     flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkResetCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    VkResult result = get_device_table(device)->ResetCommandPool(device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkResetCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkResetCommandPool>::Dispatch(encode::TraceManager::Get(), result, device, commandPool, flags);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AllocateCommandBuffers(
    VkDevice                                    device,
    const VkCommandBufferAllocateInfo*          pAllocateInfo,
    VkCommandBuffer*                            pCommandBuffers)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkAllocateCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, pAllocateInfo, pCommandBuffers);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->AllocateCommandBuffers(device, pAllocateInfo, pCommandBuffers);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkAllocateCommandBuffers);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pAllocateInfo);
            encoder->EncodeHandleIdArray(pCommandBuffers, pAllocateInfo->commandBufferCount);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkAllocateCommandBuffers>::Dispatch(encode::TraceManager::Get(), result, device, pAllocateInfo, pCommandBuffers);

    return result;
}

VKAPI_ATTR void VKAPI_CALL FreeCommandBuffers(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkFreeCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->FreeCommandBuffers(device, commandPool, commandBufferCount, pCommandBuffers);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkFreeCommandBuffers);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(commandPool);
            encoder->EncodeUInt32Value(commandBufferCount);
            encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkFreeCommandBuffers>::Dispatch(encode::TraceManager::Get(), device, commandPool, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BeginCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    const VkCommandBufferBeginInfo*             pBeginInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBeginCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, pBeginInfo);

    VkResult result = get_device_table(commandBuffer)->BeginCommandBuffer(commandBuffer, pBeginInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBeginCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pBeginInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBeginCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer, pBeginInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL EndCommandBuffer(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkEndCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    VkResult result = get_device_table(commandBuffer)->EndCommandBuffer(commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkEndCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkEndCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL ResetCommandBuffer(
    VkCommandBuffer                             commandBuffer,
    VkCommandBufferResetFlags                   flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkResetCommandBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, flags);

    VkResult result = get_device_table(commandBuffer)->ResetCommandBuffer(commandBuffer, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkResetCommandBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkResetCommandBuffer>::Dispatch(encode::TraceManager::Get(), result, commandBuffer, flags);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBindPipeline(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipeline                                  pipeline)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBindPipeline>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);

    get_device_table(commandBuffer)->CmdBindPipeline(commandBuffer, pipelineBindPoint, pipeline);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBindPipeline);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(pipeline);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBindPipeline>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, pipeline);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewport(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewport*                           pViewports)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetViewport>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);

    get_device_table(commandBuffer)->CmdSetViewport(commandBuffer, firstViewport, viewportCount, pViewports);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetViewport);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pViewports, viewportCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetViewport>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewports);
}

VKAPI_ATTR void VKAPI_CALL CmdSetScissor(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstScissor,
    uint32_t                                    scissorCount,
    const VkRect2D*                             pScissors)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetScissor>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);

    get_device_table(commandBuffer)->CmdSetScissor(commandBuffer, firstScissor, scissorCount, pScissors);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetScissor);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstScissor);
        encoder->EncodeUInt32Value(scissorCount);
        encode_struct_array(encoder, pScissors, scissorCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetScissor>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstScissor, scissorCount, pScissors);
}

VKAPI_ATTR void VKAPI_CALL CmdSetLineWidth(
    VkCommandBuffer                             commandBuffer,
    float                                       lineWidth)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetLineWidth>::Dispatch(encode::TraceManager::Get(), commandBuffer, lineWidth);

    get_device_table(commandBuffer)->CmdSetLineWidth(commandBuffer, lineWidth);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetLineWidth);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(lineWidth);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetLineWidth>::Dispatch(encode::TraceManager::Get(), commandBuffer, lineWidth);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBias(
    VkCommandBuffer                             commandBuffer,
    float                                       depthBiasConstantFactor,
    float                                       depthBiasClamp,
    float                                       depthBiasSlopeFactor)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetDepthBias>::Dispatch(encode::TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    get_device_table(commandBuffer)->CmdSetDepthBias(commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDepthBias);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(depthBiasConstantFactor);
        encoder->EncodeFloatValue(depthBiasClamp);
        encoder->EncodeFloatValue(depthBiasSlopeFactor);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetDepthBias>::Dispatch(encode::TraceManager::Get(), commandBuffer, depthBiasConstantFactor, depthBiasClamp, depthBiasSlopeFactor);
}

VKAPI_ATTR void VKAPI_CALL CmdSetBlendConstants(
    VkCommandBuffer                             commandBuffer,
    const float                                 blendConstants[4])
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetBlendConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, blendConstants);

    get_device_table(commandBuffer)->CmdSetBlendConstants(commandBuffer, blendConstants);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetBlendConstants);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatArray(blendConstants, 4);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetBlendConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, blendConstants);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDepthBounds(
    VkCommandBuffer                             commandBuffer,
    float                                       minDepthBounds,
    float                                       maxDepthBounds)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetDepthBounds>::Dispatch(encode::TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);

    get_device_table(commandBuffer)->CmdSetDepthBounds(commandBuffer, minDepthBounds, maxDepthBounds);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDepthBounds);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFloatValue(minDepthBounds);
        encoder->EncodeFloatValue(maxDepthBounds);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetDepthBounds>::Dispatch(encode::TraceManager::Get(), commandBuffer, minDepthBounds, maxDepthBounds);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilCompareMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    compareMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetStencilCompareMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, compareMask);

    get_device_table(commandBuffer)->CmdSetStencilCompareMask(commandBuffer, faceMask, compareMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetStencilCompareMask);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(compareMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetStencilCompareMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, compareMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilWriteMask(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    writeMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetStencilWriteMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, writeMask);

    get_device_table(commandBuffer)->CmdSetStencilWriteMask(commandBuffer, faceMask, writeMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetStencilWriteMask);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(writeMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetStencilWriteMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, writeMask);
}

VKAPI_ATTR void VKAPI_CALL CmdSetStencilReference(
    VkCommandBuffer                             commandBuffer,
    VkStencilFaceFlags                          faceMask,
    uint32_t                                    reference)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetStencilReference>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, reference);

    get_device_table(commandBuffer)->CmdSetStencilReference(commandBuffer, faceMask, reference);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetStencilReference);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(faceMask);
        encoder->EncodeUInt32Value(reference);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetStencilReference>::Dispatch(encode::TraceManager::Get(), commandBuffer, faceMask, reference);
}

VKAPI_ATTR void VKAPI_CALL CmdBindDescriptorSets(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    firstSet,
    uint32_t                                    descriptorSetCount,
    const VkDescriptorSet*                      pDescriptorSets,
    uint32_t                                    dynamicOffsetCount,
    const uint32_t*                             pDynamicOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBindDescriptorSets>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    get_device_table(commandBuffer)->CmdBindDescriptorSets(commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBindDescriptorSets);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(firstSet);
        encoder->EncodeUInt32Value(descriptorSetCount);
        encoder->EncodeHandleIdArray(pDescriptorSets, descriptorSetCount);
        encoder->EncodeUInt32Value(dynamicOffsetCount);
        encoder->EncodeUInt32Array(pDynamicOffsets, dynamicOffsetCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBindDescriptorSets>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, firstSet, descriptorSetCount, pDescriptorSets, dynamicOffsetCount, pDynamicOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdBindIndexBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkIndexType                                 indexType)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBindIndexBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, indexType);

    get_device_table(commandBuffer)->CmdBindIndexBuffer(commandBuffer, buffer, offset, indexType);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBindIndexBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeEnumValue(indexType);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBindIndexBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, indexType);
}

VKAPI_ATTR void VKAPI_CALL CmdBindVertexBuffers(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstBinding,
    uint32_t                                    bindingCount,
    const VkBuffer*                             pBuffers,
    const VkDeviceSize*                         pOffsets)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBindVertexBuffers>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    get_device_table(commandBuffer)->CmdBindVertexBuffers(commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBindVertexBuffers);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstBinding);
        encoder->EncodeUInt32Value(bindingCount);
        encoder->EncodeHandleIdArray(pBuffers, bindingCount);
        encoder->EncodeVkDeviceSizeArray(pOffsets, bindingCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBindVertexBuffers>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstBinding, bindingCount, pBuffers, pOffsets);
}

VKAPI_ATTR void VKAPI_CALL CmdDraw(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    vertexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstVertex,
    uint32_t                                    firstInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDraw>::Dispatch(encode::TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    get_device_table(commandBuffer)->CmdDraw(commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDraw);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(vertexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstVertex);
        encoder->EncodeUInt32Value(firstInstance);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDraw>::Dispatch(encode::TraceManager::Get(), commandBuffer, vertexCount, instanceCount, firstVertex, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexed(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    indexCount,
    uint32_t                                    instanceCount,
    uint32_t                                    firstIndex,
    int32_t                                     vertexOffset,
    uint32_t                                    firstInstance)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndexed>::Dispatch(encode::TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    get_device_table(commandBuffer)->CmdDrawIndexed(commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexed);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(indexCount);
        encoder->EncodeUInt32Value(instanceCount);
        encoder->EncodeUInt32Value(firstIndex);
        encoder->EncodeInt32Value(vertexOffset);
        encoder->EncodeUInt32Value(firstInstance);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndexed>::Dispatch(encode::TraceManager::Get(), commandBuffer, indexCount, instanceCount, firstIndex, vertexOffset, firstInstance);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    get_device_table(commandBuffer)->CmdDrawIndirect(commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndirect);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    uint32_t                                    drawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndexedIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);

    get_device_table(commandBuffer)->CmdDrawIndexedIndirect(commandBuffer, buffer, offset, drawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexedIndirect);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeUInt32Value(drawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndexedIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, drawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatch(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDispatch>::Dispatch(encode::TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);

    get_device_table(commandBuffer)->CmdDispatch(commandBuffer, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatch);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDispatch>::Dispatch(encode::TraceManager::Get(), commandBuffer, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchIndirect(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDispatchIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset);

    get_device_table(commandBuffer)->CmdDispatchIndirect(commandBuffer, buffer, offset);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatchIndirect);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDispatchIndirect>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferCopy*                         pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdCopyBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    get_device_table(commandBuffer)->CmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdCopyBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageCopy*                          pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdCopyImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    get_device_table(commandBuffer)->CmdCopyImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdCopyImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdBlitImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageBlit*                          pRegions,
    VkFilter                                    filter)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBlitImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    get_device_table(commandBuffer)->CmdBlitImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBlitImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encoder->EncodeEnumValue(filter);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBlitImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions, filter);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyBufferToImage(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    srcBuffer,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdCopyBufferToImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    get_device_table(commandBuffer)->CmdCopyBufferToImage(commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyBufferToImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcBuffer);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdCopyBufferToImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcBuffer, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyImageToBuffer(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkBuffer                                    dstBuffer,
    uint32_t                                    regionCount,
    const VkBufferImageCopy*                    pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdCopyImageToBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    get_device_table(commandBuffer)->CmdCopyImageToBuffer(commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyImageToBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdCopyImageToBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstBuffer, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdUpdateBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                dataSize,
    const void*                                 pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdUpdateBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    get_device_table(commandBuffer)->CmdUpdateBuffer(commandBuffer, dstBuffer, dstOffset, dataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdUpdateBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(dataSize);
        encoder->EncodeVoidArray(pData, dataSize);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdUpdateBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, dataSize, pData);
}

VKAPI_ATTR void VKAPI_CALL CmdFillBuffer(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                size,
    uint32_t                                    data)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdFillBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);

    get_device_table(commandBuffer)->CmdFillBuffer(commandBuffer, dstBuffer, dstOffset, size, data);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdFillBuffer);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(size);
        encoder->EncodeUInt32Value(data);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdFillBuffer>::Dispatch(encode::TraceManager::Get(), commandBuffer, dstBuffer, dstOffset, size, data);
}

VKAPI_ATTR void VKAPI_CALL CmdClearColorImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearColorValue*                    pColor,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdClearColorImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    get_device_table(commandBuffer)->CmdClearColorImage(commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdClearColorImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        encode_struct_ptr(encoder, pColor);
        encoder->EncodeUInt32Value(rangeCount);
        encode_struct_array(encoder, pRanges, rangeCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdClearColorImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pColor, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearDepthStencilImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     image,
    VkImageLayout                               imageLayout,
    const VkClearDepthStencilValue*             pDepthStencil,
    uint32_t                                    rangeCount,
    const VkImageSubresourceRange*              pRanges)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdClearDepthStencilImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    get_device_table(commandBuffer)->CmdClearDepthStencilImage(commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdClearDepthStencilImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(image);
        encoder->EncodeEnumValue(imageLayout);
        encode_struct_ptr(encoder, pDepthStencil);
        encoder->EncodeUInt32Value(rangeCount);
        encode_struct_array(encoder, pRanges, rangeCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdClearDepthStencilImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, image, imageLayout, pDepthStencil, rangeCount, pRanges);
}

VKAPI_ATTR void VKAPI_CALL CmdClearAttachments(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    attachmentCount,
    const VkClearAttachment*                    pAttachments,
    uint32_t                                    rectCount,
    const VkClearRect*                          pRects)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdClearAttachments>::Dispatch(encode::TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    get_device_table(commandBuffer)->CmdClearAttachments(commandBuffer, attachmentCount, pAttachments, rectCount, pRects);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdClearAttachments);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(attachmentCount);
        encode_struct_array(encoder, pAttachments, attachmentCount);
        encoder->EncodeUInt32Value(rectCount);
        encode_struct_array(encoder, pRects, rectCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdClearAttachments>::Dispatch(encode::TraceManager::Get(), commandBuffer, attachmentCount, pAttachments, rectCount, pRects);
}

VKAPI_ATTR void VKAPI_CALL CmdResolveImage(
    VkCommandBuffer                             commandBuffer,
    VkImage                                     srcImage,
    VkImageLayout                               srcImageLayout,
    VkImage                                     dstImage,
    VkImageLayout                               dstImageLayout,
    uint32_t                                    regionCount,
    const VkImageResolve*                       pRegions)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdResolveImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    get_device_table(commandBuffer)->CmdResolveImage(commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdResolveImage);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(srcImage);
        encoder->EncodeEnumValue(srcImageLayout);
        encoder->EncodeHandleIdValue(dstImage);
        encoder->EncodeEnumValue(dstImageLayout);
        encoder->EncodeUInt32Value(regionCount);
        encode_struct_array(encoder, pRegions, regionCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdResolveImage>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcImage, srcImageLayout, dstImage, dstImageLayout, regionCount, pRegions);
}

VKAPI_ATTR void VKAPI_CALL CmdSetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);

    get_device_table(commandBuffer)->CmdSetEvent(commandBuffer, event, stageMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdResetEvent(
    VkCommandBuffer                             commandBuffer,
    VkEvent                                     event,
    VkPipelineStageFlags                        stageMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdResetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);

    get_device_table(commandBuffer)->CmdResetEvent(commandBuffer, event, stageMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdResetEvent);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(event);
        encoder->EncodeFlagsValue(stageMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdResetEvent>::Dispatch(encode::TraceManager::Get(), commandBuffer, event, stageMask);
}

VKAPI_ATTR void VKAPI_CALL CmdWaitEvents(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    eventCount,
    const VkEvent*                              pEvents,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdWaitEvents>::Dispatch(encode::TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    get_device_table(commandBuffer)->CmdWaitEvents(commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdWaitEvents);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(eventCount);
        encoder->EncodeHandleIdArray(pEvents, eventCount);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        encode_struct_array(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        encode_struct_array(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        encode_struct_array(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdWaitEvents>::Dispatch(encode::TraceManager::Get(), commandBuffer, eventCount, pEvents, srcStageMask, dstStageMask, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdPipelineBarrier(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlags                        srcStageMask,
    VkPipelineStageFlags                        dstStageMask,
    VkDependencyFlags                           dependencyFlags,
    uint32_t                                    memoryBarrierCount,
    const VkMemoryBarrier*                      pMemoryBarriers,
    uint32_t                                    bufferMemoryBarrierCount,
    const VkBufferMemoryBarrier*                pBufferMemoryBarriers,
    uint32_t                                    imageMemoryBarrierCount,
    const VkImageMemoryBarrier*                 pImageMemoryBarriers)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdPipelineBarrier>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    get_device_table(commandBuffer)->CmdPipelineBarrier(commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdPipelineBarrier);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeFlagsValue(srcStageMask);
        encoder->EncodeFlagsValue(dstStageMask);
        encoder->EncodeFlagsValue(dependencyFlags);
        encoder->EncodeUInt32Value(memoryBarrierCount);
        encode_struct_array(encoder, pMemoryBarriers, memoryBarrierCount);
        encoder->EncodeUInt32Value(bufferMemoryBarrierCount);
        encode_struct_array(encoder, pBufferMemoryBarriers, bufferMemoryBarrierCount);
        encoder->EncodeUInt32Value(imageMemoryBarrierCount);
        encode_struct_array(encoder, pImageMemoryBarriers, imageMemoryBarrierCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdPipelineBarrier>::Dispatch(encode::TraceManager::Get(), commandBuffer, srcStageMask, dstStageMask, dependencyFlags, memoryBarrierCount, pMemoryBarriers, bufferMemoryBarrierCount, pBufferMemoryBarriers, imageMemoryBarrierCount, pImageMemoryBarriers);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query,
    VkQueryControlFlags                         flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBeginQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags);

    get_device_table(commandBuffer)->CmdBeginQuery(commandBuffer, queryPool, query, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginQuery);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBeginQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdEndQuery(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdEndQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query);

    get_device_table(commandBuffer)->CmdEndQuery(commandBuffer, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdEndQuery);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdEndQuery>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdResetQueryPool(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdResetQueryPool>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);

    get_device_table(commandBuffer)->CmdResetQueryPool(commandBuffer, queryPool, firstQuery, queryCount);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdResetQueryPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdResetQueryPool>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount);
}

VKAPI_ATTR void VKAPI_CALL CmdWriteTimestamp(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkQueryPool                                 queryPool,
    uint32_t                                    query)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdWriteTimestamp>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);

    get_device_table(commandBuffer)->CmdWriteTimestamp(commandBuffer, pipelineStage, queryPool, query);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdWriteTimestamp);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(query);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdWriteTimestamp>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, queryPool, query);
}

VKAPI_ATTR void VKAPI_CALL CmdCopyQueryPoolResults(
    VkCommandBuffer                             commandBuffer,
    VkQueryPool                                 queryPool,
    uint32_t                                    firstQuery,
    uint32_t                                    queryCount,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    VkDeviceSize                                stride,
    VkQueryResultFlags                          flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdCopyQueryPoolResults>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    get_device_table(commandBuffer)->CmdCopyQueryPoolResults(commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdCopyQueryPoolResults);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(queryPool);
        encoder->EncodeUInt32Value(firstQuery);
        encoder->EncodeUInt32Value(queryCount);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeVkDeviceSizeValue(stride);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdCopyQueryPoolResults>::Dispatch(encode::TraceManager::Get(), commandBuffer, queryPool, firstQuery, queryCount, dstBuffer, dstOffset, stride, flags);
}

VKAPI_ATTR void VKAPI_CALL CmdPushConstants(
    VkCommandBuffer                             commandBuffer,
    VkPipelineLayout                            layout,
    VkShaderStageFlags                          stageFlags,
    uint32_t                                    offset,
    uint32_t                                    size,
    const void*                                 pValues)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdPushConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);

    get_device_table(commandBuffer)->CmdPushConstants(commandBuffer, layout, stageFlags, offset, size, pValues);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdPushConstants);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeFlagsValue(stageFlags);
        encoder->EncodeUInt32Value(offset);
        encoder->EncodeUInt32Value(size);
        encoder->EncodeVoidArray(pValues, size);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdPushConstants>::Dispatch(encode::TraceManager::Get(), commandBuffer, layout, stageFlags, offset, size, pValues);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    VkSubpassContents                           contents)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBeginRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);

    get_device_table(commandBuffer)->CmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pRenderPassBegin);
        encoder->EncodeEnumValue(contents);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBeginRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass(
    VkCommandBuffer                             commandBuffer,
    VkSubpassContents                           contents)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdNextSubpass>::Dispatch(encode::TraceManager::Get(), commandBuffer, contents);

    get_device_table(commandBuffer)->CmdNextSubpass(commandBuffer, contents);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdNextSubpass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(contents);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdNextSubpass>::Dispatch(encode::TraceManager::Get(), commandBuffer, contents);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdEndRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    get_device_table(commandBuffer)->CmdEndRenderPass(commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdEndRenderPass);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdEndRenderPass>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdExecuteCommands(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    commandBufferCount,
    const VkCommandBuffer*                      pCommandBuffers)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdExecuteCommands>::Dispatch(encode::TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);

    get_device_table(commandBuffer)->CmdExecuteCommands(commandBuffer, commandBufferCount, pCommandBuffers);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdExecuteCommands);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(commandBufferCount);
        encoder->EncodeHandleIdArray(pCommandBuffers, commandBufferCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdExecuteCommands>::Dispatch(encode::TraceManager::Get(), commandBuffer, commandBufferCount, pCommandBuffers);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBindBufferMemory2>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = get_device_table(device)->BindBufferMemory2(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBindBufferMemory2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBindBufferMemory2>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBindImageMemory2>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = get_device_table(device)->BindImageMemory2(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBindImageMemory2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBindImageMemory2>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeatures(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    get_device_table(device)->GetDeviceGroupPeerMemoryFeatures(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupPeerMemoryFeatures);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceGroupPeerMemoryFeatures>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMask(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetDeviceMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);

    get_device_table(commandBuffer)->CmdSetDeviceMask(commandBuffer, deviceMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDeviceMask);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetDeviceMask>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBase(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDispatchBase>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    get_device_table(commandBuffer)->CmdDispatchBase(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatchBase);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDispatchBase>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroups(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkEnumeratePhysicalDeviceGroups>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkResult result = get_instance_table(instance)->EnumeratePhysicalDeviceGroups(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkEnumeratePhysicalDeviceGroups);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkEnumeratePhysicalDeviceGroups>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    get_device_table(device)->GetImageMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetBufferMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    get_device_table(device)->GetBufferMemoryRequirements2(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetBufferMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetBufferMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageSparseMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    get_device_table(device)->GetImageSparseMemoryRequirements2(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageSparseMemoryRequirements2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageSparseMemoryRequirements2>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceFeatures2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures2(physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFeatures2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceFeatures2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties2(physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pImageFormatInfo);
        encode_struct_ptr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2(physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPool(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkTrimCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    get_device_table(device)->TrimCommandPool(device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkTrimCommandPool);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkTrimCommandPool>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceQueue2(
    VkDevice                                    device,
    const VkDeviceQueueInfo2*                   pQueueInfo,
    VkQueue*                                    pQueue)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceQueue2>::Dispatch(encode::TraceManager::Get(), device, pQueueInfo, pQueue);

    get_device_table(device)->GetDeviceQueue2(device, pQueueInfo, pQueue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceQueue2);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pQueueInfo);
        encoder->EncodeHandleIdPtr(pQueue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceQueue2>::Dispatch(encode::TraceManager::Get(), device, pQueueInfo, pQueue);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversion(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateSamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateSamplerYcbcrConversion(device, pCreateInfo, pAllocator, pYcbcrConversion);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateSamplerYcbcrConversion);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pYcbcrConversion);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateSamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversion(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroySamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroySamplerYcbcrConversion(device, ycbcrConversion, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroySamplerYcbcrConversion);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(ycbcrConversion);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroySamplerYcbcrConversion>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplate(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateDescriptorUpdateTemplate(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorUpdateTemplate);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplate(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyDescriptorUpdateTemplate(device, descriptorUpdateTemplate, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorUpdateTemplate);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDescriptorUpdateTemplate>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalBufferProperties(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalBufferProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalBufferInfo);
        encode_struct_ptr(encoder, pExternalBufferProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalBufferProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFenceProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalFenceProperties(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalFenceProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalFenceInfo);
        encode_struct_ptr(encoder, pExternalFenceProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalFenceProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphoreProperties(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalSemaphoreProperties(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalSemaphoreProperties);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalSemaphoreInfo);
        encode_struct_ptr(encoder, pExternalSemaphoreProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalSemaphoreProperties>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupport(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDescriptorSetLayoutSupport>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);

    get_device_table(device)->GetDescriptorSetLayoutSupport(device, pCreateInfo, pSupport);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDescriptorSetLayoutSupport);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pSupport);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDescriptorSetLayoutSupport>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL DestroySurfaceKHR(
    VkInstance                                  instance,
    VkSurfaceKHR                                surface,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroySurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, surface, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_instance_table(instance)->DestroySurfaceKHR(instance, surface, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroySurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encoder->EncodeHandleIdValue(surface);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroySurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, surface, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    VkSurfaceKHR                                surface,
    VkBool32*                                   pSupported)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, surface, pSupported);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceSupportKHR(physicalDevice, queueFamilyIndex, surface, pSupported);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeVkBool32Ptr(pSupported);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, surface, pSupported);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilitiesKHR*                   pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encode_struct_ptr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormatsKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormatKHR*                         pSurfaceFormats)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceFormatsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceFormatsKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfacePresentModesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pPresentModeCount,
    VkPresentModeKHR*                           pPresentModes)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pPresentModeCount, pPresentModes);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, pPresentModeCount, pPresentModes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pPresentModeCount);
        encoder->EncodeEnumArray(pPresentModes, (pPresentModeCount != nullptr) ? (*pPresentModeCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pPresentModeCount, pPresentModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSwapchainKHR(
    VkDevice                                    device,
    const VkSwapchainCreateInfoKHR*             pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchain)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateSwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pSwapchain);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateSwapchainKHR(device, pCreateInfo, pAllocator, pSwapchain);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateSwapchainKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSwapchain);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateSwapchainKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pSwapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySwapchainKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroySwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroySwapchainKHR(device, swapchain, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroySwapchainKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(swapchain);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroySwapchainKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainImagesKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pSwapchainImageCount,
    VkImage*                                    pSwapchainImages)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetSwapchainImagesKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, pSwapchainImageCount, pSwapchainImages);

    VkResult result = get_device_table(device)->GetSwapchainImagesKHR(device, swapchain, pSwapchainImageCount, pSwapchainImages);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetSwapchainImagesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pSwapchainImageCount);
        encoder->EncodeHandleIdArray(pSwapchainImages, (pSwapchainImageCount != nullptr) ? (*pSwapchainImageCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetSwapchainImagesKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pSwapchainImageCount, pSwapchainImages);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImageKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint64_t                                    timeout,
    VkSemaphore                                 semaphore,
    VkFence                                     fence,
    uint32_t*                                   pImageIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkAcquireNextImageKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain, timeout, semaphore, fence, pImageIndex);

    VkResult result = get_device_table(device)->AcquireNextImageKHR(device, swapchain, timeout, semaphore, fence, pImageIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkAcquireNextImageKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt64Value(timeout);
        encoder->EncodeHandleIdValue(semaphore);
        encoder->EncodeHandleIdValue(fence);
        encoder->EncodeUInt32Ptr(pImageIndex);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkAcquireNextImageKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, timeout, semaphore, fence, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL QueuePresentKHR(
    VkQueue                                     queue,
    const VkPresentInfoKHR*                     pPresentInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueuePresentKHR>::Dispatch(encode::TraceManager::Get(), queue, pPresentInfo);

    VkResult result = get_device_table(queue)->QueuePresentKHR(queue, pPresentInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueuePresentKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode_struct_ptr(encoder, pPresentInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueuePresentKHR>::Dispatch(encode::TraceManager::Get(), result, queue, pPresentInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupPresentCapabilitiesKHR(
    VkDevice                                    device,
    VkDeviceGroupPresentCapabilitiesKHR*        pDeviceGroupPresentCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), device, pDeviceGroupPresentCapabilities);

    VkResult result = get_device_table(device)->GetDeviceGroupPresentCapabilitiesKHR(device, pDeviceGroupPresentCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupPresentCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pDeviceGroupPresentCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceGroupPresentCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, pDeviceGroupPresentCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDeviceGroupSurfacePresentModesKHR(
    VkDevice                                    device,
    VkSurfaceKHR                                surface,
    VkDeviceGroupPresentModeFlagsKHR*           pModes)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), device, surface, pModes);

    VkResult result = get_device_table(device)->GetDeviceGroupSurfacePresentModesKHR(device, surface, pModes);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupSurfacePresentModesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeFlagsPtr(pModes);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceGroupSurfacePresentModesKHR>::Dispatch(encode::TraceManager::Get(), result, device, surface, pModes);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDevicePresentRectanglesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    uint32_t*                                   pRectCount,
    VkRect2D*                                   pRects)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pRectCount, pRects);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDevicePresentRectanglesKHR(physicalDevice, surface, pRectCount, pRects);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDevicePresentRectanglesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encoder->EncodeUInt32Ptr(pRectCount);
        encode_struct_array(encoder, pRects, (pRectCount != nullptr) ? (*pRectCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDevicePresentRectanglesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pRectCount, pRects);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL AcquireNextImage2KHR(
    VkDevice                                    device,
    const VkAcquireNextImageInfoKHR*            pAcquireInfo,
    uint32_t*                                   pImageIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkAcquireNextImage2KHR>::Dispatch(encode::TraceManager::Get(), device, pAcquireInfo, pImageIndex);

    VkResult result = get_device_table(device)->AcquireNextImage2KHR(device, pAcquireInfo, pImageIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkAcquireNextImage2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pAcquireInfo);
        encoder->EncodeUInt32Ptr(pImageIndex);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkAcquireNextImage2KHR>::Dispatch(encode::TraceManager::Get(), result, device, pAcquireInfo, pImageIndex);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPropertiesKHR*                     pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceDisplayPropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlanePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlanePropertiesKHR*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPlanePropertiesKHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayPlanePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceDisplayPlanePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneSupportedDisplaysKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    planeIndex,
    uint32_t*                                   pDisplayCount,
    VkDisplayKHR*                               pDisplays)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, planeIndex, pDisplayCount, pDisplays);

    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneSupportedDisplaysKHR(physicalDevice, planeIndex, pDisplayCount, pDisplays);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayPlaneSupportedDisplaysKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(planeIndex);
        encoder->EncodeUInt32Ptr(pDisplayCount);
        encoder->EncodeHandleIdArray(pDisplays, (pDisplayCount != nullptr) ? (*pDisplayCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDisplayPlaneSupportedDisplaysKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, planeIndex, pDisplayCount, pDisplays);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModePropertiesKHR*                 pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDisplayModePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkResult result = get_instance_table(physicalDevice)->GetDisplayModePropertiesKHR(physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayModePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDisplayModePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayModeKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    const VkDisplayModeCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDisplayModeKHR*                           pMode)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDisplayModeKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pCreateInfo, pAllocator, pMode);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(physicalDevice)->CreateDisplayModeKHR(physicalDevice, display, pCreateInfo, pAllocator, pMode);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDisplayModeKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(physicalDevice);
            encoder->EncodeHandleIdValue(display);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pMode);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDisplayModeKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pCreateInfo, pAllocator, pMode);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilitiesKHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayModeKHR                            mode,
    uint32_t                                    planeIndex,
    VkDisplayPlaneCapabilitiesKHR*              pCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, mode, planeIndex, pCapabilities);

    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneCapabilitiesKHR(physicalDevice, mode, planeIndex, pCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayPlaneCapabilitiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(mode);
        encoder->EncodeUInt32Value(planeIndex);
        encode_struct_ptr(encoder, pCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDisplayPlaneCapabilitiesKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, mode, planeIndex, pCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDisplayPlaneSurfaceKHR(
    VkInstance                                  instance,
    const VkDisplaySurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateDisplayPlaneSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDisplayPlaneSurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDisplayPlaneSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSharedSwapchainsKHR(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainCreateInfoKHR*             pCreateInfos,
    const VkAllocationCallbacks*                pAllocator,
    VkSwapchainKHR*                             pSwapchains)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateSharedSwapchainsKHR>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateSharedSwapchainsKHR(device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateSharedSwapchainsKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeUInt32Value(swapchainCount);
            encode_struct_array(encoder, pCreateInfos, swapchainCount);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdArray(pSwapchains, swapchainCount);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateSharedSwapchainsKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchainCount, pCreateInfos, pAllocator, pSwapchains);

    return result;
}

#ifdef VK_USE_PLATFORM_XLIB_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateXlibSurfaceKHR(
    VkInstance                                  instance,
    const VkXlibSurfaceCreateInfoKHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateXlibSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateXlibSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateXlibSurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateXlibSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXlibPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    Display*                                    dpy,
    VisualID                                    visualID)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, dpy, visualID);

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceXlibPresentationSupportKHR(physicalDevice, queueFamilyIndex, dpy, visualID);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceXlibPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeUInt32Value(visualID);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceXlibPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, dpy, visualID);

    return result;
}
#endif /* VK_USE_PLATFORM_XLIB_KHR */

#ifdef VK_USE_PLATFORM_XCB_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateXcbSurfaceKHR(
    VkInstance                                  instance,
    const VkXcbSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateXcbSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateXcbSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateXcbSurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateXcbSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceXcbPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    xcb_connection_t*                           connection,
    xcb_visualid_t                              visual_id)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, connection, visual_id);

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceXcbPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection, visual_id);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceXcbPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encoder->EncodeUInt32Value(visual_id);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceXcbPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, connection, visual_id);

    return result;
}
#endif /* VK_USE_PLATFORM_XCB_KHR */

#ifdef VK_USE_PLATFORM_WAYLAND_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateWaylandSurfaceKHR(
    VkInstance                                  instance,
    const VkWaylandSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateWaylandSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateWaylandSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateWaylandSurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateWaylandSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWaylandPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    struct wl_display*                          display)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, display);

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceWaylandPresentationSupportKHR(physicalDevice, queueFamilyIndex, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceWaylandPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(display);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceWaylandPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, display);

    return result;
}
#endif /* VK_USE_PLATFORM_WAYLAND_KHR */

#ifdef VK_USE_PLATFORM_MIR_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateMirSurfaceKHR(
    VkInstance                                  instance,
    const VkMirSurfaceCreateInfoKHR*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateMirSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateMirSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateMirSurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateMirSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceMirPresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex,
    MirConnection*                              connection)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex, connection);

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceMirPresentationSupportKHR(physicalDevice, queueFamilyIndex, connection);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMirPresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeVoidPtr(connection);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceMirPresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex, connection);

    return result;
}
#endif /* VK_USE_PLATFORM_MIR_KHR */

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateAndroidSurfaceKHR(
    VkInstance                                  instance,
    const VkAndroidSurfaceCreateInfoKHR*        pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateAndroidSurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateAndroidSurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateAndroidSurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateAndroidSurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL CreateWin32SurfaceKHR(
    VkInstance                                  instance,
    const VkWin32SurfaceCreateInfoKHR*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateWin32SurfaceKHR>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateWin32SurfaceKHR(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateWin32SurfaceKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateWin32SurfaceKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}

VKAPI_ATTR VkBool32 VKAPI_CALL GetPhysicalDeviceWin32PresentationSupportKHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t                                    queueFamilyIndex)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, queueFamilyIndex);

    VkBool32 result = get_instance_table(physicalDevice)->GetPhysicalDeviceWin32PresentationSupportKHR(physicalDevice, queueFamilyIndex);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceWin32PresentationSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Value(queueFamilyIndex);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceWin32PresentationSupportKHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, queueFamilyIndex);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFeatures2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceFeatures2*                  pFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);

    get_instance_table(physicalDevice)->GetPhysicalDeviceFeatures2KHR(physicalDevice, pFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFeatures2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceFeatures2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceProperties2*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkFormatProperties2*                        pFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceFormatProperties2KHR(physicalDevice, format, pFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encode_struct_ptr(encoder, pFormatProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, pFormatProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceImageFormatInfo2*     pImageFormatInfo,
    VkImageFormatProperties2*                   pImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pImageFormatInfo, pImageFormatProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceImageFormatProperties2KHR(physicalDevice, pImageFormatInfo, pImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pImageFormatInfo);
        encode_struct_ptr(encoder, pImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pImageFormatInfo, pImageFormatProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2*                   pQueueFamilyProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pQueueFamilyPropertyCount);
        encode_struct_array(encoder, pQueueFamilyProperties, (pQueueFamilyPropertyCount != nullptr) ? (*pQueueFamilyPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceQueueFamilyProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMemoryProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkPhysicalDeviceMemoryProperties2*          pMemoryProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceMemoryProperties2KHR(physicalDevice, pMemoryProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pMemoryProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceMemoryProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pMemoryProperties);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceSparseImageFormatProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSparseImageFormatInfo2* pFormatInfo,
    uint32_t*                                   pPropertyCount,
    VkSparseImageFormatProperties2*             pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceSparseImageFormatProperties2KHR(physicalDevice, pFormatInfo, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFormatInfo);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSparseImageFormatProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFormatInfo, pPropertyCount, pProperties);
}

VKAPI_ATTR void VKAPI_CALL GetDeviceGroupPeerMemoryFeaturesKHR(
    VkDevice                                    device,
    uint32_t                                    heapIndex,
    uint32_t                                    localDeviceIndex,
    uint32_t                                    remoteDeviceIndex,
    VkPeerMemoryFeatureFlags*                   pPeerMemoryFeatures)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    get_device_table(device)->GetDeviceGroupPeerMemoryFeaturesKHR(device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDeviceGroupPeerMemoryFeaturesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(heapIndex);
        encoder->EncodeUInt32Value(localDeviceIndex);
        encoder->EncodeUInt32Value(remoteDeviceIndex);
        encoder->EncodeFlagsPtr(pPeerMemoryFeatures);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDeviceGroupPeerMemoryFeaturesKHR>::Dispatch(encode::TraceManager::Get(), device, heapIndex, localDeviceIndex, remoteDeviceIndex, pPeerMemoryFeatures);
}

VKAPI_ATTR void VKAPI_CALL CmdSetDeviceMaskKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    deviceMask)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetDeviceMaskKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);

    get_device_table(commandBuffer)->CmdSetDeviceMaskKHR(commandBuffer, deviceMask);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDeviceMaskKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(deviceMask);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetDeviceMaskKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, deviceMask);
}

VKAPI_ATTR void VKAPI_CALL CmdDispatchBaseKHR(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    baseGroupX,
    uint32_t                                    baseGroupY,
    uint32_t                                    baseGroupZ,
    uint32_t                                    groupCountX,
    uint32_t                                    groupCountY,
    uint32_t                                    groupCountZ)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDispatchBaseKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    get_device_table(commandBuffer)->CmdDispatchBaseKHR(commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDispatchBaseKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(baseGroupX);
        encoder->EncodeUInt32Value(baseGroupY);
        encoder->EncodeUInt32Value(baseGroupZ);
        encoder->EncodeUInt32Value(groupCountX);
        encoder->EncodeUInt32Value(groupCountY);
        encoder->EncodeUInt32Value(groupCountZ);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDispatchBaseKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, baseGroupX, baseGroupY, baseGroupZ, groupCountX, groupCountY, groupCountZ);
}

VKAPI_ATTR void VKAPI_CALL TrimCommandPoolKHR(
    VkDevice                                    device,
    VkCommandPool                               commandPool,
    VkCommandPoolTrimFlags                      flags)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkTrimCommandPoolKHR>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);

    get_device_table(device)->TrimCommandPoolKHR(device, commandPool, flags);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkTrimCommandPoolKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(commandPool);
        encoder->EncodeFlagsValue(flags);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkTrimCommandPoolKHR>::Dispatch(encode::TraceManager::Get(), device, commandPool, flags);
}

VKAPI_ATTR VkResult VKAPI_CALL EnumeratePhysicalDeviceGroupsKHR(
    VkInstance                                  instance,
    uint32_t*                                   pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties*            pPhysicalDeviceGroupProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(encode::TraceManager::Get(), instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    VkResult result = get_instance_table(instance)->EnumeratePhysicalDeviceGroupsKHR(instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkEnumeratePhysicalDeviceGroupsKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeUInt32Ptr(pPhysicalDeviceGroupCount);
        encode_struct_array(encoder, pPhysicalDeviceGroupProperties, (pPhysicalDeviceGroupCount != nullptr) ? (*pPhysicalDeviceGroupCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkEnumeratePhysicalDeviceGroupsKHR>::Dispatch(encode::TraceManager::Get(), result, instance, pPhysicalDeviceGroupCount, pPhysicalDeviceGroupProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalBufferPropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalBufferInfo*   pExternalBufferInfo,
    VkExternalBufferProperties*                 pExternalBufferProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalBufferPropertiesKHR(physicalDevice, pExternalBufferInfo, pExternalBufferProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalBufferPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalBufferInfo);
        encode_struct_ptr(encoder, pExternalBufferProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalBufferPropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalBufferInfo, pExternalBufferProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleKHR(
    VkDevice                                    device,
    const VkMemoryGetWin32HandleInfoKHR*        pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    VkResult result = get_device_table(device)->GetMemoryWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandlePropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    HANDLE                                      handle,
    VkMemoryWin32HandlePropertiesKHR*           pMemoryWin32HandleProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(encode::TraceManager::Get(), device, handleType, handle, pMemoryWin32HandleProperties);

    VkResult result = get_device_table(device)->GetMemoryWin32HandlePropertiesKHR(device, handleType, handle, pMemoryWin32HandleProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryWin32HandlePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(handle);
        encode_struct_ptr(encoder, pMemoryWin32HandleProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryWin32HandlePropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, handleType, handle, pMemoryWin32HandleProperties);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdKHR(
    VkDevice                                    device,
    const VkMemoryGetFdInfoKHR*                 pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    VkResult result = get_device_table(device)->GetMemoryFdKHR(device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryFdPropertiesKHR(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    int                                         fd,
    VkMemoryFdPropertiesKHR*                    pMemoryFdProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryFdPropertiesKHR>::Dispatch(encode::TraceManager::Get(), device, handleType, fd, pMemoryFdProperties);

    VkResult result = get_device_table(device)->GetMemoryFdPropertiesKHR(device, handleType, fd, pMemoryFdProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryFdPropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeInt32Value(fd);
        encode_struct_ptr(encoder, pMemoryFdProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryFdPropertiesKHR>::Dispatch(encode::TraceManager::Get(), result, device, handleType, fd, pMemoryFdProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalSemaphorePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalSemaphoreInfo* pExternalSemaphoreInfo,
    VkExternalSemaphoreProperties*              pExternalSemaphoreProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalSemaphorePropertiesKHR(physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalSemaphoreInfo);
        encode_struct_ptr(encoder, pExternalSemaphoreProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalSemaphorePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalSemaphoreInfo, pExternalSemaphoreProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkImportSemaphoreWin32HandleInfoKHR*  pImportSemaphoreWin32HandleInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkImportSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pImportSemaphoreWin32HandleInfo);

    VkResult result = get_device_table(device)->ImportSemaphoreWin32HandleKHR(device, pImportSemaphoreWin32HandleInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkImportSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportSemaphoreWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkImportSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportSemaphoreWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreWin32HandleKHR(
    VkDevice                                    device,
    const VkSemaphoreGetWin32HandleInfoKHR*     pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    VkResult result = get_device_table(device)->GetSemaphoreWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetSemaphoreWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetSemaphoreWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL ImportSemaphoreFdKHR(
    VkDevice                                    device,
    const VkImportSemaphoreFdInfoKHR*           pImportSemaphoreFdInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkImportSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), device, pImportSemaphoreFdInfo);

    VkResult result = get_device_table(device)->ImportSemaphoreFdKHR(device, pImportSemaphoreFdInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkImportSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportSemaphoreFdInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkImportSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportSemaphoreFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSemaphoreFdKHR(
    VkDevice                                    device,
    const VkSemaphoreGetFdInfoKHR*              pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    VkResult result = get_device_table(device)->GetSemaphoreFdKHR(device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetSemaphoreFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetSemaphoreFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdPushDescriptorSetKHR(
    VkCommandBuffer                             commandBuffer,
    VkPipelineBindPoint                         pipelineBindPoint,
    VkPipelineLayout                            layout,
    uint32_t                                    set,
    uint32_t                                    descriptorWriteCount,
    const VkWriteDescriptorSet*                 pDescriptorWrites)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdPushDescriptorSetKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    get_device_table(commandBuffer)->CmdPushDescriptorSetKHR(commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdPushDescriptorSetKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineBindPoint);
        encoder->EncodeHandleIdValue(layout);
        encoder->EncodeUInt32Value(set);
        encoder->EncodeUInt32Value(descriptorWriteCount);
        encode_struct_array(encoder, pDescriptorWrites, descriptorWriteCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdPushDescriptorSetKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineBindPoint, layout, set, descriptorWriteCount, pDescriptorWrites);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateDescriptorUpdateTemplateKHR(device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDescriptorUpdateTemplateKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pDescriptorUpdateTemplate);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pDescriptorUpdateTemplate);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDescriptorUpdateTemplateKHR(
    VkDevice                                    device,
    VkDescriptorUpdateTemplate                  descriptorUpdateTemplate,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyDescriptorUpdateTemplateKHR(device, descriptorUpdateTemplate, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDescriptorUpdateTemplateKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(descriptorUpdateTemplate);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDescriptorUpdateTemplateKHR>::Dispatch(encode::TraceManager::Get(), device, descriptorUpdateTemplate, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateRenderPass2KHR(
    VkDevice                                    device,
    const VkRenderPassCreateInfo2KHR*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkRenderPass*                               pRenderPass)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pRenderPass);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateRenderPass2KHR(device, pCreateInfo, pAllocator, pRenderPass);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateRenderPass2KHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pRenderPass);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pRenderPass);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdBeginRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkRenderPassBeginInfo*                pRenderPassBegin,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBeginRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    get_device_table(commandBuffer)->CmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pRenderPassBegin);
        encode_struct_ptr(encoder, pSubpassBeginInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBeginRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdNextSubpass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassBeginInfoKHR*                pSubpassBeginInfo,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdNextSubpass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    get_device_table(commandBuffer)->CmdNextSubpass2KHR(commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdNextSubpass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pSubpassBeginInfo);
        encode_struct_ptr(encoder, pSubpassEndInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdNextSubpass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassBeginInfo, pSubpassEndInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndRenderPass2KHR(
    VkCommandBuffer                             commandBuffer,
    const VkSubpassEndInfoKHR*                  pSubpassEndInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdEndRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassEndInfo);

    get_device_table(commandBuffer)->CmdEndRenderPass2KHR(commandBuffer, pSubpassEndInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdEndRenderPass2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pSubpassEndInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdEndRenderPass2KHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSubpassEndInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainStatusKHR(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetSwapchainStatusKHR>::Dispatch(encode::TraceManager::Get(), device, swapchain);

    VkResult result = get_device_table(device)->GetSwapchainStatusKHR(device, swapchain);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetSwapchainStatusKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetSwapchainStatusKHR>::Dispatch(encode::TraceManager::Get(), result, device, swapchain);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceExternalFencePropertiesKHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceExternalFenceInfo*    pExternalFenceInfo,
    VkExternalFenceProperties*                  pExternalFenceProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceExternalFencePropertiesKHR(physicalDevice, pExternalFenceInfo, pExternalFenceProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalFencePropertiesKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pExternalFenceInfo);
        encode_struct_ptr(encoder, pExternalFenceProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalFencePropertiesKHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pExternalFenceInfo, pExternalFenceProperties);
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL ImportFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkImportFenceWin32HandleInfoKHR*      pImportFenceWin32HandleInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkImportFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pImportFenceWin32HandleInfo);

    VkResult result = get_device_table(device)->ImportFenceWin32HandleKHR(device, pImportFenceWin32HandleInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkImportFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportFenceWin32HandleInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkImportFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportFenceWin32HandleInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceWin32HandleKHR(
    VkDevice                                    device,
    const VkFenceGetWin32HandleInfoKHR*         pGetWin32HandleInfo,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), device, pGetWin32HandleInfo, pHandle);

    VkResult result = get_device_table(device)->GetFenceWin32HandleKHR(device, pGetWin32HandleInfo, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetFenceWin32HandleKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetWin32HandleInfo);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetFenceWin32HandleKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetWin32HandleInfo, pHandle);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

VKAPI_ATTR VkResult VKAPI_CALL ImportFenceFdKHR(
    VkDevice                                    device,
    const VkImportFenceFdInfoKHR*               pImportFenceFdInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkImportFenceFdKHR>::Dispatch(encode::TraceManager::Get(), device, pImportFenceFdInfo);

    VkResult result = get_device_table(device)->ImportFenceFdKHR(device, pImportFenceFdInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkImportFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pImportFenceFdInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkImportFenceFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pImportFenceFdInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetFenceFdKHR(
    VkDevice                                    device,
    const VkFenceGetFdInfoKHR*                  pGetFdInfo,
    int*                                        pFd)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetFenceFdKHR>::Dispatch(encode::TraceManager::Get(), device, pGetFdInfo, pFd);

    VkResult result = get_device_table(device)->GetFenceFdKHR(device, pGetFdInfo, pFd);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetFenceFdKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pGetFdInfo);
        encoder->EncodeInt32Ptr(pFd);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetFenceFdKHR>::Dispatch(encode::TraceManager::Get(), result, device, pGetFdInfo, pFd);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    VkSurfaceCapabilities2KHR*                  pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2KHR(physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pSurfaceInfo);
        encode_struct_ptr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceFormats2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR*      pSurfaceInfo,
    uint32_t*                                   pSurfaceFormatCount,
    VkSurfaceFormat2KHR*                        pSurfaceFormats)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceFormats2KHR(physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceFormats2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pSurfaceInfo);
        encoder->EncodeUInt32Ptr(pSurfaceFormatCount);
        encode_struct_array(encoder, pSurfaceFormats, (pSurfaceFormatCount != nullptr) ? (*pSurfaceFormatCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceFormats2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pSurfaceInfo, pSurfaceFormatCount, pSurfaceFormats);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayProperties2KHR*                    pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceDisplayProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceDisplayPlaneProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    uint32_t*                                   pPropertyCount,
    VkDisplayPlaneProperties2KHR*               pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pPropertyCount, pProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceDisplayPlaneProperties2KHR(physicalDevice, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceDisplayPlaneProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceDisplayPlaneProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayModeProperties2KHR(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display,
    uint32_t*                                   pPropertyCount,
    VkDisplayModeProperties2KHR*                pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDisplayModeProperties2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, display, pPropertyCount, pProperties);

    VkResult result = get_instance_table(physicalDevice)->GetDisplayModeProperties2KHR(physicalDevice, display, pPropertyCount, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayModeProperties2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeUInt32Ptr(pPropertyCount);
        encode_struct_array(encoder, pProperties, (pPropertyCount != nullptr) ? (*pPropertyCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDisplayModeProperties2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display, pPropertyCount, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetDisplayPlaneCapabilities2KHR(
    VkPhysicalDevice                            physicalDevice,
    const VkDisplayPlaneInfo2KHR*               pDisplayPlaneInfo,
    VkDisplayPlaneCapabilities2KHR*             pCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), physicalDevice, pDisplayPlaneInfo, pCapabilities);

    VkResult result = get_instance_table(physicalDevice)->GetDisplayPlaneCapabilities2KHR(physicalDevice, pDisplayPlaneInfo, pCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDisplayPlaneCapabilities2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pDisplayPlaneInfo);
        encode_struct_ptr(encoder, pCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDisplayPlaneCapabilities2KHR>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, pDisplayPlaneInfo, pCapabilities);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetImageMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageMemoryRequirementsInfo2*       pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    get_device_table(device)->GetImageMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetBufferMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkBufferMemoryRequirementsInfo2*      pInfo,
    VkMemoryRequirements2*                      pMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetBufferMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);

    get_device_table(device)->GetBufferMemoryRequirements2KHR(device, pInfo, pMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetBufferMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encode_struct_ptr(encoder, pMemoryRequirements);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetBufferMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pMemoryRequirements);
}

VKAPI_ATTR void VKAPI_CALL GetImageSparseMemoryRequirements2KHR(
    VkDevice                                    device,
    const VkImageSparseMemoryRequirementsInfo2* pInfo,
    uint32_t*                                   pSparseMemoryRequirementCount,
    VkSparseImageMemoryRequirements2*           pSparseMemoryRequirements)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    get_device_table(device)->GetImageSparseMemoryRequirements2KHR(device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetImageSparseMemoryRequirements2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encoder->EncodeUInt32Ptr(pSparseMemoryRequirementCount);
        encode_struct_array(encoder, pSparseMemoryRequirements, (pSparseMemoryRequirementCount != nullptr) ? (*pSparseMemoryRequirementCount) : 0);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetImageSparseMemoryRequirements2KHR>::Dispatch(encode::TraceManager::Get(), device, pInfo, pSparseMemoryRequirementCount, pSparseMemoryRequirements);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateSamplerYcbcrConversionKHR(
    VkDevice                                    device,
    const VkSamplerYcbcrConversionCreateInfo*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSamplerYcbcrConversion*                   pYcbcrConversion)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateSamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pYcbcrConversion);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateSamplerYcbcrConversionKHR(device, pCreateInfo, pAllocator, pYcbcrConversion);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateSamplerYcbcrConversionKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pYcbcrConversion);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateSamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pYcbcrConversion);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroySamplerYcbcrConversionKHR(
    VkDevice                                    device,
    VkSamplerYcbcrConversion                    ycbcrConversion,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroySamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroySamplerYcbcrConversionKHR(device, ycbcrConversion, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroySamplerYcbcrConversionKHR);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(ycbcrConversion);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroySamplerYcbcrConversionKHR>::Dispatch(encode::TraceManager::Get(), device, ycbcrConversion, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL BindBufferMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindBufferMemoryInfo*               pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBindBufferMemory2KHR>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = get_device_table(device)->BindBufferMemory2KHR(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBindBufferMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBindBufferMemory2KHR>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL BindImageMemory2KHR(
    VkDevice                                    device,
    uint32_t                                    bindInfoCount,
    const VkBindImageMemoryInfo*                pBindInfos)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkBindImageMemory2KHR>::Dispatch(encode::TraceManager::Get(), device, bindInfoCount, pBindInfos);

    VkResult result = get_device_table(device)->BindImageMemory2KHR(device, bindInfoCount, pBindInfos);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkBindImageMemory2KHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(bindInfoCount);
        encode_struct_array(encoder, pBindInfos, bindInfoCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkBindImageMemory2KHR>::Dispatch(encode::TraceManager::Get(), result, device, bindInfoCount, pBindInfos);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetDescriptorSetLayoutSupportKHR(
    VkDevice                                    device,
    const VkDescriptorSetLayoutCreateInfo*      pCreateInfo,
    VkDescriptorSetLayoutSupport*               pSupport)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);

    get_device_table(device)->GetDescriptorSetLayoutSupportKHR(device, pCreateInfo, pSupport);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetDescriptorSetLayoutSupportKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pCreateInfo);
        encode_struct_ptr(encoder, pSupport);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetDescriptorSetLayoutSupportKHR>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pSupport);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    get_device_table(commandBuffer)->CmdDrawIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountKHR(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    get_device_table(commandBuffer)->CmdDrawIndexedIndirectCountKHR(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexedIndirectCountKHR);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndexedIndirectCountKHR>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugReportCallbackEXT(
    VkInstance                                  instance,
    const VkDebugReportCallbackCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugReportCallbackEXT*                   pCallback)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pCallback);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateDebugReportCallbackEXT(instance, pCreateInfo, pAllocator, pCallback);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDebugReportCallbackEXT);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pCallback);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pCallback);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugReportCallbackEXT(
    VkInstance                                  instance,
    VkDebugReportCallbackEXT                    callback,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, callback, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_instance_table(instance)->DestroyDebugReportCallbackEXT(instance, callback, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDebugReportCallbackEXT);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encoder->EncodeHandleIdValue(callback);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDebugReportCallbackEXT>::Dispatch(encode::TraceManager::Get(), instance, callback, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL DebugReportMessageEXT(
    VkInstance                                  instance,
    VkDebugReportFlagsEXT                       flags,
    VkDebugReportObjectTypeEXT                  objectType,
    uint64_t                                    object,
    size_t                                      location,
    int32_t                                     messageCode,
    const char*                                 pLayerPrefix,
    const char*                                 pMessage)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDebugReportMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    get_instance_table(instance)->DebugReportMessageEXT(instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDebugReportMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeEnumValue(objectType);
        encoder->EncodeUInt64Value(object);
        encoder->EncodeSizeTValue(location);
        encoder->EncodeInt32Value(messageCode);
        encoder->EncodeString(pLayerPrefix);
        encoder->EncodeString(pMessage);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDebugReportMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, flags, objectType, object, location, messageCode, pLayerPrefix, pMessage);
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectTagEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectTagInfoEXT*        pTagInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDebugMarkerSetObjectTagEXT>::Dispatch(encode::TraceManager::Get(), device, pTagInfo);

    VkResult result = get_device_table(device)->DebugMarkerSetObjectTagEXT(device, pTagInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDebugMarkerSetObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDebugMarkerSetObjectTagEXT>::Dispatch(encode::TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DebugMarkerSetObjectNameEXT(
    VkDevice                                    device,
    const VkDebugMarkerObjectNameInfoEXT*       pNameInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDebugMarkerSetObjectNameEXT>::Dispatch(encode::TraceManager::Get(), device, pNameInfo);

    VkResult result = get_device_table(device)->DebugMarkerSetObjectNameEXT(device, pNameInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDebugMarkerSetObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDebugMarkerSetObjectNameEXT>::Dispatch(encode::TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerBeginEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDebugMarkerBeginEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);

    get_device_table(commandBuffer)->CmdDebugMarkerBeginEXT(commandBuffer, pMarkerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDebugMarkerBeginEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pMarkerInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDebugMarkerBeginEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerEndEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDebugMarkerEndEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    get_device_table(commandBuffer)->CmdDebugMarkerEndEXT(commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDebugMarkerEndEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDebugMarkerEndEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdDebugMarkerInsertEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugMarkerMarkerInfoEXT*           pMarkerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDebugMarkerInsertEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);

    get_device_table(commandBuffer)->CmdDebugMarkerInsertEXT(commandBuffer, pMarkerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDebugMarkerInsertEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pMarkerInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDebugMarkerInsertEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pMarkerInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    get_device_table(commandBuffer)->CmdDrawIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR void VKAPI_CALL CmdDrawIndexedIndirectCountAMD(
    VkCommandBuffer                             commandBuffer,
    VkBuffer                                    buffer,
    VkDeviceSize                                offset,
    VkBuffer                                    countBuffer,
    VkDeviceSize                                countBufferOffset,
    uint32_t                                    maxDrawCount,
    uint32_t                                    stride)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    get_device_table(commandBuffer)->CmdDrawIndexedIndirectCountAMD(commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdDrawIndexedIndirectCountAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeHandleIdValue(buffer);
        encoder->EncodeVkDeviceSizeValue(offset);
        encoder->EncodeHandleIdValue(countBuffer);
        encoder->EncodeVkDeviceSizeValue(countBufferOffset);
        encoder->EncodeUInt32Value(maxDrawCount);
        encoder->EncodeUInt32Value(stride);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdDrawIndexedIndirectCountAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, buffer, offset, countBuffer, countBufferOffset, maxDrawCount, stride);
}

VKAPI_ATTR VkResult VKAPI_CALL GetShaderInfoAMD(
    VkDevice                                    device,
    VkPipeline                                  pipeline,
    VkShaderStageFlagBits                       shaderStage,
    VkShaderInfoTypeAMD                         infoType,
    size_t*                                     pInfoSize,
    void*                                       pInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetShaderInfoAMD>::Dispatch(encode::TraceManager::Get(), device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    VkResult result = get_device_table(device)->GetShaderInfoAMD(device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetShaderInfoAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(pipeline);
        encoder->EncodeEnumValue(shaderStage);
        encoder->EncodeEnumValue(infoType);
        encoder->EncodeSizeTPtr(pInfoSize);
        encoder->EncodeVoidArray(pInfo, (pInfoSize != nullptr) ? (*pInfoSize) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetShaderInfoAMD>::Dispatch(encode::TraceManager::Get(), result, device, pipeline, shaderStage, infoType, pInfoSize, pInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceExternalImageFormatPropertiesNV(
    VkPhysicalDevice                            physicalDevice,
    VkFormat                                    format,
    VkImageType                                 type,
    VkImageTiling                               tiling,
    VkImageUsageFlags                           usage,
    VkImageCreateFlags                          flags,
    VkExternalMemoryHandleTypeFlagsNV           externalHandleType,
    VkExternalImageFormatPropertiesNV*          pExternalImageFormatProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(encode::TraceManager::Get(), physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceExternalImageFormatPropertiesNV(physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceExternalImageFormatPropertiesNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(format);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(tiling);
        encoder->EncodeFlagsValue(usage);
        encoder->EncodeFlagsValue(flags);
        encoder->EncodeFlagsValue(externalHandleType);
        encode_struct_ptr(encoder, pExternalImageFormatProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceExternalImageFormatPropertiesNV>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, format, type, tiling, usage, flags, externalHandleType, pExternalImageFormatProperties);

    return result;
}

#ifdef VK_USE_PLATFORM_WIN32_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetMemoryWin32HandleNV(
    VkDevice                                    device,
    VkDeviceMemory                              memory,
    VkExternalMemoryHandleTypeFlagsNV           handleType,
    HANDLE*                                     pHandle)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryWin32HandleNV>::Dispatch(encode::TraceManager::Get(), device, memory, handleType, pHandle);

    VkResult result = get_device_table(device)->GetMemoryWin32HandleNV(device, memory, handleType, pHandle);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryWin32HandleNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(memory);
        encoder->EncodeFlagsValue(handleType);
        encoder->EncodeVoidPtrPtr(pHandle);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryWin32HandleNV>::Dispatch(encode::TraceManager::Get(), result, device, memory, handleType, pHandle);

    return result;
}
#endif /* VK_USE_PLATFORM_WIN32_KHR */

#ifdef VK_USE_PLATFORM_VI_NN
VKAPI_ATTR VkResult VKAPI_CALL CreateViSurfaceNN(
    VkInstance                                  instance,
    const VkViSurfaceCreateInfoNN*              pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateViSurfaceNN>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateViSurfaceNN(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateViSurfaceNN);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateViSurfaceNN>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_VI_NN */

VKAPI_ATTR void VKAPI_CALL CmdBeginConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer,
    const VkConditionalRenderingBeginInfoEXT*   pConditionalRenderingBegin)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBeginConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);

    get_device_table(commandBuffer)->CmdBeginConditionalRenderingEXT(commandBuffer, pConditionalRenderingBegin);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pConditionalRenderingBegin);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBeginConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pConditionalRenderingBegin);
}

VKAPI_ATTR void VKAPI_CALL CmdEndConditionalRenderingEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdEndConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    get_device_table(commandBuffer)->CmdEndConditionalRenderingEXT(commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdEndConditionalRenderingEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdEndConditionalRenderingEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdProcessCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdProcessCommandsInfoNVX*          pProcessCommandsInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdProcessCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pProcessCommandsInfo);

    get_device_table(commandBuffer)->CmdProcessCommandsNVX(commandBuffer, pProcessCommandsInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdProcessCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pProcessCommandsInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdProcessCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pProcessCommandsInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdReserveSpaceForCommandsNVX(
    VkCommandBuffer                             commandBuffer,
    const VkCmdReserveSpaceForCommandsInfoNVX*  pReserveSpaceInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdReserveSpaceForCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pReserveSpaceInfo);

    get_device_table(commandBuffer)->CmdReserveSpaceForCommandsNVX(commandBuffer, pReserveSpaceInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdReserveSpaceForCommandsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pReserveSpaceInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdReserveSpaceForCommandsNVX>::Dispatch(encode::TraceManager::Get(), commandBuffer, pReserveSpaceInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    const VkIndirectCommandsLayoutCreateInfoNVX* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkIndirectCommandsLayoutNVX*                pIndirectCommandsLayout)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateIndirectCommandsLayoutNVX(device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateIndirectCommandsLayoutNVX);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pIndirectCommandsLayout);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pIndirectCommandsLayout);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyIndirectCommandsLayoutNVX(
    VkDevice                                    device,
    VkIndirectCommandsLayoutNVX                 indirectCommandsLayout,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, indirectCommandsLayout, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyIndirectCommandsLayoutNVX(device, indirectCommandsLayout, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyIndirectCommandsLayoutNVX);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(indirectCommandsLayout);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyIndirectCommandsLayoutNVX>::Dispatch(encode::TraceManager::Get(), device, indirectCommandsLayout, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateObjectTableNVX(
    VkDevice                                    device,
    const VkObjectTableCreateInfoNVX*           pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkObjectTableNVX*                           pObjectTable)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pObjectTable);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateObjectTableNVX(device, pCreateInfo, pAllocator, pObjectTable);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateObjectTableNVX);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pObjectTable);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateObjectTableNVX>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pObjectTable);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyObjectTableNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyObjectTableNVX(device, objectTable, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyObjectTableNVX);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(objectTable);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyObjectTableNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL UnregisterObjectsNVX(
    VkDevice                                    device,
    VkObjectTableNVX                            objectTable,
    uint32_t                                    objectCount,
    const VkObjectEntryTypeNVX*                 pObjectEntryTypes,
    const uint32_t*                             pObjectIndices)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkUnregisterObjectsNVX>::Dispatch(encode::TraceManager::Get(), device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    VkResult result = get_device_table(device)->UnregisterObjectsNVX(device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkUnregisterObjectsNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(objectTable);
        encoder->EncodeUInt32Value(objectCount);
        encoder->EncodeEnumArray(pObjectEntryTypes, objectCount);
        encoder->EncodeUInt32Array(pObjectIndices, objectCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkUnregisterObjectsNVX>::Dispatch(encode::TraceManager::Get(), result, device, objectTable, objectCount, pObjectEntryTypes, pObjectIndices);

    return result;
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceGeneratedCommandsPropertiesNVX(
    VkPhysicalDevice                            physicalDevice,
    VkDeviceGeneratedCommandsFeaturesNVX*       pFeatures,
    VkDeviceGeneratedCommandsLimitsNVX*         pLimits)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures, pLimits);

    get_instance_table(physicalDevice)->GetPhysicalDeviceGeneratedCommandsPropertiesNVX(physicalDevice, pFeatures, pLimits);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encode_struct_ptr(encoder, pFeatures);
        encode_struct_ptr(encoder, pLimits);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceGeneratedCommandsPropertiesNVX>::Dispatch(encode::TraceManager::Get(), physicalDevice, pFeatures, pLimits);
}

VKAPI_ATTR void VKAPI_CALL CmdSetViewportWScalingNV(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstViewport,
    uint32_t                                    viewportCount,
    const VkViewportWScalingNV*                 pViewportWScalings)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetViewportWScalingNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    get_device_table(commandBuffer)->CmdSetViewportWScalingNV(commandBuffer, firstViewport, viewportCount, pViewportWScalings);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetViewportWScalingNV);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstViewport);
        encoder->EncodeUInt32Value(viewportCount);
        encode_struct_array(encoder, pViewportWScalings, viewportCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetViewportWScalingNV>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstViewport, viewportCount, pViewportWScalings);
}

VKAPI_ATTR VkResult VKAPI_CALL ReleaseDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    VkDisplayKHR                                display)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkReleaseDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, display);

    VkResult result = get_instance_table(physicalDevice)->ReleaseDisplayEXT(physicalDevice, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkReleaseDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkReleaseDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, display);

    return result;
}

#ifdef VK_USE_PLATFORM_XLIB_XRANDR_EXT
VKAPI_ATTR VkResult VKAPI_CALL AcquireXlibDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    VkDisplayKHR                                display)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkAcquireXlibDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, dpy, display);

    VkResult result = get_instance_table(physicalDevice)->AcquireXlibDisplayEXT(physicalDevice, dpy, display);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkAcquireXlibDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeHandleIdValue(display);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkAcquireXlibDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, dpy, display);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRandROutputDisplayEXT(
    VkPhysicalDevice                            physicalDevice,
    Display*                                    dpy,
    RROutput                                    rrOutput,
    VkDisplayKHR*                               pDisplay)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetRandROutputDisplayEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, dpy, rrOutput, pDisplay);

    VkResult result = get_instance_table(physicalDevice)->GetRandROutputDisplayEXT(physicalDevice, dpy, rrOutput, pDisplay);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetRandROutputDisplayEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeVoidPtr(dpy);
        encoder->EncodeUInt32Value(rrOutput);
        encoder->EncodeHandleIdPtr(pDisplay);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetRandROutputDisplayEXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, dpy, rrOutput, pDisplay);

    return result;
}
#endif /* VK_USE_PLATFORM_XLIB_XRANDR_EXT */

VKAPI_ATTR VkResult VKAPI_CALL GetPhysicalDeviceSurfaceCapabilities2EXT(
    VkPhysicalDevice                            physicalDevice,
    VkSurfaceKHR                                surface,
    VkSurfaceCapabilities2EXT*                  pSurfaceCapabilities)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, surface, pSurfaceCapabilities);

    VkResult result = get_instance_table(physicalDevice)->GetPhysicalDeviceSurfaceCapabilities2EXT(physicalDevice, surface, pSurfaceCapabilities);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2EXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeHandleIdValue(surface);
        encode_struct_ptr(encoder, pSurfaceCapabilities);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceSurfaceCapabilities2EXT>::Dispatch(encode::TraceManager::Get(), result, physicalDevice, surface, pSurfaceCapabilities);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL DisplayPowerControlEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayPowerInfoEXT*                pDisplayPowerInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDisplayPowerControlEXT>::Dispatch(encode::TraceManager::Get(), device, display, pDisplayPowerInfo);

    VkResult result = get_device_table(device)->DisplayPowerControlEXT(device, display, pDisplayPowerInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDisplayPowerControlEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        encode_struct_ptr(encoder, pDisplayPowerInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDisplayPowerControlEXT>::Dispatch(encode::TraceManager::Get(), result, device, display, pDisplayPowerInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDeviceEventEXT(
    VkDevice                                    device,
    const VkDeviceEventInfoEXT*                 pDeviceEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkRegisterDeviceEventEXT>::Dispatch(encode::TraceManager::Get(), device, pDeviceEventInfo, pAllocator, pFence);

    VkResult result = get_device_table(device)->RegisterDeviceEventEXT(device, pDeviceEventInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkRegisterDeviceEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pDeviceEventInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkRegisterDeviceEventEXT>::Dispatch(encode::TraceManager::Get(), result, device, pDeviceEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL RegisterDisplayEventEXT(
    VkDevice                                    device,
    VkDisplayKHR                                display,
    const VkDisplayEventInfoEXT*                pDisplayEventInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkFence*                                    pFence)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkRegisterDisplayEventEXT>::Dispatch(encode::TraceManager::Get(), device, display, pDisplayEventInfo, pAllocator, pFence);

    VkResult result = get_device_table(device)->RegisterDisplayEventEXT(device, display, pDisplayEventInfo, pAllocator, pFence);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkRegisterDisplayEventEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(display);
        encode_struct_ptr(encoder, pDisplayEventInfo);
        encode_struct_ptr(encoder, pAllocator);
        encoder->EncodeHandleIdPtr(pFence);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkRegisterDisplayEventEXT>::Dispatch(encode::TraceManager::Get(), result, device, display, pDisplayEventInfo, pAllocator, pFence);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetSwapchainCounterEXT(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkSurfaceCounterFlagBitsEXT                 counter,
    uint64_t*                                   pCounterValue)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetSwapchainCounterEXT>::Dispatch(encode::TraceManager::Get(), device, swapchain, counter, pCounterValue);

    VkResult result = get_device_table(device)->GetSwapchainCounterEXT(device, swapchain, counter, pCounterValue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetSwapchainCounterEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeEnumValue(counter);
        encoder->EncodeUInt64Ptr(pCounterValue);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetSwapchainCounterEXT>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, counter, pCounterValue);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetRefreshCycleDurationGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    VkRefreshCycleDurationGOOGLE*               pDisplayTimingProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetRefreshCycleDurationGOOGLE>::Dispatch(encode::TraceManager::Get(), device, swapchain, pDisplayTimingProperties);

    VkResult result = get_device_table(device)->GetRefreshCycleDurationGOOGLE(device, swapchain, pDisplayTimingProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetRefreshCycleDurationGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encode_struct_ptr(encoder, pDisplayTimingProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetRefreshCycleDurationGOOGLE>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pDisplayTimingProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetPastPresentationTimingGOOGLE(
    VkDevice                                    device,
    VkSwapchainKHR                              swapchain,
    uint32_t*                                   pPresentationTimingCount,
    VkPastPresentationTimingGOOGLE*             pPresentationTimings)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPastPresentationTimingGOOGLE>::Dispatch(encode::TraceManager::Get(), device, swapchain, pPresentationTimingCount, pPresentationTimings);

    VkResult result = get_device_table(device)->GetPastPresentationTimingGOOGLE(device, swapchain, pPresentationTimingCount, pPresentationTimings);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPastPresentationTimingGOOGLE);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(swapchain);
        encoder->EncodeUInt32Ptr(pPresentationTimingCount);
        encode_struct_array(encoder, pPresentationTimings, (pPresentationTimingCount != nullptr) ? (*pPresentationTimingCount) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPastPresentationTimingGOOGLE>::Dispatch(encode::TraceManager::Get(), result, device, swapchain, pPresentationTimingCount, pPresentationTimings);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdSetDiscardRectangleEXT(
    VkCommandBuffer                             commandBuffer,
    uint32_t                                    firstDiscardRectangle,
    uint32_t                                    discardRectangleCount,
    const VkRect2D*                             pDiscardRectangles)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetDiscardRectangleEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    get_device_table(commandBuffer)->CmdSetDiscardRectangleEXT(commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetDiscardRectangleEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeUInt32Value(firstDiscardRectangle);
        encoder->EncodeUInt32Value(discardRectangleCount);
        encode_struct_array(encoder, pDiscardRectangles, discardRectangleCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetDiscardRectangleEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, firstDiscardRectangle, discardRectangleCount, pDiscardRectangles);
}

VKAPI_ATTR void VKAPI_CALL SetHdrMetadataEXT(
    VkDevice                                    device,
    uint32_t                                    swapchainCount,
    const VkSwapchainKHR*                       pSwapchains,
    const VkHdrMetadataEXT*                     pMetadata)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkSetHdrMetadataEXT>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);

    get_device_table(device)->SetHdrMetadataEXT(device, swapchainCount, pSwapchains, pMetadata);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkSetHdrMetadataEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeUInt32Value(swapchainCount);
        encoder->EncodeHandleIdArray(pSwapchains, swapchainCount);
        encode_struct_array(encoder, pMetadata, swapchainCount);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkSetHdrMetadataEXT>::Dispatch(encode::TraceManager::Get(), device, swapchainCount, pSwapchains, pMetadata);
}

#ifdef VK_USE_PLATFORM_IOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL CreateIOSSurfaceMVK(
    VkInstance                                  instance,
    const VkIOSSurfaceCreateInfoMVK*            pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateIOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateIOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateIOSSurfaceMVK);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateIOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_IOS_MVK */

#ifdef VK_USE_PLATFORM_MACOS_MVK
VKAPI_ATTR VkResult VKAPI_CALL CreateMacOSSurfaceMVK(
    VkInstance                                  instance,
    const VkMacOSSurfaceCreateInfoMVK*          pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkSurfaceKHR*                               pSurface)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateMacOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pSurface);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateMacOSSurfaceMVK(instance, pCreateInfo, pAllocator, pSurface);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateMacOSSurfaceMVK);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pSurface);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateMacOSSurfaceMVK>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pSurface);

    return result;
}
#endif /* VK_USE_PLATFORM_MACOS_MVK */

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectNameEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectNameInfoEXT*        pNameInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkSetDebugUtilsObjectNameEXT>::Dispatch(encode::TraceManager::Get(), device, pNameInfo);

    VkResult result = get_device_table(device)->SetDebugUtilsObjectNameEXT(device, pNameInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkSetDebugUtilsObjectNameEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pNameInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkSetDebugUtilsObjectNameEXT>::Dispatch(encode::TraceManager::Get(), result, device, pNameInfo);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL SetDebugUtilsObjectTagEXT(
    VkDevice                                    device,
    const VkDebugUtilsObjectTagInfoEXT*         pTagInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkSetDebugUtilsObjectTagEXT>::Dispatch(encode::TraceManager::Get(), device, pTagInfo);

    VkResult result = get_device_table(device)->SetDebugUtilsObjectTagEXT(device, pTagInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkSetDebugUtilsObjectTagEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pTagInfo);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkSetDebugUtilsObjectTagEXT>::Dispatch(encode::TraceManager::Get(), result, device, pTagInfo);

    return result;
}

VKAPI_ATTR void VKAPI_CALL QueueBeginDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);

    get_device_table(queue)->QueueBeginDebugUtilsLabelEXT(queue, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueueBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode_struct_ptr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueueBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL QueueEndDebugUtilsLabelEXT(
    VkQueue                                     queue)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueueEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue);

    get_device_table(queue)->QueueEndDebugUtilsLabelEXT(queue);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueueEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueueEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue);
}

VKAPI_ATTR void VKAPI_CALL QueueInsertDebugUtilsLabelEXT(
    VkQueue                                     queue,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);

    get_device_table(queue)->QueueInsertDebugUtilsLabelEXT(queue, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkQueueInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(queue);
        encode_struct_ptr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkQueueInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), queue, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdBeginDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);

    get_device_table(commandBuffer)->CmdBeginDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdBeginDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdBeginDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR void VKAPI_CALL CmdEndDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);

    get_device_table(commandBuffer)->CmdEndDebugUtilsLabelEXT(commandBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdEndDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdEndDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer);
}

VKAPI_ATTR void VKAPI_CALL CmdInsertDebugUtilsLabelEXT(
    VkCommandBuffer                             commandBuffer,
    const VkDebugUtilsLabelEXT*                 pLabelInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);

    get_device_table(commandBuffer)->CmdInsertDebugUtilsLabelEXT(commandBuffer, pLabelInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdInsertDebugUtilsLabelEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pLabelInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdInsertDebugUtilsLabelEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pLabelInfo);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    const VkDebugUtilsMessengerCreateInfoEXT*   pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDebugUtilsMessengerEXT*                   pMessenger)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, pCreateInfo, pAllocator, pMessenger);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_instance_table(instance)->CreateDebugUtilsMessengerEXT(instance, pCreateInfo, pAllocator, pMessenger);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateDebugUtilsMessengerEXT);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pMessenger);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), result, instance, pCreateInfo, pAllocator, pMessenger);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyDebugUtilsMessengerEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessengerEXT                    messenger,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, messenger, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_instance_table(instance)->DestroyDebugUtilsMessengerEXT(instance, messenger, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyDebugUtilsMessengerEXT);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(instance);
            encoder->EncodeHandleIdValue(messenger);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyDebugUtilsMessengerEXT>::Dispatch(encode::TraceManager::Get(), instance, messenger, pAllocator);
}

VKAPI_ATTR void VKAPI_CALL SubmitDebugUtilsMessageEXT(
    VkInstance                                  instance,
    VkDebugUtilsMessageSeverityFlagBitsEXT      messageSeverity,
    VkDebugUtilsMessageTypeFlagsEXT             messageTypes,
    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkSubmitDebugUtilsMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);

    get_instance_table(instance)->SubmitDebugUtilsMessageEXT(instance, messageSeverity, messageTypes, pCallbackData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkSubmitDebugUtilsMessageEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(instance);
        encoder->EncodeEnumValue(messageSeverity);
        encoder->EncodeFlagsValue(messageTypes);
        encode_struct_ptr(encoder, pCallbackData);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkSubmitDebugUtilsMessageEXT>::Dispatch(encode::TraceManager::Get(), instance, messageSeverity, messageTypes, pCallbackData);
}

#ifdef VK_USE_PLATFORM_ANDROID_KHR
VKAPI_ATTR VkResult VKAPI_CALL GetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                    device,
    const struct AHardwareBuffer*               buffer,
    VkAndroidHardwareBufferPropertiesANDROID*   pProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(encode::TraceManager::Get(), device, buffer, pProperties);

    VkResult result = get_device_table(device)->GetAndroidHardwareBufferPropertiesANDROID(device, buffer, pProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetAndroidHardwareBufferPropertiesANDROID);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeVoidPtr(buffer);
        encode_struct_ptr(encoder, pProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetAndroidHardwareBufferPropertiesANDROID>::Dispatch(encode::TraceManager::Get(), result, device, buffer, pProperties);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryAndroidHardwareBufferANDROID(
    VkDevice                                    device,
    const VkMemoryGetAndroidHardwareBufferInfoANDROID* pInfo,
    struct AHardwareBuffer**                    pBuffer)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(encode::TraceManager::Get(), device, pInfo, pBuffer);

    VkResult result = get_device_table(device)->GetMemoryAndroidHardwareBufferANDROID(device, pInfo, pBuffer);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryAndroidHardwareBufferANDROID);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encode_struct_ptr(encoder, pInfo);
        encoder->EncodeVoidPtrPtr(pBuffer);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryAndroidHardwareBufferANDROID>::Dispatch(encode::TraceManager::Get(), result, device, pInfo, pBuffer);

    return result;
}
#endif /* VK_USE_PLATFORM_ANDROID_KHR */

VKAPI_ATTR void VKAPI_CALL CmdSetSampleLocationsEXT(
    VkCommandBuffer                             commandBuffer,
    const VkSampleLocationsInfoEXT*             pSampleLocationsInfo)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdSetSampleLocationsEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSampleLocationsInfo);

    get_device_table(commandBuffer)->CmdSetSampleLocationsEXT(commandBuffer, pSampleLocationsInfo);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdSetSampleLocationsEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encode_struct_ptr(encoder, pSampleLocationsInfo);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdSetSampleLocationsEXT>::Dispatch(encode::TraceManager::Get(), commandBuffer, pSampleLocationsInfo);
}

VKAPI_ATTR void VKAPI_CALL GetPhysicalDeviceMultisamplePropertiesEXT(
    VkPhysicalDevice                            physicalDevice,
    VkSampleCountFlagBits                       samples,
    VkMultisamplePropertiesEXT*                 pMultisampleProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);

    get_instance_table(physicalDevice)->GetPhysicalDeviceMultisamplePropertiesEXT(physicalDevice, samples, pMultisampleProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetPhysicalDeviceMultisamplePropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(physicalDevice);
        encoder->EncodeEnumValue(samples);
        encode_struct_ptr(encoder, pMultisampleProperties);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetPhysicalDeviceMultisamplePropertiesEXT>::Dispatch(encode::TraceManager::Get(), physicalDevice, samples, pMultisampleProperties);
}

VKAPI_ATTR VkResult VKAPI_CALL CreateValidationCacheEXT(
    VkDevice                                    device,
    const VkValidationCacheCreateInfoEXT*       pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkValidationCacheEXT*                       pValidationCache)
{
    VkResult result;

    encode::CustomEncoderPreCall<format::ApiCallId_vkCreateValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, pCreateInfo, pAllocator, pValidationCache);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        result = get_device_table(device)->CreateValidationCacheEXT(device, pCreateInfo, pAllocator, pValidationCache);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCreateValidationCacheEXT);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encode_struct_ptr(encoder, pCreateInfo);
            encode_struct_ptr(encoder, pAllocator);
            encoder->EncodeHandleIdPtr(pValidationCache);
            encoder->EncodeEnumValue(result);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCreateValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), result, device, pCreateInfo, pAllocator, pValidationCache);

    return result;
}

VKAPI_ATTR void VKAPI_CALL DestroyValidationCacheEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    const VkAllocationCallbacks*                pAllocator)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkDestroyValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pAllocator);

    {
        std::lock_guard<std::mutex> create_destroy_lock(g_create_destroy_mutex);

        get_device_table(device)->DestroyValidationCacheEXT(device, validationCache, pAllocator);

        auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkDestroyValidationCacheEXT);
        if (encoder)
        {
            encoder->EncodeHandleIdValue(device);
            encoder->EncodeHandleIdValue(validationCache);
            encode_struct_ptr(encoder, pAllocator);
            encode::TraceManager::Get()->EndApiCallTrace(encoder);
        }
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkDestroyValidationCacheEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pAllocator);
}

VKAPI_ATTR VkResult VKAPI_CALL MergeValidationCachesEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        dstCache,
    uint32_t                                    srcCacheCount,
    const VkValidationCacheEXT*                 pSrcCaches)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkMergeValidationCachesEXT>::Dispatch(encode::TraceManager::Get(), device, dstCache, srcCacheCount, pSrcCaches);

    VkResult result = get_device_table(device)->MergeValidationCachesEXT(device, dstCache, srcCacheCount, pSrcCaches);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkMergeValidationCachesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(dstCache);
        encoder->EncodeUInt32Value(srcCacheCount);
        encoder->EncodeHandleIdArray(pSrcCaches, srcCacheCount);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkMergeValidationCachesEXT>::Dispatch(encode::TraceManager::Get(), result, device, dstCache, srcCacheCount, pSrcCaches);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetValidationCacheDataEXT(
    VkDevice                                    device,
    VkValidationCacheEXT                        validationCache,
    size_t*                                     pDataSize,
    void*                                       pData)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetValidationCacheDataEXT>::Dispatch(encode::TraceManager::Get(), device, validationCache, pDataSize, pData);

    VkResult result = get_device_table(device)->GetValidationCacheDataEXT(device, validationCache, pDataSize, pData);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetValidationCacheDataEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeHandleIdValue(validationCache);
        encoder->EncodeSizeTPtr(pDataSize);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? (*pDataSize) : 0);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetValidationCacheDataEXT>::Dispatch(encode::TraceManager::Get(), result, device, validationCache, pDataSize, pData);

    return result;
}

VKAPI_ATTR VkResult VKAPI_CALL GetMemoryHostPointerPropertiesEXT(
    VkDevice                                    device,
    VkExternalMemoryHandleTypeFlagBits          handleType,
    const void*                                 pHostPointer,
    VkMemoryHostPointerPropertiesEXT*           pMemoryHostPointerProperties)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(encode::TraceManager::Get(), device, handleType, pHostPointer, pMemoryHostPointerProperties);

    VkResult result = get_device_table(device)->GetMemoryHostPointerPropertiesEXT(device, handleType, pHostPointer, pMemoryHostPointerProperties);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkGetMemoryHostPointerPropertiesEXT);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(device);
        encoder->EncodeEnumValue(handleType);
        encoder->EncodeVoidPtr(pHostPointer);
        encode_struct_ptr(encoder, pMemoryHostPointerProperties);
        encoder->EncodeEnumValue(result);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkGetMemoryHostPointerPropertiesEXT>::Dispatch(encode::TraceManager::Get(), result, device, handleType, pHostPointer, pMemoryHostPointerProperties);

    return result;
}

VKAPI_ATTR void VKAPI_CALL CmdWriteBufferMarkerAMD(
    VkCommandBuffer                             commandBuffer,
    VkPipelineStageFlagBits                     pipelineStage,
    VkBuffer                                    dstBuffer,
    VkDeviceSize                                dstOffset,
    uint32_t                                    marker)
{
    encode::CustomEncoderPreCall<format::ApiCallId_vkCmdWriteBufferMarkerAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    get_device_table(commandBuffer)->CmdWriteBufferMarkerAMD(commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);

    auto encoder = encode::TraceManager::Get()->BeginApiCallTrace(format::ApiCallId_vkCmdWriteBufferMarkerAMD);
    if (encoder)
    {
        encoder->EncodeHandleIdValue(commandBuffer);
        encoder->EncodeEnumValue(pipelineStage);
        encoder->EncodeHandleIdValue(dstBuffer);
        encoder->EncodeVkDeviceSizeValue(dstOffset);
        encoder->EncodeUInt32Value(marker);
        encode::TraceManager::Get()->EndApiCallTrace(encoder);
    }

    encode::CustomEncoderPostCall<format::ApiCallId_vkCmdWriteBufferMarkerAMD>::Dispatch(encode::TraceManager::Get(), commandBuffer, pipelineStage, dstBuffer, dstOffset, marker);
}

BRIMSTONE_END_NAMESPACE(brimstone)
