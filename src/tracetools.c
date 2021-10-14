//     ____  ____
//    /   /\/   /
//   /___/  \  /   Copyright (c) 2021, Xilinx®.
//   \   \   \/    Author: Víctor Mayoral Vilches <victorma@xilinx.com>
//    \   \
//    /   /
//   /___/   /\
//   \   \  /  \
//    \___\/\___\
//
// Inspired by https://gitlab.com/ros-tracing/ros2_tracing
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "tracetools_acceleration/tracetools.h"

#ifndef TRACETOOLS_DISABLED

#ifdef TRACETOOLS_LTTNG_ENABLED
# include "tracetools_acceleration/tp_call.h"
# define CONDITIONAL_TP(...) \
  tracepoint(TRACEPOINT_PROVIDER, __VA_ARGS__)
#else
# define CONDITIONAL_TP(...)
#endif

bool ros_trace_compile_status()
{
#ifdef TRACETOOLS_LTTNG_ENABLED
  return true;
#else
  return false;
#endif
}

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
#else
# pragma warning(push)
# pragma warning(disable: 4100)
#endif

void TRACEPOINT(
  vadd_pre)
{
  CONDITIONAL_TP(
    vadd_pre);
}

void TRACEPOINT(
  vadd_post)
{
  CONDITIONAL_TP(
    vadd_post);
}

#ifndef _WIN32
# pragma GCC diagnostic pop
#else
# pragma warning(pop)
#endif

#endif  // TRACETOOLS_DISABLED
