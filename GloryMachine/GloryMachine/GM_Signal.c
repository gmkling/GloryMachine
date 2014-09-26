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

void initSignal (Signal * theSig, double sRate, int numChan, float dur, int sigType, void * otherData)
{
    theSig->sampRate = sRate;
    theSig->sampInterval = 1/sRate;
    theSig->chanCnt = numChan;
    theSig->sigDur = dur;
    theSig->chanCnt = numChan;
    theSig->sampCnt = numChan*sRate*dur;
    theSig->frameCnt = theSig->sampCnt/numChan;
    theSig->sigType = sigType;
    
    // no ptr provided in this case
    theSig->otherData = otherData;
    
    // caller frees the actual signal data
    theSig->sigBuf = (float *)malloc(sizeof(float)*theSig->sampCnt);
    
    return;
}

void retireSignal (Signal * theSig)
{
    // should only be called when all users are done with it
    // set all to NULL
    theSig->sampRate = NULL;
    theSig->sampInterval = NULL;
    theSig->chanCnt = NULL;
    theSig->sigDur = NULL;
    theSig->chanCnt = NULL;
    theSig->sampCnt = NULL;
    theSig->frameCnt = NULL;
    theSig->sigType = NULL;
    theSig->otherData = NULL;
    
    // free()
    free(theSig->sigBuf);
    theSig = NULL;
}

