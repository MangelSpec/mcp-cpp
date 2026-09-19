//==========================================================================================================
// SPDX-License-Identifier: MIT
// Copyright (c) 2025 Vinny Parla
// File: tests/test_log_handler.cpp
// Purpose: Verify that SDK log messages can be routed through an embedding application callback.
//==========================================================================================================

#include "logging/LogHandler.h"
#include "logging/Logger.h"

#include <gtest/gtest.h>

#include <string>

namespace {

class LogHandlerReset final {
public:
    ~LogHandlerReset() { mcp::logging::SetLogHandler({}); }
};

TEST(LogHandler, RoutesMessageMetadataToEmbeddingCallback) {
    const LogHandlerReset reset;
    std::string level;
    std::string message;
    std::string file;
    unsigned int line = 0;

    mcp::logging::SetLogHandler(
        [&](std::string_view receivedLevel,
            std::string_view receivedMessage,
            std::string_view receivedFile,
            unsigned int receivedLine) {
            level = receivedLevel;
            message = receivedMessage;
            file = receivedFile;
            line = receivedLine;
        });

    Logger::log("WARN", "routed message", "source.cpp", 42);

    EXPECT_EQ(level, "WARN");
    EXPECT_EQ(message, "routed message");
    EXPECT_EQ(file, "source.cpp");
    EXPECT_EQ(line, 42U);
}

} // namespace
