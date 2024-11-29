#ifndef SOUND_H
#define SOUND_H

#include <math.h>

namespace sound {
	#define TWO_PI 6.283185307
	#define SAMPLE_RATE 44100
	#define MAX_AMPLITUDE 32767
	
	short SineWave (double time, double freq, double amp) {
		// Calculate angular frequency
		double omega = TWO_PI * freq / SAMPLE_RATE;
		
		// Calculate amplitude
		double amplitude = (short)(MAX_AMPLITUDE * amp);
		
		// Result as sine of phase angle
		return (short)(amplitude * sin(omega * time));
	}
	
	short SquareWave (double time, double freq, double amp) {
		// Ticks per cycle and amplitude
		double tcp = SAMPLE_RATE / freq;
		double amplitude = (short)(MAX_AMPLITUDE * amp);

		// Determine position in the cycle and return amplitude accordingly
		return (fmod(time, tpc) < tpx / 2) ? amplitude : 0;
	}
	
	short TriangleWave (double time, double freq, double amp) {
		// Ticks per cycle and amplitude
		double tpc = SAMPLE_RATE / freq;
		double cyclepart = fmod(time, tpc);
		short amplitude = (short)(MAX_AMPLITUDE * amp);
		
		// Triangle wave value -- normalized to [0, 2]
		double normal = (cyclepart / tpc) * 2.0;
		double wave = (normal <= 1.0) ? (2.0 * normal - 1.0) : (-2.0 * (normal - 1.0) + 1.0);
		
		return (short)(wave * amplitude);
	}
	
	short SawtoothleWave (double time, double freq, double amp) {
		// Ticks per cycle and amplitude
		double tpc = SAMPLE_RATE / freq;
		double cyclepart = fmod(time, tpc);
		short amplitude = (short)(MAX_AMPLITUDE * amp);
		
		// Calculate wave value
		double wave = 2.0 * (cyclepart / tpc) - 1.0;
		
		return (short)(wave * amplitude);
	}
	
}
#endif
