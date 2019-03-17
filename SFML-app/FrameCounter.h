#pragma once
#include <chrono>

class FrameCounter {
	const unsigned m_targetFps;
	const double m_targetFrameDuration;

	unsigned m_elapsedFrames = 0;
	std::chrono::steady_clock::time_point m_lastTime = std::chrono::high_resolution_clock::now();

public:

	FrameCounter(unsigned fps)
		: m_targetFps(fps), m_targetFrameDuration(1.0/fps)
	{}

	double frame_duration() const {
		return m_targetFrameDuration;
	}

	unsigned total_elapsed_frames()  const {
		return m_elapsedFrames;
	}

	void tick() {
		++m_elapsedFrames;
	}

	bool next_frame() {
		const auto now = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> delta = now - m_lastTime;
		const auto seconds = delta.count();

		if (seconds > m_targetFrameDuration) {
			++m_elapsedFrames;
			m_lastTime = now;
			return true;
		}
		return false;
	}
};