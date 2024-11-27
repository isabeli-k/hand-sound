#ifndef SOUND_H
#define SOUND_H

#include <math.h>

namespace sound {
	#define TWO_PI 6.283185307
	
	short SineWave (double time, double freq, double amp) {
		// Calculate angular frequency
		double omega = TWO_PI * freq / 44100;
		
		// Calculate amplitude
		double amplitude = (short)(32767 * amp);
		
		// Result as sine of phase angle
		return (short)(amplitude * sin(omega * time));
	}
	
	short SquareWave (double time, double freq, double amp) {
		short result = 0;
		int tpc = 44100 / freq;
		int cyclepart = (int)time % tpc;
		int halfcycle = tpc / 2;
		short amplitude = 32767 * amp;

		if (cyclepart < halfcycle) {
		   result = amplitude;
		}

		return result;
	}
	
	short TriangleWave (double time, double freq, double amp) {
		// Ticks per cycle and amplitude
		double tpc = 44100 / freq;
		double cyclepart = fmod(time, tpc);
		short amplitude = (short)(32767 * amp);
		
		// Triangle wave value -- normalized to [0, 2]
		double normal = (cyclepart / tpc) * 2.0;
		double wave = (normal <= 1.0) ? (2.0 * normal - 1.0) : (-2.0 * (normal - 1.0) + 1.0);
		
		return (short)(wave * amplitude);
	}
	
	short SawtoothleWave (double time, double freq, double amp) {
		// Ticks per cycle and amplitude
		double tpc = 44100 / freq;
		double cyclepart = fmod(time, tpc);
		short amplitude = (short)(32767 * amp);
		
		// Calculate wave value
		double wave = 2.0 * (cyclepart / tpc) - 1.0;
		
		return (short)(wave * amplitude);
	}
	
}
#endif
