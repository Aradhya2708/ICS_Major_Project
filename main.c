#include "ICS_Project.h"
// #include"cJSON.c"


int state;

int main()
{
    printf("\e[1;1H\e[2J");

    char *playerID = (char *)malloc(sizeof(char) * MAX_PLAYER_ID_LENGTH);
    if (playerID == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printStory("\nEnter Login ID : ",BYEL,HIG);
    if (scanf("%s", playerID) != 1)
    {
        fprintf(stderr, "Error reading player ID\n");
        free(playerID);
        return EXIT_FAILURE;
    }


    Player *player = NULL;

    // printRules();
    printf("\e[1;1H\e[2J");
    char *story = " In the aftermath of war, Marcus Agrippa sought solace in the tranquil embrace of his farm,\n where the earth's gentle rhythm promised respite from the horrors of battle.\n But peace was fleeting, shattered by the cruel hand of fate. Returning home one fateful eve,\n Marcus found his sanctuary engulfed in flames, a grim omen of the tragedy that awaited.\n Amidst the smoldering ruins, he discovered the lifeless bodies of his beloved wife and son,\n their innocence consumed by the merciless flames of war. With nothing left to lose,\n Marcus's heart ignited with a searing thirst for vengeance.\n His once-pure hands now hardened into fists, clenched in defiance against\n the darkness that had stolen his loved ones. Guided by the flickering flames\n of retribution, Marcus embarked on a perilous journey, his path illuminated by\n the glint of steel and the echoes of his anguished cries. And it was within\n the hallowed walls of the Colosseum, where blood flowed like wine and echoes\n of cheers mingled with the moans of the fallen, that Marcus's quest for justice began.\n In the heart of the arena, amidst the clash of swords and the roar of the crowd,\n Marcus Agrippa emerged as a beacon of hope, his resolve unyielding against the tide of despair.\n And as he faced his first opponent,\n the world watched in awe as a new legend was born: the legend of Marcus Agrippa, the Avenger.\n";
    printStory(story, BMAG,10);
    
    // printStory("Press Enter to Continue", YEL, MED);

    player = gameInitializer(playerID);
    if (player == NULL)
    {
        fprintf(stderr, "Failed to initialize player\n");
        free(playerID);
        return EXIT_FAILURE;
    }
    // printStory("\nid-%s",player->id,31,0);
    // printf("\nname-%s",player->name);
    // printf("\nlevel-%d",player->level);
    // printf("\nstats,hp-%d",player->stats->HP);
    // printf("\ninventory,items[0]-%s",player->inventory->items[0]);
    // printf("\ninventory,aitems[0]-%d",player->inventory->activeItems[0]);
    // printf("\ngold-%d",player->gold);
    // printf("\ncur_loc-%s",player->currentLocation);
    // printf("\nact_que[0]-%s",player->activeQuests[0]);
    // printf("\nnpcInfo[0][0]-%d",player->NPCInfo[0][0]);
//     printPrologue();

    char *rules = "\n1. Switch between the realms of navigation (n), questing (q), and interaction (i), each representing a facet of Marcus's journey through tragedy and redemption.\nOffered as a fleeting respite from the harsh realities of Marcus's world, the option to exit serves as a reminder of the impossibility of escape from one's past.\n2. Engage with characters who embody the trials and tribulations of Marcus's existence, delving into the depths of human suffering and forging connections in a world haunted by tragedy.\n3. Undertake quests as allegories for Marcus's struggles, confronting demons both internal and external as he seeks redemption in the face of overwhelming adversity.\n4. Exercise caution in choices, as wrong steps may lead to ruin, plunging Marcus deeper into despair in a world where redemption is but a fleeting dream.\n5. Collect items as tangible reminders of Marcus's journey, each possessing a story and a shard of hope amidst the darkness.\n6. Navigate moral dilemmas that test Marcus's resolve, each decision shaping his path towards salvation or damnation in a world on the brink of collapse.\n7. Be mindful of the ripple effect of choices, as every action leaves an indelible mark upon the fabric of reality, determining Marcus's fate in a world overshadowed by tragedy.";
    printStory("\nRules:", BHRED, HIG);
    printStory(rules, HBLU, 10);
    printf("\n");
    selectState(&state); // function that can be called from anywhere by player to choose a state
    while (state >= 0)
        processState(player, &state); // function that processes the state

    printStory("\n\nThank you for playing The Vindication ",BYEL,HIG); /// EXIT STATEMENT

    savePlayerData(player);
    // Cleanup
    freePlayer(player);
    return EXIT_SUCCESS;
}
