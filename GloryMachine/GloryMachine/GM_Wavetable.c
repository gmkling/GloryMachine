//
//  GM_Wavetable.c
//  GloryMachine
//
//  Created by Garry Kling on 9/23/14.
//  Copyright (c) 2014 Garry Kling. All rights reserved.
//

#include "GM_Signal.h"

// utility functions for creating/managing wavetables
/*
// Create a sine wavetable
void initSineWavetable(Signal * theSig, int sampCnt, float periods)
{
    //init the Signal
    
    initSignal(theSig, sampCnt, 1, 1.0, kWavetable, NULL);
    
    // fill it with a sine wave
    int k = 0;
    float amplitude = 1;
    float coeff = 2*M_PI/sampCnt;
    
    for (k = 0 ; k <= sampCnt ; k++)
    {
        theSig->sigBuf[k] = amplitude * sinf(periods * k * coeff);
    }
    
    k++;
    theSig->sigBuf[k] = 0;
    
}
*/