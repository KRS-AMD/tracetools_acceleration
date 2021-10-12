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

/** \mainpage tracetools: tracing tools and instrumentation for ROS 2
 *
 * `tracetools` provides utilities to instrument ROS.
 * It provides two main headers:
 *
 * - tracetools/tracetools.h
 *   - instrumentation functions
 * - tracetools/utils.hpp
 *   - utility functions
 */

#ifndef TRACETOOLS_ACCELERATION__TRACETOOLS_H_
#define TRACETOOLS_ACCELERATION__TRACETOOLS_H_

#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "tracetools_acceleration/config.h"
#include "tracetools_acceleration/visibility_control.hpp"

#ifndef TRACETOOLS_DISABLED
/// Call a tracepoint.
/**
 * This is the preferred method over calling the actual function directly.
 */
#  define TRACEPOINT(event_name, ...) \
  (ros_trace_ ## event_name)(__VA_ARGS__)
#  define DECLARE_TRACEPOINT(event_name, ...) \
  TRACETOOLS_PUBLIC void ros_trace_ ## event_name(__VA_ARGS__);
#else
#  define TRACEPOINT(event_name, ...) ((void) (0))
#  define DECLARE_TRACEPOINT(event_name, ...)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/// Get tracing compilation status.
/**
 * \return `true` if tracing is enabled, `false` otherwise
 */
TRACETOOLS_PUBLIC bool ros_trace_compile_status();

/// `vadd_pre_simple`
/**
 * Initialisation for the whole process.
 * Notes the `tracetools` version automatically.
 */
DECLARE_TRACEPOINT(
  vadd_pre_simple)

/// `vadd_pre`
/**
 * Node initialisation.
 * Links a `rcl_node_t` handle to its `rmw_node_t` handle.
 *
 * \param[in] node_handle pointer to the node's `rcl_node_t` handle
 * \param[in] rmw_handle pointer to the node's `rmw_node_t` handle
 * \param[in] node_name node name
 * \param[in] node_namespace node namespace
 */
DECLARE_TRACEPOINT(
  vadd_pre,
  const unsigned int * in1,
  const unsigned int * in2,
  const unsigned int * out)


#ifdef __cplusplus
}
#endif

#endif  // TRACETOOLS_ACCELERATION__TRACETOOLS_H_
