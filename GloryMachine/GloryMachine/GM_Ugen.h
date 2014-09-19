//
//  GM_Ugen.h
//  GloryMachine
//
//  Created by Garry Kling on 9/18/14.
//  Copyright (c) 2014 Garry Kling. All rights reserved.
//

#ifndef GloryMachine_GM_Ugen_h
#define GloryMachine_GM_Ugen_h

#include "GM_Signal.h"
#include "GM_Graph.h"

// the way to get Ugens to do their thing
typedef void (UgenFunc)(struct Ugen * theUgen, int nSamps);

struct Cable {
    struct Graph * parent;
    struct Ugen * start;
    struct Ugen * end;
    
    float * audioPipe;
    double value;
};

typedef struct Cable Cable;

struct Ugen {
    // The basic unit generator services
    // interconnection in graph
    struct Graph *parent;
    struct Cable *ins, *outs;
    int nIns, nOuts;
    float * audioIn, * audioOut;
    int nAudioSamps;
    bool active;
    
    // the code
    UgenFunc doFuncPtr;
    
    // state is defined by subs
    
};

typedef struct Ugen Ugen;

