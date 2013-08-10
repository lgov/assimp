//
//  MyView.m
//  SimpleAssimpViewX
//
//  Created by Lieven Govaerts on 09/08/13.
//
//

#import "MyView.h"
#import "MyDocument.h"

@implementation MyView

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    NSLog(@"drawRect");
}

-(void)scrollWheel:(NSEvent *)event {
    CGFloat x = [event deltaX];
    CGFloat y = [event deltaY];

    if (x == 0.0 && y == 0.0)
        return;

    NSLog(@"scrollWheel: %f,%f", x, y);

    [document rotate:x arc_y:y];
}

@end
