//==========================================================================================================
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Vinny Parla
// File: Logger.cpp
// Purpose: Definitions for Logger static members.
//==========================================================================================================

#include "logging/Logger.h"

#include <utility>

// Define static members
LogLevel Logger::sLogLevel = LogLevel::LOG_INFO_LEVEL;
std::ofstream Logger::sLogFile;
std::mutex Logger::sLogMutex;
mcp::logging::LogHandler Logger::sLogHandler;

namespace mcp::logging {

void
SetLogHandler(LogHandler handler)
{
    Logger::setLogHandler(std::move(handler));
}

} // namespace mcp::logging
