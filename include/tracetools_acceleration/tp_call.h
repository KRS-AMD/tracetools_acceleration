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

// Provide fake header guard for cpplint
#undef TRACETOOLS__TP_CALL_H_
#ifndef TRACETOOLS__TP_CALL_H_
#define TRACETOOLS__TP_CALL_H_

#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER ros2_acceleration

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "tracetools_acceleration/tp_call.h"

#if !defined(_TRACETOOLS__TP_CALL_H_) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TRACETOOLS__TP_CALL_H_

#include <lttng/tracepoint.h>

#include <stdint.h>
#include <stdbool.h>

#define DATA_SIZE 4096  // 2**12

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,  // tracepoint provider name
  vadd_pre_simple,      // tracepoint name
  TP_ARGS(              // input arguments, see https://lttng.org/docs/v2.12/#doc-tpp-def-input-args
  ),
  TP_FIELDS(            // output event fields, see https://lttng.org/man/3/lttng-ust/v2.12/#doc-ctf-macros
    ctf_string(version, tracetools_acceleration_VERSION)
  )
)

TRACEPOINT_EVENT(
  TRACEPOINT_PROVIDER,
  vadd_pre,
  TP_ARGS(
    const unsigned int *, in1_arg,
    const unsigned int *, in2_arg,
    const unsigned int *, out_arg
  ),
  TP_FIELDS(
    ctf_array(const unsigned int *, in1, in1_arg, DATA_SIZE)
    ctf_array(const unsigned int *, in2, in2_arg, DATA_SIZE)
    ctf_array(const unsigned int *, out, out_arg, DATA_SIZE)
  )
)

#endif  // _TRACETOOLS__TP_CALL_H_

#include <lttng/tracepoint-event.h>

#endif  // TRACETOOLS__TP_CALL_H_
