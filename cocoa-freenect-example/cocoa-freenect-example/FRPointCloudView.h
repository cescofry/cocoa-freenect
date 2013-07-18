//
//  FRPointCloudView.h
//  cocoa-freenect-example
//
//  Created by James Reuss on 18/07/2013.
//  Copyright (c) 2013 James Reuss. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <CoreVideo/CoreVideo.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl.h>
#import <OpenGL/glu.h>
#import <GLUT/GLUT.h>
#import "FRGLProgram.h"

@class FRGLProgram;
@class JRObjectDetector;
@interface FRPointCloudView : NSOpenGLView {
	IBOutlet NSWindow *window;
    
    CVDisplayLinkRef _displayLink;
	
	BOOL _newDepth, _newRGB;
	
	uint16_t *_intDepth;
	uint8_t *_intRGB;
    GLuint _depthTex, _videoTex, _colormapTex;
    GLuint _pointBuffer;
    
    GLuint *_indicies;
    int _nTriIndicies;
    
    FRGLProgram *_pointProgram;
    FRGLProgram *_depthProgram;
    
    // 3D navigation
    NSPoint _lastPos, _lastPosRight;
    float _offset[3];
    float _angle, _tilt, _roll;
	
	// Draw Modes
	BOOL _drawFrustrum;
	BOOL _normals;
    BOOL _mirror;
    BOOL _natural;
#ifndef DRAW_MODE
#define DRAW_MODE
    enum drawMode {
        MODE_2D = 0,
        MODE_POINTS = 1,
        MODE_MESH = 2,
    };
#endif
	enum drawMode _drawMode;
}

- (void)setDrawMode:(enum drawMode)newDrawMode;
- (void)swapInNewDepthFrame:(uint16_t**)newDepth RGBFrame:(uint8_t**)newRGB;

- (void)stopDrawing;

- (IBAction)resetView:(id)sender;
- (IBAction)rightView:(id)sender;

@end
