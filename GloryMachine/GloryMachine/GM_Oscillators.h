//
//  GM_Oscillators.h
//  WaveTableSynth
//
//  Created by Garry Kling on 8/17/14.
//  Copyright (c) 2014 Garry Kling. All rights reserved.
//

#ifndef WaveTableSynth_Oscillators_h
#define WaveTableSynth_Oscillators_h

#include "GM_Signal.h"
#include "GM_Ugen.h"


// wavetable osc ugens

#ifndef SineOsc_Ugen
#define SineOsc_Ugen

struct SineOsc : public Ugen {
    
    float baseIncr;
    double phaseIncr, indexRemainder, currentPhase, currentAmp;
    Signal * sineTable; // ptr to wavetable, created externally

};

// is this needed?
typedef struct SineOsc SineOsc;

// the standard ugen method signatures
void SineOsc_Init(SineOsc * theUgen);
void SineOsc_Retire(SineOsc * theUgen);
void SineOsc_Calc(SineOsc * theUgen, int nSamps);
// since we aren't using plugins, we have to explicitly load the ugen into the Ugen interface table
void SineOsc_Load();


#endif /* SineOsc_Ugen */

void wavetableOsc(float * buffer, int bufferSize, float * wavetable, int wavetableSize, float freq, float amp, float dur);

/*
// wavetable osc that has persistent phase

void wavetableOscBuf(float * buffer, int bufferSize, float * wavetable, int wavetableSize, float freq, float amp, float dur);
*/
// create wavetables

void createSineWavetable(float * buffer, int sampCnt, float periods);
/*
// misc functions
void fillBufferWithSine(float * buffer, float freq);
*/

#endif
