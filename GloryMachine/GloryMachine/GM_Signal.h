//
//  GM_Signal.h
//  WaveTableSynth
//
//  Created by Garry Kling on 8/18/14.
//  Copyright (c) 2014 Garry Kling. All rights reserved.
//

#ifndef WaveTableSynth_Signal_h
#define WaveTableSynth_Signal_h

#include "sndfile.h"


struct Signal
{
    double sampRate;     // # of samples/second
    double sampInterval; // 1/sampRate
    float * sigBuf;      // the signal data
    float sigDur;        // duration of the signal in seconds
    int chanCnt;         // # of interleaved signals
    int frameCnt;        // sampCnt/chanCnt
    int sampCnt;         // total # of samples (frameCnt*sampRate*sigDur)
    int sigType;         // the type of signal (should this be a bitmap?)
    void * otherData;    // for misc pointers, file handles, etc.
};

typedef struct Signal Signal;

enum SignalTypes {kNoType, kSoundFile, kWavetable, kBuffer};

// init/retire
void initSignal (Signal * theSig, double sRate, int numChan, float dur, int sigType, void * otherData);
void retireSignal (Signal * theSig);

#endif
