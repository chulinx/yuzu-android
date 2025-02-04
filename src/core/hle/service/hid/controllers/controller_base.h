// SPDX-FileCopyrightText: Copyright 2018 yuzu Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/common_types.h"
#include "core/hle/result.h"

namespace Core::Timing {
class CoreTiming;
}

namespace Core::HID {
class HIDCore;
}

namespace Service::HID {
class ControllerBase {
public:
    explicit ControllerBase(Core::HID::HIDCore& hid_core_);
    virtual ~ControllerBase();

    // Called when the controller is initialized
    virtual void OnInit() = 0;

    // When the controller is released
    virtual void OnRelease() = 0;

    // When the controller is requesting an update for the shared memory
    virtual void OnUpdate(const Core::Timing::CoreTiming& core_timing) = 0;

    // When the controller is requesting a motion update for the shared memory
    virtual void OnMotionUpdate(const Core::Timing::CoreTiming& core_timing) {}

    Result Activate();
    Result Activate(u64 aruid);

    void DeactivateController();

    bool IsControllerActivated() const;

protected:
    bool is_activated{false};

    Core::HID::HIDCore& hid_core;
};
} // namespace Service::HID
