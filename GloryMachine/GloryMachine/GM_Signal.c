//
//  Signal.c
//  WaveTableSynth
//
//  Created by Garry Kling on 8/18/14.
//  Copyright (c) 2014 Garry Kling. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "GM_Signal.h"


/*
 * Functions dealing with Signal(s)
 * Basic operations
 *
 */

// allocation

// once we implement sigTypes enum, we can indicate the type
//void createSignal (Signal * theSig, double sRate, int numChan, float dur, int * info)
void createSignal (GM_Signal * theSig, double sRate, int numChan, float dur)
{
    // allocate and init the signal with info provided
    theSig->sampRate = sRate;
    theSig->sampInterval = 1/sRate;
    theSig->chanCnt = numChan;
    theSig->sigDur = dur;
    theSig->chanCnt = numChan;
    theSig->sampCnt = numChan*sRate*dur;
    theSig->frameCnt = theSig->sampCnt/numChan;
    theSig->sigType = NULL;
    
    // no ptr provided
    theSig->otherData = NULL;
    
    // caller frees the actual signal data
    theSig->sigBuf = (float *)malloc(sizeof(float)*theSig->sampCnt);
    
    return;
}