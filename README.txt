# Maryo

Basic 2D arcade game with Arduino and Led Matrix

# Explanation About Level Editor Parameters

# DISPLAY
This is the size of display. A display must have a constant size like 1920x1080.

# FRAME
A level in the game may be too long. The level designer puts the limits of it according to level designed. According to dislay size, a part of the frame should be displayed. Lets give an example.

Lets say there is a display which is 5x10 pixels.
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

There is a frame which is 10x20 pixels which means level is totaly 10x20 pixels.
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

In the beginning of the game, the part of the frame that will be shown to the player.
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1

When the player started to moving left, situation will be like this.
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1

When the player jump, situation will be like this.
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1

And so on.. That is frame. With the level editor, we'll be building the level by saving multiple frames.
