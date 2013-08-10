//
//  MyView.h
//  SimpleAssimpViewX
//
//  Created by Lieven Govaerts on 09/08/13.
//
//

#import <Cocoa/Cocoa.h>

@class MyDocument;

@interface MyView : NSView
{
IBOutlet MyDocument* document;
}


-(void)scrollWheel:(NSEvent *)event;
@end
