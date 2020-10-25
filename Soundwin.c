#include "main.h"

int loadSounds(){
    int success = 1;
    gBGM = (Mix_Music**) malloc(sizeof(Mix_Music*) * TOTAL_BGM);

    gBGM[MENU] = Mix_LoadMUS(".\\audio\\bgm\\village-consort-by-kevin-macleod-from-filmmusic-io.mp3");
    if( gBGM[MENU] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", MENU, Mix_GetError() );
        success = 0;
    }
    gBGM[BATTLE] = Mix_LoadMUS(".\\audio\\bgm\\PerituneMaterial_BattleField5_Retro_loop.mp3");
    if( gBGM[BATTLE] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", BATTLE, Mix_GetError() );
        success = 0;
    }
    gBGM[BATTLE_CRISIS] = Mix_LoadMUS(".\\audio\\bgm\\PerituneMaterial_Blast_loop.mp3");
    if( gBGM[BATTLE_CRISIS] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", BATTLE_CRISIS, Mix_GetError() );
        success = 0;
    }
    gBGM[BOSS_THEME] = Mix_LoadMUS(".\\audio\\bgm\\PerituneMaterial_Dramatic5_Retro_loop.mp3");
    if( gBGM[BOSS_THEME] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", BOSS_THEME, Mix_GetError() );
        success = 0;
    }
    gBGM[BOSS_CRISIS] = Mix_LoadMUS(".\\audio\\bgm\\PerituneMaterial_Crisis_loop.mp3");
    if( gBGM[BOSS_CRISIS] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", BOSS_CRISIS, Mix_GetError() );
        success = 0;
    }
    gBGM[BATTLE_WON] = Mix_LoadMUS(".\\audio\\bgm\\PerituneMaterial_OverWorld3_loop.mp3");
    if( gBGM[BATTLE_WON] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", BATTLE_WON, Mix_GetError() );
        success = 0;
    }
    gBGM[GAME_OVER] = Mix_LoadMUS(".\\audio\\bgm\\PerituneMaterial_Pray_Organ2_loop.mp3");
    if( gBGM[GAME_OVER] == NULL ){
        printf( "Music Failed! Music_id: %i\nSDL_mixer Error: %s\n", GAME_OVER, Mix_GetError() );
        success = 0;
    }
	
    gSFX = (Mix_Chunk**) malloc(sizeof(Mix_Chunk*) * TOTAL_SFX);
    

    gSFX[TITLE_START] = Mix_LoadWAV(".\\audio\\sfx\\TITLE-START.wav");
        if( gSFX[TITLE_START] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", TITLE_START, Mix_GetError() );
            success = 0;
        }
    gSFX[HIT] = Mix_LoadWAV(".\\audio\\sfx\\HIT.wav");
        if( gSFX[HIT] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", HIT, Mix_GetError() );
            success = 0;
        }
    gSFX[HIT_CRIT] = Mix_LoadWAV(".\\audio\\sfx\\HIT-CRIT.wav");
        if( gSFX[HIT_CRIT] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", HIT_CRIT, Mix_GetError() );
            success = 0;
        }
    gSFX[HIT_PROTEC] = Mix_LoadWAV(".\\audio\\sfx\\HIT-PROTEC.wav");
        if( gSFX[HIT_PROTEC] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", HIT_PROTEC, Mix_GetError() );
            success = 0;
        }
    gSFX[CAST] = Mix_LoadWAV(".\\audio\\sfx\\CAST.wav");
        if( gSFX[CAST] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", CAST, Mix_GetError() );
            success = 0;
        }
    gSFX[HEAL] = Mix_LoadWAV(".\\audio\\sfx\\HEAL.wav");
        if( gSFX[HEAL] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", HEAL, Mix_GetError() );
            success = 0;
        }
    gSFX[HEAL_FULL] = Mix_LoadWAV(".\\audio\\sfx\\HEAL-FULL.wav");
        if( gSFX[HEAL_FULL] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", HEAL_FULL, Mix_GetError() );
            success = 0;
        }
    gSFX[FIRE1] = Mix_LoadWAV(".\\audio\\sfx\\FIRE1.wav");
        if( gSFX[FIRE1] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", FIRE1, Mix_GetError() );
            success = 0;
        }
    gSFX[FIRE2] = Mix_LoadWAV(".\\audio\\sfx\\FIRE2.mp3");
        if( gSFX[FIRE2] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", FIRE2, Mix_GetError() );
            success = 0;
        }
    gSFX[FIRE3] = Mix_LoadWAV(".\\audio\\sfx\\FIRE3.mp3");
        if( gSFX[FIRE3] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", FIRE3, Mix_GetError() );
            success = 0;
        }
    gSFX[ICE1] = Mix_LoadWAV(".\\audio\\sfx\\ICE1.wav");
        if( gSFX[ICE1] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", ICE1, Mix_GetError() );
            success = 0;
        }
    gSFX[ICE2] = Mix_LoadWAV(".\\audio\\sfx\\ICE2.flac");
        if( gSFX[ICE2] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", ICE2, Mix_GetError() );
            success = 0;
        }
    gSFX[ICE3] = Mix_LoadWAV(".\\audio\\sfx\\ICE3.mp3");
        if( gSFX[ICE3] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", ICE3, Mix_GetError() );
            success = 0;
        }
    gSFX[ELEC1] = Mix_LoadWAV(".\\audio\\sfx\\ELEC1.wav");
        if( gSFX[ELEC1] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", ELEC1, Mix_GetError() );
            success = 0;
        }
    gSFX[ELEC2] = Mix_LoadWAV(".\\audio\\sfx\\ELEC2.wav");
        if( gSFX[ELEC2] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", ELEC2, Mix_GetError() );
            success = 0;
        }
    gSFX[ELEC3] = Mix_LoadWAV(".\\audio\\sfx\\ELEC3.wav");
        if( gSFX[ELEC3] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", ELEC3, Mix_GetError() );
            success = 0;
        }
    gSFX[SUPP_ESCUDO] = Mix_LoadWAV(".\\audio\\sfx\\SUPP-ESCUDO.wav");
        if( gSFX[SUPP_ESCUDO] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", SUPP_ESCUDO, Mix_GetError() );
            success = 0;
        }
    gSFX[SUPP_PREV] = Mix_LoadWAV(".\\audio\\sfx\\SUPP-PREV.wav");
        if( gSFX[SUPP_PREV] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", SUPP_PREV, Mix_GetError() );
            success = 0;
        }
    gSFX[SUPP_TRICK] = Mix_LoadWAV(".\\audio\\sfx\\SUPP-TRICK.wav");
        if( gSFX[SUPP_TRICK] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", SUPP_TRICK, Mix_GetError() );
            success = 0;
        }
    gSFX[HP_LOW] = Mix_LoadWAV(".\\audio\\sfx\\HPLOW.wav");
        if( gSFX[HP_LOW] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", HP_LOW, Mix_GetError() );
            success = 0;
        }
    gSFX[MONSTER_HIT] = Mix_LoadWAV(".\\audio\\sfx\\MONSTER-HIT.wav");
        if( gSFX[MONSTER_HIT] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", MONSTER_HIT, Mix_GetError() );
            success = 0;
        }
    gSFX[MONSTER_CRIT] = Mix_LoadWAV(".\\audio\\sfx\\MONSTER-CRIT.wav");
        if( gSFX[MONSTER_CRIT] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", MONSTER_CRIT, Mix_GetError() );
            success = 0;
        }
    gSFX[MONSTER_STEAL] = Mix_LoadWAV(".\\audio\\sfx\\MONSTER-STEAL.wav");
        if( gSFX[MONSTER_STEAL] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", MONSTER_STEAL, Mix_GetError() );
            success = 0;
        }
    gSFX[MONSTER_FLEE] = Mix_LoadWAV(".\\audio\\sfx\\MONSTER-FLEE.wav");
        if( gSFX[MONSTER_FLEE] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", MONSTER_FLEE, Mix_GetError() );
            success = 0;
        }
    gSFX[DEATH_PINGUIM] = Mix_LoadWAV(".\\audio\\sfx\\DEATH-PINGUIM.wav");
        if( gSFX[DEATH_PINGUIM] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", DEATH_PINGUIM, Mix_GetError() );
            success = 0;
        }
    gSFX[DEATH_LADRAO] = Mix_LoadWAV(".\\audio\\sfx\\DEATH-BANDIDO.wav");
        if( gSFX[DEATH_LADRAO] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", DEATH_LADRAO, Mix_GetError() );
            success = 0;
        }
    gSFX[DEATH_GOBLIN] = Mix_LoadWAV(".\\audio\\sfx\\DEATH-GOBLIN.wav");
        if( gSFX[DEATH_GOBLIN] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", DEATH_GOBLIN, Mix_GetError() );
            success = 0;
        }
    gSFX[DEATH_ABU] = Mix_LoadWAV(".\\audio\\sfx\\DEATH-ABU.wav");
        if( gSFX[DEATH_ABU] == NULL ){
            printf( "SFX Failed! sfx_id %i\nSDL_mixer Error: %s\n", DEATH_ABU, Mix_GetError() );
            success = 0;
        }
    
    return success;
}

void closeSounds(){
    int i;
    for (i = 0; i < TOTAL_BGM; i++){
        Mix_FreeMusic(gBGM[i]);
    }
    free(gBGM);
    for (i = 0; i < TOTAL_SFX; i++){
        Mix_FreeChunk(gSFX[i]);
    }
    free(gSFX);
    Mix_Quit();
}

void controlBGM(int bgmID, int command){
    if(Mix_PlayingMusic() == 0){
        Mix_PlayMusic(gBGM[bgmID], -1);
    }
    else{
        if(command == STOP){
            Mix_HaltMusic();
        }
        else if (command == PAUSE){
            if(Mix_PausedMusic() == 1){
                Mix_ResumeMusic();
            }
            else{
                Mix_PauseMusic();
            }
        }
    }
}

void playSFX(int sfxID){
    Mix_PlayChannel(-1, gSFX[sfxID], 0);
}