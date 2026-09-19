//==========================================================================================================
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Vinny Parla
// File: include/logging/LogHandler.h
// Purpose: Configure an embedding application callback for SDK log messages.
//==========================================================================================================
#pragma once

#include <functional>
#include <string_view>

namespace mcp::logging {

using LogHandler = std::function<void(std::string_view level,
                                      std::string_view message,
                                      std::string_view file,
                                      unsigned int line)>;

// Route SDK logs through an embedding application's logger. When a handler is
// installed, the SDK's built-in console and file output are bypassed.
void
SetLogHandler(LogHandler handler);

} // namespace mcp::logging
