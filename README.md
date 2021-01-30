# Project Description

You can find a complete description of the project <a href="http://cs.oswego.edu/~alex/teaching/csc241/hw/project.pdf">in this pdf document</a>

When the game starts, it takes from <b>stdin</b> (so no files are opened/closed/used in the project code) input in the following format:

> n (integer, the number of rooms, 1 < n < 100)
> 
> The next n lines are: state-north-south-east-west (five integers, signifying the cleanliness of the room and the numbers of the respective neighbors. State can be 0 for clean, 1 for half-dirty, 2 for dirty, -1 signifies no neighbor. Numbering of the rooms starts at 0)

> m (integer, the number of creatures, 1 < m < 100)
> 
> The next m lines are: CreatureType location (two integers; creatureType is 0 for the PC, 1 for an animal, 2 for an NPC. Location is the number of the room the creature is in. Numbering starts at 0)

After the above is read from stdin, the game should continue reading game commands from stdin.

<h3> Example </h3> 

`Input`
> 3
> 0 -1 1 -1 2
> 2 0 -1 -1 -1
> 2 -1 -1 0 -1
> 4
> 1 0
> 0 2
> 2 2
> 2 1
> look
> clean
> 2:clean
> east
> look
> 0:clean
> look
> exit

`Output`
> Room 2, dirty, neighbors 0 to the east, contains:
> PC
> human 2
> 
> 2 grumbles. Respect is now 39
> 
> 2 grumbles a lot. Respect is now 36
> 2 leaves towards the east.
> 
> You leave towards the east.
> 
> Room 0, half-dirty, neighbors 1 to the south 2 to the west, contains:
> animal 0
> PC
> human 2
> 
> 0 licks your face a lot. Respect is now 39
> 2 grumbles. Respect is now 38
> 2 leaves towards the south
> 
> Room 0, clean, neighbors 1 to the south 2 to the west, contains:
> animal 0
> PC
> 
> Goodbye!
