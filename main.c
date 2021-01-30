#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int respect = 40;
int numOfCreatures;

typedef struct room {
    char name[20];
    int state;
    struct room *north;
    struct room *south;
    struct room *east;
    struct room *west;
    int num;
}room;

typedef struct creature{
    int type;
    char name[100];
    struct room *location;
}creature;

// Room
void look (struct creature* pc, struct creature creatures[]){
    printf("%s, ", pc->location->name);
    if(pc->location->state == 0) {
        printf("clean, neighbors ");
    } else if (pc->location->state == 1) {
        printf("half-dirty, neighbors ");
    } else if (pc->location->state == 2) {
        printf("dirty, neighbors ");
    }
    if(pc->location->north != NULL){
        printf("%s to the north, ", pc->location->north->name);
    }
    if(pc->location->south != NULL){
        printf("%s to the south, ", pc->location->south->name);
    }
    if(pc->location->east != NULL){
        printf("%s to the east, ", pc->location->east->name);
    }
    if(pc->location->west != NULL){
        printf("%s to the west, ", pc->location->west->name);
    }
    printf("contains:\n");
    for (int i = 0; i < numOfCreatures; i++){
        if(creatures[i].location == pc->location) {
            printf("%s\n", creatures[i].name);
        }
    }

}
void clean (struct room* r) {
    if (r->state == 2){
        r->state = 1;
    } else if (r->state == 1){
        r->state = 0;
    }
}
void dirty (struct room* r) {
    if (r->state == 0){
        r->state = 1;
    } else if (r->state == 1){
        r->state = 2;
    }
}

// PC
void move (struct creature* pc, char* direction){
    pc->location->num--;
    printf("You leave towards the %s\n", direction);
    if (strcmp(direction, "north") == 0){
        if (pc->location->north != NULL){
            pc->location->north->num++;
            pc->location = pc->location->north;
        } else {
            printf("You can not move to this side\n");
        }
    } else if (strcmp(direction, "south") == 0){
        if (pc->location->south != NULL){
            pc->location->south->num++;
            pc->location = pc->location->south;
        } else {
            printf("You can not move to this side\n");
        }
    } else if (strcmp(direction, "east") == 0){
        if (pc->location->east != NULL){
            pc->location->east->num++;
            pc->location = pc->location->east;
        } else {
            printf("You can not move to this side\n");
        }
    } else if (strcmp(direction, "west") == 0){
        if (pc->location->west != NULL){
            pc->location->west->num++;
            pc->location = pc->location->west;
        } else {
            printf("You can not move to this side\n");
        }
    }
}

// Animal
void lickFace (struct creature* c) {
    respect++;
    printf("%s licks your face. Respect is now %d\n", c->name, respect);

}
void superLickFace (struct creature* c) {
    respect = respect + 3;
    printf("%s licks your face a lot. Respect is now %d\n", c->name, respect);
}
void growl (struct creature* c) {
    respect--;
    printf("%s growls. Respect is now %d\n", c->name, respect);
}
void superGrowl (struct creature* c) {
    respect = respect - 3;
    printf("%s growls a lot. Respect is now %d\n", c->name, respect);
}

// NPC
void smile (struct creature* c) {
    respect++;
    printf("%s smiles. Respect is now %d\n", c->name, respect);

}
void superSmile (struct creature* c) {
    respect = respect + 3;
    printf("%s smiles a lot. Respect is now %d\n", c->name, respect);
}
void grumble (struct creature* c) {
    respect--;
    printf("%s grumbles. Respect is now %d\n", c->name, respect);
}
void superGrumble (struct creature* c) {
    respect = respect - 3;
    printf("%s grumbles a lot. Respect is now %d\n", c->name, respect);
}

