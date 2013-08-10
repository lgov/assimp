//
//  MyDocument.h
//  DisplayLinkAsyncMoviePlayer
//
//  Created by vade on 10/26/10.
//  Copyright __MyCompanyName__ 2010 . All rights reserved.
//


#import "ModelLoaderHelperClasses.h"

// assimp include files. These three are usually needed.
#import <assimp/config.h>
#import <assimp/cimport.h>
#import <assimp/scene.h>
#import <assimp/postprocess.h>

#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <Quartz/Quartz.h>

@class MyView;

@interface MyDocument : NSPersistentDocument 
{
    CVDisplayLinkRef _displayLink;
    NSOpenGLContext* _glContext;
    NSOpenGLPixelFormat* _glPixelFormat;
    
    MyView* _view;
    
    // Assimp Stuff
    const aiScene* _scene;
    aiVector3D scene_min, scene_max, scene_center;
    double normalizedScale;    
    
    // Our array of textures.
    GLuint *textureIds;
    
    // only used if we use
    NSMutableArray* modelMeshes;   
    BOOL builtBuffers;
    
    NSMutableDictionary* textureDictionary;	// Array of Dicionaries that map image filenames to textureIds

    // degrees of rotation around an imaginary sphere's center
    double rad_x, rad_y;
}

@property (retain) IBOutlet MyView* _view;


- (CVReturn)displayLinkRenderCallback:(const CVTimeStamp *)timeStamp;
- (void) render;
- (void) rotate:(float)arc_x arc_y:(float)arc_y;

- (void) drawMeshesInContext:(CGLContextObj)cgl_ctx;
- (void) createGLResourcesInContext:(CGLContextObj)cgl_ctx;
- (void) deleteGLResourcesInContext:(CGLContextObj)cgl_ctx;

- (void) loadTexturesInContext:(CGLContextObj)cgl_ctx withModelPath:(NSString*) modelPath;
- (void) getBoundingBoxWithMinVector:(aiVector3D*) min maxVectr:(aiVector3D*) max;
- (void) getBoundingBoxForNode:(const aiNode*)nd  minVector:(aiVector3D*) min maxVector:(aiVector3D*) max matrix:(aiMatrix4x4*) trafo;
@end
