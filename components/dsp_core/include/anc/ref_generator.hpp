#pragma once

#include <cmath>

namespace anc {

class RefGenerator {
public:
    explicit RefGenerator(float sampleRateHz)
        : sampleRateHz_(sampleRateHz) {}

    void setFrequency(float freqHz) {
        phaseStep_ = kTwoPi * freqHz / sampleRateHz_;
    }

    void next(float& sinOut, float& cosOut) {
        sinOut = std::sin(phase_);
        cosOut = std::cos(phase_);
        phase_ += phaseStep_;
        if (phase_ >= kTwoPi) {
            phase_ -= kTwoPi;
        }
    }

private:
    static constexpr float kTwoPi = 6.28318530717958647692f;

    float sampleRateHz_;
    float phase_ = 0.0f;
    float phaseStep_ = 0.0f;
};

}  // namespace anc