// Animal/NPC
void moveOut (struct creature* pc, struct creature* c){
    c->location->num--;
    if(c->location->north != NULL && pc->location->north->num != 10){
        c->location->north->num++;
        c->location = c->location->north;
        printf("%s leaves towards the north\n", c->name);
    } else if(c->location->south != NULL && pc->location->south->num != 10){
        c->location->south->num++;
        c->location = c->location->south;
        printf("%s leaves towards the south\n", c->name);
    } else if (c->location->east != NULL && pc->location->east->num != 10){
        c->location->east->num++;
        c->location = c->location->east;
        printf("%s leaves towards the east\n", c->name);
    } else if (c->location->west != NULL && pc->location->west->num != 10){
        c->location->west->num++;
        c->location = c->location->west;
        printf("%s leaves towards the west\n", c->name);
    } else {
        c->location = NULL;
    }
    if (c->type == 1) {
        if (c->location->state == 2) {
            clean(c->location);
        }
    } else if (c->type == 2){
        if (c->location->state == 0) {
            dirty(c->location);
        }
    }
}

int main() {
    // Create Rooms
    int numOfRooms;
    printf("What is the number of rooms you would like to create?\n");
    scanf("%d",&numOfRooms);
    room rooms[numOfRooms];
    int state;
    int north;
    int south;
    int east;
    int west;
    for(int i = 0; i < numOfRooms; i++){
        printf("What is the information of the room number %d (state, north, south, east, west)?\n", i + 1);
        scanf("%d%d%d%d%d", &state, &north, &south, &east, &west);
        // Name
        sprintf(rooms[i].name,"Room %d", i);
        // Number of Creature
        rooms->num = 0;
        // Cleanliness
        if (state == 0) {
            rooms[i].state = 0;
        } else if (state == 1) {
            rooms[i].state = 1;
        } else if (state == 2)  {
            rooms[i].state = 2;
        } else {
            printf("The system can not create this room\n");
        }
        //--------------------- north side ---------------------------
        if (north == -1) {
            rooms[i].north = NULL;
        } else if (-1 < north < numOfRooms) {
            rooms[i].north = &rooms[north];
        } else {
            printf("The system can not create this room\n");
        }
        //--------------------- south side ---------------------------
        if (south == -1) {
            rooms[i].south = NULL;
        } else if (-1 < south < numOfRooms) {
            rooms[i].south = &rooms[south];
        } else {
            printf("The system can not create this room\n");
        }
        //--------------------- west side ---------------------------
        if (west == -1) {
            rooms[i].west = NULL;
        } else if (-1 < west < numOfRooms) {
            rooms[i].west = &rooms[west];
        } else {
            printf("The system can not create this room\n");
        }
        //--------------------- east side ---------------------------
        if (east == -1) {
            rooms[i].east = NULL;
        } else if (-1 < east < numOfRooms) {
            rooms[i].east = &rooms[east];
        } else {
            printf("The system can not create this room\n");
        }
    }


    // Create Creatures
    printf("What is the number of creatures you would like to create?\n");
    scanf("%d",&numOfCreatures);
    creature creatures[numOfCreatures];
    int type;
    int location;
    struct creature *pc = (struct creature *) malloc(sizeof(struct creature));
    for(int i = 0; i < numOfCreatures; i++){
        printf("What is the information of the creature number %d (creatureType, location)?\n", i + 1);
        scanf("%d%d", &type, &location);
        if (type == 0) {
            pc = &creatures[i];
            creatures[i].type = 0;
            sprintf(creatures[i].name, "PC %d", i);
        } else if (type == 1) {
            creatures[i].type = 1;
            sprintf(creatures[i].name, "animal %d", i);
        } else if (type == 2) {
            creatures[i].type = 2;
            sprintf(creatures[i].name, "human %d", i);
        } else {
            printf("The system can not create this creature\n");
        }
        creatures[i].location = &rooms[location];
        rooms[location].num++;
    }

    //Operation
    char input[20];
    char *command;
    int a;
    char s[20];
    while (1){
        printf("\nWhat is your next command?\n");
        scanf("%s", input);
        sscanf(input,"%d", &a);
        sprintf(s, "%d", a);
        command = strtok(input, s);
        if (strcmp(command, "look") == 0){
            look(pc, creatures);
        } else if (strcmp(command, "clean") == 0){
            clean(pc->location);
            for(int i = 0; i < numOfCreatures; i++) {
                if (creatures[i].location == pc->location && creatures[i].type == 1) {
                    lickFace(&creatures[i]);
                } else if (creatures[i].location == pc->location && creatures[i].type == 2) {
                    grumble(&creatures[i]);
                    if (pc->location->state == 0) {
                        moveOut(pc, &creatures[i]);
                    }
                }
            }
        } else if (strcmp(command, "dirty") == 0){
            dirty(pc->location);
            for(int i = 0; i < numOfCreatures; i++) {
                if (creatures[i].location == pc->location && creatures[i].type == 2) {
                    smile(&creatures[i]);
                } else if (creatures[i].location == pc->location && creatures[i].type == 1) {
                    growl(&creatures[i]);
                    if (pc->location->state == 2) {
                        moveOut(pc, &creatures[i]);
                    }
                }
            }

        }else if (strcmp(command, "north") == 0) {
            move(pc, "north");
        } else if (strcmp(command, "south") == 0) {
            move(pc,"south");
        } else if (strcmp(command, "east") == 0) {
            move(pc,"east");
        } else if (strcmp(command, "west") == 0) {
            move(pc,"west");
        } else if (strcmp(command, ":clean") == 0) {
            clean(pc->location);
            if (creatures[a].type == 1) {
                superLickFace(&creatures[a]);
                for(int i = 0; i < numOfCreatures; i++){
                    if (creatures[i].location == pc->location && creatures[i].type == 1 && creatures[i].name != creatures[a].name ){
                        lickFace(&creatures[i]);
                    } else if (creatures[i].location == pc->location && creatures[i].type == 2){
                        grumble(&creatures[i]);
                    }
                }
            } else if (creatures[a].type == 2) {
                superGrumble(&creatures[a]);
                for(int i = 0; i < numOfCreatures; i++){
                    if (creatures[i].location == pc->location && creatures[i].type == 1){
                        lickFace(&creatures[i]);
                    } else if (creatures[i].location == pc->location && creatures[i].type == 2 && creatures[i].name != creatures[a].name){
                        grumble(&creatures[i]);
                    }
                }
            }
            if ( pc->location->state == 0) {
                for(int i = 0; i < numOfCreatures; i++){
                     if (creatures[i].location == pc->location && creatures[i].type == 2){
                        moveOut(pc, &creatures[i]);
                    }
                }
            }

        } else if (strcmp(command, ":dirty") == 0) {
            dirty(pc->location);
            if (creatures[a].type == 2) {
                superSmile(&creatures[a]);
                for(int i = 0; i < numOfCreatures; i++){
                    if (creatures[i].location == pc->location && creatures[i].type == 2 && creatures[i].name != creatures[a].name ){
                        smile(&creatures[i]);
                    } else if (creatures[i].location == pc->location && creatures[i].type == 1){
                        growl(&creatures[i]);
                    }
                }
            } else if (creatures[a].type == 1) {
                superGrowl(&creatures[a]);
                for(int i = 0; i < numOfCreatures; i++){
                    if (creatures[i].location == pc->location && creatures[i].type == 2){
                        smile(&creatures[i]);
                    } else if (creatures[i].location == pc->location && creatures[i].type == 1 && creatures[i].name != creatures[a].name){
                        growl(&creatures[i]);
                    }
                }
            }
            if ( pc->location->state == 2) {
                for(int i = 0; i < numOfCreatures; i++){
                    if (creatures[i].location == pc->location && creatures[i].type == 1){
                        moveOut(pc, &creatures[i]);
                    }
                }
            }

        }else if (respect >= 80) {
            printf("Congratulations, you are praised!\n");
            break;
        } else if (respect <= 0) {
            printf("Shame on you! You lose.\n");
            break;
        } else if (strcmp(command, "help") == 0)  {
            printf("Please use look/clean/dirty/north/south/east/west/2:clean/0:clean/exit.\n");
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("We do not understand your command. Please use help!\n");
        }
    }
    printf("Goodbye!");
    return 0;
}

// FUNCTIONS






