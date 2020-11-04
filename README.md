# Bounce
This game is the modification of Nokia Bounce - a legendary classic game developed by Nokia in the early 2000s. 

The main aim is to collect all the keys, passing though the doors from one level to another avoiding monsters and using all available artifacts.

You are avialable to modify this game (edit level maps, select your own music, etc)

## How to start
### Clone repository or download one of .zip releases
	git clone https://github.com/OlegYariga/Bounce
or download latest release here: https://github.com/OlegYariga/Bounce/releases/tag/4.0

### Go to "Release" folder and launch .exe file
- Make sure that all .dll files are existing in "Release" folder
- If game is launching but you don't see valid levels, check image files

## Gameplay

- Your current lives number are shown in the top left corner of the screen.
- When you lose, you waste one live. If all lives are lost, game starts again from the first level.
- Beware spikes, wasps and spiders.
- Note, that wasps and spiders use bullets to shoot you.
- Red and blue arrows can toggle gravity. Use them to pass through some places.
- Use rubber mats to jump higher.
- Collect keys on level and then the door will be opened.
- Search for secret passage to pass through walls. 

![BMamqiAFKss (1).jpg](https://github.com/OlegYariga/Bounce/blob/master/Documentation/Pictures/BMamqiAFKss%20(1).jpg?raw=true)

![3wZEeRCZSn0.jpg](https://github.com/OlegYariga/Bounce/blob/master/Documentation/Pictures/3wZEeRCZSn0.jpg?raw=true)![fvXl42mpw0c.jpg](https://github.com/OlegYariga/Bounce/blob/master/Documentation/Pictures/fvXl42mpw0c.jpg?raw=true)![lIQOBw637Ks.jpg](https://github.com/OlegYariga/Bounce/blob/master/Documentation/Pictures/lIQOBw637Ks.jpg?raw=true)
## Creating new levels
In this game you are able to create your own levels. Let's check file level1.map to understand how to do this. In this file you can see the folowing items:

|item| symbol |
|--|--|
| wall  | 0  	|
|ball position	|B	|
|heal	|*	|
|spike	|^	|
|wasp	|A	|
|spider	|S	|
|gravity-off toggle	|8	|
|gravity-on toggle	|2	|
|door	|D	|
|rubber mat	|R	|
|fake wall	|F	|
|speedup	|7	|
|key	|K	|

Use these notifications to construct your own maps.

## Acknowledgements
Thank my team for their participation in developing this project
![UWFTo9C-Mrg.jpg](https://github.com/OlegYariga/Bounce/blob/master/Documentation/Pictures/UWFTo9C-Mrg.jpg?raw=true)


