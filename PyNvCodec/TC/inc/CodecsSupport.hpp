/*
 * Copyright 2019 NVIDIA Corporation
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *    http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once
#include "MemoryInterfaces.hpp"
#include "cuviddec.h"
#include <stdint.h>

struct PacketData {
  int64_t pts;
  int64_t dts;
  uint64_t pos;
  uint64_t duration;
};

struct VideoContext {
  uint32_t width;
  uint32_t height;
  double frameRate;
  double timeBase;
  uint32_t streamIndex;
  cudaVideoCodec codec;
  PacketData packetData;
  Pixel_Format format;
};

struct AudioContext {
  // Reserved for future use;
};

struct MuxingParams {
  VideoContext videoContext;
  AudioContext audioContext;
};