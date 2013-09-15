#include <iostream>
#include <vector>

#define NUM_PEGS  3
#define NUM_DISKS 3

int ** pegs;

void initialState()
{
    /* Manually setting some initial state */
    pegs[0][0] = 3;
    pegs[0][1] = 2;
    pegs[0][2] = 1;
    
    pegs[1][0] = 0;
    pegs[1][1] = 0;
    pegs[1][2] = 0;
    
    pegs[2][0] = 0;
    pegs[2][1] = 0;
    pegs[2][2] = 0;
    
}

void dumpPegs()
{
    if(pegs)
    {
        for(int j= NUM_DISKS - 1; j > -1 ; --j){
            printf("\n");
            for(int i=0;i < NUM_PEGS;++i) {
                printf("| %d ", pegs[i][j]);
            }
        }
    }
    printf("\n");
}

bool findDisk(int disk, int& peg, int& pos)
{
    pos = -1; peg = -1;
    for(int p = 0; p < NUM_PEGS ; ++p) {
        for (int d = 0 ; d < NUM_DISKS ; ++d) {
            if(pegs[p][d] != 0 && disk <= pegs[p][d]) {
                if(pegs[p][d] == disk) { peg = p; pos = d; return true; }
            }
            else {
            /* implies we don't have any disk */ d = NUM_DISKS - 1; 
            }   
        }
    }
    
    /* Should never be here */
    return false;
}

bool isThereAnyoneAbove(int p, int pos)
{
    if(pos < NUM_DISKS - 1) {
        return (pegs[p][++pos] != 0 ) ; 
    }
    return false;
}

bool findFirstSuitablePegToMove(int move_disk, int cur_peg, int avoid_peg, int& target_peg, int& target_pos)
{
    for(int p = 0; p < NUM_PEGS; ++p) {
        if(cur_peg == p || avoid_peg == p )
            continue;
        for (int d = 0; d < NUM_DISKS; ++ d) {
            if( pegs[p][d] == 0 ) { target_peg = p; target_pos = d; return true; }
            else if( pegs[p][d] > move_disk ){ continue; }
            else { /* move to end */ d = NUM_DISKS - 1; } 
        }
     }   
    return false;
}

int getFirstEmptySlot(int target_peg)
{   
    for(int d = 0; d < NUM_DISKS ; ++d) {
        if(pegs[target_peg][d] == 0)
            return d;
    } 
    return -1;
}
bool isTargetCondusiveToMove(int disk, int cur_peg, int target_peg, int& disk_to_clear)
{

    int firstEmptySlot = getFirstEmptySlot(target_peg);
    
    disk_to_clear = -1; 
    //No empty slots available condition to check is 'false' and 'disk_to_clear' = -1
    if (firstEmptySlot < 0)
        return false;
           
    if(firstEmptySlot == 0) {
        disk_to_clear = 0;
        return true;
    }
    
    //Can place on the first empty slot since, the disk below is bigger
    if( pegs[target_peg][firstEmptySlot - 1] > disk )
        return true;
    
    //if not, we need to move the first disk from bottom of the target_peg
    //that is lower than the disk
    for(int d = 0; d < firstEmptySlot; ++d) {
        if(pegs[target_peg][d] < disk) {
            disk_to_clear = pegs[target_peg][d];
            break;
        }
    }
    
    return false;
}

void staleMate(int pos)
{
    printf("StaleMate at %d", pos);
    dumpPegs();
    exit(0);
    

}

void doMove(int disk, int to_peg) 
{
    int cur_peg = -1;
    int cur_pos = -1;
    findDisk(disk, cur_peg, cur_pos);
    
    if(isThereAnyoneAbove(cur_peg, cur_pos)){
        printf("Woooa, this is not possible 1");
        exit(0);
    }
    
    int slot = getFirstEmptySlot(to_peg);
    if(  slot < 0 ) {
        printf("Woooa, this is not possible 2");
        exit(0);
    }
    
    pegs[cur_peg][cur_pos] = 0;
    pegs[to_peg][slot] = disk;

}

int move(int disk, int to_peg)
{
    int cur_peg, cur_pos;
    findDisk(disk, cur_peg, cur_pos);
    printf("------> Move %d  from %d to %d\n", disk, cur_peg, to_peg); 
    /* Nothing much to do */
    if(cur_peg == to_peg)
     return 1;
     
    /* Is there anybody above me? */
    if(isThereAnyoneAbove(cur_peg, cur_pos)) {
        /* Need to move this guy */
        int target_peg = -1;
        int target_pos = -1;
        int move_disk = pegs[cur_peg][++cur_pos];
        if (findFirstSuitablePegToMove(move_disk, cur_peg, to_peg, target_peg, target_pos)){
            move(move_disk, target_peg);
        }else {
            staleMate(1);
        }
        
    }
    
    int disk_to_clear = -1;
    bool ok_to_move = isTargetCondusiveToMove(disk, cur_peg, to_peg, disk_to_clear);
    
    if(ok_to_move == false && disk_to_clear == -1 ) {
        staleMate(2);
    }else if (ok_to_move == false && disk_to_clear > 0 ) {
          int new_target_peg = -1;
          int new_target_pos = -1; 
          if(findFirstSuitablePegToMove(disk_to_clear, to_peg, cur_peg, new_target_peg, new_target_pos)){
                move(disk_to_clear, new_target_peg);
          }else {
            staleMate(3);
          }
    }
    
    doMove(disk, to_peg);
    
}


int main()
{    
    pegs =(int **)malloc(sizeof(int *) * NUM_PEGS);
    /* Initializing */
    for (int i = 0; i< NUM_PEGS ; ++i ) {
        pegs[i] = (int *) malloc(sizeof(int) * NUM_DISKS);
        //TODO: check if alloc was successful
        memset(pegs[i],0, sizeof(int)* NUM_DISKS);        
    }
    
    initialState();
    dumpPegs();
    move(3, 2);
    move(2, 2);
    move(1, 2);
    dumpPegs();
    
}