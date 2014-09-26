//
//  GM_Graph.h
//  GloryMachine
//
//  Created by Garry Kling on 9/19/14.
//  Copyright (c) 2014 Garry Kling. All rights reserved.
//

#ifndef GloryMachine_GM_Graph_h
#define GloryMachine_GM_Graph_h

// this func retrieves a sequential optimization of the graph, like a tsort?
// typedef void (GraphOptFunc)(Graph theGraph, Ugen ** optOutput);

struct Graph {
    
    // The global object
    // struct SynthesisContext * sContext;
    
    // placeholder declaration, will contain graph and shit
    double srate;
    double sampleDur;
    int bufSize;
    double bufDur;
    int bufRate;

    struct Ugen ** theUgens; // ptr array for the actual graph
    
//    GraphOptFunc optFunc; // this is interchangable - the dependency tsort
    
};

typedef struct Graph Graph;
#endif
